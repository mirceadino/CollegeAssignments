################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SortedMapWithBalancedTree_test.cpp \
../src/SortedMapWithLinkedList_test.cpp \
../src/main.cpp 

OBJS += \
./src/SortedMapWithBalancedTree_test.o \
./src/SortedMapWithLinkedList_test.o \
./src/main.o 

CPP_DEPS += \
./src/SortedMapWithBalancedTree_test.d \
./src/SortedMapWithLinkedList_test.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


