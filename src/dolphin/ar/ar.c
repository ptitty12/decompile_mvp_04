/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8041583C-0x80417314 (code-only unit, 9 functions; original file name from the reference split).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 * Written from the public SDK ar.c (doldecomp/dolsdk2004 layout), small functions only; the SDK names are in
 * the comments, the symbols stay fn_<addr> (symbols.txt has no real names for this range).
 * Not written: fn_80415B20 (__ARChecksize, 0x17F4 bytes).
 */
#include <dolphin.h>
#include <dolphin/ar.h>
#include <dolphin/os.h>

#include <dolphin/hw_regs.h>

typedef void (*ARCallback)(void);

extern const char* lbl_806EF150;   /* __ARVersion */
extern ARCallback lbl_806EF4D8;   /* __AR_Callback */
extern u32 lbl_806EF4E8;           /* __AR_StackPointer */
extern u32 lbl_806EF4EC;           /* __AR_FreeBlocks */
extern u32* lbl_806EF4F0;          /* __AR_BlockLength */
extern volatile BOOL lbl_806EF4F4; /* __AR_init_flag */

void fn_80433814(OSContext* context);  /* OSClearContext */
void fn_8043364C(OSContext* context);  /* OSSetCurrentContext */
void fn_80415B20(void);                /* __ARChecksize */

ARCallback fn_8041583C(ARCallback callback);
u32 fn_80415880(void);
void fn_804158BC(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);
u32 fn_804159AC(u32* stack_index_addr, u32 num_entries);
u32 fn_80415A70(void);
void fn_80415A78(__OSInterrupt interrupt, OSContext* context);
void fn_80415AF0(void);
u16 fn_80415B10(void);

/* ARRegisterDMACallback */
ARCallback fn_8041583C(ARCallback callback)
{
    ARCallback old;
    BOOL enabled;

    old = lbl_806EF4D8;
    enabled = OSDisableInterrupts();
    lbl_806EF4D8 = callback;
    OSRestoreInterrupts(enabled);
    return old;
}

/* ARGetDMAStatus */
u32 fn_80415880(void)
{
    BOOL enabled;
    u32 val;

    enabled = OSDisableInterrupts();
    val = __DSPRegs[5] & 0x200;
    OSRestoreInterrupts(enabled);
    return val;
}

/* ARStartDMA */
void fn_804158BC(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    __DSPRegs[16] = (u16)((__DSPRegs[16] & ~0x3FF) | (mainmem_addr >> 16));
    __DSPRegs[17] = (u16)((__DSPRegs[17] & ~0xFFE0) | (mainmem_addr & 0xFFFF));
    __DSPRegs[18] = (u16)((__DSPRegs[18] & ~0x3FF) | (aram_addr >> 16));
    __DSPRegs[19] = (u16)((__DSPRegs[19] & ~0xFFE0) | (aram_addr & 0xFFFF));
    __DSPRegs[20] = (u16)((__DSPRegs[20] & ~0x8000) | (type << 15));
    __DSPRegs[20] = (u16)((__DSPRegs[20] & ~0x3FF) | (length >> 16));
    __DSPRegs[21] = (u16)((__DSPRegs[21] & ~0xFFE0) | (length & 0xFFFF));
    OSRestoreInterrupts(enabled);
}

/* ARInit */
u32 fn_804159AC(u32* stack_index_addr, u32 num_entries)
{
    BOOL old;
    u16 refresh;

    if (lbl_806EF4F4 == TRUE) {
        return 0x4000;
    }
    OSRegisterVersion(lbl_806EF150);
    old = OSDisableInterrupts();
    lbl_806EF4D8 = NULL;
    __OSSetInterruptHandler(6, fn_80415A78);
    __OSUnmaskInterrupts(0x02000000);
    lbl_806EF4E8 = 0x4000;
    lbl_806EF4EC = num_entries;
    lbl_806EF4F0 = stack_index_addr;
    refresh = (u16)(__DSPRegs[13] & 0xFF);
    __DSPRegs[13] = (u16)((__DSPRegs[13] & ~0xFF) | refresh);
    fn_80415B20();
    lbl_806EF4F4 = TRUE;
    OSRestoreInterrupts(old);
    return lbl_806EF4E8;
}

/* ARGetBaseAddress */
u32 fn_80415A70(void)
{
    return 0x4000;
}

/* __ARHandler */
void fn_80415A78(__OSInterrupt interrupt, OSContext* context)
{
    OSContext exceptionContext;
    u16 tmp;

    tmp = __DSPRegs[5];
    tmp = (u16)((tmp & ~(0x80 | 0x08)) | 0x20);
    __DSPRegs[5] = tmp;
    fn_80433814(&exceptionContext);
    fn_8043364C(&exceptionContext);
    if (lbl_806EF4D8) {
        lbl_806EF4D8();
    }
    fn_80433814(&exceptionContext);
    fn_8043364C(context);
}

/* __ARClearInterrupt */
void fn_80415AF0(void)
{
    u16 tmp;

    tmp = __DSPRegs[5];
    tmp = (u16)((tmp & ~(0x80 | 0x08)) | 0x20);
    __DSPRegs[5] = tmp;
}

/* __ARGetInterruptStatus */
u16 fn_80415B10(void)
{
    return (u16)(__DSPRegs[5] & 0x20);
}
