.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_202.s", 0

subscr_202:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    Message                             881, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NORMAL
    WaitFrames                          30
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    JumpToSubscript                     290
    End                                 
