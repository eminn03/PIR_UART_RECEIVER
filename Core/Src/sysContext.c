#include "../Inc/sysContext.h"


static Queue_t taskQueue;

static bool isTxBusy = false;


void sysContextInit(){

    queInit(&taskQueue);
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
