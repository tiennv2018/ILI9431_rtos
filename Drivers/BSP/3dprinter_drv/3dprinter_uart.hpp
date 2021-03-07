/*
 * 3dprinter_uart.hpp
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */



#ifndef BSP_3DPRINTER_DRV_3DPRINTER_UART_HPP_
#define BSP_3DPRINTER_DRV_3DPRINTER_UART_HPP_
#ifdef __cplusplus
 extern "C" {
#endif

//#include "stm32f10x.h"
#include "stm32f1xx.h"

/* Exported macros ------------------------------------------------------------*/
#define UART_TX_BUFFER_SIZE (2048)
#define UART_RX_BUFFER_SIZE (2048)
/* Definition for Usart resources *********************************************/

#define BSP_UART_DEBUG      	(USART1)

class BspUart{
public:

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
		void (*uartRxDataCallback)(uint8_t *,uint8_t);
		void (*uartTxDoneCallback)(void);
	//	UART_HandleTypeDef handle;
		uint32_t debugNbRxFrames;
		uint32_t debugNbTxFrames;
		volatile uint32_t nbBridgedBytes;
	}BspUartDataType;
	BspUartDataType gBspUartData;

	uint8_t *IfGetFreeTxBuffer(void);
	void HwInit(uint32_t newBaudRate);
	void IfStart(void);
	void IfQueueTxData(uint8_t *pBuf, uint8_t nbData);
	void IfSendQueuedData(void);
	void AttachRxDataHandler(void (*callback)(uint8_t *, uint8_t));
	void AttachTxDoneCallback(void (*callback)(void));
	uint32_t Printf(const char* format,...);
	uint32_t GetNbRxAvalaibleBytes(void);
	int8_t GetNextRxBytes(void);
	uint8_t IsTxOnGoing(void);
	#if defined(MARLIN)
	uint32_t CommandsFilter(char *pBufCmd, uint8_t nxRxBytes);
	#endif
	void LockingTx(uint8_t *pBuf, uint8_t nbData);

	ErrorStatus Transmit_IT(uint8_t *pData, uint16_t Size);
	ErrorStatus Receive_IT(uint8_t *pData, uint16_t Size);

private:
	uint8_t ParseRxAvalaibleBytes(const char* pBuffer, uint8_t nbRxBytes);

};

/* Exported variables  --------------------------------------------------------*/
extern BspUart BSP_UART;

#ifdef __cplusplus
}
#endif
#endif /* BSP_3DPRINTER_DRV_3DPRINTER_UART_HPP_ */




