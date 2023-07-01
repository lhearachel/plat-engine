.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_255.bin", 0

// SUBSCR_DISOBEY
subscr_255:
    WaitTime                            15
    // Pick the disobey action
    Random                              3, 0
    If                                  EQUAL, VAR_CALC_WORK, 1, subscr_255_WontObey
    If                                  EQUAL, VAR_CALC_WORK, 2, subscr_255_TurnedAway
    If                                  EQUAL, VAR_CALC_WORK, 3, subscr_255_DidntNotice
    // "{0} is loafing around!"
    Message                             828, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_255_Exit

subscr_255_WontObey:
    // "{0} won't obey!"
    Message                             829, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_255_Exit

subscr_255_TurnedAway:
    // "{0} turned away!"
    Message                             830, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_255_Exit

subscr_255_DidntNotice:
    // "{0} pretended not to notice!"
    Message                             831, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_255_Exit

subscr_255_Exit:
    Wait                                
    WaitTime                            30
    End                                 

.close