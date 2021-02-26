/*
 * TIMEOUT.c
 *
 *  Created on: Sep 23, 2019
 *      Author: On-HP
 */
#include "PROCESS/PROCESS.h"

TIMEOUT_typedef TIMEOUT;


void TIMEOUT_init(void)
{
    SystemCoreClockUpdate();
    if(SysTick_Config(SystemCoreClock / 1000))
    {
        while(1);
    }
}

void TIMEOUT_transfer_reader_start(uint32_t ms)
{
    TIMEOUT.tran_reader.flag 		= TIMEOUT_FLAG_INACTIVE;
    TIMEOUT.tran_reader.time_start 	= TIMEOUT_gettick_ms();
    TIMEOUT.tran_reader.time_interval = ms;
    TIMEOUT.tran_reader.state 		= TIMEOUT_STATE_RUN;
}

void TIMEOUT_recevice_reader_start(uint32_t ms)
{
    TIMEOUT.rec_reader.flag 		= TIMEOUT_FLAG_INACTIVE;
    TIMEOUT.rec_reader.time_start 	= TIMEOUT_gettick_ms();
    TIMEOUT.rec_reader.time_interval = ms;
    TIMEOUT.rec_reader.state 		= TIMEOUT_STATE_RUN;
}

void TIMEOUT_transfer_reader_stop(void)
{
    if(TIMEOUT.tran_reader.state == TIMEOUT_STATE_RUN)
    {
        if(TIMEOUT_gettick_ms() - TIMEOUT.tran_reader.time_start > TIMEOUT.tran_reader.time_interval)
        {
            TIMEOUT.tran_reader.flag 	= TIMEOUT_FLAG_ACTIVE;
            TIMEOUT.tran_reader.state 	= TIMEOUT_STATE_STOP;
        }
    }
}

void TIMEOUT_recevice_reader_stop(void)
{
    if(TIMEOUT.rec_reader.state == TIMEOUT_STATE_RUN)
    {
        if(TIMEOUT_gettick_ms() - TIMEOUT.rec_reader.time_start > TIMEOUT.rec_reader.time_interval)
        {
            TIMEOUT.rec_reader.flag = TIMEOUT_FLAG_ACTIVE;
            TIMEOUT.rec_reader.state = TIMEOUT_STATE_STOP;
        }
    }
}

uint32_t TIMEOUT_gettick_ms(void)
{
    return TIMEOUT.tick_ms.count_tick;
}

void TIMEOUT_delay_us( uint32_t num)
{
    uint32_t index;
    for(index = 0; index < 4*num; index++);
}

void TIMEOUT_delay_ms( uint32_t num)
{
    uint32_t index;
    for(index = 0; index < 4240*num; index++);
}
