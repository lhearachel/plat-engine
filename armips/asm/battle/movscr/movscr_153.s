.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_153.s", 0

movscr_153:
    IncGameStat                         BATTLER_ATTACKER, 0, 79
    JumpToMoveEffectScript              
