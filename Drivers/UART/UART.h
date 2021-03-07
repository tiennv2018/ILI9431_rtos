/*
 * uart.h
 *
 *  Created on: Sep 23, 2020
 *      Author: fw
 */


#ifndef UART_UART_H_
#define UART_UART_H_


//#define UART_TYPE_BASE_64						64

#define UART_RF									0x01
#define UART_APPLICATION						0x02

#define UART_FLAG_ACTIVE           				0x01
#define UART_FLAG_INACTIVE         				0x00
#define UART_MAX_HEX_LENGTH            			128
#define UART_MAX_STR_LENGTH            			256


typedef struct
{
    uint16_t length_str;
    uint16_t length_hex;
    uint8_t data_hex[UART_MAX_HEX_LENGTH];
    char data_str[UART_MAX_STR_LENGTH];
    uint8_t flag;
    uint8_t flag_recv;

}UART_INFO_typedef;

typedef struct
{
	UART_INFO_typedef RF;
	UART_INFO_typedef APPLICATION;

}UART_MODULE_typedef;

typedef struct
{
	UART_MODULE_typedef read;
	UART_INFO_typedef write;

}UART_typedef;


extern UART_typedef		UART;


extern void UART_init(void);
extern void UART_putchar(USART_TypeDef* USARTx, char ch);
extern void UART_putstring(USART_TypeDef* USARTx, char *str, uint16_t length);
extern void UART_write_buff(uint8_t *data, uint16_t data_length);
extern void UART_read_buff(void);


#endif /* UART_UART_H_ */









