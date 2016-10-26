################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GradingController.cpp \
../src/GradingRepository.cpp \
../src/MainTeacherWindow.cpp \
../src/Student.cpp \
../src/Teacher.cpp \
../src/TeacherWindow.cpp \
../src/Utils.cpp \
../src/main.cpp \
../src/moc_MainTeacherWindow.cpp \
../src/moc_TeacherWindow.cpp 

OBJS += \
./src/GradingController.o \
./src/GradingRepository.o \
./src/MainTeacherWindow.o \
./src/Student.o \
./src/Teacher.o \
./src/TeacherWindow.o \
./src/Utils.o \
./src/main.o \
./src/moc_MainTeacherWindow.o \
./src/moc_TeacherWindow.o 

CPP_DEPS += \
./src/GradingController.d \
./src/GradingRepository.d \
./src/MainTeacherWindow.d \
./src/Student.d \
./src/Teacher.d \
./src/TeacherWindow.d \
./src/Utils.d \
./src/main.d \
./src/moc_MainTeacherWindow.d \
./src/moc_TeacherWindow.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


