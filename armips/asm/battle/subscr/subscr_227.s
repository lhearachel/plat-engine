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


.create "build/battle/scr/subscr/sub_seq_227.bin", 0

// SUBSCR_SAFARI_THROW_BAIT
subscr_227:
    // "{0} threw some bait at the {1}!"
    MessageNoBattler                    851, TAG_TRNAME_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Throw                               BATTLER_ME, THROW_SAFARI_BAIT
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, STATUS_HAPPY
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, STATUS_EATING
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 0, subscr_227_BusyEating
    // "{0} is eating!"
    MessageNoBattler                    852, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_227_AfterMessage

subscr_227_BusyEating:
    // "{0} is busy eating!"
    MessageNoBattler                    853, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
subscr_227_AfterMessage:
    Wait                                
    WaitTime                            30
    End                                 

.close