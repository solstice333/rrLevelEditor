################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/gameSaves/Dot.cpp \
../src/test/gameSaves/SDLGameSavesTest.cpp \
../src/test/gameSaves/SimpleLoadSave.cpp 

OBJS += \
./src/test/gameSaves/Dot.o \
./src/test/gameSaves/SDLGameSavesTest.o \
./src/test/gameSaves/SimpleLoadSave.o 

CPP_DEPS += \
./src/test/gameSaves/Dot.d \
./src/test/gameSaves/SDLGameSavesTest.d \
./src/test/gameSaves/SimpleLoadSave.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/gameSaves/%.o: ../src/test/gameSaves/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"D:\SDL-1.2.15\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


