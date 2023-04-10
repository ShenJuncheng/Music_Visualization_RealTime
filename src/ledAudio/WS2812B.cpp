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


// according light count
void WS2812B::updateLEDMode1(double amplitude)
{

    if(amplitude < 132 && amplitude > 124){

        for (int i = 0; i < LED_COUNT; i++) {
            matrix[i] = 0;
        }
        update();
    }
    else{
        /*颜色值使用二进制移位操作（<<）分别左移 16 位（红色通道）,
         * 8 位（绿色通道）和 0 位（蓝色通道）,
         * 然后使用位或操作（|）将这些通道的值组合起来，形成一个完整的颜色值*/
//        ws2811_led_t color = (int(255 * amplitude) << 16) | (int(255 * amplitude) << 8) | int(255 * amplitude);
//        for (int i = 0; i < LED_COUNT; i++) {
//            ws2812b->matrix[i] = color;
//        }
//        ws2812b->update();
        int lit_led_count = int(100 * abs(amplitude - 128));
        // 将前 lit_led_count 个 LED 点亮为白色，其余 LED 关闭
        ws2811_led_t whiteColor = 0xFFFFFF;
//        ws2811_led_t blackColor = 0x000000;

        for (int i = 0; i < LED_COUNT; i++) {
            if (i < lit_led_count) {
                matrix[i] = whiteColor;
            }
        }
        update();
    }

}

void WS2812B::updateLEDMode2(double amplitude)
{
    int lit_leds = int(LED_COUNT * amplitude);

    for (int i = 0; i < LED_COUNT; i++) {
        if (i < lit_leds) {
            matrix[i] = 0x00000002; // 红色
        } else {
            matrix[i] = 0x00000000; // 熄灭
        }
    }

    update();
}
void WS2812B::updateLEDMode3(double amplitude)
{

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

