.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_148.bin", 0

effscr_148:
    TryFutureSight                      9
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 558108
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            30
    JumpToSubscript                     75
    End                                 

.close