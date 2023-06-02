.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_154.s", 0

subscr_154:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 2
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    AttackMessage                       
    Wait                                
    JumpToSubscript                     111
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2147483648, 4
    SetOneTurnFlag                      BATTLER_ATTACKER, 6, 1
    End                                 
