/*
 * PROCESS.c
 *
 *  Created on: Nov 25, 2020
 *      Author: fw_tien
 */

#include "PROCESS/PROCESS.h"

PROCESS_typedef SENSOR_HUB;
PACKET_typedef PACKET_RF;
PROCESS_LED_typedef LED;



void LCD0_Task(void * pvParameters);
void LCD1_Task(void * pvParameters);


void vApplicationTickHook(void)
{

}

void PROCESS_init(void)
{
//	TIMEOUT_init();
	ILI9431_init();

	LED.time_start = TIMEOUT_gettick_ms();
	LED.time_cycle = 1000;

	xTaskCreate(LCD0_Task, (const char *)"LCD0", 128, NULL, tskIDLE_PRIORITY, NULL);
	xTaskCreate(LCD1_Task, (const char *)"LCD1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);

	vTaskStartScheduler();
}

void PROCESS_led(void)
{
	static uint8_t a = 0;
    if(TIMEOUT_gettick_ms() - LED.time_start > LED.time_cycle)
    {
    	LED.time_start = TIMEOUT_gettick_ms();
    	if(a == 0)
		{
    		a = 1;
			DISPLAY_scr_fill(0, 0, 320, 240, 0x0000);
		}
    	else
    	{
    		a = 0;
    		DISPLAY_scr_fill(0, 0, 320, 240, 0x21a7);
    	}
    }
}


void PROCESS_app(void)
{
	Delay_ms(200);
	DISPLAY_scr_fill(0, 0, 320, 240, 0x0000);
	Delay_ms(200);
	DISPLAY_scr_fill(0, 0, 320, 240, 0x21a7);
}



void LCD0_Task(void * pvParameters)
{
	while (1)
	{
		PROCESS_led();
	}
}

void LCD1_Task(void * pvParameters)
{
	while (1)
	{
//		DISPLAY_scr_fill(0, 0, 320, 240, 0x21a7);
		vTaskDelay(1500/ portTICK_RATE_MS);
	}
}








