#include "../Inc/dataBuffer.h"
#include <stddef.h>


void dataBufferInit(DataBuffer_t* buff){

    if(buff == NULL)
        return;

    buff->index = 0;
}

void dataBufferReset(DataBuffer_t* buff){

    if(buff == NULL)
        return;

    buff->index = 0;
}

void dataBufferAppend(DataBuffer_t* buff, uint16_t data){

    if(buff == NULL)
        return;
    
    if(dataBufferIsFull(buff))
        dataBufferReset(buff);

    buff->buffer[buff->index] = data;
    buff->index++;
}

const uint16_t* dataBufferGetBuffer(DataBuffer_t* buff){

    if(buff == NULL)
        return 0;

    return buff->buffer;
}

uint8_t dataBufferGetIndex(DataBuffer_t* buff){

    if(buff == NULL)
        return 0;
    
    return buff->index;
}

bool dataBufferIsFull(DataBuffer_t* buff){

    if(buff == NULL)
        return 0;
      
    return buff->index == MAX_BUFFER_SIZE;
}

