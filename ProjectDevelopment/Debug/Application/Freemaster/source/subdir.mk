################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Freemaster/source/freemaster_STM32F4xx.c \
../Application/Freemaster/source/freemaster_appcmd.c \
../Application/Freemaster/source/freemaster_bdm.c \
../Application/Freemaster/source/freemaster_can.c \
../Application/Freemaster/source/freemaster_lin.c \
../Application/Freemaster/source/freemaster_pipes.c \
../Application/Freemaster/source/freemaster_protocol.c \
../Application/Freemaster/source/freemaster_rec.c \
../Application/Freemaster/source/freemaster_scope.c \
../Application/Freemaster/source/freemaster_serial.c \
../Application/Freemaster/source/freemaster_sfio.c \
../Application/Freemaster/source/freemaster_tsa.c 

OBJS += \
./Application/Freemaster/source/freemaster_STM32F4xx.o \
./Application/Freemaster/source/freemaster_appcmd.o \
./Application/Freemaster/source/freemaster_bdm.o \
./Application/Freemaster/source/freemaster_can.o \
./Application/Freemaster/source/freemaster_lin.o \
./Application/Freemaster/source/freemaster_pipes.o \
./Application/Freemaster/source/freemaster_protocol.o \
./Application/Freemaster/source/freemaster_rec.o \
./Application/Freemaster/source/freemaster_scope.o \
./Application/Freemaster/source/freemaster_serial.o \
./Application/Freemaster/source/freemaster_sfio.o \
./Application/Freemaster/source/freemaster_tsa.o 

C_DEPS += \
./Application/Freemaster/source/freemaster_STM32F4xx.d \
./Application/Freemaster/source/freemaster_appcmd.d \
./Application/Freemaster/source/freemaster_bdm.d \
./Application/Freemaster/source/freemaster_can.d \
./Application/Freemaster/source/freemaster_lin.d \
./Application/Freemaster/source/freemaster_pipes.d \
./Application/Freemaster/source/freemaster_protocol.d \
./Application/Freemaster/source/freemaster_rec.d \
./Application/Freemaster/source/freemaster_scope.d \
./Application/Freemaster/source/freemaster_serial.d \
./Application/Freemaster/source/freemaster_sfio.d \
./Application/Freemaster/source/freemaster_tsa.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Freemaster/source/freemaster_STM32F4xx.o: ../Application/Freemaster/source/freemaster_STM32F4xx.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_STM32F4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_appcmd.o: ../Application/Freemaster/source/freemaster_appcmd.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_appcmd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_bdm.o: ../Application/Freemaster/source/freemaster_bdm.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_bdm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_can.o: ../Application/Freemaster/source/freemaster_can.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_can.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_lin.o: ../Application/Freemaster/source/freemaster_lin.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_lin.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_pipes.o: ../Application/Freemaster/source/freemaster_pipes.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_pipes.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_protocol.o: ../Application/Freemaster/source/freemaster_protocol.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_protocol.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_rec.o: ../Application/Freemaster/source/freemaster_rec.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_rec.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_scope.o: ../Application/Freemaster/source/freemaster_scope.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_scope.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_serial.o: ../Application/Freemaster/source/freemaster_serial.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_serial.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_sfio.o: ../Application/Freemaster/source/freemaster_sfio.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_sfio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Freemaster/source/freemaster_tsa.o: ../Application/Freemaster/source/freemaster_tsa.c Application/Freemaster/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Application/Freemaster/include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/Freemaster/source/freemaster_tsa.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

