.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_179.bin", 0

subscr_179:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_FLASH_FIRE_ACTIVE, 0, 14
    Message                             656, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_FLASH_FIRE_ACTIVE, 1
    End                                 
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close