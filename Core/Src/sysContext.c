#include "../Inc/sysContext.h"


static PriorityQueue_t taskQueue;

static bool isTxBusy = false;


void sysContextInit(){

    pqueInit(&taskQueue);
}


PriorityQueue_t* sysContextGetTaskQueue(){

    return &taskQueue;
}

bool sysContextGetIsTxBusy(){

    return isTxBusy;
}

void sysContextSetIsTxBusy(bool isBusy){

    isTxBusy = isBusy;
}
