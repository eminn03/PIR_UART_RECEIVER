#ifndef DATA_DEFINITIONS_H
#define DATA_DEFINITIONS_H

#include <stdint.h>

#define BUFFER_SIZE 7

#define DATA_STRT 0x02
#define DATA_END 0x03
#define DATA_DEV_ADDR 0x10


typedef enum{

    DATA_IDX_STRT = 0,
    DATA_IDX_DEV_ADDR = 2,
    DATA_IDX_CMD_MS = 4,
    DATA_IDX_CMD_LS = 5,
    DATA_IDX_CRC_MS = 6,
    DATA_IDX_CRC_LS = 7,
    DATA_IDX_END = 8

}DataIndex_t;


typedef enum{

    CMD_SYS_RESTART = 0x1000,
    CMD_LED_BLINK_3_TIMES = 0x1001,
    CMD_LED_BLINK_5_TIMES = 0x1002,
    CMD_LED_BLINK_7_TIMES = 0x1003,
    CMD_LED_ON = 0x1007,
    CMD_LED_OFF = 0x1008,
    CMD_NO_TASK = 0x0000

}Cmd_t;


typedef struct{
    uint16_t cmd;
} parsedData_t;

typedef struct{
    uint8_t value[BUFFER_SIZE];
    uint8_t len;
} rawData_t;


#endif
