.text
.align 2
.thumb

.global Pokemon_LoadSprite
Pokemon_LoadSprite: // hooked out of fun_02075FB4 @ 2075FBC
    ldr     r6, [sp, #0x18]
    ldr     r1, [sp, #0x1C]
    mov     r0, #0x0
    strh    r0, [r5, #0x06]
    strb    r0, [r5, #0x08]
    str     r0, [r5, #0x0C]
    push    {r0-r3}
    sub     sp, #0x4
    str     r1, [sp, #0x00]
    mov     r0, r5
    mov     r1, r4
    mov     r2, r3
    mov     r3, r6
    bl      Form_LoadSprite
    add     sp, #0x04
    cmp     r0, #0x00
    bne     NewSpriteLoaded
    pop     {r0-r3}
    ldr     r0, =0x02075FC8 + 1
    bx      r0

NewSpriteLoaded:
    pop     {r0-r3}
    pop     {r3-r7, pc}


.align 2
.global gFormWord;
gFormWord:
    .word   0


.global Encounter_SeparateFormFromSpecies  @ hooked into FUN_02241CC0 (ov6) @ 0x02241CC4
Encounter_SeparateFormFromSpecies:
    @ separate out the form number (top 5 bits)
    mov     r4, #0xF8
    lsl     r4, #8
    and     r4, r0
    lsr     r4, #11
    ldr     r5, =gPokeDataPointer
    strb    r4, [r5]            @ r5 => form number

    @ separate out the species (bottom 11 bits)
    mov     r4, #0x07
    lsl     r4, #8
    add     r4, #0xFF
    and     r0, r4              @ r0 := species

    @ call back into the hooked func
    push    {r4-r7, lr}
    mov     r7, r0
    mov     r0, #0x0B           @ heap ID
    str     r1, [sp, #0x0C]     @ original species input
    str     r2, [sp, #0x10]     @ original direction input
    ldr     r4, =0x02241CCC | 1
    bx      r4

