#include"lcd.h"
#include"systick_timer.h"
#include"i2c.h"

extern unsigned char rtc_data[20];
static char str[3],a,b;
static int res;
void Task1_ReadRTC_WriteLCD_1Sec(void)
	{
    res=KM_I2C_Mem_Read( 0x68, 0x00, 0x01, rtc_data, 7); 
		KM_LCD_Write_CMD(0x80);
		delay(300);
		
		//display hours
		 a=(char)((rtc_data[2]%0X10)+48);
	   b=(char)(((rtc_data[2]/0X10)%10)+48);
		 str[0]=b;
		 str[1]=a;
		 KM_LCD_Write_Str(" ");
		 KM_LCD_Write_Str(str);
		 KM_LCD_Write_Str(":");
		
		//display minutes
		a=(char)((rtc_data[1]%0X10)+48);
	 b=(char)(((rtc_data[1]/0X10))+48);
		  str[0]=b;
		  str[1]=a;
		KM_LCD_Write_Str(str);
		KM_LCD_Write_Str(":");
		
   //display seconds
		a=(char)((rtc_data[0]%0X10)+48);
	 b=(char)(((rtc_data[0]/0X10)%10)+48);
		  str[0]=b;
		  str[1]=a;
		KM_LCD_Write_Str(str);
		
		//display date
		KM_LCD_Write_CMD(0xC0);
		
		 a=(char)((rtc_data[4]%0X10)+48);
	   b=(char)(((rtc_data[4]/0X10)%10)+48);
		  str[0]=b;
		  str[1]=a;
		KM_LCD_Write_Str(" ");
		KM_LCD_Write_Str(str);
		KM_LCD_Write_Str("/");
		
		//dislay month
		 a=(char)((rtc_data[5]%0X10)+48);
	   b=(char)(((rtc_data[5]/0X10)%10)+48);
		  str[0]=b;
		  str[1]=a;
		KM_LCD_Write_Str(str);
		KM_LCD_Write_Str("/");
		
		//display year
		 a=(char)((rtc_data[6]%0X10)+48);
	   b=(char)(((rtc_data[6]/0X10)%10)+48);
		  str[0]=b;
		  str[1]=a;
		KM_LCD_Write_Str(str);
		
	  }

	

