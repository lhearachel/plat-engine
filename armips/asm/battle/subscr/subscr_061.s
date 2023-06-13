.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_061.bin", 0

subscr_061:
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MAGIC_GUARD, 50
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, 4096, 45
    Message                             268, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_DAMAGE
    DamageDiv                           VAR_HP_TEMP, 2
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_MAX_HP, VAR_TEMP_WORK
    SetVar                              OP_MUL, VAR_TEMP_WORK, 4294967295
    DamageDiv                           VAR_TEMP_WORK, 2
    JumpIf                              LESSER, VAR_TEMP_WORK, VAR_HP_TEMP, 4
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_TEMP_WORK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    End                                 

.close