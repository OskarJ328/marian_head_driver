/*
 * GPIO.c
 *
 *  Created on: Nov 5, 2025
 *      Author: ozker
 */

#include "gpio.h"

#define TIM3_CH1_PIN 6
#define BUTTON_PIN 0
#define UART_TX_PIN 2
#define UART_RX_PIN 3

#define PA6_AF GPIOA->MODER |= (0b10 << (2*TIM3_CH1_PIN))
#define PA6_HS GPIOA->OSPEEDR |= (0b10 << (2*TIM3_CH1_PIN))
#define PA6_TIM3 GPIOA->AFR[0] |= (2 << (4*TIM3_CH1_PIN))

#define PA0_PULLUP GPIOA->PUPDR |= 0b01 << (2*BUTTON_PIN)

#define PA2_AF GPIOA->MODER |= 0b10 << (2*UART_TX_PIN) 
#define PA2_MS GPIOA->OSPEEDR |= 0b01 << (2* UART_TX_PIN)
#define PA2_UART_TX GPIOA->AFR[0] |= 7 << (4*UART_TX_PIN)

#define PA3_AF GPIOA->MODER |= 0b10 << (2*UART_RX_PIN)
#define PA3_MS GPIOA->OSPEEDR |= 0b01 << (2* UART_RX_PIN)
#define PA3_UART_RX GPIOA->AFR[0] |= 7 << (4*UART_RX_PIN)
#define PA3_PULLUP GPIOA->PUPDR |= 0b01 << (2*UART_RX_PIN)

static void gpioa_tim3_setup(void){
	PA6_AF;
	PA6_HS;
	PA6_TIM3;
}

static void gpioa_button_setup(void){
	PA0_PULLUP;
}

void gpioa_uart2_tx_setup(void){
	PA2_AF;
	PA2_MS;
	PA2_UART_TX;
}

void gpioa_uart2_rx_setup(void){
	PA3_AF;
	PA3_MS;
	PA3_PULLUP;
	PA3_UART_RX;
	
}

static void gpioa_setup(void){
	gpioa_tim3_setup();
	gpioa_button_setup();
	gpioa_uart2_tx_setup();
	gpioa_uart2_rx_setup();
}
void gpio_setup(void){
	gpioa_setup();
}



bool gpioa_read(uint8_t pin){
	if(pin > 15){
		pin = 15;
	}
	return GPIOA->IDR & (1 << pin);
}




