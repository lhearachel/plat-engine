.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_285.bin", 0

// Subscript for Pressure activation
subscr_285:
    LoadPopupGraphics
    ShowPopup                           BATTLER_CLIENT_WORK
    Wait
    Message                             1238, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    HidePopup                           BATTLER_CLIENT_WORK
    Wait
    FreePopupGraphics
    End                                 

.close