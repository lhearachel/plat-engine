.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_291.s", 0

movscr_291:
    PrepareMessage                      229, TAG_NICK, BATTLER_ATTACKER
    JumpToMoveEffectScript              
