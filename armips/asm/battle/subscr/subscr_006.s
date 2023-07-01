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


.create "build/battle/scr/subscr/sub_seq_006.bin", 0

// SUBSCR_FAINT
subscr_006:
    // Increment game record for number of Pokemon we have killed
    IncGameStat                         BATTLER_FAINTING, 1, 41
    // Increment game record for number of our Pokemon who have fainted
    IncGameStat                         BATTLER_FAINTING, 0, 96
    FaintAnimation                      
    Wait                                
    HPGaugeSlideOut                     BATTLER_FAINTING
    Message                             30, TAG_NICK, BATTLER_FAINTING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // lol.
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_NO_EXPERIENCE_GIVEN, subscr_006_NoExp
subscr_006_NoExp:
    End                                 

.close