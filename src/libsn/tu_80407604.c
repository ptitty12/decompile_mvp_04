/*
 * SN ProDG libsn (cflags_libsn: -O2 -G0 -fno-common),
 * .text 0x80407604-0x80407C64 (code-only unit, 12 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 *
 * SN debugger disc-interface emulation: the breakpoint-register helpers (fn_80407604, fn_80407624),
 * the exception entry (fn_804077B4, fn_8040787C) and the DI request decoder (fn_80407890) need
 * instructions only the original code has, and stay linked from the original object.
 */

typedef unsigned int u32;
typedef unsigned char u8;

/* DI (disc interface) registers */
#define DI_CMD0 (*(volatile u32 *)0xCC006008)
#define DI_CMD1 (*(volatile u32 *)0xCC00600C)
#define DI_CMD2 (*(volatile u32 *)0xCC006010)
#define DI_ADDR (*(volatile u32 *)0xCC006014)
#define DI_LEN (*(volatile u32 *)0xCC006018)
#define DI_CTRL (*(volatile u32 *)0xCC00601C)

extern void fn_80407604(void);
extern void fn_80407624(void);
extern int fn_80432014(int, void *);
extern void fn_804077B4(void);

extern int lbl_8062F200;
extern u32 lbl_8062F204;
extern int lbl_806C3220[8];
extern int lbl_806C3240[8];
extern int lbl_806C3260;
extern int lbl_806C3264;
extern int lbl_806C3268;
extern int lbl_806C326C;
extern u8 lbl_806C3270;
extern u8 lbl_806C3271;
extern int lbl_806C3274;

void fn_80407648(void *buf)
{
    fn_80407604();
    DI_CMD0 = 0x12000000;
    DI_CMD1 = 0;
    DI_CMD2 = 0x20;
    DI_LEN = 0x20;
    DI_ADDR = (u32)buf;
    DI_CTRL = 3;
    fn_80407624();
}

void fn_804076D0(void)
{
    fn_80407604();
    DI_CMD0 = 0;
    DI_CTRL = 1;
    fn_80407624();
}

void fn_80407714(int n)
{
    n = (n + 0x1F) & ~0x1F;
    if (n == lbl_806C3268) {
        lbl_806C3260 = 0;
        lbl_806C3264 += n;
        fn_80407648(lbl_806C3240);
    } else {
        lbl_806C3264 = -1;
        lbl_806C3260 = 0x31100;
        fn_804076D0();
    }
}

int fn_80407794(u32 x)
{
    if (x >= lbl_8062F204)
        return 0x52100;
    return 0;
}

void fn_80407B10(int x)
{
    if (x == -0x8000)
        lbl_8062F200 = x;
}

void fn_80407B24(void)
{
    if (lbl_8062F200 == -0x8000) {
        lbl_806C3220[0] = 0;
        lbl_806C3260 = 0;
        lbl_806C3264 = -1;
        lbl_806C326C = 0;
        lbl_806C3271 = 1;
        lbl_806C3270 = 1;
        fn_80407624();
        lbl_806C3274 = fn_80432014(2, fn_804077B4);
    }
}

int fn_80407BA8(int cmd)
{
    u32 hi = 0;

    if (lbl_8062F200 != -0x8000)
        return 0;
    switch (cmd) {
    case 0:
        lbl_806C3271 = 0;
        break;
    case 1:
        lbl_806C3271 = 1;
        break;
    case 2:
        lbl_806C3270 = 0;
        fn_80407604();
        hi = 0x80000000;
        break;
    case 3:
        lbl_806C3270 = 1;
        fn_80407624();
        hi = 0x80000000;
        break;
    }
    return hi | (lbl_806C3270 << 8) | lbl_806C3271;
}
