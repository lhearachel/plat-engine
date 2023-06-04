.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_124.bin", 0

subscr_124:
    AttackMessage                       
    Wait                                
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 3, 70
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    SetMonData                          OP_ADD, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_COUNT, 1
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_STOCKPILE_COUNT, VAR_PREPARED_MESSAGE
    Message                             317, TAG_NICK_NUM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 16
    JumpToSubscript                     12
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 131072, 5
    SetMonData                          OP_ADD, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_DEF_BOOSTS, 1
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 19
    JumpToSubscript                     12
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 131072, 5
    SetMonData                          OP_ADD, BATTLER_ATTACKER, BATTLE_MON_STOCKPILE_SPD_BOOSTS, 1
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, 128
    End                                 
    WaitTime                            30
    Message                             320, TAG_NICK_NUM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close