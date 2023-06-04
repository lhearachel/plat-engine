.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_210.bin", 0

subscr_210:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    WaitTime                            15
    SetStatusEffect                     BATTLER_WORKING, 12
    Wait                                
    Message                             759, TAG_NICK_ITEM_STAT, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET, VAR_TEMP_WORK, 18
    SetVarFromVar                       OP_ADD, VAR_TEMP_WORK, VAR_PREPARED_MESSAGE
    SetMonData                          OP_ADD, BATTLER_WORKING, BATTLE_MON_TEMP_WORK, 2
    IfMonData                           LESSER, BATTLER_WORKING, BATTLE_MON_TEMP_WORK, 12, 5
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_TEMP_WORK, 12
    JumpToSubscript                     290
    End                                 

.close