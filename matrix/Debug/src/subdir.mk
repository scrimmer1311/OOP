################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Matrix.cpp \
../src/Matrix_exc.cpp \
../src/main.cpp \
../src/matrix_assign_elem.cpp 

CPP_DEPS += \
./src/Matrix.d \
./src/Matrix_exc.d \
./src/main.d \
./src/matrix_assign_elem.d 

OBJS += \
./src/Matrix.o \
./src/Matrix_exc.o \
./src/main.o \
./src/matrix_assign_elem.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Matrix.d ./src/Matrix.o ./src/Matrix_exc.d ./src/Matrix_exc.o ./src/main.d ./src/main.o ./src/matrix_assign_elem.d ./src/matrix_assign_elem.o

.PHONY: clean-src

