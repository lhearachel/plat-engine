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


.create "build/battle/scr/subscr/sub_seq_009.bin", 0

// SUBSCR_SWITCH_POKEMON
subscr_009:
    TryNaturalCure                      BATTLER_SWITCHING, subscr_009_Start
    SetMonData                          OP_SET, BATTLER_SWITCHING, BATTLE_MON_CONDITION, 0

subscr_009_Start:
    ReturnMessage                       BATTLER_SWITCHING
    Wait                                
    CallSubscript                       SUBSCR_PURSUIT
    IfMonData                           NOT_EQUAL, BATTLER_SWITCHING, BATTLE_MON_HP, 0, subscr_009_Resume
    Branch                              subscr_009_ResumeAfterPursuitKill

subscr_009_Resume:
    PokemonReturn                       BATTLER_SWITCHING
    Wait                                
    HPGaugeSlideOut                     BATTLER_SWITCHING
    Wait                                
subscr_009_ResumeAfterPursuitKill:
    SwitchInAndUpdate                   BATTLER_SWITCHING
    LoadBallGaugeGraphics               
    ShowBallGauge                       BATTLER_SWITCHING
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 1, subscr_009_EnemySwitchMessage
    SendOutMessage                      BATTLER_SWITCHING
    Branch                              subscr_009_ResumeAfterEnemySwitchMessage

subscr_009_EnemySwitchMessage:
    Message                             979, TAG_NICK, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
subscr_009_ResumeAfterEnemySwitchMessage:
    Wait                                
    HideBallGauge                       BATTLER_SWITCHING
    Wait                                
    FreeBallGaugeGraphics               
    PokemonAppear                       BATTLER_SWITCHING
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_SWITCHING
    Wait                                
    CallSubscript                       SUBSCR_HAZARDS_CHECK
    If                                  GREATER, VAR_FAINTED_BATTLER, 3, subscr_009_Cleanup
    SetVarFromVar                       OP_TO_BIT, VAR_TEMP_WORK, VAR_FAINTED_BATTLER
    SetVar                              OP_LSH, VAR_TEMP_WORK, 24
    JumpIf                              FLAG_NEQ, VAR_SERVER_STATUS_FLAG, VAR_TEMP_WORK, subscr_009_Cleanup
    CallSubscript                       SUBSCR_FAINT

subscr_009_Cleanup:
    End                                 

.close