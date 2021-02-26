/*
 * TIMEOUT.h
 *
 *  Created on: Sep 23, 2019
 *      Author: On-HP
 */

#ifndef TIMEOUT_TIMEOUT_H_
#define TIMEOUT_TIMEOUT_H_

#define TIMEOUT_FLAG_INACTIVE 		0x00
#define TIMEOUT_FLAG_ACTIVE         0x01
#define TIMEOUT_STATE_STOP          0x00
#define TIMEOUT_STATE_RUN           0x01

#define TIMEOUT_READER_PROCESS      2000


#define Delay_ms(x)					TIMEOUT_delay_ms(x)

typedef struct
{
    uint8_t flag;
    uint8_t state;
    uint32_t time_start;
    uint32_t time_interval;

}TIMEOUT_INFOR_typedef;

typedef struct
{
    uint32_t count_tick;
    uint32_t tick;
    uint32_t time_start;

}TIMEOUT_TICK_typedef;

typedef struct
{
    TIMEOUT_TICK_typedef tick_ms;
    TIMEOUT_INFOR_typedef tran_reader;
    TIMEOUT_INFOR_typedef rec_reader;

}TIMEOUT_typedef;

extern TIMEOUT_typedef  TIMEOUT;

void TIMEOUT_init(void);

void TIMEOUT_transfer_reader_start(uint32_t ms);
void TIMEOUT_transfer_reader_stop(void);
void TIMEOUT_recevice_reader_start(uint32_t ms);
void TIMEOUT_recevice_reader_stop(void);

uint32_t TIMEOUT_gettick_ms(void);
void TIMEOUT_delay_us( uint32_t num);
void TIMEOUT_delay_ms( uint32_t num);


#endif /* TIMEOUT_TIMEOUT_H_ */
