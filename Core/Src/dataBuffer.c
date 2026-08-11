#include "../Inc/dataBuffer.h"
#include <stddef.h>


static void dataBufferReset(DataBuffer_t*);


void dataBufferInit(DataBuffer_t* buff){

    if(buff == NULL)
        return;

    dataBufferReset(buff);
}

void dataBufferAppend(DataBuffer_t* buff, uint16_t data){

    if(buff == NULL)
        return;
    
    if(dataBufferIsFull(buff))
        dataBufferReset(buff);

    buff->buffer[buff->index] = data;
    buff->index++;
}

const uint16_t* dataBufferGetBuffer(const DataBuffer_t* buff){

    if(buff == NULL)
        return 0;

    return buff->buffer;
}

uint8_t dataBufferGetIndex(const DataBuffer_t* buff){

    if(buff == NULL)
        return 0;
    
    return buff->index;
}

bool dataBufferIsFull(const DataBuffer_t* buff){

    if(buff == NULL)
        return 0;
      
    return buff->index == MAX_BUFFER_SIZE;
}


static void dataBufferReset(DataBuffer_t* buff){

    buff->index = 0;
}
