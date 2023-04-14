#include <gtest/gtest.h>
#include <QCoreApplication>
#include "LEDThread.h"

// Fixture class to setup and teardown test cases
class LEDThreadTest : public ::testing::Test
{
protected:
    LEDThread thread;

    void SetUp() override
    {
        // Start the thread
        thread.startThread();
    }

    void TearDown() override
    {
        // Stop the thread
        thread.stopThread();
    }
};

TEST_F(LEDThreadTest, SetAndGetAmplitude)
{
// Set the amplitude
thread.setAmplitude(0.5);

// Get the amplitude and verify it's correct
EXPECT_EQ(thread.m_amplitude, 0.5);
}

TEST_F(LEDThreadTest, SetAndGetMode)
{
// Set the mode
thread.setMode(2);

// Get the mode and verify it's correct
EXPECT_EQ(thread.lightMode, 2);
}

TEST(LEDThread, StartAndStopThread)
{
// Create a thread instance
LEDThread thread;

// Start the thread
thread.startThread();

// Verify that the thread is running
EXPECT_EQ(thread.isRunning(), true);

// Stop the thread
thread.stopThread();

// Verify that the thread is stopped
EXPECT_EQ(thread.isRunning(), false);
}
