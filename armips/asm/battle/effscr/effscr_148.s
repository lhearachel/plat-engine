.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_148.s", 0

effscr_148:
    TryFutureSight                      9
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 558108
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    JumpToSubscript                     75
    End                                 
