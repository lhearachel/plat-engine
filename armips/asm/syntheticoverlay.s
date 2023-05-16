.nds
.thumb

// Built off of Mikelan98 and Nomura's ARM9 Expansion Subroutine
// 
// https://pokehacking.com/tutorials/ramexpansion/
//
// This doesn't use a synthetic overlay built off of an unused
// NARC, but rather instead builds new overlay binaries, because
// we are engineers, goddammit.

.open "base/arm9.bin", 0x02000000

.org 0x02000CB4 // branch from Main(), run once
    bl LoadArm9Expansion

.org 0x0207804C

.area 0x020780C4-.

// Loads Overlay 122 as an extension of ARM9
LoadArm9Expansion:
    push {r2, lr}
    mov r0, #122
    mov r1, #2
    bl LoadOverlay122
    mov r0, #0
    mov r1, #3
    pop {r2, pc}

LoadOverlay122:
    push {r3-r7,lr}
    mov r4, r1
    mov r1, #0
    mvn r1, r1
    ldr r2, =0x02006598|1 // HandleLoadOverlay+8, need normal loading for the first one
    bx r2

.pool

.endarea

.close