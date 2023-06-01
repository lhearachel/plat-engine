.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_222.s", 0

effscr_222:
    TryNaturalGift                      5
    CriticalCalc                        
    DamageCalc                          
    RemoveItem                          BATTLER_ATTACKER
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
