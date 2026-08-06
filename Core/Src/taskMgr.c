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

    if(!ringBufferIsEmpty(p_rBuff)){
        
        uint16_t data = ringBufferPeek(p_rBuff);

        if(data < 8000 )
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    }
}
