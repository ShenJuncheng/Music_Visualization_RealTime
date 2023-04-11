#ifndef FFT_CLASS_H
#define FFT_CLASS_H
#include <iostream>
#include <fftw3.h>
// #include <qmainwindow.h>
// #include <qobjectdefs.h>
// #include <qtimer.h>
#include <stdint.h>
// #include <qwt/qwt_plot.h>
// #include <qwt/qwt_plot_curve.h>
// #include <QMainWindow>
#include "i2s_mems_mic.h"
#define FFT_BUFFER_SIZE 1024

class FftClass{

public:
    FftClass(int buffer_size = FFT_BUFFER_SIZE);
    ~FftClass();

public:
    void fill_buffer(int *);
    double update();
    double array[513];
    double max_fre;
    double *max_fre_p = &max_fre;

private:
    double *in;
    fftw_complex *out;
    double *x; //<not used>
    double *y; //<not used>
    
    double mag;
    double yMax;

    int num_samples;
    int n_out;
    int nFreqSamples;
};

#endif 