################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Infix2Postfix_Converter.c \
../src/ScannerPascal.c \
../src/error.c 

OBJS += \
./src/Infix2Postfix_Converter.o \
./src/ScannerPascal.o \
./src/error.o 

C_DEPS += \
./src/Infix2Postfix_Converter.d \
./src/ScannerPascal.d \
./src/error.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


