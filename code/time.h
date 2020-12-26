#ifndef __TIME_H
#define __TIME_H
#include "adc.h"
#include "control_temperature.h"
#include "led_key.h"
 	
void 	TIM0Init(void);					//定时器初始化函数
void    delay(int ms);					//软件延时，控制时间
void 	long_delay(void);
void    short_delay(void);
void    delay1ms(unsigned char);
void 	delay_10ms(unsigned int time);	//利用定时器延时


extern unsigned int count;
extern unsigned int temperCnt;
extern unsigned int delayCnt;
extern unsigned int resetFlg;
extern unsigned int Goflag;


#endif 