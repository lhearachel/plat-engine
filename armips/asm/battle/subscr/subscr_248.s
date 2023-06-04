.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_248.bin", 0

subscr_248:
    CheckSecondaryEffectActivation      2
    JumpToSubscript                     27
    CheckSecondaryEffectActivation      2
    JumpToSubscript                     14
    End                                 

.close