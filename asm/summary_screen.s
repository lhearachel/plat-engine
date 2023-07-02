.text
.align 2
.thumb

.thumb_func
.global Summary_Entry_Hook
Summary_Entry_Hook:
    bl      Summary_ColorizeStatScreen
    ldr     r1, =0x02090AE8 + 1
    bx      r1

.thumb_func
.global Summary_IVEV
Summary_IVEV:
    mov     r1, #0x20
    ldr     r5, [r2, #0x4C]
    mov     r6, r5
    tst     r6, r1
    beq     Summary_Check_LButton
    sub     r1, #0x21
    bl      Summary_ChangePage
    mov     r0, #2
    pop     {r4-r6,pc}

Summary_Check_LButton:
    mov     r1, #2
    lsl     r1, r1, #8
    tst     r6, r1
    beq     Summary_Check_RButton
    sub     r1, r3, #3
    ldrsb   r1, [r4, r1]
    cmp     r1, #2
    bne     Summary_Check_RButton
    mov     r1, #1
    bl      Summary_ChangeStatScreenState
    mov     r0, #2
    pop     {r4-r6,pc}

Summary_Check_RButton:
    mov     r1, #1
    lsl     r1, r1, #8
    tst     r6, r1
    beq     Summary_Check_SELButton
    sub     r1, r3, #3
    ldrsb   r1, [r4, r1]
    cmp     r1, #2
    bne     Summary_Check_SELButton
    mov     r1, #2
    bl      Summary_ChangeStatScreenState
    mov     r0, #2
    pop     {r4-r6,pc}

Summary_Check_SELButton:
    mov     r1, #4
    tst     r6, r1
    beq     Summary_StatsPage_Return
    sub     r1, r3, #3
    ldrsb   r1, [r4, r1]
    cmp     r1, #2
    bne     Summary_StatsPage_Return
    mov     r1, #0
    bl      Summary_ChangeStatScreenState
    mov     r0, #2
    pop     {r4-r6,pc}

Summary_StatsPage_Return:
    ldr     r1, =0x0208CA34 + 1
    bx      r1

Summary_ChangePage:
    ldr     r2, =0x0208D898 + 1
    bx      r2
