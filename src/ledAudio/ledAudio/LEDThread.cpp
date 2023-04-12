// LEDThread.cpp
#include "LEDThread.h"
#include <iostream>
#include <AudioSource.h>
using namespace std;

LEDThread::LEDThread(QObject *parent)
    : QThread(parent)
{
    ws2812b = new WS2812B();
    ws2812b->begin();

}

void LEDThread::run()
{
    while(true){
        {
            QMutexLocker locker(&mutex);
            if (terminateFlag) {
                break;
            }
        }
        // 根据 m_mode 变量选择不同的模式
        switch (lightMode) {
            case 1:
                ws2812b->updateLEDMode1(m_amplitude);
                break;
            case 2:
                ws2812b->updateLEDMode2(m_amplitude);
                break;
            case 3:
                ws2812b->updateLEDMode3(m_amplitude);
                break;
            case 4:
                ws2812b->updateLEDMode4(m_amplitude);
            break;
            default:
                break;
        }

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
    wait();
}

void LEDThread::setAmplitude(double amplitude) {
    m_amplitude = amplitude;
}

void LEDThread::setMode(int mode) {
    lightMode = mode;
}
