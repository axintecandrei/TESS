################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TESS/Freemaster/source/freemaster_STM32F4xx.c \
../TESS/Freemaster/source/freemaster_appcmd.c \
../TESS/Freemaster/source/freemaster_bdm.c \
../TESS/Freemaster/source/freemaster_can.c \
../TESS/Freemaster/source/freemaster_lin.c \
../TESS/Freemaster/source/freemaster_pipes.c \
../TESS/Freemaster/source/freemaster_protocol.c \
../TESS/Freemaster/source/freemaster_rec.c \
../TESS/Freemaster/source/freemaster_scope.c \
../TESS/Freemaster/source/freemaster_serial.c \
../TESS/Freemaster/source/freemaster_sfio.c \
../TESS/Freemaster/source/freemaster_tsa.c 

OBJS += \
./TESS/Freemaster/source/freemaster_STM32F4xx.o \
./TESS/Freemaster/source/freemaster_appcmd.o \
./TESS/Freemaster/source/freemaster_bdm.o \
./TESS/Freemaster/source/freemaster_can.o \
./TESS/Freemaster/source/freemaster_lin.o \
./TESS/Freemaster/source/freemaster_pipes.o \
./TESS/Freemaster/source/freemaster_protocol.o \
./TESS/Freemaster/source/freemaster_rec.o \
./TESS/Freemaster/source/freemaster_scope.o \
./TESS/Freemaster/source/freemaster_serial.o \
./TESS/Freemaster/source/freemaster_sfio.o \
./TESS/Freemaster/source/freemaster_tsa.o 

C_DEPS += \
./TESS/Freemaster/source/freemaster_STM32F4xx.d \
./TESS/Freemaster/source/freemaster_appcmd.d \
./TESS/Freemaster/source/freemaster_bdm.d \
./TESS/Freemaster/source/freemaster_can.d \
./TESS/Freemaster/source/freemaster_lin.d \
./TESS/Freemaster/source/freemaster_pipes.d \
./TESS/Freemaster/source/freemaster_protocol.d \
./TESS/Freemaster/source/freemaster_rec.d \
./TESS/Freemaster/source/freemaster_scope.d \
./TESS/Freemaster/source/freemaster_serial.d \
./TESS/Freemaster/source/freemaster_sfio.d \
./TESS/Freemaster/source/freemaster_tsa.d 


# Each subdirectory must supply rules for building sources it contributes
TESS/Freemaster/source/freemaster_STM32F4xx.o: ../TESS/Freemaster/source/freemaster_STM32F4xx.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_STM32F4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_appcmd.o: ../TESS/Freemaster/source/freemaster_appcmd.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_appcmd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_bdm.o: ../TESS/Freemaster/source/freemaster_bdm.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_bdm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_can.o: ../TESS/Freemaster/source/freemaster_can.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_can.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_lin.o: ../TESS/Freemaster/source/freemaster_lin.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_lin.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_pipes.o: ../TESS/Freemaster/source/freemaster_pipes.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_pipes.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_protocol.o: ../TESS/Freemaster/source/freemaster_protocol.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_rec.o: ../TESS/Freemaster/source/freemaster_rec.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_rec.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_scope.o: ../TESS/Freemaster/source/freemaster_scope.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_scope.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_serial.o: ../TESS/Freemaster/source/freemaster_serial.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_serial.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_sfio.o: ../TESS/Freemaster/source/freemaster_sfio.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_sfio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TESS/Freemaster/source/freemaster_tsa.o: ../TESS/Freemaster/source/freemaster_tsa.c TESS/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../TESS/ -I../TESS/Actuators/MotorDriver -I../TESS/Actuators/ -I../TESS/Actuators/ActStateMachine -I../TESS/Actuators/MotorInputProcesing -I../TESS/Actuators/MotorControl -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../TESS/Freemaster/include -I../Drivers/CMSIS/Include -I"C:/Users/NXF70809/Documents/Laboratory/TESS/ProjectDevelopment/TESS/Actuators/ActStMachine" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TESS/Freemaster/source/freemaster_tsa.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

