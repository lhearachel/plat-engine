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


.create "build/battle/scr/subscr/sub_seq_016.bin", 0

// SUBSCR_CRITICAL_HIT
subscr_016:
    // This actually checks if the move was NOT a Critical
    If                                  EQUAL, VAR_WAS_MOVE_CRITICAL, 1, subscr_016_End
    // "A critical hit!"
    Message                             774, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Check for Anger Point; only boost Attack if the defender is still alive and
    // has not already maximized its Attack stages.
    CheckAbility                        MODE_NOT_HAVE, BATTLER_DEFENDER, ABILITY_ANGER_POINT, subscr_016_End
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_016_End
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12, subscr_016_End
    // Got this far, apply the boost.
    SetStatusEffect                     BATTLER_DEFENDER, STATUS_STAT_BOOST
    Wait                                
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_ATK_STAGE, 12
    SetVar                              OP_SET, VAR_PREPARED_MESSAGE, STAT_ATTACK
    // "{0} maxed its Attack with Anger Point!"
    Message                             1093, TAG_NICK_ABILITY_STAT, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_016_End:
    End                                 

.close