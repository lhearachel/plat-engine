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


.create "build/battle/scr/subscr/sub_seq_301.bin", 0

// SUBSCR_SAP_SIPPER
subscr_183:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12, subscr_183_AlreadyMaxed
    SetStatusEffect                     BATTLER_DEFENDER, STATUS_STAT_BOOST
    Wait                                
    // Raise special attack by 1 stage
    SetMonData                          OP_ADD, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 1
    // Specify special attack for the message
    SetVar                              OP_SET, VAR_PREPARED_MESSAGE, STAT_ATTACK
    // "{0}'s {1} raised its {2}!"
    Message                             622, TAG_NICK_ABILITY_STAT, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_183_AlreadyMaxed:
    // "{0}'s {1} made {2} useless!"
    Message                             638, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close