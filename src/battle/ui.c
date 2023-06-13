#include "sound.h"

#include "battle/common.h"
#include "battle/server.h"

#include "ui/battle.h"
#include "ui/window.h"

static void __attribute__((long_call)) BattleMessage_ExpandTags(struct Battle *battle, struct MessageParams *msgParams);
static void __attribute__((long_call)) BattleMessage_ExpandMessage(struct Battle *battle, struct MessageParams *msgParams);

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

u8 BattleUI_PrintPopupMessage(struct Battle *battle, struct MessageParams *msgParams)
{
    sPopupWindow = Malloc(HEAP_ID_BATTLE, sizeof(struct Window));
    if (msgParams->client ^ 1) {
        Window_Add(battle->bgl, sPopupWindow, 1, 120, 120, 20, 4, 11, 31);
    } else {
        Window_Add(battle->bgl, sPopupWindow, 1,   2,  40, 20, 4, 11, 31);
    }

    BattleMessage_ExpandTags(battle, msgParams);
    BattleMessage_ExpandMessage(battle, msgParams);

    Window_FillWithColor(sPopupWindow, 0xFF);

    return Window_PrintString(sPopupWindow, 1, battle->preparedMessage, 0, 0, 1, BattleMessage_PopupCallback);
}

void BattleUI_ClosePopupMessage(void)
{
    Window_Clear(sPopupWindow, 0);
    Window_Delete(sPopupWindow);
    Free(sPopupWindow);
}