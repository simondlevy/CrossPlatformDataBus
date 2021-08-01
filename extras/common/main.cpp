/* 
   main.pp: Generic main() for caling Arduino-style setup(), loop()

   Copyright (c) Simon D. Levy 2021

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
