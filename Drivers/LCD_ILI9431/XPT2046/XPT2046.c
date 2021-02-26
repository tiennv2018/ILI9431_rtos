/*
 * XPT2046.c
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */

#include <PROCESS/PROCESS.h>

void XPT2046_set_gpio(void);
uint16_t XPT2046_read_x(void);
uint16_t XPT2046_read_y(void);
void XPT2046_read_cursor(int32_t *cur_x, int32_t *cur_y);

void XPT2046_delay(uint32_t time);
uint8_t XPT2046_rev_tranfer_byte(uint8_t byte);


XPT2046_touch_st XPT2046_st;


void XPT2046_set_gpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	EXTI_InitTypeDef EXTI_InitStructure;

	RCC_APB2PeriphClockCmd(XPT2046_GPIO_RCC_PORT, ENABLE);

	GPIO_InitStructure.GPIO_Pin 	= XPT2046_MISO_PIN  | XPT2046_MOSI_PIN | XPT2046_SCK_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(XPT2046_IRQ_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin 	=  XPT2046_CS_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(XPT2046_IRQ_GPIO_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin 	=  XPT2046_IRQ_PIN ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_IN_FLOATING;//GPIO_Mode_IPU  ;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(XPT2046_IRQ_GPIO_PORT, &GPIO_InitStructure);

	GPIO_EXTILineConfig(XPT2046_EXT_GPIO_PortSource, XPT2046_EXT_GPIO_PinSource);

	EXTI_InitStructure.EXTI_Mode 	= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Line 	= EXTI_Line11;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);


	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = XPT2046_IRQ_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = XPT2046_IRQ_PRIORITY;
	NVIC_Init(&NVIC_InitStructure);

	Set_CS();

	SPI_InitTypeDef  SPI_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

	SPI_Cmd(SPI2, DISABLE);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStructure);
	SPI_Cmd(SPI2, ENABLE);

	XPT2046_rev_tranfer_byte(0xFF);
}

uint16_t XPT2046_read_x(void)
{
	uint16_t curr_X;
	Reset_CS();
	XPT2046_delay(10);
	XPT2046_rev_tranfer_byte(CHX);
	XPT2046_delay(10);

	curr_X = XPT2046_rev_tranfer_byte(0x00);
	curr_X <<= 8;
	curr_X += XPT2046_rev_tranfer_byte(0x00);

	XPT2046_delay(10);
	Set_CS();

	curr_X = curr_X >> 3;
	return curr_X;
}

uint16_t XPT2046_read_y(void)
{
	uint16_t curr_Y;
	Reset_CS();
	XPT2046_delay(10);
	XPT2046_rev_tranfer_byte(CHY);
	XPT2046_delay(10);

	curr_Y = XPT2046_rev_tranfer_byte(0x00);
	curr_Y <<= 8;
	curr_Y += XPT2046_rev_tranfer_byte(0x00);

	XPT2046_delay(10);
	Set_CS();

	curr_Y = curr_Y >> 3;
	return curr_Y;
}

void XPT2046_read_cursor(int32_t *cur_x, int32_t *cur_y)
{
	if(XPT2046_st.status_pin != XPT2046_ENABLE) return;
	*cur_x = XPT2046_read_x();
	*cur_y = XPT2046_read_y();
	u8 count = 0;
	while(!GPIO_ReadInputDataBit(GPIOB, XPT2046_IRQ_PIN) && count <= 50)
	{
		*cur_x += XPT2046_read_x();
		*cur_x >>= 1;

		*cur_y += XPT2046_read_y();
		*cur_y >>= 1;
		XPT2046_delay(1000);
		count ++;
	}

}

void XPT2046_delay(uint32_t time)
{
	while(time--);
}

uint8_t XPT2046_rev_tranfer_byte(uint8_t byte)
{
	return SPI_SendReceiveByte(SPI2, byte);
}














