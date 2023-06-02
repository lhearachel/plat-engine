.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/movscr/movscr_150.s", 0

movscr_150:
    IncGameStat                         BATTLER_ATTACKER, 0, 76
    JumpToMoveEffectScript              
