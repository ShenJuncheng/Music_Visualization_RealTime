#ifndef SETDEVICE_H
#define SETDEVICE_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>

class SetDevice : public QObject
{
    Q_OBJECT

public:
    SetDevice(QObject *parent = nullptr);
    QAudioInput *initializeAudioInput();

private:
    QAudioFormat m_audioFormat;
    QAudioDeviceInfo m_inputDevices;
};

#endif // SETDEVICE_H
