/**
  ******************************************************************************
  * @file    st7735.h
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    24-November-2014
  * @brief   This file contains all the functions prototypes for the st7735.c
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ST7735_H
#define __ST7735_H

#include <stdint.h>
#include "hardware_init.h"
#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_spi.h"
#ifdef __cplusplus
 extern "C" {
#endif


 /** @addtogroup BSP
   * @{
   */

 /** @addtogroup Components
   * @{
   */

 /** @addtogroup LCD
   * @{
   */

 /** @defgroup LCD_Exported_Types
   * @{
   */
 /**
   * @brief  LCD driver structure definition
   */
 typedef struct
 {
   void     (*Init)(void);
   uint16_t (*ReadID)(void);
   void     (*DisplayOn)(void);
   void     (*DisplayOff)(void);
   void     (*SetCursor)(uint16_t, uint16_t);
   void     (*WritePixel)(uint16_t, uint16_t, uint16_t);
   uint16_t (*ReadPixel)(uint16_t, uint16_t);

    /* Optimized operation */
   void     (*SetDisplayWindow)(uint16_t, uint16_t, uint16_t, uint16_t);
   void     (*DrawHLine)(uint16_t, uint16_t, uint16_t, uint16_t);
   void     (*DrawVLine)(uint16_t, uint16_t, uint16_t, uint16_t);

   uint16_t (*GetLcdPixelWidth)(void);
   uint16_t (*GetLcdPixelHeight)(void);
   void     (*DrawBitmap)(uint16_t, uint16_t, uint8_t*);
   void     (*DrawRGBImage)(uint16_t, uint16_t, uint16_t, uint16_t, uint8_t*);
 }LCD_DrvTypeDef;

 unsigned char     lcdBuildMemoryAccessControlConfig(
                                 bool rowAddressOrder,
                                 bool columnAddressOrder,
                                 bool rowColumnExchange,
                                 bool verticalRefreshOrder,
                                 bool colorOrder,
                                 bool horizontalRefreshOrder);

 void              lcdInit(void);
 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}



