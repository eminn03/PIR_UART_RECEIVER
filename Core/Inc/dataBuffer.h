#ifndef DATA_BUFFER_H
#define DATA_BUFFER_H


#include <stdint.h>
#include <stdbool.h>


#define MAX_BUFFER_SIZE 32


typedef struct{

    uint16_t buffer[MAX_BUFFER_SIZE];
    uint8_t index;

}DataBuffer_t;


void dataBufferInit(DataBuffer_t*);
void dataBufferReset(DataBuffer_t*);
void dataBufferAppend(DataBuffer_t*, uint16_t data);
const uint16_t* dataBufferGetBuffer(DataBuffer_t*);
uint8_t dataBufferGetIndex(DataBuffer_t*);
bool dataBufferIsFull(DataBuffer_t*);


#endif
