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


.create "build/battle/scr/subscr/sub_seq_293.bin", 0

// SUBSCR_SHAYMIN_FORM_CHECK
subscr_293:
    If                                  EQUAL, VAR_DEFENDER, 0xFF, subscr_293_Exit
    // If not Shaymin, quit
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPECIES, 492, subscr_293_Exit
    // If not in Land form, quit
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_FORM_NUMBER, 0, subscr_293_Exit
    // If behind a Substitute, quit
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED, subscr_293_Exit
    // If frozen, quit
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_FROZEN, subscr_293_Exit
subscr_293_FormChange:
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_FORM_NUMBER, 0
    SetVar                              OP_SET, VAR_TEMP_WORK, 0
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_PID, 1, subscr_293_UseAbility2
subscr_293_UseAbility1:
    GetBaseStatsData                    492, VAR_TEMP_WORK, 24
    Branch                              subscr_293_AbilitySet
subscr_293_UseAbility2:
    GetBaseStatsData                    492, VAR_TEMP_WORK, 25
    // fallback to ability 1
    If                                  NOT_EQUAL, VAR_TEMP_WORK, 0, subscr_293_AbilitySet
    GetBaseStatsData                    492, VAR_TEMP_WORK, 24
subscr_293_AbilitySet:
    // Reset Shaymin's stats
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_RECALC_MON_STATS
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_ABILITY, VAR_CALC_WORK
    // Reset Shaymin's type
    GetBaseStatsData                    492, VAR_TEMP_WORK, 6
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_TYPE_1, VAR_CALC_WORK
    GetBaseStatsData                    492, VAR_TEMP_WORK, 7
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_TYPE_2, VAR_CALC_WORK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    CallSubscript                       SUBSCR_CHANGE_FORM
    RefreshMonData                      BATTLER_DEFENDER
subscr_293_Exit:
    End                                 

.close