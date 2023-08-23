#ifndef __ITEM_H
#define __ITEM_H

#include "global.h"

struct __attribute__((packed)) ItemData {
    u16 price;
    u8  holdEffect;
    u8  holdPower;

    u8  pluckEffect;
    u8  flingEffect;
    u8  flingPower;
    u8  naturalGiftPower;

    u16 naturalGiftType     :5,
        important           :1,     // important items cannot be thrown away
        canRegister         :1,
        fieldPocket         :4,
        battlePocket        :5;     // not all of these are used
    
    u8  fieldFunc;
    u8  battleFunc;
    u8  workType;

    u8  _dummy;

    u8  work[20];
};

enum ItemDataParam {
    ITEM_PARAM_PRICE,
    ITEM_PARAM_HOLD_EFFECT,
    ITEM_PARAM_HOLD_POWER,
    ITEM_PARAM_IMPORTANT,
    ITEM_PARAM_CAN_REGISTER,
    ITEM_PARAM_POCKET,
    ITEM_PARAM_FIELD_FUNC,
    ITEM_PARAM_BATTLE_FUNC,
    // ...
};

/**
 * @brief Get a value from the item data table.
 * 
 * Original function: 0x0207CFF0 (arm9)
 */
s32 __attribute__((long_call)) Item_Get(u16 itemID, u16 param, u32 heapID);

#endif // __ITEM_H