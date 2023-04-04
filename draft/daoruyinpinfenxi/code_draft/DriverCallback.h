#ifndef DRIVERCALLBACK_H
#define DRIVERCALLBACK_H

class DriverCallback {
    public:
        virtual void fftData(int *, int) = 0;
        virtual int* lpData(int *) = 0;
};

#endif
