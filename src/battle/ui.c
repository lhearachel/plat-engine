#include "sound.h"

#include "battle/common.h"
#include "battle/server.h"

#include "ui/battle.h"
#include "ui/window.h"

static void __attribute__((long_call)) BattleMessage_ExpandTags(struct Battle *battle, struct MessageParams *msgParams);
static void __attribute__((long_call)) BattleMessage_ExpandMessage(struct Battle *battle, void *msgManager, struct MessageParams *msgParams);

static BOOL BattleMessage_PopupCallback(void *mph, u16 value)
{
    BOOL ret = FALSE;
    
    switch (value) {
        case 1:
            ret = Sound_CheckAnySEsPlaying();
            break;
        case 2:
            ret = Sound_CheckMEPlaying();
            break;
        case 3:
            Sound_PlayME(1156);     // Caught Pokemon
            break;
        case 4:
            Sound_PlaySE(1510);     
            break;
        case 5:
            Sound_PlayME(1155);     // Level-up
            break;
        default:
            break;
    }

    return ret;
}

static struct Window *sPopupWindow;

#define DEBUG_POPUPS

u8 BattleUI_PrintPopupMessage(struct Battle *battle, struct MessageParams *msgParams)
{
#ifdef DEBUG_POPUPS
    u8 buf[64];
#endif
    sPopupWindow = Malloc(HEAP_ID_BATTLE, sizeof(struct Window));
    if (msgParams->client ^ 1) {
#ifdef DEBUG_POPUPS
        sprintf(buf, "Making enemy-side popup\n"); debugsyscall(buf);
#endif
        Window_Add(battle->bgl, sPopupWindow, 1, 250, 200, 20, 4, 11, 31);
    } else {
#ifdef DEBUG_POPUPS
        sprintf(buf, "Making ally-side popup\n"); debugsyscall(buf);
#endif
        Window_Add(battle->bgl, sPopupWindow, 1,   2,  40, 20, 4, 11, 31);
    }

#ifdef DEBUG_POPUPS
    sprintf(buf, "Making message to show\n"); debugsyscall(buf);
#endif
    BattleMessage_ExpandTags(battle, msgParams);
    BattleMessage_ExpandMessage(battle, battle->fightMsgManager, msgParams);

    Window_FillWithColor(sPopupWindow, 0xFF);

    return Window_PrintString(sPopupWindow, 1, battle->preparedMessage, 0, 0, 0, BattleMessage_PopupCallback);
}

void BattleUI_ClosePopupMessage(void)
{
    Window_Clear(sPopupWindow, 0);
    Window_Delete(sPopupWindow);
    Free(sPopupWindow);
}