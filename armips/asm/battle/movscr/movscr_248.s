.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_248.s", 0

movscr_248:
    PrepareMessage                      472, TAG_NICK, BATTLER_ATTACKER
    JumpToMoveEffectScript              
