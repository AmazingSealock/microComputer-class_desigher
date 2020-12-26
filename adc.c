#include "adc.h"
#include <sigmod.h>
#include <tc.h>

long     temp1;				     //�޷�������
long     temp2;				     //�з�������
long     tempp;				     //�������

float    A1out;                	 //����ֵ
float    A2out;					 //���ֵ
float    A3out;					 //�ߵ���ֵ
float    Azero;					 //���ֵ

float    AD_OUT;
float    cold;
unsigned char    in_mod;

void ADC_Init(void)
{
	in_mod = 8; //75mV
	CLK_DIV = 0x40;
	CS5550Init(); 
	wRIte_w(0x40,0x000011); 
	delay(1);											   
	BB = 1; 
	AA = 1; 
	wRIte_w(0xe8,0xffffff);
}

int GetTemper(int temper)
{
	readTemper();
	A1out = temp1 /(float)0x01000000 * 124.0; 
	if ((tempp  & 0x800000) == 0x800000) 
	{ 		
		A1out = - 1.0 * A1out; 		// ���� A/D ת������һͨ������mvֵ
	}	    
	A2out = (temp2 / (float)0x01000000) * 0.122264 * 1.00 + 0.0155 ;   // ���� A/D ת�����ڶ�ͨ������vֵ,������¶�
	datadealt();
	led_real_disp(AD_OUT);                    // ��ʾ����ֵ
	if(AD_OUT > temper)
		return 2;
	else
		return 3;
	
}


void readTemper(void)
{
	tempp = read_w(0x0e); 
	temp1 = read_w(0x16); 
	temp2 = read_w(0x18);

}

float couple_liner(unsigned char ch, float dat)
{
	unsigned char  i, line_no; float  kk, bb; float  *ptr;

	ch = ch - 10;
	if (ch < 11)        //cold compensation 
	{   
		ptr = cold_t[ch];

		for (i = 0;i < 2;i++)
		{  
			line_no = i; 
			if (cold < *(ptr+i)) break;
		}
		ptr = cold_k[ch]; kk = *(ptr+line_no);
		ptr = cold_b[ch]; bb = *(ptr+line_no);
		dat = dat + cold * kk + bb;
	}

	if (ch < 14)        //TC or TRD linerity 
	{   
		ptr = x_ad[ch];

		for (i = 0;i <= linery_no[ch];i++)
		{
			line_no = i; if( dat < *(ptr+i) ) break;
		}
		if (i > linery_no[ch]) 
		{ 
			ptr = x_ad[ch]; dat = *(ptr+line_no); 
		}
		ptr = k_ad[ch]; 
		kk = *(ptr+line_no);
		ptr = b_ad[ch]; 
		bb = *(ptr+line_no);
		dat = kk*dat + bb;
	}

	return dat;
}

//0-10V ������
void datadealt()
{
	unsigned char i;  unsigned char y;  float temp;

	cold = sqrt(2196200.0+((1.8639-(A2out + 1.00)*21.0)/0.00000388))-1481.96;   

	if ((cold > 69.9) || (cold < -25.0)) cold = 25.0;	   //��������¶ȼ�����

	for(i = 0; i < 1; i++)
	{
		y = in_mod;   //75mV
		if (y < 10)		            //DC
		{ 
			if ((y == 1)||(y == 6))  
			{
				temp = A1out * 1.00 / 107.0950469;        //26.78272514, 4-20mA,0-20mA
			}
			else if  (y == 3)            
			{
				temp = A1out * 1.00 / 53.54752343;   	   //100.4352193, 0-75mA
			}
			else if ((y == 2)||(y == 4))
			{
				temp = A1out * 1.00 / 102.8860541;    	   //102.8820078, 1-5V,0-5V
			}
			else if  (y == 5)
			{
				temp = A1out * 1.00 / 109.7725552;		   //0-10v(R8=6k)
			}
			else if  (y == 7)
			{
				temp = A1out * 1.00 / 20.0;			       //0-20mV
			}
			else if  (y == 8)
			{
				temp = A1out * 1.00 / 75.0;			       //0-75mV
			}
			else if  (y == 9)
			{
				temp = A1out * 1.00 / 100.0;			   //0-100mV
			}

			temp = temp * (75.0 - 0.0);
			if( y <= 2 ) 
			{
				temp = temp * 1.25 - (20.0 - 4.0) / 4.0;   // 4-20mA ,1-5V
				temp = temp + 4.0; 
			}
		}
		else if (y < 21) 	            // TC 
		{   
			temp = couple_liner(y, A1out*1.00);
		}
		else if (y < 24)	            // RTD 
		{
			temp = (1240.0 - 1.999658*A3out)*(A1out-A3out)/(1240.0-A1out) - 0.999658*A3out;
			temp = temp * 3892.601096 * 1.00 / (1240.0-A3out); 
			temp = couple_liner(y, temp);
		}
		AD_OUT = 8.7583*temp-296.193;
	}		    
}



//****************CS5550*******************//
void outb(unsigned char dat)
{
	unsigned char i;
	for(i = 0; i < 8; i++) 
	{
		CLK = 0; 
		if(dat & 0x80) MOSI = 1; 
		else MOSI = 0; 
		CLK = 1; 
		dat <<= 1;      
	}
	CLK = 0;
}

unsigned char inb()         
{
	unsigned char temp, i;
	for(i = 0; i < 8; i++) 
	{
		if(i == 7) 
			MOSI = 0; 
		else 
			MOSI = 1;

		CLK = 0; 
		temp <<= 1; 
		CLK = 1; 
		if(MISO) 
			temp |= 1; 
		else 
			temp &= 0xFE; 
		_nop_();	             
	}
	CLK = 0; return temp;
}

void wRIte_w(unsigned char cmd, unsigned long val)	 //��ָ���Ĵ���д������ Cmd=0x40+�Ĵ�����ַ
{
	CS_CS5550 = 0; 

	outb(cmd); outb(val >> 16); outb(val >> 8); outb(val);

	CS_CS5550 = 1;
}

unsigned long read_w(unsigned char cmd)     //��ȡָ���Ĵ������� Cmd=0x00+�Ĵ�����ַ
{
	unsigned long temp;

	CS_CS5550 = 0; 

	outb(cmd); 
	temp = ((unsigned long)inb() << 16); temp |= ((unsigned long)inb() << 8); temp |= inb();

	CS_CS5550 = 1;

	return temp;	
}   
   

void CS5550Init()
{
	wRIte_w(0x80,0xffffff); delay(1);

	wRIte_w(0xff,0xfffffe); delay(1);

	wRIte_w(0x40,0x000011); delay(1);            //����10����K=1(1��Ƶ), iCPU=1

	wRIte_w(0xe8,0xffffff); delay(1);   

	wRIte_w(0x4a,0x000138); delay(2);            //N = 312, 80ms
}