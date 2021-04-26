/*
 * 3dprinter_misc.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#include <BSP/3dprinter_drv/3dprinter_adc.h>
#include <BSP/3dprinter_drv/3dprinter_misc.h>
#include <BSP/3dprinter_drv/3dprinter_motor.h>
#include "string.h"
#include <stdio.h>


/* Private defines ----------------------------------------------------------*/
#define HEAT_TIMER_PRESCALER  (1024)
#define SERVO_TIMER_PRESCALER (8)
#define HEAT_TIMER_FREQUENCY  (1000

/*  global constant ----------------------------------------------------------*/
GPIO_TypeDef* gArrayGpioPort[BSP_MISC_MAX_PIN_NUMBER] = {
  BSP_MOTOR_CONTROL_BOARD_PWM_X_PORT,    //X_STEP_PIN       0
  BSP_MOTOR_CONTROL_BOARD_DIR_X_PORT,    //X_DIR_PIN        1
  BSP_MOTOR_CONTROL_BOARD_RESET_X_PORT,  //X_ENABLE_PIN
  BSP_STOP_X_PORT,                       //X_MIN_PIN
  0,                                     //X_MAX_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_Y_PORT,    //Y_STEP_PIN       5
  BSP_MOTOR_CONTROL_BOARD_DIR_Y_PORT,    //Y_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_Y_PORT,  //Y_ENABLE_PIN
  BSP_STOP_Y_PORT,                       //Y_MIN_PIN
  0,                                     //Y_MAX_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_Z_PORT,    //Z_STEP_PIN      10
  BSP_MOTOR_CONTROL_BOARD_DIR_Z_PORT,    //Z_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_Z_PORT,  //Z_ENABLE_PIN
  BSP_STOP_Z_PORT,                       //Z_MIN_PIN
  0,                                     //Z_MAX_PIN
  0,                                     //Y2_STEP_PIN     15
  0,                                     //Y2_DIR_PIN
  0,                                     //Y2_ENABLE_PIN
  0,                                     //Z2_STEP_PIN
  0,                                     //Z2_DIR_PIN
  0,                                     //Z2_ENABLE_PIN   20
  BSP_MOTOR_CONTROL_BOARD_PWM_E1_PORT,   //E0_STEP_PIN
  BSP_MOTOR_CONTROL_BOARD_DIR_E1_PORT,   //E0_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_E1_PORT, //E0_ENABLE_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_E2_PORT,   //E1_STEP_PIN
  BSP_MOTOR_CONTROL_BOARD_DIR_E2_PORT,   //E1_DIR_PIN      25
  BSP_MOTOR_CONTROL_BOARD_RESET_E2_PORT, //E1_ENABLE_PIN
  0,                                     //SDPOWER
  0,                                     //SDSS
  0,                                     //LED_PIN
  BSP_FAN_E1_PORT,                       //FAN_PIN         30
  0,                                     //PS_ON_PIN
  0,                                     //KILL_PIN
  BSP_HEAT_E1_PORT,                      //HEATER_0_PIN
  BSP_HEAT_E2_PORT,                      //HEATER_1_PIN
  BSP_HEAT_E3_PORT,                      //HEATER_2_PIN    35
  BSP_THERM_E1_PORT,                     //TEMP_0_PIN
  BSP_THERM_E2_PORT,                     //TEMP_1_PIN
  BSP_THERM_E3_PORT,                     //TEMP_2_PIN
  BSP_HEAT_BED1_PORT,                     //HEATER_BED_PIN
  BSP_THERM_BED1_PORT,                    //TEMP_BED_PIN    40
  BSP_SERVO0_PORT,                       //SERVO0_PIN
  0,                                     //SERVO1_PIN
  0,                                     //SERVO2_PIN
  0,                                     //SERVO3_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_E3_PORT,   //E2_STEP_PIN     45
  BSP_MOTOR_CONTROL_BOARD_DIR_E3_PORT,   //E2_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_E3_PORT,  //E2_ENABLE_PIN
  BSP_STOP_U_PORT,                        //U_MIN_PIN
  BSP_STOP_V_PORT,                        //V_MIN_PIN
  BSP_STOP_W_PORT,                         //W_MIN_PIN   50
  BSP_HEAT_BED2_PORT,                     //HEATER_BED2_PIN
  BSP_HEAT_BED3_PORT                      //HEATER_BED3_PIN
};

