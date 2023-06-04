.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_53.bin", 0

subscr_053:
    JumpToSubscript                     76
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    End                                 

.close