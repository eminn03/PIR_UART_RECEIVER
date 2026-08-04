#include "../Inc/sysContext.h"


static RingBuffer_t ringBuffer;


void sysContextInit(){

    ringBufferInit(&ringBuffer);
}

RingBuffer_t* sysContextGetRingBuffer(){

    return &ringBuffer;
}

