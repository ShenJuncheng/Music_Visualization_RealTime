//
// Created by 23194 on 2023/2/15.
//

#include <stdio.h>
#include <iostream>
#include <wiringPi.h>

using namespace std;

void test_led();

int main()
{
    test_led();
}

void test_led() {
    cout << "Hello, World!" << endl;
    wiringPiSetup();
    pinMode(3,OUTPUT);
    while(1)
    {
        digitalWrite(3,LOW);
        delay(1000);
        digitalWrite(3,HIGH);
        delay(1000);
    }
//    cout<<"hello world";
    return ;
}


