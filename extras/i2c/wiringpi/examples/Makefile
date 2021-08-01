# Makefile for CrossPlatformDataBus WiringPi examples
#
# Copyright (c) 2021 Simon D. Levy
#
# MIT License
  
ALL = MPU_WhoAmI

INC = ../../../../src
SRC = ../src

all: $(ALL)

MPU_WhoAmI: MPU_WhoAmI.o WiringPiI2C.o main.o
	g++ -std=c++11 -o MPU_WhoAmI MPU_WhoAmI.o WiringPiI2C.o main.o -lwiringPi

MPU_WhoAmI.o: MPU_WhoAmI.cpp 
	g++ -std=c++11 -Wall -I$(SRC) -I$(INC) -c MPU_WhoAmI.cpp

WiringPiI2C.o: $(SRC)/WiringPiI2C.cpp 
	g++ -std=c++11 -Wall -I$(SRC) -I$(INC) -c $(SRC)/WiringPiI2C.cpp

main.o: ../../../common/main.cpp 
	g++ -std=c++11 -Wall -c ../../../common/main.cpp

run: MPU_WhoAmI
	./MPU_WhoAmI

edit:
	vim MPU_WhoAmI.cpp

clean:
	rm -f $(ALL) *.o *~
