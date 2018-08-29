/* 
   WiringPiSPI.cpp: WiringPi implementation of cross-platform SPI routines

   This file is part of CrossPlatformSPI.

   CrossPlatformSPI is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CrossPlatformSPI is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with CrossPlatformSPI.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CrossPlatformSPI.h"

#include <wiringPi.h>
#include <wiringPiSPI.h>

void cpspi_writeRegister(uint8_t subAddress, uint8_t data)
{
    uint8_t buff2[2];
    buff2[0] = subAddress;
    buff2[1] = data;
    wiringPiSPIDataRW(1, &buff2[0], 2);
}

void cpspi_readRegisters(uint8_t subAddress, uint8_t count, uint8_t * dest)
{
     uint8_t buff2[2];
     for (uint8_t i=0; i<count; ++i) {
         buff2[0] = (subAddress+i) | 0x80;
         buff2[1] = 0;
         wiringPiSPIDataRW(1, &buff2[0], 2);
         dest[i] = buff2[1];
     }
}
