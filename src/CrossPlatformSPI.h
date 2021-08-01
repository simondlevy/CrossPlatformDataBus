/* 
   CrossPlatformSPI.h: Cross-platform SPI support

   Copyright (c) Simon D. Levy 2021

   MIT License
*/

#pragma once

#include <stdint.h>

bool cpspi_writeRegister(uint8_t subAddress, uint8_t data);

bool cpspi_readRegisters(uint8_t subAddress, uint8_t count, uint8_t * dst);

bool cpspi_transfer(const uint8_t * send, uint8_t * recv, uint8_t count);
