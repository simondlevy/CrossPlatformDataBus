# 
# Makefile for CrossPlatformDataBus i2cdev examples
#
# Copyright (c) 2021 Simon D. Levy
#
# MIT License
  
ALL = MPU_WhoAmI

INC = ../../../../src/
SRC = ../src

all: $(ALL)

MPU_WhoAmI: MPU_WhoAmI.o I2CDevI2C.o main.o
	g++ -std=c++11 -o MPU_WhoAmI MPU_WhoAmI.o I2CDevI2C.o main.o -li2c

MPU_WhoAmI.o: MPU_WhoAmI.cpp 
	g++ -std=c++11 -Wall -I$(SRC) -I$(INC) -c MPU_WhoAmI.cpp

I2CDevI2C.o: $(SRC)/I2CDevI2C.cpp 
	g++ -std=c++11 -Wall -I$(SRC) -I$(INC) -c $(SRC)/I2CDevI2C.cpp

main.o: main.cpp 
	g++ -std=c++11 -Wall -c main.cpp

run: MPU_WhoAmI
	./MPU_WhoAmI

edit:
	vim MPU_WhoAmI.cpp

clean:
	rm -f $(ALL) *.o *~
