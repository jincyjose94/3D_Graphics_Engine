################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := FOREST
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: FOREST.axf

# Tool invocations
FOREST.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\nxp_lpcxpresso_11c24_board_lib\Debug" -L"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\lpc_chip_11cxx_lib\Debug" -Xlinker -Map="FOREST.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T FOREST_Debug.ld -o "FOREST.axf" $(OBJS) $(USER_OBJS) $(LIBS) -lnxp_lpcxpresso_11c24_board_lib -llpc_chip_11cxx_lib
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) FOREST.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "FOREST.axf"; # arm-none-eabi-objcopy -O binary "FOREST.axf" "FOREST.bin" ; checksum -p LPC11C24_301 -d "FOREST.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
