################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Bill.o \
../Controller.o \
../Repository.o \
../main.o 

CPP_SRCS += \
../App.cpp \
../Bill.cpp \
../Controller.cpp \
../Repository.cpp \
../main.cpp 

OBJS += \
./App.o \
./Bill.o \
./Controller.o \
./Repository.o \
./main.o 

CPP_DEPS += \
./App.d \
./Bill.d \
./Controller.d \
./Repository.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


