#ifndef __ARCHIVE_H
#define __ARCHIVE_H

#define ARC_CODE_ADDONS 122

#define CODE_ADDON_SYNTHETIC_NARC_EXTENSION 0
#define CODE_ADDON_HIDDEN_ABILITY_LIST 7

void  __attribute__((long_call)) ArchiveDataLoad(void *data, int archiveID, int dataID);
void* __attribute__((long_call)) ArchiveDataLoadMalloc(int archiveID, int dataID, int heapID);
void  __attribute__((long_call)) ArchiveDataLoadOffset(void *data, int archiveID, int dataID, int offset, int size);
void* __attribute__((long_call)) ArchiveDataLoadOffsetMalloc(int archiveID, int dataID, int heapID, int offset, int size);

#endif // __ARCHIVE_H