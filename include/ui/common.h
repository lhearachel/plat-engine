#ifndef __UI_COMMON_H
#define __UI_COMMON_H

#include "archive.h"
#include "typedefs.h"

typedef void (*TaskControlFunc)(void*, void*);

struct CellActorParams {
    s16     x, y, z;
    
    u16     anmFrame;
    int     priority;
    int     palette;
    int     renderArea;

    int     id[6];

    int     bgPriority;
    int     vramTransfer;
};

struct CellActor {
    void    *anim;
    void    *animHeader;
    void    *animHeaderTable;

    int     vramTransfer;
};

struct CellActorSystem {
    int     heapID;
    int     resourceID;
    int     useRender;

    void    *vramCellTransferState;

    // undocumented: render data
};

struct CellActorResource {
    void    *cellActorSet;
    void    *cellActorHeaderTable;
    void    *resourceHeader;
    void    *resourceManager[6];
    void    *resourceObjects[6];

    int     resourceObjectIDs[6];
    int     resourceTypeID;
};

struct PaletteFadeParams {
    u16     fadeMask;

    u16     wait        :6,
            nowEvy      :5,
            endEvy      :5;
        
    u16     nextRGB     :15,
            direction   :1;
    
    u16     fadeValue   :4,
            waitCount   :6,
            _dummy      :6;
};

struct PaletteFadeHeader {
    u16     *defWork;
    u16     *transWork;
    u32     size;

    struct PaletteFadeParams params;
};

struct PaletteFade {
    struct PaletteFadeHeader data[14];

    u16     stateFlag       :2,
            requestMask     :14;

    u16     transferMask    :14,
            tcbFlag         :1,
            autoTransfer    :1;

    u8      forceStop;

    u8      dummy[3];
};

struct Palette {
    u16     red     :5,
            green   :5,
            blue    :5,
            _dummy  :1;
};

enum PaletteFadeRequest {
    FADE_MAIN_BACKGROUND = 0,
    FADE_SUB_BACKGROUND,
    FADE_MAIN_OBJECT,
    FADE_SUB_OBJECT,

	FADE_MAIN_BG_EX0,
	FADE_MAIN_BG_EX1,
	FADE_MAIN_BG_EX2,
	FADE_MAIN_BG_EX3,
	FADE_SUB_BG_EX0,
	FADE_SUB_BG_EX1,
	FADE_SUB_BG_EX2,
	FADE_SUB_BG_EX3,
	FADE_MAIN_OBJ_EX,
	FADE_SUB_OBJ_EX
};

// CATS_LoadResourcePlttWorkArcH
u8   __attribute__((long_call)) UI_LoadArchivePalette(
    struct PaletteFade *paletteFade,
    enum PaletteFadeRequest request,
    struct CellActorSystem *actorSys,
    struct CellActorResource *actorRes,
    void *archiveHandle,
    int dataID,
    int comp,
    int num,
    int transferMode,
    int id
);

// CATS_LoadResourceCharArcH
BOOL __attribute__((long_call)) UI_LoadArchiveData(
    struct CellActorSystem *actorSys,
    struct CellActorResource *actorRes,
    void *archiveHandle,
    int dataID,
    int comp,
    int transferMode,
    int id
);

// CATS_LoadResourceCellArcH
BOOL __attribute__((long_call)) UI_LoadArchiveCells(
    struct CellActorSystem *actorSys,
    struct CellActorResource *actorRes,
    void *archiveHandle,
    int dataID,
    int comp,
    int id
);

// CATS_LoadResourceCellAnmArcH
BOOL __attribute__((long_call)) UI_LoadArchiveAnim(
    struct CellActorSystem *actorSys,
    struct CellActorResource *actorRes,
    void *archiveHandle,
    int dataID,
    int comp,
    int id
);

// CATS_ObjectAdd_S
struct CellActor* __attribute__((long_call)) UI_AddObject(
    struct CellActorSystem *actorSys,
    struct CellActorResource *actorRes,
    const struct CellActorParams *params
);

// CATS_ActorPointerDelete_S
void __attribute__((long_call)) UI_FreeActor(struct CellActor *actor);

// CATS_ObjectPosGetCap
void __attribute__((long_call)) UI_GetObjectPos(struct CellActor *actor, s16 *x, s16 *y);

// CATS_ObjectPosSetCap
void __attribute__((long_call)) UI_SetObjectPos(struct CellActor *actor, s16 x, s16 y);

// CLACT_AnmChg
void __attribute__((long_call)) UI_SetAnimation(void *anim, u32 num);

// CATS_ObjectEnable
void __attribute__((long_call)) UI_EnableObject(void *anim, int enable);

// CATS_ObjectUpdate
void __attribute__((long_call)) UI_UpdateObject(void *anim);

// CATS_ObjectObjModeSetCap
void __attribute__((long_call)) UI_SetObjectOAMMode(struct CellActor *actor, int objMode);

// TCB_Add
void* __attribute__((long_call)) TaskControl_Add(TaskControlFunc func, void *data, u32 priority);

// TCB_Delete
void __attribute__((long_call)) TaskControl_Delete(void *taskControl);

#endif // __UI_COMMON_H