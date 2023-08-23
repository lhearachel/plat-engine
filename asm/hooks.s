.text
.align 2
.thumb

.global Hook_Pokemon_CheckEvolution
Hook_Pokemon_CheckEvolution:
    ldr     r5, =gEvoHookReturnAddress
    mov     r6, lr
    str     r6, [r5]
    pop     {r5-r6}
    bl      Pokemon_CheckEvolution
    ldr     r1, =gEvoHookReturnAddress
    ldr     r1, [r1]
    mov     pc, r1

.pool

gEvoHookReturnAddress:
    .word 0
