#include "../Inc/queue.h"


static int8_t queSlide(rawData_t* arr, uint8_t end);


void queInit(Queue_t* qu){
    qu->index = 0;
}

int8_t queEnqueue(Queue_t* qu, rawData_t* data){

	if(qu->index >= MAX_QUEUE_SIZE)
		return -1;

    queSlide(qu->queueArr, qu->index - 1);
    qu->queueArr[qu->index] = *data;
    qu->index++;

    return 0;
}

rawData_t queDequeue(Queue_t* qu){

    if(queIsEmpty(qu))
        return (rawData_t){0, 0};

    qu->index--;
    return qu->queueArr[qu->index];
}

rawData_t quePeek(Queue_t* qu){

	if(queIsEmpty(qu))
		return (rawData_t){0, 0};

	return qu->queueArr[qu->index - 1];
}

bool queIsEmpty(Queue_t* qu){
	return qu->index <= 0;
}


static int8_t queSlide(rawData_t* arr, uint8_t end){

    if(end > MAX_QUEUE_SIZE - 2)
        return -1;

    for(int i = end; i >= 0; i--)
        arr[i+1] = arr[i];

    return 0;
}

