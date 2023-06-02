.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_284.s", 0

subscr_284:
    PlaySound                           BATTLER_ATTACKER, 1791
    Message                             781, TAG_NONE
    Wait                                
    WaitFrames                          30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 129
    SetBattleResult                     
    End                                 
