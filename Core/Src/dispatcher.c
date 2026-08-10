#include "../Inc/dispatcher.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/dataCheck.h"
#include "../Inc/dataProc.h"
#include "../Inc/uartRx.h"


static rawData_t text;
static DataBuffer_t* p_dataBuffer;


void dispatcherInit(DataBuffer_t* dataBuffer){

    p_dataBuffer = dataBuffer;
}


void dispatchRawData(){

    if(uartRxGetDataReady()){

        uartRxResetDataReady();

        text = uartRxGetRawData();

        if(!checkData(&text))
           return;

        dataBufferAppend(p_dataBuffer, dataProcParseData(&text));
    }
}
