/* 
   MPU_WhoAmI.ino: Check "Who am I?" register of Invensense MPU sensors

   Copyright (C) 2018 Simon D. Levy 

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

#ifdef __MK20DX256__
#include <i2c_t3.h>
#define NOSTOP I2C_NOSTOP
#else
#include <Wire.h>
#define NOSTOP false
#endif

static const uint8_t  MPU_ADDRESS  = 0x68;
static const uint8_t  MPU_WHO_AM_I = 0x75;
 
void setup()
{
#ifdef __MK20DX256__
    Wire.begin(I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_EXT, I2C_RATE_400);
#else
    Wire.begin();
#endif

    delay(100);

    Serial.begin(115200);
}

void loop()
{  
    delay(1000);
}
