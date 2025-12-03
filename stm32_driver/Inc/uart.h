/*
 * uart.h
 *
 *  Created on: Nov 14, 2025
 *      Author: ozker
 */

#ifndef UART_H_
#define UART_H_

#include "main.h"

void uart_init(void);
void uart2_send_char(char c);
void uart2_send_string(char *s);
#endif /* UART_H_ */
