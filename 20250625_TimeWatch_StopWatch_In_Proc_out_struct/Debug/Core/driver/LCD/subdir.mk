################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/LCD/LCD.c 

OBJS += \
./Core/driver/LCD/LCD.o 

C_DEPS += \
./Core/driver/LCD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/LCD/%.o Core/driver/LCD/%.su Core/driver/LCD/%.cyclo: ../Core/driver/LCD/%.c Core/driver/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/ap" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/FND" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/LedBar" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/button" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/ap/inc" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/ap/src" -I"C:/stm32_Harman/20250625_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver-2f-LCD

clean-Core-2f-driver-2f-LCD:
	-$(RM) ./Core/driver/LCD/LCD.cyclo ./Core/driver/LCD/LCD.d ./Core/driver/LCD/LCD.o ./Core/driver/LCD/LCD.su

.PHONY: clean-Core-2f-driver-2f-LCD

