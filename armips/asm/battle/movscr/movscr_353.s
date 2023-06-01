.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_353.s", 0

movscr_353:
    PrepareMessage                      478, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER
    JumpToMoveEffectScript              
