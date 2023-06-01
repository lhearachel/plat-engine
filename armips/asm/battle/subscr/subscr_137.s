.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_137.s", 0

subscr_137:
    SetStatusEffect                     BATTLER_WORKING, 40
    Wait                                
    Message                             539, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonDataFromVar                   OP_GET, 255, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 16
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_WORKING, HOLD_EFFECT_BOOST_LEECHING, 15
    GetItemPower                        BATTLER_WORKING, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    End                                 
