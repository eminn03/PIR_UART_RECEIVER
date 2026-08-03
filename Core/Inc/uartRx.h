#ifndef UART_RX_H
#define UART_RX_H

#include <stdbool.h>
#include <stdint.h>
#include "stm32g0xx_hal.h"
#include "../Inc/dataDefinitons.h"


void uartRxInit(UART_HandleTypeDef* huart2);
bool uartRxGetDataReady();
void uartRxResetDataReady();
rawData_t uartRxGetRawData();
void uartRxTimeoutHandler();


#endif
