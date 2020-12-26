#ifndef __LED_KEY_H
#define __LED_KEY_H
#include "adc.h"
#include "control_temperature.h"
#include "time.h"

sfr AUXR = 0x8e;  



void Led_KeyInit(void);

void     send_byte(unsigned char);  				//�������ݺ���
void     led_real_disp(float RealData);   			//��ʾʵ���¶��������ǰ��λ
void     led_4int_disp(int intdata);				//��ʾ�趨�¶��ں���λ
void     led_write(unsigned char,unsigned char);	//��������ܣ���������ʾ���������
int 	 InputTemper(void);							//�����趨�¶�
unsigned char    receive_byte(void);				//���������źź���
unsigned char 	 key_read(void);					//��ֵ��ȡ����

extern unsigned char number;

#endif 