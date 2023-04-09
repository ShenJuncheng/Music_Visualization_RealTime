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
    // 根据振幅计算LED灯带的颜色和亮度
    // 示例：用振幅作为亮度的简单实现
//    ws2812b->begin();
//    mutex.lock();
//    if (terminateFlag) {
//        terminateFlag = false;
//        mutex.unlock();
//    }
    cout << amplitude << endl;
    if(amplitude < 128){
        ws2812b->random_Color();
        ws2812b->update();
    }
    else{
        ws2811_led_t color = (int(255 * amplitude) << 16) | (int(255 * amplitude) << 8) | int(255 * amplitude);
        for (int i = 0; i < LED_COUNT; i++) {
            ws2812b->matrix[i] = color;
        }
        ws2812b->update();
    }

}

