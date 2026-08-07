#include "../Inc/taskMgr.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/ledHandler.h"
#include "../Inc/statistics.h"
#include "stm32g0xx_hal.h"


static RingBuffer_t* p_rBuff;


void taskMgrInit(RingBuffer_t *rBuff){

    p_rBuff = rBuff;
}

void taskMgr(){

    if(ringBufferIsFull(p_rBuff)){
        
        uint16_t data = mean(ringBufferGetData(p_rBuff), ringBufferGetCount(p_rBuff), 24);
        uint32_t diff = successiveDifference(ringBufferGetData(p_rBuff), ringBufferGetCount(p_rBuff));

        if(diff > 0x222)
            ledON();
        else
            ledOFF();
    }
}
