#include "lcd.h"
#include "systick_timer.h"
#include "i2c.h"
#include "adc.h"
#include "usart.h"
#include "TASK.h"

int wifi(int );
//static char buffer[200];
//static char Fetch[200];
#include<stdio.h>


unsigned char T_date[]={0x00,0x37,0x12,0x01,0x26,0x11,0x23};
unsigned char rtc_data[20];
 char str[3],a,b;
int res,i,result,x,n;
int main()
{
	KM_LCD_Init();
	systick_timer_init();
	adc_init();
	KM_I2C1_Init();
	KM_I2C1_Config();
	Task5_SWMS_Config();
  res=KM_I2C_Mem_Write(0X68,0X00,0X01,T_date,7);
	usart6();
	while(1)
	{
		  n=5;
		  while(n)
		  {
         Task1_ReadRTC_WriteLCD_1Sec();
		     n--;
	    }
       Task3_Wi_Fi_Tx();
	  	 Task2_ReadLM35_WriteLCD_5Sec();
	}
}
