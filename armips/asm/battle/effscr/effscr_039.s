.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_039.bin", 0

effscr_039:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096, 26
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 512, 21
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, 9
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741836
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 35
    End                                 
    JumpToSubscript                     217
    If                                  EQUAL, VAR_DEFENDER, 255, 6
    SetVar                              OP_ADD, VAR_CRITICAL_CHANCE, 1
    CriticalCalc                        
    DamageCalc                          
    JumpToSubscript                     259
    End                                 

.close