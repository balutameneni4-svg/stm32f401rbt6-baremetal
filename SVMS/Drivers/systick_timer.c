#include "systick_timer.h"

void km_mdelay(int m)
{  
	STK_LOAD=16000*m;
	while(!(STK_CTRL&(0x01<<16)));
}

void km_udelay(int n)
{
	STK_LOAD=16*n;
	while(!(STK_CTRL&(0x01<<16)));
}

void CLK_init(void)
{
	RCC_AHB1ENR = RCC_AHB1ENR | (0x01 << 1); // port B clock enable
	STK_CTRL |= 0X00000005;
	STK_VAL |=0X229;	
}

void LED_config(void)
{
	GPIOB_MODE  &= 0xF3FFFFFF; // making 27,26 bit fields in port B clear
	GPIOB_MODE  |= 0x04000000; // load 01 into 27, 26 bit fields in port B
}	

void systick_timer_init()
{
	//1.initilization phase
	CLK_init();
	
	//2.configuration phase
	LED_config();
}
