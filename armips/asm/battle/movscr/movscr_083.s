.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_83.s", 0

movscr_083:
    PrepareMessage                      242, TAG_NICK, BATTLER_DEFENDER
    JumpToMoveEffectScript              
