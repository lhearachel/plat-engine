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


.create "build/battle/scr/subscr/sub_seq_264.bin", 0

// SUBSCR_TYPE_RESIST_BERRIES
subscr_264:
    // If the move specifies that it ignores immunities or type effectiveness, do not activate
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_IMMUNITIES | SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS, subscr_264_Exit
    // Do not activate on OHKO moves
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ONE_HIT_KO, subscr_264_Exit
    // Modify the type of the move if the attacker has Normalize
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_NORMALIZE, subscr_264_NoAbilityTypeMod
    SetVar                              OP_SET, VAR_CALC_WORK, TYPE_NORMAL
    Branch                              subscr_264_Resume

subscr_264_NoAbilityTypeMod:
    If                                  EQUAL, VAR_MOVE_TYPE, 0, subscr_264_GetType
    SetVarFromVar                       OP_GET, VAR_MOVE_TYPE, VAR_CALC_WORK
    Branch                              subscr_264_Resume

subscr_264_GetType:
    GetCurrentMoveData                  MOVE_PARAM_TYPE
subscr_264_Resume:
    GetItemEffect                       BATTLER_WORKING, VAR_TEMP_WORK
    // Chilan Berry always activates on Normal-type attacks
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_NORMAL, subscr_264_CheckNormal
    // Other types: check if the move is super-effective
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_SUPER_EFFECTIVE, subscr_264_Exit
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_FIRE, subscr_264_CheckFire
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_WATER, subscr_264_CheckWater
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_ELECTRIC, subscr_264_CheckElectric
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_GRASS, subscr_264_CheckGrass
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_ICE, subscr_264_CheckIce
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_FIGHTING, subscr_264_CheckFighting
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_POISON, subscr_264_CheckPoison
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_GROUND, subscr_264_CheckGround
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_FLYING, subscr_264_CheckFlying
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_PSYCHIC, subscr_264_CheckPsychic
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_BUG, subscr_264_CheckBug
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_ROCK, subscr_264_CheckRock
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_GHOST, subscr_264_CheckGhost
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_DRAGON, subscr_264_CheckDragon
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_DARK, subscr_264_CheckDark
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_STEEL, subscr_264_CheckSteel
    Branch                              subscr_264_Exit

subscr_264_CheckNormal:
    // Struggle check; do not consume Chilan berries
    If                                  EQUAL, VAR_CURRENT_MOVE, 165, subscr_264_Exit
    If                                  EQUAL, VAR_CALC_WORK, TYPE_NORMAL, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckFire:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIRE, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckWater:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_WATER, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckElectric:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ELECTRIC, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckGrass:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GRASS, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckIce:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ICE, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckFighting:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIGHTING, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckPoison:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_POISON, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckGround:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GROUND, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckFlying:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FLYING, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckPsychic:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_PSYCHIC, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckBug:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_BUG, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckRock:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ROCK, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckGhost:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GHOST, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckDragon:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DRAGON, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckDark:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DARK, subscr_264_HalveDamage
    Branch                              subscr_264_Exit

subscr_264_CheckSteel:
    If                                  NOT_EQUAL, VAR_CALC_WORK, TYPE_STEEL, subscr_264_Exit
subscr_264_HalveDamage:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    DamageDiv                           VAR_HP_TEMP, 2
    // "The {0} weakened {1}'s power!"
    Message                             1131, TAG_ITEM_MOVE, BATTLER_CLIENT_WORK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_WORKING
subscr_264_Exit:
    End                                 

.close