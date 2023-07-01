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


.create "build/battle/scr/subscr/sub_seq_296.bin", 0

// SUBSCR_GIRATINA_FORM_CHECK
subscr_296:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_RECALC_MON_STATS
    SetMonData                          OP_SET, BATTLER_CLIENT_WORK, BATTLE_MON_FORM_NUMBER, 0
    SetVar                              OP_SET, VAR_TEMP_WORK, 0
    IfMonData                           FLAG_EQ, BATTLER_CLIENT_WORK, BATTLE_MON_PID, 1, subscr_296_UseAbility2
subscr_296_UseAbility1:
    GetBaseStatsData                    487, VAR_TEMP_WORK, 24
    Branch                              subscr_296_SetAbility

subscr_296_UseAbility2:
    GetBaseStatsData                    487, VAR_TEMP_WORK, 25
subscr_296_SetAbility:
    SetMonDataFromVar                   OP_SET, BATTLER_CLIENT_WORK, BATTLE_MON_ABILITY, VAR_CALC_WORK
    CallSubscript                       SUBSCR_CHANGE_FORM
    RefreshMonData                      BATTLER_CLIENT_WORK
    End                                 

.close