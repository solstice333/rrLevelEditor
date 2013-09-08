################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/windowResizing/SDLResizableWindowsAndWindowEvents.cpp \
../src/test/windowResizing/Window.cpp 

OBJS += \
./src/test/windowResizing/SDLResizableWindowsAndWindowEvents.o \
./src/test/windowResizing/Window.o 

CPP_DEPS += \
./src/test/windowResizing/SDLResizableWindowsAndWindowEvents.d \
./src/test/windowResizing/Window.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/windowResizing/%.o: ../src/test/windowResizing/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"D:\SDL-1.2.15\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


