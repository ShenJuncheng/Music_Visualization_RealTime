#include "SetDevice.h"

// Constructor for the SetDevice class
SetDevice::SetDevice()
{
    // Initialize audio format settings
    m_audioFormat.setSampleRate(1000);             // Set sample rate to 1000 Hz
    m_audioFormat.setChannelCount(1);              // Set channel count to 1 (mono)
    m_audioFormat.setSampleSize(8);                // Set sample size to 8 bits
    m_audioFormat.setCodec("audio/pcm");           // Set codec to PCM (Pulse Code Modulation)
    m_audioFormat.setByteOrder(QAudioFormat::LittleEndian); // Set byte order to Little Endian
    m_audioFormat.setSampleType(QAudioFormat::UnSignedInt); // Set sample type to Unsigned Integer

    // Set the default input device for the audio system
    m_inputDevices = QAudioDeviceInfo::defaultInputDevice();
}

/*!
 * Initializes and returns a QAudioInput object with the configured audio format
 * and default input device.
 * @return QAudioInput* - pointer to the created QAudioInput object
 */
QAudioInput *SetDevice::initializeAudioInput()
{
    QAudioInput *audioInput = new QAudioInput(m_inputDevices, m_audioFormat);
    
    return audioInput;
}
