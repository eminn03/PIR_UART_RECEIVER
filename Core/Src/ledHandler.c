#include "../Inc/ledHandler.h"
#include "stm32g0xx_hal.h"


static volatile bool resetRequired = false;


bool ledON(){

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    return true;
}

void ledOFF(){

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

bool ledBlink(uint8_t count, uint16_t delay){

	static uint8_t blinkCount = 0;
	static uint32_t timer = 0;

    if(resetRequired){

        resetRequired = false;
        blinkCount = 0;
        timer = 0;
    }

	if(timer != 0 || blinkCount != 0)
		if(HAL_GetTick() - timer < delay)
			return true;

	timer = HAL_GetTick();

    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    blinkCount++;

	if(blinkCount > count*2){

        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        return false;
	}

    return true;
}

void ledReset(){

    resetRequired = true;
}

