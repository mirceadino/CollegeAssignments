################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller.cpp \
../src/Player.cpp \
../src/Repository.cpp \
../src/UI.cpp \
../src/main.cpp 

OBJS += \
./src/Controller.o \
./src/Player.o \
./src/Repository.o \
./src/UI.o \
./src/main.o 

CPP_DEPS += \
./src/Controller.d \
./src/Player.d \
./src/Repository.d \
./src/UI.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


