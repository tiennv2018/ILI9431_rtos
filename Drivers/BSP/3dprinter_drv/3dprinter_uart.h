/*
 * 3dprinter_uart.hpp
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */



#ifndef BSP_3DPRINTER_DRV_3DPRINTER_UART_H_
#define BSP_3DPRINTER_DRV_3DPRINTER_UART_H_
#ifdef __cplusplus
 extern "C" {
#endif

//#include "stm32f10x.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_uart.h"

/* Exported macros ------------------------------------------------------------*/
#define UART_TX_BUFFER_SIZE (2048)
#define UART_RX_BUFFER_SIZE (2048)
/* Definition for Usart resources *********************************************/

#define BSP_UART_DEBUG      	(USART1)

typedef struct {
	volatile uint8_t rxWriteChar;
	uint8_t *pRxBuffer;
	volatile uint8_t *pRxWriteBuffer;
	volatile uint8_t *pRxReadBuffer;
	uint8_t *pTxBuffer;
	volatile uint8_t *pTxWriteBuffer;
	volatile uint8_t *pTxReadBuffer;
	volatile uint8_t *pTxWrap;
	volatile uint8_t newTxRequestInThePipe;
	volatile uint8_t gCodeDataMode;
	volatile uint16_t nbTxBytesOnGoing;
	volatile ITStatus rxBusy;
	volatile ITStatus txBusy;
	void (*uartRxDataCallback)(uint8_t*, uint8_t);
	void (*uartTxDoneCallback)(void);
	UART_HandleTypeDef handle;
	uint32_t debugNbRxFrames;
	uint32_t debugNbTxFrames;
	volatile uint32_t nbBridgedBytes;
}BspUartDataType;

extern BspUartDataType gBspUartData;

uint8_t *BspUart_IfGetFreeTxBuffer(void);
void BspUart_HwInit(uint32_t newBaudRate);
void BspUart_IfStart(void);
void BspUart_IfQueueTxData(uint8_t *pBuf, uint8_t nbData);
void BspUart_IfSendQueuedData(void);
void BspUart_AttachRxDataHandler(void (*callback)(uint8_t *, uint8_t));
void BspUart_AttachTxDoneCallback(void (*callback)(void));
uint32_t BspUart_Printf(const char* format,...);
uint32_t BspUart_GetNbRxAvalaibleBytes(void);
int8_t BspUart_GetNextRxBytes(void);
uint8_t BspUart_IsTxOnGoing(void);
#if defined(MARLIN)
uint32_t BspUart_CommandsFilter(char *pBufCmd, uint8_t nxRxBytes);
#endif
void BspUart_LockingTx(uint8_t *pBuf, uint8_t nbData);

ErrorStatus BspUart_Transmit_IT(uint8_t *pData, uint16_t Size);
ErrorStatus BspUart_Receive_IT(uint8_t *pData, uint16_t Size);

uint8_t BspUart_ParseRxAvalaibleBytes(const char* pBuffer, uint8_t nbRxBytes);



/* Exported variables  --------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* BSP_3DPRINTER_DRV_3DPRINTER_UART_H_ */




