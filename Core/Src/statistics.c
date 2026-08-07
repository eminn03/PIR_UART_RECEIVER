#include "../Inc/statistics.h"


static inline uint32_t absValue(int32_t value);


uint16_t mean(uint16_t *data, uint16_t len, uint16_t startIndex){

    uint16_t result = 0;

    for(int i = startIndex; i < len; i++)
        result += data[i];

    result = result / (len - startIndex);

    return result;
}


uint32_t successiveDifference(uint16_t *data, uint16_t len){

    uint32_t result = 0;

    for(int i = 1; i < len; i++)
        result += absValue(data[i] - data[i-1]);

    return result;
}

static inline uint32_t absValue(int32_t value){

    return (value < 0) ? -value : value;
}
