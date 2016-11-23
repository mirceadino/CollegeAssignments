################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/App.cpp \
../src/Controller.cpp \
../src/Gene.cpp \
../src/Repository.cpp \
../src/main.cpp \
../src/moc_App.cpp 

OBJS += \
./src/App.o \
./src/Controller.o \
./src/Gene.o \
./src/Repository.o \
./src/main.o \
./src/moc_App.o 

CPP_DEPS += \
./src/App.d \
./src/Controller.d \
./src/Gene.d \
./src/Repository.d \
./src/main.d \
./src/moc_App.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


