/*
 * GPIO.h
 *
 *  Created on: Sep 23, 2019
 *      Author: On-HP
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

/************************* LED STATUS ***********************/
#define GPIO_LED_PORT                               GPIOB
#define GPIO_LED_STATUS_1                           GPIO_Pin_1
#define GPIO_LED_STATUS_2                           GPIO_Pin_0

#define GPIO_LED_ON                                 1
#define GPIO_LED_OFF                                2
#define GPIO_LED_TOGGLE                             3
/*************************** UART **************************/
#define GPIO_UART1_PORT                             GPIOA
#define GPIO_UART1_TX                               GPIO_Pin_9
#define GPIO_UART1_RX                               GPIO_Pin_10

#define GPIO_UART3_PORT                             GPIOB
#define GPIO_UART3_TX                               GPIO_Pin_10
#define GPIO_UART3_RX                               GPIO_Pin_11
/************************* BUTTON **************************/
#define GPIO_BUTTON_PORT                            GPIOB
#define GPIO_BUTTON_PIN                             GPIO_Pin_5
/********************* RS485 ENABLE ************************/
#define GPIO_ENABLE_PORT                            GPIOA
#define GPIO_ENABLE_PIN                             GPIO_Pin_11

#define GPIO_ENABLE_ACTIVE                          4
#define GPIO_ENABLE_INACTIVE                        5
/************************* SERIAL **************************/
#define GPIO_SERIAL_SCLK_PORT                       GPIOA
#define GPIO_SERIAL_SCLK                            GPIO_Pin_12

#define GPIO_SERIAL_MISO_PORT                       GPIOA
#define GPIO_SERIAL_MISO_1                          GPIO_Pin_0
#define GPIO_SERIAL_MISO_2                          GPIO_Pin_1
#define GPIO_SERIAL_MISO_3                          GPIO_Pin_2
#define GPIO_SERIAL_MISO_4                          GPIO_Pin_3
#define GPIO_SERIAL_MISO_5                          GPIO_Pin_4
#define GPIO_SERIAL_MISO_6                          GPIO_Pin_5
#define GPIO_SERIAL_MISO_7                          GPIO_Pin_6
#define GPIO_SERIAL_MISO_8                          GPIO_Pin_7
#define GPIO_SERIAL_MISO_ALL                        (uint16_t)0x00FF

#define GPIO_SERIAL_MOSI_PORT                       GPIOB
#define GPIO_SERIAL_MOSI_1                          GPIO_Pin_9
#define GPIO_SERIAL_MOSI_2                          GPIO_Pin_8
#define GPIO_SERIAL_MOSI_3                          GPIO_Pin_7
#define GPIO_SERIAL_MOSI_4                          GPIO_Pin_6
#define GPIO_SERIAL_MOSI_5                          GPIO_Pin_15
#define GPIO_SERIAL_MOSI_6                          GPIO_Pin_14
#define GPIO_SERIAL_MOSI_7                          GPIO_Pin_13
#define GPIO_SERIAL_MOSI_8                          GPIO_Pin_12
#define GPIO_SERIAL_MOSI_ALL                        (uint16_t)0xF3C0

void GPIO_init(void);
void GPIO_set(uint16_t pin, uint8_t state);

#endif /* GPIO_GPIO_H_ */
