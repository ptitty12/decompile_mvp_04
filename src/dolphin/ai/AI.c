/*
 * Dolphin SDK AI library, AI.c (build "Apr  5 2004 04:15:02", rev 0x2301).
 * Register bases come from the original code (lis 0xCC00 + 0x6C00 = AI registers,
 * 0xCC005000 = DSP registers); layout follows the public SDK AI.c.
 * Not written: fn_804155D8 (the callback stack switch, hand-written in the original),
 * AIInit (near-miss only: same instruction count, register allocation differs) and
 * __AI_SRC_INIT.
 * The compiled object is byte-identical for most of this file only WITHOUT `-opt nopeephole`
 * (cflags_dolphin_ai); with it, only the getters, AIRegisterDMACallback, AIStartDMA and
 * AIStopDMA match. Evidence: prologue copies are `addi rX,rY,0`, rlwimi in the volume setters.
 * Static data (.sbss 0x806EF488..0x806EF4C8) is extern by its lbl_ name:
 *   488 stream callback, 48C DMA callback, 490 callback stack, 494 old stack,
 *   498 init flag, 49C DMA handler active, 4A0 bound_32KHz, 4A8 bound_48KHz,
 *   4B0 min_wait, 4B8 max_wait, 4C0 buffer (the last five are 64-bit).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long long s64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef int BOOL;

typedef void (*AIDCallback)(void);
typedef void (*AISCallback)(u32 count);

typedef struct OSContext {
    u8 data[0x2C8];
} OSContext;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(const char* version);
extern void __OSSetInterruptHandler(int interrupt, void* handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void fn_80433814(OSContext* context);
extern void fn_8043364C(OSContext* context);
extern s64 fn_80438628(void);
extern void fn_804155D8(AIDCallback callback);

extern const char* lbl_806EF148;
extern AISCallback lbl_806EF488;
extern AIDCallback lbl_806EF48C;
extern u8* lbl_806EF490;
extern BOOL lbl_806EF498;
extern BOOL lbl_806EF49C;
extern s64 lbl_806EF4A0;
extern s64 lbl_806EF4A8;
extern s64 lbl_806EF4B0;
extern s64 lbl_806EF4B8;
extern s64 lbl_806EF4C0;

vu16 __DSPRegs[] : (0xCC005000);
vu32 __AIRegs[8] : (0xCC006C00);
/* The single-read getters keep a plain constant address (lis + displacement), as in the original. */
#define __AIRegsRead ((vu32*)0xCC006C00)

AIDCallback AIRegisterDMACallback(AIDCallback callback)
{
    BOOL oldInts;
    AIDCallback ret;

    ret = lbl_806EF48C;
    oldInts = OSDisableInterrupts();
    lbl_806EF48C = callback;
    OSRestoreInterrupts(oldInts);
    return ret;
}

void AIInitDMA(u32 start_addr, u32 length)
{
    BOOL oldInts;

    oldInts = OSDisableInterrupts();
    __DSPRegs[24] = (u16)((__DSPRegs[24] & ~0x3FF) | (start_addr >> 16));
    __DSPRegs[25] = (u16)((__DSPRegs[25] & ~0xFFE0) | (0xFFFF & start_addr));
    __DSPRegs[27] = (u16)((__DSPRegs[27] & ~0x7FFF) | (u16)((length >> 5) & 0xFFFF));
    OSRestoreInterrupts(oldInts);
}

void AIStartDMA(void)
{
    __DSPRegs[27] |= 0x8000;
}

void AIStopDMA(void)
{
    __DSPRegs[27] &= ~0x8000;
}

void AISetStreamPlayState(u32 state);
u32 AIGetStreamPlayState(void);
u32 AIGetDSPSampleRate(void);
u32 AIGetStreamSampleRate(void);
void AISetStreamVolLeft(u8 vol);
u8 AIGetStreamVolLeft(void);
void AISetStreamVolRight(u8 vol);
u8 AIGetStreamVolRight(void);
void __AI_SRC_INIT(void);

