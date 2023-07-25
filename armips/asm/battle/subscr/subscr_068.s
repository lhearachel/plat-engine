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


.create "build/battle/scr/subscr/sub_seq_068.bin", 0

// SUBSCR_APPLY_LEECH_SEED
subscr_068:
    // Substitute blocks Leech Seed
    CheckSubstitute                     BATTLER_DEFENDER, subscr_068_Substitute
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_TYPE_1, TYPE_GRASS, subscr_068_TypeBlocked
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_TYPE_2, TYPE_GRASS, subscr_068_TypeBlocked
    AttackMessage                       
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_LEECH_SEEDED, subscr_068_Failed
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_MISSED_BUT_IT_FAILED, subscr_068_Failed
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetMonDataFromVar                   OP_SET_FLAG, 2, BATTLE_MON_MOVE_EFFECTS, VAR_ATTACKER
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_LEECH_SEEDED
    // "{0} was seeded!"
    Message                             290, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_068_End

subscr_068_Failed:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    WaitTime                            30
    // "{0} evaded the attack!"
    Message                             293, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
subscr_068_End:
    Wait                                
    WaitTime                            30
    End                                 

subscr_068_Substitute:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

subscr_068_TypeBlocked:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_DOES_NOT_AFFECT
    End                                 

.close