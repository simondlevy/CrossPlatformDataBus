/* 
   errmsg.cpp: error-handling code for CrossPlatformDataBus

   Copyright (c) 2021 Simon D. Levy

   MIT License
*/

#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void errmsg(const char * errmsg) 
{
    fprintf(stderr, "%s\n", errmsg);
    exit(1);
}
