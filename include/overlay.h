#ifndef __OVERLAY_H
#define __OVERLAY_H

#include "typedefs.h"

struct LinkedOverlayPair {
    u8 original;
    u8 extension;
};

struct LoadedOverlay {
    u32 id;
    BOOL active;
};

#define FS_DMA_DO_NOT_USE ((u32) ~0)

u32  __attribute__((long_call)) FS_SetDefaultDMA(u32 mode);

int  __attribute__((long_call)) Overlay_MemoryRegion(const u32 overlayID); // 0x02006544
void __attribute__((long_call)) Overlay_Free(struct LoadedOverlay *overlay); // 0x020064F0
BOOL __attribute__((long_call)) Overlay_CanLoad(const u32 overlayID); // 0x02006644
BOOL __attribute__((long_call)) Overlay_Load(u32 mode, u32 overlayID); // 0x0200671C
BOOL __attribute__((long_call)) Overlay_LoadAndStart(u32 mode, u32 overlayID); // 0x02006724
BOOL __attribute__((long_call)) Overlay_LoadAndStartAsync(u32 mode, u32 overlayID); // 0x0200675C

struct LoadedOverlay* __attribute__((long_call)) Overlay_LoadedInRegion(int memoryArea); // 0x020066C0

// new functions: overlay.c
void __attribute__((long_call)) Overlay_Unload(u32 overlayID); // hook to 0x02006514
BOOL __attribute__((long_call)) Overlay_LoadWithExtension(u32 overlayID, u32 loadType); // hook to 0x02006590

#endif // __OVERLAY_H