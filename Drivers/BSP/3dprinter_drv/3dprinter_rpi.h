/*
 * 3dprinter_rpi.h
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#ifndef BSP_3DPRINTER_DRV_3DPRINTER_RPI_H_
#define BSP_3DPRINTER_DRV_3DPRINTER_RPI_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f1xx_hal.h"

/* Exported macros -----------------------------------------------------------*/

/* Definition for RPi resources *********************************************/

/// GPIO Pin used for the Raspberry Pi ready state pin
#define BSP_RPI_READY_PIN               (GPIO_PIN_0)
/// GPIO Port used for the Raspberry Pi ready state pin
#define BSP_RPI_READY_PORT              (GPIOE)


void BspRPi_GpioInit(void);
void BspRPi_WaitUntilReady(void);


#ifdef __cplusplus
}
#endif

#endif /* BSP_3DPRINTER_DRV_3DPRINTER_RPI_H_ */
