.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_109.s", 0

subscr_109:
    TrySafeguard                        2
    JumpToSubscript                     53
    End                                 
