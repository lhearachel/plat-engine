.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_024.bin", 0

subscr_024:
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_HIT_DAMAGE
    If                                  EQUAL, VAR_HP_TEMP, 0, 3
    DamageDiv                           VAR_HP_TEMP, 2
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_LEECHING, 15
    GetItemPower                        BATTLER_ATTACKER, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    CheckAbility                        MODE_HAVE, BATTLER_DEFENDER, ABILITY_LIQUID_OOZE, 33
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, 14
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    JumpToSubscript                     2
    Message                             82, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET, VAR_MOVE_TEMP, 377
    Message                             1054, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MAGIC_GUARD, 8
    JumpToSubscript                     2
    Message                             720, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close