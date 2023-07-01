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


.create "build/battle/scr/subscr/sub_seq_220.bin", 0

// SUBSCR_FLING
subscr_220:
    If                                  EQUAL, VAR_FLING_SUBSCRIPT, 0, subscr_220_Exit
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_220_Exit
    CheckSubstitute                     BATTLER_DEFENDER, subscr_220_Exit
    SetVarFromVar                       OP_SET, VAR_HP_TEMP, VAR_FLING_TEMP
    CallSubscriptFromVar                VAR_FLING_SUBSCRIPT
subscr_220_Exit:
    End                                 

.close