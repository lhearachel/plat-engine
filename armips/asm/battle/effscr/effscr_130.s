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


.create "build/battle/scr/effscr/be_seq_130.bin", 0

effscr_130:
    // This move is banned in Little Cup regulation mode
    If                                  FLAG_EQ, VAR_RULESET, 1, effscr_130_BannedInLittleCup
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS
    SetVar                              OP_SET, VAR_DAMAGE, -20
    End

effscr_130_BannedInLittleCup:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close