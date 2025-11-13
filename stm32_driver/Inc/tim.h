/*
 * tim.h
 *
 *  Created on: Nov 12, 2025
 *      Author: ozker
 */

#ifndef TIM_H_
#define TIM_H_
#include "main.h"

#define TIM3_ARR 19999

void tim_init(void);

void tim_start(void);

void tim3_set_pwm_duty_permille(uint32_t permille);


#endif /* TIM_H_ */
