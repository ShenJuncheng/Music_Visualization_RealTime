//
// Created by 23194 on 2023/2/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_keyboard_test();

int main()
{
    get_keyboard_test();
}

int get_keyboard_test() {
    // 获取从键盘输入的数据
    char buf[1024] = {0};
    printf("please input data: ");
    char *str = fgets(buf, sizeof(buf) - 1, stdin); // fgets()是阻塞的
    printf("buf : %s\n", buf);
    printf("str : %s\n", str);
    printf("len : %ld\n", strlen(buf));

    return 0;

}


