/*
 * DISPLAY.c
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */
#include <PROCESS/PROCESS.h>


void DISPLAY_point_color(uint16_t color);
void DISPLAY_scr_fill(uint16_t sx,uint16_t sy, uint16_t ex,uint16_t ey,uint16_t color);


void DISPLAY_point_color(uint16_t color)
{
	ILI9431_write_data(color);
}

void DISPLAY_scr_fill(uint16_t sx,uint16_t sy, uint16_t ex,uint16_t ey,uint16_t color)
{
	uint32_t i;
	uint16_t width=ex-sx+1;
	uint16_t height=ey-sy+1;
	ILI9431_set_windows(sx,sy,ex-1,ey-1);
	i = height*width;
	while(i--)
	{
		DISPLAY_point_color(color);
	}
}

