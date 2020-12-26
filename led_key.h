#ifndef __LED_KEY_H
#define __LED_KEY_H
#include "adc.h"
#include "control_temperature.h"
#include "time.h"

sfr AUXR = 0x8e;  



void Led_KeyInit(void);

void     send_byte(unsigned char);
void     led_real_disp(float RealData); 
void     led_4int_disp(int intdata);
void     led_write(unsigned char,unsigned char);
int 	 InputTemper(void);
unsigned char    receive_byte(void);
unsigned char 	 key_read(void);

extern unsigned char number;

#endif 