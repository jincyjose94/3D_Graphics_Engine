################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc11xx.c \
../src/crp.c \
../src/lcd__api.c \
../src/main.c \
../src/screensaver.c \
../src/sysinit.c 

C_DEPS += \
./src/cr_startup_lpc11xx.d \
./src/crp.d \
./src/lcd__api.d \
./src/main.d \
./src/screensaver.d \
./src/sysinit.d 

OBJS += \
./src/cr_startup_lpc11xx.o \
./src/crp.o \
./src/lcd__api.o \
./src/main.o \
./src/screensaver.o \
./src/sysinit.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11XX__ -D__REDLIB__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/cr_startup_lpc11xx.d ./src/cr_startup_lpc11xx.o ./src/crp.d ./src/crp.o ./src/lcd__api.d ./src/lcd__api.o ./src/main.d ./src/main.o ./src/screensaver.d ./src/screensaver.o ./src/sysinit.d ./src/sysinit.o

.PHONY: clean-src

