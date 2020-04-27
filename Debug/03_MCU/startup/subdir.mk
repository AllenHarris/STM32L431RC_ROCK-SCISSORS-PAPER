################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../03_MCU/startup/startup_stm32l431rctx.s 

C_SRCS += \
../03_MCU/startup/system_stm32l4xx.c 

OBJS += \
./03_MCU/startup/startup_stm32l431rctx.o \
./03_MCU/startup/system_stm32l4xx.o 

C_DEPS += \
./03_MCU/startup/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
03_MCU/startup/%.o: ../03_MCU/startup/%.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I../ -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
03_MCU/startup/system_stm32l4xx.o: ../03_MCU/startup/system_stm32l4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L431xx -DDEBUG -c -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/02_CPU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/Linker_file" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/MCU_drivers" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/startup" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/04_GEC" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/05_UserBoard" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/06_SoftComponent" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI/Inc" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/08_NosPrg" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"03_MCU/startup/system_stm32l4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

