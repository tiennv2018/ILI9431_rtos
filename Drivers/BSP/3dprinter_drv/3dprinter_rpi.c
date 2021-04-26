/*
 * 3dprinter_rpi.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#include "3dprinter_rpi.h"
#include "3dprinter_misc.h"
#include "string.h"
#include <stdio.h>


void BspRPi_GpioInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = BSP_RPI_READY_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(BSP_RPI_READY_PORT, &GPIO_InitStruct);

	HAL_Delay(100);
}


void BspRPi_WaitUntilReady(void)
{
	uint8_t exit_loop = 0;

	while (!exit_loop) {

		if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(BSP_RPI_READY_PORT, BSP_RPI_READY_PIN))
		{
			HAL_Delay(100);

			if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(BSP_RPI_READY_PORT, BSP_RPI_READY_PIN))
				exit_loop = 1;
		}
	}

	// Wait 5 second more
	HAL_Delay(5000);
}

