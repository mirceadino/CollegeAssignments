################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller.cpp \
../src/Programmer.cpp \
../src/ProgrammerWindow.cpp \
../src/Task.cpp \
../src/TaskRepository.cpp \
../src/main.cpp \
../src/moc_ProgrammerWindow.cpp 

OBJS += \
./src/Controller.o \
./src/Programmer.o \
./src/ProgrammerWindow.o \
./src/Task.o \
./src/TaskRepository.o \
./src/main.o \
./src/moc_ProgrammerWindow.o 

CPP_DEPS += \
./src/Controller.d \
./src/Programmer.d \
./src/ProgrammerWindow.d \
./src/Task.d \
./src/TaskRepository.d \
./src/main.d \
./src/moc_ProgrammerWindow.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


