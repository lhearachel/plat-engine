#ifndef __ITEM_H
#define __ITEM_H

#include "global.h"

struct ItemData {
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

#endif // __ITEM_H