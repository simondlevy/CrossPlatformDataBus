/* 

   ArduinoSPI.cpp: Arduino implementation of cross-platform SPI routines

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

bool cpspi_writeRegister(uint8_t subAddress, uint8_t data)
{
    // XXX stubbed for now
    (void)subAddress;
    (void)data;
    return false;
}

bool cpspi_readRegisters(uint8_t subAddress, uint8_t count, uint8_t * dst)
{  
    // XXX stubbed for now
    (void)subAddress;
    (void)count;
    (void)dst;
    return false;
}