/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup ST7735
  * @{
  */

/** @defgroup ST7735_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup ST7735_Exported_Constants
  * @{
  */
#define ILI9341_NOP        0x00
#define ILI9341_SWRESET    0x01
#define ILI9341_RDDID      0x04
#define ILI9341_RDDST      0x09

#define ILI9341_SLPIN      0x10
#define ILI9341_SLPOUT     0x11
#define ILI9341_PTLON      0x12
#define ILI9341_NORON      0x13

#define ILI9341_RDMODE     0x0A
#define ILI9341_RDMADCTL   0x0B
#define ILI9341_RDPIXFMT   0x0C
#define ILI9341_RDIMGFMT   0x0D
#define ILI9341_RDSELFDIAG 0x0F

#define ILI9341_INVOFF     0x20
#define ILI9341_INVON      0x21
#define ILI9341_GAMMASET   0x26
#define ILI9341_DISPOFF    0x28
#define ILI9341_DISPON     0x29

#define ILI9341_CASET      0x2A
#define ILI9341_PASET      0x2B
#define ILI9341_RAMWR      0x2C
#define ILI9341_RAMRD      0x2E

#define ILI9341_PTLAR      0x30
#define ILI9341_MADCTL     0x36
#define ILI9341_VSCRSADD   0x37
#define ILI9341_PIXFMT     0x3A

#define ILI9341_FRMCTR1    0xB1
#define ILI9341_FRMCTR2    0xB2
#define ILI9341_FRMCTR3    0xB3
#define ILI9341_INVCTR     0xB4
#define ILI9341_DFUNCTR    0xB6

#define ILI9341_PWCTR1     0xC0
#define ILI9341_PWCTR2     0xC1
#define ILI9341_PWCTR3     0xC2
#define ILI9341_PWCTR4     0xC3
#define ILI9341_PWCTR5     0xC4
#define ILI9341_VMCTR1     0xC5
#define ILI9341_VMCTR2     0xC7

#define ILI9341_RDID1      0xDA
#define ILI9341_RDID2      0xDB
#define ILI9341_RDID3      0xDC
#define ILI9341_RDID4      0xDD

#define ILI9341_GMCTRP1    0xE0
#define ILI9341_GMCTRN1 0xE1

#define ILI9341_SOFTRESET          0x01
#define ILI9341_SLEEPIN            0x10
#define ILI9341_SLEEPOUT           0x11
#define ILI9341_NORMALDISP         0x13
#define ILI9341_INVERTOFF          0x20
#define ILI9341_INVERTON           0x21
#define ILI9341_GAMMASET           0x26
#define ILI9341_DISPLAYOFF         0x28
#define ILI9341_DISPLAYON          0x29
#define ILI9341_COLADDRSET         0x2A
#define ILI9341_PAGEADDRSET        0x2B
#define ILI9341_MEMORYWRITE        0x2C
#define ILI9341_PIXELFORMAT        0x3A
#define ILI9341_FRAMECONTROL       0xB1
#define ILI9341_DISPLAYFUNC        0xB6
#define ILI9341_ENTRYMODE          0xB7
#define ILI9341_POWERCONTROL1      0xC0
#define ILI9341_POWERCONTROL2      0xC1
#define ILI9341_VCOMCONTROL1      0xC5
#define ILI9341_VCOMCONTROL2      0xC7
#define ILI9341_MEMCONTROL      0x36
#define ILI9341_MADCTL  0x36

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH 0x04
/**
  * @brief  ST7735 Size
  */
#define  ST7735_LCD_PIXEL_WIDTH    ((uint16_t)128)
#define  ST7735_LCD_PIXEL_HEIGHT   ((uint16_t)160)
 /* Level 1 Commands (from the display Datasheet) */
 #define ILI9488_CMD_NOP                             0x00
 #define ILI9488_CMD_SOFTWARE_RESET                  0x01
 #define ILI9488_CMD_READ_DISP_ID                    0x04
 #define ILI9488_CMD_READ_ERROR_DSI                  0x05
 #define ILI9488_CMD_READ_DISP_STATUS                0x09
 #define ILI9488_CMD_READ_DISP_POWER_MODE            0x0A
 #define ILI9488_CMD_READ_DISP_MADCTRL               0x0B
 #define ILI9488_CMD_READ_DISP_PIXEL_FORMAT          0x0C
 #define ILI9488_CMD_READ_DISP_IMAGE_MODE            0x0D
 #define ILI9488_CMD_READ_DISP_SIGNAL_MODE           0x0E
 #define ILI9488_CMD_READ_DISP_SELF_DIAGNOSTIC       0x0F
 #define ILI9488_CMD_ENTER_SLEEP_MODE                0x10
 #define ILI9488_CMD_SLEEP_OUT                       0x11
 #define ILI9488_CMD_PARTIAL_MODE_ON                 0x12
 #define ILI9488_CMD_NORMAL_DISP_MODE_ON             0x13
 #define ILI9488_CMD_DISP_INVERSION_OFF              0x20
 #define ILI9488_CMD_DISP_INVERSION_ON               0x21
 #define ILI9488_CMD_PIXEL_OFF                       0x22
 #define ILI9488_CMD_PIXEL_ON                        0x23
 #define ILI9488_CMD_DISPLAY_OFF                     0x28
 #define ILI9488_CMD_DISPLAY_ON                      0x29
 #define ILI9488_CMD_COLUMN_ADDRESS_SET              0x2A
 #define ILI9488_CMD_PAGE_ADDRESS_SET                0x2B
 #define ILI9488_CMD_MEMORY_WRITE                    0x2C
 #define ILI9488_CMD_MEMORY_READ                     0x2E
 #define ILI9488_CMD_PARTIAL_AREA                    0x30
 #define ILI9488_CMD_VERT_SCROLL_DEFINITION          0x33
 #define ILI9488_CMD_TEARING_EFFECT_LINE_OFF         0x34
 #define ILI9488_CMD_TEARING_EFFECT_LINE_ON          0x35
 #define ILI9488_CMD_MEMORY_ACCESS_CONTROL           0x36
 #define ILI9488_CMD_VERT_SCROLL_START_ADDRESS       0x37
 #define ILI9488_CMD_IDLE_MODE_OFF                   0x38
 #define ILI9488_CMD_IDLE_MODE_ON                    0x39
 #define ILI9488_CMD_COLMOD_PIXEL_FORMAT_SET         0x3A
 #define ILI9488_CMD_WRITE_MEMORY_CONTINUE           0x3C
 #define ILI9488_CMD_READ_MEMORY_CONTINUE            0x3E
 #define ILI9488_CMD_SET_TEAR_SCANLINE               0x44
 #define ILI9488_CMD_GET_SCANLINE                    0x45
 #define ILI9488_CMD_WRITE_DISPLAY_BRIGHTNESS        0x51
 #define ILI9488_CMD_READ_DISPLAY_BRIGHTNESS         0x52
 #define ILI9488_CMD_WRITE_CTRL_DISPLAY              0x53
 #define ILI9488_CMD_READ_CTRL_DISPLAY               0x54
 #define ILI9488_CMD_WRITE_CONTENT_ADAPT_BRIGHTNESS  0x55
 #define ILI9488_CMD_READ_CONTENT_ADAPT_BRIGHTNESS   0x56
 #define ILI9488_CMD_WRITE_MIN_CAB_LEVEL             0x5E
 #define ILI9488_CMD_READ_MIN_CAB_LEVEL              0x5F
 #define ILI9488_CMD_READ_ABC_SELF_DIAG_RES          0x68
 #define ILI9488_CMD_READ_ID1                        0xDA
 #define ILI9488_CMD_READ_ID2                        0xDB
 #define ILI9488_CMD_READ_ID3                        0xDC

 /* Level 2 Commands (from the display Datasheet) */
 #define ILI9488_CMD_INTERFACE_MODE_CONTROL          0xB0
 #define ILI9488_CMD_FRAME_RATE_CONTROL_NORMAL       0xB1
 #define ILI9488_CMD_FRAME_RATE_CONTROL_IDLE_8COLOR  0xB2
 #define ILI9488_CMD_FRAME_RATE_CONTROL_PARTIAL      0xB3
 #define ILI9488_CMD_DISPLAY_INVERSION_CONTROL       0xB4
 #define ILI9488_CMD_BLANKING_PORCH_CONTROL          0xB5
 #define ILI9488_CMD_DISPLAY_FUNCTION_CONTROL        0xB6
 #define ILI9488_CMD_ENTRY_MODE_SET                  0xB7
 #define ILI9488_CMD_BACKLIGHT_CONTROL_1             0xB9
 #define ILI9488_CMD_BACKLIGHT_CONTROL_2             0xBA
 #define ILI9488_CMD_HS_LANES_CONTROL                0xBE
 #define ILI9488_CMD_POWER_CONTROL_1                 0xC0
 #define ILI9488_CMD_POWER_CONTROL_2                 0xC1
 #define ILI9488_CMD_POWER_CONTROL_NORMAL_3          0xC2
 #define ILI9488_CMD_POWER_CONTROL_IDEL_4            0xC3
 #define ILI9488_CMD_POWER_CONTROL_PARTIAL_5         0xC4
 #define ILI9488_CMD_VCOM_CONTROL_1                  0xC5
 #define ILI9488_CMD_CABC_CONTROL_1                  0xC6
 #define ILI9488_CMD_CABC_CONTROL_2                  0xC8
 #define ILI9488_CMD_CABC_CONTROL_3                  0xC9
 #define ILI9488_CMD_CABC_CONTROL_4                  0xCA
 #define ILI9488_CMD_CABC_CONTROL_5                  0xCB
 #define ILI9488_CMD_CABC_CONTROL_6                  0xCC
 #define ILI9488_CMD_CABC_CONTROL_7                  0xCD
 #define ILI9488_CMD_CABC_CONTROL_8                  0xCE
 #define ILI9488_CMD_CABC_CONTROL_9                  0xCF
 #define ILI9488_CMD_NVMEM_WRITE                     0xD0
 #define ILI9488_CMD_NVMEM_PROTECTION_KEY            0xD1
 #define ILI9488_CMD_NVMEM_STATUS_READ               0xD2
 #define ILI9488_CMD_READ_ID4                        0xD3
 #define ILI9488_CMD_ADJUST_CONTROL_1                0xD7
 #define ILI9488_CMD_READ_ID_VERSION                 0xD8
 #define ILI9488_CMD_POSITIVE_GAMMA_CORRECTION       0xE0
 #define ILI9488_CMD_NEGATIVE_GAMMA_CORRECTION       0xE1
 #define ILI9488_CMD_DIGITAL_GAMMA_CONTROL_1         0xE2
 #define ILI9488_CMD_DIGITAL_GAMMA_CONTROL_2         0xE3
 #define ILI9488_CMD_SET_IMAGE_FUNCTION              0xE9
 #define ILI9488_CMD_ADJUST_CONTROL_2                0xF2
 #define ILI9488_CMD_ADJUST_CONTROL_3                0xF7
 #define ILI9488_CMD_ADJUST_CONTROL_4                0xF8
 #define ILI9488_CMD_ADJUST_CONTROL_5                0xF9
 #define ILI9488_CMD_SPI_READ_SETTINGS               0xFB
 #define ILI9488_CMD_ADJUST_CONTROL_6                0xFC
 #define ILI9488_CMD_ADJUST_CONTROL_7 0xFF
/**
  * @brief  ST7735 Registers
  */
#define LCD_REG_0             0x00
#define LCD_REG_1             0x01
#define LCD_REG_2             0x02
#define LCD_REG_3             0x03
#define LCD_REG_4             0x04
#define LCD_REG_5             0x05
#define LCD_REG_6             0x06
#define LCD_REG_7             0x07
#define LCD_REG_8             0x08
#define LCD_REG_9             0x09
#define LCD_REG_10            0x0A
#define LCD_REG_12            0x0C
#define LCD_REG_13            0x0D
#define LCD_REG_14            0x0E
#define LCD_REG_15            0x0F
#define LCD_REG_16            0x10
#define LCD_REG_17            0x11
#define LCD_REG_18            0x12
#define LCD_REG_19            0x13
#define LCD_REG_20            0x14
#define LCD_REG_21            0x15
#define LCD_REG_22            0x16
#define LCD_REG_23            0x17
#define LCD_REG_24            0x18
#define LCD_REG_25            0x19
#define LCD_REG_26            0x1A
#define LCD_REG_27            0x1B
#define LCD_REG_28            0x1C
#define LCD_REG_29            0x1D
#define LCD_REG_30            0x1E
#define LCD_REG_31            0x1F
#define LCD_REG_32            0x20
#define LCD_REG_33            0x21
#define LCD_REG_34            0x22
#define LCD_REG_36            0x24
#define LCD_REG_37            0x25
#define LCD_REG_40            0x28
#define LCD_REG_41            0x29
#define LCD_REG_43            0x2B
#define LCD_REG_45            0x2D
#define LCD_REG_48            0x30
#define LCD_REG_49            0x31
#define LCD_REG_50            0x32
#define LCD_REG_51            0x33
#define LCD_REG_52            0x34
#define LCD_REG_53            0x35
#define LCD_REG_54            0x36
#define LCD_REG_55            0x37
#define LCD_REG_56            0x38
#define LCD_REG_57            0x39
#define LCD_REG_58            0x3A
#define LCD_REG_59            0x3B
#define LCD_REG_60            0x3C
#define LCD_REG_61            0x3D
#define LCD_REG_62            0x3E
#define LCD_REG_63            0x3F
#define LCD_REG_64            0x40
#define LCD_REG_65            0x41
#define LCD_REG_66            0x42
#define LCD_REG_67            0x43
#define LCD_REG_68            0x44
#define LCD_REG_69            0x45
#define LCD_REG_70            0x46
#define LCD_REG_71            0x47
#define LCD_REG_72            0x48
#define LCD_REG_73            0x49
#define LCD_REG_74            0x4A
#define LCD_REG_75            0x4B
#define LCD_REG_76            0x4C
#define LCD_REG_77            0x4D
#define LCD_REG_78            0x4E
#define LCD_REG_79            0x4F
#define LCD_REG_80            0x50
#define LCD_REG_81            0x51
#define LCD_REG_82            0x52
#define LCD_REG_83            0x53
#define LCD_REG_96            0x60
#define LCD_REG_97            0x61
#define LCD_REG_106           0x6A
#define LCD_REG_118           0x76
#define LCD_REG_128           0x80
#define LCD_REG_129           0x81
#define LCD_REG_130           0x82
#define LCD_REG_131           0x83
#define LCD_REG_132           0x84
#define LCD_REG_133           0x85
#define LCD_REG_134           0x86
#define LCD_REG_135           0x87
#define LCD_REG_136           0x88
#define LCD_REG_137           0x89
#define LCD_REG_139           0x8B
#define LCD_REG_140           0x8C
#define LCD_REG_141           0x8D
#define LCD_REG_143           0x8F
#define LCD_REG_144           0x90
#define LCD_REG_145           0x91
#define LCD_REG_146           0x92
#define LCD_REG_147           0x93
#define LCD_REG_148           0x94
#define LCD_REG_149           0x95
#define LCD_REG_150           0x96
#define LCD_REG_151           0x97
#define LCD_REG_152           0x98
#define LCD_REG_153           0x99
#define LCD_REG_154           0x9A
#define LCD_REG_157           0x9D
#define LCD_REG_192           0xC0
#define LCD_REG_193           0xC1
#define LCD_REG_229           0xE5
#define ILI932X_START_OSC          0x00
#define ILI932X_DRIV_OUT_CTRL      0x01
#define ILI932X_DRIV_WAV_CTRL      0x02
#define ILI932X_ENTRY_MOD          0x03
#define ILI932X_RESIZE_CTRL        0x04
#define ILI932X_DISP_CTRL1         0x07
#define ILI932X_DISP_CTRL2         0x08
#define ILI932X_DISP_CTRL3         0x09
#define ILI932X_DISP_CTRL4         0x0A
#define ILI932X_RGB_DISP_IF_CTRL1  0x0C
#define ILI932X_FRM_MARKER_POS     0x0D
#define ILI932X_RGB_DISP_IF_CTRL2  0x0F
#define ILI932X_POW_CTRL1          0x10
#define ILI932X_POW_CTRL2          0x11
#define ILI932X_POW_CTRL3          0x12
#define ILI932X_POW_CTRL4          0x13
#define ILI932X_GRAM_HOR_AD        0x20
#define ILI932X_GRAM_VER_AD        0x21
#define ILI932X_RW_GRAM            0x22
#define ILI932X_POW_CTRL7          0x29
#define ILI932X_FRM_RATE_COL_CTRL  0x2B
#define ILI932X_GAMMA_CTRL1        0x30
#define ILI932X_GAMMA_CTRL2        0x31
#define ILI932X_GAMMA_CTRL3        0x32
#define ILI932X_GAMMA_CTRL4        0x35
#define ILI932X_GAMMA_CTRL5        0x36
#define ILI932X_GAMMA_CTRL6        0x37
#define ILI932X_GAMMA_CTRL7        0x38
#define ILI932X_GAMMA_CTRL8        0x39
#define ILI932X_GAMMA_CTRL9        0x3C
#define ILI932X_GAMMA_CTRL10       0x3D
#define ILI932X_HOR_START_AD       0x50
#define ILI932X_HOR_END_AD         0x51
#define ILI932X_VER_START_AD       0x52
#define ILI932X_VER_END_AD         0x53
#define ILI932X_GATE_SCAN_CTRL1    0x60
#define ILI932X_GATE_SCAN_CTRL2    0x61
#define ILI932X_GATE_SCAN_CTRL3    0x6A
#define ILI932X_PART_IMG1_DISP_POS 0x80
#define ILI932X_PART_IMG1_START_AD 0x81
#define ILI932X_PART_IMG1_END_AD   0x82
#define ILI932X_PART_IMG2_DISP_POS 0x83
#define ILI932X_PART_IMG2_START_AD 0x84
#define ILI932X_PART_IMG2_END_AD   0x85
#define ILI932X_PANEL_IF_CTRL1     0x90
#define ILI932X_PANEL_IF_CTRL2     0x92
#define ILI932X_PANEL_IF_CTRL3     0x93
#define ILI932X_PANEL_IF_CTRL4     0x95
#define ILI932X_PANEL_IF_CTRL5     0x97
#define ILI932X_PANEL_IF_CTRL6 0x98
/**
  * @brief  LCD Lines depending on the chosen fonts.
  */
#define LCD_LINE_0               LINE(0)
#define LCD_LINE_1               LINE(1)
#define LCD_LINE_2               LINE(2)
#define LCD_LINE_3               LINE(3)
#define LCD_LINE_4               LINE(4)
#define LCD_LINE_5               LINE(5)
#define LCD_LINE_6               LINE(6)
#define LCD_LINE_7               LINE(7)
#define LCD_LINE_8               LINE(8)
#define LCD_LINE_9               LINE(9)
#define LCD_LINE_10              LINE(10)
#define LCD_LINE_11              LINE(11)
#define LCD_LINE_12              LINE(12)
#define LCD_LINE_13              LINE(13)
#define LCD_LINE_14              LINE(14)
#define LCD_LINE_15              LINE(15)
#define LCD_LINE_16              LINE(16)
#define LCD_LINE_17              LINE(17)
#define LCD_LINE_18              LINE(18)
#define LCD_LINE_19              LINE(19)
 // some flags for initR() :(
 #define INITR_GREENTAB 0x0
 #define INITR_REDTAB   0x1
 #define INITR_BLACKTAB   0x2

 #define INITR_18GREENTAB    INITR_GREENTAB
 #define INITR_18REDTAB      INITR_REDTAB
 #define INITR_18BLACKTAB    INITR_BLACKTAB
 #define INITR_144GREENTAB   0x1

 #define ST7735_TFTWIDTH  128
 // for 1.44" display
 #define ST7735_TFTHEIGHT_144 128
 // for 1.8" display
 #define ST7735_TFTHEIGHT_18  160

 #define ST7735_NOP     0x00
 #define ST7735_SWRESET 0x01
 #define ST7735_RDDID   0x04
 #define ST7735_RDDST   0x09

 #define ST7735_SLPIN   0x10
 #define ST7735_SLPOUT  0x11
 #define ST7735_PTLON   0x12
 #define ST7735_NORON   0x13

 #define ST7735_INVOFF  0x20
 #define ST7735_INVON   0x21
 #define ST7735_DISPOFF 0x28
 #define ST7735_DISPON  0x29
 #define ST7735_CASET   0x2A
 #define ST7735_RASET   0x2B
 #define ST7735_RAMWR   0x2C
 #define ST7735_RAMRD   0x2E

 #define ST7735_PTLAR   0x30
 #define ST7735_COLMOD  0x3A
 #define ST7735_MADCTL  0x36

 #define ST7735_FRMCTR1 0xB1
 #define ST7735_FRMCTR2 0xB2
 #define ST7735_FRMCTR3 0xB3
 #define ST7735_INVCTR  0xB4
 #define ST7735_DISSET5 0xB6

 #define ST7735_PWCTR1  0xC0
 #define ST7735_PWCTR2  0xC1
 #define ST7735_PWCTR3  0xC2
 #define ST7735_PWCTR4  0xC3
 #define ST7735_PWCTR5  0xC4
 #define ST7735_VMCTR1  0xC5

 #define ST7735_RDID1   0xDA
 #define ST7735_RDID2   0xDB
 #define ST7735_RDID3   0xDC
 #define ST7735_RDID4   0xDD

 #define ST7735_PWCTR6  0xFC

 #define ST7735_GMCTRP1 0xE0
 #define ST7735_GMCTRN1 0xE1

 // Color definitions
 #define	ST7735_BLACK   0x0000
 #define	ST7735_BLUE    0x001F
 #define	ST7735_RED     0xF800
 #define	ST7735_GREEN   0x07E0
 #define ST7735_CYAN    0x07FF
 #define ST7735_MAGENTA 0xF81F
 #define ST7735_YELLOW  0xFFE0
 #define ST7735_WHITE 0xFFFF


/**
  * @}
  */

/** @defgroup ADAFRUIT_SPI_LCD_Exported_Functions
  * @{
  */
void     st7735_Init(void);
uint16_t st7735_ReadID(void);

void     st7735_DisplayOn(void);
void     st7735_DisplayOff(void);
void     st7735_SetCursor(uint16_t Xpos, uint16_t Ypos);
void     st7735_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode);
void     st7735_WriteReg(uint8_t LCDReg, uint8_t LCDRegValue);
uint8_t  st7735_ReadReg(uint8_t LCDReg);

