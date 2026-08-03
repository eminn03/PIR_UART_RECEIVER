#include "../Inc/dataProc.h"
#include <stdint.h>



parsedData_t dataProcParseData(rawData_t* text){

    parsedData_t data;
    
    data.priority = text->value[DATA_IDX_PRIO];
    data.cmd = (((uint16_t)(text->value[DATA_IDX_CMD_MS])) << 8) + (uint16_t)text->value[DATA_IDX_CMD_LS];

    return data;
}

