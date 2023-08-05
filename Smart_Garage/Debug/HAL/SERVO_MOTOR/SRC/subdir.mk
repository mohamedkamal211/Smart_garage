################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SERVO_MOTOR/SRC/SERVO_Program.c 

OBJS += \
./HAL/SERVO_MOTOR/SRC/SERVO_Program.o 

C_DEPS += \
./HAL/SERVO_MOTOR/SRC/SERVO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SERVO_MOTOR/SRC/%.o: ../HAL/SERVO_MOTOR/SRC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


