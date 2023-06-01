.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_265.s", 0

subscr_265:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             1157, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_TEMP_ACC_MAX, 1
    JumpToSubscript                     290
    End                                 
