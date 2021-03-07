/*
 * 3dprinter_misc.h
 *
 *  Created on: Feb 27, 2021
 *      Author: snk-tien
 */

#ifndef BSP_3DPRINTER_DRV_3DPRINTER_MISC_HPP_
#define BSP_3DPRINTER_DRV_3DPRINTER_MISC_HPP_


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"

/* Exported macros ------------------------------------------------------------*/

/* Definition for IR ON Pin used for Z probing*/
#define BSP_IR_ON_PIN               (GPIO_PIN_1)
#define BSP_IR_ON_PORT              (GPIOC)

/* Definition for Stops */
#define BSP_STOP_X_PIN               (GPIO_PIN_8)
#define BSP_STOP_X_PORT              (GPIOD)
#define BSP_STOP_Y_PIN               (GPIO_PIN_9)
#define BSP_STOP_Y_PORT              (GPIOD)
#define BSP_STOP_Z_PIN               (GPIO_PIN_10)
#define BSP_STOP_Z_PORT              (GPIOD)
#define BSP_STOP_U_PIN               (GPIO_PIN_11)
#define BSP_STOP_U_PORT              (GPIOD)
#define BSP_STOP_V_PIN               (GPIO_PIN_8)
#define BSP_STOP_V_PORT              (GPIOA)
#define BSP_STOP_W_PIN               (GPIO_PIN_0)
#define BSP_STOP_W_PORT              (GPIOD)

/* Definition for Heats*/
#define BSP_HEAT_BED1_PIN              (GPIO_PIN_14)
#define BSP_HEAT_BED1_PORT             (GPIOD)
#define BSP_HEAT_BED2_PIN             (GPIO_PIN_13)
#define BSP_HEAT_BED2_PORT            (GPIOD)
#define BSP_HEAT_BED3_PIN             (GPIO_PIN_15)
#define BSP_HEAT_BED3_PORT            (GPIOD)
#define BSP_HEAT_E1_PIN               (GPIO_PIN_7)
#define BSP_HEAT_E1_PORT              (GPIOC)
#define BSP_HEAT_E2_PIN               (GPIO_PIN_0)
#define BSP_HEAT_E2_PORT              (GPIOB)
#define BSP_HEAT_E3_PIN               (GPIO_PIN_1)
#define BSP_HEAT_E3_PORT              (GPIOB)

/* Definition for FAN 0*/
#define BSP_FAN_E1_PIN              (GPIO_PIN_4)
#define BSP_FAN_E1_PORT             (GPIOC)
#define BSP_FAN_E2_PIN              (GPIO_PIN_5)
#define BSP_FAN_E2_PORT             (GPIOC)
#define BSP_FAN_E3_PIN              (GPIO_PIN_8)
#define BSP_FAN_E3_PORT             (GPIOE)


/* Definition for Servo 0*/
#define BSP_SERVO0_PIN               (GPIO_PIN_9)
#define BSP_SERVO0_PORT              (GPIOB)

/* Definition for Tick timer */
/// Timer used for Tick
#define BSP_MISC_TIMER_TICK                  (TIM5)
/// Channel Timer used for Tick
#define BSP_MISC_CHAN_TIMER_TICK              (TIM_CHANNEL_1)
/// HAL Active Channel Timer used for Tick
#define BSP_MISC_HAL_ACT_CHAN_TIMER_TICK      (HAL_TIM_ACTIVE_CHANNEL_1)
/// Timer Clock Enable for Tick
#define __BSP_MISC_TIMER_TICK_CLCK_ENABLE()   __TIM5_CLK_ENABLE()
/// Timer Clock Disable for Tick
#define __BSP_MISC_TIMER_TICK_CLCK_DISABLE()  __TIM5_CLK_DISABLE()

/// TICK global interrupt
#define BSP_MISC_TICK_IRQn                    (TIM5_IRQn)

/* Definition for Tick2 timer  (Marlin Only)*/
/// Timer used for Tick2
#define BSP_MISC_TIMER_TICK2                  (TIM11)
/// Channel Timer used for Tick
#define BSP_MISC_CHAN_TIMER_TICK2              (TIM_CHANNEL_1)
/// HAL Active Channel Timer used for Tick
#define BSP_MISC_HAL_ACT_CHAN_TIMER_TICK2      (HAL_TIM_ACTIVE_CHANNEL_1)
/// Timer Clock Enable for Tick
#define __BSP_MISC_TIMER_TICK2_CLCK_ENABLE()   __TIM11_CLK_ENABLE()
/// Timer Clock Disable for Tick
#define __BSP_MISC_TIMER_TICK2_CLCK_DISABLE()  __TIM11_CLK_DISABLE()

