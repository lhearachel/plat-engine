.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_099.bin", 0

subscr_099:
    CheckAbility                        MODE_HAVE, BATTLER_SWITCHING, ABILITY_MAGIC_GUARD, 101
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 28672, 28
    CheckItemEffect                     MODE_HAVE, BATTLER_SWITCHING, HOLD_EFFECT_HALVE_SPEED, 23
    CheckAbility                        MODE_HAVE, BATTLER_SWITCHING, ABILITY_LEVITATE, 66
    IfMonData                           EQUAL, BATTLER_SWITCHING, BATTLE_MON_TYPE_1, 2, 60
    IfMonData                           EQUAL, BATTLER_SWITCHING, BATTLE_MON_TYPE_2, 2, 54
    IfMonData                           FLAG_EQ, BATTLER_SWITCHING, BATTLE_MON_MOVE_EFFECTS, 134217728, 48
    CheckToxicSpikes                    BATTLER_SWITCHING, 25
    If                                  EQUAL, VAR_CALC_WORK, 2, 18
    If                                  EQUAL, VAR_CALC_WORK, 1, 9
    Message                             1065, TAG_NONE_DIR, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              6
    JumpToSubscript                     22
    Branch                              2
    JumpToSubscript                     47
    CheckSpikes                         BATTLER_SWITCHING, 17
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_SWITCHED_BATTLER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             429, TAG_NICK, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    CheckStealthRock                    BATTLER_SWITCHING, 17
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_SWITCHED_BATTLER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             1079, TAG_NICK, BATTLER_SWITCHING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close