#ifndef __TIME_H
#define __TIME_H
#include "adc.h"
#include "control_temperature.h"
#include "led_key.h"
 	
void 	TIM0Init(void);
void    delay(int ms);
void 	long_delay(void);
void    short_delay(void);
void    delay1ms(unsigned char);
void 	delay_10ms(unsigned int time);


extern unsigned int count;
extern unsigned int temperCnt;
extern unsigned int delayCnt;
extern unsigned int resetFlg;
extern unsigned int Goflag;


#endif 