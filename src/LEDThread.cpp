// LEDThread.cpp
#include "LEDThread.h"
#include <iostream>
#include "AudioSource.h"
using namespace std;

/*!
 * Constructor for the LEDThread class
 */
LEDThread::LEDThread(QObject *parent)
    : QThread(parent)
{
    ws2812b = new WS2812B();
    ws2812b->begin();
}

/*!
 * Main function for the LEDThread class, responsible for updating the LED
 * patterns based on the current mode and amplitude.
 */
void LEDThread::run()
{
    while (true) {
        {
            QMutexLocker locker(&mutex);
            if (terminateFlag) {
                break;
            }
        }
        // Choose a different mode based on the m_mode variable
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
            default:
                break;
        }
    }
}

/*!
 * Starts the LEDThread.
 */
void LEDThread::startThread()
{
    mutex.lock();
    terminateFlag = false;
    mutex.unlock();
    start();
}

/*!
 * Stops the LEDThread.
 */
void LEDThread::stopThread()
{
    mutex.lock();
    terminateFlag = true;
    mutex.unlock();
    wait();
}

/*!
 * Sets the amplitude for the LEDThread.
 * @param amplitude - the amplitude value to set
 */
void LEDThread::setAmplitude(double amplitude)
{
    m_amplitude = amplitude;
}

/*!
 * Sets the mode for the LEDThread.
 * @param mode - the mode value to set
 */
void LEDThread::setMode(int mode)
{
    lightMode = mode;
}
