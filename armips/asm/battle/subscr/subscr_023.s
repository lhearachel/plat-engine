.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_23.s", 0

subscr_023:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, 51
    CheckAbility                        MODE_NOT_HAVE, BATTLER_WORKING, ABILITY_POISON_HEAL, 29
    SetMonDataFromVar                   OP_GET, 255, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    JumpIfMonData                       EQUAL, BATTLER_WORKING, BATTLE_MON_HP, VAR_HP_TEMP, 35
    DamageDiv                           VAR_HP_TEMP, 8
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             635, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK
    Wait                                
    WaitFrames                          30
    End                                 
    Message                             73, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_WORKING, 2
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    End                                 
