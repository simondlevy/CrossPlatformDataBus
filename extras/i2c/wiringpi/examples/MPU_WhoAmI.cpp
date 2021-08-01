/* 
   MPU_WhoAmI.cpp: Check "Who am I?" register of Invensense MPU sensors

   Copyright (c) 2021 Simon D. Levy

   MIT License
 */

#include "CrossPlatformI2C_Core.h"
#include <wiringPi.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t  MPU_ADDRESS = 0x68;
static const uint8_t  MPU_WHOAMI  = 0x75;

static uint8_t device;

extern void delay(uint32_t msec);

void setup()
{
    // Set up the wiringPi library
    if (wiringPiSetup () < 0) {
        fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno));
        exit(1);
    }

    device = cpi2c_open(MPU_ADDRESS);

    delay(100);
}

void loop()
{  
    uint8_t data;
    cpi2c_readRegisters(device, MPU_WHOAMI, 1, &data);
    printf("I am 0x%X\n", data);

    delay(1000);
}
