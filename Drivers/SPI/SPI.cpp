/*
 * SPI.c
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */


#include <PROCESS/PROCESS.h>



/**
 *	@brief  Sends one byte over SPI and recovers a response
 *  @param  SPIx : where x can be 1, 2 or 3 to select the SPI peripheral
 *  @param  data : data to send
 *  @return data response from SPIx
 */

uint8_t SPI_SendReceiveByte(SPI_TypeDef* SPIx, uint8_t data)
{
//	uint8_t retry = 200;
//	while((SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET) && retry--);
//	SPI_I2S_SendData(SPIx, data);
//	retry = 200;
//	while((SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET) && retry--);
//	return SPI_I2S_ReceiveData(SPIx);
	return 0;
}





