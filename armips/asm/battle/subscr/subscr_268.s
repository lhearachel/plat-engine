.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_268.bin", 0

subscr_268:
    WaitTime                            15
    PlaySound                           BATTLER_ATTACKER, 1516
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RecoverStatus                       BATTLER_ATTACKER
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, 32
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 1, 39
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 2, 41
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 3, 43
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 4, 45
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 5, 47
    Message                             896, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              47
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 7
    Message                             890, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              40
    Message                             875, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              28
    Message                             884, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              21
    Message                             881, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              14
    Message                             878, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              7
    Message                             887, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              0
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    Wait                                
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    WaitTime                            30
    End                                 

.close