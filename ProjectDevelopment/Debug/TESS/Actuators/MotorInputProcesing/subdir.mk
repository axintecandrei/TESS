################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TESS/Actuators/MotorInputProcesing/tess_motorinputprocessing.c 

OBJS += \
./TESS/Actuators/MotorInputProcesing/tess_motorinputprocessing.o 

C_DEPS += \
./TESS/Actuators/MotorInputProcesing/tess_motorinputprocessing.d 


# Each subdirectory must supply rules for building sources it contributes
TESS/Actuators/MotorInputProcesing/tess_motorinputprocessing.o: ../TESS/Actuators/MotorInputProcesing/tess_motorinputprocessing.c TESS/Actuators/MotorInputProcesing/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Actuators/MotorInputProcesing/tess_motorinputprocessing.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

