/*
 * 3dprinter_adc.h
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#ifndef BSP_3DPRINTER_DRV_3DPRINTER_ADC_H_
#define BSP_3DPRINTER_DRV_3DPRINTER_ADC_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_adc.h"
/* Exported macros ------------------------------------------------------------*/

/* Definition for ADC resources *********************************************/
#define BSP_ADC                 		(ADC1)
#define __BSP_ADC_CLK_ENABLE()   	 	__ADC1_CLK_ENABLE()
#define __BSP_ADC_CLK_DISABLE()   		__ADC1_CLK_DISABLE()

#define __BSP_ADC_FORCE_RESET()      	__ADC_FORCE_RESET()
#define __BSP_ADC_RELEASE_RESET()    	__ADC_RELEASE_RESET()

#define BSP_ADC_CHANNEL_THERM_BED1   	(ADC_CHANNEL_12)
#define BSP_ADC_CHANNEL_THERM_E1    	(ADC_CHANNEL_0)
#define BSP_ADC_CHANNEL_THERM_E2    	(ADC_CHANNEL_1)
#define BSP_ADC_CHANNEL_THERM_E3    	(ADC_CHANNEL_2)
#define BSP_ADC_CHANNEL_THERM_BED2  	(ADC_CHANNEL_13)
#define BSP_ADC_CHANNEL_THERM_BED3 		(ADC_CHANNEL_3)

//Order ranks to have growing channels for compatibility with F0, L0...
#define BSP_ADC_RANK_THERM_BED1   		(5)
#define BSP_ADC_RANK_THERM_E1    		(1)
#define BSP_ADC_RANK_THERM_E2    		(2)
#define BSP_ADC_RANK_THERM_E3    		(3)
#define BSP_ADC_RANK_THERM_BED2   		(6)
#define BSP_ADC_RANK_THERM_BED3   		(4)

/* Definition for  thermistor Pins */
#define BSP_THERM_BED1_PIN              (GPIO_PIN_2)
#define BSP_THERM_BED1_PORT             (GPIOC)
#define BSP_THERM_BED2_PIN             	(GPIO_PIN_3)
#define BSP_THERM_BED2_PORT            	(GPIOC)
#define BSP_THERM_E1_PIN               	(GPIO_PIN_0)
#define BSP_THERM_E1_PORT             	(GPIOA)
#define BSP_THERM_E2_PIN               	(GPIO_PIN_1)
#define BSP_THERM_E2_PORT              	(GPIOA)
#define BSP_THERM_E3_PIN               	(GPIO_PIN_2)
#define BSP_THERM_E3_PORT              	(GPIOA)
#define BSP_THERM_BED3_PIN             	(GPIO_PIN_3)
#define BSP_THERM_BED3_PORT            	(GPIOA)

   /* Definition for IR Out Pin used for Z probing*/
#define BSP_IR_OUT_PIN                 	(GPIO_PIN_1)
#define BSP_IR_OUT_PORT                	(GPIOD)

/* Definition of ADC NVIC resources */
#define BSP_ADC_IRQn                   	(ADC_IRQn)
#define BSP_ADC_IRQHandler             	(ADC_IRQHandler)

/* Definition for DMA resources used by ADC************************************/

#define BSP_DMA                 		(DMA2_Stream0)
#define BSP_DMA_CHANNEL         		(DMA_CHANNEL_0)
#define __BSP_DMA_CLK_ENABLE()   		__DMA2_CLK_ENABLE()

#define BSP_DMA_IRQn            		(DMA2_Stream0_IRQn)
#define BSP_DMA_IRQHandler      		(DMA2_Stream0_IRQHandler)

/* Exported types --- --------------------------------------------------------*/
typedef struct BspAdcDataTag
{
  ADC_HandleTypeDef adcHandle;
  DMA_HandleTypeDef dmaHandle;
  uint8_t acquisitionDone;
}BspAdcDataType;

/* Exported variables  --------------------------------------------------------*/
extern BspAdcDataType gBspAdcData;

/* Exported functions --------------------------------------------------------*/
void BSP_AdcHwInit(void);
uint16_t BSP_AdcGetValue(uint8_t rankId);

#ifdef __cplusplus
}
#endif



#endif /* BSP_3DPRINTER_DRV_3DPRINTER_ADC_H_ */
