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


.create "build/battle/scr/subscr/sub_seq_275.bin", 0

// SUBSCR_SAFARI_THROW_BALL
subscr_275:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_PAL_PARK, subscr_275_PalPark
    // "{0} used one {1}!"
    Message                             857, TAG_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    Throw                               BATTLER_ME, THROW_SAFARI_BALL
    Branch                              subscr_275_InitCapture

subscr_275_PalPark:
    // "{0}, come back!"
    MessageNoBattler                    1225, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Wait                                
    Throw                               BATTLER_ME, THROW_PARK_BALL

subscr_275_InitCapture:
    InitCapture                         CAPTURE_SAFARI
    Capture                             
    If                                  FLAG_EQ, VAR_BATTLE_RESULT, BATTLE_RESULT_CAPTURE, subscr_275_Exit
    If                                  NOT_EQUAL, VAR_SAFARI_BALL_COUNT, 0, subscr_275_Exit
    PlaySound                           BATTLER_ATTACKER, 1521
    // "Announcer: You're out of Safari Balls! Game over!"
    Message                             850, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_ESCAPE
subscr_275_Exit:
    End                                 

.close