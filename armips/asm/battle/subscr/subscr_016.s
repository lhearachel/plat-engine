.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_16.s", 0

subscr_016:
    If                                  EQUAL, VAR_WAS_MOVE_CRITICAL, 1, 45
    Message                             774, TAG_NONE
    Wait                                
    WaitFrames                          30
    CheckAbility                        MODE_NOT_HAVE, BATTLER_DEFENDER, ABILITY_ANGER_POINT, 34
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 28
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12, 22
    SetStatusEffect                     BATTLER_DEFENDER, 12
    Wait                                
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12
    SetVar                              OP_SET, VAR_PREPARED_MESSAGE, 1
    Message                             1093, TAG_NICK_ABILITY_STAT, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
