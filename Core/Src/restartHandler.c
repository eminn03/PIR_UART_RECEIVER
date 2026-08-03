#include "../Inc/restartHandler.h"
#include "../Inc/sysContext.h"
#include "stm32g0xx_hal.h"


void restartDevice(){

    while(sysContextGetIsTxBusy()){}

    NVIC_SystemReset();
}
