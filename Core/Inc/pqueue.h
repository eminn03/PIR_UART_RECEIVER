#ifndef PQUEUE_H
#define PQUEUE_H

#include <stdbool.h>
#include <stdint.h>
#include "dataDefinitons.h"

#define MAX_QUEUE_SIZE 64



typedef struct{
    parsedData_t queueArr[MAX_QUEUE_SIZE];
    uint8_t index;
}PriorityQueue_t;



void pqueInit(PriorityQueue_t* qu);
uint8_t pqueEnqueue(PriorityQueue_t* qu, parsedData_t* data);
parsedData_t pqueDequeue(PriorityQueue_t* qu);
parsedData_t pquePeek(PriorityQueue_t* qu);
bool pqueIsEmpty(PriorityQueue_t* qu);


#endif
