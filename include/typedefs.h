#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <stdint.h>

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
typedef int64_t     s64;

#define NULL        ((void *) 0)
#define TRUE        1
#define FALSE       0

typedef u8          bool8;
typedef u16         bool16;
typedef u32         bool32;
typedef int         BOOL;

#endif // __TYPEDEFS_H