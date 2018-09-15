/* 
   timing.h: Arduino-style delay(), micros() for Linux

   Copyright (c) 2018 Simon D. Levy

   This file is part of CrossPlatformDataBus.

   CrossPlatformDataBus is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CrossPlatformDataBus is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with CrossPlatformDataBus.  If not, see <http://www.gnu.org/licenses/>.
*/

void delay(unsigned int msec);

unsigned int millis(void);

unsigned int micros(void);
