################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Graduation_Final_RX_2.lss \

FLASH_IMAGE += \
Graduation_Final_RX_2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Graduation_Final_RX_2.elf secondary-outputs

# Tool invocations
Graduation_Final_RX_2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Graduation_Final_RX_2.map -mmcu=atmega32 -o "Graduation_Final_RX_2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Graduation_Final_RX_2.lss: Graduation_Final_RX_2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Graduation_Final_RX_2.elf  >"Graduation_Final_RX_2.lss"
	@echo 'Finished building: $@'
	@echo ' '

Graduation_Final_RX_2.hex: Graduation_Final_RX_2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Graduation_Final_RX_2.elf  "Graduation_Final_RX_2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Graduation_Final_RX_2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Graduation_Final_RX_2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Graduation_Final_RX_2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
