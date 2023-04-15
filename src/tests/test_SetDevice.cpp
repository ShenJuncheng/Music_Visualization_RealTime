#include "SetDevice.h"
#include <gtest/gtest.h>
#include <QAudioInput>

class SetDeviceTest : public testing::Test {
protected:
    SetDeviceTest() {
        setDevice = new SetDevice();
    }

    ~SetDeviceTest() override {
        delete setDevice;
    }

    SetDevice* setDevice;
};

TEST_F(SetDeviceTest, InitializeAudioInput) {
    QAudioInput* audioInput = setDevice->initializeAudioInput();
    ASSERT_NE(audioInput, nullptr);
    delete audioInput;
}
