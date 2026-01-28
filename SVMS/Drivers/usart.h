#define GPIOC_AFRL  (*((int *)0x40020820))
#define UART6_SR    (*((int *)0x40011400))
#define UART6_DR    (*((int *)0x40011404))
#define UART6_BRR   (*((int *)0x40011408))
#define UART6_CR1   (*((int *)0x4001140C))
#define UART6_CR2   (*((int *)0x40011410))
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))
	
#define GPIOB_MODE  (*((int *)0x40020400))
#define GPIOB_ODR   (*((int *)0x40020414))
	
#define GPIOC_MODE  (*((int *)0x40020800))
#define GPIOC_IDR   (*((int *)0x40020810))	
#define GPIOC_PUPDR (*((int *)0x4002080C))

void usart6(void);
void transmit_outsting(char []);
unsigned char receive_char(void);
void transmit_char(unsigned char ch);
void UART6_Config(void);
void UART6_MODE_Init(void);
