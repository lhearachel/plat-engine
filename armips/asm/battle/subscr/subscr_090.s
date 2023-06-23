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


.create "build/battle/scr/subscr/sub_seq_090.bin", 0

// SUBSCR_HIT_SUBSTITUTE
subscr_090:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK, subscr_090_SkipFlicker
    PlayMoveSoundEffect                 BATTLER_WORKING
    FlickerMon                          BATTLER_WORKING
    Wait                                
subscr_090_SkipFlicker:
    // "The substitute took damage for {0}!"
    Message                             354, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Check if Substitute is still active after the hit
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED, subscr_090_Exit
subscr_090_BreakSubstitute:
    // Play the animation for swapping the substitute out
    SetStatusEffect                     BATTLER_WORKING, STATUS_SUBSTITUTE_OUT
    Wait                                
    TransformBack                       BATTLER_WORKING
    Wait                                
    // Not sure which animation this is tbh
    SetStatusEffect                     BATTLER_WORKING, STATUS_SUB_IN
    Wait                                
    // "{0}'s substitute faded!"
    Message                             357, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_090_Exit:
    End                                 

.close