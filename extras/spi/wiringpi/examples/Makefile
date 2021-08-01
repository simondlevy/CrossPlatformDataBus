# Makefile for CrossPlatformSPI WiringPi examples
#
# Copyright (c) 2021 Simon D. Levy
#
# MIT License

  
ALL = MPU_WhoAmI

INC = ../../../src
SRC = ../src

all: $(ALL)

MPU_WhoAmI: MPU_WhoAmI.o WiringPiSPI.o main.o
	g++ -std=c++11 -o MPU_WhoAmI MPU_WhoAmI.o WiringPiSPI.o main.o -lwiringPi

MPU_WhoAmI.o: MPU_WhoAmI.cpp 
	g++ -std=c++11 -Wall -I$(SRC) -I$(INC) -c MPU_WhoAmI.cpp

WiringPiSPI.o: $(SRC)/WiringPiSPI.cpp 
	g++ -std=c++11 -Wall -I$(SRC) -I$(INC) -c $(SRC)/WiringPiSPI.cpp

main.o: main.cpp 
	g++ -std=c++11 -Wall -c main.cpp

run: MPU_WhoAmI
	./MPU_WhoAmI

edit:
	vim MPU_WhoAmI.cpp

clean:
	rm -f $(ALL) *.o *~
