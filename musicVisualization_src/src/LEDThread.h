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
    void setAmplitude(double amplitude);
    void setMode(int mode);

private:
    WS2812B *ws2812b;
    QMutex mutex;
    bool terminateFlag;
    double m_amplitude;
    int lightMode = 1;
};

#endif // LEDTHREAD_H
