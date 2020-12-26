#ifndef __ADC_H
#define __ADC_H	
#include <reg51.h>
#include <intRIns.h>
#include <ABSACC.h>
#include <math.h>



#include "control_temperature.h"
#include "led_key.h"
#include "time.h"


sbit     CS_CS5550  =  P1^0;	 //                          --OUT
sbit     MOSI       =  P1^1;	 //                          --OUT
sbit     MISO       =  P1^2;	 //                          --IN
sbit     CLK        =  P1^3; 	 //                          --OUT
 
sbit     dat        =  P1^4;
sbit     key        =  P1^5;
sbit     cs         =  P1^6;
sbit     clk        =  P1^7;

sbit     BB         =  P3^2;     //4051-B,                   --OUT
sbit     AA         =  P3^3;     //4051-A,                   --OUT
sfr      CLK_DIV    =  0x97;



int	 	 GetTemper(int temper);
void 	 readTemper(void);
void     outb(unsigned char dat);
void     wRIte_w(unsigned char cmd, unsigned long val);
void     CS5550Init();
void     datadealt();
void     init_time0();
float    couple_liner(unsigned char ch,float dat);
unsigned char    inb(void);
unsigned long    read_w(unsigned char cmd);
 							   
void ADC_Init(void);				//ADC≥ı ºªØ

#endif 
