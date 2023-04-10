// LEDThread.cpp
#include "LEDThread.h"
#include <iostream>
using namespace std;

LEDThread::LEDThread(QObject *parent)
    : QThread(parent)
{
    ws2812b = new WS2812B();
    ws2812b->begin();
}

void LEDThread::run()
{
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

//new adding
void LEDThread::updateLEDStrip(double amplitude)
{
    amplitude = abs(amplitude - 0.098) / 0.05;
    cout << "amplitude error: " << amplitude - 0.098 << endl;
    cout << "amplitude changed : " << amplitude << endl;
    if(amplitude <= 0.0495098){

        for (int i = 0; i < LED_COUNT; i++) {
            ws2812b->matrix[i] = 0x00101010;
        }
        ws2812b->update();
    }
    else{        
        int lit_leds = int(LED_COUNT * amplitude);

        for (int i = 0; i < LED_COUNT; i++) {
            if (i < lit_leds) {
                ws2812b->matrix[i] = 0xffffffff; // 红色
            } else {
                ws2812b->matrix[i] = 0x00101010; // 熄灭
            }
        }

        ws2812b->update();
    }

}

