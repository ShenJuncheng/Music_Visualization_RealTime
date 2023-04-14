#include "mainwindow.h"
#include "../lib/rpi_ws281x/ws2811.h"
#include <iostream>
#include <unistd.h>
#include "WS2812B.h"
#include "LEDThread.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    const char *pulseServer = "unix:/run/user/0/pulse/native";
    setenv("PULSE_SERVER", pulseServer, 1);

    QApplication a(argc, argv);

    LEDThread ledThread;
//    ledThread.start();
    MainWindow w;
    w.show();

    return a.exec();
}
