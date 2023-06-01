.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_160.s", 0

subscr_160:
    If                                  FLAG_EQ, VAR_ATTACKER_SIDE_CONDITIONS, 768, 14
    JumpToSubscript                     76
    Message                             1230, TAG_NONE_DIR, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_ATTACKER_SIDE_CONDITIONS, 768
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
