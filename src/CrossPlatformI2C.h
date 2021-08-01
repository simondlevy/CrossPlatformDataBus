/* 
   CrossPlatformI2C.h: Cross-platform function declarations

   Copyright (c) Simon D. Levy 2021

   MIT License
*/

#pragma once

#include <stdint.h>

#include "CrossPlatformI2C_Core.h"

void     cpi2c_close(uint8_t device);

uint8_t  cpi2c_readRegister(uint8_t address, uint16_t subAddress);

uint16_t cpi2c_readRegister_8_16(uint8_t address, uint8_t subAddress);

uint16_t cpi2c_readRegister_16(uint8_t address, uint16_t subAddress);

bool cpi2c_writeRegister(uint8_t address, uint8_t subAddress, uint8_t data);

bool cpi2c_writeRegisters(uint8_t address,
                          uint8_t subAddress,
                          uint8_t count,
                          uint8_t * src);

bool cpi2c_writeRegister_16_8(uint8_t address,
                              uint16_t subAddress,
                              uint8_t data);

bool cpi2c_writeRegister_16_16(uint8_t address,
                               uint16_t subAddress,
                               uint16_t data);

bool cpi2c_writeRegisters_16(uint8_t address,
                             uint8_t subAddress,
                             uint8_t count,
                             uint8_t * src);

void cpi2c_beginTransmission(uint8_t address);

uint8_t cpi2c_write(uint8_t data);

uint8_t cpi2c_read(void);

uint8_t cpi2c_endTransmission(bool stop=true);

uint8_t cpi2c_requestFrom(uint8_t address, uint8_t count);

uint8_t cpi2c_available(void);
