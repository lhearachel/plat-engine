.text
.align 2
.thumb

.global Pokemon_LoadSprite              @ hooked out of FUN_02075FB4 @ 0x02075FBC
.thumb_func
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
    ldr     r0, =0x02075FC8 | 1
    bx      r0

NewSpriteLoaded:
    pop     {r0-r3}
    pop     {r3-r7, pc}

.pool

.global BoxPokemon_Get_Gender       @ Hook at 0x0207493A
.thumb_func
BoxPokemon_Get_Gender:
    @ r5 is substruct A
    @ r6 is substruct B
    @ r7 is substruct C
    @ r1 is substruct D (?)
    @ sp + 0 is the boxMon pointer
    ldrh    r0, [r5, #0x00]         @ substruct A, offset 0x00 -> species
    ldrb    r1, [r6, #0x18]         @ substruct B, offset 0x18 -> mask (top 5 bits are form number)
    lsr     r1, #3                  @ r6 is now just the form number
    ldr     r2, [sp, #0x00]         @ &boxMon
    ldr     r2, [r2, #0x00]         @ boxMon->pid
    bl      PokemonForm_CalcGender  @ get the gender of this species + form + pid triplet
    ldr     r1, =0x02074944 | 1     @ call back into BoxPokemon_Get
    bx      r1

.pool
