.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/movscr/waza_seq_150.bin", 0

movscr_150:
    IncGameStat                         BATTLER_ATTACKER, 0, 76
    JumpToMoveEffectScript              

.close