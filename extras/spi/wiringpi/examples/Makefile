# Makefile for CrossPlatformSPI WiringPi examples
#
# Copyright (c) 2018 Simon D. Levy
#
# This file is part of CrossPlatformSPI.
#
# CrossPlatformSPI is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# CrossPlatformSPI is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with CrossPlatformSPI.  If not, see <http://www.gnu.org/licenses/>.

  
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
