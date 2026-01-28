#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
	
#define GPIOB_MODE (*((int *)0x40020400))
#define GPIOB_ODR (*((int *)0x40020414))	
	
void Write_high_nibble(unsigned char ch);
void Write_low_nibble(unsigned char ch);
void KM_LCD_Write_CMD(unsigned char );
void KM_LCD_Write_data(unsigned char  ch);
void KM_LCD_Write_Str(char *ch);
void KM_LCD_Init(void);
void GPIOB_Init(void);
void delay(int a);


