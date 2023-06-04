.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_9.bin", 0

subscr_009:
    TryNaturalCure                      BATTLER_SWITCHING, 5
    SetMonData                          OP_SET, BATTLER_SWITCHING, BATTLE_MON_CONDITION, 0
    ReturnMessage                       BATTLER_SWITCHING
    Wait                                
    JumpToSubscript                     153
    IfMonData                           NOT_EQUAL, BATTLER_SWITCHING, BATTLE_MON_HP, 0, 2
    Branch                              6
    PokemonReturn                       BATTLER_SWITCHING
    Wait                                
    HPGaugeSlideOut                     BATTLER_SWITCHING
    Wait                                
    SwitchInAndUpdate                   BATTLER_SWITCHING
    LoadBallGaugeGraphics               
    ShowBallGauge                       BATTLER_SWITCHING
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 1, 4
    SendOutMessage                      BATTLER_SWITCHING
    Branch                              4
    Message                             979, TAG_NICK, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    HideBallGauge                       BATTLER_SWITCHING
    Wait                                
    FreeBallGaugeGraphics               
    PokemonAppear                       BATTLER_SWITCHING
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_SWITCHING
    Wait                                
    JumpToSubscript                     99
    If                                  GREATER, VAR_FAINTED_BATTLER, 3, 15
    SetVarFromVar                       OP_TO_BIT, VAR_TEMP_WORK, VAR_FAINTED_BATTLER
    SetVar                              OP_LSH, VAR_TEMP_WORK, 24
    JumpIf                              FLAG_NEQ, VAR_SERVER_STATUS_FLAG, VAR_TEMP_WORK, 2
    JumpToSubscript                     6
    End                                 

.close