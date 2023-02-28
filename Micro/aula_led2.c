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

#define K0 !(GPIOE->IDR & (1<<4))
#define K1 !(GPIOE->IDR & (1<<3))
#define LED_ON1 (GPIOA->ODR &= ~(1<<6))
#define LED_OFF1 (GPIOA->ODR |= (1<<6))
#define LED_ON2 (GPIOA->ODR &= ~(1<<7))
#define LED_OFF2 (GPIOA->ODR |= (1<<7))
			

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
        	LED_ON1;    //manda nível alto para o pino PA6
        }
        else
        {
            //se for baixo executa aquilo
            LED_OFF1;    //manda nível baixo para o pino PA6
        }
        if(K1){
        	LED_ON1;
        }
        else{
        	LED_OFF1;
        }
        if(K0 && K1) //testa se o pino PE3 é alto
		{
			//se for alto, executa isso
			LED_ON2;    //manda nível alto para o pino PA6
		}
		else
		{
			//se for baixo executa aquilo
			LED_OFF2;    //manda nível baixo para o pino PA6
		}
		if(K1){
			LED_ON2;
		}
		else{
			LED_OFF2;
		}
    }
}




//DOIS LEDS LIGADOS JUNTOS
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

#define K0 !(GPIOE->IDR & (1<<4))
#define K1 !(GPIOE->IDR & (1<<3))
#define LED_ON1 (GPIOA->ODR &= ~(1<<6))
#define LED_OFF1 (GPIOA->ODR |= (1<<6))
#define LED_ON2 (GPIOA->ODR &= ~(1<<7))
#define LED_OFF2 (GPIOA->ODR |= (1<<7))
			

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

        if(K0||K1) //testa se o pino PE3 é alto
        {
            //se for alto, executa isso
        	LED_ON1;    //manda nível alto para o pino PA6
        }
        else
        {
            //se for baixo executa aquilo
            LED_OFF1;    //manda nível baixo para o pino PA6
        }
        if(K0 && K1) //testa se o pino PE3 é alto
		{
			//se for alto, executa isso
			LED_ON2;    //manda nível alto para o pino PA6
		}
		else
		{
			//se for baixo executa aquilo
			LED_OFF2;    //manda nível baixo para o pino PA6
		}
    }
}


///DOIS LEDS ACESOS, PRIMEIRO K0 E DEPOIS K1
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

#define K0 !(GPIOE->IDR & (1<<4))
#define K1 !(GPIOE->IDR & (1<<3))
#define LED_ON1 (GPIOA->ODR &= ~(1<<6))
#define LED_OFF1 (GPIOA->ODR |= (1<<6))
#define LED_ON2 (GPIOA->ODR &= ~(1<<7))
#define LED_OFF2 (GPIOA->ODR |= (1<<7))
			

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

    int true = 0;

    while(1)
    {

        if(K0 && !K1){
        	true = 1;
        	if(K1 && true == 1){
        		LED_ON1;
        		LED_ON2;
        	}
        	else{
        		LED_OFF1;
        		LED_OFF2;
        	}
        }
        else{
        	LED_OFF1;
        	LED_OFF2;
        }
    }
}
