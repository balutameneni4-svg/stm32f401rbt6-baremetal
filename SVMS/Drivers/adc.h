#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
	
#define GPIOB_MODE  (*((int *)0x40020400))
#define GPIOB_ODR   (*((int *)0x40020414))
	
#define GPIOC_MODE  (*((int *)0x40020800))
#define GPIOC_IDR   (*((int *)0x40020810))	
#define GPIOC_PUPDR (*((int *)0x4002080C))
	
#define STK_CTRL    (*((int *)0xE000E010))
#define STK_LOAD    (*((int *)0xE000E014))	
#define STK_VAL     (*((int *)0xE000E018))
		
#define ADC_SR      (*((int *)0x40012000))
#define ADC_CR1     (*((int *)0x40012004))
#define ADC_CR2     (*((int *)0x40012008))
#define ADC_SMPR1   (*((int *)0x4001200c))
#define ADC_SMPR2   (*((int *)0x40012010))
#define ADC_DR      (*((int *)0x4001204c))
#define ADC_SQR1    (*((int *)0x4001202c))
#define ADC_SQR2    (*((int *)0x40012030))
#define ADC_SQR3    (*((int *)0x40012034))
	
void MUX_init(void);
void RCC_Init(void);
void adc_init(void);
