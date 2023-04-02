#ifndef __GLOBAL_H
#define __GLOBAL_H

#include "archive.h"
#include "config.h"
#include "types.h"

#define NELEMS(array)       (sizeof(array) / sizeof(array[0]))
#define OFFSET_OF(st, m)    ((u32) &(((st *) 0)->m))

#define ALIGN4      __attribute__((aligned(4)))

#define HI_HALF(n)  (((n) & 0xFFFF0000) >> 16)
#define LO_HALF(n)  (((n) & 0x0000FFFF))

void  __attribute__((long_call)) GF_ASSERT(u32 cond);
u16   __attribute__((long_call)) GF_RAND(void);
u16   __attribute__((long_call)) SQRT(u32 n);

void  __attribute__((long_call)) sys_FreeMemory(void *st);
void* __attribute__((long_call)) sys_AllocMemory(u32 heapId, u32 size);

#endif // __GLOBAL_H