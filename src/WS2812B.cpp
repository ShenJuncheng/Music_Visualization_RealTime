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
    /*Initialize ws2812b*/
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
    return 0;
}

/*!
 *
 * @param m_amplitude
 */
void WS2812B::updateLEDMode2(double m_amplitude)
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

/*!
 *
 * @param m_amplitude
 */
void WS2812B::updateLEDMode3(double m_amplitude)
{
    const int SCROLL_DELAY_MS = 10;
    const double SCROLL_SPEED_SCALE = 10.0;
    double amplitude_diff = abs(m_amplitude - 0.5);
    int scroll_speed = int(amplitude_diff * SCROLL_SPEED_SCALE);

    // Calculate the brightness based on the amplitude difference
    int brightness = int(255 * amplitude_diff);

    // Shift all LEDs to the right from the middle
    for (int i = LED_COUNT - 1; i > LED_COUNT / 2; i--) {
        matrix[i] = matrix[i - 1];
    }

    // Shift all LEDs to the left from the middle
    for (int i = 0; i < LED_COUNT / 2 - 1; i++) {
        matrix[i] = matrix[i + 1];
    }

    // Set the color of the middle LEDs based on the current dotcolors index
    static int dotcolors_index = 0;
    ws2811_led_t current_color = dotcolors[dotcolors_index];
    dotcolors_index = (dotcolors_index + 1) % ARRAY_SIZE(dotcolors);

    // Adjust the brightness of the current color
    int r = (current_color & 0x00FF0000) >> 16;
    int g = (current_color & 0x0000FF00) >> 8;
    int b = (current_color & 0x000000FF);

    r = (r * brightness) / 255;
    g = (g * brightness) / 255;
    b = (b * brightness) / 255;

    // Set the middle LED colors to the adjusted color
    matrix[LED_COUNT / 2 - 1] = (g << 16) | (b << 8) | r;
    matrix[LED_COUNT / 2] = (g << 16) | (b << 8) | r;

    update();

    // Delay the loop based on the calculated scroll speed
    QCoreApplication::processEvents();
    QTime loop_timer;
    loop_timer.start();
    while (loop_timer.elapsed() < SCROLL_DELAY_MS - scroll_speed) {
        QCoreApplication::processEvents();
    }
}

/*!
 *
 * @param m_amplitude
 */
void WS2812B::updateLEDMode1(double m_amplitude)
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
            matrix[i] = 0x000000ff;
        } else {
            // If the LED is not within the range of lit LEDs, turn it off
            matrix[i] = 0x00000000;
        }
    }

    for (int i = middle_index - 1; i >= 0; i--) {
        if (i > middle_index - half_leds - 1) {
            matrix[i] = 0x000000ff;
        } else {
            // If the LED is not within the range of lit LEDs, turn it off
            matrix[i] = 0x00000000;
        }
    }
    update();
}




int WS2812B::update() {
    /*Update LED display status*/
    int loop = 0;
    /*Refresh the bgr value to the led buffer*/
    for (loop = 0; loop < LED_COUNT; loop++) {
        ledstring.channel[0].leds[loop] = matrix[loop];/*Configure the content of the cache area to the WS2812 configuration space*/
    }
    ws2811_return_t ret;
    /*Update to display on LED lights*/
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }
    return 0;
}

void WS2812B::off() {
    /*turn off all LEDs*/
    int loop = 0;
    for (loop = 0; loop < LED_COUNT; loop++) {
        matrix[loop] = 0x00000000;
    }
    update();
}

