#ifndef UART_RX_H
#define UART_RX_H

#include <stdbool.h>
#include "../Inc/dataDefinitons.h"


typedef struct __UART_HandleTypeDef UART_HandleTypeDef;


void uartRxInit(UART_HandleTypeDef* huart2);
bool uartRxGetDataReady();
void uartRxResetDataReady();
rawData_t uartRxGetRawData();
void uartRxTimeoutHandler();


#endif
