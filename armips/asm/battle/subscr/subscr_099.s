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


.create "build/battle/scr/subscr/sub_seq_099.bin", 0

// SUBSCR_HAZARDS_CHECK
subscr_099:
    CheckAbility                        MODE_HAVE, BATTLER_SWITCHING, ABILITY_MAGIC_GUARD, subscr_099_Exit
    // Gravity and Iron Ball break all immunities to Spikes/Toxic Spikes
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_GRAVITY, subscr_099_CheckToxicSpikes
    CheckItemEffect                     MODE_HAVE, BATTLER_SWITCHING, HOLD_EFFECT_IRON_BALL, subscr_099_CheckToxicSpikes
    // Levitate grants immunity to Spikes/Toxic Spikes
    CheckAbility                        MODE_HAVE, BATTLER_SWITCHING, ABILITY_LEVITATE, subscr_099_CheckStealthRock
    // Flying types are immune to Spikes/Toxic Spikes
    IfMonData                           EQUAL, BATTLER_SWITCHING, BATTLE_MON_TYPE_1, TYPE_FLYING, subscr_099_CheckStealthRock
    IfMonData                           EQUAL, BATTLER_SWITCHING, BATTLE_MON_TYPE_2, TYPE_FLYING, subscr_099_CheckStealthRock
    // Magnet Rise grants immunity to Spikes/Toxic Spikes
    IfMonData                           FLAG_EQ, BATTLER_SWITCHING, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_MAGNET_RISE, subscr_099_CheckStealthRock
subscr_099_CheckToxicSpikes:
    // Check for Toxic Spikes; this command also handles setting the spikes to 0 if the incoming Pokemon is Poison-type
    CheckToxicSpikes                    BATTLER_SWITCHING, subscr_099_CheckSpikes
    // Check the number of layers active
    If                                  EQUAL, VAR_CALC_WORK, 2, subscr_099_BadlyPoison
    If                                  EQUAL, VAR_CALC_WORK, 1, subscr_099_Poison
    // "The poison spikes disappeared from around your team's feet!"
    Message                             1065, TAG_NONE_DIR, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              subscr_099_CheckSpikes
subscr_099_Poison:
    CallSubscript                       SUBSCR_APPLY_POISON
    Branch                              subscr_099_CheckSpikes
subscr_099_BadlyPoison:
    CallSubscript                       SUBSCR_BADLY_POISON
subscr_099_CheckSpikes:
    CheckSpikes                         BATTLER_SWITCHING, subscr_099_CheckStealthRock
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_SWITCHED_BATTLER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} is hurt by the spikes!"
    Message                             429, TAG_NICK, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_099_CheckStealthRock:
    CheckStealthRock                    BATTLER_SWITCHING, subscr_099_Exit
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_SWITCHED_BATTLER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "Pointed stones dug into {0}!"
    Message                             1079, TAG_NICK, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_099_Exit:
    End                                 

.close