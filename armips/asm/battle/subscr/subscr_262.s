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


.create "build/battle/scr/subscr/sub_seq_262.bin", 0

// SUBSCR_CHANGE_FORM
subscr_262:
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED, subscr_262_Resume
    SetStatusEffect                     BATTLER_WORKING, STATUS_SUB_OUT
    Wait                                
    TransformBack                       BATTLER_WORKING
    Wait                                
    SetStatusEffect                     BATTLER_WORKING, STATUS_SUB_IN
    Wait                                
subscr_262_Resume:
    PlaySound                           BATTLER_WORKING, 1980
    Mosaic                              BATTLER_WORKING, 8, 1
    Wait                                
    ChangeForm                          BATTLER_WORKING
    PlaySound                           BATTLER_WORKING, 1984
    Mosaic                              BATTLER_WORKING, 0, 1
    Wait                                
    // "{0} transformed!"
    Message                             721, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED, subscr_262_Exit
    SetStatusEffect                     BATTLER_WORKING, STATUS_SUB_OUT
    Wait                                
    ChangeSpriteWeather                 BATTLER_WORKING
    Wait                                
    SetStatusEffect                     BATTLER_WORKING, STATUS_SUB_IN
    Wait                                
subscr_262_Exit:
    End                                 

.close