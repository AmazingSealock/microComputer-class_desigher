#include <eeprom.h>
#include <STC12C5620AD.H>
#include<intrins.h>
#include<lcd.h>



//------------------------------------------------------ 

//���ܣ�EEPROM�������� 

//��ڣ�uint address��ҳ��ַ0��8�� 

//���ڣ�

//��д���Ծ� 2009.11.08 

//------------------------------------------------------ 


void sector_erase(unsigned int address) // ��������
{ 

ISP_CONTR = ENABLE_ISP;    //��IAP���ܣ�����Flash�����ȴ�ʱ�� 

ISP_CMD = 0x03;                //ѡ��ҳ����ģʽ 

//-------------------------- 

address = DATA_FLASH_START_ADDRESS+address; 

ISP_ADDRH = (unsigned char)(address>>8);      //��ҳ��ַ 

ISP_ADDRL = (unsigned char)(address);      //��ҳ��ַ 

EA = 0; 

ISP_TRIG = 0x46;      //����ISP������ 

ISP_TRIG = 0xB9; 

_nop_(); 

EA = 1; 

//�ر�IAP����,����ISP�йص����⹦�ܼĴ��� 

ISP_CONTR = 0; 

ISP_CMD = 0; 

ISP_TRIG = 0; 

}


//------------------------------------------------------ 

//���ܣ����ֽڶ�

//��ڣ�uint address��ҳ��ַ0��8

//���ڣ�

//��д���Ծ� 2009.11.8 

//------------------------------------------------------ 

unsigned char read_eeprom_byte(unsigned int address) 

{ 

unsigned char data ch; 

     

ISP_CONTR = ENABLE_ISP;    //��ISP���ܣ�����Flash�����ȴ�ʱ�� 

ISP_CMD = 0x01;                //����Ϊ�ֽڶ�ģʽ

//-------------------------- 

address = DATA_FLASH_START_ADDRESS+address; 

ISP_ADDRH = (unsigned char)(address>>8);      //��ҳ��ַ 

ISP_ADDRL = (unsigned char)(address);      //��ҳ��ַ 

EA = 0; 

ISP_TRIG = 0x46;      //����ISP������ 

ISP_TRIG = 0xB9; 

_nop_(); 

ch = ISP_DATA;   //�������� 

EA = 1; 

//�ڴ��������֮ǰ,CUP����ͣ 

//�ر�IAP����,����ISP�йص����⹦�ܼĴ��� 

ISP_CONTR = 0; 

ISP_CMD = 0; 

ISP_TRIG = 0; 

// send_char_com(ch + 0x30); 

return ch; 

} 

 



//------------------------------------------------------ 

//���ܣ����ֽ�д 

//��ڣ�uint address��ҳ��ַ0��8��

//���ڣ�

//��д�� �Ծ� 2009.11.08 

//------------------------------------------------------ 

void write_eeprom_byte(unsigned int address,unsigned char ch) 

{    

 //Sector_Erase(address); 

ISP_CONTR = ENABLE_ISP;    //��IAP���ܣ�����Flash�����ȴ�ʱ�� 

ISP_CMD = 0x02;                //ѡ���ֽ�дģʽ 



address = DATA_FLASH_START_ADDRESS+address; 

ISP_ADDRH = (unsigned char)(address>>8);      //��ҳ��ַ 

ISP_ADDRL = (unsigned char)(address);      //��ҳ��ַ 

ISP_DATA = ch; 

EA = 0; 

ISP_TRIG = 0x46;      //����ISP������ 

ISP_TRIG = 0xB9; 

_nop_(); 

EA = 1; 

//�ر�IAP����,����ISP�йص����⹦�ܼĴ��� 

ISP_CONTR = 0; 

ISP_CMD = 0; 

ISP_TRIG = 0;  

} 


//------------------------------------------------------ 

//���ܣ�д�ַ��� 

//��ڣ�uint address��ҳ��ַ0��8��uchar *ch=Ҫд���ַ��� ��len=�ַ����ĳ��� 

//���ڣ�

//��д���Ծ� 2009.11.8 

//------------------------------------------------------ 

void write_eeprom_morebyte(unsigned int address,unsigned char *ch,unsigned char len) 

{  

unsigned char k = 0; 

sector_erase(address); 

do  

    { 

	write_eeprom_byte(address,*(ch + k)); 

	address++;  

    k++; 

    } 

while(k < len); 

} 


main()
{
 unsigned char i;
 unsigned long sum = 0;
 unsigned long arg;
 unsigned char eebuf[24];
 lcd_int();
  sum=0x01020304;
 for(i=0;i<4;i++) {
		eebuf[i]=read_eeprom_byte(i);
	}
        eebuf[0]=(unsigned char)(sum&0x000000ff);
        eebuf[1]=(unsigned char)((sum>>8)&0x000000ff);
		eebuf[2]=(unsigned char)((sum>>16)&0x000000ff);
		eebuf[3]=(unsigned char)((sum>>24)&0x000000ff);


 	sector_erase(0);
	
	write_eeprom_morebyte(0,eebuf,4);
    
	while (1)
	{
	for(i=0;i<4;i++) {
    Ftolcd(read_eeprom_byte(i),8888);
	Lcd_Dis();
    delay1(3000);

	}
    }	

}

