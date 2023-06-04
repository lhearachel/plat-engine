.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_90.bin", 0

subscr_090:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 64, 5
    PlayMoveSoundEffect                 BATTLER_WORKING
    FlickerMon                          BATTLER_WORKING
    Wait                                
    Message                             354, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 16777216, 18
    SetStatusEffect                     BATTLER_WORKING, 26
    Wait                                
    TransformBack                       BATTLER_WORKING
    Wait                                
    SetStatusEffect                     BATTLER_WORKING, 16
    Wait                                
    Message                             357, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close