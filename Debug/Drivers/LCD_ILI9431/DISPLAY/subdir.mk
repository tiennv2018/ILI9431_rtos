################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/LCD_ILI9431/DISPLAY/DISPLAY.c 

OBJS += \
./Drivers/LCD_ILI9431/DISPLAY/DISPLAY.o 

C_DEPS += \
./Drivers/LCD_ILI9431/DISPLAY/DISPLAY.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/LCD_ILI9431/DISPLAY/DISPLAY.o: ../Drivers/LCD_ILI9431/DISPLAY/DISPLAY.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/LCD_ILI9431/DISPLAY/DISPLAY.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

