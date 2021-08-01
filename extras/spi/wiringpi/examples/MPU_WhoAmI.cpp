/* 
   MPU_WhoAmI.cpp: Check "Who am I?" register of Invensense MPU sensors

   Copyright (c) 2021 Simon D. Levy

   MIT License
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
