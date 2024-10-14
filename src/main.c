#include "stm32f0xx.h"

int main(){
	while( !((RCC->CR & 0x2) >> 1) )
	RCC->CFGR &= ~0x3;

	RCC->AHBENR |= 1<<19;
	GPIOC->MODER |= 1<<16;
	GPIOC->MODER |= 1<<18;
	long a = 200000;
	while(1){
		GPIOC->ODR &= ~(3<<8);
		for(long i=0; i<a; i++);
		GPIOC->ODR |= 3<<8;
		for(long i=0; i<a; i++);
	}
	return 0;
}
