################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/croutine.c \
../FreeRTOS/Source/event_groups.c \
../FreeRTOS/Source/list.c \
../FreeRTOS/Source/queue.c \
../FreeRTOS/Source/tasks.c \
../FreeRTOS/Source/timers.c 

OBJS += \
./FreeRTOS/Source/croutine.o \
./FreeRTOS/Source/event_groups.o \
./FreeRTOS/Source/list.o \
./FreeRTOS/Source/queue.o \
./FreeRTOS/Source/tasks.o \
./FreeRTOS/Source/timers.o 

C_DEPS += \
./FreeRTOS/Source/croutine.d \
./FreeRTOS/Source/event_groups.d \
./FreeRTOS/Source/list.d \
./FreeRTOS/Source/queue.d \
./FreeRTOS/Source/tasks.d \
./FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/croutine.o: ../FreeRTOS/Source/croutine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/Source/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/Source/event_groups.o: ../FreeRTOS/Source/event_groups.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/Source/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/Source/list.o: ../FreeRTOS/Source/list.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/Source/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/Source/queue.o: ../FreeRTOS/Source/queue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/Source/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/Source/tasks.o: ../FreeRTOS/Source/tasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/Source/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FreeRTOS/Source/timers.o: ../FreeRTOS/Source/timers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F10X_HD -DGCC_ARMCM3 -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/STM32F10x_StdPeriph_Driver/inc -I../Libraries/CMSIS/Device/ST/STM32F10x/Include -I../Libraries/CMSIS/Include -I../FreeRTOS/Source/include -I../FreeRTOS -I../FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/Source/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

