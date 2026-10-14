/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8041583C-0x80417314 (code-only unit, 9 functions; original file name from the reference split).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 * Written from the public SDK ar.c (doldecomp/dolsdk2004 layout), small functions only; the SDK names are in
 * the comments, the symbols stay fn_<addr> (symbols.txt has no real names for this range).
 * __ARChecksize (fn_80415B20) is written from the public SDK ar.c (doldecomp/dolsdk2004).
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
extern u32 lbl_806EF4DC;           /* __AR_Size */
extern u32 lbl_806EF4E0;           /* __AR_InternalSize */
extern u32 lbl_806EF4E4;           /* __AR_ExpansionSize */

void OSClearContext(OSContext* context);
void OSSetCurrentContext(OSContext* context);
void __ARChecksize(void);
void PPCSync(void);
void DCInvalidateRange(void* addr, u32 len);
void DCFlushRange(void* addr, u32 len);

ARCallback fn_8041583C(ARCallback callback);
u32 fn_80415880(void);
void fn_804158BC(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);
u32 ARInit(u32* stack_index_addr, u32 num_entries);
u32 ARGetBaseAddress(void);
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
u32 ARInit(u32* stack_index_addr, u32 num_entries)
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
    __ARChecksize();
    lbl_806EF4F4 = TRUE;
    OSRestoreInterrupts(old);
    return lbl_806EF4E8;
}

/* ARGetBaseAddress */
u32 ARGetBaseAddress(void)
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
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (lbl_806EF4D8) {
        lbl_806EF4D8();
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
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

static void __ARWaitForDMA(void) {
    while (__DSPRegs[5] & 0x200);
}

static void __ARWriteDMA(u32 mmem_addr, u32 aram_addr, u32 length) {
	// Main mem address
	__DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mmem_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mmem_addr & 0xffff));

	// ARAM address
	__DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));

	// DMA buffer size
	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x8000);

	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x03ff) | (u16)(length >> 16));
	__DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff));

	__ARWaitForDMA();
    fn_80415AF0();
}

static void __ARReadDMA(u32 mmem_addr, u32 aram_addr, u32 length) {
	// Main mem address
	__DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mmem_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mmem_addr & 0xffff));

	// ARAM address
	__DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));

	// DMA buffer size
	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] | 0x8000);

	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x03ff) | (u16)(length >> 16));
	__DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff));

	__ARWaitForDMA();
    fn_80415AF0();
}

