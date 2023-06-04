.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_6.bin", 0

subscr_006:
    IncGameStat                         BATTLER_FAINTING, 1, 41
    IncGameStat                         BATTLER_FAINTING, 0, 96
    FaintAnimation                      
    Wait                                
    HPGaugeSlideOut                     BATTLER_FAINTING
    Message                             30, TAG_NICK, BATTLER_FAINTING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG2, 1, 0
    End                                 

.close