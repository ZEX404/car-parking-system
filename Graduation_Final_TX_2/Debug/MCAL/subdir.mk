################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO.c \
../MCAL/EXTI.c \
../MCAL/GIE.c \
../MCAL/UART_TX.c \
../MCAL/timer.c 

OBJS += \
./MCAL/DIO.o \
./MCAL/EXTI.o \
./MCAL/GIE.o \
./MCAL/UART_TX.o \
./MCAL/timer.o 

C_DEPS += \
./MCAL/DIO.d \
./MCAL/EXTI.d \
./MCAL/GIE.d \
./MCAL/UART_TX.d \
./MCAL/timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


