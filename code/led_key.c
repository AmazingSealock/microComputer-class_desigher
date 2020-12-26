#include <led_key.h>

unsigned char code2[] = {0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b,0x01,0x80,0x00, 0x6f};
					  //  0    1    2    3    4    5    6    7    8    9    -    .   blank error

unsigned char number;
unsigned char keyFlg = 1;

unsigned int receive_buf[10];
unsigned char receive_point=0; 

unsigned int ten;//十位
unsigned char one;//个位
unsigned long decimal;//小数第一位
extern   unsigned char number;

void Led_KeyInit(void)
{
	SCON = 0x50;
	PCON = 0x00;
	AUXR = 0x00;                           //配置T1为波特率发生器
	TH1 = 0xFD;
	TL1 = 0xFD;                            //波特率9600
	TR1 = 1;                               //开启定时器T1
}

int InputTemper(void)
{
	while(1)
	{
		number = key_read();
		led_4int_disp(number);
		delay1ms(250);
		if(number != 255) break;
	}
	return number;
}

void led_4int_disp(int intdata)  
{
	unsigned char Lcd_Data[8];
	unsigned char i;
	Lcd_Data[0] = 12;
	Lcd_Data[1] = 12; 
	Lcd_Data[2] = 12;
	Lcd_Data[3] = 12;
	Lcd_Data[4] = 12; 
	Lcd_Data[5] = intdata/100;  intdata = intdata%100;
	Lcd_Data[6] = intdata/10;   intdata = intdata%10;
	Lcd_Data[7] = intdata/1;
	
	for(i = 0;i<8;i++)
	{
		Lcd_Data[i] = code2[Lcd_Data[i]];
	}
	
	for(i = 0;i<8;i++)  //通过串口发送显示数据，数码管显示
	{
		led_write(0x97-i,Lcd_Data[i]);
	}
	
}

void led_real_disp(float RealData)
{
	float m1; unsigned char Fuhao1; unsigned long Temp; unsigned char LCD_Data[8]; unsigned char i;

	if (RealData<0.0)  { m1 = -1.0*RealData; Fuhao1 = 1; }		   //处理正负号
	else               { m1 = RealData;      Fuhao1 = 0; }

	if (m1 >= 1000.0)     Temp = (unsigned long) m1;
	else if (m1 >= 100.0) Temp = (unsigned long)(m1*10);
	else if (m1 >= 10.0)	 Temp = (unsigned long)(m1*100);
	else                  Temp = (unsigned long)(m1*1000);

	if(Fuhao1 == 0) LCD_Data[3] = 12;   // 正数       
	else            LCD_Data[3] = 10;   // 负数

	LCD_Data[4] = (Temp / 1000) % 10; Temp = Temp % 1000;
	LCD_Data[5] =  Temp / 100;        Temp = Temp % 100;
	LCD_Data[6] =  Temp / 10;         Temp = Temp % 10;
	LCD_Data[7] =  Temp / 1;

	for(i = 0; i < 3; i++) { LCD_Data[i] = 0x00;}
	for(i = 3; i < 8; i++) { LCD_Data[i] = code2[LCD_Data[i]];}

	if (m1 < 10.0)        LCD_Data[4] = LCD_Data[4] | 0x80;
	else if (m1 < 100.0)  LCD_Data[5] = LCD_Data[5] | 0x80;
	else if (m1 < 1000.0) LCD_Data[6] = LCD_Data[6] | 0x80;

	for(i = 0; i < 8; i++)
	{
		led_write(0x97-i+3, LCD_Data[i]);
	}
}

void led_write(unsigned char cmd, unsigned char dta)
{
	send_byte(cmd); send_byte(dta);
}

unsigned char key_read(void)
{
	send_byte(0x15); return(receive_byte());
}

void send_byte(unsigned char out_byte)
{
	unsigned char i;
	cs = 0; 
	long_delay();
	for (i=0;i<8;i++)
	{
		if (out_byte & 0x80) { dat = 1; }
		else { dat = 0; }
		clk = 1; 
		short_delay(); 
		clk = 0; 
		short_delay(); 
		out_byte = out_byte*2;
	}
	dat = 0;
}

unsigned char receive_byte(void)
{
	unsigned char i, in_byte;

	dat = 1; long_delay();
	for (i=0;i<8;i++)
	{
		clk = 1; 
		short_delay(); 
		in_byte = in_byte*2;
		if (dat) 
		{ 
			in_byte = in_byte|0x01; 
		}
		clk = 0; 
		short_delay();
	}
	dat = 0; return(in_byte);
}

