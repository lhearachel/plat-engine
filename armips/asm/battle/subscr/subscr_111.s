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


.create "build/battle/scr/subscr/sub_seq_111.bin", 0

// SUBSCR_RECOVER_HP
subscr_111:
    // Make sure there is actually HP to recover
    SetMonDataFromVar                   OP_GET, BATTLER_WORKING, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_WORKING, BATTLE_MON_HP, VAR_CALC_WORK, subscr_111_NoRecovery
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    // Play any animation
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_RECOVERY_EFFECT, subscr_111_SkipAnimation
    SetStatusEffect                     BATTLER_WORKING, STATUS_RESTORE_HP
    Wait                                
subscr_111_SkipAnimation:
    // Change the HP value
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} regained health!"
    Message                             184, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_111_NoRecovery:
    WaitTime                            30
    // "{0}'s HP is full!"
    Message                             187, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close