.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_328.s", 0

movscr_328:
    PrepareMessage                      245, TAG_NICK, BATTLER_DEFENDER
    JumpToMoveEffectScript              
