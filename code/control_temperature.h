#ifndef __MOTOR_COLD_H
#define __MOTOR_COLD_H
#include "adc.h"
#include "led_key.h"
#include "time.h"

sbit     P20        =  P2^0;
sbit     P21        =  P2^1;
sbit     P22        =  P2^2;
sbit     P23        =  P2^3;

void conTemInit(void);	//初始化将风扇和加热电阻开关断开
void coldDown(void);	//打开风扇开关，关闭加热电阻
void warmUp(void);		//打开加热电阻开关，关闭风扇

#endif 