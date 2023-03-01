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
wiringPiSetup ();
pcf8591Setup (makerobo_PCE, Ox48);
while(1)
{

sound_value = analogRead (makerobo_PCF + 0);
printf("value: &d\n", sound_value);

if (sound_value < 80){
printf("Makerobo Voice In! \n");
}
delay(100);
}
return 0;
}

