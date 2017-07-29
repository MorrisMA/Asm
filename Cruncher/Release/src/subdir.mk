################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cruncher.c \
../src/ScannerPascal.c \
../src/error.c \
../src/symtab.c 

OBJS += \
./src/Cruncher.o \
./src/ScannerPascal.o \
./src/error.o \
./src/symtab.o 

C_DEPS += \
./src/Cruncher.d \
./src/ScannerPascal.d \
./src/error.d \
./src/symtab.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


