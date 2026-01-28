#include"systick_timer.h"
#include"lcd.h"
#include"adc.h"
static int ss,mm,hh,WD,DD,MM,YY=0;
static char str[3];
extern unsigned char T_date[20];
int p;
void MODE_config(void)
{
	GPIOB_MODE &= 0xFCFFFFFF;
	GPIOB_MODE |= 0x01000000;
	GPIOC_MODE &= 0xFFCFFFFF;
	GPIOC_MODE |= 0x00000000;
	GPIOC_PUPDR &= 0xFFC0FFFF;
	GPIOC_PUPDR |= 0x00150000;
}
void Task5_SWMS_Config()
{
	MODE_config();
	KM_LCD_Write_CMD(0X01);
	GPIOB_ODR |=(0x1<<13);
  KM_LCD_Write_Str(" ENTER SWITCH-ENT ");
	while((GPIOC_IDR &(0x01<<10)))
	{
		;
	}
	KM_LCD_Write_CMD(0X01);
	KM_LCD_Write_Str(" HH:MM:SS ");
	KM_LCD_Write_CMD(0XC0);
	KM_LCD_Write_Str(" 00:00:00 ");
  while(1)
  {
		while(1)
	  {
		   if (!(GPIOC_IDR & (0x1<<8)))
	     {
				 KM_LCD_Write_CMD(0XC6);
	       KM_LCD_Write_Str(":");	
				 ss++;
				 str[0]=(char)(ss/10+48);
				 str[1]=(char)(ss%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
			 if (!(GPIOC_IDR & (0x1<<9)))
	     {
				 KM_LCD_Write_CMD(0XC6);
	       KM_LCD_Write_Str(":");	
				 ss--;
				 str[0]=(char)(ss/10+48);
				 str[1]=(char)(ss%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
			 if (ss>=60)
			 {
				 break;
			 }
			 if (!(GPIOC_IDR &(0x1<<10)))
			 {
				 break;
			 }
	 }
	 delay(500);
	 while(1)
	 {
		   if(!(GPIOC_IDR &(0x1<<8)))
	     {
				  KM_LCD_Write_CMD(0XC3);
	        KM_LCD_Write_Str(":");
					 mm++;
				  str[0]=(char)(mm/10+48);
				  str[1]=(char)(mm%10+48);
				  KM_LCD_Write_Str(str); 
				  delay(900);
			 }
			 if (!(GPIOC_IDR & (0x1<<9)))
	     {
				 KM_LCD_Write_CMD(0XC3);
	       KM_LCD_Write_Str(":");	
				 mm--;
				 str[0]=(char)(mm/10+48);
				 str[1]=(char)(mm%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
			 if (mm>=60)
			 {
				 break;
			 }
		   if(!(GPIOC_IDR &(0x1<<10)))
			 {
				 break;
			 }
		}
	  delay(500);
	  while(1)
	  {
		   if(!(GPIOC_IDR &(0x1<<8)))
	     {
				 KM_LCD_Write_CMD(0XC1);
					hh++;
				 str[0]=(char)(hh/10+48);
				 str[1]=(char)(hh%10+48);
				 KM_LCD_Write_Str(str); 
				 delay(900);
			 }
			 if (!(GPIOC_IDR & (0x1<<9)))
	     {
				 KM_LCD_Write_CMD(0XC1);	
				 hh--;
				 str[0]=(char)(hh/10+48);
				 str[1]=(char)(hh%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
			 if (hh>=24)
			 {
				 break;
			 }
		   if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	  }
	  while(1)
	  {
		   if(!(GPIOC_IDR &(0x01<<8)))
		   {
			   p=1;
			   break;
		   }
		   if(!(GPIOC_IDR &(0x01<<9)))
		   {
			   break;
		   }
	  }
	  if(p==1)
	  {
		   KM_LCD_Write_CMD(0X01);
		   break;
	  }
 }
//FOR DATE
	KM_LCD_Write_CMD(0X80);
	KM_LCD_Write_Str(" YY:MM:DD:WD ");
	KM_LCD_Write_CMD(0XC0);
	KM_LCD_Write_Str(" 00:00:00:00 ");
  while(1)
  {
			while(1)
	    {
				 if(!(GPIOC_IDR &(0x01<<8)))
				 {
						KM_LCD_Write_CMD(0XC9);
						KM_LCD_Write_Str(":");		
						WD++;
						str[0]=(char)(WD/10+48);
						str[1]=(char)(WD%10+48);
						KM_LCD_Write_Str(str);
						delay(900);
				 }
				 if (!(GPIOC_IDR & (0x1<<9)))
	       {
				   KM_LCD_Write_CMD(0XC9);
	         KM_LCD_Write_Str(":");	
				   WD--;
				   str[0]=(char)(WD/10+48);
				   str[1]=(char)(WD%10+48);
				   KM_LCD_Write_Str(str);
				   delay(900);
			   }
				 if (WD>=7)
			   {
					 GPIOB_ODR |=(0x1<<12);
				   break;
				 }
			   if(!(GPIOC_IDR &(0x01<<10)))
			   {
				   break;
			   }
	   }
		 GPIOB_ODR &=~(0x1<<12);
		 delay(500);
		 while(1)
	   {
		    if(!(GPIOC_IDR &(0x01<<8)))
	      {
				  KM_LCD_Write_CMD(0XC6);
	        KM_LCD_Write_Str(":");		
					DD++;
				  str[0]=(char)(DD/10+48);
				  str[1]=(char)(DD%10+48);
				  KM_LCD_Write_Str(str);
				  delay(900);
			  }
				if (!(GPIOC_IDR & (0x1<<9)))
	     {
				 KM_LCD_Write_CMD(0XC6);
	       KM_LCD_Write_Str(":");	
				 DD--;
				 str[0]=(char)(DD/10+48);
				 str[1]=(char)(DD%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
				if (DD>=30)
			   {
				   break;
			   }
			 
			 if(!(GPIOC_IDR &(0x01<<10)))
			 {
				 break;
			 }
	 }
	 delay(500);
	 while(1)
	 {
		   if(!(GPIOC_IDR &(0x01<<8)))
	     {
				  KM_LCD_Write_CMD(0XC3);
	        KM_LCD_Write_Str(":");
					MM++;
				  str[0]=(char)(MM/10+48);
				  str[1]=(char)(MM%10+48);
				  KM_LCD_Write_Str(str); 
				  delay(900);
			 }
			 if (!(GPIOC_IDR & (0x1<<9)))
	     {
				 KM_LCD_Write_CMD(0XC3);
	       KM_LCD_Write_Str(":");	
				 MM--;
				 str[0]=(char)(MM/10+48);
				 str[1]=(char)(MM%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
			 if (MM>=12)
			   {
					 GPIOB_ODR |=(0x1<<12);
				   break;
			   }
		  if(!(GPIOC_IDR &(0x01<<10)))
			{
				 break;
			}
	 }
	 GPIOB_ODR &=~(0x1<<12);
	 delay(500);
	 while(1)
	 {
		   if(!(GPIOC_IDR &(0x01<<8)))
	     {
				  KM_LCD_Write_CMD(0XC1);
					YY++;
				  str[0]=(char)(YY/10+48);
				  str[1]=(char)(YY%10+48);
				  KM_LCD_Write_Str(str); 
				 	delay(900);
			 }
			 if (!(GPIOC_IDR & (0x1<<9)))
	     {
				 KM_LCD_Write_CMD(0XC1);
				 YY--;
				 str[0]=(char)(YY/10+48);
				 str[1]=(char)(YY%10+48);
				 KM_LCD_Write_Str(str);
				 delay(900);
			 }
			 if (YY>=23)
			 {
				   break;
			 }
		 if(!(GPIOC_IDR &(0x01<<10)))
		 {
			  break;
		 }
	 } 
	 while(1)
	 {
		 if(!(GPIOC_IDR &(0x01<<8)))
		 {
			 p=1;
			 break;
		 }
		 if(!(GPIOC_IDR &(0x01<<9)))
		 {
			 break;
		 }
	 }
	 
	 if(p==1)
	 {
		 KM_LCD_Write_CMD(0X01);
		 break;
	 }
	 
 }
	 T_date[0]=((ss/10)*16+(ss%10));
   T_date[1]=((mm/10)*16+(mm%10));
   T_date[2]=((hh/10)*16+(hh%10));
   T_date[3]=((WD/10)*16+(WD%10));
   T_date[4]=((DD/10)*16+(DD%10));
   T_date[5]=((MM/10)*16+(MM%10));
   T_date[6]=((YY/10)*16+(YY%10));
 }
