.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_249.s", 0

subscr_249:
    CheckSecondaryEffectActivation      2
    JumpToSubscript                     31
    CheckSecondaryEffectActivation      2
    JumpToSubscript                     14
    End                                 
