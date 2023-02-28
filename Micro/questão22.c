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
#define LED_ON3 (GPIOE->ODR |=(1<<9))
#define LED_OFF3 (GPIOE->ODR &= ~(1<<9))
#define LED_ON4 (GPIOE->ODR |= (1<<10))
#define LED_OFF4 (GPIOE->ODR &= ~(1<<10))
#define LED_ON5 (GPIOE->ODR |= (1<<11))
#define LED_OFF5 (GPIOE->ODR &= ~(1<<11))
#define LED_ON6 (GPIOE->ODR |= (1<<12))
#define LED_OFF6 (GPIOE->ODR &= ~(1<<12))
#define LED_ON7 (GPIOE->ODR |= (1<<13))
#define LED_OFF7 (GPIOE->ODR &= ~(1<<13))
#define LED_ON8 (GPIOE->ODR |= (1<<14))
#define LED_OFF8 (GPIOE->ODR &= ~(1<<14))

#define LED_ON1A (GPIOA->ODR &= ~(1<<6))
#define LED_OFF1A (GPIOA->ODR |= (1<<6))
#define LED_ON2A (GPIOA->ODR &= ~(1<<7))
#define LED_OFF2A (GPIOA->ODR |= (1<<7))


int main(void)
{
    RCC->AHB1ENR |= 1;        //habilita o clock do GPIOA
    RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

    //configurando PA6 como saída (o pino PA6 tem um LED conectado)
    GPIOA->MODER |= (0b01 << 12);
    //configurando PA7 como saída (o pino PA6 tem um LED conectado)
    GPIOA->MODER |= (0b01 << 14);

    //Configurando o pino PE3 como entrada
    GPIOE->MODER &= ~(0b11 << 6);
    GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
    //Configurando o pino PE4 como entrada
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto

    while(1)
    {

        if(K0) //testa se o pino PE3 é alto
        {
            //se for alto, executa isso
        	LED_ON1A;    //manda nível alto para o pino PA6
        }
        else
        {
            //se for baixo executa aquilo
            LED_OFF1A;    //manda nível baixo para o pino PA6
        }
        if(K1){
        	LED_ON2A;
        }
        else{
        	LED_OFF2A;
        }
    }
}


