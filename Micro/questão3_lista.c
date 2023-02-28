
#include "stm32f4xx.h"
#include "Utility.h"
			

int main(void)
{
	Configure_Clock();		//Configuração do sistema de clock
	Delay_Start();			//Inicializa as funções de delay

		//Configura o delay em milissegundos

	 RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
	 RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE
	 GPIOA->MODER |= (0b01 << 12);

	 //configurando PA6 como saída (o pino PA6 tem um LED conectado)
	 while(1){
		 GPIOA->ODR &=~(1 << 6);
		 Delay_ms(50);
		 //configurando PA7 como saída (o pino PA6 tem um LED conectado)
		 GPIOA->ODR |=(1 << 6);
		 Delay_ms(1000);
		 GPIOA->ODR &=~(1 << 6);
		 Delay_ms(50);
		 GPIOA->ODR |=(1 << 6);
		 Delay_ms(100);
		 GPIOA->ODR &=~(1 << 6);
		 Delay_ms(50);
		 GPIOA->ODR |=(1 << 6);
		 Delay_ms(1000);
	 }

}