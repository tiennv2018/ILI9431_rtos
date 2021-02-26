/*
 * TOUCH.h
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */

#ifndef LCD_ILI9431_TOUCH_TOUCH_H_
#define LCD_ILI9431_TOUCH_TOUCH_H_



typedef struct {
	int32_t An;
	int32_t Bn;
	int32_t Cn;
	int32_t Dn;
	int32_t En;
	int32_t Fn;
	int32_t Divider;
}MATRIX_st;


typedef struct {
	int32_t x;
	int32_t y;
	MATRIX_st matrix;
}TOUCH_cursor_st;

TOUCH_cursor_st TOUCH_st;


#endif /* LCD_ILI9431_TOUCH_TOUCH_H_ */







