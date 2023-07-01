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


.create "build/battle/scr/effscr/be_seq_088.bin", 0

// Psywave
effscr_088:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS
    // Generate a random number from 5 to 14
    Random                              10, 5
    // Multiply the random number by the attacker's level
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_LEVEL, VAR_DAMAGE
    SetVarFromVar                       OP_MUL, VAR_DAMAGE, VAR_CALC_WORK
    // Divide the result by 10
    SetVar                              OP_DIV, VAR_DAMAGE, 10
    // Deal at least 1 damage always
    If                                  NOT_EQUAL, VAR_DAMAGE, 0, effscr_088_Damage
    SetVar                              OP_SET, VAR_DAMAGE, 1
effscr_088_Damage:
    SetVar                              OP_MUL, VAR_DAMAGE, -1
    End                                 

.close