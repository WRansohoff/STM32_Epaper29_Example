#include "global.h"

const uint8_t VVC_LOGO_BUF[VVC_LOGO_L] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0xfe,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x0f,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0x0f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0xf8,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x0f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0x07,0xfe,
0x0f,0xf0,0xff,0xff,0xff,0xff,0xff,0xff,0x03,0xfc,0x0f,0xe0,0xff,0xff,0xff,
0xff,0xff,0xff,0x61,0xf8,0x0f,0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xf1,
0x0f,0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0x10,0xf1,0x0f,0x80,0xff,0xff,0xff,
0xff,0xff,0xff,0x30,0xf3,0x0f,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x21,0xf3,
0x0f,0x00,0xfe,0xff,0xff,0xff,0xff,0xff,0x01,0xf1,0x0f,0x00,0xfe,0xff,0xff,
0xff,0xff,0x7f,0xc2,0xf1,0x0f,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x7c,0xf1,
0x0f,0x00,0xf8,0xff,0xff,0xff,0xff,0xe7,0xef,0xf8,0x0f,0x00,0xf0,0xff,0xff,
0xff,0xff,0x01,0x10,0xf8,0x0f,0x00,0xf0,0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,
0x0f,0x00,0xe0,0xff,0xff,0xff,0x7f,0x7c,0x00,0xfc,0x0f,0x00,0xe0,0xff,0xff,
0xff,0x81,0xe5,0xff,0xf8,0x0f,0x00,0xc0,0xff,0xff,0x3f,0x00,0x06,0xf8,0xff,
0x0f,0x00,0x80,0xff,0xff,0x0f,0x00,0x08,0xff,0xff,0x0f,0x00,0x80,0xff,0xff,
0xf3,0x00,0xc0,0xff,0xff,0x0f,0x00,0x00,0xff,0x7f,0x80,0x01,0xf8,0xff,0xff,
0x0f,0x00,0x00,0xfe,0x7f,0x0e,0x06,0xfe,0xff,0xff,0x0f,0x00,0x00,0xfe,0x3f,
0x33,0xcc,0xff,0xff,0xff,0x0f,0x00,0x00,0xfe,0x3f,0xd5,0xf8,0xff,0xff,0xff,
0x0f,0x00,0x00,0xfe,0x3f,0x95,0xe1,0xff,0xff,0xff,0x0f,0x00,0x00,0xfe,0x7f,
0x10,0x03,0xfe,0xff,0xff,0x0f,0x00,0x00,0xff,0xff,0x18,0xe6,0xf9,0xff,0xff,
0x0f,0x00,0x00,0xff,0xff,0x0f,0x64,0xc0,0xff,0xff,0x0f,0x00,0x00,0xfe,0xff,
0x1f,0x48,0x00,0xfe,0xf3,0x0f,0x00,0x00,0xfe,0xff,0xff,0x98,0x00,0xe0,0xf1,
0x0f,0x00,0x00,0xfe,0xff,0xff,0x1f,0x01,0x00,0xf0,0x0f,0x00,0x00,0xfe,0xff,
0xff,0x3f,0x03,0x80,0xff,0x0f,0x00,0x00,0xfe,0xff,0xff,0xff,0x04,0x38,0xf0,
0x0f,0x00,0x00,0xfe,0xff,0xff,0xff,0x19,0x06,0xf0,0x0f,0x00,0x00,0xfe,0xff,
0xff,0xff,0xf7,0xf9,0xf1,0x0f,0x00,0x00,0xfe,0x7f,0xff,0xff,0xfe,0x0f,0xf7,
0x0f,0x00,0x00,0xfe,0x7f,0xc0,0x1f,0xfe,0x1f,0xf8,0x0f,0x00,0x00,0xfc,0x7f,
0x00,0x00,0xfe,0xff,0xf0,0x0f,0x00,0x00,0xfc,0x7f,0x00,0x00,0xfe,0xff,0xf1,
0x0f,0x00,0x00,0xfc,0x7f,0x00,0x00,0xfe,0xff,0xf1,0x0f,0x00,0x00,0xfc,0x7f,
0xfe,0x1f,0xfe,0xff,0xf3,0x0f,0x00,0x00,0xfc,0x7f,0xff,0xff,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,
0xff,0xff,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,0xff,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xf8,0xff,0xff,0x1f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,
0xff,0x07,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,0xff,0x01,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xf0,0xff,0x7f,0x00,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf0,0xff,
0x1f,0xe0,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf0,0xff,0x07,0xf8,0xff,0xff,0xff,
0x0f,0x00,0x00,0xf0,0xff,0x00,0xfe,0xff,0xff,0xff,0x0f,0x00,0x00,0xf0,0x3f,
0x80,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xe0,0x3f,0xf0,0xff,0xff,0xff,0xff,
0x0f,0x00,0x00,0xe0,0x7f,0xe0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xe0,0xff,
0x81,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xe0,0xff,0x07,0xfe,0xff,0xff,0xff,
0x0f,0x00,0x00,0xc0,0xff,0x1f,0xf0,0xfe,0xff,0xff,0x0f,0x00,0x00,0xc0,0xff,
0xff,0x00,0xfe,0xff,0xff,0x0f,0x00,0x00,0xc0,0xff,0xff,0x03,0xfe,0xff,0xff,
0x1f,0x00,0x00,0xc0,0xff,0xff,0x0f,0xfe,0xff,0xff,0x1f,0x00,0x00,0xc0,0xff,
0xff,0x3f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x80,0xff,0xff,0x7f,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x80,0xff,0x0f,0xf8,0xfe,0xff,0xff,0x1f,0x00,0x00,0x80,0xff,
0x07,0xf0,0xff,0xff,0xff,0x1f,0x00,0x00,0x80,0xff,0x03,0xe0,0xff,0xff,0xff,
0x1f,0x00,0x00,0x80,0xff,0x01,0xc0,0xff,0xff,0xff,0x1f,0x00,0x00,0x80,0xff,
0xc0,0x81,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xff,0xf8,0x8f,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7f,0xfc,0x1f,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0x7f,
0xfe,0x3f,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0x7f,0xfe,0x3f,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7f,0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7e,
0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7e,0xff,0x7f,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7e,0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7e,
0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7e,0xfe,0x7f,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7e,0xfe,0x3f,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0x7e,
0xfc,0x1f,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,0xf8,0x8f,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfe,0xc0,0x81,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,
0x01,0xc0,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,0x03,0xe0,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfc,0x07,0xf0,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,
0x0f,0x78,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,0xff,0x7f,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0x3c,0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,
0x00,0x10,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7e,0x00,0x00,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x3e,
0xff,0x0f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,0xff,0x03,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfe,0xff,0x81,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,
0xff,0xc0,0xff,0xff,0xff,0x3f,0x00,0x00,0x00,0xfe,0x7f,0xf0,0xff,0xff,0xff,
0x7f,0x00,0x00,0x00,0xfe,0x3f,0xf8,0xff,0xff,0xff,0x0f,0x00,0x00,0x00,0xfe,
0x1f,0xfc,0xff,0xff,0xff,0x07,0x00,0x00,0x00,0xff,0x0f,0xfe,0xff,0xff,0xff,
0x07,0x00,0x00,0x00,0xff,0x07,0xff,0xff,0xff,0xff,0x07,0x00,0x00,0x00,0xff,
0x81,0xff,0xff,0xff,0xff,0x07,0x00,0x00,0x00,0xff,0xc0,0xff,0xfe,0xff,0xff,
0x07,0x00,0x00,0x80,0x7f,0xf0,0x7f,0xfe,0xff,0xff,0x07,0x00,0x00,0x80,0x3f,
0x00,0x00,0xfe,0xff,0xff,0x07,0x00,0x00,0x80,0x3f,0x00,0x00,0xfe,0xff,0xff,
0x07,0x00,0x00,0xc0,0xff,0xff,0x03,0xfe,0xff,0xff,0x07,0x00,0x00,0xc0,0xff,
0x3f,0xfe,0xfe,0xff,0xff,0x07,0x00,0x00,0xe0,0xff,0x0f,0xf0,0xff,0xff,0xff,
0x07,0x00,0x00,0xf0,0xff,0x03,0xe0,0xff,0xff,0xff,0x07,0x00,0x00,0xf0,0xff,
0x01,0xc0,0xff,0xff,0xff,0x07,0x00,0x00,0xf8,0xff,0x01,0xc0,0xff,0xff,0xff,
0x07,0x00,0x00,0xfc,0xff,0xe0,0x83,0xff,0xff,0xff,0x07,0x00,0x00,0xfe,0xff,
0xf8,0x0f,0xff,0xff,0xff,0x07,0x00,0x00,0xff,0x7f,0xfc,0x1f,0xff,0xff,0xff,
0x07,0x00,0x80,0xff,0x7f,0xfe,0x3f,0xff,0xff,0xff,0x07,0x00,0xe0,0xff,0x7f,
0xfe,0x7f,0xfe,0xff,0xff,0x07,0x00,0xf8,0xff,0x7f,0xff,0x7f,0xfe,0xff,0xff,
0x07,0x00,0xfe,0xff,0x7f,0xff,0x7f,0xfe,0xff,0xff,0x07,0xc0,0xff,0xff,0x7f,
0xff,0x7f,0xfe,0xff,0xff,0x07,0x80,0xff,0xff,0x7f,0xff,0x7f,0xfe,0xff,0xff,
0x07,0x00,0xfc,0xff,0x7f,0xff,0x7f,0xfe,0xff,0xff,0x07,0x00,0xf0,0xff,0x7f,
0xfe,0x3f,0xff,0xff,0xff,0x07,0x00,0xc0,0xff,0x7f,0xfc,0x3f,0xff,0xff,0xff,
0x07,0x00,0x80,0xff,0xff,0xf8,0x1f,0xff,0xff,0xff,0x07,0x00,0x00,0xff,0xff,
0xf0,0x8f,0xff,0xff,0xff,0x07,0x00,0x00,0xfc,0xff,0x00,0x80,0xff,0xff,0xff,
0x07,0x00,0x00,0xf8,0xff,0x01,0xc0,0xff,0xff,0xff,0x07,0x00,0x00,0xf8,0xff,
0x03,0xe0,0xff,0xff,0xff,0x07,0x00,0x00,0xf0,0xff,0x07,0xf0,0xff,0xff,0xff,
0x07,0x00,0x00,0xe0,0xff,0x3f,0x7c,0xfe,0xff,0xff,0x07,0x00,0x00,0xe0,0xff,
0xff,0x7f,0xfe,0xff,0xff,0x07,0x00,0x00,0xc0,0x3f,0xff,0x7f,0xfe,0xff,0xff,
0x07,0x00,0x00,0xc0,0x7f,0xe0,0x1f,0xfe,0xff,0xff,0x07,0x00,0x00,0x80,0x7f,
0x00,0x00,0xfe,0xff,0xff,0x07,0x00,0x00,0x80,0x7f,0x00,0x00,0xfe,0xff,0xff,
0x07,0x00,0x00,0x80,0x3f,0xfe,0x07,0xfe,0xff,0xff,0x07,0x00,0x00,0x00,0x7f,
0xff,0x03,0xff,0xff,0xff,0x07,0x00,0x00,0x00,0xff,0xff,0xc0,0xff,0xff,0xff,
0x07,0x00,0x00,0x00,0xff,0x7f,0xe0,0xff,0xff,0xff,0x0f,0x00,0x00,0x00,0xfe,
0x1f,0xf8,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,0x0f,0xfc,0xff,0xff,0xff,
0x3f,0x00,0x00,0x00,0xfe,0x07,0xfe,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,
0x81,0xff,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,0xc3,0xff,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfe,0x0f,0xff,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,
0x1f,0xfe,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,0x7f,0xf8,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfc,0xff,0xf1,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,
0xff,0xc3,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,0xff,0x8f,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,
0x00,0x00,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,
0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,0xff,0xff,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,
0xfe,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,
0x00,0x00,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x7c,0x00,0x00,0xfe,0xff,0xff,
0x1f,0x00,0x00,0x00,0x7c,0xff,0x7f,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,
0xff,0xff,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfc,0x1f,0xfc,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfc,0x07,0xf0,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,
0x03,0xe0,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,0xfe,0x01,0xc0,0xff,0xff,0xff,
0x1f,0x00,0x00,0x00,0xfe,0x00,0x80,0xff,0xff,0xff,0x0f,0x00,0x00,0x00,0xfe,
0xe0,0x87,0xff,0xff,0xff,0x0f,0x00,0x00,0x00,0x7e,0xf8,0x0f,0xff,0xff,0xff,
0x0f,0x00,0x00,0x00,0x7e,0xfc,0x1f,0xff,0xff,0xff,0x0f,0x00,0x00,0x00,0x7e,
0xfc,0x3f,0xff,0xff,0xff,0x0f,0x00,0x00,0x00,0x7e,0xfe,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0x00,0x7e,0xfe,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0x00,0x7f,
0xfe,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0x00,0x7f,0xff,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0x00,0x7f,0xff,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0x00,0x7f,
0xff,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0x00,0x7f,0xfe,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0x00,0x7f,0xfe,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0x80,0x7f,
0xfc,0x3f,0xff,0xff,0xff,0x0f,0x00,0x00,0x80,0x7f,0xfc,0x3f,0xff,0xff,0xff,
0x0f,0x00,0x00,0x80,0xff,0xf8,0x1f,0xff,0xff,0xff,0x0f,0x00,0x00,0x80,0xff,
0xf0,0x8f,0xff,0xff,0xff,0x0f,0x00,0x00,0x80,0xff,0xe1,0xc7,0xff,0xff,0xff,
0x0f,0x00,0x00,0x80,0xff,0xef,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0x80,0xff,
0xff,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xc0,0xff,0x0f,0xf8,0xff,0xff,0xff,
0x0f,0x00,0x00,0xc0,0xff,0x07,0xf0,0xff,0xff,0xff,0x0f,0x00,0x00,0xc0,0xff,
0x03,0xe0,0xff,0xff,0xff,0x0f,0x00,0x00,0xc0,0xff,0x01,0xc0,0xff,0xff,0xff,
0x0f,0x00,0x00,0xc0,0xff,0xe0,0x83,0xff,0xff,0xff,0x0f,0x00,0x00,0xc0,0xff,
0xf8,0x0f,0xff,0xff,0xff,0x0f,0x00,0x00,0xe0,0x7f,0xfc,0x1f,0xff,0xff,0xff,
0x0f,0x00,0x00,0xe0,0x7f,0xfe,0x3f,0xff,0xff,0xff,0x0f,0x00,0x00,0xe0,0x7f,
0xfe,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xe0,0x7f,0xff,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xe0,0x7f,0xff,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf0,0x7f,
0xff,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf0,0x7f,0xff,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xf0,0x7f,0xff,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf0,0x7f,
0xfe,0x3f,0xff,0xff,0xff,0x0f,0x00,0x00,0xf0,0x7f,0xfe,0x3f,0xff,0xff,0xff,
0x0f,0x00,0x00,0xf0,0x7f,0xfc,0x1f,0xff,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,
0xf0,0x8f,0xff,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,0x80,0x81,0xff,0xff,0xff,
0x0f,0x00,0x00,0xf8,0xff,0x01,0xc0,0xff,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,
0x03,0xe0,0xff,0xff,0xff,0x0f,0x00,0x00,0xf8,0xff,0x07,0xf0,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xf8,0xff,0x1f,0x7c,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf8,0x3f,
0xff,0x7f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xf8,0x3f,0xff,0x7f,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xfc,0x7f,0x00,0x00,0xfe,0xff,0xff,0x0f,0x00,0x00,0xfc,0x7f,
0x00,0x00,0xfe,0xff,0xff,0x0f,0x00,0x00,0xfc,0x7f,0x00,0x00,0xfe,0xff,0xff,
0x0f,0x00,0x00,0xfc,0x3f,0xff,0x0f,0xfe,0xff,0xff,0x0f,0x00,0x00,0xfe,0xff,
0xff,0x03,0xff,0xff,0xff,0x0f,0x00,0x00,0xff,0xff,0xff,0x81,0xff,0xff,0xff,
0x0f,0x00,0x80,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0x0f,0x00,0x80,0xff,0xff,
0x7f,0xf0,0xff,0xff,0xff,0x0f,0x00,0xc0,0xff,0xff,0x3f,0xf8,0xff,0xff,0xff,
0x07,0x00,0xe0,0xff,0xff,0x1f,0xfc,0xff,0xff,0xff,0x07,0x00,0xf0,0xff,0xff,
0x0f,0xfe,0xff,0xff,0xff,0x07,0x00,0xf8,0xff,0xff,0x03,0xff,0xff,0xff,0xff,
0x07,0x00,0xf8,0xff,0xff,0x81,0xff,0xff,0xff,0xff,0x07,0x00,0xfc,0xff,0xff,
0xc0,0xff,0xfe,0xff,0xff,0x07,0x00,0xfe,0xff,0x7f,0xf0,0x7f,0xfe,0xff,0xff,
0x07,0x00,0xfe,0xff,0x3f,0x00,0x00,0xfe,0xff,0xff,0x07,0x00,0xff,0xff,0x3f,
0x00,0x00,0xfe,0xff,0xff,0x07,0x80,0xff,0xff,0xff,0xff,0x1f,0xfe,0xff,0xff,
0x07,0xc0,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0x07,0xc0,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x07,0xe0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0x07,0xf0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x07,0xf0,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x07,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0x07,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x07,0xfc,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x07,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x07,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};