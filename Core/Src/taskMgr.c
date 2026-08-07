#include "../Inc/taskMgr.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/ledHandler.h"
#include "../Inc/statistics.h"
#include "stm32g0xx_hal.h"


static DataBuffer_t* p_dataBuffer;


void taskMgrInit(DataBuffer_t *dataBuffer){

    p_dataBuffer = dataBuffer;
}

void taskMgr(){

    if(dataBufferIsFull(p_dataBuffer)){

        uint16_t data = mean(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer), 24);
        uint32_t diff = successiveDifference(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer));

        if(diff > 0x222)
            ledON();
        else
            ledOFF();
    }
}
