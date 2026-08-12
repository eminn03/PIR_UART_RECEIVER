#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdint.h>


uint32_t filteredSuccessiveDifference(const uint16_t* data, uint16_t len, uint16_t threshold, uint8_t reductionAmount);
uint16_t mean(const uint16_t* data, uint16_t len, uint16_t startIndex);


#endif
