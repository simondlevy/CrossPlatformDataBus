/* 
   I2CDevI2C.cpp: Linux i2cdev implementation of cross-platform I2C routines

   Copyright (c) 2021 Simon D. Levy

   MIT License
*/

#include "CrossPlatformI2C.h"

#include <linux/i2c-dev.h>
extern "C" {
#include <i2c/smbus.h>
}
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

uint8_t cpi2c_open(uint8_t address, uint8_t bus)
{
    // Attempt to open /dev/i2c-<NUMBER>
    char fname[32];
    sprintf(fname,"/dev/i2c-%d", bus);
    int fd = open(fname, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Unable to open %s\n", fname);
        exit(1);
    }

    // Attempt to make this device an I2C slave
    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        fprintf(stderr, "ioctl failed on %s\n", fname);
        exit(1);
    }

    return fd;
}

void cpi2c_close(uint8_t device)
{
    close(device);
}

bool cpi2c_writeRegister(uint8_t device, uint8_t subAddress, uint8_t data)
{
    return i2c_smbus_write_byte_data(device, subAddress, data) == 0;
}

void cpi2c_readRegisters(uint8_t device, uint8_t subAddress, uint8_t count, uint8_t * dest)
{
    for (uint8_t k=0; k<count; ++k) {
        i2c_smbus_write_byte(device, subAddress+k);
        dest[k] = i2c_smbus_read_byte(device);
    }
}

bool cpi2c_writeRegister_16_8(uint8_t device, uint16_t subAddress, uint8_t data)
{
    return i2c_smbus_write_byte_data(device, subAddress, data) == 0;
}

uint16_t cpi2c_readRegister_8_16(uint8_t device, uint8_t subAddress)
{
    i2c_smbus_write_byte(device, subAddress);
    return i2c_smbus_read_word_data(device, subAddress);
}
