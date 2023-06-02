.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_143.s", 0

movscr_143:
    PrepareMessage                      220, TAG_NICK, BATTLER_ATTACKER
    JumpToMoveEffectScript              
