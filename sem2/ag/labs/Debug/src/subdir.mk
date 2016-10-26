################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AG.cpp \
../src/ApproximativelyDoubleVertexCover.cpp \
../src/BranchAndBoundVertexCover.cpp \
../src/ConnectedComponentsUndirectedGraphBFS.cpp \
../src/Digraph.cpp \
../src/Lab2.cpp \
../src/Lab3.cpp \
../src/Lab4.cpp \
../src/Lab5.cpp \
../src/Lab6.cpp \
../src/MinimumWalkFloydWarshall.cpp \
../src/NumberOfMinimumWalks.cpp \
../src/StronglyConnectedComponentsKosaraju.cpp \
../src/TopologicalSortingActivityByEdge.cpp \
../src/UndirectedGraph.cpp \
../src/VertexCover.cpp \
../src/WeightedDigraph.cpp 

OBJS += \
./src/AG.o \
./src/ApproximativelyDoubleVertexCover.o \
./src/BranchAndBoundVertexCover.o \
./src/ConnectedComponentsUndirectedGraphBFS.o \
./src/Digraph.o \
./src/Lab2.o \
./src/Lab3.o \
./src/Lab4.o \
./src/Lab5.o \
./src/Lab6.o \
./src/MinimumWalkFloydWarshall.o \
./src/NumberOfMinimumWalks.o \
./src/StronglyConnectedComponentsKosaraju.o \
./src/TopologicalSortingActivityByEdge.o \
./src/UndirectedGraph.o \
./src/VertexCover.o \
./src/WeightedDigraph.o 

CPP_DEPS += \
./src/AG.d \
./src/ApproximativelyDoubleVertexCover.d \
./src/BranchAndBoundVertexCover.d \
./src/ConnectedComponentsUndirectedGraphBFS.d \
./src/Digraph.d \
./src/Lab2.d \
./src/Lab3.d \
./src/Lab4.d \
./src/Lab5.d \
./src/Lab6.d \
./src/MinimumWalkFloydWarshall.d \
./src/NumberOfMinimumWalks.d \
./src/StronglyConnectedComponentsKosaraju.d \
./src/TopologicalSortingActivityByEdge.d \
./src/UndirectedGraph.d \
./src/VertexCover.d \
./src/WeightedDigraph.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/include/qt4 -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


