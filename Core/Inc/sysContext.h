#ifndef SYS_CONTEXT_H
#define SYS_CONTEXT_H

#include "pqueue.h"


void sysContextInit();
PriorityQueue_t* sysContextGetTaskQueue();
bool sysContextGetIsTxBusy();
void sysContextSetIsTxBusy(bool isBusy);


#endif
