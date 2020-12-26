/***************************************************************************
                
****************************************************************************/
#ifndef EEPROM_H
#define EEPROM_H

#define DATA_FLASH_START_ADDRESS 0x0000 	  //12C5620AD EEPROM��ʼ��ַ
#define ENABLE_ISP 0x84 //ϵͳʱ�� 4M   <6M   

void sector_erase(unsigned int address); //��������
unsigned char read_eeprom_byte(unsigned int address);//���ֽڶ�
void write_eeprom_byte(unsigned int address,unsigned char ch);//���ֽ�д
void write_eeprom_morebyte(unsigned int address,unsigned char *ch,unsigned char len);//���ֽ�д 
#endif