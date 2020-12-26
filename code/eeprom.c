#include <eeprom.h>
#include <STC12C5620AD.H>
#include<intrins.h>
#include<lcd.h>



//------------------------------------------------------ 

//功能：EEPROM擦除扇区 

//入口：uint address＝页地址0～8。 

//出口：

//编写：赵军 2009.11.08 

//------------------------------------------------------ 


void sector_erase(unsigned int address) // 擦出扇区
{ 

ISP_CONTR = ENABLE_ISP;    //打开IAP功能，设置Flash操作等待时间 

ISP_CMD = 0x03;                //选择页擦除模式 

//-------------------------- 

address = DATA_FLASH_START_ADDRESS+address; 

ISP_ADDRH = (unsigned char)(address>>8);      //填页地址 

ISP_ADDRL = (unsigned char)(address);      //填页地址 

EA = 0; 

ISP_TRIG = 0x46;      //触发ISP处理器 

ISP_TRIG = 0xB9; 

_nop_(); 

EA = 1; 

//关闭IAP功能,清与ISP有关的特殊功能寄存器 

ISP_CONTR = 0; 

ISP_CMD = 0; 

ISP_TRIG = 0; 

}


//------------------------------------------------------ 

//功能：单字节读

//入口：uint address＝页地址0～8

//出口：

//编写：赵军 2009.11.8 

//------------------------------------------------------ 

unsigned char read_eeprom_byte(unsigned int address) 

{ 

unsigned char data ch; 

     

ISP_CONTR = ENABLE_ISP;    //打开ISP功能，设置Flash操作等待时间 

ISP_CMD = 0x01;                //设置为字节读模式

//-------------------------- 

address = DATA_FLASH_START_ADDRESS+address; 

ISP_ADDRH = (unsigned char)(address>>8);      //填页地址 

ISP_ADDRL = (unsigned char)(address);      //填页地址 

EA = 0; 

ISP_TRIG = 0x46;      //触发ISP处理器 

ISP_TRIG = 0xB9; 

_nop_(); 

ch = ISP_DATA;   //保存数据 

EA = 1; 

//在处理器完成之前,CUP将暂停 

//关闭IAP功能,清与ISP有关的特殊功能寄存器 

ISP_CONTR = 0; 

ISP_CMD = 0; 

ISP_TRIG = 0; 

// send_char_com(ch + 0x30); 

return ch; 

} 

 



//------------------------------------------------------ 

//功能：单字节写 

//入口：uint address＝页地址0～8。

//出口：

//编写： 赵军 2009.11.08 

//------------------------------------------------------ 

void write_eeprom_byte(unsigned int address,unsigned char ch) 

{    

 //Sector_Erase(address); 

ISP_CONTR = ENABLE_ISP;    //打开IAP功能，设置Flash操作等待时间 

ISP_CMD = 0x02;                //选择字节写模式 



address = DATA_FLASH_START_ADDRESS+address; 

ISP_ADDRH = (unsigned char)(address>>8);      //填页地址 

ISP_ADDRL = (unsigned char)(address);      //填页地址 

ISP_DATA = ch; 

EA = 0; 

ISP_TRIG = 0x46;      //触发ISP处理器 

ISP_TRIG = 0xB9; 

_nop_(); 

EA = 1; 

//关闭IAP功能,清与ISP有关的特殊功能寄存器 

ISP_CONTR = 0; 

ISP_CMD = 0; 

ISP_TRIG = 0;  

} 


//------------------------------------------------------ 

//功能：写字符串 

//入口：uint address＝页地址0～8；uchar *ch=要写的字符串 ；len=字符串的长度 

//出口：

//编写：赵军 2009.11.8 

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

