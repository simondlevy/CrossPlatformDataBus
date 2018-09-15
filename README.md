This library supports communication with I<sup>2</sup>C and SPI devices on today's
popular microcontroller and single-board-computer platforms:

* Arduino 
* Teensy
* Raspberry Pi
* NVIDIA Jetson 

The project is similar in spirit to Jeff Rowberg's [I<sup>2</sup>Cdevlib](https://www.i2cdevlib.com), but unlike
I<sup>2</sup>Cdevlib, CrossPlatformDataBus does not provide code for particular I<sup>2</sup>C devices.  Instead,
we provide a separate repository with support for each such sensor, which works
together with CrossPlatformDataBus to help you use that sensor.  Currently
supported sensors include:

* [EM7180](https://github.com/simondlevy/EM7180) SENtral Sensor Fusion Solution from Tlera Corp

* [LIS2MDL](https://github.com/simondlevy/LIS2MDL) magnetometer from STMicroelectronics

* [LPS22HB](https://github.com/simondlevy/LPS22HB) barometer from STMicroelectronics

* [LSM6DSM](https://github.com/simondlevy/LSM6DSM) intertial measurement unit from STMicroelectronics

* [MB1242](https://github.com/simondlevy/MB1242) ultrasonic rangefinder from MaxBotix

* [MPU](https://github.com/simondlevy/MPU) line of intertial measurement units from Invensense

* [MS5637](https://github.com/simondlevy/MS5637) barometer from TE / Measurement Specialties

* [VL53L1X](https://github.com/simondlevy/VL53L1X) time-of-flight rangefinder from STMicroelectronics (partial support)

We've set up the library as a standard Arduino library, with <b>src</b> and <b>examples</b> folders.  To keep things
simple, we provide a single example sketch 
[MPU_WhoAmI.ino](https://github.com/simondlevy/CrossPlatformDataBus/blob/master/examples/MPU_WhoAmI/MPU_WhoAmI.ino),
which reads from the &ldquo;Who am I&rdquo; register (0x75) of an Invensense MPU Internal Measurement Unit
(device address 0x68).  Success at reading from this register results in a reported value of 0x71.  Arduino users who
have such a sensor can just open the <b>File/Examples/CrossPlatformDataBus</b> menu item to try out the sketch.

RaspberryPi users should download and install WiringPi, then cd to
<b>CrossPlatformDataBus/extras/i2c/wiringpi/examples</b>, and run make to build the example. 
You may have to run this examples as root; i.e., <tt>sudo ./MPU_WhoAmI</tt>.

Users of NVIDIA Jetson and other Linux-based boards can cd to <b>CrossPlatformDataBus/extras/i2c/i2cdev/examples<b>,
and run make.
You may have to run this examples as root; i.e., <tt>sudo ./MPU_WhoAmI</tt>.
