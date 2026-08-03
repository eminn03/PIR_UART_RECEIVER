#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#include <stdint.h>
#include <stdbool.h>


bool ledON();
void ledOFF();
bool ledBlink(uint8_t count, uint16_t delay);
void ledReset();


#endif
