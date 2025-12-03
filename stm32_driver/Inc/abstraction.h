/*
 * abstraction.h
 *
 *  Created on: Nov 13, 2025
 *      Author: ozker
 */

#ifndef ABSTRACTION_H_
#define ABSTRACTION_H_

#include "tim.h"
#include "gpio.h"

uint32_t servo_set_angle(uint8_t angle);

bool button_read(void);

#endif /* ABSTRACTION_H_ */
