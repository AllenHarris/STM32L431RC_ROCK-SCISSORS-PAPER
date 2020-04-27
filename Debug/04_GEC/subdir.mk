################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../04_GEC/bios_api.c 

OBJS += \
./04_GEC/bios_api.o 

C_DEPS += \
./04_GEC/bios_api.d 


# Each subdirectory must supply rules for building sources it contributes
04_GEC/bios_api.o: ../04_GEC/bios_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L431xx -DDEBUG -c -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/02_CPU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/Linker_file" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/MCU_drivers" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/startup" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/04_GEC" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/05_UserBoard" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/06_SoftComponent" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI/Inc" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/08_NosPrg" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"04_GEC/bios_api.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

