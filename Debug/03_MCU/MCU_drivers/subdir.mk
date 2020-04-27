################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../03_MCU/MCU_drivers/flash.c \
../03_MCU/MCU_drivers/gpio.c \
../03_MCU/MCU_drivers/light.c \
../03_MCU/MCU_drivers/uart.c 

OBJS += \
./03_MCU/MCU_drivers/flash.o \
./03_MCU/MCU_drivers/gpio.o \
./03_MCU/MCU_drivers/light.o \
./03_MCU/MCU_drivers/uart.o 

C_DEPS += \
./03_MCU/MCU_drivers/flash.d \
./03_MCU/MCU_drivers/gpio.d \
./03_MCU/MCU_drivers/light.d \
./03_MCU/MCU_drivers/uart.d 


# Each subdirectory must supply rules for building sources it contributes
03_MCU/MCU_drivers/flash.o: ../03_MCU/MCU_drivers/flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L431xx -DDEBUG -c -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/02_CPU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/Linker_file" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/MCU_drivers" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/startup" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/04_GEC" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/05_UserBoard" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/06_SoftComponent" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI/Inc" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/08_NosPrg" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"03_MCU/MCU_drivers/flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
03_MCU/MCU_drivers/gpio.o: ../03_MCU/MCU_drivers/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L431xx -DDEBUG -c -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/02_CPU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/Linker_file" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/MCU_drivers" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/startup" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/04_GEC" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/05_UserBoard" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/06_SoftComponent" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI/Inc" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/08_NosPrg" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"03_MCU/MCU_drivers/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
03_MCU/MCU_drivers/light.o: ../03_MCU/MCU_drivers/light.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L431xx -DDEBUG -c -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/02_CPU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/Linker_file" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/MCU_drivers" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/startup" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/04_GEC" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/05_UserBoard" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/06_SoftComponent" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI/Inc" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/08_NosPrg" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"03_MCU/MCU_drivers/light.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
03_MCU/MCU_drivers/uart.o: ../03_MCU/MCU_drivers/uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L431xx -DDEBUG -c -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/02_CPU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/Linker_file" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/MCU_drivers" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/03_MCU/startup" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/04_GEC" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/05_UserBoard" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/06_SoftComponent" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/07_X-Cube_AI/AI/Inc" -I"D:/STM32/Cube AI/rock_paper_scissors_cnn/STM32L432-X_Cube_AI_20200426/08_NosPrg" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"03_MCU/MCU_drivers/uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