/// TICK global interrupt
#define BSP_MISC_TICK2_IRQn                    (TIM1_TRG_COM_TIM11_IRQn)

 /// Timer used for PWM_HEAT_BED
#define BSP_MISC_TIMER_PWM_HEAT_BED                  (TIM4)
/// Channel Timer used for PWM_HEAT_BED
#define BSP_MISC_CHAN_TIMER_PWM_HEAT_BED                  (TIM_CHANNEL_3)
/// HAL Active Channel Timer used for PWM_HEAT_BED
#define BSP_MISC_HAL_ACT_CHAN_TIMER_PWM_HEAT_BED     (HAL_TIM_ACTIVE_CHANNEL_3)
/// Timer Clock Enable for PWM_HEAT_BED
#define __BSP_MISC_TIMER_PWM_HEAT_BED_CLCK_ENABLE()  __TIM4_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_BED
#define __BSP_MISC_TIMER_PWM_HEAT_BED_CLCK_DISABLE() __TIM4_CLK_DISABLE()
/// PWM_HEAT_BED GPIO alternate function
#define BSP_MISC_AFx_TIMx_PWM_HEAT_BED               (GPIO_AF2_TIM4)

/// Timer used for PWM_HEAT_BED2
#define BSP_MISC_TIMER_PWM_HEAT_BED2                  (TIM4)
/// Channel Timer used for PWM_HEAT_BED2
#define BSP_MISC_CHAN_TIMER_PWM_HEAT_BED2                  (TIM_CHANNEL_2)
/// HAL Active Channel Timer used for PWM_HEAT_BED2
#define BSP_MISC_HAL_ACT_CHAN_TIMER_PWM_HEAT_BED2     (HAL_TIM_ACTIVE_CHANNEL_2)
/// Timer Clock Enable for PWM_HEAT_BED2
#define __BSP_MISC_TIMER_PWM_HEAT_BED2_CLCK_ENABLE()  __TIM4_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_BED2
#define __BSP_MISC_TIMER_PWM_HEAT_BED2_CLCK_DISABLE() __TIM4_CLK_DISABLE()
/// PWM_HEAT_BED2 GPIO alternate function
#define BSP_MISC_AFx_TIMx_PWM_HEAT_BED2               (GPIO_AF2_TIM4)

/// Timer used for PWM_HEAT_BED3
#define BSP_MISC_TIMER_PWM_HEAT_BED3                  (TIM4)
/// Channel Timer used for PWM_HEAT_BED3
#define BSP_MISC_CHAN_TIMER_PWM_HEAT_BED3                  (TIM_CHANNEL_4)
/// HAL Active Channel Timer used for PWM_HEAT_BED3
#define BSP_MISC_HAL_ACT_CHAN_TIMER_PWM_HEAT_BED3     (HAL_TIM_ACTIVE_CHANNEL_4)
/// Timer Clock Enable for PWM_HEAT_BED3
#define __BSP_MISC_TIMER_PWM_HEAT_BED3_CLCK_ENABLE()  __TIM4_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_BED3
#define __BSP_MISC_TIMER_PWM_HEAT_BED3_CLCK_DISABLE() __TIM4_CLK_DISABLE()
/// PWM_HEAT_BED3 GPIO alternate function
#define BSP_MISC_AFx_TIMx_PWM_HEAT_BED3               (GPIO_AF2_TIM4)

/// Timer used for PWM_HEAT_E1
#define BSP_MISC_TIMER_PWM_HEAT_E1                  (TIM3)
/// Channel Timer used for PWM_HEAT_E1
#define BSP_MISC_CHAN_TIMER_PWM_HEAT_E1                  (TIM_CHANNEL_2)
/// HAL Active Channel Timer used for PWM_HEAT_E1
#define BSP_MISC_HAL_ACT_CHAN_TIMER_PWM_HEAT_E1     (HAL_TIM_ACTIVE_CHANNEL_2)
/// Timer Clock Enable for PWM_HEAT_E1
#define __BSP_MISC_TIMER_PWM_HEAT_E1_CLCK_ENABLE()  __TIM3_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_E1
#define __BSP_MISC_TIMER_PWM_HEAT_E1_CLCK_DISABLE() __TIM3_CLK_DISABLE()
/// PWM_HEAT_E1 GPIO alternate function
#define BSP_MISC_AFx_TIMx_PWM_HEAT_E1               (GPIO_AF2_TIM3)

