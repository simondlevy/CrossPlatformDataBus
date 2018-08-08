/* 

   ArduinoI2C.cpp: Arduino implementation of cross-platform I^C routines

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

#include <stdint.h>

#if defined(TEENSYDUINO)
#include <i2c_t3.h>
#define NOSTOP I2C_NOSTOP
#else
#include <Wire.h>
#define NOSTOP false
#endif

uint8_t cpi2c_open(uint8_t address, uint8_t bus)
{
    (void)bus;
    return address;
}

void cpi2c_close(uint8_t device)
{
    (void)device;
}

bool cpi2c_writeRegister(uint8_t address, uint8_t subAddress, uint8_t data)
{
    Wire.beginTransmission(address);    // Initialize the Tx buffer
    Wire.write(subAddress);             // Put slave register address in Tx buffer
    Wire.write(data);                   // Put data in Tx buffer
    return Wire.endTransmission() == 0; // Send the Tx buffer
}

void cpi2c_readRegisters(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest)
{  
    Wire.beginTransmission(address);   // Initialize the Tx buffer
    Wire.write(subAddress);            // Put slave register address in Tx buffer
    Wire.endTransmission(NOSTOP);      // Send the Tx buffer, but send a restart to keep connection alive
    uint8_t i = 0;
    Wire.requestFrom(address, count);  // Read bytes from slave register address 
    while (Wire.available()) {
        dest[i++] = Wire.read(); 
    } 
}

uint8_t cpi2c_readRegister(uint8_t address, uint16_t subAddress)
{
    Wire.beginTransmission(address);
    Wire.write(subAddress >> 8); //MSB
    Wire.write(subAddress & 0xFF); //LSB
    if (Wire.endTransmission() != 0) //Send a restart command. Do not release bus.
        return 0; //Sensor did not ACK

    Wire.requestFrom((uint8_t)address, (uint8_t)1);
    if (Wire.available())
        return (Wire.read());
    
    return 0; //Error: Sensor did not respond
}

uint16_t cpi2c_readRegister_8_16(uint8_t address, uint8_t subAddress)
{
    Wire.beginTransmission(address);
    Wire.write(subAddress); 
    if (Wire.endTransmission() != 0) //Send a restart command. Do not release bus.
        return 0; //Sensor did not ACK

    Wire.requestFrom((uint8_t)address, (uint8_t)2);
    if (Wire.available())
    {
        uint8_t lsb = Wire.read();
        uint8_t msb = Wire.read();
        return ((uint16_t)msb << 8 | lsb);
    }
    
    return 0; //Error: Sensor did not respond
}

uint16_t cpi2c_readRegister_16(uint8_t address, uint16_t subAddress)
{
    Wire.beginTransmission(address);
    Wire.write(subAddress >> 8); //MSB
    Wire.write(subAddress & 0xFF); //LSB
    if (Wire.endTransmission() != 0) //Send a restart command. Do not release bus.
        return 0; //Sensor did not ACK

    Wire.requestFrom((uint8_t)address, (uint8_t)2);
    if (Wire.available())
    {
        uint8_t msb = Wire.read();
        uint8_t lsb = Wire.read();
        return ((uint16_t)msb << 8 | lsb);
    }
    
    return 0; //Error: Sensor did not respond
}

bool cpi2c_writeRegister_16_8(uint8_t address, uint16_t subAddress, uint8_t data)
{
   
    Wire.beginTransmission(address);
    Wire.write(subAddress >> 8); //MSB
    Wire.write(subAddress & 0xFF); //LSB
    Wire.write(data);
    if (Wire.endTransmission() != 0)
        return false; //Error: Sensor did not ACK
  
    return true; // success
}

bool cpi2c_writeRegister_16_16(uint8_t address, uint16_t subAddress, uint16_t data)
{
    Wire.beginTransmission(address);
    Wire.write(subAddress >> 8); //MSB
    Wire.write(subAddress & 0xFF); //LSB
    Wire.write(data >> 8); //MSB
    Wire.write(data & 0xFF); //LSB
    if (Wire.endTransmission() != 0)
        return 0; //Error: Sensor did not ACK
    
    return true; // success
}

void cpi2c_beginTransmission(uint8_t address)
{
    Wire.beginTransmission(address);
}

uint8_t cpi2c_write(uint8_t data)
{
    return Wire.write(data);
}

uint8_t cpi2c_read(void)
{
    return Wire.read();
}

uint8_t cpi2c_endTransmission(bool stop)
{
    return Wire.endTransmission(stop);
}

uint8_t  cpi2c_requestFrom(uint8_t address, uint8_t count)
{
    return Wire.requestFrom(address, count);
}

uint8_t  cpi2c_available(void)
{
    return Wire.available();
}
