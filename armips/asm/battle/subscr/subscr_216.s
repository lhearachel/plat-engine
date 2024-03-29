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


.create "build/battle/scr/subscr/sub_seq_216.bin", 0

// SUBSCR_ITEM_GIVE_STICKY_BARB
subscr_216:
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 0
    End                                 

.close