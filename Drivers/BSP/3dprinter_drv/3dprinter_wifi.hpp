/*
 * 3dprinter_wifi.hpp
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#ifndef __3DPRINTER_WIFI_H
#define __3DPRINTER_WIFI_H

#ifdef __cplusplus
 extern "C" {
#endif
 /* Includes ---------------------------------------------------------------*/
#include "stm32f1xx.h"

/* Exported macros -----------------------------------------------------------*/

/* Definition for Wifi resources *********************************************/

/// GPIO Pin used for the WIFI boot0 pin
#define BSP_WIFI_BOOT_PIN               (GPIO_PIN_12)
/// GPIO Port used for the WIFI boot0 pin
#define BSP_WIFI_BOOT_PORT              (GPIOE)

/// GPIO Pin used for the WIFI Reset pin
#define BSP_WIFI_RESET_PIN              GPIO_PIN_11
/// GPIO Port used for the WIFI Reset pin
#define BSP_WIFI_RESET_PORT             (GPIOE)

/// GPIO Pin used for the WIFI wakeup pin
#define BSP_WIFI_WAKEUP_PIN             //(GPIO_PIN_5)
/// GPIO Port used for the WIFI wakeup pin
#define BSP_WIFI_WAKEUP_PORT            (GPIOB)

/* Definition for the UART used by the WIFI module */
#define BSP_WIFI_UART_BYTES_NONE                     (0x0)
#define BSP_WIFI_UART_BYTES_TO_WIFI                  (0x1)
#define BSP_WIFI_THRES_TO_GCODE_PARSER               (0x2)
#define BSP_WIFI_UART_BYTES_TO_GCODE_PARSER          (0x4)
#define BSP_WIFI_UART_BYTES_TO_WIFI_AND_GCODE_PARSER (BSP_WIFI_UART_BYTES_TO_WIFI |\
												   BSP_WIFI_UART_BYTES_TO_GCODE_PARSER)
#define BSP_WIFI_FILE_CREATION_OK            (0)
#define BSP_WIFI_FILE_SIZE_TOO_BIG           (1)
#define BSP_WIFI_FILE_NAME_TOO_LONG          (2)

#define BSP_WIFI_SOURCE_IS_PLATFORM          (0)
#define BSP_WIFI_SOURCE_IS_DEBUG_UART        (1)

#define BSP_WIFI_UART                           (USART2)
#define __BSP_WIFI_UART_CLK_ENABLE()              __USART2_CLK_ENABLE()
#define __BSP_WIFI_UART_CLK_DISABLE()             __USART2_CLK_DISABLE()

#define __BSP_WIFI_UART_CTS_GPIO_CLK_ENABLE()      __GPIOD_CLK_ENABLE()
#define __BSP_WIFI_UART_RTS_GPIO_CLK_ENABLE()      __GPIOD_CLK_ENABLE()
#define __BSP_WIFI_UART_RX_GPIO_CLK_ENABLE()      __GPIOD_CLK_ENABLE()
#define __BSP_WIFI_UART_TX_GPIO_CLK_ENABLE()      __GPIOD_CLK_ENABLE()

#define __BSP_WIFI_UART_FORCE_RESET()             __USART2_FORCE_RESET()
#define __BSP_WIFI_UART_RELEASE_RESET()           __USART2_RELEASE_RESET()

/// GPIO Pin used for the UART2 CTS pin
#define BSP_WIFI_UART_CTS_PIN               (GPIO_PIN_3)
/// GPIO Port used for the UART2 CTS pin
#define BSP_WIFI_UART_CTS_PORT              (GPIOD)

/// GPIO Pin used for the UART2 RTS pin
#define BSP_WIFI_UART_RTS_PIN               (GPIO_PIN_4)
/// GPIO Port used for the UART2 RTS pin
#define BSP_WIFI_UART_RTS_PORT              (GPIOD)

/// GPIO Pin used for the UART2 TX pin
#define BSP_WIFI_UART_TX_PIN               (GPIO_PIN_5)
/// GPIO Port used for the UART2 TX pin
#define BSP_WIFI_UART_TX_PORT              (GPIOD)

