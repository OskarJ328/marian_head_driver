/*
 * clock.h
 *
 *  Created on: Nov 6, 2025
 *      Author: ozker
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "main.h"

extern volatile uint32_t ticks;

void clock_setup(void);

void delay_ms(uint32_t period_ms);

uint32_t current_time_ms(void);



void SysTic_Handler(void);
#endif /* CLOCK_H_ */
