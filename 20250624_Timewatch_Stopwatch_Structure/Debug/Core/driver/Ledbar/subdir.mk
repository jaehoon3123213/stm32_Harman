################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/Ledbar/ledbar.c 

OBJS += \
./Core/driver/Ledbar/ledbar.o 

C_DEPS += \
./Core/driver/Ledbar/ledbar.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/Ledbar/%.o Core/driver/Ledbar/%.su Core/driver/Ledbar/%.cyclo: ../Core/driver/Ledbar/%.c Core/driver/Ledbar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/ap" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/driver/Button" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/driver/FND" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/driver/Ledbar" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/ap/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver-2f-Ledbar

clean-Core-2f-driver-2f-Ledbar:
	-$(RM) ./Core/driver/Ledbar/ledbar.cyclo ./Core/driver/Ledbar/ledbar.d ./Core/driver/Ledbar/ledbar.o ./Core/driver/Ledbar/ledbar.su

.PHONY: clean-Core-2f-driver-2f-Ledbar

