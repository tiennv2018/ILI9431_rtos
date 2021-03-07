/*
 * 3dprinter_uart.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "3dprinter_uart.hpp"
#include "3dprinter_wifi.hpp"

BspUart BSP_UART;

#define UART_ERROR_TAG        (0x1000)
//#define UART_ERROR(error)     BSP_MiscErrorHandler(error|UART_ERROR_TAG)

uint8_t gBspUartTxBuffer[2 * UART_TX_BUFFER_SIZE]; // real size is double to easily handle memcpy and tx uart
uint8_t gBspUartRxBuffer[2 * UART_RX_BUFFER_SIZE];

void BspUart::HwInit(uint32_t newBaudRate)
{

//	USART_InitTypeDef		UART_InitStructure;
//	NVIC_InitTypeDef		NVIC_InitStructure;
//
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//
//    UART_InitStructure.USART_BaudRate 	= newBaudRate;
//	UART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	UART_InitStructure.USART_StopBits 	= USART_StopBits_1;
//	UART_InitStructure.USART_Parity 	= USART_Parity_No;
//	UART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	UART_InitStructure.USART_Mode 		= USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART1, &UART_InitStructure);
//
//	USART_Cmd(BSP_UART_DEBUG, ENABLE);
//	USART_ClearFlag(BSP_UART_DEBUG, USART_FLAG_RXNE);
//
//    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//    USART_ClearFlag(USART1, USART_IT_RXNE);
//    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void BspUart::IfStart(void)
{
	BspUart::BspUartDataType *pUart = &gBspUartData;

	pUart->pRxBuffer 		= (uint8_t *)gBspUartRxBuffer;
	pUart->pRxWriteBuffer 	=  pUart->pRxBuffer;
	pUart->pRxReadBuffer	=  pUart->pRxBuffer;

	pUart->pTxBuffer 		= (uint8_t *)gBspUartTxBuffer;
	pUart->pTxWriteBuffer 	=  pUart->pTxBuffer;
	pUart->pTxReadBuffer 	=  pUart->pTxBuffer;
	pUart->pTxWrap  		=  pUart->pTxBuffer + UART_TX_BUFFER_SIZE;

	pUart->rxBusy 			= RESET;
	pUart->txBusy 			= RESET;
	pUart->debugNbTxFrames 	= 0;
	pUart->debugNbRxFrames 	= 0;

	pUart->newTxRequestInThePipe = 0;
	pUart->nbBridgedBytes 	= 0;
	pUart->gCodeDataMode 	= 0;

	if(Receive_IT((uint8_t *)(&pUart->rxWriteChar), 1) != SUCCESS){
//		UART_ERROR(3);
	}
	pUart->rxBusy = SET;
}

void BspUart::IfQueueTxData(uint8_t *pBuf, uint8_t nbData)
{
	if (nbData != 0)
	{
		BspUart::BspUartDataType *pUart= &gBspUartData;
		int32_t nbFreeBytes = pUart->pTxReadBuffer - pUart->pTxWriteBuffer;

		if (nbFreeBytes <= 0)
		{
			nbFreeBytes += UART_TX_BUFFER_SIZE;
		}
		if (nbData > nbFreeBytes)
		{
		/* Uart Tx buffer is full */
//				UART_ERROR(4);
		}
		memcpy((uint8_t *)pUart->pTxWriteBuffer, pBuf, nbData);
		pUart->pTxWriteBuffer += nbData;
#if defined(MARLIN)
		if (pBuf[nbData-1] == '\n')
		{
		  *pUart->pTxWriteBuffer = '\n';
		  pUart->pTxWriteBuffer--;
		  *pUart->pTxWriteBuffer = '\r';
		  pUart->pTxWriteBuffer += 2;
		  if (pUart->pTxWriteBuffer >= pUart->pTxBuffer + UART_TX_BUFFER_SIZE)
		  {
			pUart->pTxWrap = pUart->pTxWriteBuffer;
			pUart->pTxWriteBuffer = pUart->pTxBuffer;
		  }
		  //BSP_UartIfSendQueuedData();  // BDI
		}
