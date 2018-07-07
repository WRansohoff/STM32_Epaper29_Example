# Overview

This is a minimal project to demonstrate how to use the STM32's SPI peripheral to drive a 2.9" epaper display from Waveshare.

# Building and Flashing

A Makefile is provided, and I've tested the program with 'Nucleo-32' boards for STM32L031K6 and STM32F042K6 chips. To upload the resulting program, you can use your choice of uploader/debugger. I use GDB and Texane's "stlink" project:

https://github.com/texane/stlink

It's a fairly simple process to upload a program:

1. Plug your board in - for ST's Nucleo boards, you can just use an ordinary micro-USB cable.

2. Make sure the correct MCU core is un-commented in the Makefile, and enter `make` to build the project binary.

3. Upload the binary image: `st-flash write main.bin 0x08000000`
