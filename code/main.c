#include <reg51.h>

#include <REG51.H>  
#include <intRIns.h>
#include <ABSACC.h>
#include <math.h>


#include "adc.h"
#include "control_temperature.h"
#include "led_key.h"
#include "time.h"

#define KEYNUM 0 //�������ø����¶�
#define ADCNUM 1 //ADģ��ת���õ��¶�
#define COLD   2 //����
#define WARM   3 //����


void config(void);



void main(void)
{
	unsigned int stepFlg = 0;
	int temper = 0;
	config();
	while(1)
	{
		if(Goflag == 1)
		{
			Goflag = 0;
			switch(stepFlg)
			{
				case KEYNUM:	//0
				{
					temper = InputTemper();
					stepFlg++;
					break;
				}
				case ADCNUM:	//1
				{
					stepFlg = GetTemper(temper);
					break;
				}
				case COLD:		//2
				{
					coldDown();
					stepFlg = 1;
					break;
				}
				case WARM:		//3
				{
					warmUp();
					stepFlg = 1;
					break;
				}
				default:		//����
				{
					stepFlg = 0;
					break;
				}
			}
			if(resetFlg == 1)
			{
				resetFlg = 0;
				stepFlg = 0;
			}
		}
		
	}
}

void config(void)
{   
	ADC_Init();
	TIM0Init();
	Led_KeyInit();
	conTemInit();
}







