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


.create "build/battle/scr/subscr/sub_seq_261.bin", 0

// SUBSCR_LUNAR_DANCE
subscr_261:
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    // Special Self-Destruct value
    SetVar                              OP_SET, VAR_HP_TEMP, 0x7FFF
    UpdateHPGauge                       BATTLER_ATTACKER
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    TryFaintMon                         BATTLER_ATTACKER
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON
    CallSubscript                       SUBSCR_FAINT
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_BATTLER_GETS_EXP
    CallSubscript                       SUBSCR_GET_EXP
subscr_261_Loop:
    TrySwitchInMon                      BATTLER_ATTACKER, 1, subscr_261_Exit
    ShowMonList                         
    WaitForMonSelection                 
    SwitchInAndUpdate                   BATTLER_SWITCHING
    SendOutMessage                      BATTLER_SWITCHING
    Wait                                
    PokemonAppear                       BATTLER_SWITCHING
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_SWITCHING
    Wait                                
    CallSubscript                       SUBSCR_HAZARDS_CHECK
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON, subscr_261_Effect
    CallSubscript                       SUBSCR_FAINT
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_BATTLER_GETS_EXP
    CallSubscript                       SUBSCR_GET_EXP
    TrySwitchInMon                      BATTLER_ATTACKER, 1, subscr_261_Exit
    Branch                              subscr_261_Loop
subscr_261_Effect:
    // Heal any non-volatile condition
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    // Set the PP of all moves to maximum
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_PP_MAX_1, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_PP_CUR_1, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_PP_MAX_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_PP_CUR_2, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_PP_MAX_3, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_PP_CUR_3, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_PP_MAX_4, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_PP_CUR_4, VAR_CALC_WORK
    // Restore HP to maximum
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    // "It became cloaked in mystical moonlight!"
    PrepareMessage                      1006, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    CallSubscript                       SUBSCR_WISH_HEAL
subscr_261_Exit:
    End                                 

.close