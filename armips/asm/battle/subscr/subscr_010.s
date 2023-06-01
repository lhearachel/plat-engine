.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_10.s", 0

subscr_010:
    ShowMonList                         
    WaitForMonSelection                 
    SwitchInAndUpdate                   BATTLER_SWITCHING
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
    JumpIfAnySwitching                  4294967265
    End                                 
