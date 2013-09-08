################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/alphaBlending/SDLAlphaBlending.cpp 

OBJS += \
./src/test/alphaBlending/SDLAlphaBlending.o 

CPP_DEPS += \
./src/test/alphaBlending/SDLAlphaBlending.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/alphaBlending/%.o: ../src/test/alphaBlending/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"D:\SDL-1.2.15\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


