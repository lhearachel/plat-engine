.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_051.bin", 0

subscr_051:
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 4
    JumpToSubscript                     37
    IfMonData                           FLAG_NEQ, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION_2, 7, 7
    Message                             338, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close