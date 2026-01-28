#include"adc.h"
#include"lcd.h"
static char str[3],a,b;
static int result;
int ch;
void Task3_Wi_Fi_Tx(void)
{
	//display temperature
	 KM_LCD_Write_CMD(0X89);
	 ADC_CR2|=(0x01<<30);
	 while(!(ADC_SR&(0x01<<1)))
	 {
		 ;
	 }
	 result=ADC_DR ;
	 ch=(result*3000)/(4096*10);
	 a=(char)((ch%10)+48);
	 b=(char)(((ch/10)%10)+48);
   str[0]=b;
	 str[1]=a;
	 KM_LCD_Write_Str(" T:");
	 KM_LCD_Write_Str(str);
	 KM_LCD_Write_Str("DC");
//	 KM_LCD_Write_CMD(0XCD);
//	 KM_LCD_Write_Str("OK");
}
