#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "ringBuffer.h"


void dispatcherInit(RingBuffer_t* rBuff);
void dispatcher();


#endif
