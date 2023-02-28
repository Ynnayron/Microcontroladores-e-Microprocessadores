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
			

int main(void)
{
	Configure_Clock();		//Configuração do sistema de clock
	Delay_Start();			//Inicializa as funções de delay

	 RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
	 RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE
	 GPIOA->MODER |= (0b01 << 12);

	 int intervalo = 1000;

	 while(1){
		 GPIOA->ODR &=~(1 << 6);
		 Delay_ms(50);
		 GPIOA->ODR |=(1 << 6);
		 Delay_ms(intervalo);
		 intervalo -= 25;
		 if(intervalo == 0){
			 intervalo = 1000;
		 }
	 }
}
