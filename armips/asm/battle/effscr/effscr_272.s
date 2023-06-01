.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_272.s", 0

effscr_272:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096, 44
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 512, 39
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, 14
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 536870912
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741836
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 35
    End                                 
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 536870912
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS_TEMP, 536870912
    JumpToSubscript                     217
    ToggleVanish                        1, 1
    If                                  EQUAL, VAR_DEFENDER, 255, 6
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870991
    CriticalCalc                        
    DamageCalc                          
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 537133248
    JumpToSubscript                     259
    End                                 
