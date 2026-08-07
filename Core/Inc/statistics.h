#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdint.h>


uint32_t successiveDifference(const uint16_t* data, uint16_t len);
uint16_t mean(const uint16_t* data, uint16_t len, uint16_t startIndex);


#endif
