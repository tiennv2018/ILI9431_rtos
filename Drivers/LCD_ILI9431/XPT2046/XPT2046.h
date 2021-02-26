/*
 * XPT2046.h
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */

#ifndef LCD_ILI9431_XPT2046_XPT2046_H_
#define LCD_ILI9431_XPT2046_XPT2046_H_

#define	CHX 	0x90
#define	CHY 	0xD0

#define XPT2046_MISO_PIN	 		GPIO_Pin_14
#define XPT2046_MOSI_PIN	  		GPIO_Pin_15
#define XPT2046_SCK_PIN		  		GPIO_Pin_13

#define XPT2046_CS_PIN		  		GPIO_Pin_10
#define XPT2046_GPIO_RCC_PORT		RCC_APB2Periph_GPIOB

#define XPT2046_IRQ_PIN		  		GPIO_Pin_11
#define XPT2046_IRQ_GPIO_PORT		GPIOB
#define XPT2046_IRQ_GPIO_RCC_PORT	RCC_APB2Periph_GPIOB

#define XPT2046_EXT_GPIO_PortSource				GPIO_PortSourceGPIOB
#define XPT2046_EXT_GPIO_PinSource				GPIO_PinSource11

#define Set_CS()      				GPIO_SetBits(GPIOB, XPT2046_CS_PIN);
#define Reset_CS() 					GPIO_ResetBits(GPIOB, XPT2046_CS_PIN);

#define XPT2046_IRQ_PRIORITY 		8

typedef enum {
	XPT2046_NONE = 0,
	XPT2046_DISABLE,
	XPT2046_ENABLE
}XPT2046_touch_en;


typedef struct {
	uint8_t status_pin;

}XPT2046_touch_st;

extern XPT2046_touch_st XPT2046_st;


extern uint16_t XPT2046_read_x(void);
extern uint16_t XPT2046_read_y(void);




#endif /* LCD_ILI9431_XPT2046_XPT2046_H_ */
