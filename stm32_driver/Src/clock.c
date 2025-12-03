/*
 * clock.c
 *
 *  Created on: Nov 6, 2025
 *      Author: ozker
 */

#include "clock.h"

#define SYSTICK_DIVIDER 16000
#define GPIOA_EN RCC->AHB1ENR |= (1 << 0)
#define TIM3_EN RCC->APB1ENR |= (1 << 1)

#define UART2_EN RCC->APB1ENR |= RCC_APB1ENR_USART2EN

volatile uint32_t ticks = 0;

static void setup_GPIOA(void){
	GPIOA_EN;
}

static void setup_TIM3(void){
	TIM3_EN;
}

static void setup_UART2(void){
	UART2_EN;
}

static void setup_sysTick(void){
	SysTick_Config(SYSTICK_DIVIDER);
}

void clock_setup(void){
	setup_sysTick();
	setup_GPIOA();
	setup_TIM3();
	setup_UART2();
	/*
	 * tu dodaj pozostałą konfiguracje zegarów
	 */
}







void delay_ms(uint32_t period_ms) {
	uint32_t start_time = ticks;
	while(ticks - start_time < period_ms){
		// wait
	}
}

uint32_t current_time_ms(void){
	return ticks;
}






void SysTick_Handler(void){
	ticks ++;
}






