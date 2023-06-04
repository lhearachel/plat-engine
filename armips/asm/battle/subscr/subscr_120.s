.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_120.bin", 0

subscr_120:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ATK_STAGE, 12, 47
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 2
    JumpIfMonData                       LESSER, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP, 33
    JumpToSubscript                     76
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_ATK_STAGE, 12
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    SetStatusEffect                     BATTLER_ATTACKER, 12
    Wait                                
    Message                             449, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close