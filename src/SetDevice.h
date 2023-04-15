#ifndef SETDEVICE_H
#define SETDEVICE_H

#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>

class SetDevice
{
public:
    SetDevice();
    QAudioInput *initializeAudioInput();

private:
    QAudioFormat m_audioFormat;
    QAudioDeviceInfo m_inputDevices;
};

#endif // SETDEVICE_H
