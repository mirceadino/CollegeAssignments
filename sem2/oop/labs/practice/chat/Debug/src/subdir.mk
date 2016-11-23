################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Admin.cpp \
../src/AdminWindow.cpp \
../src/User.cpp \
../src/main.cpp \
../src/moc_AdminWindow.cpp \
../src/moc_User.cpp 

OBJS += \
./src/Admin.o \
./src/AdminWindow.o \
./src/User.o \
./src/main.o \
./src/moc_AdminWindow.o \
./src/moc_User.o 

CPP_DEPS += \
./src/Admin.d \
./src/AdminWindow.d \
./src/User.d \
./src/main.d \
./src/moc_AdminWindow.d \
./src/moc_User.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


