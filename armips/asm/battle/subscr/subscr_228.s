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


.create "build/battle/scr/subscr/sub_seq_228.bin", 0

// SUBSCR_SAFARI_THROW_MUD
subscr_228:
    // "{0} threw mud at the {1}!"
    MessageNoBattler                    854, TAG_TRNAME_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Throw                               BATTLER_ME, THROW_SAFARI_ROCK
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, STATUS_ANGRY
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 0, subscr_228_AlreadyAngry
    // "{0} is angry!"
    MessageNoBattler                    855, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_228_AfterMessage

subscr_228_AlreadyAngry:
    // "{0} is beside itself with anger!"
    MessageNoBattler                    856, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
subscr_228_AfterMessage:
    Wait                                
    WaitTime                            30
    End                                 

.close