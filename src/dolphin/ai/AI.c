/*
 * Dolphin SDK AI library, AI.c (build "Apr  5 2004 04:15:02", rev 0x2301).
 * Partial: only the functions matched so far. Register bases come from the
 * original code (lis 0xCC00 + 0x6C00 = AI registers); layout follows the public SDK AI.c.
 * Parked (not matching yet): AIInitDMA, AIStartDMA, AIStopDMA, AISetStreamPlayState,
 * AISetStreamVolLeft/Right (the target keeps a full 32-bit register base in a
 * register, lis+addi; every compile here folds the offset into the load/store).
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef volatile u32 vu32;
typedef int BOOL;

typedef void (*AIDCallback)(void);

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);

extern AIDCallback __AID_Callback;

#define __AIRegs ((vu32*)0xCC006C00)

AIDCallback AIRegisterDMACallback(AIDCallback callback)
{
    BOOL oldInts;
    AIDCallback ret;

    ret = __AID_Callback;
    oldInts = OSDisableInterrupts();
    __AID_Callback = callback;
    OSRestoreInterrupts(oldInts);
    return ret;
}

u32 AIGetStreamPlayState(void)
{
    return __AIRegs[0] & 1;
}

u32 AIGetDSPSampleRate(void)
{
    return ((__AIRegs[0] >> 6) & 1) ^ 1;
}

u32 AIGetStreamSampleRate(void)
{
    return (__AIRegs[0] >> 1) & 1;
}

u8 AIGetStreamVolLeft(void)
{
    return (u8)(__AIRegs[1] & 0xFF);
}

u8 AIGetStreamVolRight(void)
{
    return (u8)((__AIRegs[1] >> 8) & 0xFF);
}
