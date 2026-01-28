#include "usart.h"
 
void UART6_MODE_Init(void)
{
	RCC_AHB1ENR |= 0x01<<2;								//clock enable for Port C
	while(!(RCC_AHB1ENR & 0x01<<2)); 			//wait until bit is set
	GPIOC_MODE |= 0x0000A000;						//alternate function mode PC6, PC7
	GPIOC_AFRL |= 0x88000000;						//PC6 acts as TX, PC7 acts as RX	
}	
 
void UART6_Config(void)
{
	RCC_APB2ENR |= (0x01 << 5);					 //UART6 clock enable.
	while(!(RCC_APB2ENR & (0x01<<5)));  	//wait until bit is set
	UART6_CR1 |= 0x0C;									//TX, RX enable
	UART6_BRR |= 0x87;									//Baud rate
	UART6_CR1 |= (0x01<<13);						//UART enable
}	

void transmit_char(unsigned char ch)
{
	while(!(UART6_SR&(0x01<<7)))
	{
		;
	}
	UART6_DR = ch;
}

unsigned char receive_char(void)
{
	while(!(UART6_SR&(0x01<<5)))
	{
		;
  }
	return UART6_DR ;
}
	
void transmit_outsting(char ch[])
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		transmit_char(ch[i]); 
	}
}

void usart6()
{	
	UART6_MODE_Init();
	UART6_Config();	
}
