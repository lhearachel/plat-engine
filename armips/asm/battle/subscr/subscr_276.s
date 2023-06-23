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


.create "build/battle/scr/subscr/sub_seq_276.bin", 0

// SUBSCR_GET_EXP
subscr_276:
    ShouldGetExp                        subscr_276_Exit
subscr_276_Loop:
    InitGetExp                          
    WaitExp                             
    ExpLoopback                         subscr_276_Loop
subscr_276_Exit:
    End                                 

.close