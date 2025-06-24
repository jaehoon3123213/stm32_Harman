################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/Src/Controller.c \
../Core/ap/Src/Listener.c \
../Core/ap/Src/Presenter.c \
../Core/ap/Src/ap_main.c \
../Core/ap/Src/stopwatch.c \
../Core/ap/Src/timewatch.c 

OBJS += \
./Core/ap/Src/Controller.o \
./Core/ap/Src/Listener.o \
./Core/ap/Src/Presenter.o \
./Core/ap/Src/ap_main.o \
./Core/ap/Src/stopwatch.o \
./Core/ap/Src/timewatch.o 

C_DEPS += \
./Core/ap/Src/Controller.d \
./Core/ap/Src/Listener.d \
./Core/ap/Src/Presenter.d \
./Core/ap/Src/ap_main.d \
./Core/ap/Src/stopwatch.d \
./Core/ap/Src/timewatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/Src/%.o Core/ap/Src/%.su Core/ap/Src/%.cyclo: ../Core/ap/Src/%.c Core/ap/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/ap" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/driver/Button" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/driver/FND" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/driver/Ledbar" -I"C:/stm32_Harman/20250624_Timewatch_Stopwatch_Structure/Core/ap/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-Src

clean-Core-2f-ap-2f-Src:
	-$(RM) ./Core/ap/Src/Controller.cyclo ./Core/ap/Src/Controller.d ./Core/ap/Src/Controller.o ./Core/ap/Src/Controller.su ./Core/ap/Src/Listener.cyclo ./Core/ap/Src/Listener.d ./Core/ap/Src/Listener.o ./Core/ap/Src/Listener.su ./Core/ap/Src/Presenter.cyclo ./Core/ap/Src/Presenter.d ./Core/ap/Src/Presenter.o ./Core/ap/Src/Presenter.su ./Core/ap/Src/ap_main.cyclo ./Core/ap/Src/ap_main.d ./Core/ap/Src/ap_main.o ./Core/ap/Src/ap_main.su ./Core/ap/Src/stopwatch.cyclo ./Core/ap/Src/stopwatch.d ./Core/ap/Src/stopwatch.o ./Core/ap/Src/stopwatch.su ./Core/ap/Src/timewatch.cyclo ./Core/ap/Src/timewatch.d ./Core/ap/Src/timewatch.o ./Core/ap/Src/timewatch.su

.PHONY: clean-Core-2f-ap-2f-Src

