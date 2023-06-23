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


.create "build/battle/scr/effscr/be_seq_265.bin", 0

// Captivate
effscr_265:
    // If the defender has Oblivious, fail.
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_DEFENDER, ABILITY_OBLIVIOUS, effscr_265_BlockedByOblivious
    // If either the attacker or defender is genderless, fail.
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_GENDER, 2, effscr_265_InvalidGender
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_GENDER, 2, effscr_265_InvalidGender
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_GENDER, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_ATTACKER, BATTLE_MON_GENDER, VAR_CALC_WORK, effscr_265_InvalidGender
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_SPA_DOWN_2
    End                                 

effscr_265_InvalidGender:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    // "It failed to affect {0}!"
    Message                             1235, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

effscr_265_BlockedByOblivious:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    // "{0}'s {1} made {2} ineffective!"
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close