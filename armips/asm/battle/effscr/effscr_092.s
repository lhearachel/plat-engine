.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_92.bin", 0

effscr_092:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 7, 14
    If                                  EQUAL, VAR_MOVE_NUM_WORK, 214, 2
    JumpToSubscript                     20
    SetVar                              OP_SET_FLAG, VAR_ADD_STATUS_INDIRECT, 2147483656
    CriticalCalc                        
    DamageCalc                          
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close