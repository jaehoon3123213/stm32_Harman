################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/button/button.c 

OBJS += \
./Src/driver/button/button.o 

C_DEPS += \
./Src/driver/button/button.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/button/%.o Src/driver/button/%.su Src/driver/button/%.cyclo: ../Src/driver/button/%.c Src/driver/button/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/stm32_Harman/25250619_button_led/Src/driver/GPIO" -I"C:/stm32_Harman/25250619_button_led/Src/driver/LedBar" -I"C:/stm32_Harman/25250619_button_led/Src/driver/SystemClock" -I"C:/stm32_Harman/25250619_button_led/Src/ap" -I"C:/stm32_Harman/25250619_button_led/Src/driver/button" -I"C:/stm32_Harman/25250619_button_led/Src/driver/FND" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver-2f-button

clean-Src-2f-driver-2f-button:
	-$(RM) ./Src/driver/button/button.cyclo ./Src/driver/button/button.d ./Src/driver/button/button.o ./Src/driver/button/button.su

.PHONY: clean-Src-2f-driver-2f-button

