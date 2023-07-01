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


.create "build/battle/scr/effscr/be_seq_173.bin", 0

// Nature Power
effscr_173:
    AttackMessage                       
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    NaturePower                         
    Message                             490, TAG_MOVE_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    JumpToMoveScript                    

.close