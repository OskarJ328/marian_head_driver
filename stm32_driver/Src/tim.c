/*
 * tim.c
 *
 *  Created on: Nov 12, 2025
 *      Author: ozker
 */

#include "tim.h"

 
#define TIM3_PSC 15
/*
wartosci przepelnienia licznika oraz preskalera dobrane sa biorac pod uwage, ze zegar ma 16MHz.
Dla takiego przypadku dzielimy czestotliwosc przez 16 (15+1) co daje nam 1Mhz. Do sterowania
serwomachanizmami potrzebne jest 50Hz. Aby uzyskac taka czestotliwosc nalezy ustalic wartosc przepelnienia
na 20000 (19999+1), wynika to z faktu ze 1 000 000 / 20 000 = 50
*/
#define TIM3_CH1_SET_PWM_MODE TIM3->CCMR1 |= 0b110 << 4
#define TIM3_PRELOAD_EN TIM3->CCMR1 |= 1 << 3
#define TIM3_OC1_OUT_EN TIM3->CCER |= 1 << 0
#define TIM3_SET_DEFAULT_DUTY TIM3->CCR1 = (TIM3_ARR +1)/2
#define TIM3_FORCE_UPDATE TIM3->EGR = 1 << 0
#define TIM3_ARR_PRELOAD_EN TIM3->CR1 |= 1 << 7

#define TIM3_START TIM3->CR1 |= 1 << 0

static void tim3_init(void){
    TIM3->PSC = TIM3_PSC;
    TIM3->ARR = TIM3_ARR;

    TIM3_ARR_PRELOAD_EN;
    TIM3_CH1_SET_PWM_MODE;
    TIM3_PRELOAD_EN;

    TIM3_SET_DEFAULT_DUTY;
    TIM3_FORCE_UPDATE;

    TIM3_OC1_OUT_EN;
}

void tim_start(void){
    TIM3_START;
}
void tim_init(void){
    tim3_init();
}

void tim3_set_pwm_duty_permille(uint32_t permille){
    if (permille > 1000) {
        permille = 1000;
    }
    uint32_t ccr = (TIM3_ARR + 1) * permille / 1000;
    if (ccr > TIM3_ARR) {
        ccr = TIM3_ARR;
    }
    TIM3->CCR1 = ccr;
}
