################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/3d_lcd__api.c \
../example/src/cr_startup_lpc11xx.c \
../example/src/diffuse.c \
../example/src/forest.c \
../example/src/main.c \
../example/src/sysinit.c 

C_DEPS += \
./example/src/3d_lcd__api.d \
./example/src/cr_startup_lpc11xx.d \
./example/src/diffuse.d \
./example/src/forest.d \
./example/src/main.d \
./example/src/sysinit.d 

OBJS += \
./example/src/3d_lcd__api.o \
./example/src/cr_startup_lpc11xx.o \
./example/src/diffuse.o \
./example/src/forest.o \
./example/src/main.o \
./example/src/sysinit.o 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c example/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\prj2_3d\example\inc" -I"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\lpc_chip_11cxx_lib\inc" -I"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\nxp_lpcxpresso_11c24_board_lib\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

example/src/cr_startup_lpc11xx.o: ../example/src/cr_startup_lpc11xx.c example/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\prj2_3d\example\inc" -I"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\lpc_chip_11cxx_lib\inc" -I"C:\Users\Checkout\Documents\FALL2023\CMPE240_CLASS\HW_CUBE\PRJ_1\nxp_lpcxpresso_11c24_board_lib\inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-example-2f-src

clean-example-2f-src:
	-$(RM) ./example/src/3d_lcd__api.d ./example/src/3d_lcd__api.o ./example/src/cr_startup_lpc11xx.d ./example/src/cr_startup_lpc11xx.o ./example/src/diffuse.d ./example/src/diffuse.o ./example/src/forest.d ./example/src/forest.o ./example/src/main.d ./example/src/main.o ./example/src/sysinit.d ./example/src/sysinit.o

.PHONY: clean-example-2f-src

