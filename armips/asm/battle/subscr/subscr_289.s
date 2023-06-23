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


.create "build/battle/scr/subscr/sub_seq_289.bin", 0

// SUBSCR_FULL_RESTORE
subscr_289:
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    WaitTime                            30
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED
    JumpTo                              SUBSCR_BAG_HP_RESTORE

.close