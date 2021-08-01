/* 
   WiringPiI2C.cpp: WiringPi implementation of cross-platform I2C routines

   Copyright (c) 2021 Simon D. Levy

   MIT License
*/

#include "CrossPlatformI2C.h"

#include <wiringPi.h>
#include <wiringPiI2C.h>

uint8_t cpi2c_open(uint8_t address, uint8_t bus)
{
    (void)bus;
    return (uint8_t)wiringPiI2CSetup(address);
}


uint16_t cpi2c_readRegister_8_16(uint8_t address, uint8_t subAddress)
{
    return wiringPiI2CReadReg16 (address, subAddress);
}

void cpi2c_readRegisters(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dst)
{
    for (uint8_t k=0; k<count; ++k) {
        dst[k] = wiringPiI2CReadReg8(address, subAddress+k);
    }
}

bool cpi2c_writeRegister(uint8_t address, uint8_t subAddress, uint8_t data)
{
	return wiringPiI2CWriteReg8(address, subAddress, data) == 0;
}

bool cpi2c_writeRegister_16_8(uint8_t address, uint16_t subAddress, uint8_t data)
{
    return wiringPiI2CWriteReg8 (address, subAddress, data) > 0;
}


bool cpi2c_writeRegisters(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * src)
{
    for (uint8_t k=0; k<count; ++k) {
        if (!cpi2c_writeRegister(address, subAddress+k, src[k])) {
            return false;
        }
    }

    return true;
}
