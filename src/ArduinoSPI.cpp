/* 

   ArduinoSPI.cpp: Arduino implementation of cross-platform SPI routines

   Copyright (c) Simon D. Levy 2021

   MIT License
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

