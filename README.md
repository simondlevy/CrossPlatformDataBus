This library supports communication with I<sup>2</sup>C devices on today's
popular micrcontroller and single-board-computer platforms:

* Arduino 
* Teensy
* Raspberry Pi
* NVIDIA Jetson 

The project is similar in spirit to Jeff Rowberg's [I<sup>2</sup>Cdevlib](https://www.i2cdevlib.com), but unlike
I<sup>2</sup>Cdevlib, CrossPlatformI2C does not provide code for particular I<sup>2</sup>C devices.  Instead,
we provide a separate repository with support for each such sensor, which works together with CrossPlatformI2C to help
you use that sensor.

We've set up the library as a standard Arduino library, with <b>src</b> and <b>examples</b> folders.  To keep things
simple, we provide a single example sketch 
[MPU_WhoAmI.ino](https://github.com/simondlevy/CrossPlatformI2C/blob/master/examples/MPU_WhoAmI/MPU_WhoAmI.ino),
which reads from the &ldquo;Who am I&rdquo; register (0x75) of an Invensense MPU Internal Measurement Unit
(address 0x68).  Success at reading from this register results in a reported value of 0x71.  Arduino users who
have such a sensor can just open the <b>File/CrossPlatformI2C/example</b> menu item to try out the sketch.
RaspberryPi users should download and install WiringPi, then cd to
CrossPlatformI2C/extras/wiringpi/examples, and run make to build the example. 
Users of NVIDIA Jetson and other Linux-based boards can cd to CrossPlatformI2C/extras/i2cdev/examples, and run make.
You may have to run this examples as root; i.e., <b>sudo ./MPU_WhoAmI</tt>.
