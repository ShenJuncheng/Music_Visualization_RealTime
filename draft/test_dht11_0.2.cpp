//
// Created by 23194 on 2023/2/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <wiringPi.h>

typedef unsigned char uint8;  //  typedef 重命名 char 为 uint8
typedef unsigned int  uint16;
typedef unsigned long uint32;

uint32 databuf;

/*
//初始化引脚
//上电1s内不操作，维持电平稳定
*/
void GPIO_init(int gpio_pin)
{
    pinMode(gpio_pin, OUTPUT); // set mode to output
    digitalWrite(gpio_pin, 1); // output a high level

    sleep(1);

    return;
}

/*
//起始信号
	1.主机初状态是高电平，要超过1s稳定电平
	2.主机再拉低延时18ms-30ms
	3.主机末状态是高电平，等待
*/
void DHT11_start(int gpio_pin)
{
    pinMode(gpio_pin, OUTPUT);
    digitalWrite(gpio_pin, 0);

    delay(25);

    digitalWrite(gpio_pin, 1);
    pinMode(gpio_pin, INPUT);
    pullUpDnControl(gpio_pin, PUD_UP);	//当引脚被配置为输入(INPUT)模式，使用函数pullUpDnControl来激活其内部的上拉电阻或下拉电阻

    delayMicroseconds(27);

    return;
}

/*
//主机接受数据
	1.主机接受到从机回复的响应信号
	2.格式0——54us的低电平+23到27us的高电平
	  格式1——54us的低电平+68到74us的高电平
	3.思路：从识别到低电平开始，然后去除掉掉前面54秒的低电平还有
*/
uint8 DHT11_read(int gpio_pin)
{
    uint8 crc, i;

    if (0 == digitalRead(gpio_pin))			//主机接收到从机发送的响应信号（低电平）
    {
        while(!digitalRead(gpio_pin));		//主机接收到从机发送的响应信号（高电平）

        for (i = 0; i < 32; i++)
        {
            while(digitalRead(gpio_pin));	//数据位开始的54us低电平
            while(!digitalRead(gpio_pin));	//数据位开始的高电平就开始

            delayMicroseconds(32);			//跳过位数据，32us已经是数据0和数据1的差距点

            databuf *= 2;

            if (digitalRead(gpio_pin) == 1)
            {
                databuf++;
            }
        }

        for (i = 0; i < 8; i++)
        {
            while (digitalRead(gpio_pin));
            while (!digitalRead(gpio_pin));

            delayMicroseconds(32);

            crc *= 2;
            if (digitalRead(gpio_pin) == 1)
            {
                crc++;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void test_led() {
    wiringPiSetup();
    pinMode(3,OUTPUT);
    while(1)
    {
        digitalWrite(3,LOW);
        delay(1000);
        digitalWrite(3,HIGH);
        delay(1000);
    }
//    return 0;
}
int main(int argc, char *argv[])
{
    test_led();
    
    if (2 != argc)
    {
        printf("Usge: %s <gpio_pin>\n", argv[0]);
        return 0;
    }

    if (-1 == wiringPiSetup())
    {
        printf("Setup WiringPi failed!\n");

        return 1;
    }

    while(1)
    {
        GPIO_init(atoi(argv[1]));

        DHT11_start(atoi(argv[1]));

        if (DHT11_read(atoi(argv[1])))
        {
            printf("RH:%d.%d\n", (databuf >> 24) & 0xff, (databuf >> 16) & 0xff);
            printf("TMP:%d.%d\n", (databuf >> 8) & 0xff, databuf & 0xff);

            databuf = 0;
        }
        else
        {
            printf("Sensor dosent ans!\n");
            databuf = 0;
        }

        sleep(3);
    }

    return 0;
}
