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


.create "build/battle/scr/subscr/sub_seq_054.bin", 0

// SUBSCR_APPLY_MIST
subscr_054:
    SetMist                             subscr_054_Failure
    // "Your team became shrouded in mist!"
    PrepareMessage                      271, TAG_NONE_DIR, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    CallSubscript                       SUBSCR_ANIMATION_WITH_PREPARED_MESSAGE
subscr_054_Failure:
    End                                 

.close