/// GPIO Pintused for the UART2 Rx pin
#define BSP_WIFI_UART_RX_PIN               (GPIO_PIN_6)
/// GPIO Port used for the UART2 Rx pin
#define BSP_WIFI_UART_RX_PORT              (GPIOD)

/* Definition for BSP_UART_DEBUG's NVIC */
#define BSP_WIFI_UART_IRQn                      (USART2_IRQn)
#define BSP_WIFI_UART_IRQHandler                (USART2_IRQHandler)

#define BSP_WIFI_UART_CTS_AF                     (GPIO_AF7_USART2)
#define BSP_WIFI_UART_RTS_AF                     (GPIO_AF7_USART2)
#define BSP_WIFI_UART_TX_AF                     (GPIO_AF7_USART2)
#define BSP_WIFI_UART_RX_AF                     (GPIO_AF7_USART2)

/* Definition for DMA resources used by UART for Wifi module ******************/

#define __BSP_WIFI_UART_DMA_CLK_ENABLE()          __HAL_RCC_DMA1_CLK_ENABLE()

#define BSP_WIFI_UART_DMA_RX           (DMA1_Stream5)
#define BSP_WIFI_UART_DMA_RX_CHANNEL   (DMA_CHANNEL_4)

#define BSP_WIFI_UART_DMA_TX           (DMA1_Stream6)
#define BSP_WIFI_UART_DMA_TX_CHANNEL   (DMA_CHANNEL_4)

#define BSP_WIFI_UART_DMA_TX_IRQn               (DMA1_Stream6_IRQn)
#define BSP_WIFI_UART_DMA_TX_IRQHandler         (DMA1_Stream6_IRQHandler)

#define BSP_WIFI_UART_DMA_RX_IRQn               (DMA1_Stream5_IRQn)
#define BSP_WIFI_UART_DMA_RX_IRQHandler         (DMA1_Stream5_IRQHandler)

/* Exported types --- --------------------------------------------------------*/

class BspWifi
{
private :
	void Restart(void);
public:
	typedef struct BspWifiDataTag
	{
//		UART_HandleTypeDef uartHandle;
//		DMA_HandleTypeDef rxDmaHandle;
//		DMA_HandleTypeDef txDmaHandle;
		volatile uint8_t txFlag;
		uint8_t *pRxBuffer;
		uint8_t *pRxWriteBuffer;
		uint8_t *pRxReadBuffer;
		uint8_t *pTxBuffer;
		uint8_t *pTxWriteBuffer;
		uint8_t mode;
		uint8_t state;
		uint8_t restartPending;
		volatile uint8_t commandPending;
		int8_t configPending;
		uint8_t fileCreationPending;
		uint32_t lastTime;
		uint32_t replyCounter;
//#if defined(PROD_TEST)
		uint8_t fwUpdatePending;
		int8_t fsUpdatePending;
		char currentFwVersion[14+1];
		char expectedFwVersion[14+1];
		char expectedFsVersion[21+1];
//#endif //#if defined(PROD_TEST)
		char wepKey[13+1];
	  char ssid[32+1];
	}BspWifiDataType;

	BspWifiDataType gBspWifiData;

//#if defined(PROD_TEST)
	void HwInit(uint32_t baudRate, char* ssid, char* wepKey, char* expectedFwVersion, char* expectedFsVersion);
//#else
	void HwInit(uint32_t baudRate, char* ssid, char* wepKey);
//#endif
	uint8_t UartRxCpltCallback(void *UartHandle,
			unsigned char **c);
	void UartTxCpltCallback(void *UartHandle);
	void ProcessUartBytes(void);
	uint8_t ParseTxBytes(const char* pBuffer, uint16_t nbTxBytes,
			uint8_t source);
	uint8_t ParseRxBytes(uint8_t offset, uint8_t nbBytes);
	uint8_t CreateFileInWifiModuleRam(const char* fileName,\
			uint16_t fileSizeWithoutHttpHeader);
	uint8_t IsFileCreation(void);
	void GpioInit(void);
	void UartInit(uint32_t baudRate);
};

extern BspWifi BSP_WIFI;



#ifdef __cplusplus
}
#endif

#endif
