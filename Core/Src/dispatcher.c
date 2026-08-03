#include "../Inc/dispatcher.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/dataCheck.h"
#include "../Inc/dataProc.h"
#include "../Inc/uartRx.h"


static rawData_t text;
static parsedData_t data;
static Queue_t* p_taskQueue;


void dispatcherInit(Queue_t* taskQueue){

    p_taskQueue = taskQueue;
}


void dispatcher(){

    if(uartRxGetDataReady()){

        uartRxResetDataReady();

        text = uartRxGetRawData();

        if(!checkData(&text))
           return;

        data = dataProcParseData(&text);
        
        queEnqueue(p_taskQueue, &data);

    }

}
