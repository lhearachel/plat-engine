.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_293.s", 0

subscr_293:
    If                                  EQUAL, VAR_DEFENDER, 255, 93
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPECIES, 492, 87
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_FORM_NUMBER, 0, 81
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 16777216, 75
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_CONDITION, 32, 69
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_FORM_NUMBER, 0
    SetVar                              OP_SET, VAR_TEMP_WORK, 0
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_PID, 1, 6
    GetBaseStatsData                    492, 43, 24
    Jump                                13
    GetBaseStatsData                    492, 43, 25
    If                                  NOT_EQUAL, VAR_TEMP_WORK, 0, 4
    GetBaseStatsData                    492, 43, 24
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 134217728
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_ABILITY, VAR_CALC_WORK
    GetBaseStatsData                    492, 43, 6
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TYPE_1, VAR_CALC_WORK
    GetBaseStatsData                    492, 43, 7
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TYPE_2, VAR_CALC_WORK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    JumpToSubscript                     262
    RefreshMonData                      BATTLER_DEFENDER
    End                                 
