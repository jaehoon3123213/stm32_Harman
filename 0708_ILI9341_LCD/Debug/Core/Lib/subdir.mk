################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Lib/fonts.c \
../Core/Lib/ili9341.c \
../Core/Lib/ili9341_touch.c \
../Core/Lib/parrot_240x240.c 

OBJS += \
./Core/Lib/fonts.o \
./Core/Lib/ili9341.o \
./Core/Lib/ili9341_touch.o \
./Core/Lib/parrot_240x240.o 

C_DEPS += \
./Core/Lib/fonts.d \
./Core/Lib/ili9341.d \
./Core/Lib/ili9341_touch.d \
./Core/Lib/parrot_240x240.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Lib/%.o Core/Lib/%.su Core/Lib/%.cyclo: ../Core/Lib/%.c Core/Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/stm32_Harman/0708_ILI9341_LCD/Core/Lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Lib

clean-Core-2f-Lib:
	-$(RM) ./Core/Lib/fonts.cyclo ./Core/Lib/fonts.d ./Core/Lib/fonts.o ./Core/Lib/fonts.su ./Core/Lib/ili9341.cyclo ./Core/Lib/ili9341.d ./Core/Lib/ili9341.o ./Core/Lib/ili9341.su ./Core/Lib/ili9341_touch.cyclo ./Core/Lib/ili9341_touch.d ./Core/Lib/ili9341_touch.o ./Core/Lib/ili9341_touch.su ./Core/Lib/parrot_240x240.cyclo ./Core/Lib/parrot_240x240.d ./Core/Lib/parrot_240x240.o ./Core/Lib/parrot_240x240.su

.PHONY: clean-Core-2f-Lib

