#include "../Inc/ringBuffer.h"


void ringBufferInit(RingBuffer_t* rBuff){

    rBuff->head = -1;
    rBuff->count = 0;
}

void ringBufferReset(RingBuffer_t* rBuff){

    rBuff->head = -1;
    rBuff->count = 0;
}

void ringBufferAppend(RingBuffer_t* rBuff, uint16_t data){

    if(rBuff->head == RING_BUFFER_SIZE - 1)
        rBuff->head = 0;
    else
        rBuff->head++;

    rBuff->data[rBuff->head] = data;

    if(rBuff->count < RING_BUFFER_SIZE)
        rBuff->count++;
}

uint16_t ringBufferPop(RingBuffer_t* rBuff){

    if(ringBufferIsEmpty(rBuff))
        return 0;

    if(rBuff->head == 0 && rBuff->count > 1){

        rBuff->count--;
        rBuff->head = RING_BUFFER_SIZE - 1;
        return rBuff->data[rBuff->head];
    }

    rBuff->count--;
    return rBuff->data[rBuff->head--];
}

uint16_t ringBufferPeek(RingBuffer_t* rBuff){

    if(ringBufferIsEmpty(rBuff))
        return 0;

    return rBuff->data[rBuff->head];
}

bool ringBufferIsEmpty(RingBuffer_t* rBuff){

    return rBuff->count == 0; 
}

bool ringBufferIsFull(RingBuffer_t* rBuff){

    return rBuff->count == RING_BUFFER_SIZE;
}

uint16_t* ringBufferGetData(RingBuffer_t* rBuff){

    return rBuff->data;
}

uint8_t ringBufferGetCount(RingBuffer_t* rBuff){

    return rBuff->count;
}
