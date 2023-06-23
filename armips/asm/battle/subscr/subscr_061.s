.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_061.bin", 0

// SUBSCR_CRASH_ON_MISS
subscr_061:
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MAGIC_GUARD, subscr_061_End
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_CRASH_DAMAGE, subscr_061_End
    // "{0} kept going and crashed!"
    Message                             268, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Calc the damage applied by crashing (either half of damage it would've dealt, or half of the target's max HP, whichever is greater)
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_DAMAGE
    DamageDiv                           VAR_HP_TEMP, 2
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_MAX_HP, VAR_TEMP_WORK
    SetVar                              OP_MUL, VAR_TEMP_WORK, -1
    DamageDiv                           VAR_TEMP_WORK, 2
    JumpIf                              LESSER, VAR_TEMP_WORK, VAR_HP_TEMP, subscr_061_HPLoss
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_TEMP_WORK
subscr_061_HPLoss:
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
subscr_061_End:
    End                                 

.close