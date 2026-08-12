#ifndef DATA_BUFFER_H
#define DATA_BUFFER_H


#include <stdint.h>
#include <stdbool.h>


#define MAX_BUFFER_SIZE 16


typedef struct{

    uint16_t buffer[MAX_BUFFER_SIZE];
    uint8_t index;

}DataBuffer_t;


void dataBufferInit(DataBuffer_t*);
void dataBufferAppend(DataBuffer_t*, uint16_t data);
const uint16_t* dataBufferGetBuffer(const DataBuffer_t*);
uint8_t dataBufferGetIndex(const DataBuffer_t*);
bool dataBufferIsFull(const DataBuffer_t*);


#endif
