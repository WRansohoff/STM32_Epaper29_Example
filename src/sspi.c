#include "sspi.h"

/*
 * Write a byte of data using software SPI. For each bit:
 * 1. Pull the clock pin low.
 * 2. Set the 'MOSI' data pin to the correct value.
 * 3. Pull the clock pin high.
 */
inline void sspi_w(uint8_t dat) {
  uint8_t sspi_i;
  // Send 8 bits, with the MSB first.
  for (sspi_i = 0x80; sspi_i != 0x00; sspi_i >>= 1) {
    GPIOB->ODR &= ~(1 << PB_SCK);
    if (dat & sspi_i) {
      GPIOB->ODR |=  (1 << PB_MOSI);
    }
    else {
      GPIOB->ODR &= ~(1 << PB_MOSI);
    }
    GPIOB->ODR |=  (1 << PB_SCK);
  }
}

/*
 * Write a 'Command byte' over software SPI.
 * "4-wire" SPI interfaces are common in devices like
 * screens. A 'Data/Command' pin determines whether
 * the SPI data is an instruction for the display,
 * or pixel data for the framebuffer RAM.
 * Here, '0' means 'Command' and '1' means 'Data'.
 */
inline void sspi_cmd(uint8_t cdat) {
  // Pull the 'D/C' pin low, write data, pull 'D/C' high.
  GPIOB->ODR &= ~(1 << PB_DC);
  sspi_w(cdat);
  GPIOB->ODR |=  (1 << PB_DC);
}

/*
 * Initialize the SPI peripheral for use with a 4-wire display.
 */
void hspi_init(SPI_TypeDef *SPIx) {
  // Ensure that the peripheral is disabled, and reset it.
  SPIx->CR1 &= ~(SPI_CR1_SPE);
  if (SPIx == SPI1) {
    RCC->APB2RSTR |=  (RCC_APB2RSTR_SPI1RST);
    RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST);
  }
  // Set the STM32 to act as a host device.
  SPIx->CR1 |=  (SPI_CR1_MSTR);
  // Set software 'Chip Select' pin.
  SPIx->CR1 |=  (SPI_CR1_SSM);
  // (Set the internal 'Chip Select' signal.)
  SPIx->CR1 |=  (SPI_CR1_SSI);
  // Enable the peripheral.
  SPIx->CR1 |=  (SPI_CR1_SPE);
}

/*
 * Send a byte of data over hardware SPI.
 * This method does not wait for the communication to finish.
 * (The STM32 has an onboard FIFO queue, so we can check
 *  whether that has space for writing instead.)
 */
inline void hspi_w8(SPI_TypeDef *SPIx, uint8_t dat) {
  // Wait for TXE.
  while (!(SPIx->SR & SPI_SR_TXE)) {};
  // Wait for idle EPD.
  //while ((GPIOA->IDR & (1 << PA_BUSY))) {};
  // Send the byte.
  *(uint8_t*)&(SPIx->DR) = dat;
}

/*
 * Send 16 bits of data over hardware SPI.
 * This method does not wait for the communication to finish.
 * It adds two bytes to the FIFO queue at once; that's one
 * pixel for a 16-bit color display.
 *
 * On L0 platforms, packing 2 data frames at once does
 * not appear to be supported.
 */
inline void hspi_w16(SPI_TypeDef *SPIx, uint16_t dat) {
#ifdef VVC_F0
  // Wait for TXE.
  while (!(SPIx->SR & SPI_SR_TXE)) {};
  // Wait for idle EPD.
  //while ((GPIOA->IDR & (1 << PA_BUSY))) {};
  // Send the data.
  // (Flip the bytes for the little-endian ARM core.)
  dat = (((dat & 0x00FF) << 8) | ((dat & 0xFF00) >> 8));
  *(uint16_t*)&(SPIx->DR) = dat;
#elif  VVC_L0
  hspi_w8(SPIx, (uint8_t)(dat >> 8));
  hspi_w8(SPIx, (uint8_t)(dat & 0xFF));
#endif
}

/*
 * Send a 'command' byte over hardware SPI.
 * Pull the 'D/C' pin low, send the byte, then pull the pin high.
 * Wait for the transmission to finish before changing the
 * 'D/C' pin value.
 */
inline void hspi_cmd(SPI_TypeDef *SPIx, uint8_t cmd) {
  while ((SPIx->SR & SPI_SR_BSY)) {};
  GPIOB->ODR &= ~(1 << PB_DC);
  hspi_w8(SPIx, cmd);
  while ((SPIx->SR & SPI_SR_BSY)) {};
  GPIOB->ODR |=  (1 << PB_DC);
}
