.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_268.s", 0

subscr_268:
    WaitFrames                          15
    PlaySound                           BATTLER_ATTACKER, 1516
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    RecoverStatus                       BATTLER_ATTACKER
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, 32
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 1, 39
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 2, 41
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 3, 43
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 4, 45
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 5, 47
    Message                             896, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                47
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 7
    Message                             890, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                40
    Message                             875, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                28
    Message                             884, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                21
    Message                             881, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                14
    Message                             878, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                7
    Message                             887, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Jump                                0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    Wait                                
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    WaitFrames                          30
    End                                 
