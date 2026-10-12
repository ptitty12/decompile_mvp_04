/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8043E344-0x8043EDC4 (code-only unit, 14 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/hw_regs.h>

extern void (*lbl_806EF958)(s32 chan);        /* callback given to the init routine */
extern void (*lbl_806EF95C)(s16 interrupt);   /* handler callback */
extern u32 lbl_806EF960;                      /* status word of the last mailbox read */
extern s32 lbl_806EF964;                      /* bytes waiting */
extern u32 lbl_806EF968;                      /* address of the input-pending flag */
extern u8 lbl_806EF96C;                       /* input pending */
extern u8 lbl_806EF358;                       /* buffer toggle */

extern void fn_80435350(u32 mask);            /* __OSMaskInterrupts */

#define EXI2_CSR (__EXIRegs[10])
#define EXI2_CR (__EXIRegs[13])

void fn_8043E344(void);
void fn_8043E348(void);
int fn_8043E34C(void* bytes, u32 length);
int fn_8043E5AC(void* bytes, u32 length);
int fn_8043E638(void);
void fn_8043E6D4(void);
void fn_8043E728(volatile u8** inputPendingPtrRef, void (*monitorCallback)(s32));
void fn_8043E7A0(s16 interrupt, OSContext* context);
void fn_8043E7E0(s16 interrupt, OSContext* context);
int fn_8043E81C(u32* out);
int fn_8043E8C8(u32 addr, u32* src, s32 len);
int fn_8043E9A4(u32 addr, u32* dst, s32 len);
int fn_8043EA80(u32* out);
int fn_8043EB2C(void* buf, s32 len, u32 type);

void fn_8043E344(void)
{
}

void fn_8043E348(void)
{
}

/* EXI2_Poll */
int fn_8043E638(void)
{
    u32 status;
    BOOL enabled;

    lbl_806EF96C = 0;
    if (lbl_806EF964 == 0) {
        enabled = OSDisableInterrupts();
        fn_8043E81C(&status);
        if (status & 1) {
            fn_8043EA80(&status);
            status &= 0x1FFFFFFF;
            if ((status & 0x1F000000) == 0x1F000000) {
                lbl_806EF960 = status;
                lbl_806EF964 = status & 0x7FFF;
                lbl_806EF96C = 1;
            }
        }
        OSRestoreInterrupts(enabled);
    }
    return lbl_806EF964;
}

/* EXI2_EnableInterrupts */
void fn_8043E6D4(void)
{
    fn_80435350(0x18000);
    fn_80435350(0x40);
    lbl_806EF95C = (void (*)(s16))fn_8043E7E0;
    __OSSetInterruptHandler(0x19, fn_8043E7A0);
    __OSUnmaskInterrupts(0x40);
}

/* EXI2_Init */
void fn_8043E728(volatile u8** inputPendingPtrRef, void (*monitorCallback)(s32))
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    lbl_806EF968 = (u32)&lbl_806EF96C;
    *inputPendingPtrRef = (volatile u8*)lbl_806EF968;
    lbl_806EF958 = monitorCallback;
    fn_80435350(0x18000);
    EXI2_CSR = 0;
    OSRestoreInterrupts(enabled);
}

void fn_8043E7E0(s16 interrupt, OSContext* context)
{
    lbl_806EF96C = 1;
    if (lbl_806EF958) {
        lbl_806EF958(0);
    }
}

/* single-register EXI2 transfer (EXIImm-style) */
int fn_8043EB2C(void* buf, s32 len, u32 type)
{
    u32 data;
    u8* p;
    int i;

    if (type != 0) {
        data = 0;
        for (i = 0; i < len; i++) {
            data |= ((u8*)buf)[i] << ((3 - i) * 8);
        }
        __EXIRegs[14] = data;
    }
    __EXIRegs[13] = (type << 2) | 1 | ((len - 1) << 4);
    while (__EXIRegs[13] & 1)
        ;
    if (type == 0) {
        data = __EXIRegs[14];
        p = (u8*)buf;
        for (i = 0; i < len; i++) {
            *p++ = data >> ((3 - i) * 8);
        }
    }
    return 1;
}
