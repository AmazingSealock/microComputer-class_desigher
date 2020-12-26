/***************************************************************************
                
****************************************************************************/
#ifndef EEPROM_H
#define EEPROM_H

#define DATA_FLASH_START_ADDRESS 0x0000 	  //12C5620AD EEPROM起始地址
#define ENABLE_ISP 0x84 //系统时钟 4M   <6M   

void sector_erase(unsigned int address); //擦出扇区
unsigned char read_eeprom_byte(unsigned int address);//单字节读
void write_eeprom_byte(unsigned int address,unsigned char ch);//单字节写
void write_eeprom_morebyte(unsigned int address,unsigned char *ch,unsigned char len);//多字节写 
#endif