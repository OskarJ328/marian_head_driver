/*
 * uart.c
 *
 *  Created on: Nov 14, 2025
 *      Author: ozker
 */

 #include "uart.h"

 /*
 wyznaczanie wartosci rejestru BRR:
 USARTDIV = USART_CLK / (OVERSAMPLING * BAUDRATE)
 OVERSAMPLING - ZALEZY OD WARTOSCI BITU OVER8 W REJESTRZE CR1
 BAUDRATE - predkosc jaka chcemy aby miala nasza transmisja
 MANTISSA - calkowita czesc wyniku usartdiv
 FRACTION - czesc po przecinku, w celu wpisania jej do rejestru nalezy przemnozyc ją
 przez oversampling i zaokraglic do liczby calkowitej.
 */

#define MANTISSA 8
#define FRACTION 11

#define UART2_SET_BRR USART2->BRR = MANTISSA << 4 | FRACTION
#define UART2_RE USART2->CR1 |= 1 << 2
#define UART2_TE USART2->CR1 |= 1 << 3
#define UART2_EN USART2->CR1 |= 1 << 13

void uart_init(void){
    uart2_init();
}


void uart2_init(void){
    UART2_SET_BRR;
    UART2_TE;
    UART2_RE;
    UART2_EN;
}
 





