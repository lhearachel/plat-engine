.text
.align 2
.thumb

.global Pokemon_LoadSprite              @ hooked out of FUN_02075FB4 @ 0x02075FBC
Pokemon_LoadSprite:
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


.global Pokemon_LoadIconPalette         @ hooked into FUN_02079EDC @ 0x02079EDC
Pokemon_LoadIconPalette:
    push    {r3}
    bl      Pokemon_IconPaletteID
    pop     {r3}
    ldr     r1, =0x02079F70 | 1
    bx      r1


.align 2
.global gFormWord;
gFormWord:
    .word   0


.global Encounter_SeparateFormAndSpecies  @ hooked into FUN_02241CC0 (ov6) @ 0x02241CC4
Encounter_SeparateFormAndSpecies:
    @ separate out the form number (top 5 bits)
    @ r4 is treated as free since the parent func is only ever called as the
    @ final step
    mov     r4, #0xF8
    lsl     r4, #8
    and     r4, r0
    lsr     r4, #11
    ldr     r5, =gFormPointer
    strb    r4, [r5]            @ r5 := &form

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


.global Encounter_SetForm               @ hooked into FUN_02241CC0 (ov6) @ 0x02241D9C
Encounter_SetForm:
    @ r4 should be the Pokemon struct
    bl      Call_Pokemon_Set            @ set the ID number
    mov     r0, r4                      @ r0 := Pokemon struct
    mov     r1, #112                    @ r1 := MON_PARAM_FORM_NUMBER
    ldr     r2, =gFormPointer           @ r2 := &form
    bl      Call_Pokemon_Set

    mov     r0, r4                      @ r0 := Pokemon struct
    bl      Pokemon_UpdatePassiveForm   @ enforce the form for a passive

    @ now that the form is set, we can put everything else together
    mov     r0, r4
    ldr     r3, =0x0207418C | 1         @ Pokemon_RecalcStats
    bl      Call_ViaR3

    mov     r0, r4
    ldr     r3, =0x0207803C | 1         @ Pokemon_RecalcAbility
    bl      Call_ViaR3

    mov     r0, r4                      @ BoxPokemon is conveniently at offset 0 of the Pokemon struct
    ldr     r3, =0x02077020 | 1         @ Pokemon_InitMoveset
    bl      Call_ViaR3

    @ now setup the callback
    ldr     r0, [sp, #0x10]
    ldr     r3, [sp, #0x2C]
    mov     r1, r5
    ldr     r7, =0x02241DA6 | 1
    bx      r7


Call_Pokemon_Set:
    ldr     r3, =0x02074B30 | 1
Call_ViaR3:
    bx      r3

.pool

.global gFormPointer
gFormPointer:
    .word   0


.global Hook_Encounter_AddToWildParty
Hook_Encounter_AddToWildParty:
    ldr     r5, =Encounter_AddToWildParty_Return
    mov     r6, lr
    str     r6, [r5]
    pop     {r5-r6}
    bl      Encounter_AddToWildParty
    ldr     r1, =Encounter_AddToWildParty_Return
    ldr     r1, [r1]
    mov     pc, r1

.pool

Encounter_AddToWildParty_Return:
    .word   0


.global Hook_Client_SetEncounter    @ Hook at 0x0225CC88
Hook_Client_SetEncounter:
    push    {r0-r7}
    ldr     r1, =gFormWord
    ldr     r1, [r1]                @ form
    ldrh    r0, [r5, #2]            @ species
    bl      Pokemon_FormTarget      @ (species, form)
    strh    r0, [r5, #2]            @ store species target back
    pop     {r0-r7}

    ldr     r0, [r5, #4]            @ pid
    str     r0, [sp]
    ldrb    r3, [r5, #1]            @ gender + shiny flag + form
    ldrh    r0, [r5, #2]            @ species

    ldr     r2, =0x0225CC90 | 1     @ re-entry
    bx      r2


.global Hook_Client_ShowEncounter   @ Hook at 0x0225CE82
Hook_Client_ShowEncounter:
    @ This one is used, e.g., whenever a mon escapes from a
    @ capture attempt.
    push    {r0-r7}
    ldr     r1, =gFormWord
    ldr     r1, [r1]                @ form
    ldrh    r0, [r5, #2]            @ species
    bl      Pokemon_FormTarget      @ (species, form)
    strh    r0, [r5, #2]            @ store species target back
    pop     {r0-r7}

    ldr     r0, [r5, #4]            @ pid
    str     r0, [sp]
    ldrb    r3, [r5, #1]
    add     r2, #0x84

    ldr     r0, =0x0225CE8A | 1     @ re-entry
    bx      r0
