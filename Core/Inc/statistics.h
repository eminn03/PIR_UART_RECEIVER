#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdint.h>


uint32_t successiveDifference(uint16_t* data, uint16_t len);
uint16_t mean(uint16_t* data, uint16_t len, uint16_t startIndex);


#endif
