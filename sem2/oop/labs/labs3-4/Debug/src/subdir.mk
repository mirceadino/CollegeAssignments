################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Estate.c \
../src/Main.c \
../src/OperationStack.c \
../src/Repository.c \
../src/TestController.c \
../src/TestEstate.c \
../src/TestRepository.c \
../src/TestVector.c \
../src/UI.c \
../src/Vector.c 

OBJS += \
./src/Controller.o \
./src/Estate.o \
./src/Main.o \
./src/OperationStack.o \
./src/Repository.o \
./src/TestController.o \
./src/TestEstate.o \
./src/TestRepository.o \
./src/TestVector.o \
./src/UI.o \
./src/Vector.o 

C_DEPS += \
./src/Controller.d \
./src/Estate.d \
./src/Main.d \
./src/OperationStack.d \
./src/Repository.d \
./src/TestController.d \
./src/TestEstate.d \
./src/TestRepository.d \
./src/TestVector.d \
./src/UI.d \
./src/Vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


