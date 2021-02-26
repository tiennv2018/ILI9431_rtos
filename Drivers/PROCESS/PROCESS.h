/*
 * PROCESS.h
 *
 *  Created on: Nov 25, 2020
 *      Author: fw_tien
 */

#ifndef PROCESS_PROCESS_H_
#define PROCESS_PROCESS_H_

/* Includes */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stm32f10x.h>
#include <stm32f1xx_it.h>
#include <stm32f10x_conf.h>

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <misc.h>

#include <GPIO/GPIO.h>
#include <SPI/SPI.h>
//#include <UART/UART.h>
#include <ENCODE/ENCODE.h>
#include <ANALYZE/ANALYZE.h>
//#include <CRYPTION/cryption.h>
#include <TIMEOUT/TIMEOUT.h>
#include <LCD_ILI9431/ILI9431/ILI9431.h>
#include <LCD_ILI9431/XPT2046/XPT2046.h>
#include <LCD_ILI9431/TOUCH/TOUCH.h>
#include <LCD_ILI9431/DISPLAY/DISPLAY.h>

//#include <PACKET/PACKET.h>
//#include <TIM/TIM.h>


#define PROCESS_FLAG_ACTIVE                             0x01
#define PROCESS_FLAG_INACTIVE                           0x00

#define PROCESS_READER_MAX_NUMBER                       8
#define PROCESS_READER_MAX_VALUE                        150
#define PROCESS_READER_STEP                             3
#define PROCESS_READER_START_PORT                       1
#define PROCESS_READER_MIN_LENGTH                       5
#define PROCESS_READER_MAX_LENGTH                       128


#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5


typedef struct
{
    uint32_t time_start;
    uint32_t time_cycle;

}PROCESS_LED_typedef;

typedef struct
{
    uint8_t number;
    uint8_t length;
    uint8_t data[PROCESS_READER_MAX_VALUE];

}METADATA_typedef;

typedef struct
{
    uint8_t length;
    uint8_t type;
    uint16_t port;
    uint8_t data[PROCESS_READER_MAX_VALUE];

}CHANGE_SETTING_typedef;

typedef struct
{
    uint8_t number_connected;
    uint8_t data[PROCESS_READER_MAX_VALUE];
    uint8_t length;
    uint8_t flag;

}READER_typedef;

typedef struct
{
    PROCESS_LED_typedef led;
    METADATA_typedef metadata;
    CHANGE_SETTING_typedef setting;
    READER_typedef reader;

}PROCESS_typedef;

extern PROCESS_typedef SENSOR_HUB;

void PROCESS_led(void);
void PROCESS_init(void);
void PROCESS_app(void);
void vApplicationTickHook(void);

#endif /* PROCESS_PROCESS_H_ */
