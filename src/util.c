#include "util.h"

// Initialize a 2.9" EPaper display module.
void epd29_hspi_init(SPI_TypeDef *SPIx) {
  // Send initialization commands.
  // 'Driver output control'
  hspi_cmd(SPIx, 0x01);
  //hspi_w16(SPIx, (uint16_t)(EPD_H));
  hspi_w8(SPIx, ((EPD_H-1) % 256));
  hspi_w8(SPIx, ((EPD_H-1) / 256));
  hspi_w8(SPIx, 0x00);
  // 'Booster soft start control'
  hspi_cmd(SPIx, 0x0C);
  hspi_w8(SPIx, 0xD7);
  hspi_w8(SPIx, 0xD6);
  hspi_w8(SPIx, 0x9D);
  // 'Write VCOM register'
  hspi_cmd(SPIx, 0x2C);
  hspi_w8(SPIx, 0xA8);
  // 'Set dummy line period'
  hspi_cmd(SPIx, 0x3A);
  hspi_w8(SPIx, 0x1A);
  // 'Set gate time'
  hspi_cmd(SPIx, 0x3B);
  hspi_w8(SPIx, 0x08);
  // 'Set data entry mode setting'
  hspi_cmd(SPIx, 0x11);
  hspi_w8(SPIx, 0x03);
  // 'Set RAM area'
  hspi_cmd(SPIx, 0x44);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, (uint8_t)((EPD_W-1)/8));
  hspi_cmd(SPIx, 0x45);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, ((EPD_H-1) % 256));
  hspi_w8(SPIx, ((EPD_H-1) / 256));
  // 'Set RAM pointer'
  hspi_cmd(SPIx, 0x4E);
  hspi_w8(SPIx, 0x00);
  hspi_cmd(SPIx, 0x4F);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);

  // 'Set Look-Up Table' settings...all 30 bytes of them.
  hspi_cmd(SPIx, 0x32);
  hspi_w8(SPIx, 0x50);
  hspi_w8(SPIx, 0xAA);
  hspi_w8(SPIx, 0x55);
  hspi_w8(SPIx, 0xAA);
  hspi_w8(SPIx, 0x11);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0xFF);
  hspi_w8(SPIx, 0xFF);
  hspi_w8(SPIx, 0x1F);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  hspi_w8(SPIx, 0x00);
  // (These are for a full-display update?)
  /*
  hspi_w16(SPIx, 0x0202);
  hspi_w16(SPIx, 0x0111);
  hspi_w16(SPIx, 0x1212);
  hspi_w16(SPIx, 0x2222);
  hspi_w16(SPIx, 0x6669);
  hspi_w16(SPIx, 0x6959);
  hspi_w16(SPIx, 0x5899);
  hspi_w16(SPIx, 0x9988);
  hspi_w16(SPIx, 0x0000);
  hspi_w16(SPIx, 0x0000);
  hspi_w16(SPIx, 0xF8B4);
  hspi_w16(SPIx, 0x1351);
  hspi_w16(SPIx, 0x3551);
  hspi_w16(SPIx, 0x5119);
  hspi_w16(SPIx, 0x0100);
  */
  // 'Power on.'
  hspi_cmd(SPI1, 0x22);
  hspi_w8(SPI1, 0xC0);
  hspi_cmd(SPI1, 0x20);
  // Wait for the peripheral to finish sending.
  while ((SPI1->SR & SPI_SR_BSY)) {};
}

// Simple delay method, with instructions not to optimize.
// It doesn't accurately delay a precise # of cycles,
// it's just a rough scale.
void __attribute__((optimize("O0"))) delay_cycles(uint32_t cyc) {
  uint32_t d_i;
  for (d_i = 0; d_i < cyc; ++d_i) {
    asm("NOP");
  }
}

/*
 * Framebuffer drawing methods.
 */
/*
 * Draw a single pixel to the epaper framebuffer.
 * 'C' indicates the color. For b/w displays,
 * 0 is 'black' and >= 1 is 'white'.
 */
inline void epd_draw_px(int x, int y, uint8_t c) {
  if (c) {
    epd_buf[(y * 16) + (x / 8)] |=  (1 << (7-(x % 8)));
  }
  else {
    epd_buf[(y * 16) + (x / 8)] &= ~(1 << (7-(x % 8)));
  }
}

/*
 * Draw a horizontal line to the epaper framebuffer.
 */
void epd_draw_hline(int x, int y, int w, uint8_t c) {
  // Draw pixels until the 'x' coordinate is byte-aligned.
  while (x % 8 != 0) {
    epd_draw_px(x, y, c);
    ++x;
    --w;
  }
  // Draw one byte at a time.
  while (w >= 8) {
    if (c) {
      epd_buf[(y * 16) + (x / 8)] = 0xFF;
    }
    else {
      epd_buf[(y * 16) + (x / 8)] = 0x00;
    }
    w -= 8;
    x += 8;
  }
  // Draw trailing pixels.
  while (w >= 0) {
    epd_draw_px(x, y, c);
    ++x;
    --w;
  }
}

/*
 * Draw a vertical line to the epaper framebuffer.
 */
void epd_draw_vline(int x, int y, int h, uint8_t c) {
  // Draw the appropriate bitmask down the vertical length.
  while (h >= 0) {
    epd_draw_px(x, y, c);
    ++y;
    --h;
  }
}

/*
 * Draw a rectangle to the epaper framebuffer.
 */
void epd_draw_rect(int x, int y, int w, int h, int o, uint8_t c) {
  // The 'o' argument lets the user draw an outline around the
  // area, of 'o' pixels. If 'o' is <= 0, the full area is filled.
  if (o <= 0) {
    // If the width is > the height, draw horizontal lines.
    if (w > h) {
      while (h >= 0) {
        epd_draw_hline(x, y, w, c);
        ++y;
        --h;
      }
    }
    // Otherwise, draw vertical lines.
    else {
      while (w >= 0) {
        epd_draw_vline(x, y, h, c);
        ++x;
        --w;
      }
    }
  }
  else {
    // Draw an outline.
    while (o > 0) {
      // Top.
      epd_draw_hline(x, (y + (o - 1)), w, c);
      // Bottom.
      epd_draw_hline(x, (y + h - (o - 1)), w, c);
      // Left.
      epd_draw_vline((x + (o - 1)), y, h, c);
      // Right.
      epd_draw_vline((x + w - (o - 1)), y, h, c);
      --o;
    }
  }
}

/*
 * Draw a buffered image to the framebuffer.
 * For simplicity, this currently rounds the 'x' coordinate
 * off to a byte boundary.
 */
void epd_draw_buf(int x, int y, int w, int h, uint8_t c, const uint8_t* buf) {
  int pos = (y * 16) + (x / 8);
  int offset = 0;
  int x_iter;
  int y_iter;
  for (y_iter = y; y_iter < (y + h); ++y_iter) {
    for (x_iter = x/8; x_iter < (x/8 + w); ++x_iter) {
      if (c) {
        epd_buf[pos] = REVERSE_BYTE(buf[offset]);
      }
      else {
        epd_buf[pos] = ~(REVERSE_BYTE(buf[offset]));
      }
      ++offset;
      ++pos;
    }
    pos = (y_iter * 16) + (x / 8);
  }
}
