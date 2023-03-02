//“chrono是在std下,属于C++11的标准,它的头文件为#include<chrono>,是一个处理时间的元素。”
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <cstdint>

//constant value
constexpr int LED_COUNT = 16;
constexpr int LED_PIN = 18;
constexpr int LED_FREQ_HZ = 800000;
constexpr int LED_DMA = 10;
constexpr int LED_BRIGHTNESS = 255;
constexpr bool LED_INVERT = false;
constexpr int LED_CHANNEL = 0;

// Color class to represent an RGB color, can be moved to a single file
class Color {
public:
    uint8_t r, g, b;
    Color(uint8_t r_, uint8_t g_, uint8_t b_) : r(r_), g(g_), b(b_) {}
};

// LED pattern functions

//一次擦除显示像素的颜色
void colorWipe(ws2811_t* led, Color color, int wait_ms = 20) {
    for (int i = 0; i < LED_COUNT; i++) {
        led->channel[0].leds[i] = (color.r << 16) | (color.g << 8) | color.b;
        ws2811_render(led);
        std::this_thread::sleep_for(std::chrono::milliseconds(wait_ms));
    }
}

// 效果1 影院效果
void theaterChase(ws2811_t* led, Color color, int wait_ms = 50, int iterations = 10) {
    for (int j = 0; j < iterations; j++) {
        for (int q = 0; q < 3; q++) {
            for (int i = 0; i < LED_COUNT; i += 3) {
                led->channel[0].leds[i + q] = (color.r << 16) | (color.g << 8) | color.b;
            }
            ws2811_render(led);
            std::this_thread::sleep_for(std::chrono::milliseconds(wait_ms));
            for (int i = 0; i < LED_COUNT; i += 3) {
                led->channel[0].leds[i + q] = 0;
            }
        }
    }
}

// 效果2 彩虹
void rainbow(ws2811_t* led, int wait_ms = 20, int iterations = 1) {
    for (int j = 0; j < 256 * iterations; j++) {
        for (int i = 0; i < LED_COUNT; i++) {
            int pos = (i + j) & 255;
            led->channel[0].leds[i] = (wheel(pos).r << 16) | (wheel(pos).g << 8) | wheel(pos).b;
        }
        ws2811_render(led);
        std::this_thread::sleep_for(std::chrono::milliseconds(wait_ms));
    }
}