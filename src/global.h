#ifndef _VVC_GLOBAL_H
#define _VVC_GLOBAL_H

#include <stdint.h>
#ifdef VVC_F0
  #include "stm32f0xx.h"
#elif  VVC_L0
  #include "stm32l0xx.h"
#endif

// Global macro defines.
// Define the size of the epaper display, in pixels.
#define EPD_W     (128)
#define EPD_H     (296)
#define EPD_BYTES ((EPD_W * EPD_H) / 8)

// Define GPIOB pin mappings for software '4-wire' SPI.
#define PB_MOSI (5)
#define PB_SCK  (3)
// ('Data/Command' pin.)
#define PB_DC   (4)
// ('Busy' pin - when low, don't send commands/data.)
#define PA_BUSY (11)
#define PA_CS   (0)
#define PA_RST  (8)

// Global defines.
uint32_t core_clock_hz;

// Framebuffer for the EPaper display. (2.9", 128x296)
// Note: This will not fit in RAM if there is <4KB available.
// This means that some 'access line' chips like the
// STM32F03xK6 won't work. Recommend at least 8KB of RAM on-chip.
uint8_t epd_buf[EPD_BYTES];

// Define logo dfinitions.
#define VVC_LOGO_W (80)
#define VVC_LOGO_H (256)
#define VVC_LOGO_L ((VVC_LOGO_W * VVC_LOGO_H) / 8)
extern const uint8_t VVC_LOGO_BUF[VVC_LOGO_L];

#endif
