################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f411retx.s 

OBJS += \
./Core/Startup/startup_stm32f411retx.o 

S_DEPS += \
./Core/Startup/startup_stm32f411retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/stm32_Harman/20250623_TimeWatch_StopWatch/Core/ap" -I"C:/stm32_Harman/20250623_TimeWatch_StopWatch/Core/driver" -I"C:/stm32_Harman/20250623_TimeWatch_StopWatch/Core/driver/FND" -I"C:/stm32_Harman/20250623_TimeWatch_StopWatch/Core/driver/LedBar" -I"C:/stm32_Harman/20250623_TimeWatch_StopWatch/Core/driver/button" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f411retx.d ./Core/Startup/startup_stm32f411retx.o

.PHONY: clean-Core-2f-Startup

