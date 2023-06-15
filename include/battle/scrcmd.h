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
BOOL __attribute__((long_call)) BattleScrCmd_Exec(void *battle, struct BattleServer *server);

/**
 * Reads a word from the scripting buffer.
 * 
 * Original function: 0x02248AD0 (overlay 16) 
 * 
 * @param server
 */
int  __attribute__((long_call)) BattleScrCmd_ReadWord(struct BattleServer *server);

/**
 * Canonizes an incoming client parameter into a canonical client identifier.
 * 
 * Original function: 0x0224A984 (overlay 16)
 */
int  __attribute__((long_call)) BattleScrCmd_CanonClient(void *battle, struct BattleServer *server, int clientParam);

#endif // __BATTLE_SCRCMD_H