#else
		if (pUart->pTxWriteBuffer >= pUart->pTxBuffer + UART_TX_BUFFER_SIZE)
		{
		  pUart->pTxWrap = pUart->pTxWriteBuffer;
		  pUart->pTxWriteBuffer = pUart->pTxBuffer;
		}
#endif
		BspUart::IfSendQueuedData();
	}
}

/******************************************************//**
 * @brief  Send queued data to the GUI
 * @param None
 * @retval None
 **********************************************************/
void BspUart::IfSendQueuedData(void)
{
	BspUart::BspUartDataType *pUart= &gBspUartData;
#ifdef USE_XONXOFF
    if ((pUart->newTxRequestInThePipe == 0)&&
        (pUart->txBusy == RESET))
    {
		if ((BspUartXonXoff == 2)||
		((BSP_UART_GET_NB_BYTES_IN_TX_BUFFER()  > BSP_UART_TX_THRESHOLD_XOFF) && (BspUartXonXoff == 0)))
		{
			pUart->txBusy = SET;
			pUart->nbTxBytesOnGoing = 0;
			BspUartXoffBuffer[0] = 0x13;
		if (HAL_UART_Transmit_IT(&pUart->handle, (uint8_t *)&BspUartXoffBuffer, sizeof(BspUartXoffBuffer))!= HAL_OK)
		{
//			UART_ERROR(10);
		}
			BspUartXonXoff = 3;
			return;
		}
		else if ((BspUartXonXoff == 1)||
        ((BSP_UART_GET_NB_BYTES_IN_RX_BUFFER()  < BSP_UART_RX_THRESHOLD_XON) && (BspUartXonXoff == 3)&& (BSP_UART_GET_NB_BYTES_IN_TX_BUFFER() < BSP_UART_TX_THRESHOLD_XON)))
		{
			pUart->txBusy = SET;
			pUart->nbTxBytesOnGoing = 0;
			BspUartXonBuffer[0] = 0x11;

			if (HAL_UART_Transmit_IT(&pUart->handle, (uint8_t *)&BspUartXonBuffer, sizeof(BspUartXonBuffer))!= HAL_OK)
			{
//				UART_ERROR(11);
			}
			BspUartXonXoff = 0;
			return;
		}
    }
#endif

	if ((pUart->newTxRequestInThePipe == 0)&&
	(pUart->txBusy == RESET)&&
	(pUart->pTxReadBuffer != pUart->pTxWriteBuffer))
	{
		int32_t nbTxBytes = pUart->pTxWriteBuffer - pUart->pTxReadBuffer;
		pUart->newTxRequestInThePipe++;
		if (nbTxBytes < 0)
		{
			nbTxBytes = pUart->pTxWrap - pUart->pTxReadBuffer;
		}
#if defined(MARLIN)
		if (pUart->pTxReadBuffer[nbTxBytes-1]!='\n')
		{
			pUart->newTxRequestInThePipe--;
			return;
		}
#endif
		pUart->txBusy = SET;
		pUart->nbTxBytesOnGoing = nbTxBytes;

		//use of HAL_UART_Transmit_IT is safe as real buffer size is 2 * UART_TX_BUFFER_SIZE
		if(Transmit_IT((uint8_t *) pUart->pTxReadBuffer, nbTxBytes)!= SUCCESS)
		{
//			UART_ERROR(5);
		}

		pUart->debugNbTxFrames++;
		pUart->newTxRequestInThePipe--;
	}
}

/******************************************************//**
 * @brief  Attaches a callback which will be called when
 * a complete rx uart buffer is ready
 * @param[in] callback Name of the callback to attach
 * @retval None
 **********************************************************/
