################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/ultraSonic/ultrasonic.c 

OBJS += \
./Core/driver/ultraSonic/ultrasonic.o 

C_DEPS += \
./Core/driver/ultraSonic/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/ultraSonic/%.o Core/driver/ultraSonic/%.su Core/driver/ultraSonic/%.cyclo: ../Core/driver/ultraSonic/%.c Core/driver/ultraSonic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver/Button" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver/LedBar" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver/LCD" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver/FND" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/ap/Controller" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/ap/Listener" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/ap/Model" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/ap/Presenter" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver/DHT11" -I"C:/stm32_Harman/20250704_RTOS_Watch/Core/driver/ultraSonic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver-2f-ultraSonic

clean-Core-2f-driver-2f-ultraSonic:
	-$(RM) ./Core/driver/ultraSonic/ultrasonic.cyclo ./Core/driver/ultraSonic/ultrasonic.d ./Core/driver/ultraSonic/ultrasonic.o ./Core/driver/ultraSonic/ultrasonic.su

.PHONY: clean-Core-2f-driver-2f-ultraSonic

