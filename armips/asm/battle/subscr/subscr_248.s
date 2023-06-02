.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_248.s", 0

subscr_248:
    CheckSecondaryEffectActivation      2
    JumpToSubscript                     27
    CheckSecondaryEffectActivation      2
    JumpToSubscript                     14
    End                                 
