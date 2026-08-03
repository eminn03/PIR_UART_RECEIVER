#include "../Inc/pqueue.h"


static int8_t pqueSlide(parsedData_t* arr, uint8_t target, uint8_t end);


void pqueInit(PriorityQueue_t* qu){
    qu->index = 0;
}

uint8_t pqueEnqueue(PriorityQueue_t* qu, parsedData_t* data){

	if(qu->index >= MAX_QUEUE_SIZE)
		return 0;

    for(int i = qu->index - 1; i >= -1; i--){
        if(i == -1 ||qu->queueArr[i].priority < data->priority){
            pqueSlide(qu->queueArr, i+1, qu->index - 1);
            qu->queueArr[i+1] = *data;
            qu->index++;
            return i+1;
        }
    }

    return 0;
}

parsedData_t pqueDequeue(PriorityQueue_t* qu){

    if(pqueIsEmpty(qu))
        return (parsedData_t){0, 0};

    qu->index--;
    return qu->queueArr[qu->index];
}

parsedData_t pquePeek(PriorityQueue_t* qu){

	if(pqueIsEmpty(qu))
		return (parsedData_t){0, 0};

	return qu->queueArr[qu->index - 1];
}

bool pqueIsEmpty(PriorityQueue_t* qu){
	return qu->index <= 0;
}


static int8_t pqueSlide(parsedData_t* arr, uint8_t target, uint8_t end){

    if(end > MAX_QUEUE_SIZE - 2)
        return -1;

    if(target > end)
        return 0;

    for(int i = end; i >= target; i--)
        arr[i+1] = arr[i];

    return 0;
}

