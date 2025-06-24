################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/ap_main.c \
../Core/ap/stopwatch.c \
../Core/ap/timewatch.c 

OBJS += \
./Core/ap/ap_main.o \
./Core/ap/stopwatch.o \
./Core/ap/timewatch.o 

C_DEPS += \
./Core/ap/ap_main.d \
./Core/ap/stopwatch.d \
./Core/ap/timewatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/%.o Core/ap/%.su Core/ap/%.cyclo: ../Core/ap/%.c Core/ap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kccistc/STM32CubeIDE/workspace_1.18.1/20250624_Timewatch_Stopwatch_copy/Core/ap" -I"C:/Users/kccistc/STM32CubeIDE/workspace_1.18.1/20250624_Timewatch_Stopwatch_copy/Core/driver/Button" -I"C:/Users/kccistc/STM32CubeIDE/workspace_1.18.1/20250624_Timewatch_Stopwatch_copy/Core/driver/FND" -I"C:/Users/kccistc/STM32CubeIDE/workspace_1.18.1/20250624_Timewatch_Stopwatch_copy/Core/driver/Ledbar" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap

clean-Core-2f-ap:
	-$(RM) ./Core/ap/ap_main.cyclo ./Core/ap/ap_main.d ./Core/ap/ap_main.o ./Core/ap/ap_main.su ./Core/ap/stopwatch.cyclo ./Core/ap/stopwatch.d ./Core/ap/stopwatch.o ./Core/ap/stopwatch.su ./Core/ap/timewatch.cyclo ./Core/ap/timewatch.d ./Core/ap/timewatch.o ./Core/ap/timewatch.su

.PHONY: clean-Core-2f-ap

