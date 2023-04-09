//
// Created by JUNCHENG SHEN on 2023/3/14 0014.
//


#include "WS2812B.h"
#include <random>

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


/*按照一种灯光模式设置所有的led灯*/
void WS2812B::random_Color(void) {
    int i;
    for (i = 0; i < LED_COUNT; i++) {
        matrix[i] = dotcolors[rand() % (sizeof(dotcolors) / sizeof(dotcolors[0]))];
    }
}

//// 彩虹轮函数，用于彩虹循环
//ws2811_led_t Wheel(uint8_t WheelPos) {
//    WheelPos = 255 - WheelPos;
//    if (WheelPos < 85) {
//        return ((255 - WheelPos * 3) << 16) | ((WheelPos * 3) << 8);
//    } else if (WheelPos < 170) {
//        WheelPos -= 85;
//        return ((WheelPos * 3) << 16) | ((255 - WheelPos * 3) << 8);
//    } else {
//        WheelPos -= 170;
//        return ((WheelPos * 3) << 16) | (WheelPos * 3);
//    }
//}

//// 灯带彩虹循环
//void WS2812B::rainbowCycle(uint8_t wait) {
//    uint16_t i, j;

//    for (j = 0; j < 256 * 5; j++) {
//        for (i = 0; i < LED_COUNT; i++) {
//            matrix[i] = Wheel(((i * 256 / LED_COUNT) + j) & 255);
//        }
//        update();
//        usleep(wait * 1000);
//    }
//}

// 剧院追踪模式
void WS2812B::theaterChase(ws2811_led_t color, uint8_t wait) {
    for (int j = 0; j < 10; j++) {
        for (int q = 0; q < 3; q++) {
            for (int i = 0; i < LED_COUNT; i = i + 3) {
                matrix[i + q] = color;
            }
            update();

            usleep(wait * 1000);

            for (int i = 0; i < LED_COUNT; i = i + 3) {
                matrix[i + q] = 0;
            }
        }
    }
}


// 渐变擦除
void WS2812B::colorWipe(ws2811_led_t color, uint8_t wait) {
    for (uint16_t i = 0; i < LED_COUNT; i++) {
        matrix[i] = color;
        update();
        usleep(wait * 1000);
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
        matrix[loop] = 0;
    }
    update();
}

