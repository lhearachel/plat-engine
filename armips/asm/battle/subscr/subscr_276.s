.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_276.bin", 0

subscr_276:
    ShouldGetExp                        4
    InitGetExp                          
    WaitExp                             
    ExpLoopback                         4294967292
    End                                 

.close