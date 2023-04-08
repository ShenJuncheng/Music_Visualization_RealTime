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
    while (1) {
        ws2812b->random_Color();
        ws2812b->update();
        usleep(1000000 / 15);
    }
}
