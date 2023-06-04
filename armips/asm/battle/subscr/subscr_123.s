.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_123.bin", 0

subscr_123:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    MessagePrepared                     
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    End                                 

.close