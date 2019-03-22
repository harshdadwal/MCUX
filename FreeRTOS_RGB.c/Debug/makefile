################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FreeRTOS_RGB.c.axf

# Tool invocations
FreeRTOS_RGB.c.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/harsh/MCUX/lpc_board_nxp_lpcxpresso_1769/Debug" -L"/home/harsh/MCUX/lpc_chip_175x_6x/Debug" -Xlinker -Map="FreeRTOS_RGB.c.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "FreeRTOS_RGB_c_Debug.ld" -o "FreeRTOS_RGB.c.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FreeRTOS_RGB.c.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "FreeRTOS_RGB.c.axf"; # arm-none-eabi-objcopy -v -O binary "FreeRTOS_RGB.c.axf" "FreeRTOS_RGB.c.bin" ; # checksum -p LPC1769 -d "FreeRTOS_RGB.c.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