void     st7735_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     st7735_DrawHLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     st7735_DrawVLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos, uint16_t Length);

uint16_t st7735_GetLcdPixelWidth(void);
uint16_t st7735_GetLcdPixelHeight(void);
void     st7735_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);

/* LCD driver structure */
extern LCD_DrvTypeDef   st7735_drv;

/* LCD IO functions */
void     LCD_IO_Init(void);
void     LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void     LCD_IO_WriteReg(uint8_t Reg);
void     LCD_Delay(uint32_t delay);
/**
  * @}
  */

#define DELAY 0x80
static const uint8_t
  Bcmd[] = {                  // Initialization commands for 7735B screens
    18,                       // 18 commands in list:
    ST7735_SWRESET,   DELAY,  //  1: Software reset, no args, w/delay
      50,                     //     50 ms delay
    ST7735_SLPOUT ,   DELAY,  //  2: Out of sleep mode, no args, w/delay
      255,                    //     255 = 500 ms delay
    ST7735_COLMOD , 1+DELAY,  //  3: Set color mode, 1 arg + delay:
      0x05,                   //     16-bit color
      10,                     //     10 ms delay
    ST7735_FRMCTR1, 3+DELAY,  //  4: Frame rate control, 3 args + delay:
      0x00,                   //     fastest refresh
      0x06,                   //     6 lines front porch
      0x03,                   //     3 lines back porch
      10,                     //     10 ms delay
    ST7735_MADCTL , 1      ,  //  5: Memory access ctrl (directions), 1 arg:
      0x08,                   //     Row addr/col addr, bottom to top refresh
    ST7735_DISSET5, 2      ,  //  6: Display settings #5, 2 args, no delay:
      0x15,                   //     1 clk cycle nonoverlap, 2 cycle gate
                              //     rise, 3 cycle osc equalize
      0x02,                   //     Fix on VTL
    ST7735_INVCTR , 1      ,  //  7: Display inversion control, 1 arg:
      0x0,                    //     Line inversion
    ST7735_PWCTR1 , 2+DELAY,  //  8: Power control, 2 args + delay:
      0x02,                   //     GVDD = 4.7V
      0x70,                   //     1.0uA
      10,                     //     10 ms delay
    ST7735_PWCTR2 , 1      ,  //  9: Power control, 1 arg, no delay:
      0x05,                   //     VGH = 14.7V, VGL = -7.35V
    ST7735_PWCTR3 , 2      ,  // 10: Power control, 2 args, no delay:
      0x01,                   //     Opamp current small
      0x02,                   //     Boost frequency
    ST7735_VMCTR1 , 2+DELAY,  // 11: Power control, 2 args + delay:
      0x3C,                   //     VCOMH = 4V
      0x38,                   //     VCOML = -1.1V
      10,                     //     10 ms delay
    ST7735_PWCTR6 , 2      ,  // 12: Power control, 2 args, no delay:
      0x11, 0x15,
    ST7735_GMCTRP1,16      ,  // 13: Magical unicorn dust, 16 args, no delay:
      0x09, 0x16, 0x09, 0x20, //     (seriously though, not sure what
      0x21, 0x1B, 0x13, 0x19, //      these config values represent)
      0x17, 0x15, 0x1E, 0x2B,
      0x04, 0x05, 0x02, 0x0E,
    ST7735_GMCTRN1,16+DELAY,  // 14: Sparkles and rainbows, 16 args + delay:
      0x0B, 0x14, 0x08, 0x1E, //     (ditto)
      0x22, 0x1D, 0x18, 0x1E,
      0x1B, 0x1A, 0x24, 0x2B,
      0x06, 0x06, 0x02, 0x0F,
      10,                     //     10 ms delay
    ST7735_CASET  , 4      ,  // 15: Column addr set, 4 args, no delay:
      0x00, 0x02,             //     XSTART = 2
      0x00, 0x81,             //     XEND = 129
    ST7735_RASET  , 4      ,  // 16: Row addr set, 4 args, no delay:
      0x00, 0x02,             //     XSTART = 1
      0x00, 0x81,             //     XEND = 160
    ST7735_NORON  ,   DELAY,  // 17: Normal display on, no args, w/delay
      10,                     //     10 ms delay
    ST7735_DISPON ,   DELAY,  // 18: Main screen turn on, no args, w/delay
      255 },                  //     255 = 500 ms delay

  Rcmd1[] = {                 // Init for 7735R, part 1 (red or green tab)
    15,                       // 15 commands in list:
    ST7735_SWRESET,   DELAY,  //  1: Software reset, 0 args, w/delay
      150,                    //     150 ms delay
    ST7735_SLPOUT ,   DELAY,  //  2: Out of sleep mode, 0 args, w/delay
      255,                    //     500 ms delay
    ST7735_FRMCTR1, 3      ,  //  3: Frame rate ctrl - normal mode, 3 args:
      0x01, 0x2C, 0x2D,       //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
    ST7735_FRMCTR2, 3      ,  //  4: Frame rate control - idle mode, 3 args:
      0x01, 0x2C, 0x2D,       //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
    ST7735_FRMCTR3, 6      ,  //  5: Frame rate ctrl - partial mode, 6 args:
      0x01, 0x2C, 0x2D,       //     Dot inversion mode
      0x01, 0x2C, 0x2D,       //     Line inversion mode
    ST7735_INVCTR , 1      ,  //  6: Display inversion ctrl, 1 arg, no delay:
      0x07,                   //     No inversion
    ST7735_PWCTR1 , 3      ,  //  7: Power control, 3 args, no delay:
      0xA2,
      0x02,                   //     -4.6V
      0x84,                   //     AUTO mode
    ST7735_PWCTR2 , 1      ,  //  8: Power control, 1 arg, no delay:
      0xC5,                   //     VGH25 = 2.4C VGSEL = -10 VGH = 3 * AVDD
    ST7735_PWCTR3 , 2      ,  //  9: Power control, 2 args, no delay:
      0x0A,                   //     Opamp current small
      0x00,                   //     Boost frequency
    ST7735_PWCTR4 , 2      ,  // 10: Power control, 2 args, no delay:
      0x8A,                   //     BCLK/2, Opamp current small & Medium low
      0x2A,
    ST7735_PWCTR5 , 2      ,  // 11: Power control, 2 args, no delay:
      0x8A, 0xEE,
    ST7735_VMCTR1 , 1      ,  // 12: Power control, 1 arg, no delay:
      0x0E,
    ST7735_INVOFF , 0      ,  // 13: Don't invert display, no args, no delay
    ST7735_MADCTL , 1      ,  // 14: Memory access control (directions), 1 arg:
      0xC8,                   //     row addr/col addr, bottom to top refresh
    ST7735_COLMOD , 1      ,  // 15: set color mode, 1 arg, no delay:
      0x05 },                 //     16-bit color

  Rcmd2green[] = {            // Init for 7735R, part 2 (green tab only)
    2,                        //  2 commands in list:
    ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x02,             //     XSTART = 0
      0x00, 0x7F+0x02,        //     XEND = 127
    ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x01,             //     XSTART = 0
      0x00, 0x9F+0x01 },      //     XEND = 159
  Rcmd2red[] = {              // Init for 7735R, part 2 (red tab only)
    2,                        //  2 commands in list:
    ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x00,             //     XSTART = 0
      0x00, 0x7F,             //     XEND = 127
    ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x00,             //     XSTART = 0
      0x00, 0x9F },           //     XEND = 159

  Rcmd2green144[] = {              // Init for 7735R, part 2 (green 1.44 tab)
    2,                        //  2 commands in list:
    ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
      0x00, 0x00,             //     XSTART = 0
      0x00, 0x7F,             //     XEND = 127
    ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
      0x00, 0x00,             //     XSTART = 0
      0x00, 0x7F },           //     XEND = 127

  Rcmd3[] = {                 // Init for 7735R, part 3 (red or green tab)
    4,                        //  4 commands in list:
    ST7735_GMCTRP1, 16      , //  1: Magical unicorn dust, 16 args, no delay:
      0x02, 0x1c, 0x07, 0x12,
      0x37, 0x32, 0x29, 0x2d,
      0x29, 0x25, 0x2B, 0x39,
      0x00, 0x01, 0x03, 0x10,
    ST7735_GMCTRN1, 16      , //  2: Sparkles and rainbows, 16 args, no delay:
      0x03, 0x1d, 0x07, 0x06,
      0x2E, 0x2C, 0x29, 0x2D,
      0x2E, 0x2E, 0x37, 0x3F,
      0x00, 0x00, 0x02, 0x10,
    ST7735_NORON  ,    DELAY, //  3: Normal display on, no args, w/delay
      10,                     //     10 ms delay
    ST7735_DISPON ,    DELAY, //  4: Main screen turn on, no args w/delay
100 }; //     100 ms delay
#define TFTLCD_DELAY 0xFF
static const uint16_t _regValues_big[] = {
	  /* Start Initial Sequence --------------------------------------------------*/
	  LCD_REG_0, 0x0001, /* Start internal OSC. */
	  LCD_REG_1, 0x0000, /* Set SS and SM bit */
	  LCD_REG_2, 0x0700, /* Set 1 line inversion */
	  LCD_REG_3, 0x1030, /* Set GRAM write direction and BGR=1. */
	  LCD_REG_4, 0x0000, /* Resize register */
		/////
	  LCD_REG_8, 0x0207, /* Set the back porch and front porch */
	  LCD_REG_9, 0x0000, /* Set non-display area refresh cycle ISC[3:0] */
	  LCD_REG_10, 0x0000, /* FMARK function */
	  LCD_REG_12, 0x0000, /* RGB interface setting */
	  LCD_REG_13, 0x0000, /* Frame marker Position */
	  LCD_REG_15, 0x0000, /* RGB interface polarity */

	  /* Power On sequence -------------------------------------------------------*/
	  LCD_REG_16, 0x0000, /* SAP, BT[3:0], AP, DSTB, SLP, STB */
	  LCD_REG_17, 0x0000, /* DC1[2:0], DC0[2:0], VC[2:0] */
	  LCD_REG_18, 0x0000, /* VREG1OUT voltage */
	  LCD_REG_19, 0x0000, /* VDV[4:0] for VCOM amplitude */

	  LCD_REG_16, 0x17B0, /* SAP, BT[3:0], AP, DSTB, SLP, STB */
	  LCD_REG_17, 0x0137, /* DC1[2:0], DC0[2:0], VC[2:0] */

	  LCD_REG_18, 0x0139, /* VREG1OUT voltage */

	  LCD_REG_19, 0x1d00, /* VDV[4:0] for VCOM amplitude */
	  LCD_REG_41, 0x0013, /* VCM[4:0] for VCOMH */

	  LCD_REG_32, 0x0000, /* GRAM horizontal Address */
	  LCD_REG_33, 0x0000, /* GRAM Vertical Address */

	  /* Adjust the Gamma Curve (ILI9325) ----------------------------------------*/
	  LCD_REG_48, 0x0007,
	  LCD_REG_49, 0x0302,
	  LCD_REG_50, 0x0105,
	  LCD_REG_53, 0x0206,
	  LCD_REG_54, 0x0808,
	  LCD_REG_55, 0x0206,
	  LCD_REG_56, 0x0504,
	  LCD_REG_57, 0x0007,
	  LCD_REG_60, 0x0105,
	  LCD_REG_61, 0x0808,
	  /* Set GRAM area -----------------------------------------------------------*/
	  LCD_REG_80, 0x0000, /* Horizontal GRAM Start Address */
	  LCD_REG_81, 0x00EF, /* Horizontal GRAM End Address */
	  LCD_REG_82, 0x0000, /* Vertical GRAM Start Address */
	  LCD_REG_83, 0x0013F, /* Vertical GRAM End Address */

	  LCD_REG_96,  0x2700, /* Gate Scan Line(GS=1, scan direction is G320~G1) */
	  LCD_REG_97,  0x0001, /* NDL,VLE, REV */
	  LCD_REG_106, 0x0000, /* set scrolling line */

	  /* Partial Display Control -------------------------------------------------*/
	  LCD_REG_128, 0x0000,
	  LCD_REG_129, 0x0000,
	  LCD_REG_130, 0x0000,
	  LCD_REG_131, 0x0000,
	  LCD_REG_132, 0x0000,
	  LCD_REG_133, 0x0000,

	  /* Panel Control -----------------------------------------------------------*/
	  LCD_REG_144, 0x0010,
	  LCD_REG_146, 0x0000,
	  LCD_REG_147, 0x0003,
	  LCD_REG_149, 0x0110,
	  LCD_REG_151, 0x0000,
	  LCD_REG_152, 0x0000,

	  /* set GRAM write direction and BGR = 1 */
	  /* I/D=00 (Horizontal : increment, Vertical : decrement) */
	  /* AM=1 (address is updated in vertical writing direction) */
	  LCD_REG_3, 0x1028,

	  /* 262K color and display ON */
	  LCD_REG_7, 0x0173,
	  /* Set the Cursor */};

#ifdef __cplusplus
}
#endif

#endif /* __ST7735_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
