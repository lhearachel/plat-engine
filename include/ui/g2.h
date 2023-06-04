#ifndef __UI_G2_H
#define __UI_G2_H

#define GX_BLEND_PLANEMASK_NONE     0x0000
#define GX_BLEND_PLANEMASK_BG0      0x0001
#define GX_BLEND_PLANEMASK_BG1      0x0002
#define GX_BLEND_PLANEMASK_BG2      0x0004
#define GX_BLEND_PLANEMASK_BG3      0x0008
#define GX_BLEND_PLANEMASK_OBJ      0x0010
#define GX_BLEND_PLANEMASK_BD       0x0020

void __attribute__((long_call)) G2_BlendNone(void);
void __attribute__((long_call)) G2_ChangeBlendAlpha(int ev1, int ev2);
void __attribute__((long_call)) G2_SetBlendAlpha(int plane1, int plane2, int ev1, int ev2);

#endif // __UI_G2_H