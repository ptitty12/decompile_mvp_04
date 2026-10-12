/*
 * SDK debugger support code (MWCC GC/2.0-style prologue; library and flags
 * unconfirmed, probably DebuggerDriver),
 * .text 0x8043F058-0x8043FDB8 (code-only unit, 33 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * What the code does (from its use of SR7, SDR1 and the 0x7E000000 window): a software page-table manager.
 * lbl_806EF970 is a 64 KB hashed page table (0x2000 PTEs of 8 bytes), lbl_806EF974 a 0x1000-word table of
 * per-page values, lbl_806EF978 a 0x1000-byte table of per-page flags, lbl_806EF97C a fault callback.
 *
 * Original-code functions in this range are not reproduced (they need tlbie, tlbsync, mfsr/mtsr, mfsdr1,
 * mtsrr0/1, rfi, sync/isync/icbi or the SPRG/GQR registers): fn_8043F34C, fn_8043F808, fn_8043F860, fn_8043F8B4,
 * fn_8043F8CC, fn_8043F8FC, fn_8043FA78 and fn_8043FC20.
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/tail10.h>

extern u32 lbl_806EF970;
extern u32 lbl_806EF974;
extern u32 lbl_806EF978;
extern void (*lbl_806EF97C)(u32);
extern s32 lbl_806EF980;

extern void fn_80433004(void* addr, u32 len);
extern void fn_80433060(void* addr, u32 len);
extern void fn_8043F34C(u32 va);
extern void fn_8043F808(void);
extern void fn_8043F860(void);
extern void fn_8043F8FC(void);

void fn_8043F058(void (*cb)(u32));
void fn_8043F124(u32 va, u32 pa, u32 idx);
void fn_8043F1B8(u32 va, u32 idx);
u32 fn_8043F244(u32 va);
u32 fn_8043F26C(u32 va);
u32 fn_8043F294(u32 va);
void fn_8043F2BC(u32 va, s32 flag);
u32 fn_8043F35C(u32 va);
u32 fn_8043F388(u32 idx);
void fn_8043F398(u32 idx, u32 val);
u32 fn_8043F3A8(u32 idx);
void fn_8043F3B4(u32 idx, s32 val);
void fn_8043F3DC(void (*cb)(u32));
void fn_8043F3E4(void);
void fn_8043F420(void);
void fn_8043F450(void);
void fn_8043F480(void);
void fn_8043F5D8(void);
void fn_8043F6B0(void);
void fn_8043F728(void (*cb)(u32));
u32* fn_8043F7D4(u32 va);
u32 fn_8043F7EC(u32* pte);
void fn_8043F8F8(void);
void fn_8043FBBC(OSContext* ctx, u32 dar);
void fn_8043FD60(OSContext* ctx);

void fn_8043F058(void (*cb)(u32))
{
    if (lbl_806EF980 == 0) {
        BOOL en = OSDisableInterrupts();
        lbl_806EF980 = 1;
        fn_8043F3DC(cb);
        {
            u32 gap = 0x10000 - ((u32)fn_80432CBC() & 0xFFFF);
            if (gap >= 0x5000) {
                fn_8043F420();
                fn_8043F450();
                fn_8043F3E4();
            } else if (gap >= 0x4000) {
                fn_8043F450();
                fn_8043F3E4();
                fn_8043F420();
            } else if (gap >= 0x1000) {
                fn_8043F420();
                fn_8043F3E4();
                fn_8043F450();
            } else {
                fn_8043F3E4();
                fn_8043F420();
                fn_8043F450();
            }
        }
        fn_8043F8FC();
        fn_8043F860();
        fn_8043F808();
        OSRestoreInterrupts(en);
    }
}

void fn_8043F124(u32 va, u32 pa, u32 idx)
{
    u32* pte = fn_8043F7D4(va);
    BOOL en = OSDisableInterrupts();
    pte[0] = 0x80000000 | ((va >> 22) & 0x3F);
    pte[1] = pa & 0x0FFFF000;
    fn_80433004(pte, 8);
    fn_8043F34C(va);
    fn_8043F398(idx, va);
    OSRestoreInterrupts(en);
}

void fn_8043F1B8(u32 va, u32 idx)
{
    BOOL en = OSDisableInterrupts();
    u32* pte = fn_8043F7D4(va);
    pte[0] = 0;
    pte[1] = 0;
    fn_80433004(pte, 8);
    fn_8043F34C(va);
    fn_8043F398(idx, 0);
    fn_8043F3B4(idx, 0);
    OSRestoreInterrupts(en);
}

u32 fn_8043F244(u32 va)
{
    return fn_8043F7D4(va)[0] >> 31;
}

u32 fn_8043F26C(u32 va)
{
    return (fn_8043F7D4(va)[1] >> 8) & 1;
}

u32 fn_8043F294(u32 va)
{
    return (fn_8043F7D4(va)[1] >> 7) & 1;
}

void fn_8043F2BC(u32 va, s32 flag)
{
    BOOL en = OSDisableInterrupts();
    u32* pte = fn_8043F7D4(va);
    if (flag != 0) {
        pte[1] |= 0x100;
    } else {
        pte[1] &= ~0x100;
    }
    fn_80433004(&pte[1], 4);
    fn_8043F34C(va);
    OSRestoreInterrupts(en);
}

u32 fn_8043F35C(u32 va)
{
    return (fn_8043F7D4(va)[1] & 0x0FFFF000) + 0x80000000;
}

u32 fn_8043F388(u32 idx)
{
    return *(u32*)(lbl_806EF974 + idx * 4);
}

void fn_8043F398(u32 idx, u32 val)
{
    *(u32*)(lbl_806EF974 + idx * 4) = val;
}

u32 fn_8043F3A8(u32 idx)
{
    return *(u8*)(lbl_806EF978 + idx);
}

void fn_8043F3B4(u32 idx, s32 val)
{
    if (val != 0) {
        *(u8*)(lbl_806EF978 + idx) = 1;
    } else {
        *(u8*)(lbl_806EF978 + idx) = 0;
    }
}

void fn_8043F3DC(void (*cb)(u32))
{
    lbl_806EF97C = cb;
}

void fn_8043F3E4(void)
{
    u32 lo = (u32)fn_80432CBC();
    lbl_806EF970 = lo + 0x10000 - (lo & 0xFFFF);
    fn_80432CCC((void*)(lbl_806EF970 + 0x10000));
    fn_8043F480();
}

void fn_8043F420(void)
{
    lbl_806EF978 = (u32)fn_80432CBC();
    fn_80432CCC((void*)(lbl_806EF978 + 0x1000));
    fn_8043F5D8();
}

void fn_8043F450(void)
{
    lbl_806EF974 = (u32)fn_80432CBC();
    fn_80432CCC((void*)(lbl_806EF974 + 0x4000));
    fn_8043F6B0();
}

void fn_8043F480(void)
{
    u32 i;
    BOOL en = OSDisableInterrupts();
    for (i = 0; i < 0x10000; i += 8) {
        *(u32*)(lbl_806EF970 + i) = 0;
        *(u32*)(lbl_806EF970 + i + 4) = 0;
    }
    fn_80433004((void*)lbl_806EF970, 0x10000);
    fn_8043F808();
    OSRestoreInterrupts(en);
}

void fn_8043F5D8(void)
{
    u32 i;
    for (i = 0; i < 0x1000; i++) {
        *(u8*)(lbl_806EF978 + i) = 0;
    }
}

void fn_8043F6B0(void)
{
    u32 i;
    for (i = 0; i < 0x4000; i += 4) {
        *(u32*)(lbl_806EF974 + i) = 0;
    }
}

void fn_8043F728(void (*cb)(u32))
{
    u32 i;
    BOOL en = OSDisableInterrupts();
    for (i = 0; i < 0x2000; i++) {
        u32* pte = (u32*)(lbl_806EF970 + i * 8);
        if ((pte[0] & 0x80000000) && (pte[1] & 0x80)) {
            cb(fn_8043F7EC(pte));
            pte[1] &= ~0x80;
            fn_80433060(&pte[1], 4);
        }
    }
    fn_8041A5DC();
    fn_8043F808();
    OSRestoreInterrupts(en);
}

u32* fn_8043F7D4(u32 va)
{
    return (u32*)(((va >> 19) & 0x38) | (lbl_806EF970 | ((va >> 6) & 0xFFC0)));
}

u32 fn_8043F7EC(u32* pte)
{
    u32 off = (u32)pte - lbl_806EF970;
    return (((off & 0x38) << 19) | 0x7E000000) | ((off << 6) & 0x3FF000);
}

void fn_8043F8F8(void)
{
}

void fn_8043FBBC(OSContext* ctx, u32 dar)
{
    OSContext tmp;
    fn_80433814(&tmp);
    fn_8043364C(&tmp);
    lbl_806EF97C(dar);
    fn_8043364C(ctx);
    fn_80433734(ctx);
}

void fn_8043FD60(OSContext* ctx)
{
    OSContext tmp;
    fn_80433814(&tmp);
    fn_8043364C(&tmp);
    lbl_806EF97C(ctx->srr0);
    fn_8043364C(ctx);
    fn_80433734(ctx);
}
