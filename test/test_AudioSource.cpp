#include "gtest/gtest.h"
#include "AudioSource.h"

class AudioSourceTest : public ::testing::Test {
protected:
    void SetUp() override {
        audioSource = new AudioSource();
    }

    void TearDown() override {
        delete audioSource;
    }

    AudioSource *audioSource;
};

TEST_F(AudioSourceTest, CalculateAmplitudeTest) {
    const char data[] = {0, 64, 127, 64, 0, static_cast<char>(-64), static_cast<char>(-127), static_cast<char>(-64)};

    qint64 maxSize = sizeof(data);
    double expectedAmplitude = 0.5;

    double resultAmplitude = audioSource->calculateAmplitude(data, maxSize);
    EXPECT_NEAR(expectedAmplitude, resultAmplitude, 0.01);
}
