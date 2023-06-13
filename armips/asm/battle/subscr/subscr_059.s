.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_059.bin", 0

subscr_059:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, 78
    If                                  EQUAL, VAR_MOVE_TEMP, 35, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 83, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 463, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 128, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 250, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 328, 30
    SetStatusEffect                     BATTLER_WORKING, 33
    Branch                              28
    SetStatusEffect                     BATTLER_WORKING, 34
    Branch                              23
    SetStatusEffect                     BATTLER_WORKING, 35
    Branch                              18
    SetStatusEffect                     BATTLER_WORKING, 36
    Branch                              13
    SetStatusEffect                     BATTLER_WORKING, 37
    Branch                              8
    SetStatusEffect                     BATTLER_WORKING, 38
    Branch                              3
    SetStatusEffect                     BATTLER_WORKING, 39
    Wait                                
    Message                             262, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpTo                              2
    End                                 

.close