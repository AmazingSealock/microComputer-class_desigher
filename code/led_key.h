#ifndef __LED_KEY_H
#define __LED_KEY_H
#include "adc.h"
#include "control_temperature.h"
#include "time.h"

sfr AUXR = 0x8e;  



void Led_KeyInit(void);

void     send_byte(unsigned char);  				//发送数据函数
void     led_real_disp(float RealData);   			//显示实际温度在数码管前五位
void     led_4int_disp(int intdata);				//显示设定温度在后三位
void     led_write(unsigned char,unsigned char);	//控制数码管，将数据显示在数码管上
int 	 InputTemper(void);							//输入设定温度
unsigned char    receive_byte(void);				//接收主控信号函数
unsigned char 	 key_read(void);					//键值读取函数

extern unsigned char number;

#endif 