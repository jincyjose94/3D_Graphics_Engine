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


BUILD_ARTIFACT_NAME := prj2_3d
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: prj2_3d.axf

# Tool invocations
prj2_3d.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\nxp_lpcxpresso_11c24_board_lib\Debug" -L"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\lpc_chip_11cxx_lib\Debug" -Xlinker -Map="prj2_3d.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T prj2_3d_Debug.ld -o "prj2_3d.axf" $(OBJS) $(USER_OBJS) $(LIBS) -lnxp_lpcxpresso_11c24_board_lib -llpc_chip_11cxx_lib
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) prj2_3d.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "prj2_3d.axf"; # arm-none-eabi-objcopy -O binary "prj2_3d.axf" "prj2_3d.bin" ; checksum -p LPC11C24_301 -d "prj2_3d.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
