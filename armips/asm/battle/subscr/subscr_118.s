.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_118.s", 0

subscr_118:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 7, 4
    JumpToSubscript                     18
    Jump                                32
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 8, 4
    JumpToSubscript                     22
    Jump                                22
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 16, 4
    JumpToSubscript                     25
    Jump                                12
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 64, 4
    JumpToSubscript                     31
    Jump                                2
    JumpToSubscript                     47
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, 255, 8
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    End                                 
