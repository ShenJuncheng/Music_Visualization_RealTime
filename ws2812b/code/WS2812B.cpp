//
// Created by JUNCHENG SHEN on 2023/3/14 0014.
//



#include "WS2812B.h"


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
}


/*按照一种灯光模式设置所有的led灯*/
void WS2812B::matrix_bottom(void) {
    int i;

    for (i = 0; i < LED_COUNT; i++) {
        matrix[i] = dotcolors[rand() % (sizeof(dotcolors) / sizeof(dotcolors[0]))];
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
}

int WS2812B::off() {
    /*关闭所有的LED*/
    int loop = 0;
    for (loop = 0; loop < LED_COUNT; loop++) {
        matrix[loop] = 0;
    }
    update();
}

