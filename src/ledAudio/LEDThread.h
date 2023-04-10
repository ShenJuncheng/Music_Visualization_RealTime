#ifndef LEDTHREAD_H
#define LEDTHREAD_H
// LEDThread.h
#include <QThread>
#include <QMutex>
#include "WS2812B.h"

class LEDThread : public QThread
{
    Q_OBJECT

public:
    explicit LEDThread(QObject *parent = nullptr);

    void startThread();
    void stopThread();

protected:
    void run() override;

public slots:
    void updateLEDStrip(double amplitude);

private:
    WS2812B *ws2812b;
    QMutex mutex;
    bool terminateFlag;
    double currentAmplitude; // 新增变量，存储当前振幅
    // 11:50 new adding
//    double calculateAmplitude(const char *data, qint64 maxSize); // 新增方法
//    void updateLEDStrip(double amplitude);
};

#endif // LEDTHREAD_H
