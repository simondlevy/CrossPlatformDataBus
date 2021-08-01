/* 
   MPU_WhoAmI.ino: Check "Who am I?" register of Invensense MPU sensors

   Copyright (c) 2021 Simon D. Levy 

   MIT License
 */

#include "CrossPlatformI2C_Core.h"

#if defined(TEENSYDUINO)
#include <i2c_t3.h>
#define NOSTOP I2C_NOSTOP
#else
#include <Wire.h>
#define NOSTOP false
#endif

static const uint8_t  MPU_ADDRESS = 0x68;
static const uint8_t  MPU_WHOAMI  = 0x75;

static uint8_t device;
 
void setup()
{
#if defined(TEENSYDUINO)
    Wire.begin(I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_INT, 400000);
#else
    Wire.begin();
#endif

    delay(100);

    Serial.begin(115200);

    device = cpi2c_open(MPU_ADDRESS);

    delay(100);
}

void loop()
{  

    uint8_t data;
    cpi2c_readRegisters(device, MPU_WHOAMI, 1, &data);
    Serial.print("I am 0x");
    Serial.println(data, HEX);

    delay(1000);
}
