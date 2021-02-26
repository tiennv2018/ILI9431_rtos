/*
 * TOUCH.c
 *
 *  Created on: Feb 19, 2021
 *      Author: snk-tien
 */

#include <PROCESS/PROCESS.h>



uint8_t TOUCH_calibration_Matrix(TOUCH_cursor_st *lcdPtr, TOUCH_cursor_st *touchPtr, MATRIX_st *matrixPtr)
{
	matrixPtr->Divider = ((touchPtr[0].x - touchPtr[2].x) * (touchPtr[1].y - touchPtr[2].y)) -
						 ((touchPtr[1].x - touchPtr[2].x) * (touchPtr[0].y - touchPtr[2].y)) ;
	if( matrixPtr->Divider == 0 )
		return 0;
	matrixPtr->An = ((lcdPtr[0].x - lcdPtr[2].x) * (touchPtr[1].y - touchPtr[2].y)) -
					((lcdPtr[1].x - lcdPtr[2].x) * (touchPtr[0].y - touchPtr[2].y)) ;

	matrixPtr->Bn = ((touchPtr[0].x - touchPtr[2].x) * (lcdPtr[1].x - lcdPtr[2].x)) -
					((lcdPtr[0].x - lcdPtr[2].x) * (touchPtr[1].x - touchPtr[2].x)) ;

	matrixPtr->Cn = (touchPtr[2].x * lcdPtr[1].x - touchPtr[1].x * lcdPtr[2].x) * touchPtr[0].y +
					(touchPtr[0].x * lcdPtr[2].x - touchPtr[2].x * lcdPtr[0].x) * touchPtr[1].y +
					(touchPtr[1].x * lcdPtr[0].x - touchPtr[0].x * lcdPtr[1].x) * touchPtr[2].y ;

	matrixPtr->Dn = ((lcdPtr[0].y - lcdPtr[2].y) * (touchPtr[1].y - touchPtr[2].y)) -
									((lcdPtr[1].y - lcdPtr[2].y) * (touchPtr[0].y - touchPtr[2].y)) ;

	matrixPtr->En = ((touchPtr[0].x - touchPtr[2].x) * (lcdPtr[1].y - lcdPtr[2].y)) -
					((lcdPtr[0].y - lcdPtr[2].y) * (touchPtr[1].x - touchPtr[2].x)) ;


	matrixPtr->Fn = (touchPtr[2].x * lcdPtr[1].y - touchPtr[1].x * lcdPtr[2].y) * touchPtr[0].y +
					(touchPtr[0].x * lcdPtr[2].y - touchPtr[2].x * lcdPtr[0].y) * touchPtr[1].y +
					(touchPtr[1].x * lcdPtr[0].y - touchPtr[0].x * lcdPtr[1].y) * touchPtr[2].y ;
	return 1;
}

uint8_t TOUCH_mode_calib(void)
{
//	TOUCH_cursor_st screenSample[3];
//	TOUCH_cursor_st displaySample[3] = {{20,120},
//								   {160,220},
//								   {300,70}};
//	LCD_Fill(0,0,320,240,0x000);
//	setFont(Rcalibri8pt7b);
	return 0;
}

void TOUCH_get_point(void)
{
	XPT2046_read_x();
}
