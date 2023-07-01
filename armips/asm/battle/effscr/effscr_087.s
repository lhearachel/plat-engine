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


.create "build/battle/scr/effscr/be_seq_087.bin", 0

// Deal damage equal to user's level
effscr_087:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_LEVEL, VAR_DAMAGE
    SetVar                              OP_MUL, VAR_DAMAGE, -1
    End                                 

.close