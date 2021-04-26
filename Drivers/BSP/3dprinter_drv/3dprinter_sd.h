/*
 * 3dprinter_sd.h
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#ifndef BSP_3DPRINTER_DRV_3DPRINTER_SD_H_
#define BSP_3DPRINTER_DRV_3DPRINTER_SD_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_sd.h"

/* Exported macros ------------------------------------------------------------*/

#define MSD_OK         0x00
#define MSD_ERROR      0x01

#define SD_PRESENT               ((uint8_t)0x01)
#define SD_NOT_PRESENT           ((uint8_t)0x00)

#define SD_DATATIMEOUT           ((uint32_t)100000000)

/* Definition for SD resources *********************************************/
#define BSP_SD_DETECT_PIN    (GPIO_PIN_15)
#define BSP_SD_DETECT_PORT   (GPIOA)

/// Interrupt line used for SD card detection
#define BSP_SD_DETECT_IRQn           (EXTI0_IRQn)

/// Priority used for SD card detection.
/// Warning, this priority shall be less than SysTick priority (higuest value)
#define BSP_SD_DETECT_PRIORITY	(0x07)

/* DMA definitions for SD DMA transfer */
#define __BSP_BSP_SD_DMAx_TxRx_CLK_ENABLE            __DMA2_CLK_ENABLE
#define BSP_SD_DMAx_Tx_CHANNEL                //DMA_CHANNEL_4
#define BSP_SD_DMAx_Rx_CHANNEL                //DMA_CHANNEL_4
#define BSP_SD_DMAx_Tx_STREAM                 //DMA2_Stream6
#define BSP_SD_DMAx_Rx_STREAM                 //DMA1_Channel3
#define BSP_SD_DMAx_Tx_IRQn                   //DMA1_Channel6
#define BSP_SD_DMAx_Rx_IRQn                   //DMA2_Stream3_IRQn
#define BSP_SD_DMAx_Tx_IRQHandler             //DMA2_Stream6_IRQHandler
#define BSP_SD_DMAx_Rx_IRQHandler             //DMA2_Stream3_IRQHandler

/* Exported types --- --------------------------------------------------------*/
#define SD_CardInfo HAL_SD_CardInfoTypeDef

typedef struct BspSdDataTag {
	SD_HandleTypeDef uSdHandle;
	SD_CardInfo uSdCardInfo;
} BspSdDataType;

/* Exported variables  --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
uint8_t BSP_SD_Init(void);
uint8_t BSP_SD_DeInit(void);
void BSP_SD_DetectInit(void);
void BSP_SD_DetectIT(void);
void BSP_SD_DetectCallback(void);
uint8_t BSP_SD_ReadBlocks(uint32_t *pData, uint64_t ReadAddr,
						  uint32_t BlockSize, uint32_t NumOfBlocks);
uint8_t BSP_SD_WriteBlocks(uint32_t *pData, uint64_t WriteAddr,
							uint32_t BlockSize, uint32_t NumOfBlocks);
uint8_t BSP_SD_ReadBlocks_DMA(uint32_t *pData, uint64_t ReadAddr,
							  uint32_t BlockSize, uint32_t NumOfBlocks);
uint8_t BSP_SD_WriteBlocks_DMA(uint32_t *pData, uint64_t WriteAddr,
								uint32_t BlockSize, uint32_t NumOfBlocks);
uint8_t BSP_SD_Erase(uint64_t StartAddr, uint64_t EndAddr);
void BSP_SD_IRQHandler(void);
void BSP_SD_DMA_Tx_IRQHandler(void);
void BSP_SD_DMA_Rx_IRQHandler(void);
HAL_SD_TransferStateTypedef BSP_SD_GetStatus(void);
void BSP_SD_GetCardInfo(HAL_SD_CardInfoTypeDef *CardInfo);
uint8_t BSP_SD_IsDetected(void);

#ifdef __cplusplus
}
#endif


#endif /* BSP_3DPRINTER_DRV_3DPRINTER_SD_H_ */
