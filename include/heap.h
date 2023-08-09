#ifndef __HEAP_H
#define __HEAP_H

#include "typedefs.h"

#define HEAP_ID_SYSTEM  0
#define HEAP_ID_BATTLE  5
#define HEAP_ID_FIELD  11

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

#endif // __HEAP_H