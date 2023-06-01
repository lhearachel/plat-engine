.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_221.s", 0

subscr_221:
    Message                             740, TAG_NICK_ABILITY_COND, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NORMAL
    WaitFrames                          30
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, 17
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 5, 24
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 6, 26
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    Jump                                24
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 134217728
    Jump                                12
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 7
    Jump                                5
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 983040
    End                                 
