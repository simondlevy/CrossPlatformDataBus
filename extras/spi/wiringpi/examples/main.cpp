/* 
   main.pp: Generic main() for caling Arduino-style setup(), loop()

   Copyright (c) 2021 Simon D. Levy

   MIT License
 */

extern void setup(), loop();

int main(int argc, char ** argv)
{
    setup();

    while (true) {
        loop();
    }
}
