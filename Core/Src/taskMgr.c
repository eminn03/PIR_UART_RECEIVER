#include "../Inc/taskMgr.h"
#include "../Inc/ledHandler.h"
#include "../Inc/statistics.h"
#include <stddef.h>


const uint16_t treshold = 0x133;
static DataBuffer_t* p_dataBuffer;


void taskMgrInit(DataBuffer_t *dataBuffer){

    if(dataBuffer == NULL)
        return;

    p_dataBuffer = dataBuffer;
}

void taskMgr(){

    if(dataBufferIsFull(p_dataBuffer)){

        //uint16_t data = mean(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer), 0);
        uint32_t diff = successiveDifference(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer));

        if(diff > treshold)
            ledON();
        else
            ledOFF();
    }
}
