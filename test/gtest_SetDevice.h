#include <gtest/gtest.h>
#include <QCoreApplication>
#include "SetDevice.h"

TEST(SetDeviceTest, InitializeAudioInputTest) {
// Create a QCoreApplication instance to avoid QAudioDeviceInfo initialization error
int argc = 0;
char** argv = nullptr;
QCoreApplication app(argc, argv);

SetDevice setDevice;
QAudioInput* audioInput = setDevice.initializeAudioInput();

EXPECT_NE(audioInput, nullptr);
EXPECT_EQ(audioInput->state(), QAudio::StoppedState);
EXPECT_EQ(audioInput->format().sampleRate(), 1000);
EXPECT_EQ(audioInput->format().channelCount(), 1);
EXPECT_EQ(audioInput->format().sampleSize(), 8);
EXPECT_EQ(audioInput->format().codec(), "audio/pcm");
EXPECT_EQ(audioInput->format().byteOrder(), QAudioFormat::LittleEndian);
EXPECT_EQ(audioInput->format().sampleType(), QAudioFormat::UnSignedInt);
delete audioInput;
}

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
