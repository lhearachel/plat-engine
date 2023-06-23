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


.create "build/battle/scr/subscr/sub_seq_162.bin", 0

// SUBSCR_POWER_TRICK
subscr_162:
    SetMonData                          OP_XOR, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_POWER_TRICK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_ATTACK, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_DEFENSE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_ATTACK, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_DEFENSE, VAR_CALC_WORK
    // "{0} switched its Attack and Defense!"
    Message                             1009, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close