#include "global.h"
#include "sound.h"

#include "battle/client.h"
#include "battle/scio.h"
#include "battle/server.h"

#include "ui/battle.h"
#include "ui/common.h"
#include "ui/g2.h"

#if 0

// ========================================================================= //
//                          LOAD THE RESOURCE                                //
// ========================================================================= //

void Client_PopupResourceLoad(void *battle, struct BattleClient *client)
{
    struct CellActorSystem   *actorSys    = Battle_GetClientActorSys(battle);
    struct CellActorResource *actorRes    = Battle_GetClientActorRes(battle);
    struct PaletteFade       *paletteFade = Battle_GetPaletteFade(battle);

    PartyGauge_Load(actorSys, actorRes, paletteFade);

    SCIO_ClearQueue(battle, client->clientNum, CLIENT_POPUP_RESOURCE_LOAD);
    ClientCommand_Reset(client);
}

// ========================================================================= //
//                          FREE THE RESOURCE                                //
// ========================================================================= //

void Client_PopupResourceFree(void *battle, struct BattleClient *client)
{
    struct CellActorResource *actorRes = Battle_GetClientActorRes(battle);

    PartyGauge_Free(actorRes);

    SCIO_ClearQueue(battle, client->clientNum, CLIENT_POPUP_RESOURCE_FREE);
    ClientCommand_Reset(client);
}

// ========================================================================= //
//                          EXTRA POPUP STUFF                                //
// ========================================================================= //

#define ARROW_IN_SPEED  0x1200
#define ARROW_OUT_SPEED 0x0400
#define ARROW_ALPHA_OUT_SPEED 0x0100

struct PopupArrow {
    struct CellActor    *actor;
    void                *taskControl;

    BOOL scrollOut;
    BOOL enemySide;
    s32  x;
    s16  alpha;
    u8   seqNum;
    u8   startWait;
};

static struct PopupArrow *sPopupArrow;

static const struct CellActorParams PopupArrowParams = {
    0, 0, 0,        // (x, y, z)
    0,              // starting frame
    10,             // priority
    0,              // palette ID
    1,              // 2D main VRAM
    {
        20413,      // party gauge data
        20037,      // party gauge palette
        20407,      // party gauge cells
        20396,      // party gauge animation
        0xFFFFFFFF,
        0xFFFFFFFF,
    },
    0,
    0
};

// ========================================================================= //
//                            SHOW THE POPUP                                 //
// ========================================================================= //

static void TaskControl_PopupShow(void *taskControl, void *taskData)
{
    struct PopupTaskControl *popupTask = taskData;
    BOOL enemySide = popupTask->clientNum & 1;

    struct CellActorSystem   *actorSys = Battle_GetClientActorSys(popupTask->battle);
    struct CellActorResource *actorRes = Battle_GetClientActorRes(popupTask->battle);

    switch (popupTask->seqNum) {
        case 0:         // Initialization
            Popup_ArrowIn(enemySide, actorSys, actorRes);
            popupTask->seqNum++;
            break;
        case 1:         // Mid-Animation
            if (sPopupArrow->taskControl == NULL) { // Check if we're done
                popupTask->seqNum++;
            }
            break;
        default:        // Done, cleanup
            SCIO_ClearQueue(popupTask->battle, popupTask->clientNum, CLIENT_POPUP_IN);
            Free(taskData);
            TaskControl_Delete(taskControl);
            break;
    }
}

static void TaskControl_ArrowShow(void *taskControl, void *taskData)
{
    struct PopupArrow *arrow = taskData;
    switch (arrow->seqNum) {
        case 0:
            s16 x, y;
            UI_GetObjectPos(arrow->actor, &x, &y);
            arrow->x = x << 8;
            arrow->seqNum++;
            // FALL THROUGH
        case 1:
            if (arrow->enemySide) {
                arrow->x -= ARROW_IN_SPEED;
                if (arrow->x <= 224 << 8) {
                    arrow->x =  224 << 8;
                    arrow->seqNum++;
                }
                UI_SetObjectPos(arrow->actor, arrow->x >> 8,  64);
            } else {
                arrow->x += ARROW_IN_SPEED;
                if (arrow->x >= 32 << 8) {
                    arrow->x  = 32 << 8;
                    arrow->seqNum++;
                }
                UI_SetObjectPos(arrow->actor, arrow->x >> 8, 120);
            }
            break;
        default:
            TaskControl_Delete(taskControl);
            arrow->taskControl = NULL;
            return;
    } 
}

