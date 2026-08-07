#include "../Inc/uartRx.h"
#include <stdint.h>


static UART_HandleTypeDef* p_huart2;
static rawData_t rxData;

static uint8_t rxValue;
static uint8_t rxBuffIndex = 0;

static volatile bool dataReady;


static void uartRxAddToBuffer(uint8_t value);


void uartRxInit(UART_HandleTypeDef* huart2){

    p_huart2 = huart2;
    dataReady = false;
    rxBuffIndex = 0;
 
    HAL_UART_ReceiverTimeout_Config(p_huart2, 30000);
    HAL_UART_EnableReceiverTimeout(p_huart2);
    __HAL_UART_ENABLE_IT(p_huart2, UART_IT_RTO);   

    HAL_UART_Receive_IT(p_huart2, &rxValue, 1);
}

bool uartRxGetDataReady(){

    return dataReady;
}

void uartRxResetDataReady(){

    dataReady = false;
}

rawData_t uartRxGetRawData(){

    __disable_irq();
    rawData_t copyData = rxData;
    __enable_irq();

    return copyData;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

    uartRxAddToBuffer(rxValue);

    HAL_UART_Receive_IT(p_huart2, &rxValue, 1);
}

void uartRxTimeoutHandler(){
        
    if(__HAL_UART_GET_FLAG(p_huart2, UART_FLAG_RTOF)){
    
        __HAL_UART_CLEAR_FLAG(p_huart2, UART_FLAG_RTOF);

        if(!dataReady)
            rxBuffIndex = 0;
    }
}


static void uartRxAddToBuffer(uint8_t value){

    if(rxBuffIndex == DATA_IDX_STRT){
     
        if(value != DATA_STRT)
            return;
        
        rxData.value[rxBuffIndex] = value;
        rxBuffIndex++;
    }
    else if(rxBuffIndex == DATA_IDX_LEN){
        
        if(value < 3 || value > BUFFER_SIZE){

            rxBuffIndex = 0;
            return;
        }
        rxData.len = value;
        rxData.value[rxBuffIndex] = value;
        rxBuffIndex++;
    }
    else if(rxBuffIndex == rxData.len - 1){
        
        if(value == DATA_END){
            
            rxData.value[rxBuffIndex] = value;
            dataReady = true;
        }

        rxBuffIndex = 0;
    }
    else {

        rxData.value[rxBuffIndex] = value;
        rxBuffIndex++;
    }
}

