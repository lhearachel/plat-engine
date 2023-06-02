.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_170.s", 0

effscr_170:
    If                                  NOT_EQUAL, VAR_PHYSICAL_DAMAGE, 0, 12
    If                                  NOT_EQUAL, VAR_SPECIAL_DAMAGE, 0, 7
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    CriticalCalc                        
    DamageCalc                          
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 131072
    PrepareMessage                      600, TAG_NICK, BATTLER_ATTACKER
    End                                 
