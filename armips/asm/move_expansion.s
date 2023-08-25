.nds
.thumb

/*
 * The goal here is to repoint the move table outside of the AIWork struct
 * so that it can be expanded to support future moves. There are a number
 * of references to a certain value from the table in the original code
 * which need to be re-pointed to a later offset. This file contains all of
 * those references and re-points.
 */

MAX_MOVE_ID equ 852

.open "base/arm9.bin", 0x02000000

.org 0x0202F850 // battle recording stuff
    .word MAX_MOVE_ID

.org 0x0206F25C // TV stuff
    .word MAX_MOVE_ID

.org 0x020790B2 // table load from the archive
    mov     r1, #0x6B
    lsl     r1, r1, #7  // r1 := 0x3580 (856 * 16) ; use 856 because it's greater than 852 and makes for a clean shift

.close

.open "base/overlay/overlay_0012.bin", 0x0221FC20

.org 0x02220158 // animations for expanded moves
    .word MAX_MOVE_ID

.close

.open "base/overlay/overlay_0016.bin", 0x0223B140

.org 0x02260F10
    .word MAX_MOVE_ID

.org 0x02243F50
    .word MAX_MOVE_ID

.org 0x02266CD0
    .word 0x3180

// priority when calcing speed
// This is, thankfully, the only place that this value is accessed, because it is hella cursed
.org 0x0225341E
    bne     _Optimized3188

.org 0x02253436
    b       _Optimized3188

