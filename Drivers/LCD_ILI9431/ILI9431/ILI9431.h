/*
 * ILI9431.h
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */

#ifndef LCD_ILI9431_ILI9431_H_
#define LCD_ILI9431_ILI9431_H_

#define LCD_GPIO_PIN_CS			GPIO_Pin_7
#define LCD_GPIO_PIN_RS			GPIO_Pin_6
#define LCD_GPIO_PIN_WR			GPIO_Pin_5
#define LCD_GPIO_PIN_RD			GPIO_Pin_4
#define LCD_GPIO_PIN_RST		GPIO_Pin_3
#define LCD_GPIO_LED			GPIO_Pin_12

#define OFF_DISPLAY				GPIOB->BRR = 0x1000;//GPIO_ResetBits(,LCD_GPIO_LED)
#define ON_DISPLAY				GPIOB->BSRR = 0x1000;//GPIO_SetBits(LCD_GPIO_PORT_SET,LCD_GPIO_LED)

#define LCD_GPIO_PORT_SET		GPIOB //GPIOB
#define LCD_GPIO_PORT_DATA		GPIOD

#define	LCD_LED 				GPIOB->BSRR = 0x1000;//GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_LED); 				 //LCD  PB12
#define	LCD_CS_SET  			GPIOB->BSRR = 0x0080;//GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_CS);    	 //  	PB7
#define	LCD_RS_SET				GPIOB->BSRR = 0x0040;//GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RS);    	 //  PB6
#define	LCD_WR_SET				GPIOB->BSRR = 0x0020;//GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_WR);      //		PB5
#define	LCD_RD_SET				GPIOB->BSRR = 0x0010;//GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RD);      //		PB4
#define	LCD_RST_SET				GPIOB->BSRR = 0x0008;//GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RST);     //			PB3

#define	LCD_CS_CLR  			GPIOB->BRR = 0x0080;//GPIO_ResetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_CS);     //  	PB7
#define	LCD_RS_CLR				GPIOB->BRR = 0x0040;//GPIO_ResetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RS);     ///  	PB6
#define	LCD_WR_CLR				GPIOB->BRR = 0x0020;//GPIO_ResetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_WR);     //		PB5
#define	LCD_RD_CLR				GPIOB->BRR = 0x0010;//GPIO_ResetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RD);     //		PB4
#define	LCD_RST_CLR				GPIOB->BRR = 0x0008;//GPIO_ResetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RST);    //			PB3

#define DATAOUT(x) 				GPIOD->ODR=x; //Set Port Data out Port D Sout DATA into
#define DATAIN     				GPIOD->IDR;   //

typedef struct
{
	uint16_t 	width;			//LCD
	uint16_t 	height;			//LCD
	uint16_t 	id;				//LCD ID
	uint8_t  	dir;			//:0,;1,
	uint16_t	wramcmd;		//gram
	uint16_t  	setxcmd;		//x
	uint16_t  	setycmd;		//y
}ILI9431_infor_st;

extern ILI9431_infor_st ILI9431;

typedef struct
{
	u16 LCD_REG;
	u16 LCD_RAM;
} LCD_TypeDef;


#define LCD_BASE        ((u32)(0x6C000000 | 0x000007FE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

extern void ILI9431_init(void);

extern void ILI9431_write_data(uint16_t data);
extern void ILI9431_set_windows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);

#endif /* LCD_ILI9431_ILI9431_H_ */
