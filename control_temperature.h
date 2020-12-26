#ifndef __MOTOR_COLD_H
#define __MOTOR_COLD_H
#include "adc.h"
#include "led_key.h"
#include "time.h"

sbit     P20        =  P2^0;
sbit     P21        =  P2^1;
sbit     P22        =  P2^2;
sbit     P23        =  P2^3;

void conTemInit(void);
void coldDown(void);
void warmUp(void);

#endif 