#include "adc.h"

void adc_init(void)
{
  MUX_init();
	RCC_Init();
	RCC_APB2ENR|=(0x01<<8); //enable ADC clock
	ADC_CR2|=(0x01<<0);//set oth bit
	ADC_CR2|=(0x01<<1);//set 1st bit
	ADC_CR2|=(0x01<<10);//set 10th bit
  ADC_SQR3=10;
}

void MUX_init(void)
{
	RCC_AHB1ENR |=(0x01<<2);//enable port c clock
	GPIOC_MODE&=0xfffffffc;//clear 1-0 positions 
	GPIOC_MODE|=0x00000003;//load "11" in 1-0 positions on GPIOC_MODE
}

void RCC_Init(void)
{
	RCC_AHB1ENR |=(0x01<<1);
	RCC_AHB1ENR |=(0x01<<2);
	GPIOB_MODE &=0xFFFCF000;
	GPIOB_MODE |=0x00010555; 
	GPIOC_MODE &=0xFFFCFFFF;
	GPIOC_MODE |=0X00000000;
	GPIOC_PUPDR &=0xFFCFFFFF;
	GPIOC_PUPDR |=0x00100000;
	GPIOB_ODR &=~(0x13<<4); 
}