void __ARChecksize(void) {
    u8 test_data_pad[63];
    u8 dummy_data_pad[63];
    u8 buffer_pad[63];
    u8 save_pad_1[63];
    u8 save_pad_2[63];
    u8 save_pad_3[63];
    u8 save_pad_4[63];
    u8 save_pad_5[63];
    u32* test_data;
    u32* dummy_data;
    u32* buffer;
    u32* save1;
    u32* save2;
    u32* save3;
    u32* save4;
    u32* save5;
    u16 ARAM_mode = 0;
    u32 ARAM_size = 0;
    u32 i;

    do {} while(!(__DSPRegs[11] & 1));

    ARAM_mode = 3;
    ARAM_size = lbl_806EF4E0 = 0x1000000;
    __DSPRegs[9] = ((__DSPRegs[9] & 0xFFFFFFC0) | 3) | 0x20;

    test_data = (u32*)(OSRoundUp32B((u32)(test_data_pad)));
    dummy_data = (u32*)(OSRoundUp32B((u32)(dummy_data_pad)));
    buffer = (u32*)(OSRoundUp32B((u32)(buffer_pad)));

    save1 = (u32*)(OSRoundUp32B((u32)(save_pad_1)));
    save2 = (u32*)(OSRoundUp32B((u32)(save_pad_2)));
    save3 = (u32*)(OSRoundUp32B((u32)(save_pad_3)));
    save4 = (u32*)(OSRoundUp32B((u32)(save_pad_4)));
    save5 = (u32*)(OSRoundUp32B((u32)(save_pad_5)));

    for (i = 0; i < 8; i++) {
        *(test_data + i) = 0xDEADBEEF;
        *(dummy_data + i) = 0xBAD0BAD0;
    }

    DCFlushRange((void*)test_data, 0x20);
    DCFlushRange((void*)dummy_data, 0x20);

    lbl_806EF4E4 = 0;

    DCInvalidateRange((void*)save1, 0x20);
    __ARReadDMA((u32)save1, ARAM_size + 0, 0x20);
    PPCSync();

    __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

    memset((void*)buffer, 0, 0x20);
    DCFlushRange((void*)buffer, 0x20);

    __ARReadDMA((u32)buffer, ARAM_size + 0x0000000, 0x20);
    PPCSync();

    if (buffer[0] == test_data[0]) {
        DCInvalidateRange((void*)save2, 0x20);
        __ARReadDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
        PPCSync();

        DCInvalidateRange((void*)save3, 0x20);
        __ARReadDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
        PPCSync();

        DCInvalidateRange((void*)save4, 0x20);
        __ARReadDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
        PPCSync();

        DCInvalidateRange((void*)save5, 0x20);
        __ARReadDMA((u32)save5, ARAM_size + 0x0400000, 0x20);
        PPCSync();

        __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0200000, 0x20);
        __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

        memset((void*)buffer, 0, 0x20);
        DCFlushRange((void*)buffer, 0x20);

        __ARReadDMA((u32)buffer, ARAM_size + 0x0200000, 0x20);
        PPCSync();

        if (buffer[0] == test_data[0]) {
            __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);

            ARAM_mode |= 0 << 1;
            ARAM_size += 0x0200000;
            lbl_806EF4E4 = 0x0200000;
        } else {
            __ARWriteDMA((u32)dummy_data, ARAM_size + 0x1000000, 0x20);
            __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

            memset((void*)buffer, 0, 0x20);
            DCFlushRange((void*)buffer, 0x20);

            __ARReadDMA((u32)buffer, ARAM_size + 0x1000000, 0x20);
            PPCSync();

            if (buffer[0] == test_data[0]) {
                __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);

                ARAM_mode |= 4 << 1;
                ARAM_size += 0x0400000;
                lbl_806EF4E4 = 0x0400000;
            } else {
                __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0000200, 0x20);
                __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

                memset((void*)buffer, 0, 0x20);
                DCFlushRange((void*)buffer, 0x20);

                __ARReadDMA((u32)buffer, ARAM_size + 0x0000200, 0x20);
                PPCSync();

                if (buffer[0] == test_data[0]) {
                    __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                    __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                    __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);

                    ARAM_mode |= 8 << 1;
                    ARAM_size += 0x0800000;
                    lbl_806EF4E4 = 0x0800000;
                } else {
                    __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0400000, 0x20);

                    __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

                    memset((void*)buffer, 0, 0x20);
                    DCFlushRange((void*)buffer, 0x20);

                    __ARReadDMA((u32)buffer, ARAM_size + 0x0400000, 0x20);
                    PPCSync();

                    if (buffer[0] == test_data[0]) {
                        __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                        __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                        __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                        __ARWriteDMA((u32)save4, ARAM_size + 0x0000200, 0x20);

                        ARAM_mode |= 12 << 1;
                        ARAM_size += 0x1000000;
                        lbl_806EF4E4 = 0x1000000;
                    } else {
                        __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                        __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                        __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                        __ARWriteDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
                        __ARWriteDMA((u32)save5, ARAM_size + 0x0400000, 0x20);

                        ARAM_mode |= 16 << 1;
                        ARAM_size += 0x2000000;
                        lbl_806EF4E4 = 0x2000000;
                    }
                }
            }
        }

        __DSPRegs[9] = (u16)((__DSPRegs[9] & ~(0x07 | 0x38)) | ARAM_mode);
    }

    *(u32*)OSPhysicalToUncached(0x00D0) = ARAM_size;
    lbl_806EF4DC = ARAM_size;
}