void AISetStreamPlayState(u32 state)
{
    BOOL oldInts;
    u8 left;
    u8 right;

    if (state == AIGetStreamPlayState()) {
        return;
    }
    if (AIGetStreamSampleRate() == 0 && state == 1) {
        left = AIGetStreamVolRight();
        right = AIGetStreamVolLeft();
        AISetStreamVolRight(0);
        AISetStreamVolLeft(0);
        oldInts = OSDisableInterrupts();
        __AI_SRC_INIT();
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~1) | 1;
        OSRestoreInterrupts(oldInts);
        AISetStreamVolLeft(left);
        AISetStreamVolRight(right);
    } else {
        __AIRegs[0] = (__AIRegs[0] & ~1) | state;
    }
}

u32 AIGetStreamPlayState(void)
{
    return __AIRegsRead[0] & 1;
}

void AISetDSPSampleRate(u32 rate)
{
    u32 state;
    BOOL oldInts;
    u32 sampleRate;
    u8 left;
    u8 right;

    if (rate == AIGetDSPSampleRate()) {
        return;
    }
    __AIRegs[0] &= ~0x40;
    if (rate != 0) {
        return;
    }
    left = AIGetStreamVolLeft();
    right = AIGetStreamVolRight();
    state = __AIRegs[0] & 1;
    sampleRate = AIGetStreamSampleRate();
    AISetStreamVolLeft(0);
    AISetStreamVolRight(0);
    oldInts = OSDisableInterrupts();
    __AI_SRC_INIT();
    __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
    __AIRegs[0] = (__AIRegs[0] & ~2) | (sampleRate << 1);
    __AIRegs[0] = (__AIRegs[0] & ~1) | state;
    __AIRegs[0] |= 0x40;
    OSRestoreInterrupts(oldInts);
    AISetStreamVolLeft(left);
    AISetStreamVolRight(right);
}

u32 AIGetDSPSampleRate(void)
{
    return ((__AIRegsRead[0] >> 6) & 1) ^ 1;
}

void AISetStreamSampleRate(u32 rate)
{
    BOOL oldInts;
    u32 state;
    u8 left;
    u8 right;
    u32 dsp;

    if (rate == AIGetStreamSampleRate()) {
        return;
    }
    state = AIGetStreamPlayState();
    left = AIGetStreamVolLeft();
    right = AIGetStreamVolRight();
    AISetStreamVolRight(0);
    AISetStreamVolLeft(0);
    dsp = __AIRegs[0] & 0x40;
    __AIRegs[0] &= ~0x40;
    oldInts = OSDisableInterrupts();
    __AI_SRC_INIT();
    __AIRegs[0] |= dsp;
    __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
    __AIRegs[0] = (__AIRegs[0] & ~2) | (rate << 1);
    OSRestoreInterrupts(oldInts);
    AISetStreamPlayState(state);
    AISetStreamVolLeft(left);
    AISetStreamVolRight(right);
}

u32 AIGetStreamSampleRate(void)
{
    return (__AIRegsRead[0] >> 1) & 1;
}

void AISetStreamVolLeft(u8 vol)
{
    __AIRegs[1] = (__AIRegs[1] & ~0xFF) | vol;
}

u8 AIGetStreamVolLeft(void)
{
    return (u8)(__AIRegsRead[1] & 0xFF);
}

void AISetStreamVolRight(u8 vol)
{
    __AIRegs[1] = (__AIRegs[1] & ~0xFF00) | (vol << 8);
}

u8 AIGetStreamVolRight(void)
{
    return (u8)((__AIRegsRead[1] >> 8) & 0xFF);
}

void fn_804154B0(int interrupt, OSContext* context)
{
    OSContext tmpContext;

    __AIRegs[0] |= 8;
    fn_80433814(&tmpContext);
    fn_8043364C(&tmpContext);
    if (lbl_806EF488) {
        lbl_806EF488(__AIRegs[2]);
    }
    fn_80433814(&tmpContext);
    fn_8043364C(context);
}

void fn_8041552C(int interrupt, OSContext* context)
{
    OSContext tmpContext;
    u32 tmp;

    tmp = __DSPRegs[5];
    tmp = (tmp & ~0xA0) | 8;
    __DSPRegs[5] = (u16)tmp;
    fn_80433814(&tmpContext);
    fn_8043364C(&tmpContext);
    if (lbl_806EF48C && !lbl_806EF49C) {
        lbl_806EF49C = 1;
        if (lbl_806EF490) {
            fn_804155D8(lbl_806EF48C);
        } else {
            lbl_806EF48C();
        }
        lbl_806EF49C = 0;
    }
    fn_80433814(&tmpContext);
    fn_8043364C(context);
}
