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


.create "build/battle/scr/subscr/sub_seq_001.bin", 0

// SUBSCR_TRY_MOVE
subscr_001:
    // If the move's effect is direct (i.e., it's a status move), jump to the end
    If                                  EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_001_End
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
subscr_001_End:
    End                                 

.close