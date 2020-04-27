################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 08_NosPrg/subdir.mk
-include 07_X-Cube_AI/subdir.mk
-include 06_SoftComponent/subdir.mk
-include 05_UserBoard/subdir.mk
-include 04_GEC/subdir.mk
-include 03_MCU/startup/subdir.mk
-include 03_MCU/MCU_drivers/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32_x-cube-ai_20200426.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32_x-cube-ai_20200426.list \

OBJCOPY_HEX += \
STM32_x-cube-ai_20200426.hex \

OBJCOPY_BIN += \
STM32_x-cube-ai_20200426.bin \


# All Target
all: STM32_x-cube-ai_20200426.elf secondary-outputs

# Tool invocations
STM32_x-cube-ai_20200426.elf: $(OBJS) $(USER_OBJS) D:\STM32\Cube\ AI\rock_paper_scissors_cnn\STM32L432-X_Cube_AI_20200426\03_MCU\Linker_file\STM32L431RCTX_FLASH.ld
	arm-none-eabi-gcc -o "STM32_x-cube-ai_20200426.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\STM32\Cube AI\rock_paper_scissors_cnn\STM32L432-X_Cube_AI_20200426\03_MCU\Linker_file\STM32L431RCTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32_x-cube-ai_20200426.map" -Wl,--gc-sections -static -L../07_X-Cube_AI/AI/Lib --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32_x-cube-ai_20200426.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32_x-cube-ai_20200426.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32_x-cube-ai_20200426.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "STM32_x-cube-ai_20200426.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32_x-cube-ai_20200426.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32_x-cube-ai_20200426.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
