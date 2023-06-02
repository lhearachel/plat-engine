.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_296.s", 0

subscr_296:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 134217728
    SetMonData                          OP_SET, BATTLER_CLIENT_WORK, BATTLE_MON_FORM_NUMBER, 0
    SetVar                              OP_SET, VAR_TEMP_WORK, 0
    IfMonData                           FLAG_EQ, BATTLER_CLIENT_WORK, BATTLE_MON_PID, 1, 6
    GetBaseStatsData                    487, 43, 24
    Jump                                4
    GetBaseStatsData                    487, 43, 25
    SetMonDataFromVar                   OP_SET, 21, BATTLE_MON_ABILITY, VAR_CALC_WORK
    JumpToSubscript                     262
    RefreshMonData                      BATTLER_CLIENT_WORK
    End                                 
