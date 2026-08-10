#include "../Inc/taskMgr.h"
#include "../Inc/ledHandler.h"
#include "../Inc/statistics.h"


static DataBuffer_t* p_dataBuffer;


void taskMgrInit(DataBuffer_t *dataBuffer){

    p_dataBuffer = dataBuffer;
}

void taskMgr(){

    if(dataBufferIsFull(p_dataBuffer)){

        //uint16_t data = mean(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer), 0);
        uint32_t diff = successiveDifference(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer));

        if(diff > 0x133)
            ledON();
        else
            ledOFF();
    }
}
