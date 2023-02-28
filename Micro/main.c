#include <stdio.h>

int main(void) {
  GPIO-> MODER= 0b01<< 12; // configura o pino PA6 como saída e os demais como entrada.
  GPIO -> MODER = 0b01 << 14;  // configura o pino PA7 como saída e os demais como entrada.
  GPIO -> MODER |= 0b01 << 12; //setar bit 12
  GPIO -> MODER &= ~(0b01 << 12); // resetar 12 bit
  GPIOC -> MODER |= 0b11<<14); // configura PC7 como analogica
  GPIOD -> MODER &= ~(0b11<< 18); // configua pino PD9 como entrada
  GPIOD -> MODER &= ~(1<< 18); // supoe que o pino PD9 esta analogica configurando ele como alternativa
  GPIOE -> MODER &= ~(0b11<< 8);
  return 0;
}