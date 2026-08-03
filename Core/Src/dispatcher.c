#include "../Inc/dispatcher.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/dataCheck.h"
#include "../Inc/dataProc.h"
#include "../Inc/uartRx.h"
#include "../Inc/uartTx.h"


static rawData_t text;
static parsedData_t data;
static PriorityQueue_t* p_taskQueue;


void dispatcherInit(PriorityQueue_t* taskQueue){

    p_taskQueue = taskQueue;
}


void dispatcher(){

    if(uartRxGetDataReady()){

        uartRxResetDataReady();

        text = uartRxGetRawData();

        if(!checkData(&text)){

           uartTxTransmitERR(&text);
           return;
        }

        uartTxTransmitACK(&text);

        data = dataProcParseData(&text);
        
        pqueEnqueue(p_taskQueue, &data);

    }

}
