.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_340.s", 0

movscr_340:
    PrepareMessage                      232, TAG_NICK, BATTLER_ATTACKER
    JumpToMoveEffectScript              
