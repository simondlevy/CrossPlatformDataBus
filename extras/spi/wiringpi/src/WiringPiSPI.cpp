/* 
   WiringPiSPI.cpp: WiringPi implementation of cross-platform SPI routines

   Copyright (c) 2021 Simon D. Levy

   MIT License
*/

#include "CrossPlatformSPI.h"

#include <wiringPi.h>
#include <wiringPiSPI.h>

bool cpspi_writeRegister(uint8_t subAddress, uint8_t data)
{
    uint8_t buff2[2];
    buff2[0] = subAddress;
    buff2[1] = data;
    wiringPiSPIDataRW(1, &buff2[0], 2);
    return true; // XXX should check
}

bool cpspi_readRegisters(uint8_t subAddress, uint8_t count, uint8_t * dest)
{
     uint8_t buff2[2];
     for (uint8_t i=0; i<count; ++i) {
         buff2[0] = (subAddress+i) | 0x80;
         buff2[1] = 0;
         wiringPiSPIDataRW(1, &buff2[0], 2);
         dest[i] = buff2[1];
     }
    return true; // XXX should check
}
