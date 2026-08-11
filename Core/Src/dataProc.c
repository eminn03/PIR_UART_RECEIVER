#include "../Inc/dataProc.h"
#include <stdint.h>
#include <stddef.h>


parsedData_t dataProcParseData(const rawData_t* text){

    if(text == NULL || text->len <= DATA_IDX_PIR_LS)
        return 0;
        
    return ((uint16_t)text->value[DATA_IDX_PIR_MS] << 8) | (uint16_t)text->value[DATA_IDX_PIR_LS];
}

