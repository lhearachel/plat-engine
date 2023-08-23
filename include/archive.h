#ifndef __ARCHIVE_H
#define __ARCHIVE_H

#define ARCHIVE_SUBSCR      1
#define ARCHIVE_POKESPRITE  4
#define ARCHIVE_EVOLUTIONS 34

/**
 * @brief Load data from an archive into an allocated buffer.
 * 
 * Original Function: [`LoadFromNARC @ 0x02006AA4` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_NARC.s#L249)
 * 
 * @param[out] data         Allocated buffer to fill with data from the NARC.
 * @param[in]  archiveID    ID of the NARC from which to load data.
 * @param[in]  dataID       ID of data within the NARC to be loaded.
 */
void  __attribute__((long_call)) LoadFromNARC(void *data, int archiveID, int dataID);

/**
 * @brief Load data from an archive, allocate a buffer for it, and return the
 * allocated data block.
 * 
 * Original Function: [`LoadFromNARC_2 @ 0x02006AC0` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_NARC.s#L275)
 * 
 * @param[in]  archiveID    ID of the NARC from which to load data.
 * @param[in]  dataID       ID of data within the NARC to be loaded.
 * @param[in]  heapID       ID of the heap which will own the allocated memory.
 * @return                  Address of allocated memory block containing the data.
 */
void* __attribute__((long_call)) LoadFromNARC_Malloc(int archiveID, int dataID, int heapID);

/**
 * @brief Load data from an archive with a specified offset into an allocated
 * buffer.
 * 
 * Original Function: [`LoadFromNARC_3 @ 0x02006AFC` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_NARC.s#L322)
 * 
 * @param[out] data         Allocated buffer to fill with data from the NARC.
 * @param[in]  archiveID    ID of the NARC from which to load data.
 * @param[in]  dataID       ID of data within the NARC to be loaded.
 * @param[in]  offset       Additional offset into the NARC to increment the cursor.   
 * @param[in]  size         Maximum data size to be read.
 */
void  __attribute__((long_call)) LoadFromNARC_Offset(void *data, int archiveID, int dataID, int offset, int size);

/**
 * @brief Load data from an archive with a specified offset, allocate a buffer
 * for it, and return the allocated data block.
 * 
 * Original Function: [`LoadFromNARC_5 @ 0x02006B18` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_NARC.s#L344)
 * 
 * @param[in]  archiveID    ID of the NARC from which to load data.
 * @param[in]  dataID       ID of data within the NARC to be loaded.
 * @param[in]  heapID       ID of the heap which will own the allocated memory.
 * @param[in]  offset       Additional offset into the NARC to increment the cursor. 
 * @param[in]  size         Maximum data size to be read.
 * @return                  Address of allocated memory block containing the data.
 */
void* __attribute__((long_call)) LoadFromNARC_OffsetAndMalloc(int archiveID, int dataID, int heapID, int offset, int size);

#endif // __ARCHIVE_H