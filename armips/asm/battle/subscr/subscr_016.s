.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_016.bin", 0

subscr_016:
    If                                  EQUAL, VAR_WAS_MOVE_CRITICAL, 1, 45
    Message                             774, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    CheckAbility                        MODE_NOT_HAVE, BATTLER_DEFENDER, ABILITY_ANGER_POINT, 34
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, 28
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12, 22
    SetStatusEffect                     BATTLER_DEFENDER, 12
    Wait                                
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12
    SetVar                              OP_SET, VAR_PREPARED_MESSAGE, 1
    Message                             1093, TAG_NICK_ABILITY_STAT, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close