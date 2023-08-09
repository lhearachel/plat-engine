.text
.align 2
.thumb

gFieldHookReturnAddress:
    .word 0

.global Hook_Encounter_Set
Hook_Encounter_Set:
    ldr     r5, =gFieldHookReturnAddress
    mov     r6, lr
    str     r6, [r5]
    pop     {r5-r6}
    bl      Encounter_Set
    ldr     r1, =gFieldHookReturnAddress
    ldr     r1, [r1]
    mov     pc, r1