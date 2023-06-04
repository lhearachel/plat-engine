.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_13.bin", 0

subscr_013:
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    SetContinuation                     BATTLER_EFFECTSRC
    IfMonData                           FLAG_NEQ, BATTLER_EFFECTSRC, BATTLE_MON_MOVE_EFFECTS, 537133248, 3
    ToggleVanish                        7, 1
    End                                 

.close