/*
 * ILI9431.c
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */


#include <PROCESS/PROCESS.h>

void ILI9431_gpio_set(void);
void ILI9431_reset(void);

void ILI9431_write_reg(uint8_t byte);
void ILI9431_write_ram_pre(void);
void ILI9431_write_data(uint16_t data);
void ILI9431_write_Reg_Data(uint8_t LCD_Reg, uint8_t LCD_RegValue);

uint16_t ILI9431_read_word(void);

void ILI9431_set_cur(uint16_t Xpos, uint16_t Ypos);
void ILI9431_set_windows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);


void ILI9431_point_color(uint16_t color);
void ILI9431_draw_point(uint16_t color);

void ILI9431_init(void);


ILI9431_infor_st ILI9431;

void ILI9431_set_gpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);

	GPIO_InitStructure.GPIO_Pin 	= LCD_GPIO_PIN_RST | LCD_GPIO_PIN_RD | LCD_GPIO_PIN_WR | LCD_GPIO_PIN_RS | LCD_GPIO_PIN_CS | LCD_GPIO_LED;	   //GPIO_Pin_10
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(LCD_GPIO_PORT_SET, &GPIO_InitStructure);

	GPIO_SetBits(LCD_GPIO_PORT_SET, LCD_GPIO_PIN_RST | LCD_GPIO_PIN_RD | LCD_GPIO_PIN_WR | LCD_GPIO_PIN_RS | LCD_GPIO_PIN_CS);

	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_All);
}

void ILI9431_reset(void)
{
	LCD_RST_CLR;
	Delay_ms(100);
	LCD_RST_SET;
	Delay_ms(50);
}

uint16_t ILI9431_read_word(void)
{
	return LCD->LCD_RAM;
}

void ILI9431_write_reg(uint8_t byte)
{
	LCD_RS_CLR;
	LCD_CS_CLR;
	DATAOUT(byte);
	LCD_WR_CLR;
	LCD_WR_SET;
	LCD_CS_SET;
}

void ILI9431_write_data(uint16_t data)
{
	LCD_RS_SET;
	LCD_CS_CLR;
	DATAOUT(data);
	LCD_WR_CLR;
	LCD_WR_SET;
	LCD_CS_SET;
}
void ILI9431_write_ram_pre(void)
{
	ILI9431_write_reg(ILI9431.wramcmd);
}

void ILI9431_write_Reg_Data(uint8_t LCD_Reg, uint8_t LCD_RegValue)
{
	ILI9431_write_reg(LCD_Reg);
	ILI9431_write_data(LCD_RegValue);
}

void ILI9431_set_cur(uint16_t Xpos, uint16_t Ypos)
{
	ILI9431_write_reg(ILI9431.setxcmd);
	ILI9431_write_data(Xpos>>8);
	ILI9431_write_data(0x00FF&Xpos);


	ILI9431_write_reg(ILI9431.setycmd);
	ILI9431_write_data(Ypos>>8);
	ILI9431_write_data(0x00FF&Ypos);

	ILI9431_write_ram_pre();
}

void ILI9431_set_windows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd)
{
	ILI9431_write_reg(ILI9431.setxcmd);
	ILI9431_write_data(xStar>>8);
	ILI9431_write_data(0x00FF&xStar);
	ILI9431_write_data(xEnd>>8);
	ILI9431_write_data(0x00FF&xEnd);

	ILI9431_write_reg(ILI9431.setycmd);
	ILI9431_write_data(yStar>>8);
	ILI9431_write_data(0x00FF&yStar);
	ILI9431_write_data(yEnd>>8);
	ILI9431_write_data(0x00FF&yEnd);

	ILI9431_write_ram_pre();	//????GRAM
}

void ILI9431_set_param(void)
{
//	USE_HORIZONTAL
	ILI9431.wramcmd	= 0x2C;
	ILI9431.dir		= 1;
	ILI9431.width	= 320;
	ILI9431.height	= 240;
	ILI9431.setxcmd	= 0x2A;
	ILI9431.setycmd	= 0x2B;
	ILI9431_write_Reg_Data(0x36,0x6C);
}

