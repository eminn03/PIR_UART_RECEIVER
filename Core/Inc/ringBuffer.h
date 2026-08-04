#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>


#define RING_BUFFER_SIZE 16


typedef struct{

    uint16_t data[RING_BUFFER_SIZE];
    uint8_t head;
    uint8_t count;

}RingBuffer_t;


void ringBufferInit(RingBuffer_t* rBuff);
void ringBufferReset(RingBuffer_t* rBuff);
void ringBufferAppend(RingBuffer_t* rBuff, uint16_t data);
uint16_t ringBufferPop(RingBuffer_t* rBuff);
uint16_t ringBufferPeek(RingBuffer_t* rBuff);
bool ringBufferIsEmpty(RingBuffer_t* rBuff);
bool ringBufferIsFull(RingBuffer_t* rBuff);


#endif
