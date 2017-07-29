################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ScannerPascal.c \
../src/XRef.c \
../src/error.c \
../src/symtab.c 

OBJS += \
./src/ScannerPascal.o \
./src/XRef.o \
./src/error.o \
./src/symtab.o 

C_DEPS += \
./src/ScannerPascal.d \
./src/XRef.d \
./src/error.d \
./src/symtab.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


