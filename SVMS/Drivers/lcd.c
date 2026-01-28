#include "lcd.h"
void GPIOB_Init()
{
RCC_AHB1ENR |=(0x01<<1);
GPIOB_MODE &=0xFFFCF000;
GPIOB_MODE |=0x00010555;
}
void delay(int a)
{
	int i;
	for(i=0;i<1670*a;i++)
	{
		;
	}
}
void Write_high_nibble(unsigned char ch)
{
GPIOB_ODR &= ~(0xF); 
GPIOB_ODR |= (ch>>4 & 0xF);
GPIOB_ODR |=(0x1<<8); 
delay(10);
GPIOB_ODR &=~(0x1<<8); 
}
void Write_low_nibble(unsigned char ch)
{


GPIOB_ODR &=~(0xF);
GPIOB_ODR |= (ch&0xF);
GPIOB_ODR |=(0x1<<8);  
	delay(10);
GPIOB_ODR &=~(0x1<<8); 

}
void KM_LCD_Write_CMD(unsigned char ch)
{
GPIOB_ODR &=~(0x01<<4);  
  Write_high_nibble(ch);
Write_low_nibble(ch);
}
void KM_LCD_Write_data(unsigned char  ch)
{
GPIOB_ODR |=(0x01<<4);  
    Write_high_nibble(ch);  
 Write_low_nibble(ch);

}
void KM_LCD_Write_Str(char *ch)
{
int i;
for(i=0;ch[i]!='\0';i++)
{
KM_LCD_Write_data(ch[i]);
}
}


void KM_LCD_Init(void)
{
GPIOB_Init();

KM_LCD_Write_CMD(0x33);
	delay(20);
KM_LCD_Write_CMD(0x32);
	delay(1);
KM_LCD_Write_CMD(0x0C);
KM_LCD_Write_CMD(0x01);

}
