#include "../Inc/uartTx.h"
#include "../Inc/queue.h"
#include "../Inc/sysContext.h"
#include "stm32g0xx_hal.h"


typedef enum{

    TX_ERR_SIGN = 0x00,
    TX_ACK_SIGN = 0x01

}txSign_t;


static UART_HandleTypeDef* p_huart2;
static rawData_t rawText;
static rawData_t rawTextTx;
static Queue_t txQueue;


static void uartTxTransmitText(rawData_t* text);


void uartTxInit(UART_HandleTypeDef* huart2){

    p_huart2 = huart2;
    queInit(&txQueue);
}

void uartTxTransmitACK(rawData_t* text){

    rawText = *text;
    rawText.value[DATA_IDX_PRIO] = TX_ACK_SIGN;

    if(sysContextGetIsTxBusy())
        queEnqueue(&txQueue, &rawText);
    else
        uartTxTransmitText(&rawText);
}

void uartTxTransmitERR(rawData_t* text){

    rawText = *text;
    rawText.value[DATA_IDX_PRIO] = TX_ERR_SIGN;
    
    if(sysContextGetIsTxBusy())
        queEnqueue(&txQueue, &rawText);
    else
        uartTxTransmitText(&rawText);
}


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

    sysContextSetIsTxBusy(false);

    if(!queIsEmpty(&txQueue)){

        rawTextTx = queDequeue(&txQueue);
        uartTxTransmitText(&rawTextTx);
    }
}


static void uartTxTransmitText(rawData_t* text){

    HAL_UART_Transmit_IT(p_huart2, text->value, text->len);
    sysContextSetIsTxBusy(true);
}

