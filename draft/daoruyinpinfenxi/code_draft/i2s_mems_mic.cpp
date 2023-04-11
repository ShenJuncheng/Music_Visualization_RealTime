/* Use the newer ALSA API */
#include "i2s_mems_mic.h"
#include <cmath>
#include "Global.h"
#define ALSA_PCM_NEW_HW_PARAMS_API

void I2Smic::open_pcm(){
    rc = snd_pcm_open(&handle, pcm_name,
                   stream, open_mode);
    if (rc < 0) {
        fprintf(stderr,
                "unable to open pcm device: %s\n",
                snd_strerror(rc));

        exit(1);
    }    
}

void I2Smic::set_params(void) {
    snd_pcm_hw_params_t *params;
    snd_pcm_hw_params_alloca(&params);
    int err;
    err = snd_pcm_hw_params_any(handle, params);
    if (err < 0) {
        fprintf(stderr,
               "Broken configuration for this PCM: no configurations avaliable: %s",
                snd_strerror(rc));

        exit(1);
    }
    
    err = snd_pcm_hw_params_set_access(handle, params,
                        SND_PCM_ACCESS_RW_INTERLEAVED); 
    if (err < 0) {
        fprintf(stderr,
                "Access type not available: %s",
                snd_strerror(rc));

        exit(1);
    }

    err = snd_pcm_hw_params_set_format(handle, params,
                                hwparams.format);
    if (err < 0) {
        fprintf(stderr,
                "Sample format non available: %s",
                snd_strerror(err));

        exit(1);
    }

    err = snd_pcm_hw_params_set_channels(handle, params, hwparams.channels);
    if (err < 0) {
        fprintf(stderr, "Channels count non avaliable");

        exit(1);
    }
    
    err = snd_pcm_hw_params_set_rate_near(handle, params, &hwparams.rate, 0);
    assert(err >= 0);
    
    frames = frames_number;
    err = snd_pcm_hw_params_set_period_size_near(handle, params, &frames, 0);
    assert(err >= 0);
    
    err = snd_pcm_hw_params(handle, params);
    if (err < 0) {
        fprintf(stderr, "unable to installl hw params: ");
        exit(1);
    }

    snd_pcm_hw_params_get_period_size(params, &frames, 0); 
    
    snd_pcm_hw_params_get_period_time(params, &val, 0);
}

void I2Smic::run(){
    while (!global_program_exit) {
        rc = snd_pcm_readi(handle, &(buffer[currentBufIdx][0]), frames);

        if (rc == -EPIPE) {
            fprintf(stderr, "overrun occurred\n");
            snd_pcm_prepare(handle);
        } else if (rc < 0) {
            fprintf(stderr,
                "error from read: %s\n",
                snd_strerror(rc));
        } else if (rc != (int)frames) {
            fprintf(stderr, "short read, read %d frames\n", rc);
        }

        callback->lpData(&(buffer[currentBufIdx][0]));
        callback->fftData(&(buffer[currentBufIdx][0]), frames);
    

        readoutMtx.lock();
        currentBufIdx = !currentBufIdx;
        readoutMtx.unlock();
        
    }
}

int I2Smic::get_rc(){
    return this->rc;
}


void I2Smic::registercallback(DriverCallback* cb) {
    this->callback = cb;
}


void I2Smic::close_pcm() {
    global_program_exit=true;
    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    ///free(buffer);
}