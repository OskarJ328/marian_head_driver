/*
 * GPIO.h
 *
 *  Created on: Nov 5, 2025
 *      Author: ozker
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "main.h"
void gpio_setup(void);

bool gpioa_read(uint8_t pin);
#endif /* GPIO_H_ */
