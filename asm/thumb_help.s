.global sprintf
sprintf:
    push    {lr}
    blx     0x020D7510
    pop     {pc}

.global debugsyscall
debugsyscall:
    swi     0xFC
    bx      lr

.global memset
memset:
    push    {lr}
    blx     0x020D5124
    pop     {pc}

.global strcpy
strcpy:
    push    {lr}
    blx     0x020D8B7C
    pop     {pc}

    .force_thumb
    .syntax unified
    .global __gnu_thumb1_case_uqi
    .thumb_func
    .type __gnu_thumb1_case_uqi,function
__gnu_thumb1_case_uqi:
	push    {r1}
	mov	    r1, lr
	lsrs	r1, r1, #1
	lsls	r1, r1, #1
	ldrb	r1, [r1, r0]
	lsls	r1, r1, #1
	add	    lr, lr, r1
	pop	    {r1}
	bx	    lr
    .size __gnu_thumb1_case_uqi, . - __gnu_thumb1_case_uqi

    .force_thumb
    .syntax unified
    .global __aeabi_idiv
    .thumb_func
    .type __aeabi_idiv,function
__aeabi_idiv:
    .force_thumb
    .syntax unified
    .global __aeabi_idivmod
    .thumb_func
    .type __aeabi_idivmod,function
__aeabi_idivmod:
    push    {lr}
    blx     0x020E1F6C
    pop     {pc}
    .size __aeabi_idiv, . - __aeabi_idiv
    .size __aeabi_idivmod, . - __aeabi_idivmod

    .force_thumb
    .syntax unified
    .global __aeabi_uidiv
    .thumb_func
    .type __aeabi_uidiv,function
__aeabi_uidiv:
    push    {lr}
    blx     0x020E2178
    pop     {pc}
    .size __aeabi_uidiv, . - __aeabi_uidiv