/* 
   timing.cpp: Arduino-style delay(), micros() for Linux

   Copyright (c) 2021 Simon D. Levy

   MIT License
*/

#include <unistd.h>
#include <time.h>

void delay(unsigned int msec)
{
    usleep(msec*1000);
}

unsigned int millis(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return 1000*ts.tv_sec + ts.tv_nsec/1000000;
}

unsigned int micros(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return 1000000*ts.tv_sec + ts.tv_nsec/1000;
}
