################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/LedBar/LedBar.c 

OBJS += \
./Src/driver/LedBar/LedBar.o 

C_DEPS += \
./Src/driver/LedBar/LedBar.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/LedBar/%.o Src/driver/LedBar/%.su Src/driver/LedBar/%.cyclo: ../Src/driver/LedBar/%.c Src/driver/LedBar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/button" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/FND" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/GPIO" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/LedBar" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/SystemClock" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/ap" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/TIM" -I"C:/stm32_Harman/20250620_FND_TIM_interrupt/Src/driver/SysTick" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-LedBar

clean-Src-2f-driver-2f-LedBar:
	-$(RM) ./Src/driver/LedBar/LedBar.cyclo ./Src/driver/LedBar/LedBar.d ./Src/driver/LedBar/LedBar.o ./Src/driver/LedBar/LedBar.su

.PHONY: clean-Src-2f-driver-2f-LedBar

