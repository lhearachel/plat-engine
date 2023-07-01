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


.create "build/battle/scr/subscr/sub_seq_035.bin", 0

// SUBSCR_START_BIDE
subscr_035:
    // Play the starting move animation
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // Set the flag that tells us to keep using this move
    SetContinuation                     BATTLER_ATTACKER
    // Set the condition to 0x200, which tells the server that we have 2 turns of Bide remaining
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_BIDING_START
    // Init the Bide damage counter to 0
    SetVar                              OP_SET, VAR_BIDE_DAMAGE, 0
    End                                 

.close