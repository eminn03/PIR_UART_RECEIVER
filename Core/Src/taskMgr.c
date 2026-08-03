#include "../Inc/taskMgr.h"
#include "../Inc/dataDefinitons.h"
#include "../Inc/ledHandler.h"
#include "../Inc/restartHandler.h"


static PriorityQueue_t* p_taskQueue;
static parsedData_t activeTask;


void taskMgrInit(PriorityQueue_t *taskQueue){

    p_taskQueue = taskQueue;

    activeTask.cmd = CMD_NO_TASK;
    activeTask.priority = 0x00;
}

void taskMgr(){

    if(!pqueIsEmpty(p_taskQueue)){

        if(pquePeek(p_taskQueue).priority > activeTask.priority || activeTask.cmd == CMD_NO_TASK){

            ledReset();
            activeTask = pqueDequeue(p_taskQueue);
        }
    }

    switch (activeTask.cmd) {

        case CMD_SYS_RESTART:
            restartDevice();
            break;

        case CMD_LED_BLINK_3_TIMES:
            if(!ledBlink(3, 500))
                activeTask.cmd = CMD_NO_TASK;
            break;

        case CMD_LED_BLINK_5_TIMES:
            if(!ledBlink(5, 1000))
                activeTask.cmd = CMD_NO_TASK;
            break;

        case CMD_LED_BLINK_7_TIMES:
            if(!ledBlink(7, 2000))
                activeTask.cmd = CMD_NO_TASK;
            break;
        
        case CMD_LED_ON:
            ledON();
            activeTask.cmd = CMD_NO_TASK;
            break;
    
        case CMD_LED_OFF:
            ledOFF();
            activeTask.cmd = CMD_NO_TASK;
            break;
    }
}
