.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_126.bin", 0

subscr_126:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 5
    AttackMessage                       
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    End                                 

.close