#include "gtest/gtest.h"
#include "gtest_AudioSource.h"
#include "gtest_LEDThread.h"
#include "gtest_SetDevice.h"
#include "gtest_WS2812B.h"
//#include ""


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}