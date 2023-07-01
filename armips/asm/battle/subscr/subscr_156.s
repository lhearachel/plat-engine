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


.create "build/battle/scr/subscr/sub_seq_156.bin", 0

// SUBSCR_APPLY_GRAVITY
subscr_156:
    // "Gravity intensified!"
    Message                             997, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Set 5 turns of Gravity
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 0x5000
    // Iterate over battlers in speed-order
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
subscr_156_Loop:
    GetBattlerBySpeedOrder              VAR_BATTLER_WORK
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_HP, 0, subscr_156_Resume
    // Handle Magnet Rise
    IfMonData                           NOT_EQUAL, BATTLER_WORKING, BATTLE_MON_MAGNET_RISE_TURNS, 0, subscr_156_MagnetRise
    // Handle Fly/Bounce state
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_AIRBORNE, subscr_156_Fly
    // Handle Levitate/Flying-types
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_ABILITY_SUPPRESSED, subscr_156_Resume
    IfMonData                           FLAG_EQ, BATTLER_WORKING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_INGRAINED, subscr_156_Resume
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_ABILITY, ABILITY_LEVITATE, subscr_156_FallDown
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_TYPE_1, TYPE_FLYING, subscr_156_FallDown
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_TYPE_2, TYPE_FLYING, subscr_156_FallDown
    Branch                              subscr_156_Resume

subscr_156_MagnetRise:
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_MAGNET_RISE_TURNS, 0
    Branch                              subscr_156_FallDown

subscr_156_Fly:
    ClearContinuation                   BATTLER_WORKING
    ToggleVanish                        BATTLER_WORKING, 0
    Wait                                
subscr_156_FallDown:
    // "{0} couldn't stay airborne because of gravity!"
    Message                             998, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_156_Resume:
    // Get the next battler and loop back up
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, subscr_156_Loop
    End                                 

.close