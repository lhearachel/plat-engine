.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_261.bin", 0

subscr_261:
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    SetVar                              OP_SET, VAR_HP_TEMP, 32767
    UpdateHPGauge                       BATTLER_ATTACKER
    JumpToSubscript                     76
    TryFaintMon                         BATTLER_ATTACKER
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 251658240
    JumpToSubscript                     6
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 4026531840
    JumpToSubscript                     276
    TrySwitchInMon                      BATTLER_ATTACKER, 1, 97
    ShowMonList                         
    WaitForMonSelection                 
    SwitchInAndUpdate                   BATTLER_SWITCHING
    SendOutMessage                      BATTLER_SWITCHING
    Wait                                
    PokemonAppear                       BATTLER_SWITCHING
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_SWITCHING
    Wait                                
    JumpToSubscript                     99
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, 251658240, 14
    JumpToSubscript                     6
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 4026531840
    JumpToSubscript                     276
    TrySwitchInMon                      BATTLER_ATTACKER, 1, 64
    Branch                              4294967257
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_PP_MAX_1, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_PP_CUR_1, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_PP_MAX_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_PP_CUR_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_PP_MAX_3, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_PP_CUR_3, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_PP_MAX_4, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_PP_CUR_4, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    PrepareMessage                      1006, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    JumpToSubscript                     136
    End                                 

.close