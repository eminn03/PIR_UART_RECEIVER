#ifndef UART_TX_H
#define UART_TX_H

#include <stdint.h>
#include "../Inc/dataDefinitons.h"
#include "stm32g0xx_hal.h"


void uartTxInit(UART_HandleTypeDef* huart2);
void uartTxTransmitACK(rawData_t* text);
void uartTxTransmitERR(rawData_t* text);


#endif
