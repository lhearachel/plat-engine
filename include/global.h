#ifndef __GLOBAL_H
#define __GLOBAL_H

#include "config.h"
#include "heap.h"
#include "typedefs.h"

#define NELEMS(array)       (sizeof(array) / sizeof(array[0]))
#define OFFSET_OF(st, m)    ((u32) &(((st *) 0)->m))

#define HI_HALF(n)  (((n) & 0xFFFF0000) >> 16)
#define LO_HALF(n)  (((n) & 0x0000FFFF))

/**
 * @brief Generates a pseudo-random number according to the seed.
 * 
 * Original Function: `PRNG @ 0x0201D2E8` (ARM9)
 * 
 * @return Pseudo-random value generated from the starting seed at the current
 * sequence iteration.
 */
u16   __attribute__((long_call)) GF_RAND(void);

/**
 * @brief Fills a memory buffer with the specified data up to a
 * specified size.
 * 
 * Original function: 0x020C4BB8 (ARM9)
 */
void  __attribute__((long_call)) MemFill(u32 data, void *buf, u32 size);

#endif // __GLOBAL_H