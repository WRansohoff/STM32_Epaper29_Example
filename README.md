# Overview

This is a minimal project to demonstrate how to support multiple microcontroller cores in a single project, with minimal code changes. The project supports both Cortex-M0 'STM32F031K6' and Cortex-M0+ 'STM32L031K6' chips.

The example project initializes pin B1 as input with a built-in pull-up resistor; it listens for button presses on a button connected to ground. pin B3 is set to push-pull output, and it is connected to a built-in LED on ST's "Nucleo" board.

# Uploading and Debugging

A Makefile is provided, and I've tested the program with 'Nucleo-32' boards for both chips. To upload the resulting program, you can use your choice of uploader/debugger. I use GDB and Texane's "stlink" project:

https://github.com/texane/stlink

It's a fairly simple process to upload and debug a program:

1. Plug your board in - for ST's Nucleo boards, you can just use an ordinary micro-USB cable.

2. Enter 'st-util' in a terminal window after installing the utilities linked above. You should see some general information printed about your chip.

3. Run `arm-none-eabi-gdb main.elf` (or whatever your file is called, if it's not 'main.elf')

4. Point GDB to the port opened by 'st-util' - usually 4242: `target extended-remote :4242`

5. Enter `load` to upload your program.

6. You're code is uploaded! Enter `continue` to start it running, and hit `ctrl+C` a few times (followed by 'y' for 'yes') to interrupt it once it's started.

Once the code is uploaded, you can more or less treat the GDB debugging session like you would any other C/C++ program in GDB. You can set breakpoints, step through the code with `s`/`si`/`n`/`ni`/etc, inspect variables or memory addresses, and so on.
