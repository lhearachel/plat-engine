.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_97.bin", 0

subscr_097:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65536, 47
    CheckSubstitute                     BATTLER_DEFENDER, 44
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 268435456, 38
    JumpToSubscript                     76
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, 268435456
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    DamageDiv                           VAR_HP_TEMP, 2
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    JumpToSubscript                     2
    Message                             417, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close