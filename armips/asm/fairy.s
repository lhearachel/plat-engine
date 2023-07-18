.nds
.thumb

/*
 * This file contains all edits that can be made to the ROM using ARMIPS which do not deal with data.
 * This file does NOT deal with any of the following:
 *  - The summary screen (image, palette)
 *  - The dex icon (image)
 *  - The item graphics (palette)
 *  - The Judgment battle script
 *  - The Roseli Berry and Pixie Plate implementations
 *
 * Adapted from BluRose's setup in hg-engine.
 */

.open "base/arm9.bin", 0x02000000
.org 0x02077988

/*
 * Input:
 *  - r0: held item effect
 * 
 * Output:
 *  - r0: type from the held item
 */
Pokemon_ArceusType:
    sub     r0, #HOLD_EFFECT_BOOST_FIRE_PLATE
    cmp     r0, #HOLD_EFFECT_BOOST_FAIRY_PLATE - HOLD_EFFECT_BOOST_FIRE_PLATE
    bhi     @@normal
    ldr     r1, =PlateToTypeTable
    ldrb    r0, [r1, r0]
    bx      lr

@@normal:
    mov     r0, #TYPE_NORMAL
    bx      lr

.align 2
.pool

PlateToTypeTable:   // 21 bytes
    .byte   TYPE_FIRE
    .byte   TYPE_WATER
    .byte   TYPE_ELECTRIC
    .byte   TYPE_GRASS
    .byte   TYPE_ICE
    .byte   TYPE_FIGHTING
    .byte   TYPE_POISON
    .byte   TYPE_GROUND
    .byte   TYPE_FLYING
    .byte   TYPE_PSYCHIC
    .byte   TYPE_BUG
    .byte   TYPE_ROCK
    .byte   TYPE_GHOST
    .byte   TYPE_DRAGON
    .byte   TYPE_DARK
    .byte   TYPE_STEEL
    .byte   0               // some evo items here
    .byte   0
    .byte   0
    .byte   0
    .byte   0
    .byte   TYPE_FAIRY

.close


/*
 * Other references to plate-type checks:
 *  - FUN_overlay_14__02222e84
 *  - FUN_overlay_14__0222327c
 *  - FUN_overlay_16__0225b734
 *  - FUN_overlay_16__0225b910
 *  - FUN_overlay_16__0225be3c
 *
 * These functions all use a switch-jump table that we can cleanly
 * replace with the function defined above.
 */

.open "base/overlay/overlay_0014.bin", 0x0221FC20   // battle AI overlay

.org 0x02222F72 // hook from FUN_overlay_14__02222e84

Hook_AI_DamageCalc:
    bl      Pokemon_ArceusType
    mov     r7, r0          // base routine sets the type value in r7
    b       0x022231B4      // continue with the routine


.org 0x022232C0 // hook from FUN_overlay_14__0222327c

Hook_AI_MoveType:
    bl      Pokemon_ArceusType
    mov     r5, r0          // base routine sets the type value in r5
    b       0x022233E4      // continue with the routine


.close


.open "base/overlay/overlay_0016.bin", 0x0223B140   // battle code overlay

.org 0x0225B786 // hook from FUN_overlay_16__0225b734

Hook_Server_BattlePokemonType:
    bl      Pokemon_ArceusType
    mov     r4, r0          // base routine sets the type value in r4
    b       0x0225B7FA      // continue with the routine


.org 0x0225B954 // hook from FUN_overlay_16__0225b910

Hook_Server_AIMoveType:
    bl      Pokemon_ArceusType
    mov     r5, r0          // base routine sets the type value in r5
    b       0x0225BA78      // continue with the routine


.org 0x0225BEA2 // hook from FUN_overlay_16__0225be3c

Hook_Server_AIMoveType2:    // not sure why these are separate but ok
    bl      Pokemon_ArceusType
    mov     r5, r0          // base routine sets the type value in r5
    b       0x0225BFEE      // continue with the routine

.close


/*
 * Credit to Mikelan98 and BagBoy for these graphical tidbits.
 *
 * https://pokehacking.com/r/20071800
 */

.open "base/overlay/overlay_0011.bin", 0x0221F800

/*
 * This updates the palette used by the move-selection view on the bottom
 * screen during a battle.
 */
.orga 0x290 // palette for move selection
.halfword 0x7EDF, 0xF23F, 0x6A1E, 0x59DD, 0xCD5B, 0xC117, 0xB4D6, 0xFB3F

.close


.open "base/overlay/overlay_0021.bin", 0x021D0D80

/*
 * This updates the rendering for the Fairy type in the Pokedex (which
 * would otherwise default to Ghost).
 */
.orga 0x021DF180 // Pokedex type icon function

Pokedex_TypeOffset:
    cmp     r0, #0x11
    bhi     @@normal_override
    ldr     r1, =TypeOffsetTable
    ldrb    r0, [r1, r0]
    bx      lr

@@normal_override:
    mov     r0, 0x0
    bx      lr

.align 2
.pool

TypeOffsetTable:
    .byte   0x00    // NORMAL
    .byte   0x06    // FIGHTING
    .byte   0x0E    // FLYING
    .byte   0x0A    // POISON
    .byte   0x08    // GROUND
    .byte   0x05    // ROCK
    .byte   0x0B    // BUG
    .byte   0x07    // GHOST
    .byte   0x09    // STEEL
    .byte   0x12    // FAIRY
    .byte   0x01    // FIRE
    .byte   0x03    // WATER
    .byte   0x02    // GRASS
    .byte   0x04    // ELECTRIC
    .byte   0x0F    // PSYCHIC
    .byte   0x0D    // ICE
    .byte   0x10    // DRAGON
    .byte   0x0C    // DARK
    .byte   0x00    // padding
    .byte   0x00    // padding

.close
