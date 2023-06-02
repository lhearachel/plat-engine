.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_243.s", 0

subscr_243:
    SetVar                              OP_SET, VAR_MOVE_TEMP, 377
    Message                             1060, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, 33554432
    End                                 
