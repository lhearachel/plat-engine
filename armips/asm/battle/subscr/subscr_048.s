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


.create "build/battle/scr/subscr/sub_seq_048.bin", 0

// SUBSCR_PAY_DAY
subscr_048:
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_LEVEL, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_CALC_WORK, 5
    // Don't add money if we targeted an ally
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_ENEMY, subscr_048_DoNotAddMoney
    SetVarFromVar                       OP_ADD, VAR_MONEY, VAR_CALC_WORK
subscr_048_DoNotAddMoney:
    // "Coins scattered everywhere!"
    Message                             818, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close