#include "../Inc/ledHandler.h"
#include "stm32g0xx_hal.h"


void ledON(){

    GPIOA->BSRR = GPIO_PIN_5;
}

void ledOFF(){

    GPIOA->BRR = GPIO_PIN_5;
}
