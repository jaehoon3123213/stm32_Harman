################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/Model/Model_Distance.c \
../Core/ap/Model/Model_Mode.c \
../Core/ap/Model/Model_StopWatch.c \
../Core/ap/Model/Model_TempHumi.c \
../Core/ap/Model/Model_TimeWatch.c 

OBJS += \
./Core/ap/Model/Model_Distance.o \
./Core/ap/Model/Model_Mode.o \
./Core/ap/Model/Model_StopWatch.o \
./Core/ap/Model/Model_TempHumi.o \
./Core/ap/Model/Model_TimeWatch.o 

C_DEPS += \
./Core/ap/Model/Model_Distance.d \
./Core/ap/Model/Model_Mode.d \
./Core/ap/Model/Model_StopWatch.d \
./Core/ap/Model/Model_TempHumi.d \
./Core/ap/Model/Model_TimeWatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/Model/%.o Core/ap/Model/%.su Core/ap/Model/%.cyclo: ../Core/ap/Model/%.c Core/ap/Model/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/Button" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/LedBar" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/LCD" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/FND" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Controller" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Listener" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Model" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Presenter" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/DHT11" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/UltraSonic" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-Model

clean-Core-2f-ap-2f-Model:
	-$(RM) ./Core/ap/Model/Model_Distance.cyclo ./Core/ap/Model/Model_Distance.d ./Core/ap/Model/Model_Distance.o ./Core/ap/Model/Model_Distance.su ./Core/ap/Model/Model_Mode.cyclo ./Core/ap/Model/Model_Mode.d ./Core/ap/Model/Model_Mode.o ./Core/ap/Model/Model_Mode.su ./Core/ap/Model/Model_StopWatch.cyclo ./Core/ap/Model/Model_StopWatch.d ./Core/ap/Model/Model_StopWatch.o ./Core/ap/Model/Model_StopWatch.su ./Core/ap/Model/Model_TempHumi.cyclo ./Core/ap/Model/Model_TempHumi.d ./Core/ap/Model/Model_TempHumi.o ./Core/ap/Model/Model_TempHumi.su ./Core/ap/Model/Model_TimeWatch.cyclo ./Core/ap/Model/Model_TimeWatch.d ./Core/ap/Model/Model_TimeWatch.o ./Core/ap/Model/Model_TimeWatch.su

.PHONY: clean-Core-2f-ap-2f-Model

