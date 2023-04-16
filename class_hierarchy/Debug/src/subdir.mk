################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Circle.cpp \
../src/MinusTriRect.cpp \
../src/Rectangle.cpp \
../src/TriOnRect.cpp \
../src/Triangle.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/Circle.d \
./src/MinusTriRect.d \
./src/Rectangle.d \
./src/TriOnRect.d \
./src/Triangle.d \
./src/main.d 

OBJS += \
./src/Circle.o \
./src/MinusTriRect.o \
./src/Rectangle.o \
./src/TriOnRect.o \
./src/Triangle.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/george/git/OOP/class_hierarchy/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Circle.d ./src/Circle.o ./src/MinusTriRect.d ./src/MinusTriRect.o ./src/Rectangle.d ./src/Rectangle.o ./src/TriOnRect.d ./src/TriOnRect.o ./src/Triangle.d ./src/Triangle.o ./src/main.d ./src/main.o

.PHONY: clean-src

