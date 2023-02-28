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
			

void atraso(int atraso)
{
    while(atraso) --atraso;
}
void buzina()
{
	RCC->AHB1ENR |= (1<<2);         //habilita o clock do GPIOC


	//configurando PA11 como saída (o pino PA6 tem um LED conectado)
	GPIOC->MODER |= (0b01 << 22);
	while(1)
	{
		 GPIOC->ODR |= (1<<11);
		 atraso(3000000);
		 GPIOC -> ODR &=~(1<<11);
		 atraso(3000000);
	}

}
int main(void)
{
buzina();

}
