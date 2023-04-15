/*
 * Created by JUNCHENG SHEN
 * */
#include "WS2812B.h"
#include <gtest/gtest.h>

class WS2812BTest : public testing::Test {
protected:
    WS2812BTest() {
        ws2812b = new WS2812B();
    }

    ~WS2812BTest() override {
        delete ws2812b;
    }

    WS2812B* ws2812b;
};

TEST_F(WS2812BTest, InitializeAndUpdateLEDs) {
    // unit test 
    ASSERT_EQ(ws2812b->begin(), 0);
    ws2812b->updateLEDMode1(0.5);
    ws2812b->updateLEDMode2(0.5);
    ws2812b->updateLEDMode3(0.5);
}
