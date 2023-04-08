#ifndef LEDTHREAD_H
#define LEDTHREAD_H
// LEDThread.h
#include <QThread>
#include "WS2812B.h"

class LEDThread : public QThread
{
    Q_OBJECT

public:
    explicit LEDThread(QObject *parent = nullptr);
//    enum LEDMode {
//            RANDOM_COLOR,
//            THEATER_CHASE,
//            COLOR_WIPE
//    };

//    void setNextMode();

protected:
    void run() override;

private:
    WS2812B *ws2812b;
//    LEDMode currentMode;
};

#endif // LEDTHREAD_H
