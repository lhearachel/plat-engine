.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_257.bin", 0

subscr_257:
    WaitTime                            15
    Message                             827, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_ATTACKER
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 7
    JumpToSubscript                     18
    End                                 

.close