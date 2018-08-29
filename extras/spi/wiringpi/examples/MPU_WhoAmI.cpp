/* 
   MPU_WhoAmI.cpp: Check "Who am I?" register of Invensense MPU sensors

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
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t  MPU_WHOAMI  = 0x75;

void setup()
{
    // Set up the wiringPi library
    if (wiringPiSetup () < 0) {
        fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno));
        exit(1);
    }

    // Start SPI on bus 1 at 400kHz
    wiringPiSPISetup(1, 400000);

    delay(100);
}

void loop()
{  
    uint8_t data;
    cpspi_readRegisters(MPU_WHOAMI, 1, &data);
    printf("I am 0x%X\n", data);

    delay(1000);
}
