// LEDThread.cpp
#include "LEDThread.h"

LEDThread::LEDThread(QObject *parent)
    : QThread(parent)
{
    ws2812b = new WS2812B();
}

void LEDThread::run()
{
    ws2812b->begin();
    while (true) {
        mutex.lock();
        if (terminateFlag) {
            terminateFlag = false;
            mutex.unlock();
            break;
        }
        mutex.unlock();
        ws2812b->random_Color();
        ws2812b->update();
        usleep(1000000 / 15);
    }
}

void LEDThread::startThread()
{
    mutex.lock();
    terminateFlag = false;
    mutex.unlock();
    start();
}

void LEDThread::stopThread()
{
    mutex.lock();
    terminateFlag = true;
    mutex.unlock();
}
