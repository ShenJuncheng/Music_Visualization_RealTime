//
// Created by JUNCHENG SHEN on 2023/3/14 0014.
//


#include "WS2812B.h"
#include <random>
#include <vector>
#include <algorithm>
#include <QVector>
#include <iostream>
#include <QCoreApplication>
#include <QTime>
#include <cmath>

using namespace std;

WS2812B::WS2812B() {
    matrix = (ws2811_led_t *) malloc(sizeof(ws2811_led_t) * LED_COUNT); /*定义灯的缓存区*/

}

int WS2812B::begin() {
    ws2811_return_t ret;
    /*初始化ws2812b*/
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
    return 0;
}

// according light count
void WS2812B::updateLEDMode1(double m_amplitude)
{
    double amplitude = abs(m_amplitude - 0.098) / 0.05;

    if(amplitude <= 0.135){
        for (int i = 0; i < LED_COUNT * 0.135; i++) {
            matrix[i] = 0x00000001 * 0.135; // 红色，乘以振幅
        }
        update();
    }
    else{
        int lit_leds = int(LED_COUNT * amplitude);

        for (int i = 0; i < LED_COUNT; i++) {
            if (i < lit_leds) {
                matrix[i] = 0x00ff0000 * amplitude; // 红色，乘以振幅
            } else {
                matrix[i] = 0x00000000; // 熄灭
            }
        }
        update();
    }
}


void WS2812B::updateLEDMode2(double m_amplitude)
{
    // Normalize the amplitude
    double amplitude = abs(m_amplitude - 0.098) / 0.05;
    // Calculate the brightness value based on the amplitude
    int brightness = int(255 * amplitude);

    // Clamp the brightness value between 0 and 255
    brightness = max(0, min(255, brightness));

    // Apply the brightness to all LEDs
    for (int i = 0; i < LED_COUNT; i++) {
        // Define the color (white) with the calculated brightness
        uint32_t color = (brightness << 16) | (brightness << 8) | brightness;

        // Set the LED color
        matrix[i] = color;
    }

    // Update the LED strip
    update();

}
void WS2812B::updateLEDMode3(double m_amplitude)
{

    double amplitude_diff = abs(m_amplitude - 0.5);

    // Scale factor to increase the number of lit LEDs
    double scale_factor = 4.0;

    // Calculate the number of LEDs to light up based on the amplitude difference and scale factor
    int lit_leds = int(LED_COUNT * amplitude_diff * scale_factor);

    // Calculate the middle index of the LED strip
    int middle_index = LED_COUNT / 2;
    int half_leds = lit_leds / 2;

    for (int i = middle_index; i < LED_COUNT; i++) {
        if (i < middle_index + half_leds) {
            matrix[i] = 0x00ffffff;
        } else {
            // If the LED is not within the range of lit LEDs, turn it off
            matrix[i] = 0x00010101;
        }
    }

    for (int i = middle_index - 1; i >= 0; i--) {
        if (i > middle_index - half_leds - 1) {
            matrix[i] = 0x00ffffff;
        } else {
            // If the LED is not within the range of lit LEDs, turn it off
            matrix[i] = 0x00010101;
        }
    }
    update();
}


//void WS2812B::updateLEDMode4(double m_amplitude)
//{
//    const int SCROLL_DELAY_MS = 10;
//    const double SCROLL_SPEED_SCALE = 10.0;
//    double amplitude_diff = abs(m_amplitude - 0.5);
//    int scroll_speed = int(amplitude_diff * SCROLL_SPEED_SCALE);

//    // Calculate the brightness based on the amplitude difference
//    int brightness = int(255 * amplitude_diff);

//    // Shift all LEDs to the right
//    for (int i = LED_COUNT - 1; i > 0; i--) {
//        matrix[i] = matrix[i - 1];
//    }

//    // Set the color of the first LED based on the calculated brightness
//    matrix[0] = (brightness << 16) | (brightness << 8) | brightness;

//    update();

//    // Delay the loop based on the calculated scroll speed
//    QCoreApplication::processEvents();
//    QTime loop_timer;
//    loop_timer.start();
//    while (loop_timer.elapsed() < SCROLL_DELAY_MS - scroll_speed) {
//        QCoreApplication::processEvents();
//    }
//}
void WS2812B::updateLEDMode4(double m_amplitude)
{
    const int SCROLL_DELAY_MS = 10;
    const double SCROLL_SPEED_SCALE = 10.0;
    double amplitude_diff = abs(m_amplitude - 0.5);
    int scroll_speed = int(amplitude_diff * SCROLL_SPEED_SCALE);

    // Calculate the brightness based on the amplitude difference
    int brightness = int(255 * amplitude_diff);

    // Shift all LEDs to the right
    for (int i = LED_COUNT - 1; i > 0; i--) {
        matrix[i] = matrix[i - 1];
    }

    // Set the color of the first LED based on the calculated brightness
    matrix[0] = (brightness << 16) | (brightness << 8) | brightness;

    update();

    // Delay the loop based on the calculated scroll speed
    QCoreApplication::processEvents();
    QTime loop_timer;
    loop_timer.start();
    while (loop_timer.elapsed() < SCROLL_DELAY_MS - scroll_speed) {
        QCoreApplication::processEvents();
    }
}


int WS2812B::update() {
    /*更新LED显示状态*/
    int loop = 0;
    /*刷新bgr值到led缓存区*/
    for (loop = 0; loop < LED_COUNT; loop++) {
        ledstring.channel[0].leds[loop] = matrix[loop];/*将缓存区的内容配置到WS2812配置空间*/
    }
    ws2811_return_t ret;
    /*更新到LED灯上显示*/
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
    return 0;
}

void WS2812B::off() {
    /*关闭所有的LED*/
    int loop = 0;
    for (loop = 0; loop < LED_COUNT; loop++) {
        matrix[loop] = 0x00000000;
    }
    update();
}

