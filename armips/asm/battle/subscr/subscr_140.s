.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_140.s", 0

subscr_140:
    TryBreakScreens                     14
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    JumpToSubscript                     76
    Message                             606, TAG_NONE
    Wait                                
    WaitFrames                          30
    Jump                                7
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 2
    JumpToSubscript                     76
    End                                 
