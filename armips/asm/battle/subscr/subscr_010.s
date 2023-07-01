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


.create "build/battle/scr/subscr/sub_seq_010.bin", 0

// SUBSCR_PARTY_LIST
subscr_010:
    ShowMonList                         
    WaitForMonSelection                 

subscr_010_SwitchLoop:
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
    CallSubscript                       SUBSCR_HAZARDS_CHECK
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_ANY_FAINTED_MON, subscr_010_NoFaintedMons
    CallSubscript                       SUBSCR_FAINT

subscr_010_NoFaintedMons:
    JumpIfAnySwitching                  subscr_010_SwitchLoop
    End                                 

.close