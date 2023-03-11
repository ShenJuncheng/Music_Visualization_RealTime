//
// Created by 23194 on 2023/3/11.
//






//
// Created by 23194 on 2023/3/1.
//

//https://blog.csdn.net/weixin_64131855/article/details/123671846
#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#define makerobo_PCF 120
int main (void)
{
    int sound_value;
    wiringPiSetup();
    pcf8591Setup(makerobo_PCF, 0x48);  //0x48 是 pcf8591 的 I2C 设备地址; pcf8591 可以有 8 个不同的 I2C 地址，但默认为 0x48
    while(1)
    {

        sound_value = analogRead(makerobo_PCF + 0);
        printf("test \n");
        printf("value: %d\n", sound_value);  //%d 输出的数据转化为十进制的一个数
        if (sound_value < 80){
            printf("Makerobo Voice In! \n");
        }
        delay(100);
    }
    return 0;
}

//https://baike.baidu.com/item/PCF8591/3916799?fr=aladdin
//https://forums.raspberrypi.com/viewtopic.php?t=177559