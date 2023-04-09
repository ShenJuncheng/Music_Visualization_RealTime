//
// Created by JUNCHENG SHEN on 2023/3/14 0014.
//

#ifndef RPI_WS281X_WS2812B_H
#define RPI_WS281X_WS2812B_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <stdarg.h>
#include <getopt.h>
#include "clk.h"
#include "gpio.h"
#include "dma.h"
#include "pwm.h"
#include "ws2811.h"


// 下面的信息用于配置 ws2812b
#define TARGET_FREQ             WS2811_TARGET_FREQ /*定义触发频率*/
#define GPIO_PIN                18
#define DMA                     10
#define STRIP_TYPE              WS2811_STRIP_GBR        // WS2812/SK6812RGB integrated chip+leds


#define LED_COUNT               100
#define ARRAY_SIZE(stuff)       (sizeof(stuff) / sizeof(stuff[0]))
class WS2812B{

        public:
        int dotspos[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        ws2811_led_t dotcolors[8] =
        {
            0x00200000,  // red
            0x00201000,  // orange
            0x00202000,  // yellow
            0x00002000,  // green
            0x00002020,  // lightblue
            0x00000020,  // blue
            0x00100010,  // purple
            0x00200010,  // pink
        };
        /*颜色定义*/
        ws2811_led_t * matrix;          /*定义灯的RGB值buf*/
        ws2811_t ledstring =
        {
            .freq = TARGET_FREQ,
            .dmanum = DMA,
            .channel =
                     {
                         {
                                 .gpionum = GPIO_PIN,
                                 .invert = 0,
                                 .count = LED_COUNT,
                                 .strip_type = STRIP_TYPE,
                                 .brightness = 255,
                         },

                         {
                                 .gpionum = 0,
                                 .invert = 0,
                                 .count = 0,
                                 .brightness = 0,
                         },
                     },
        };
        WS2812B();
        int begin();
        int update();
        void off();
        void random_Color(void);
//        void rainbowCycle(uint8_t wait);
        void theaterChase(ws2811_led_t color, uint8_t wait);
        void colorWipe(ws2811_led_t color, uint8_t wait);
        void runningLights(ws2811_led_t color, uint8_t wait);
};


#endif //RPI_WS281X_WS2812B_H
