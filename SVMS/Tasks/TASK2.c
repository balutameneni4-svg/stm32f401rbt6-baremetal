#include"lcd.h"
#include"i2c.h"
static char buffer[200];
char Fetch[200];
#include<stdio.h>
#include"usart.h"
static int i,res,k;
 extern int ch;
 extern unsigned char rtc_data[50];
 extern unsigned char T_date[50];
void Task2_ReadLM35_WriteLCD_5Sec(void)
{
transmit_outsting("AT+CIPSTATUS\r\n");
		
		 for(i=0;i<100;i++)
		{
			buffer[i]=receive_char();
			if(( buffer[i]=='3'|| buffer[i]=='5' ))
			{  
				KM_LCD_Write_CMD(0XC9);
				KM_LCD_Write_Str("  ERROR");
				T_date[0]=ch;
				for(i=0;rtc_data[i]!='\0';i++)
				{
					T_date[i+1]=rtc_data[i];
				}	
				res=KM_I2C_Mem_Write(0X50,0X00,0X08,T_date,8);
		        break;
			}
			
		 if((buffer[i]=='K' && buffer[i-1]=='O')&&(buffer[i-6]=='2' || buffer[i-6]=='4'))
			{
				KM_LCD_Write_CMD(0XC9);
				KM_LCD_Write_Str("  OK");
         break;
			}	
	 	}
			transmit_outsting("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		
		 for(i=0;i<40;i++)
		{
			buffer[i]=receive_char();
			if(buffer[i]=='K' && buffer[i-1]=='O')
			{
				break;
			}
		}
		
		transmit_outsting("AT+CIPSEND=41\r\n");
			sprintf(Fetch,"GET /page.php?temp=%d&hum=90&dev=01\r\n\r\n",ch);
		   delay(500);
			transmit_outsting(Fetch);
	}
		