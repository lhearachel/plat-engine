.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_265.bin", 0

effscr_265:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_DEFENDER, ABILITY_OBLIVIOUS, 44
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_GENDER, 2, 22
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_GENDER, 2, 16
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_GENDER, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_ATTACKER, BATTLE_MON_GENDER, VAR_CALC_WORK, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 2147483697
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            15
    Message                             1235, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            15
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close