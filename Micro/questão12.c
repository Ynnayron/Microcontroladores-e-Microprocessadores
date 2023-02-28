/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "Utility.h"
			

#define K0 !(GPIOE->IDR & (1<<4))
#define K1 !(GPIOE->IDR & (1<<3))
#define LED_ON1 (GPIOE->ODR |=(1<<7))
#define LED_OFF1 (GPIOE->ODR &= ~(1<<7))
#define LED_ON2 (GPIOE->ODR |= (1<<8))
#define LED_OFF2 (GPIOE->ODR &= ~(1<<8))
#define LED_ON3 (GPIOE->ODR |=(1<<14))
#define LED_OFF3 (GPIOE->ODR &= ~(1<<14))
#define LED_ON4 (GPIOE->ODR |= (1<<13))
#define LED_OFF4 (GPIOE->ODR &= ~(1<<13))
#define LED_ON5 (GPIOE->ODR |= (1<<9))
#define LED_OFF5 (GPIOE->ODR &= ~(1<<9))
#define LED_ON6 (GPIOE->ODR |= (1<<10))
#define LED_OFF6 (GPIOE->ODR &= ~(1<<10))
#define LED_ON7 (GPIOE->ODR |= (1<<11))
#define LED_OFF7 (GPIOE->ODR &= ~(1<<11))
#define LED_ON8 (GPIOE->ODR |= (1<<12))
#define LED_OFF8 (GPIOE->ODR &= ~(1<<12))


int main(void) {
  Configure_Clock(); // Configuração do sistema de clock
  Delay_Start();     // Inicializa as funções de delay

  // Configura o delay em milissegundos

  RCC->AHB1ENR |= 1 << 4; // habilita o clock do GPIOE
  GPIOE->MODER |= (0b01 << 14);
  GPIOE->MODER |= (0b01 << 16);
  GPIOE->MODER |= (0b01 << 18);
  GPIOE->MODER |= (0b01 << 20);
  GPIOE->MODER |= (0b01 << 22);
  GPIOE->MODER |= (0b01 << 24);
  GPIOE->MODER |= (0b01 << 26);
  GPIOE->MODER |= (0b01 << 28);

  // configurando PA6 como saída (o pino PA6 tem um LED conectado)
  while (1) {
    for(int x = 7; x <= 14; x++){
    	GPIOE->ODR |= (1<<x);
    	Delay_ms(75);
    	GPIOE->ODR &= ~(1<<x);
    }
  }
}
