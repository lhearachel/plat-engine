.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_231.bin", 0

subscr_231:
    If                                  EQUAL, VAR_TEMP_WORK, 1, 30
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 1, 9
    Message                             11, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    YesNoBox                            YES_NO_NEXT_MON
    YesNoWait                           0, 6
    ShowMonList                         
    WaitForMonSelection                 
    SwitchInAndUpdate                   BATTLER_SWITCHING
    Branch                              40
    TryEscape                           BATTLER_ME, 4
    JumpToSubscript                     8
    Branch                              4294967283
    JumpToSubscript                     3
    End                                 
    ShowMonList                         
    WaitForMonSelection                 
    SwitchInAndUpdate                   BATTLER_SWITCHING
    Message                             835, TAG_TRTYPE_TRNAME_NICK_TRNAME, BATTLER_SWITCHING, BATTLER_SWITCHING, BATTLER_SWITCHING, BATTLER_ME, NaN, NaN
    Wait                                
    YesNoBox                            YES_NO_CHANGE_MON
    YesNoWait                           0, 13
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER_TEMP, VAR_SWITCHED_BATTLER
    ShowPartyList                       
    WaitPartyList                       2
    JumpToSubscript                     9
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_SWITCHED_BATTLER_TEMP
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
    JumpToSubscript                     99
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, 251658240, 2
    JumpToSubscript                     6
    JumpIfAnySwitching                  4294967239
    End                                 

.close