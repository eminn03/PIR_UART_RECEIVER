#include "../Inc/sysContext.h"


static DataBuffer_t dataBuffer;


void sysContextInit(){

    dataBufferInit(&dataBuffer);
}

DataBuffer_t* sysContextGetDataBuffer(){

    return &dataBuffer;
}

