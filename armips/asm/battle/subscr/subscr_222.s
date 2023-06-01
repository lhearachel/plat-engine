.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_222.s", 0

subscr_222:
    Message                             1206, TAG_ITEM, BATTLER_WORKING
    Wait                                
    SetStatusEffect                     BATTLER_ME, 17
    Wait                                
    PlaySound                           BATTLER_ATTACKER, 1791
    Message                             781, TAG_NONE
    Wait                                
    WaitFrames                          30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    End                                 
