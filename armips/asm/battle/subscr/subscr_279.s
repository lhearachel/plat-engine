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


.create "build/battle/scr/subscr/sub_seq_279.bin", 0

// SUBSCR_PUSH_ATTACKER_DEFENDER
subscr_279:
    SetVarFromVar                       OP_GET, VAR_ATTACKER, VAR_ATTACKER_TEMP
    SetVarFromVar                       OP_GET, VAR_DEFENDER, VAR_DEFENDER_TEMP
    End                                 

.close