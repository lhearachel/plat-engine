#ifndef __LIB_STRING_H
#define __LIB_STRING_H

#include "typedefs.h"

struct String {
    u16 alloc;
    u16 size;
    u32 magic;
    u16 data[1];
};

#endif // __LIB_STRING_H