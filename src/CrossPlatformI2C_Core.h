/* 
   CrossPlatformI2C_core.h: Declarations f core cross-platform I2C functions

   Copyright (c) Simon D. Levy 2021

   MIT License
*/

#pragma once

#include <stdint.h>

void    cpi2c_readRegisters(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dst);

bool    cpi2c_writeRegister(uint8_t address, uint8_t subAddress, uint8_t data);

bool    cpi2c_writeRegisters(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * src);

uint8_t cpi2c_open(uint8_t address, uint8_t bus=1);
