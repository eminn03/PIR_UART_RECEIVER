#include "../Inc/dispatcher.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/dataCheck.h"
#include "../Inc/dataProc.h"
#include "../Inc/uartRx.h"


static rawData_t text;
static parsedData_t data;
static RingBuffer_t* p_rBuff;


void dispatcherInit(RingBuffer_t* rBuff){

    p_rBuff = rBuff;
}


void dispatcher(){

    if(uartRxGetDataReady()){

        uartRxResetDataReady();

        text = uartRxGetRawData();

        if(!checkData(&text))
           return;

        data = dataProcParseData(&text);
        
        ringBufferAppend(p_rBuff, data);

    }
}
