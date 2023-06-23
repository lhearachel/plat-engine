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


.create "build/battle/scr/subscr/sub_seq_263.bin", 0

// SUBSCR_BAD_DREAMS
subscr_263:
    SetVar                              OP_SET, VAR_ATTACKER_WORK, 0
subscr_263_Loop:
    If                                  FLAG_NEQ, VAR_TEMP_WORK, 1, subscr_263_Resume
    // "{0} is tormented by {2}'s {1}!"
    Message                             1121, TAG_NICK_ABILITY_NICK, BATTLER_ATTACKER_WORK, BATTLER_ATTACKER_WORK, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_HP, 0, subscr_263_Exit
subscr_263_Resume:
    SetVar                              OP_ADD, VAR_ATTACKER_WORK, 1
    SetVar                              OP_RSH, VAR_TEMP_WORK, 1
    If                                  NOT_EQUAL, VAR_TEMP_WORK, 0, subscr_263_Loop
subscr_263_Exit:
    End                                 

.close