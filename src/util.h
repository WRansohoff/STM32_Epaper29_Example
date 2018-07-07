#ifndef _VVC_UTIL_H
#define _VVC_UTIL_H

#include "global.h"
#include "sspi.h"

/* Utility macro definitions. */
#define REVERSE_BYTE(a) (((a & 0x01) << 7) | ((a & 0x02) << 5) |\
                         ((a & 0x04) << 3) | ((a & 0x08) << 1) |\
                         ((a & 0x10) >> 1) | ((a & 0x20) >> 3) |\
                         ((a & 0x40) >> 5) | ((a & 0x80) >> 7))

/* Utility method declarations. */
void epd29_hspi_init(SPI_TypeDef *SPIx);
void delay_cycles(uint32_t cyc);

/* Framebuffer drawing methods. */
void epd_draw_px(int x, int y, uint8_t c);
void epd_draw_hline(int x, int y, int w, uint8_t c);
void epd_draw_vline(int x, int y, int h, uint8_t c);
void epd_draw_rect(int x, int y, int w, int h, int o, uint8_t c);
void epd_draw_buf(int x, int y, int w, int h, uint8_t c, const uint8_t* buf);

#endif
