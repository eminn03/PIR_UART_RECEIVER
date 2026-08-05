#include "../Inc/taskMgr.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/ledHandler.h"
#include "stm32g0xx_hal.h"


static RingBuffer_t* p_rBuff;


void taskMgrInit(RingBuffer_t *rBuff){

    p_rBuff = rBuff;
}

void taskMgr(){

    //ledBlink(500);

    if(ringBufferIsFull(p_rBuff)){
        
        uint16_t data = ringBufferPeek(p_rBuff);

        if(data < 5000 || data > 11000)
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    }
}
