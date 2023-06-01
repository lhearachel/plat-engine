.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_26.s", 0

subscr_026:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, 37
    SetMonDataFromVar                   OP_GET, 255, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 8
    CheckAbility                        MODE_NOT_HAVE, BATTLER_WORKING, ABILITY_HEATPROOF, 3
    DamageDiv                           VAR_HP_TEMP, 2
    SetVar                              OP_MUL, VAR_HP_TEMP, 4294967295
    Message                             95, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetStatusEffect                     BATTLER_WORKING, 3
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    End                                 
