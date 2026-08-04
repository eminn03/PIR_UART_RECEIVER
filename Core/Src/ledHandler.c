#include "../Inc/ledHandler.h"
#include "stm32g0xx_hal.h"


static volatile bool ledState = false;


void ledBlink(uint16_t delay){

	static uint32_t timer = 0;
	static uint8_t count = 0;

    if(!ledState)
        return;

	if(HAL_GetTick() - timer < delay && timer != 0)
		return;

	timer = HAL_GetTick();
    count++;

    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	if(count >= 2){

        count = 0;
        timer = 0;
        ledState = false;
    }

    return;
}

void ledON(){

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    ledState = true;
}
