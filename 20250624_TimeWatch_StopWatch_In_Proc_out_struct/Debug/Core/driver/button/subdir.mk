################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/button/button.c 

OBJS += \
./Core/driver/button/button.o 

C_DEPS += \
./Core/driver/button/button.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/button/%.o Core/driver/button/%.su Core/driver/button/%.cyclo: ../Core/driver/button/%.c Core/driver/button/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/ap" -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver" -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/FND" -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/LedBar" -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/driver/button" -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/ap/inc" -I"C:/stm32_Harman/20250624_TimeWatch_StopWatch_In_Proc_out_struct/Core/ap/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver-2f-button

clean-Core-2f-driver-2f-button:
	-$(RM) ./Core/driver/button/button.cyclo ./Core/driver/button/button.d ./Core/driver/button/button.o ./Core/driver/button/button.su

.PHONY: clean-Core-2f-driver-2f-button

