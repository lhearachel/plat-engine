.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_268.s", 0

effscr_268:
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FIGHTING_PLATE, 77
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FLYING_PLATE, 78
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_POISON_PLATE, 79
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GROUND_PLATE, 80
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ROCK_PLATE, 81
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_BUG_PLATE, 82
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GHOST_PLATE, 83
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_STEEL_PLATE, 84
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FIRE_PLATE, 85
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_WATER_PLATE, 86
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GRASS_PLATE, 87
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ELECTRIC_PLATE, 88
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_PSYCHIC_PLATE, 89
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ICE_PLATE, 90
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_DRAGON_PLATE, 91
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_DARK_PLATE, 92
    Jump                                94
    SetVar                              OP_SET, VAR_MOVE_TYPE, 1
    Jump                                88
    SetVar                              OP_SET, VAR_MOVE_TYPE, 2
    Jump                                82
    SetVar                              OP_SET, VAR_MOVE_TYPE, 3
    Jump                                76
    SetVar                              OP_SET, VAR_MOVE_TYPE, 4
    Jump                                70
    SetVar                              OP_SET, VAR_MOVE_TYPE, 5
    Jump                                64
    SetVar                              OP_SET, VAR_MOVE_TYPE, 6
    Jump                                58
    SetVar                              OP_SET, VAR_MOVE_TYPE, 7
    Jump                                52
    SetVar                              OP_SET, VAR_MOVE_TYPE, 8
    Jump                                46
    SetVar                              OP_SET, VAR_MOVE_TYPE, 10
    Jump                                40
    SetVar                              OP_SET, VAR_MOVE_TYPE, 11
    Jump                                34
    SetVar                              OP_SET, VAR_MOVE_TYPE, 12
    Jump                                28
    SetVar                              OP_SET, VAR_MOVE_TYPE, 13
    Jump                                22
    SetVar                              OP_SET, VAR_MOVE_TYPE, 14
    Jump                                16
    SetVar                              OP_SET, VAR_MOVE_TYPE, 15
    Jump                                10
    SetVar                              OP_SET, VAR_MOVE_TYPE, 16
    Jump                                4
    SetVar                              OP_SET, VAR_MOVE_TYPE, 17
    CriticalCalc                        
    DamageCalc                          
    End                                 
