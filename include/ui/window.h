#ifndef __UI_BASE_H
#define __UI_BASE_H

#include "typedefs.h"

struct Window {
    void *ini;
    u8    frameNum;
    u8    posX;
    u8    posY;
    u8    sizX;
    u8    sizY;
    u8    palNum;
    u16   chrOffset :15,
          bitMode    :1;
    void *chrBuffer;
};

/**
 * @brief Fills a window with a particular color.
 * 
 * Original Function: `Function_201ada4_ClearTextBox` (ARM9)
 * 
 * @param[in,out] window
 * @param[in]     color
 */
void __attribute__((long_call)) Window_FillWithColor(struct Window *window, u8 color);

/**
 * @brief Passes the input window to VRAM for display.
 * 
 * Original Function: `Function_201a9a4` (ARM9)
 * 
 * @param[in] window
 */
void __attribute__((long_call)) Window_ToVRAM(struct Window *window);

#endif // __UI_BASE_H