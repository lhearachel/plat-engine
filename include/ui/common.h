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

/**
 * Registers an object on the UI and returns a pointer to it.
 * 
 * Original function: 0x0200CE6C (arm9)
 * 
 * @param actorSys  System data for the object.
 * @param actorRes  Resources for the object.
 * @param params    Extra parameters for the object.
 * @return          The newly-registered object.
 */
struct CellActor* __attribute__((long_call)) UI_AddObject(
    struct CellActorSystem *actorSys,
    struct CellActorResource *actorRes,
    const struct CellActorParams *params
);

/**
 * Frees an object from the UI.
 * 
 * Original function: 0x0200D0F4 (arm9)
 * 
 * @param actor     The object to be freed.
 */
void __attribute__((long_call)) UI_FreeObject(struct CellActor *actor);

// CATS_ObjectPosGetCap
/**
 * Get the position of an object in X,Y space on the screen.
 * 
 * Original function: 0x0200D550 (arm9)
 * 
 * @param actor
 * @param[out] x
 * @param[out] y
 */
void __attribute__((long_call)) UI_GetObjectPos(struct CellActor *actor, s16 *x, s16 *y);

/**
 * Set the position of an object in X,Y space on the screen.
 * 
 * Original function: 0x0200D4C4 (arm9)
 * 
 * @param actor
 * @param x
 * @param y
 */
void __attribute__((long_call)) UI_SetObjectPos(struct CellActor *actor, s16 x, s16 y);

/**
 * Assigns an animation to be played.
 * 
 * Original function: 0x02021D6C (arm9)
 * 
 * @param anim  The animation system for an actor.
 * @param frame Which frame of the NCER file to show.
 */
void __attribute__((long_call)) UI_SetAnimation(void *anim, u32 frame);

/**
 * Enable the object for display.
 * 
 * Original function: 0x0200D3EC (arm9)
 * 
 * @param anim
 * @param enable
 */
void __attribute__((long_call)) UI_EnableObject(void *anim, int enable);

/**
 * Increment the animation by a frame.
 * 
 * Original function: 0x0200D324 (arm9)
 * 
 * @param anim
 */
void __attribute__((long_call)) UI_UpdateObject(void *anim);

/**
 * Set an object's OAM mode.
 * 
 * Original function: 0x0200D810 (arm9)
 * 
 * @param actor
 * @param objMode
 */
void __attribute__((long_call)) UI_SetObjectOAMMode(struct CellActor *actor, int objMode);

/**
 * Add a function to task control with specified data and return a reference
 * to the task.
 * 
 * Original function: 0x0200D9E8 (arm9)
 * 
 * @param func
 * @param data
 * @param priority
 */
void* __attribute__((long_call)) TaskControl_Add(TaskControlFunc func, void *data, u32 priority);

/**
 * Remove a task from task control.
 * 
 * Original function: 0x0200DA58 (arm9)
 * 
 * @param taskControl
 */
void __attribute__((long_call)) TaskControl_Delete(void *taskControl);

#endif // __UI_COMMON_H