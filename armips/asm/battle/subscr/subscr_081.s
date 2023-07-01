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


.create "build/battle/scr/subscr/sub_seq_081.bin", 0

// SUBSCR_FEINT
subscr_081:
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_FEINT, subscr_081_Feint
subscr_081_ShadowForce:
    CheckOneTurnFlag                    BATTLER_DEFENDER, OTF_PROTECTED, 0, subscr_081_SkipMessage
    // "It broke through {0}'s protection!"
    Message                             1243, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_081_AfterMessage

subscr_081_Feint:
    Message                             1048, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
subscr_081_AfterMessage:
    Wait                                
    WaitTime                            30
subscr_081_SkipMessage:
    SetOneTurnFlag                      BATTLER_DEFENDER, OTF_PROTECTED, 0
    End                                 

.close