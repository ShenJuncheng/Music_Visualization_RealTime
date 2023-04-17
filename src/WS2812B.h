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
#include <cmath>
#include <vector>
#include <QVector>


/*!
 * The following information is used to configure ws2812b
 */
#define TARGET_FREQ             WS2811_TARGET_FREQ /*定义触发频率*/
#define GPIO_PIN                18
#define DMA                     10
#define STRIP_TYPE              WS2811_STRIP_GBR        // WS2812/SK6812RGB integrated chip+leds


#define LED_COUNT               300
#define ARRAY_SIZE(stuff)       (sizeof(stuff) / sizeof(stuff[0]))
class WS2812B{

        public:
        int dotspos[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        ws2811_led_t dotcolors[8] =
        {
            //0x00GGBBRR
            0x00200000,
            0x00201000,
            0x00202000,
            0x00002000,
            0x00002020,
            0x00000020,
            0x00100010,
            0x00200010,
        };
        /*color definition*/
        ws2811_led_t * matrix;          /*Defines the RGB value buf of the light*/
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
        void updateLEDMode1(double amplitude);
        void updateLEDMode2(double amplitude);
        void updateLEDMode3(double amplitude);
};


#endif //RPI_WS281X_WS2812B_H
