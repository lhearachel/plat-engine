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



.create "build/battle/scr/effscr/be_seq_109.bin", 0

// Curse
//
// Note that the effect here differs depending on the Pokemon's type.
effscr_109:
    // If the user has Ghost typing, branch the effect
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TYPE_1, TYPE_GHOST, effscr_109_GhostType_Precheck
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TYPE_2, TYPE_GHOST, effscr_109_GhostType_Precheck
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_ATTACKER | ADDL_EFFECT_CURSE
    End                                 

effscr_109_GhostType_Precheck:
    // Make sure the attacker and defender are not equal; if they are, then pick
    // a random opponent and reassign that as the defender.
    //
    // This is mostly to ensure that the effect is handled correctly if a user
    // is changed to the Ghost type before execution. That can happen, e.g., to
    // a Kecleon with Color Change which was previously changed to a non-Normal
    // type, then hit with a Ghost-type move before it acts for the turn.
    JumpIf                              NOT_EQUAL, VAR_ATTACKER, VAR_DEFENDER, effscr_109_GhostType_Effect
    PickRandomOpponent                  BATTLER_ATTACKER
effscr_109_GhostType_Effect:
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_GHOST_CURSE
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    End                                 

.close