/// Timer used for PWM_HEAT_E2
#define BSP_MISC_TIMER_PWM_HEAT_E2                  (TIM3)
/// Channel Timer used for PWM_HEAT_E2
#define BSP_MISC_CHAN_TIMER_PWM_HEAT_E2                  (TIM_CHANNEL_3)
/// HAL Active Channel Timer used for PWM_HEAT_E2
#define BSP_MISC_HAL_ACT_CHAN_TIMER_PWM_HEAT_E2     (HAL_TIM_ACTIVE_CHANNEL_3)
/// Timer Clock Enable for PWM_HEAT_E2
#define __BSP_MISC_TIMER_PWM_HEAT_E2_CLCK_ENABLE()  __TIM3_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_E2
#define __BSP_MISC_TIMER_PWM_HEAT_E2_CLCK_DISABLE() __TIM3_CLK_DISABLE()
/// PWM_HEAT_E2 GPIO alternate function
#define BSP_MISC_AFx_TIMx_PWM_HEAT_E2               (GPIO_AF2_TIM3)

/// Timer used for PWM_HEAT_E3
#define BSP_MISC_TIMER_PWM_HEAT_E3                  (TIM3)
/// Channel Timer used for PWM_HEAT_E3
#define BSP_MISC_CHAN_TIMER_PWM_HEAT_E3                  (TIM_CHANNEL_4)
/// HAL Active Channel Timer used for PWM_HEAT_E3
#define BSP_MISC_HAL_ACT_CHAN_TIMER_PWM_HEAT_E3     (HAL_TIM_ACTIVE_CHANNEL_4)
/// Timer Clock Enable for PWM_HEAT_E3
#define __BSP_MISC_TIMER_PWM_HEAT_E3_CLCK_ENABLE()  __TIM3_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_E3
#define __BSP_MISC_TIMER_PWM_HEAT_E3_CLCK_DISABLE() __TIM3_CLK_DISABLE()
/// PWM_HEAT_E3 GPIO alternate function
#define BSP_MISC_AFx_TIMx_PWM_HEAT_E3               (GPIO_AF2_TIM3)

/// Timer used for Servo (marlin only)
#define BSP_MISC_TIMER_SERVO                      (TIM10)
/// Channel Timer used for PWM_HEAT_E4
#define BSP_MISC_CHAN_TIMER_SERVO                 (TIM_CHANNEL_1)
/// HAL Active Channel Timer used for PWM_HEAT_E4
#define BSP_MISC_HAL_ACT_CHAN_TIMER_SERVO         (HAL_TIM_ACTIVE_CHANNEL_1)
/// Timer Clock Enable for PWM_HEAT_E4
#define __BSP_MISC_TIMER_SERVO_CLCK_ENABLE()       __TIM10_CLK_ENABLE()
/// Timer Clock Disable for PWM_HEAT_E4
#define __BSP_MISC_TIMER_SERVO_CLCK_DISABLE()     __TIM10_CLK_DISABLE()
/// PWM_HEAT_E4 GPIO alternate function
#define BSP_MISC_AFx_TIMx_SERVO                    (GPIO_AF3_TIM10)
   /// SERVO global interrupt
#define BSP_MISC_SERVO_IRQn                    (TIM1_UP_TIM10_IRQn)

/// User SPI (in example for LCD)
#define SPI_USER                             (SPI2)
/// SPI clock enable
#define SPI_USER_CLK_ENABLE()                __SPI2_CLK_ENABLE()
/// SPI SCK enable
#define SPI_USER_SCK_GPIO_CLK_ENABLE()       __GPIOB_CLK_ENABLE()
/// SPI MISO enable
#define SPI_USER_MISO_GPIO_CLK_ENABLE()      __GPIOB_CLK_ENABLE()
/// SPI MOSI enable
#define SPI_USER_MOSI_GPIO_CLK_ENABLE()      __GPIOB_CLK_ENABLE()
/// SPI Force reset
#define SPI_USER_FORCE_RESET()               __SPI2_FORCE_RESET()
/// SPI Release reset
#define SPI_USER_RELEASE_RESET()             __SPI2_RELEASE_RESET()
/// SPI SCK pin
#define SPI_USER_NSS_PIN                     (GPIO_PIN_12)
/// SPI SCK port
#define SPI_USER_NSS_GPIO_PORT               (GPIOB)
/// SPI SCK Pin
#define SPI_USER_SCK_PIN                     (GPIO_PIN_13)
/// SPI SCK port
#define SPI_USER_SCK_GPIO_PORT               (GPIOB)
/// SPI MISO pin
#define SPI_USER_MISO_PIN                    (GPIO_PIN_14)
/// SPI MISO port
#define SPI_USER_MISO_GPIO_PORT              (GPIOB)
/// SPI MOSI pin
#define SPI_USER_MOSI_PIN                    (GPIO_PIN_15)
/// SPI MOSI port
#define SPI_USER_MOSI_GPIO_PORT              (GPIOB)
/// SPI_SCK alternate function
#define SPI_USER_SCK_AF                      (GPIO_AF5_SPI2)
/// SPI MISO AF
#define SPI_USER_MISO_AF                     (SPI_USER_SCK_AF)
/// SPI MOSI AF
#define SPI_USER_MOSI_AF                     (SPI_USER_SCK_AF)

