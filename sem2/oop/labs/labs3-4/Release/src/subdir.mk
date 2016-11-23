################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Main.c \
../src/Offer.c \
../src/TestOffer.c \
../src/TestRepository.c \
../src/TestVector.c \
../src/UI.c \
../src/Vector.c 

OBJS += \
./src/Controller.o \
./src/Main.o \
./src/Offer.o \
./src/TestOffer.o \
./src/TestRepository.o \
./src/TestVector.o \
./src/UI.o \
./src/Vector.o 

C_DEPS += \
./src/Controller.d \
./src/Main.d \
./src/Offer.d \
./src/TestOffer.d \
./src/TestRepository.d \
./src/TestVector.d \
./src/UI.d \
./src/Vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


