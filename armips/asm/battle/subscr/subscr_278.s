.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_278.bin", 0

subscr_278:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TEMP_SPE_MAX, 1, 17
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, 52
    If                                  EQUAL, VAR_CLIENT_WORKING_COUNT, 1, 23
    SetStatusEffect                     BATTLER_ATTACKER, 10
    Wait                                
    Branch                              17
    SetStatusEffect                     BATTLER_ATTACKER, 10
    Wait                                
    If                                  EQUAL, VAR_CLIENT_WORKING_COUNT, 1, 8
    Message                             1254, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, 5
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TEMP_SPE_MAX, 0, 7
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_TEMP_SPE_MAX, 0
    RemoveItem                          BATTLER_ATTACKER
    End                                 

.close