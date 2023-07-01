#ifndef __SOUND_H
#define __SOUND_H

#include "typedefs.h"

/**
 * @brief Returns TRUE if any SEs are still playing for any player.
 * 
 * Original function: 0x020057E0 (arm9)
 */
BOOL __attribute__((long_call)) Sound_CheckAnySEsPlaying(void);

/**
 * @brief Returns TRUE if any ME is playing (including BGM).
 * 
 * Original function: 0x020061E4 (arm9)
 */
BOOL __attribute__((long_call)) Sound_CheckMEPlaying(void);

/**
 * @brief Plays an SE from the SDAT archive.
 * 
 * Original function: 0x02005748 (arm9)
 * 
 * @param sdatSeq
 */
BOOL __attribute__((long_call)) Sound_PlaySE(int sdatSeq);

/**
 * @brief Plays an ME from the SDAT archive.
 * 
 * Original function: 0x02006150 (arm9)
 * 
 * @param sdatSeq
 */
BOOL __attribute__((long_call)) Sound_PlayME(int sdatSeq);

#endif // __SOUND_H