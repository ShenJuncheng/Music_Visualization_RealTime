#ifndef I2S_H
#define I2S_H

#define ALSA_PCM_NEW_HW_PARAMS_API
#define SAMPLE_RATE 8000
#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <cstdint>
#include <errno.h>
#include <thread>
#include <mutex>
#include "DriverCallback.h"
//buffer size
#define frames_number 1024

static struct snd_params{
    snd_pcm_format_t format = SND_PCM_FORMAT_S32_LE;
    unsigned int channels = 1;
    unsigned int rate = SAMPLE_RATE;
} hwparams;

class I2Smic {

public:

    void open_pcm();
    void set_params(void);
    void close_pcm();
    void run();
    void registercallback(DriverCallback* cb);
    ~I2Smic() {
        this->close_pcm();
    }

    int get_rc();
private:

    snd_pcm_t *handle;
    const int open_mode = 0;
    const snd_pcm_stream_t stream = SND_PCM_STREAM_CAPTURE;
    char const* pcm_name = "plughw:1";//sound device name
    snd_pcm_uframes_t frames; 
    unsigned int val;   
    snd_pcm_hw_params_t *params;
    snd_pcm_info_t *info;
    DriverCallback* callback;
    int rc;
    std::mutex readoutMtx;
    int buffer[2][frames_number];
    unsigned currentBufIdx = 0;
};

#endif
