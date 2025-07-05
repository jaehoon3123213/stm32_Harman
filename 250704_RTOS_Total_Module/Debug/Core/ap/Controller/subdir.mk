################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/Controller/Controller.c \
../Core/ap/Controller/Distance.c \
../Core/ap/Controller/StopWatch.c \
../Core/ap/Controller/TempHumi.c \
../Core/ap/Controller/TimeWatch.c 

OBJS += \
./Core/ap/Controller/Controller.o \
./Core/ap/Controller/Distance.o \
./Core/ap/Controller/StopWatch.o \
./Core/ap/Controller/TempHumi.o \
./Core/ap/Controller/TimeWatch.o 

C_DEPS += \
./Core/ap/Controller/Controller.d \
./Core/ap/Controller/Distance.d \
./Core/ap/Controller/StopWatch.d \
./Core/ap/Controller/TempHumi.d \
./Core/ap/Controller/TimeWatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/Controller/%.o Core/ap/Controller/%.su Core/ap/Controller/%.cyclo: ../Core/ap/Controller/%.c Core/ap/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/Button" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/LedBar" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/LCD" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/FND" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Controller" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Listener" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Model" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Presenter" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/DHT11" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/UltraSonic" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-Controller

clean-Core-2f-ap-2f-Controller:
	-$(RM) ./Core/ap/Controller/Controller.cyclo ./Core/ap/Controller/Controller.d ./Core/ap/Controller/Controller.o ./Core/ap/Controller/Controller.su ./Core/ap/Controller/Distance.cyclo ./Core/ap/Controller/Distance.d ./Core/ap/Controller/Distance.o ./Core/ap/Controller/Distance.su ./Core/ap/Controller/StopWatch.cyclo ./Core/ap/Controller/StopWatch.d ./Core/ap/Controller/StopWatch.o ./Core/ap/Controller/StopWatch.su ./Core/ap/Controller/TempHumi.cyclo ./Core/ap/Controller/TempHumi.d ./Core/ap/Controller/TempHumi.o ./Core/ap/Controller/TempHumi.su ./Core/ap/Controller/TimeWatch.cyclo ./Core/ap/Controller/TimeWatch.d ./Core/ap/Controller/TimeWatch.o ./Core/ap/Controller/TimeWatch.su

.PHONY: clean-Core-2f-ap-2f-Controller

