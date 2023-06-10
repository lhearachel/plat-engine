#ifndef __BATTLE_SKILLSEQ_H
#define __BATTLE_SKILLSEQ_H

#include "typedefs.h"

#include "battle/server.h"

typedef BOOL (*SkillSeqCmd)(void *battle, struct BattleServer *server);

/**
 * Executes a scripting command.
 * 
 * Original function: 0x022405FC (overlay 16)
 * 
 * @param battle The battle structure.
 * @param server The invoking server.
 */
BOOL __attribute__((long_call)) SkillSeq_Exec(void *battle, struct BattleServer *server);

// defined in skillseq.c
BOOL __attribute__((long_call)) SkillSeq_LoadPopupGraphics(void *battle, struct BattleServer *server);
BOOL __attribute__((long_call)) SkillSeq_FreePopupGraphics(void *battle, struct BattleServer *server);
BOOL __attribute__((long_call)) SkillSeq_ShowPopup(void *battle, struct BattleServer *server);
BOOL __attribute__((long_call)) SkillSeq_HidePopup(void *battle, struct BattleServer *server);

#endif // __BATTLE_SKILLSEQ_H