.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_6.s", 0

subscr_006:
    IncGameStat                         BATTLER_FAINTING, 1, 41
    IncGameStat                         BATTLER_FAINTING, 0, 96
    FaintAnimation                      
    Wait                                
    HPGaugeSlideOut                     BATTLER_FAINTING
    Message                             30, TAG_NICK, BATTLER_FAINTING
    Wait                                
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG2, 1, 0
    End                                 
