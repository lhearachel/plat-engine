@ .global Hook_Client_SetEncounter    @ Hook at 0x0225CC88
@ .thumb_func
@ Hook_Client_SetEncounter:
@     push    {r0-r7}
@     ldr     r1, =gFormWord
@     ldr     r1, [r1]                @ form
@     ldrh    r0, [r5, #2]            @ species
@     bl      Pokemon_FormTarget      @ (species, form)
@     strh    r0, [r5, #2]            @ store species target back
@     pop     {r0-r7}

@     ldr     r0, [r5, #4]            @ pid
@     str     r0, [sp]
@     ldrb    r3, [r5, #1]            @ gender + shiny flag + form
@     ldrh    r0, [r5, #2]            @ species

@     ldr     r2, =0x0225CC90 | 1     @ re-entry
@     bx      r2


@ .global Hook_Client_ShowEncounter   @ Hook at 0x0225CE82
@ .thumb_func
@ Hook_Client_ShowEncounter:
@     @ This one is used, e.g., whenever a mon escapes from a
@     @ capture attempt.
@     push    {r0-r7}
@     ldr     r1, =gFormWord
@     ldr     r1, [r1]                @ form
@     ldrh    r0, [r5, #2]            @ species
@     bl      Pokemon_FormTarget      @ (species, form)
@     strh    r0, [r5, #2]            @ store species target back
@     pop     {r0-r7}

@     ldr     r0, [r5, #4]            @ pid
@     str     r0, [sp]
@     ldrb    r3, [r5, #1]
@     add     r2, #0x84

@     ldr     r0, =0x0225CE8A | 1     @ re-entry
@     bx      r0