void BspUart::AttachRxDataHandler(void (*callback)(uint8_t *, uint8_t))
{
	BspUart::BspUartDataType *pUart = &gBspUartData;
	pUart->uartRxDataCallback = (void (*)(uint8_t *, uint8_t))callback;
}
/******************************************************//**
 * @brief  Attaches a callback which will be called when
 * a complete tx uart buffer is ready
 * @param[in] callback Name of the callback to attach
 * @retval None
 **********************************************************/
void BspUart::AttachTxDoneCallback(void (*callback)(void))
{
	BspUartDataType *pUart = &gBspUartData;
	pUart->uartTxDoneCallback = (void (*)(void))callback;
}

/******************************************************//**
 * @brief  This function trigs the transmission of a string over the UART
 *             for printing
 * @param[in] format string with formatting
 * @param[in]  Optional arguments to fit with formatting
 * @retval Lengthj of the string to print (uint32_t)
 **********************************************************/
uint32_t BspUart::Printf(const char* format,...)
{
	BspUartDataType *pUart = &gBspUartData;
	va_list args;
	uint32_t size;
	uint32_t retSize = 0;
	int32_t nbFreeBytes = pUart->pTxReadBuffer - pUart->pTxWriteBuffer;

	if (nbFreeBytes <= 0)
	{
		nbFreeBytes += UART_TX_BUFFER_SIZE;
	}

	char *writeBufferp =(char *) pUart->pTxWriteBuffer;
	/* the string to transmit is copied in the temporary buffer in order to    */
	/* check its size.                                                         */
	va_start(args, format);
	size=vsprintf(writeBufferp, (const char*)format, args);
	va_end(args);

	retSize = size;
	if (*(writeBufferp + size - 1) == '\n')
	{
		*(writeBufferp + size - 1) = '\r';
		*(writeBufferp + size) = '\n';
		size++;
	}
	if (size != 0)
	{
		if ( size > (uint32_t)nbFreeBytes )
		{
//			UART_ERROR(9);
		}
	pUart->pTxWriteBuffer += size;
	if (pUart->pTxWriteBuffer >= pUart->pTxBuffer + UART_TX_BUFFER_SIZE)
	{
		pUart->pTxWrap = pUart->pTxWriteBuffer;
		pUart->pTxWriteBuffer  = pUart->pTxBuffer;
	}

	BspUart::IfSendQueuedData();
	}
	return(retSize);
}

/******************************************************//**
 * @brief  This function returns the number of bytes received via the UART
 * @param[in] fnone
  * @retval nxRxBytes nb received bytes
 **********************************************************/
uint32_t BspUart::GetNbRxAvalaibleBytes(void)
{
	BspUartDataType *pUart = &gBspUartData;
	uint8_t *writePtr = (uint8_t *)(pUart->pRxWriteBuffer - 1);

	if (writePtr < pUart->pRxBuffer)
	{
		writePtr += UART_RX_BUFFER_SIZE;
	}

	//waitline feed to have a complete line before processing bytes
	if ((int8_t)(*writePtr) != 0XA)
	return (0);

	int32_t nxRxBytes = pUart->pRxWriteBuffer - pUart->pRxReadBuffer;
	if (nxRxBytes < 0)
	{
		nxRxBytes += UART_RX_BUFFER_SIZE;
	}
#if !defined(MARLIN)
	if (nxRxBytes != 0)
	{
		uint8_t result = BspUart::ParseRxAvalaibleBytes((char const*)pUart->pRxReadBuffer, nxRxBytes);
		if (result < BSP_WIFI_THRES_TO_GCODE_PARSER)
		{
			//The available bytes will not to go into the Gcode parser
			pUart->pRxReadBuffer += nxRxBytes;
			nxRxBytes = 0;
			if (pUart->pRxReadBuffer >= (pUart->pRxBuffer + UART_RX_BUFFER_SIZE))
			{
				pUart->pRxReadBuffer = pUart->pRxBuffer;
			}
		}
	}
#endif
	return ((uint32_t) nxRxBytes );
}

