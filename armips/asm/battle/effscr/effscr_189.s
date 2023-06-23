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


.create "build/battle/scr/effscr/be_seq_189.bin", 0

// Endeavor
effscr_189:
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_DAMAGE
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_CALC_WORK
    JumpIf                              LESSER, VAR_DAMAGE, VAR_CALC_WORK, effscr_189_DefenderHasLessHP
    SetVarFromVar                       OP_SUB, VAR_DAMAGE, VAR_CALC_WORK
    SetVar                              OP_MUL, VAR_DAMAGE, -1
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS
    End

effscr_189_DefenderHasLessHP:                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close