/// User GPIOs
#define BSP_USER_1_PIN                       (GPIO_PIN_9)
#define BSP_USER_1_PORT                      (GPIOB)
#define BSP_USER_2_PIN                       (GPIO_PIN_0)
#define BSP_USER_2_PORT                      (GPIOE)
#define BSP_USER_3_PIN                       (GPIO_PIN_7)
#define BSP_USER_3_PORT                      (GPIOD)
#define BSP_USER_4_PIN                       (GPIO_PIN_4)
#define BSP_USER_4_PORT                      (GPIOB)

/// User I2C (in example for LCD)
#define BSP_MISC_I2C                         (I2C1)
#define __BSP_MISC_I2C_CLK_ENABLE()          __I2C1_CLK_ENABLE()
#define __BSP_MISC_I2C_CLK_DISABLE()         __I2C1_CLK_DISABLE()
#define __BSP_MISC_I2C_FORCE_RESET()         __I2C1_FORCE_RESET()
#define __BSP_MISC_I2C_RELEASE_RESET()       __I2C1_RELEASE_RESET()
#define __BSP_MISC_I2C_SCL_GPIO_CLK_ENABLE() __GPIOB_CLK_ENABLE()
#define __BSP_MISC_I2C_SDA_GPIO_CLK_ENABLE() __GPIOB_CLK_ENABLE()
#define BSP_MISC_I2C_SCL_PIN                 (GPIO_PIN_6)
#define BSP_MISC_I2C_SCL_PORT                (GPIOB)
#define BSP_MISC_I2C_SDA_PIN                 (GPIO_PIN_7)
#define BSP_MISC_I2C_SDA_PORT                (GPIOB)
#define BSP_MISC_AFx_I2C                     //(GPIO_AF4_I2C1)
#define BSP_MISC_I2C_CLOCK_SPEED             (100000)

#define BSP_MISC_MAX_PIN_NUMBER (53)

//Tick timer prescaler
#define TICK_TIMER_PRESCALER  (32)

/* Exported constants --------------------------------------------------------*/
extern GPIO_TypeDef* gArrayGpioPort[BSP_MISC_MAX_PIN_NUMBER];
extern uint16_t gArrayGpioPin[BSP_MISC_MAX_PIN_NUMBER];
/* Extern function -----------------------------------------------------------*/
/* Extern function -----------------------------------------------------------*/

void BSP_MiscOverallInit(uint8_t nbDevices);
void BSP_MiscErrorHandler(uint16_t error);
void BSP_MiscInitZProbeInit(void);
void BSP_MiscInitZProbeEnable(uint8_t enable);

void BSP_MiscStopInit(uint8_t id);
uint8_t BSP_MiscStopGetStatus(uint8_t id);
void BSP_MiscFanInit(uint8_t id);
void BSP_MiscFanSetSpeed(uint8_t id,uint8_t speed);
void BSP_MiscTickInit(void);
void BSP_MiscTickSetFreq(uint32_t newFreq);
void BSP_MiscTickSetPeriod(uint32_t newTimPeriod);
void BSP_MiscTickStop(void);
void BSP_MiscTick2Init(void);
void BSP_MiscTick2SetFreq(float newPeriod);
void BSP_MiscTick2Stop(void);
void BSP_MiscSetStepClockToSwMode(void);
void BSP_MiscGenerateStepClockPulse(uint8_t deviceId);
void BSP_MiscSetOcdThreshold(uint8_t deviceId, uint32_t current);
void BSP_MiscHeatManualInit(uint8_t heatId);
void BSP_MiscHeatPwmInit(uint8_t heatId);
void BSP_MiscHeatPwmSetDutyCycle(uint8_t heatId, uint8_t newDuty);
void  BSP_MotorControlBoard_ServoInit(void);
void  BSP_MotorControlBoard_ServoSetTimerValue(uint32_t value);
void  BSP_MotorControlBoard_ServoStop(void);
void BSP_MiscUserGpioInit(uint8_t id, uint32_t mode, uint32_t pull);


#ifdef __cplusplus
}
#endif

#endif /* BSP_3DPRINTER_DRV_3DPRINTER_MISC_HPP_ */
