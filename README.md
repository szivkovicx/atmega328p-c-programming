# Programming ATMEGA328P with C

This simple repo showcases a simple and minimalistic environment for development of ATMEGA328P microcontrollers. 

It features simple `Makefile` that compiles and builds `main.c` from `src` and uploads it to connected ATMEGA328P. `Makefile` compiles C file to elf, then converts elf to hex and uploads it via USB-TTL module directly to the board via TX/RX pins ( Bootloader required ). 

# Setup

## Arduino Uno

Setup is pretty simple here, just connecting the following pins ( in order of USB-TTL to Arduino):

* `5.0v` or `3.3v` -> `5.0v` or `3.3v`
* `GND` -> `GND`
* `TX` -> `RX`
* `RX` -> `TX`

## Standalone controller

Coming soon... This will probably require a bit better setup ( attaching crystal clock, adding a reset button etc... )

If you wish to run example from `src` folder, make sure to connect LED light ( with resistor or if you are using RGB LED it usually comes with resistor on the board ) to a pin 5 ( Digital ).

# Compiling and Uploading

Make sure you have the following installed:

* `avr-gcc`
* `avr-objcopy`
* `avrdude`
* `avr` library for C
* `make`

After you check that all of that is installed, do the following:

* Press the reset button
* Just run `make` in the command line
* Let go of the reset button

Uploading process should be pretty quick and straight-forward with all details logged.
