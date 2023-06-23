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


.create "build/battle/scr/subscr/sub_seq_231.bin", 0

// SUBSCR_REPLACE_FAINTED
subscr_231:
    If                                  EQUAL, VAR_TEMP_WORK, 1, subscr_231_EnemySwitching
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, subscr_231_DoSwitch
    // "Use next Pokemon?"
    Message                             11, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    YesNoBox                            YES_NO_NEXT_MON
    YesNoWait                           subscr_231_DoSwitch, subscr_231_TryEscape
subscr_231_DoSwitch:
    ShowMonList                         
    WaitForMonSelection                 
    SwitchInAndUpdate                   BATTLER_SWITCHING
    Branch                              subscr_231_DoEnemySwitch

subscr_231_TryEscape:
    TryEscape                           BATTLER_ME, subscr_231_Escape
    CallSubscript                       SUBSCR_ESCAPE_FAIL
    Branch                              subscr_231_DoSwitch

subscr_231_Escape:
    CallSubscript                       SUBSCR_ESCAPE
    End                                 

subscr_231_EnemySwitching:
    ShowMonList                         
    WaitForMonSelection                 
subscr_231_SwitchPrompt:
    SwitchInAndUpdate                   BATTLER_SWITCHING
    // "{0} {1} is about so end in {2}. Will you switch your Pokemon?"
    Message                             835, TAG_TRTYPE_TRNAME_NICK_TRNAME, BATTLER_SWITCHING, BATTLER_SWITCHING, BATTLER_SWITCHING, BATTLER_ME, NaN, NaN
    Wait                                
    YesNoBox                            YES_NO_CHANGE_MON
    YesNoWait                           subscr_231_SwitchModeDoSwitch, subscr_231_DoEnemySwitch
subscr_231_SwitchModeDoSwitch:
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER_TEMP, VAR_SWITCHED_BATTLER
    ShowPartyList                       
    WaitPartyList                       subscr_231_TrainerNoSwitch
    CallSubscript                       SUBSCR_SWITCH_POKEMON
subscr_231_TrainerNoSwitch:
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_SWITCHED_BATTLER_TEMP
subscr_231_DoEnemySwitch:
    LoadBallGaugeGraphics               
    ShowBallGauge                       BATTLER_SWITCHING
    Wait                                
    SendOutMessage                      BATTLER_SWITCHING
    Wait                                
    HideBallGauge                       BATTLER_SWITCHING
    Wait                                
    FreeBallGaugeGraphics               
    PokemonAppear                       BATTLER_SWITCHING
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_SWITCHING
    Wait                                
    CallSubscript                       SUBSCR_HAZARDS_CHECK
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON, subscr_231_Resume
    CallSubscript                       SUBSCR_FAINT
subscr_231_Resume:
    JumpIfAnySwitching                  subscr_231_SwitchPrompt
    End                                 

.close