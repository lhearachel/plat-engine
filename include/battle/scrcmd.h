#ifndef __BATTLE_SCRCMD_H
#define __BATTLE_SCRCMD_H

#include "typedefs.h"

#include "battle/server.h"

/**
 * Executes a scripting command.
 * 
 * Hook point: 0x022405FC (overlay 16)
 * 
 * @param battle The battle structure.
 * @param server The invoking server.
 */
BOOL __attribute__((long_call)) BattleScrCmd_Exec(struct Battle *battle, struct BattleServer *server);

/**
 * @brief Gets the actual client number behind a battler definition.
 * 
 * @param battle
 * @param server
 * @param battlerDef    Refer to the BATTLER definitions from battle_scrcmd.s
 * @return              The actual client number
 */
int  __attribute__((long_call)) BattleScrCmd_TrueBattler(struct Battle *battle, struct BattleServer *server, int battlerDef);

/**
 * Reads a word from the scripting buffer.
 * 
 * Original function: 0x02248AD0 (overlay 16) 
 * 
 * @param server
 */
int  __attribute__((long_call)) BattleScrCmd_ReadWord(struct BattleServer *server);

#endif // __BATTLE_SCRCMD_H