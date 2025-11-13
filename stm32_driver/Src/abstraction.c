/*
 * abstraction.c
 *
 *  Created on: Nov 13, 2025
 *      Author: ozker
 */

#include "abstraction.h"

#define MIN_CCR 1000
#define MAX_CCR 2000
#define MAX_ANGLE 180


uint32_t servo_set_angle(uint8_t angle){
    if (angle > 180){
        angle = 180;
    }
    uint32_t ccr = MIN_CCR + ((MAX_CCR - MIN_CCR) * angle / MAX_ANGLE);
    TIM3->CCR1 = ccr;
    return ccr;
}

bool button_read(void){
    return !gpioa_read(0);
}