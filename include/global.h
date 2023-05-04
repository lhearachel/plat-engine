#ifndef __GLOBAL_H
#define __GLOBAL_H

#include "archive.h"
#include "config.h"
#include "types.h"

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
 * @brief Free a block of memory. The heap to free the block from is determined
 * programmatically.
 * 
 * Original Function: [`free @ 0x020181C4` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_RAM_21bfaf0.s#L548)
 * 
 * @param o The memory block to be freed.
 */
void  __attribute__((long_call)) Free(void *o);

/**
 * @brief Allocate a block of memory on the heap with a given size.
 * 
 * Original Function: [`malloc @ 0x02018144` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_RAM_21bfaf0.s#L460)
 * 
 * @param heapID    ID of the heap which will own this allocated memory.
 * @param size      Desired size of the block to be allocated.
 * @return          Address to the allocated memory block.
 */
void* __attribute__((long_call)) Malloc(u32 heapId, u32 size);

#endif // __GLOBAL_H