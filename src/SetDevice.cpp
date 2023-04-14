#include "SetDevice.h"

SetDevice::SetDevice(QObject *parent) : QObject(parent)
{
    // Initialize audio format here
    m_audioFormat.setSampleRate(1000);
    m_audioFormat.setChannelCount(1);
    m_audioFormat.setSampleSize(8);
    m_audioFormat.setCodec("audio/pcm");
    m_audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    m_audioFormat.setSampleType(QAudioFormat::UnSignedInt);

    m_inputDevices = QAudioDeviceInfo::defaultInputDevice();
}

QAudioInput *SetDevice::initializeAudioInput()
{
    QAudioInput *audioInput = new QAudioInput(m_inputDevices, m_audioFormat);
    return audioInput;
}
