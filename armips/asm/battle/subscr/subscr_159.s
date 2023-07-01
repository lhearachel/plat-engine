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


.create "build/battle/scr/subscr/sub_seq_159.bin", 0

// SUBSCR_HEALING_WISH
subscr_159:
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    // Magic self-destruct HP
    SetVar                              OP_SET, VAR_HP_TEMP, 0x7FFF
    UpdateHPGauge                       BATTLER_ATTACKER
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    TryFaintMon                         BATTLER_ATTACKER
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON
    CallSubscript                       SUBSCR_FAINT
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_BATTLER_GETS_EXP
    CallSubscript                       SUBSCR_GET_EXP
subscr_159_Loop:
    // Try to open the party list
    TrySwitchInMon                      BATTLER_ATTACKER, 1, subscr_159_Exit
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
    // Check for any fainting on switch-in due to hazards
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON, subscr_159_Resume
    CallSubscript                       SUBSCR_FAINT
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_BATTLER_GETS_EXP
    CallSubscript                       SUBSCR_GET_EXP
    // Try to open the party list again
    TrySwitchInMon                      BATTLER_ATTACKER, 1, subscr_159_Exit
    Branch                              subscr_159_Loop

subscr_159_Resume:
    // Got a living switch in
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    // "The healing wish came true!"
    PrepareMessage                      1005, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    CallSubscript                       SUBSCR_WISH_HEAL
subscr_159_Exit:
    End                                 

.close