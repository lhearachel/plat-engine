.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_69.s", 0

subscr_069:
    SetStatusEffectMulti                BATTLER_ATTACKER_WORK, BATTLER_DEFENDER_WORK, 32
    Wait                                
    SetMonDataFromVar                   OP_GET, 15, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 8
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER_WORK
    JumpToSubscript                     2
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_HIT_DAMAGE
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_ATTACKER_WORK, HOLD_EFFECT_BOOST_LEECHING, 15
    GetItemPower                        BATTLER_ATTACKER_WORK, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER_WORK
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    CheckAbility                        MODE_HAVE, BATTLER_DEFENDER_WORK, ABILITY_LIQUID_OOZE, 33
    IfMonData                           NOT_EQUAL, BATTLER_WORKING, BATTLE_MON_HEAL_BLOCK_TURNS, 0, 14
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    JumpToSubscript                     2
    Message                             296, TAG_NICK, BATTLER_DEFENDER_WORK
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET, VAR_MOVE_TEMP, 377
    Message                             1054, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER_WORK, ABILITY_MAGIC_GUARD, 9
    JumpToSubscript                     2
    Message                             720, TAG_NONE
    Wait                                
    WaitFrames                          30
    End                                 
    Message                             720, TAG_NONE
    Wait                                
    WaitFrames                          30
    Message                             727, TAG_NICK_ABILITY_NICK_ABILITY, BATTLER_ATTACKER_WORK, BATTLER_ATTACKER_WORK, BATTLER_DEFENDER_WORK, BATTLER_DEFENDER_WORK
    Wait                                
    WaitFrames                          30
    End                                 
