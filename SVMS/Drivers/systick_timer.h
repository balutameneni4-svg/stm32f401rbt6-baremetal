#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
	
#define GPIOB_MODE  (*((int *)0x40020400))
#define GPIOB_ODR   (*((int *)0x40020414))
	
#define STK_CTRL    (*((int *)0xE000E010))
#define STK_LOAD    (*((int *)0xE000E014))	
#define STK_VAL     (*((int *)0xE000E018))
	
void CLK_init(void);
void LED_config(void);
void systick(void);
void systick_timer_init(void);