uint16_t gArrayGpioPin[BSP_MISC_MAX_PIN_NUMBER] = {
  BSP_MOTOR_CONTROL_BOARD_PWM_X_PIN,    //X_STEP_PIN        0
  BSP_MOTOR_CONTROL_BOARD_DIR_X_PIN,    //X_DIR_PIN         1
  BSP_MOTOR_CONTROL_BOARD_RESET_X_PIN,  //X_ENABLE_PIN
  BSP_STOP_X_PIN,                       //X_MIN_PIN
  0,                                    //X_MAX_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_Y_PIN,    //Y_STEP_PIN        5
  BSP_MOTOR_CONTROL_BOARD_DIR_Y_PIN,    //Y_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_Y_PIN,  //Y_ENABLE_PIN
  BSP_STOP_Y_PIN,                       //Y_MIN_PIN
  0,                                    //Y_MAX_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_Z_PIN,    //Z_STEP_PIN       10
  BSP_MOTOR_CONTROL_BOARD_DIR_Z_PIN,    //Z_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_Z_PIN,  //Z_ENABLE_PIN
  BSP_STOP_Z_PIN,                       //Z_MIN_PIN
  0,                                    //Z_MAX_PIN
  0,                                    //Y2_STEP_PIN      15
  0,                                    //Y2_DIR_PIN
  0,                                    //Y2_ENABLE_PIN
  0,                                    //Z2_STEP_PIN
  0,                                    //Z2_DIR_PIN
  0,                                    //Z2_ENABLE_PIN    20
  BSP_MOTOR_CONTROL_BOARD_PWM_E1_PIN,   //E0_STEP_PIN
  BSP_MOTOR_CONTROL_BOARD_DIR_E1_PIN,   //E0_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_E1_PIN, //E0_ENABLE_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_E2_PIN,   //E1_STEP_PIN
  BSP_MOTOR_CONTROL_BOARD_DIR_E2_PIN,   //E1_DIR_PIN       25
  BSP_MOTOR_CONTROL_BOARD_RESET_E2_PIN, //E1_ENABLE_PIN
  0,                                    //SDPOWER
  0,                                    //SDSS
  0,                                    //LED_PIN
  BSP_FAN_E1_PIN,                       //FAN_PIN          30
  0,                                    //PS_ON_PIN
  0,                                    //KILL_PIN
  BSP_HEAT_E1_PIN,                      //HEATER_0_PIN
  BSP_HEAT_E2_PIN,                      //HEATER_1_PIN
  BSP_HEAT_E3_PIN,                      //HEATER_2_PIN     35
  BSP_THERM_E1_PIN,                     //TEMP_0_PIN
  BSP_THERM_E2_PIN,                     //TEMP_1_PIN
  BSP_THERM_E3_PIN,                     //TEMP_2_PIN
  BSP_HEAT_BED1_PIN,                     //HEATER_BED_PIN
  BSP_THERM_BED1_PIN,                    //TEMP_BED_PIN     40
  BSP_SERVO0_PIN,                       //SERVO0_PIN
  0,                                    //SERVO1_PIN
  0,                                    //SERVO2_PIN
  0,                                    //SERVO3_PIN
  BSP_MOTOR_CONTROL_BOARD_PWM_E3_PIN,   //E2_STEP_PIN      45
  BSP_MOTOR_CONTROL_BOARD_DIR_E3_PIN,   //E2_DIR_PIN
  BSP_MOTOR_CONTROL_BOARD_RESET_E3_PIN, //E2_ENABLE_PIN
  BSP_STOP_U_PIN,                       //U_MIN_PIN
  BSP_STOP_V_PIN,                       //V_MIN_PIN
  BSP_STOP_W_PIN,                        //W_MIN_PIN     50
  BSP_HEAT_BED2_PIN,                     //HEATER_BED2_PIN
  BSP_HEAT_BED3_PIN                      //HEATER_BED3_PIN
};

/* Type definition ------------------------------------------------------------*/
typedef struct {
	 uint32_t 		gpioPin;
	 GPIO_TypeDef* 	gpioPort;
	 uint8_t		speed;
	 uint8_t		up_val;
	 uint8_t		count;
	 uint8_t		level; /* Up = 1 ; down = 0 */
	 uint8_t		activePwm;
} tFanStruct;


/* Global variable ------------------------------------------------------------*/
static tFanStruct fanE1;
static tFanStruct fanE2;
static tFanStruct fanE3;





