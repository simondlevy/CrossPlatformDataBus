/* 
   CrossPlatformSPI.h: Cross-platform SPI support

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

#pragma once

#include <stdint.h>

bool cpspi_writeRegister(uint8_t subAddress, uint8_t data);

bool cpspi_readRegisters(uint8_t subAddress, uint8_t count, uint8_t * dst);

bool cpspi_transfer(const uint8_t * send, uint8_t * recv, uint8_t count);
