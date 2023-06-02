.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_276.s", 0

subscr_276:
    ShouldGetExp                        4
    InitGetExp                          
    WaitExp                             
    ExpLoopback                         4294967292
    End                                 
