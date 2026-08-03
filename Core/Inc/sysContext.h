#ifndef SYS_CONTEXT_H
#define SYS_CONTEXT_H

#include "queue.h"


void sysContextInit();
Queue_t* sysContextGetTaskQueue();
bool sysContextGetIsTxBusy();
void sysContextSetIsTxBusy(bool isBusy);


#endif
