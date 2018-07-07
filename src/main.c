#include "main.h"

/**
 * Main program.
 */
int main(void) {
  // Initial clock setup.
  #ifdef VVC_F0
    // Reset the Flash 'Access Control Register', and
    // then set 1 wait-state and enable the prefetch buffer.
    // (The device header files only show 1 bit for the F0
    //  line, but the reference manual shows 3...)
    FLASH->ACR &= ~(0x00000017);
    FLASH->ACR |=  (FLASH_ACR_LATENCY |
                    FLASH_ACR_PRFTBE);
    // Configure the PLL to (HSI / 2) * 12 = 48MHz.
    // Use a PLLMUL of 0xA for *12, and keep PLLSRC at 0
    // to use (HSI / PREDIV) as the core source. HSI = 8MHz.
    RCC->CFGR  &= ~(RCC_CFGR_PLLMUL |
                    RCC_CFGR_PLLSRC);
    RCC->CFGR  |=  (RCC_CFGR_PLLSRC_HSI_DIV2 |
                    RCC_CFGR_PLLMUL12);
    // Turn the PLL on and wait for it to be ready.
    RCC->CR    |=  (RCC_CR_PLLON);
    while (!(RCC->CR & RCC_CR_PLLRDY)) {};
    // Select the PLL as the system clock source.
    RCC->CFGR  &= ~(RCC_CFGR_SW);
    RCC->CFGR  |=  (RCC_CFGR_SW_PLL);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {};
    // The system clock is now 48MHz.
    core_clock_hz = 48000000;
  #elif VVC_L0
    // Set the Flash ACR to use 1 wait-state
    // and enable the prefetch buffer and pre-read.
    FLASH->ACR |=  (FLASH_ACR_LATENCY |
                    FLASH_ACR_PRFTEN |
                    FLASH_ACR_PRE_READ);
    // Enable the HSI oscillator, since the L0 series boots
    // to the MSI one.
    RCC->CR    |=  (RCC_CR_HSION);
    while (!(RCC->CR & RCC_CR_HSIRDY)) {};
    // Configure the PLL to use HSI16 with a PLLDIV of
    // 2 and PLLMUL of 4.
    RCC->CFGR  &= ~(RCC_CFGR_PLLDIV |
                    RCC_CFGR_PLLMUL |
                    RCC_CFGR_PLLSRC);
    RCC->CFGR  |=  (RCC_CFGR_PLLDIV2 |
                    RCC_CFGR_PLLMUL4 |
                    RCC_CFGR_PLLSRC_HSI);
    // Enable the PLL and wait for it to stabilize.
    RCC->CR    |=  (RCC_CR_PLLON);
    while (!(RCC->CR & RCC_CR_PLLRDY)) {};
    // Select the PLL as the system clock source.
    RCC->CFGR  &= ~(RCC_CFGR_SW);
    RCC->CFGR  |=  (RCC_CFGR_SW_PLL);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {};
    // Set the global clock speed variable.
    core_clock_hz = 32000000;
  #endif

  // Reset the Epaper display's framebuffer.
  int epd_iter = 0;
  for (epd_iter = 0; epd_iter < EPD_BYTES; ++epd_iter) {
    epd_buf[epd_iter] = 0x00;
  }

  #ifdef VVC_F0
    // Enable the GPIOB peripheral in 'RCC_AHBENR'.
    RCC->AHBENR   |= RCC_AHBENR_GPIOAEN;
    RCC->AHBENR   |= RCC_AHBENR_GPIOBEN;
  #elif  VVC_L0
    RCC->IOPENR   |= RCC_IOPENR_IOPAEN;
    RCC->IOPENR   |= RCC_IOPENR_IOPBEN;
  #endif
  // Enable the SPI1 peripheral.
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

  // Initialize the 'input' GPIOA pins.
  // Input mode, no pulling resistors.
  GPIOA->MODER   &= ~((0x3 << (PA_BUSY * 2)));
  GPIOA->PUPDR   &= ~((0x3 << (PA_BUSY * 2)));
  // Or use a pull-up?
  //GPIOA->PUPDR   |=  ((0x1 << (PA_BUSY * 2)));
  // Initialize the 'output' GPIOB pins.
  // Mode: Output
  GPIOB->MODER   &= ~((0x3 << (PB_MOSI * 2)) |
                      (0x3 << (PB_SCK  * 2)) |
                      (0x3 << (PB_DC   * 2)));
  // Set the MOSI and SCK pins to alternate function mode 0.
  // Set D/C to normal output.
  #ifdef VVC_F0
    GPIOB->AFR[0]  &= ~(GPIO_AFRL_AFSEL3 |
                        GPIO_AFRL_AFSEL5);
  #elif  VVC_L0
    GPIOB->AFR[0]  &= ~(GPIO_AFRL_AFRL3 |
                        GPIO_AFRL_AFRL5);
  #endif
  GPIOB->MODER   |=  ((0x2 << (PB_MOSI * 2)) |
                      (0x2 << (PB_SCK  * 2)) |
                      (0x1 << (PB_DC   * 2)));
  // Use pull-down resistors for the SPI peripheral?
  // Or no pulling resistors?
  GPIOB->PUPDR   &= ~((0x3 << (PB_MOSI * 2)) |
                      (0x3 << (PB_SCK  * 2)) |
                      (0x3 << (PB_DC   * 2)));
  GPIOB->PUPDR  |=   ((0x1 << (PB_MOSI * 2)) |
                      (0x1 << (PB_SCK  * 2)));
  // Output type: Push-pull
  GPIOB->OTYPER  &= ~((0x1 << PB_MOSI) |
                      (0x1 << PB_SCK)  |
                      (0x1 << PB_DC));
  // High-speed - 50MHz maximum
  // (Setting all '1's, so no need to clear bits first.)
  GPIOB->OSPEEDR |=  ((0x3 << (PB_MOSI * 2)) |
                      (0x3 << (PB_SCK  * 2)) |
                      (0x3 << (PB_DC   * 2)));
  // Initialize the GPIOA pins; ditto.
  GPIOA->MODER   &= ~((0x3 << (PA_CS   * 2)) |
                      (0x3 << (PA_RST  * 2)));
  GPIOA->MODER   |=  ((0x1 << (PA_CS   * 2)) |
                      (0x1 << (PA_RST  * 2)));
  GPIOA->OTYPER  &= ~((0x1 << PA_CS) |
                      (0x1 << PA_RST));
  GPIOA->PUPDR   &= ~((0x3 << (PA_CS  * 2)) |
                      (0x3 << (PA_RST * 2)));
  // Perform ILI9341 panel initialization.
  // Set initial pin values.
  //   (The 'Chip Select' pin tells the display if it
  //    should be listening. '0' means 'hey, listen!', and
  //    '1' means 'ignore the SCK/MOSI/DC pins'.)
  GPIOA->ODR |=  (1 << PA_CS);
  //   (See the 'sspi_cmd' method for 'DC' pin info.)
  GPIOB->ODR |=  (1 << PB_DC);
  // Set SCK low to start.
  //GPIOB->ODR &= ~(1 << PB_SCK);
  // Or high?
  GPIOB->ODR |=  (1 << PB_SCK);
  // Reset the display by pulling the reset pin low,
  // delaying a bit, then pulling it high.
  GPIOA->ODR &= ~(1 << PA_RST);
  // Delay at least 100ms; meh, call it 2 million no-ops.
  delay_cycles(2000000);
  GPIOA->ODR |=  (1 << PA_RST);
  delay_cycles(2000000);

  // Send initialization commands for a 320x240 display.
  // Initialize the SPI peripheral.
  hspi_init(SPI1);
  // Pull CS low.
  GPIOA->ODR &= ~(1 << PA_CS);
  // Initialize the display and power it on.
  epd29_hspi_init(SPI1);

  // Main loop - empty the screen as a test.
  uint8_t epd_color_byte = 0x00;

  while (1) {
    // Write a display to the EPD.
    epd_draw_rect(0, 0, (EPD_W - 1), (EPD_H - 1), 0, ~epd_color_byte);
    epd_draw_rect(0, 0, (EPD_W - 1), (EPD_H - 1), 2, epd_color_byte);
    epd_draw_rect(4, 4, (EPD_W - 9), (EPD_H - 9), 4, epd_color_byte);
    epd_draw_rect(16, 16, (EPD_W - 33), (EPD_H - 33), 6, epd_color_byte);
    epd_draw_buf(24, 20, VVC_LOGO_W / 8, VVC_LOGO_H, epd_color_byte, VVC_LOGO_BUF);
    // Draw the logo.
    // Send the 'write to RAM' command.
    hspi_cmd(SPI1, 0x24);
    // Write to the actual RAM.
    for (epd_iter = 0; epd_iter < (EPD_BYTES); ++epd_iter) {
      //hspi_w8(SPI1, epd_color_byte);
      hspi_w8(SPI1, epd_buf[epd_iter]);
    }
    // Tell the epaper display to update.
    // 'Display update control 2'
    hspi_cmd(SPI1, 0x22);
    hspi_w8(SPI1, 0xC4);
    // 'Master activation'
    hspi_cmd(SPI1, 0x20);
    // Wait for the peripheral to finish sending.
    while ((SPI1->SR & SPI_SR_BSY)) {};
    // Wait for the epaper display to finish.
    while ((GPIOA->IDR & (1 << PA_BUSY))) {};
    // 'Terminate frame r/w'
    hspi_cmd(SPI1, 0xFF);
    // Wait for the epaper display to finish.
    while ((GPIOA->IDR & (1 << PA_BUSY))) {};
    // Change the color being written.
    epd_color_byte = ~(epd_color_byte);
    // Delay for a bit.
    delay_cycles(8000000);
  }
}
