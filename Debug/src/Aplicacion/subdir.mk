################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aplicacion/inicializar.cpp \
../src/Aplicacion/main.cpp 

CPP_DEPS += \
./src/Aplicacion/inicializar.d \
./src/Aplicacion/main.d 

OBJS += \
./src/Aplicacion/inicializar.o \
./src/Aplicacion/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/Aplicacion/%.o: ../src/Aplicacion/%.cpp src/Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Hardware/Drivers" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Hardware/Perifericos" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Hardware/Perifericos/01-Pin" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Hardware/Perifericos/02-Gpio" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Hardware/Perifericos/SCTimer" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Aplicacion" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Firmware" -I"/home/agustin/Documents/MCUXpresso/workspace/LPC845/src/Hardware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Aplicacion

clean-src-2f-Aplicacion:
	-$(RM) ./src/Aplicacion/inicializar.d ./src/Aplicacion/inicializar.o ./src/Aplicacion/main.d ./src/Aplicacion/main.o

.PHONY: clean-src-2f-Aplicacion

