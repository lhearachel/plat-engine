.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_255.bin", 0

subscr_255:
    WaitTime                            15
    Random                              3, 0
    If                                  EQUAL, VAR_CALC_WORK, 1, 16
    If                                  EQUAL, VAR_CALC_WORK, 2, 17
    If                                  EQUAL, VAR_CALC_WORK, 3, 18
    Message                             828, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              18
    Message                             829, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              12
    Message                             830, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              6
    Message                             831, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              0
    Wait                                
    WaitTime                            30
    End                                 

.close