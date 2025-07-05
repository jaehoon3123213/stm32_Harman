################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/Presenter/Presenter.c \
../Core/ap/Presenter/Presenter_Distance.c \
../Core/ap/Presenter/Presenter_StopWatch.c \
../Core/ap/Presenter/Presenter_TempHumi.c \
../Core/ap/Presenter/Presenter_TimeWatch.c 

OBJS += \
./Core/ap/Presenter/Presenter.o \
./Core/ap/Presenter/Presenter_Distance.o \
./Core/ap/Presenter/Presenter_StopWatch.o \
./Core/ap/Presenter/Presenter_TempHumi.o \
./Core/ap/Presenter/Presenter_TimeWatch.o 

C_DEPS += \
./Core/ap/Presenter/Presenter.d \
./Core/ap/Presenter/Presenter_Distance.d \
./Core/ap/Presenter/Presenter_StopWatch.d \
./Core/ap/Presenter/Presenter_TempHumi.d \
./Core/ap/Presenter/Presenter_TimeWatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/Presenter/%.o Core/ap/Presenter/%.su Core/ap/Presenter/%.cyclo: ../Core/ap/Presenter/%.c Core/ap/Presenter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/Button" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/LedBar" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/LCD" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/FND" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Controller" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Listener" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Model" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/ap/Presenter" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/DHT11" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/driver/UltraSonic" -I"C:/stm32_Harman/250704_RTOS_Total_Module/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-Presenter

clean-Core-2f-ap-2f-Presenter:
	-$(RM) ./Core/ap/Presenter/Presenter.cyclo ./Core/ap/Presenter/Presenter.d ./Core/ap/Presenter/Presenter.o ./Core/ap/Presenter/Presenter.su ./Core/ap/Presenter/Presenter_Distance.cyclo ./Core/ap/Presenter/Presenter_Distance.d ./Core/ap/Presenter/Presenter_Distance.o ./Core/ap/Presenter/Presenter_Distance.su ./Core/ap/Presenter/Presenter_StopWatch.cyclo ./Core/ap/Presenter/Presenter_StopWatch.d ./Core/ap/Presenter/Presenter_StopWatch.o ./Core/ap/Presenter/Presenter_StopWatch.su ./Core/ap/Presenter/Presenter_TempHumi.cyclo ./Core/ap/Presenter/Presenter_TempHumi.d ./Core/ap/Presenter/Presenter_TempHumi.o ./Core/ap/Presenter/Presenter_TempHumi.su ./Core/ap/Presenter/Presenter_TimeWatch.cyclo ./Core/ap/Presenter/Presenter_TimeWatch.d ./Core/ap/Presenter/Presenter_TimeWatch.o ./Core/ap/Presenter/Presenter_TimeWatch.su

.PHONY: clean-Core-2f-ap-2f-Presenter

