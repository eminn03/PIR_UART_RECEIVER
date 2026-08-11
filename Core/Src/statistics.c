#include "../Inc/statistics.h"
#include <stddef.h>


static inline uint32_t absValue(int32_t value);


uint16_t mean(const uint16_t *data, uint16_t len, uint16_t startIndex){

    if(data == NULL)
        return 0;

    uint16_t result = 0;

    for(int i = startIndex; i < len; i++)
        result += data[i];

    result = result / (len - startIndex);

    return result;
}


uint32_t successiveDifference(const uint16_t *data, uint16_t len){

    if(data == NULL)
        return 0;

    uint32_t result = 0;

    for(int i = 1; i < len; i++)
        result += absValue(data[i] - data[i-1]);

    return result;
}

static inline uint32_t absValue(int32_t value){

    return (value < 0) ? -value : value;
}
