#ifndef __UI_BATTLE_H
#define __UI_BATTLE_H

#include "battle/common.h"

#include "ui/common.h"

struct PopupTaskControl {
    void    *battle;
    u8      commandCode;
    u8      clientNum;
    u8      seqNum;
    u8      nickMsgIdx;
    u8      abilityMsgIdx;
};

// BattleWorkCATS_SYS_PTRGet
struct CellActorSystem*   __attribute__((long_call)) Battle_GetClientActorSys(void *battle);
// BattleWorkCATS_RES_PTRGet
struct CellActorResource* __attribute__((long_call)) Battle_GetClientActorRes(void *battle);
// BattleWorkPfdGet
struct PaletteFade*       __attribute__((long_call)) Battle_GetPaletteFade(void *battle);

// TEMOTI_ResourceLoad
void __attribute__((long_call)) PartyGauge_Load(struct CellActorSystem *actorSys,
                                                struct CellActorResource *actorRes,
                                                struct PaletteFade *palData);
// TEMOTI_ResourceFree
void __attribute__((long_call)) PartyGauge_Free(struct CellActorResource *actorRes);

// novel functions
u8   __attribute__((long_call)) BattleUI_PrintPopupMessage(struct Battle *battle, struct MessageParams *msgParams);
void __attribute__((long_call)) BattleUI_ClosePopupMessage(void);

#endif // __UI_BATTLE_H