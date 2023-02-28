
#include "Utility.h"
#include "stm32f4xx.h"

int main(void) {
  Configure_Clock(); // Configuração do sistema de clock
  Delay_Start();     // Inicializa as funções de delay

  // Configura o delay em milissegundos

  RCC->AHB1ENR |= 1;      // habilita o clock do GPIOA
  RCC->AHB1ENR |= 1 << 4; // habilita o clock do GPIOE
  GPIOA->MODER |= (0b01 << 12);
  GPIOA->MODER |= (0b01 << 14);

  // configurando PA6 como saída (o pino PA6 tem um LED conectado)
  while (1) {
    GPIOA->ODR &= ~(1 << 6);
    Delay_ms(1);
    GPIOA->ODR |= (1 << 6);
    Delay_ms(9);
  }
}
