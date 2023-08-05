################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/Sourse/DIO_Prog.c 

OBJS += \
./MCAL/DIO/Sourse/DIO_Prog.o 

C_DEPS += \
./MCAL/DIO/Sourse/DIO_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/Sourse/%.o: ../MCAL/DIO/Sourse/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


