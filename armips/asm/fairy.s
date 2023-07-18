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
 * Credits to BluRose for this setup.
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


