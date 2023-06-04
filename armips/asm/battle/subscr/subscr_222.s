.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_222.bin", 0

subscr_222:
    Message                             1206, TAG_ITEM, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusEffect                     BATTLER_ME, 17
    Wait                                
    PlaySound                           BATTLER_ATTACKER, 1791
    Message                             781, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    End                                 

.close