static void Popup_ArrowIn(BOOL enemySide, struct CellActorSystem *actorSys, struct CellActorResource *actorRes)
{
    sPopupArrow = Malloc(HEAP_ID_BATTLE, sizeof(struct PopupArrow));
    sPopupArrow->actor = UI_AddObject(actorSys, actorRes, &PopupArrowParams);
    if (enemySide) {
        UI_SetObjectPos(sPopupArrow->actor, 256 + 96,  64);
        UI_SetAnimation(sPopupArrow->actor->anim, 8);
    } else {
        UI_SetObjectPos(sPopupArrow->actor,   0 - 96, 120);
        UI_SetAnimation(sPopupArrow->actor->anim, 7);
    }

    UI_UpdateObject(sPopupArrow->actor->anim);

    sPopupArrow->enemySide   = enemySide;
    sPopupArrow->seqNum      = 0;
    sPopupArrow->taskControl = TaskControl_Add(TaskControl_ArrowShow, sPopupArrow, 500);

    Sound_PlaySE(1633);
}

static void Client_PopupShow(void *battle, struct BattleClient *client)
{
    struct PopupTaskControl *popupTask = Malloc(HEAP_ID_BATTLE, sizeof(struct PopupTaskControl));
    popupTask->seqNum      = 0;
    popupTask->battle      = battle;
    popupTask->commandCode = CLIENT_POPUP_IN;
    popupTask->clientNum   = client->clientNum;

    TaskControl_Add(TaskControl_PopupShow, popupTask, 1);
}

// ========================================================================= //
//                            HIDE THE POPUP                                 //
// ========================================================================= //

static void TaskControl_PopupHide(void *taskControl, void *taskData)
{
    struct PopupTaskControl *popupTask = taskData;
    BOOL enemySide = popupTask->clientNum & 1;

    switch (popupTask->seqNum) {
        case 0:
            Popup_ArrowOut(sPopupArrow);
            popupTask->seqNum++;
            break;
        case 1:
            if (sPopupArrow->taskControl == NULL) {
                UI_FreeObject(sPopupArrow->actor);
                Free(sPopupArrow);
                popupTask->seqNum++;
            }
            break;
        default:
            SCIO_ClearQueue(popupTask->battle, popupTask->clientNum, CLIENT_POPUP_OUT);
            Free(taskData);
            TaskControl_Delete(taskControl);
            break;
    }
}

static void TaskControl_ArrowHide(void *taskControl, void *taskData)
{
    switch (sPopupArrow->seqNum) {
        case 0:
            UI_SetObjectOAMMode(sPopupArrow->actor, 1); // OAM_MODE_XLU
            
            sPopupArrow->alpha= 16 << 8;
            G2_SetBlendAlpha(
                GX_BLEND_PLANEMASK_NONE,
                (GX_BLEND_PLANEMASK_BG0
                    | GX_BLEND_PLANEMASK_BG1
                    | GX_BLEND_PLANEMASK_BG2
                    | GX_BLEND_PLANEMASK_BG3
                    | GX_BLEND_PLANEMASK_OBJ
                    | GX_BLEND_PLANEMASK_BD),
                (sPopupArrow->alpha >> 8),
                16 - (sPopupArrow->alpha >> 8)
            );

            sPopupArrow->seqNum++;
            // FALL THROUGH
        case 1:
            if (sPopupArrow->startWait > 0) {
                sPopupArrow->startWait--;
                break;
            }
            sPopupArrow->seqNum++;
            // FALL THROUGH
        case 2:
            if (sPopupArrow->enemySide) {
                sPopupArrow->x -= ARROW_OUT_SPEED;
                UI_SetObjectPos(sPopupArrow->actor, sPopupArrow->x >> 8,  64);
            } else {
                sPopupArrow->x += ARROW_OUT_SPEED;
                UI_SetObjectPos(sPopupArrow->actor, sPopupArrow->x >> 8, 120);
            }

            sPopupArrow->alpha -= ARROW_ALPHA_OUT_SPEED;
            if (sPopupArrow->alpha <= 0) {
                sPopupArrow->alpha  = 0;
                UI_EnableObject(sPopupArrow->actor->anim, 0);

                sPopupArrow->seqNum++;
            }

            G2_ChangeBlendAlpha((sPopupArrow->alpha >> 8), 16 - (sPopupArrow->alpha >> 8));
            break;
        default:
            G2_BlendNone();
            TaskControl_Delete(taskControl);
            sPopupArrow->taskControl = NULL;
            return;
    }
}

static void Popup_ArrowOut(struct PopupArrow *arrow)
{
    arrow->seqNum      = 0;
    arrow->scrollOut   = TRUE;
    arrow->startWait   = 4;
    arrow->taskControl = TaskControl_Add(TaskControl_ArrowHide, arrow, 500);
}

static void Client_PopupHide(void *battle, struct BattleClient *client)
{
    struct PopupTaskControl *popupTask = Malloc(HEAP_ID_BATTLE, sizeof(struct PopupTaskControl));
    popupTask->seqNum      = 0;
    popupTask->battle      = battle;
    popupTask->commandCode = CLIENT_POPUP_OUT;
    popupTask->clientNum   = client->clientNum;

    TaskControl_Add(TaskControl_PopupHide, popupTask, 1);
}

#endif