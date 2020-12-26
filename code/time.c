#include <time.h>

unsigned int count;
unsigned int temperCnt;
unsigned int delayCnt;
unsigned int resetFlg = 0;
unsigned int Goflag;


void TIM0Init(void)
{
	IE = 0x83;
	TMOD = 0x21;  
	TH0 = 0xD8;
	TL0 = 0xF0;               
	TR0  = 1;
}
	
void time0() interrupt 1         //10ms¶¨Ê±ÖÐ¶Ï
{
    TH0 = 0xD8;
	TL0 = 0xF0;  
	count++;
	delayCnt++;
	temperCnt++;
	Goflag = 1;
}

void INT0Interrupt0() interrupt 0
{
	resetFlg = 1;
}

void delay1ms(unsigned char time)
{
	unsigned char i; unsigned int j;
	for (i=0;i<time;i++)
	{
		for(j=0;j<355;j++){;}
	}
}
   
void long_delay(void)
{
	unsigned char i;
	for (i=0;i<0x30;i++){;}
}

void short_delay(void)
{
	unsigned char i;
	for (i=0;i<8;i++){;}
}
   
void delay_10ms(unsigned int time)
{
	count = 0;
    while(count < time);

}  

void delay(int ms)	  //1 ms
{
	unsigned int j, g;
	for(j = 0; j < ms; j++)
	{			 
		for(g = 0; g < 335; g++)
		{
			_nop_(); _nop_(); _nop_(); _nop_(); 
		}
	}
}

