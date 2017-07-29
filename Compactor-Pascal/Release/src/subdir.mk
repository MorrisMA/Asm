################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Compactor-Pascal.c \
../src/ScannerPascal.c \
../src/error.c 

OBJS += \
./src/Compactor-Pascal.o \
./src/ScannerPascal.o \
./src/error.o 

C_DEPS += \
./src/Compactor-Pascal.d \
./src/ScannerPascal.d \
./src/error.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c99 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


