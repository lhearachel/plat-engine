.nds
.thumb

// Built off of Mikelan98 and Nomura's ARM9 Expansion Subroutine
// 
// https://pokehacking.com/tutorials/ramexpansion/
//
// This doesn't use a synthetic overlay built off of an unused
// NARC, but rather instead builds new overlay binaries, because
// we are engineers, goddammit.
//
// Key values:
//   - Initialization subroutine offset: 0x02100E20
//   - Branch offset: 0x02000CB4

.open "base/arm9.bin", 0x02000000

.org 0x02000CB4 // branch from Main(), run once
    bl LoadArm9Expansion

.org 0x02100E20

LoadArm9Expansion:
    push {r2, lr}
    mov r0, #5
    bl RomSelfCheck     // self-check 1
    mov r0, #13
    bl RomSelfCheck     // self-check 2

    mov r0, #122
    mov r1, #2
    bl LoadOverlay122   // no-init load routine

    mov r0, #0
    mov r0, #0
    mov r1, #3
    pop {r2, pc}

.pool

.org 0x02100DB0

LoadOverlay122:
    push {r3-r7,lr}
    mov r4, r1
    mov r1, #0
    mvn r1, r1
    ldr r2, =0x02007000|1 // HandleLoadOverlay+8, need normal loading for the first one
    bx r2

.pool

.org 0x02100D48

RomSelfCheck:
    push {r3, lr}
    mov r2, r0
    ldr r0, =0x023C8000 // destination offset
    ldr r1, =#80 // (opening demo narc)
    bl 0x02006E3C // load_from_narc(&(0x023C8000), 80, 5) first run, load_from_narc(&(0x023C8000, 80, 13)) second run
    ldr r0, =0xFFFF
    ldr r1, =0x023C8000
    ldr r2, =0xC2A
    swi 0x0E // crc-16
    ldr r1, =0xD65B
    cmp r0, r1
    bne RomInvalid
    mov r0, #0
    mov r1, #3
    pop {r3, pc}

RomInvalid:
    swi 0x00

.pool

.close