.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_001.bin", 0

subscr_001:
    If                                  EQUAL, VAR_EFFECT_TYPE, 1, 2
    JumpToSubscript                     76
    End                                 

.close