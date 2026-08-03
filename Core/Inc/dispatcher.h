#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "pqueue.h"


void dispatcherInit(PriorityQueue_t* taskQueue);
void dispatcher();


#endif
