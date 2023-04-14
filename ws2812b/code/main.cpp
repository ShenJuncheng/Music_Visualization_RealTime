//
// Created by JUNCHENG SHEN on 2023/3/14 0014.
//
#include "WS2812B.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    WS2812B *ws2812b = new WS2812B();
    ws2812b->begin();
    while (1) {
        ws2812b->matrix_bottom();
        ws2812b->update();
        usleep(1000000 / 15);
    }
}
