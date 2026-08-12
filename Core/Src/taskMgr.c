#include "../Inc/taskMgr.h"
#include "../Inc/ledHandler.h"
#include "../Inc/statistics.h"
#include <stddef.h>


const uint16_t treshold = 0x44;
static DataBuffer_t* p_dataBuffer;


void taskMgrInit(DataBuffer_t *dataBuffer){

    if(dataBuffer == NULL)
        return;

    p_dataBuffer = dataBuffer;
}

void taskMgr(){

    if(dataBufferIsFull(p_dataBuffer)){

        uint32_t diff = filteredSuccessiveDifference(dataBufferGetBuffer(p_dataBuffer), dataBufferGetIndex(p_dataBuffer), 0x200, 8);

        if(diff > treshold)
            ledON();
        else
            ledOFF();
    }
}