.org 0x02253444 // the original bytecode here has an effective 4-byte no-op that we can exploit
    str     r0, [sp, #0x5C]

_Optimized3188:
    // setup the table offset for a move's priority
    mov     r1, #0x31           // r1 := 0x31
    lsl     r1, r1, #8          // r1 := 0x3100
    add     r1, #0x88           // r1 := 0x3188

    // load the priority for the first move
    ldr     r0, [sp, #0x60]     // r0 := moveID
    lsl     r0, r0, #0x04       // r0 := moveID * 16 (each entry in the table is 16 bytes)
    add     r0, r5, r0          // r0 := server[(moveID * 16)]
    ldrsb   r0, [r0, r1]        // r0 := server[0x3188 + (moveID * 16)]    
    nop                         // padding; rest is the same from here


// secondary chance
.org 0x02253944 // originally 0x03E5
    .word 0x3185


// target
.org 0x02253C1C // originally 0x03E6
    .word 0x3186


// type
.org 0x02253E2C // originally 0x03E2
    .word 0x3182

// target
.org 0x02253E30 // originally 0x03E6
    .word 0x3186


// power
.org 0x02254CA4 // originally 0x03E1
    .word 0x3181


// type
.org 0x022552BC // 0x03E2
    .word 0x3182

// power
.org 0x022552C0 // 0x03E1
    .word 0x3181


// type
.org 0x022553F0 // 0x03E2
    .word 0x3182


// effect
.org 0x02255888 // 0x03DE
    .word 0x317E


// type
.org 0x022562CC // 0x03E2
    .word 0x3182

// power
.org 0x022562DC // 0x03E1
    .word 0x3181


// effect
.org 0x02256AB8 // 0x03DE
    .word 0x317E

// power
.org 0x02256AC0 // 0x03E1
    .word 0x3181


// type
.org 0x022573C0 // 0x03E2
    .word 0x3182

// power
.org 0x022573C4 // 0x03E1
    .word 0x3181

// flags
.org 0x022573B8 // 0x03E9
    .word 0x3189


// flags
.org 0x02258AA4 // 0x03E9
    .word 0x3189


// There are a bunch of elements in the original calc routine that I'm not bothering to replace
// because the calc has to be totally rewritten anyways

// might actually need to take care of this I guess? idk, need to look at how this stitches together
// with Calc_MoveDamage
//
// other references to the original routine:
//  - AI switch check (no chance to crit)
//  - badge check (for obedience self-hit, no chance to crit)
//  - confusion self-hit (no chance to crit)
//  - future sight damage storage (no chance to crit)
//  - AI damage calc (no chance to crit)
//
// can probably repoint these using ASM


// effect
.org 0x0225B0B8 // 0x03DE
    .word 0x317E


// effect
.org 0x0225B0F4 // 0x03DE
    .word 0x317E


// pss
.org 0x0225B2EA // 0x03E0
    mov     r0, #0x63
    lsl     r0, r0, #7  // r0 := 0x3180


// flags
.org 0x0225B404 // 0x03E9
    .word 0x3189


// effect
.org 0x0225B72C // 0x03DE
    .word 0x317E


// effect
.org 0x0225B908 // 0x03DE
    .word 0x317E


// power
.org 0x0225BE20 // 0x03E1
    .word 0x3181


// server.c

// table load and struct initialization
.org 0x0224B984 // size of the struct
    .word 0x317E + ((MAX_MOVE_ID + 1) * 16)
.org 0x0224B988 // 0x03DE (load location)
    .word 0x317E


// target
.org 0x0224E5E4 // 0x03E6
    .word 0x3186


// effect
.org 0x0224E6F0 // 0x03DE
    .word 0x317E


// target; also used for accessing power
.org 0x0224E778 // 0x03E6
    .word 0x3186


// effect
.org 0x0224EAB4 // 0x03DE
    .word 0x317E

// power
.org 0x0224EAD4 // 0x03E1
    .word 0x3181


// there should be a type check here, but it looks like it got optimized out somehow

// pss
.org 0x0224EF50 // 0x03E0
    mov     r0, #0x63
    lsl     r0, r0, #7  // r0 := 0x3180

// accuracy
.org 0x0224F254 // 0x03E3
    .word 0x3183

// effect
.org 0x0224F25C // 0x03DE
    .word 0x317E


// flags
.org 0x0224F450 // 0x03E9
    .word 0x3189

// effect
.org 0x0224F458 // 0x03DE
    .word 0x317E

// this one kinda sucks cause it builds 0x3E6 off of 0x400
// we can exploit that 0x400 is only used for a bitwise and to check for the lock-on
// flag, and 0x3200 implicitly contains 0x400 (both have bit 10 set to 1)
// then we can build 0x3186 from 0x3200 (subtract 0x7A)
.org 0x0224F3B8
    mov     r2, #0x32
    ldr     r0, [r5, r1]
    lsl     r2, r2, #8      // r2 := 0x3200
    tst     r0, r2
    bne     0x0224F446
    ldr     r0, =0x3044
    sub     r2, 0x7A        // r2 := 0x3186
    // rest is the same

.org 0x0224F45C
.pool


// flags
.org 0x0224F5BC // 0x03E9
    .word 0x3189


// effect
.org 0x0224FC34 // 0x03DE
    .word 0x317E

// pss
.org 0x0224FB68 // 0x03E0 (by shift)
    mov     r1, #0x63
    ldr     r0, [r4, r0]
    lsl     r1, r1, #7      // r1 := 0x3180


// type
.org 0x02250154 // 0x03E2
    .word 0x3182


// target
.org 0x02250420 // 0x03E6
    .word 0x3186


// target
.org 0x02250E80 // 0x03E6
    .word 0x3186


// type
.org 0x022511DC // 0x03E2
    .word 0x3182

// flags
.org 0x022511E0 // 0x03E9
    .word 0x3189

// target
.org 0x022511F4 // 0x03E6
    .word 0x3186


// flags
.org 0x022513A8 // 0x03E9
    .word 0x3189


// pss
.org 0x02251576 // 0x03E0 (by shift)
    mov     r0, #0x63
    lsl     r0, r0, #7


// effect
.org 0x02241C24 // 0x03DE
    .word 0x317E


// type
.org 0x02243700 // 0x03E2
    .word 0x3182


// accuracy
.org 0x02243D18 // 0x03E3
    .word 0x3183


// pp
// this function has an unnecessary reload of the move ID into r0
// which means we can overwrite an instruction
.org 0x02243E6E
    // these two are shifted up one instruction
    lsl     r0, r0, #4
    add     r4, r6, r0

    // this is the new load
    mov     r0, #0x31
    lsl     r0, r0, #8
    add     r0, #0x84       // r0 := 0x3184 (pp offset)


// pp
// this function loads a close value (0x30AC) earlier in the pool
// which means we can just reload that value and add to it
.org 0x02244568
    ldr     r1, =0x30AC
    add     r1, #0xD8       // r1 := 0x3184 (pp offset)

.org 0x022445C4 // this is the actual location of 0x3184

.pool


// effect
.org 0x02244B44 // 0x03DE
    .word 0x317E


// pp
// me when I must reimplement a loop in assembly :(
.org 0x02244EF6

Transform_SetupLoop:
    mov     r0, #0x63
    mov     r5, r6
    mov     r1, #5
    lsl     r0, r0, #7      // r0 := 0x3180
    add     r0, r0, #4      // r0 := 0x3184 ; need to make room for this extra instruction

Transform_CopyLoop:
    ldr     r3, [r4, #0x64]
    mov     r2, #0xC0
    mul     r2, r3
    add     r3, r4, r2
    ldr     r2, =0x2D4C
    add     r7, r3, r5
    ldrh    r2, [r7, r2]
    lsl     r2, r2, #4
    add     r2, r4, r2
    ldrb    r2, [r2, r0]    // r2 := pp of move (new table)
    add     r7, r3, r6      // moved up to cut an instruction from the loop
    cmp     r2, #0x05
    bcs     Transform_LessThan5PP
//  add     r7, r3, r6      ; original instruction moved up
    ldr     r3, =0x2D6C
    strb    r2, [r7, r3]
    b       Transform_ResetLoop

Transform_LessThan5PP:
    ldr     r2, =0x2D6C
//  add     r3, r3, r6      ; original instruction moved up
    strb    r1, [r7, r2]    // use r7 instead of r3 to make the move up possible

Transform_ResetLoop:
    add     r6, r6, #1
    add     r5, r5, #2
    cmp     r6, #4
    blt     Transform_CopyLoop


.org 0x02244F4C             // location of 0x2D4C

.pool


// power
.org 0x0224555C // 0x03E1
    .word 0x3181


// power
.org 0x022455F0 // 0x03E1
    .word 0x3181


// power
.org 0x02245FB8 // 0x03E1
    .word 0x3181


// target
.org 0x022463E4 // 0x03E6
    .word 0x3186


// power
.org 0x02246680 // 0x03E1
    .word 0x3181


// power
.org 0x022469B8 // 0x03E1
    .word 0x3181


// effect
.org 0x02246B54 // 0x03DE
    .word 0x317E


// power
.org 0x02246F28 // 0x03E1
    .word 0x3181


// power
.org 0x0224705C // 0x03E1
    .word 0x3181


// power
.org 0x02247190 // 0x03E1
    .word 0x3181


// secondaryChance
.org 0x02247E90 // 0x03E5
    .word 0x3185


// table entry
.org 0x02247F74 // 0x03DE
    .word 0x317E


// type
.org 0x02248A30 // 0x03E2
    .word 0x3182

.close

.open "base/overlay/overlay_0014.bin", 0x0221FC20

// the whole battle AI system needs to be totally rewritten anyways most likely
// so I'm just not bothering atm

// WazaAIMainDouble -> target
// original load here uses an earlier load of 0x03CF and adds 0x17 to get 0x03E6
// this exploits an unnecessary recomputation of r1 := r0 + 0x0B, which
// saves two instructions
/*
.org 0x02220000
    add     r3, r5, r2
    ldrb    r1, [r3, r1]
    add     r3, sp, #0x18
    mov     r0, #0x31
    lsl     r0, r0, #8
    add     r0, #0x86


// AI_IF_HAVE_DAMAGE_WAZA -> power
.org 0x022208FC // 0x03E1
    .word 0x3181


// AI_IFN_HAVE_DAMAGE_WAZA -> power
.org 0x02220960 // 0x03E1
    .word 0x3181


// AI_CHECK_TYPE -> type
// original loadhere uses an earlier load of 0x0356 and adds 0x8C to get 0x03E2
.org 0x02220A14
    ldr     r0, =0x0356
    ldrh    r1, [r4, r0]
    lsl     r1, r1, #4
    add     r2, r4, r1
    mov     r1, r0
    add     r1, #0x8C
    ldrb    r1, [r2, r1]
    add     r0, r0, #6
    str     r1, [r4, r0]
*/


.close
