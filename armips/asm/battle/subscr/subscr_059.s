.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_59.s", 0

subscr_059:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, 78
    If                                  EQUAL, VAR_MOVE_TEMP, 35, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 83, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 463, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 128, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 250, 30
    If                                  EQUAL, VAR_MOVE_TEMP, 328, 30
    SetStatusEffect                     BATTLER_WORKING, 33
    Jump                                28
    SetStatusEffect                     BATTLER_WORKING, 34
    Jump                                23
    SetStatusEffect                     BATTLER_WORKING, 35
    Jump                                18
    SetStatusEffect                     BATTLER_WORKING, 36
    Jump                                13
    SetStatusEffect                     BATTLER_WORKING, 37
    Jump                                8
    SetStatusEffect                     BATTLER_WORKING, 38
    Jump                                3
    SetStatusEffect                     BATTLER_WORKING, 39
    Wait                                
    Message                             262, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    End                                 
