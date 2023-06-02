.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_233.s", 0

effscr_233:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, 121, 29
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, 23
    TryFling                            21
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2684354696
    CriticalCalc                        
    DamageCalc                          
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             1144, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    RemoveItem                          BATTLER_ATTACKER
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
