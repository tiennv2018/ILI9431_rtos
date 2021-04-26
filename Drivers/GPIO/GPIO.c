/*
 * GPIO.c
 *
 *  Created on: Nov 25, 2020
 *      Author: fw_tien
 */

#include <PROCESS/PROCESS.h>

//GPIO_InitTypeDef GPIO_InitStructure;

void GPIO_init(void)
{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//
//    /*************************** MODE OUTPP ************************************/
//    GPIO_InitStructure.GPIO_Pin = GPIO_LED_STATUS_1 | GPIO_LED_STATUS_2;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_Init(GPIO_LED_PORT, &GPIO_InitStructure);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_ENABLE_PIN;
//    GPIO_Init(GPIO_ENABLE_PORT, &GPIO_InitStructure);
//    GPIO_ResetBits(GPIO_ENABLE_PORT, GPIO_ENABLE_PIN);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_SERIAL_SCLK;
//    GPIO_Init(GPIO_SERIAL_SCLK_PORT, &GPIO_InitStructure);
//    GPIO_SetBits(GPIO_SERIAL_SCLK_PORT, GPIO_SERIAL_SCLK);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_SERIAL_MOSI_ALL;
//    GPIO_Init(GPIO_SERIAL_MOSI_PORT, &GPIO_InitStructure);
//    GPIO_SetBits(GPIO_SERIAL_MOSI_PORT, GPIO_SERIAL_MOSI_ALL);
//    /************************* MODE IN-FLOATING ********************************/
//    GPIO_InitStructure.GPIO_Pin = GPIO_SERIAL_MISO_ALL;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_Init(GPIO_SERIAL_MISO_PORT, &GPIO_InitStructure);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_BUTTON_PIN;
//    GPIO_Init(GPIO_BUTTON_PORT, &GPIO_InitStructure);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_UART1_RX;
//    GPIO_Init(GPIO_UART1_PORT, &GPIO_InitStructure);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_UART3_RX;
//    GPIO_Init(GPIO_UART3_PORT, &GPIO_InitStructure);
//    /**************************** MODE AF-PP ***********************************/
//    GPIO_InitStructure.GPIO_Pin = GPIO_UART1_TX;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIO_UART1_PORT, &GPIO_InitStructure);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_UART3_TX;
//    GPIO_Init(GPIO_UART3_PORT, &GPIO_InitStructure);
}

void GPIO_set(uint16_t pin, uint8_t state)
{

}


