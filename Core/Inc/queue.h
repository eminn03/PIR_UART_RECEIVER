#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>
#include "dataDefinitons.h"

#define MAX_QUEUE_SIZE 64


typedef struct{
    rawData_t queueArr[MAX_QUEUE_SIZE];
    uint8_t index;
}Queue_t;


void queInit(Queue_t* qu);
int8_t queEnqueue(Queue_t* qu, rawData_t* data);
rawData_t queDequeue(Queue_t* qu);
rawData_t quePeek(Queue_t* qu);
bool queIsEmpty(Queue_t* qu);


#endif
