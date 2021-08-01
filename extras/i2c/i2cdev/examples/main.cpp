/* 
   main.pp: Generic main() for caling Arduino-style setup(), loop()

   Copyright (c) 2021 Simon D. Levy

   MIT License
 */

#include <unistd.h>
#include <stdint.h>

void delay(uint32_t msec)
{
    usleep(msec*1000);
}

extern void setup(), loop();

int main(int argc, char ** argv)
{
    setup();

    while (true) {
        loop();
    }
}
