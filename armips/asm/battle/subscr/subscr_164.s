.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_164.s", 0

subscr_164:
    SetVar                              OP_SET, VAR_CALC_WORK, 20480
    SetVarFromVar                       OP_SET_FLAG, VAR_ATTACKER_SIDE_CONDITIONS, VAR_CALC_WORK
    Message                             1241, TAG_NONE_DIR, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
