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


.create "build/battle/scr/subscr/sub_seq_297.bin", 0

// SUBSCR_CHECK_REMOVE_RESIST_BERRY
subscr_297:
    // If the move specifies that it ignores immunities or type effectiveness, do not activate
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_IMMUNITIES | SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS, subscr_297_Exit
    // Do not activate on OHKO moves
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ONE_HIT_KO, subscr_297_Exit
    // Modify the type of the move if the attacker has Normalize
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_NORMALIZE, subscr_297_NoAbilityTypeMod
    SetVar                              OP_SET, VAR_CALC_WORK, TYPE_NORMAL
    Branch                              subscr_297_Resume

subscr_297_NoAbilityTypeMod:
    If                                  EQUAL, VAR_MOVE_TYPE, 0, subscr_297_GetType
    SetVarFromVar                       OP_GET, VAR_MOVE_TYPE, VAR_CALC_WORK
    Branch                              subscr_297_Resume

subscr_297_GetType:
    GetCurrentMoveData                  MOVE_PARAM_TYPE
subscr_297_Resume:
    GetItemEffect                       BATTLER_DEFENDER, VAR_TEMP_WORK
    // Chilan Berry always activates on Normal-type attacks
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_NORMAL, subscr_297_CheckNormal
    // Other types: check if the move is super-effective
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_SUPER_EFFECTIVE, subscr_297_Exit
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_FIRE, subscr_297_CheckFire
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_WATER, subscr_297_CheckWater
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_ELECTRIC, subscr_297_CheckElectric
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_GRASS, subscr_297_CheckGrass
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_ICE, subscr_297_CheckIce
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_FIGHTING, subscr_297_CheckFighting
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_POISON, subscr_297_CheckPoison
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_GROUND, subscr_297_CheckGround
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_FLYING, subscr_297_CheckFlying
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_PSYCHIC, subscr_297_CheckPsychic
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_BUG, subscr_297_CheckBug
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_ROCK, subscr_297_CheckRock
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_GHOST, subscr_297_CheckGhost
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_DRAGON, subscr_297_CheckDragon
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_DARK, subscr_297_CheckDark
    If                                  EQUAL, VAR_TEMP_WORK, HOLD_EFFECT_WEAKEN_SE_STEEL, subscr_297_CheckSteel
    Branch                              subscr_297_Exit

subscr_297_CheckNormal:
    // Struggle check; do not consume Chilan berries
    If                                  EQUAL, VAR_CURRENT_MOVE, 165, subscr_297_Exit
    If                                  EQUAL, VAR_CALC_WORK, TYPE_NORMAL, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckFire:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIRE, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckWater:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_WATER, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckElectric:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ELECTRIC, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckGrass:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GRASS, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckIce:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ICE, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckFighting:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FIGHTING, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckPoison:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_POISON, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckGround:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GROUND, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckFlying:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_FLYING, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckPsychic:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_PSYCHIC, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckBug:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_BUG, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckRock:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_ROCK, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckGhost:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_GHOST, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckDragon:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DRAGON, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckDark:
    If                                  EQUAL, VAR_CALC_WORK, TYPE_DARK, subscr_297_RemoveItem
    Branch                              subscr_297_Exit

subscr_297_CheckSteel:
    If                                  NOT_EQUAL, VAR_CALC_WORK, TYPE_STEEL, subscr_297_Exit
subscr_297_RemoveItem:
    RemoveItem                          BATTLER_DEFENDER
subscr_297_Exit:
    End                                 

.close