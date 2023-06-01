.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_190.s", 0

subscr_190:
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 134217728
    Message                             717, TAG_NICK_ABILITY_COND, BATTLER_WORKING, BATTLER_CLIENT_WORK, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NORMAL
    WaitFrames                          30
    End                                 
