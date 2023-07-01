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


.create "build/battle/scr/effscr/be_seq_178.bin", 0

// Copy the target's ability
effscr_178:
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_MULTITYPE, effscr_178_CannotCopy
    // Fail if the user is holding a Griseous Orb (don't fuck around with item-induced form changes)
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, effscr_178_CannotCopy
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_EXTRA_FAIL_CHECK | ADDL_EFFECT_ROLE_PLAY
    End                                 

effscr_178_CannotCopy:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close