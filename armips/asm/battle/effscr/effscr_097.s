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


.create "build/battle/scr/effscr/be_seq_097.bin", 0

// Sleep Talk
effscr_097:
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, effscr_097_Failure
    // Sleeping subscript
    CallSubscript                       SUBSCR_SLEEPING
    TrySleepTalk                        effscr_097_Failure
    // Play the script for the chosen move
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    JumpToMoveScript                    

effscr_097_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close