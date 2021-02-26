################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Startup/subdir.mk
-include Libraries/STM32F10x_StdPeriph_Driver/src/subdir.mk
-include FreeRTOS/Source/portable/MemMang/subdir.mk
-include FreeRTOS/Source/portable/GCC/ARM_CM3/subdir.mk
-include FreeRTOS/Source/subdir.mk
-include Drivers/TIMEOUT/subdir.mk
-include Drivers/SPI/subdir.mk
-include Drivers/PROCESS/subdir.mk
-include Drivers/LCD_ILI9431/XPT2046/subdir.mk
-include Drivers/LCD_ILI9431/TOUCH/subdir.mk
-include Drivers/LCD_ILI9431/ILI9431/subdir.mk
-include Drivers/LCD_ILI9431/DISPLAY/subdir.mk
-include Drivers/GPIO/subdir.mk
-include Drivers/ENCODE/subdir.mk
-include Drivers/ANALYZE/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F103VET6_LCD.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103VET6_LCD.list \

OBJCOPY_BIN += \
STM32F103VET6_LCD.bin \


# All Target
all: STM32F103VET6_LCD.elf secondary-outputs

# Tool invocations
STM32F103VET6_LCD.elf: $(OBJS) $(USER_OBJS) ../STM32F103VET_flash.ld
	arm-none-eabi-gcc -o "STM32F103VET6_LCD.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"../STM32F103VET_flash.ld" --specs=nosys.specs -Wl,-Map="STM32F103VET6_LCD.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103VET6_LCD.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103VET6_LCD.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103VET6_LCD.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103VET6_LCD.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
