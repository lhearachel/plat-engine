.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_9.s", 0

effscr_009:
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    SetMirrorMove                       
    Message                             798, TAG_NONE
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
