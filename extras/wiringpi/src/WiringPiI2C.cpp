/* 
   WiringPiI2C.cpp: WiringPi implementation of cross-platform I2C routines

   This file is part of CrossPlatformI2C.

   CrossPlatformI2C is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CrossPlatformI2C is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with CrossPlatformI2C.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CrossPlatformI2C.h"

#include <wiringPi.h>
#include <wiringPiI2C.h>

uint8_t cpi2c_open(uint8_t address, uint8_t bus)
{
    (void)bus;
    return (uint8_t)wiringPiI2CSetup(address);
}

bool cpi2c_writeRegister(uint8_t address, uint8_t subAddress, uint8_t data)
{
	return wiringPiI2CWriteReg8(address, subAddress, data) == 0;
}

uint16_t cpi2c_readRegister_8_16(uint8_t address, uint8_t subAddress)
{
    return wiringPiI2CReadReg16 (address, subAddress);
}

void cpi2c_readRegisters(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest)
{
    for (uint8_t i=0; i<count; ++i) {
        dest[i] = wiringPiI2CReadReg8(address, subAddress+i);
    }
}

bool cpi2c_writeRegister_16_8(uint8_t address, uint16_t subAddress, uint8_t data)
{
    return wiringPiI2CWriteReg8 (address, subAddress, data) > 0;
}
