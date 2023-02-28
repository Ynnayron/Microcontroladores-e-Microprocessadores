#include "stm32f4xx.h"
#include "Utility.h"
			

#define K0 !(GPIOE->IDR & (1<<4))
#define K1 !(GPIOE->IDR & (1<<3))

int main(void)
{  
  Configure_Clock();
	Delay_Start();
	RCC->AHB1ENR |= 1;        //habilita o clock do GPIOA
  RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 0);
  int i = 600;

  GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

  
	while(1){

    if(K0){
      if (i>600){
        i=i-10;
      }
      
    }
    if(K1){
      if(i<2400){
        i=i+10;
      }
    }
	  GPIOA -> ODR |= (1 << 0);
	  Delay_us(i);
	  GPIOA -> ODR &= ~(1 << 0);
	  Delay_us(20000-i);
    }
	