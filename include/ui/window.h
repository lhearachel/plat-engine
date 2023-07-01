#ifndef __UI_BASE_H
#define __UI_BASE_H

#include "typedefs.h"

#include "lib/string.h"

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

typedef BOOL (*PrintStringCallback)(void*, u16);

/**
 * @brief Adds a window at the specified position with certain dimensions.
 * 
 * Original function: 0x0201A7E8 (arm9)
 */
void __attribute__((long_call)) Window_Add(
    void *bgl,
    struct Window *window,
    u8 frameNumber,
    u8 posX,
    u8 posY,
    u8 sizX,
    u8 sizY,
    u8 paletteNumber,
    u16 chrOffset
);

/**
 * @brief Deletes a window from the BGL.
 * 
 * Original function: 0x0201A8FC (arm9)
 */
void __attribute__((long_call)) Window_Delete(struct Window *window);

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

/**
 * @brief Prints a string into the window with the specified font ID.
 * 
 * Original function: 0x0201D738 (arm9)
 * 
 * @param window
 * @param fontID
 * @param string
 * @param xOffset
 * @param yOffset
 * @param callback
 */
u8   __attribute__((long_call)) Window_PrintString(
    struct Window *window,
    u32 fontID,
    const struct String *string,
    u32 xOffset,
    u32 yOffset,
    u32 waitTime,
    PrintStringCallback callback
);

/**
 * @brief Clear a window's painted data.
 * 
 * Original function: 0x0200E084 (arm9)
 */
void __attribute__((long_call)) Window_Clear(struct Window *window, u8 transfer);

#endif // __UI_BASE_H