.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_012.bin", 0

subscr_012:
    StatBoostChange                     38, 56, 57
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG2, 2, 13
    SetStatusEffectFromVar              BATTLER_EFFECTSRC, VAR_TEMP_WORK
    Wait                                
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG2, 128, 4
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, 2
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    End                                 
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 2
    AttackMessage                       
    Wait                                
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 2097152, 6
    WaitTime                            30
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close