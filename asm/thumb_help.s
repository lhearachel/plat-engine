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