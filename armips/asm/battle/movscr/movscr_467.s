.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_467.s", 0

movscr_467:
    PrepareMessage                      1082, TAG_NICK, BATTLER_ATTACKER
    JumpToMoveEffectScript              