/******************************************************//**
 * @brief  This function returns the number of bytes received via the UART
 * @param[in] fnone
  * @retval nxRxBytes nb received bytes
 **********************************************************/
uint8_t BspUart::ParseRxAvalaibleBytes(const char* pBuffer, uint8_t nbRxBytes)
{
	return (BSP_WIFI.ParseTxBytes(pBuffer, nbRxBytes, BSP_WIFI_SOURCE_IS_DEBUG_UART));
}

/******************************************************//**
 * @brief  This function returns the first byte available on the UART
 * @param[in] none
 * @retval byteValue (0-0X7F)  or -1 if no byte is available
 **********************************************************/
int8_t BspUart::GetNextRxBytes(void)
{
	BspUartDataType *pUart = &gBspUartData;
	int8_t byteValue;

	uint8_t *writePtr = (uint8_t *)(pUart->pRxWriteBuffer);

	if (writePtr < pUart->pRxBuffer)
	{
		writePtr += UART_RX_BUFFER_SIZE;
	}

	if (pUart->pRxReadBuffer != writePtr)
	{
		byteValue = (int8_t)(*(pUart->pRxReadBuffer));
		pUart->pRxReadBuffer++;

		if (pUart->pRxReadBuffer >= (pUart->pRxBuffer + UART_RX_BUFFER_SIZE))
		{
			pUart->pRxReadBuffer = pUart->pRxBuffer;
		}
	}
	else
	{
		byteValue = -1;
	}

	return (byteValue);
}

/******************************************************//**
 * @brief  Returns if there is a pending TX request in the UART
 * @param[in] none
 * @retval 0 if no pending TX request in the UART
 **********************************************************/
uint8_t BspUart::IsTxOnGoing(void)
{
	BspUartDataType *pUart = &gBspUartData;
	return (pUart->newTxRequestInThePipe||pUart->txBusy);
}

#if defined(MARLIN)
/******************************************************//**
 * @brief  This function calls the WIFI TX parser and returns 0 when the command
   in the buffer is not destinated to the gcode parser
 * @param[in] pBuf pointer to the buffer holding the command
 * @retval number of bytes destinated to the gcode parser
 **********************************************************/
uint32_t BspUart::CommandsFilter(char *pBufCmd, uint8_t nxRxBytes)
{
	if (BSP_UartParseRxAvalaibleBytes((char const*)pBufCmd, nxRxBytes)\
		< BSP_WIFI_THRES_TO_GCODE_PARSER)
	{
		nxRxBytes = 0;
	}
	return nxRxBytes;
}
#endif

/******************************************************//**
 * @brief  This function sends data via the Uart in locking
 * mode (no interrupt used).
 * It should not be used except by the Error handler
 * @param[in]  pBuf pointer to the data to be sent
 * @param[in]  nbData number of bytes to be sent
 * @retval None
 **********************************************************/

void BspUart::LockingTx(uint8_t *pBuf, uint8_t nbData)
{
//   BspUartDataType *pUart = &gBspUartData;
   Transmit_IT(pBuf, nbData);
}


ErrorStatus BspUart::Transmit_IT(uint8_t *pData, uint16_t Size)
{
    uint16_t i;
    for(i = 0; i < Size; i++)
    {
//        USART_SendData(BSP_UART_DEBUG, (char) pData[i]);
//        while (USART_GetFlagStatus(BSP_UART_DEBUG, USART_FLAG_TC) == RESET);
    }
    return SUCCESS;
}

ErrorStatus BspUart::Receive_IT(uint8_t *pData, uint16_t Size)
{
	uint16_t i;

	for(i = 0; i < Size; i++)
	{
//		while(USART_GetFlagStatus (USART1, USART_FLAG_RXNE) == RESET);
//		pData[i] = USART_ReceiveData(BSP_UART_DEBUG);
	}

	return SUCCESS;
}






















