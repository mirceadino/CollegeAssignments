################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Console.cpp \
../src/Controller.cpp \
../src/ControllerTest.cpp \
../src/DynamicVector.cpp \
../src/DynamicVectorTest.cpp \
../src/Playlist.cpp \
../src/Repository.cpp \
../src/RepositoryTest.cpp \
../src/Tutorial.cpp \
../src/main.cpp 

OBJS += \
./src/Console.o \
./src/Controller.o \
./src/ControllerTest.o \
./src/DynamicVector.o \
./src/DynamicVectorTest.o \
./src/Playlist.o \
./src/Repository.o \
./src/RepositoryTest.o \
./src/Tutorial.o \
./src/main.o 

CPP_DEPS += \
./src/Console.d \
./src/Controller.d \
./src/ControllerTest.d \
./src/DynamicVector.d \
./src/DynamicVectorTest.d \
./src/Playlist.d \
./src/Repository.d \
./src/RepositoryTest.d \
./src/Tutorial.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


