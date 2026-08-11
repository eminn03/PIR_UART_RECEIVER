#include "../Inc/dispatcher.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/dataCheck.h"
#include "../Inc/dataProc.h"
#include "../Inc/uartRx.h"
#include <stddef.h>


static DataBuffer_t* p_dataBuffer;


void dispatcherInit(DataBuffer_t* dataBuffer){

    if(dataBuffer == NULL)
        return;

    p_dataBuffer = dataBuffer;
}


void dispatchRawData(){

    if(uartRxGetDataReady()){

        rawData_t text = uartRxGetRawData();

        uartRxResetDataReady();

        if(!checkData(&text))
           return;

        dataBufferAppend(p_dataBuffer, dataProcParseData(&text));
    }
}
