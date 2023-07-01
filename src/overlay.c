#include "global.h"
#include "overlay.h"

struct LinkedOverlayPair gLinkedOverlayPairs[1] = {
    { 16, 123}, // battle overlay extension
};

//#define DEBUG_OVERLAYS

void Overlay_Unload(u32 overlayID)
{
    u8 buf[50];

unload:
#ifdef DEBUG_OVERLAYS
    sprintf(buf, "Freed overlay %d.\n", overlayID);
    debugsyscall(buf);
#endif
    struct LoadedOverlay *loadedOverlays = Overlay_LoadedInRegion(Overlay_MemoryRegion(overlayID));
    for (int i = 0; i < 8; i++) {
        if (loadedOverlays[i].active == TRUE && loadedOverlays[i].id == overlayID) {
            Overlay_Free(&loadedOverlays[i]);
            break;
        }
    }

    for (int i = 0; i < NELEMS(gLinkedOverlayPairs); i++) {
        if (gLinkedOverlayPairs[i].original == overlayID)
        {
            overlayID = gLinkedOverlayPairs[i].extension;
            goto unload;
        }
    }
}

typedef BOOL (*OverlayLoadFunc)(u32, u32);

BOOL Overlay_LoadWithExtension(u32 overlayID, u32 loadType)
{
    int i;
    u32 dmaBackup = FS_DMA_DO_NOT_USE;
    u8 buf[64];

load:
    if (!Overlay_CanLoad(overlayID)) {
        return FALSE;
    }

    u32 overlayRegion = Overlay_MemoryRegion(overlayID);
    struct LoadedOverlay *loadedOverlays = Overlay_LoadedInRegion(overlayRegion);

    for (i = 0; i < 8; i++) {
        if (loadedOverlays[i].active == FALSE) {
            struct LoadedOverlay *overlay = &loadedOverlays[i];
            overlay->active = TRUE;
            overlay->id = overlayID;
            break;
        }
    }

#ifdef DEBUG_OVERLAYS
    sprintf(buf, "Loaded in overlay_%04d.bin. Total of %d overlays loaded.\n", overlayID, i+1);
    debugsyscall(buf);
#endif

    if (i >= 8) {
#ifdef DEBUG_OVERLAYS
        sprintf(buf, "ERROR: Too many overlays loaded!\n");
        debugsyscall(buf);
#endif
        return FALSE;
    }

    if (overlayRegion == 1 || overlayRegion == 2) {
        dmaBackup = FS_SetDefaultDMA(FS_DMA_DO_NOT_USE);
    }

    OverlayLoadFunc loadFunc;
    switch (loadType) {
        case 0:
            loadFunc = &Overlay_Load;
            break;
        case 1:
            loadFunc = &Overlay_LoadAndStart;
            break;
        case 2:
            loadFunc = &Overlay_LoadAndStartAsync;
            break;
        default:
            return FALSE;
    }
    BOOL result = loadFunc(0, overlayID);

    if (overlayRegion == 1 || overlayRegion == 2) {
        FS_SetDefaultDMA(dmaBackup);
    }

    if (result == FALSE) {
#ifdef DEBUG_OVERLAYS
        sprintf(buf, "Failed to load overlay_%04d.bin.\n", overlayID);
        debugsyscall(buf);
#endif
        return FALSE;
    }

    for (i = 0; i < NELEMS(gLinkedOverlayPairs); i++) {
        if (gLinkedOverlayPairs[i].original == overlayID) {
#ifdef DEBUG_OVERLAYS
            sprintf(buf, "Need to load linked overlay_%04d.bin.\n", gLinkedOverlayPairs[i].extension);
            debugsyscall(buf);
#endif
            overlayID = gLinkedOverlayPairs[i].extension;
            loadType = 2;
            goto load;
        }
    }

    return TRUE;
}
