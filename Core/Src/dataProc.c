#include "../Inc/dataProc.h"
#include <stdint.h>


parsedData_t dataProcParseData(rawData_t* text){

    parsedData_t data = (((uint16_t)(text->value[DATA_IDX_PIR_MS])) << 8) + (uint16_t)text->value[DATA_IDX_PIR_LS];
    return data;
}

