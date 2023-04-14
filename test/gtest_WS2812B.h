#include "WS2812B.h"
#include "gtest/gtest.h"

class WS2812BTest : public ::testing::Test {
protected:
    WS2812B led;

    virtual void SetUp() {
        led.begin();
    }

    virtual void TearDown() {
        led.off();
    }
};

TEST_F(WS2812BTest, UpdateLEDMode2) {
double amplitude = 0.5;
for (int i = 0; i < LED_COUNT; i++) {
led.matrix[i] = 0x000000;
}

led.updateLEDMode2(amplitude);

// Check that the first LED has the expected color
int expected_brightness = 127;
ws2811_led_t expected_color = (expected_brightness << 16) | (expected_brightness << 8) | expected_brightness;
EXPECT_EQ(expected_color, led.matrix[0]);

// Check that the other LEDs have been shifted to the right
for (int i = 1; i < LED_COUNT; i++) {
EXPECT_EQ(0x000000, led.matrix[i]);
}
}

TEST_F(WS2812BTest, UpdateLEDMode3) {
double amplitude = 0.5;
for (int i = 0; i < LED_COUNT; i++) {
led.matrix[i] = 0x000000;
}

led.updateLEDMode3(amplitude);

// Check that the first LED has the expected color
int expected_brightness = 127;
ws2811_led_t expected_color = (expected_brightness << 16) | (expected_brightness << 8) | expected_brightness;
EXPECT_EQ(expected_color, led.matrix[0]);

// Check that the LEDs on the left have been shifted to the right
for (int i = 1; i < LED_COUNT / 2; i++) {
EXPECT_EQ(0x000000, led.matrix[i]);
}

// Check that the LEDs on the right have been shifted to the left
for (int i = LED_COUNT / 2 + 1; i < LED_COUNT; i++) {
EXPECT_EQ(0x000000, led.matrix[i]);
}
}
