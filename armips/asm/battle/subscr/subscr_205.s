.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_205.s", 0

subscr_205:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             890, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 7
    JumpToSubscript                     290
    End                                 
