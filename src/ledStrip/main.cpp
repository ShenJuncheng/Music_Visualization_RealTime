#include "mainwindow.h"
#include "rpi_ws281x/ws2811.h"
#include <iostream>
#include <unistd.h>
#include "WS2812B.h"
#include "LEDThread.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LEDThread ledThread;
    ledThread.start();
    MainWindow w;
    w.show();

    return a.exec();
}