void ILI9431_point_color(uint16_t color)
{
	ILI9431_write_data(color);
}


//void ILI9431_
//void ILI9431_
//void ILI9431_


void ILI9431_init(void)
{
	ILI9431_set_gpio();
	ILI9431_reset();
	ILI9431_write_reg(0xCF);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0xC1);
	ILI9431_write_data(0X30);
	ILI9431_write_reg(0xED);
	ILI9431_write_data(0x64);
	ILI9431_write_data(0x03);
	ILI9431_write_data(0X12);
	ILI9431_write_data(0X81);
	ILI9431_write_reg(0xE8);
	ILI9431_write_data(0x85);
	ILI9431_write_data(0x10);
	ILI9431_write_data(0x7A);
	ILI9431_write_reg(0xCB);
	ILI9431_write_data(0x39);
	ILI9431_write_data(0x2C);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x34);
	ILI9431_write_data(0x02);
	ILI9431_write_reg(0xF7);
	ILI9431_write_data(0x20);
	ILI9431_write_reg(0xEA);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_reg(0xC0);    //Power control
	ILI9431_write_data(0x1B);   //VRH[5:0]
	ILI9431_write_reg(0xC1);    //Power control
	ILI9431_write_data(0x01);   //SAP[2:0];BT[3:0]
	ILI9431_write_reg(0xC5);    //VCM control
	ILI9431_write_data(0x30); 	 //3F
	ILI9431_write_data(0x30); 	 //3C
	ILI9431_write_reg(0xC7);    //VCM control2
	ILI9431_write_data(0XB7);
	ILI9431_write_reg(0x36);    // Memory Access Control
	ILI9431_write_data(0x48);
	ILI9431_write_reg(0x3A);
	ILI9431_write_data(0x55);
	ILI9431_write_reg(0xB1);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x1A);
	ILI9431_write_reg(0xB6);    // Display Function Control
	ILI9431_write_data(0x0A);
	ILI9431_write_data(0xA2);
	ILI9431_write_reg(0xF2);    // 3Gamma Function Disable
	ILI9431_write_data(0x00);
	ILI9431_write_reg(0x26);    //Gamma curve selected
	ILI9431_write_data(0x01);
	ILI9431_write_reg(0xE0);    //Set Gamma
	ILI9431_write_data(0x0F);
	ILI9431_write_data(0x2A);
	ILI9431_write_data(0x28);
	ILI9431_write_data(0x08);
	ILI9431_write_data(0x0E);
	ILI9431_write_data(0x08);
	ILI9431_write_data(0x54);
	ILI9431_write_data(0XA9);
	ILI9431_write_data(0x43);
	ILI9431_write_data(0x0A);
	ILI9431_write_data(0x0F);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_reg(0XE1);    //Set Gamma
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x15);
	ILI9431_write_data(0x17);
	ILI9431_write_data(0x07);
	ILI9431_write_data(0x11);
	ILI9431_write_data(0x06);
	ILI9431_write_data(0x2B);
	ILI9431_write_data(0x56);
	ILI9431_write_data(0x3C);
	ILI9431_write_data(0x05);
	ILI9431_write_data(0x10);
	ILI9431_write_data(0x0F);
	ILI9431_write_data(0x3F);
	ILI9431_write_data(0x3F);
	ILI9431_write_data(0x0F);
	ILI9431_write_reg(0x2B);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x01);
	ILI9431_write_data(0x3f);
	ILI9431_write_reg(0x2A);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0x00);
	ILI9431_write_data(0xef);
	ILI9431_write_reg(0x11); //Exit Sleep
	Delay_ms(120);
	ILI9431_write_reg(0x29); //display on

	ILI9431_set_param();//����LCD����
	ON_DISPLAY;//????
	DISPLAY_scr_fill(0, 0, 320, 240, 0xFFFF);
}
