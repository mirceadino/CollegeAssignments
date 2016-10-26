################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Issue.cpp \
../src/IssueController.cpp \
../src/IssueController_test.cpp \
../src/IssueRepository.cpp \
../src/User.cpp \
../src/UserWindow.cpp \
../src/main.cpp \
../src/moc_UserWindow.cpp 

OBJS += \
./src/Issue.o \
./src/IssueController.o \
./src/IssueController_test.o \
./src/IssueRepository.o \
./src/User.o \
./src/UserWindow.o \
./src/main.o \
./src/moc_UserWindow.o 

CPP_DEPS += \
./src/Issue.d \
./src/IssueController.d \
./src/IssueController_test.d \
./src/IssueRepository.d \
./src/User.d \
./src/UserWindow.d \
./src/main.d \
./src/moc_UserWindow.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


