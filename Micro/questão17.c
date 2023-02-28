int main(void)
{  
  Configure_Clock();
	Delay_Start();
	RCC->AHB1ENR |= 1;        //habilita o clock do GPIOA
	GPIOA->MODER |= (0b01 << 0);
	while(1){
	for (int i=600; i<=2400; i+=10){
	  GPIOA -> ODR |= (1 << 0);
	  Delay_us(i);
	  GPIOA -> ODR &= ~(1 << 0);
	  Delay_us(20000-i);
	}
	for (int i=2400; i>=600;i-=10){
	  GPIOA -> ODR |= (1 << 0);
	  Delay_us(i);
	  GPIOA -> ODR &= ~(1 << 0);
	  Delay_us(20000-i);
	}
  }
  }