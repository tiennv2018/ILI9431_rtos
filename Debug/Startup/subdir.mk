################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f10x_md.s 

OBJS += \
./Startup/startup_stm32f10x_md.o 

S_DEPS += \
./Startup/startup_stm32f10x_md.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f10x_md.o: ../Startup/startup_stm32f10x_md.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DGCC_ARMCM3 -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS/Source -I../Drivers -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f10x_md.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

