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


.create "build/battle/scr/subscr/sub_seq_178.bin", 0

// SUBSCR_ABILITY_HP_RESTORE (Volt Absorb, Water Absorb)
subscr_178:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_CALC_WORK, subscr_178_NoRestore
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} restored HP using its {1}!"
    Message                             635, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_178_NoRestore:
    // "{0}'s {1} made {2} useless!"
    Message                             638, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close