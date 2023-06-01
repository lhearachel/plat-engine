.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_230.s", 0

subscr_230:
    PlaySound                           BATTLER_ATTACKER, 1791
    MessageNoBattler                    784, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    IncGameStat                         BATTLER_ATTACKER, 1, 99
    End                                 
