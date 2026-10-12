/*
 * Dolphin SDK EXI (MWCC GC/1.2.5n, cflags_dolphin_exi = -O3,p as EXIBios.c needs;
 * EXIUart.c at the end of this range may want -O4,p),
 * .text 0x80426CD0-0x80428F14 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * The tail of this range (fn_80428C64.., GXGetTexObj users and GX FIFO callers) is probably GX code.
 * Every data object is extern by its lbl_ name.
 *
 * EXIBios.c part (0x80426CD0..0x804286AC): the functions keep their placeholder names. Likely SDK names:
 * fn_80426CD0 SetExiInterruptMask, fn_80426DC4 EXIImm, fn_80427020 EXIImmEx, fn_804270C0 EXIDma,
 * fn_804271AC EXISync (CompleteTransfer is inlined and has no symbol), fn_804273F8 EXIClearInterrupts,
 * fn_80427440 EXISetExiCallback, fn_804274BC __EXIProbe, fn_80427630 EXIProbe, fn_804276B0 EXIProbeEx,
 * fn_80427764 EXIAttach (__EXIAttach inlined), fn_80427870 EXIDetach, fn_8042792C EXISelect,
 * fn_80427A58 EXIDeselect, fn_80427B68 EXIIntrruptHandler, fn_80427C30 TCIntrruptHandler,
 * fn_80427E48 EXTIntrruptHandler, fn_80427F18 EXIInit, fn_804280EC EXILock, fn_804281E0 EXIUnlock,
 * fn_804282BC EXIGetState, fn_804282D4 UnlockedHandler, fn_804282FC EXIGetID.
 * EXIUart.c part: fn_804286AC ProbeBarnacle, fn_80428838 __OSEnableBarnacle.
 * Placeholder callees: fn_80435350 __OSMaskInterrupts, fn_80434FF0 __OSGetInterruptHandler,
 * fn_80433814 OSClearContext, fn_8043364C OSSetCurrentContext, fn_80438628 OSGetTime,
 * fn_80406CC0 __div2i, fn_80431828 OSGetConsoleType, fn_8043218C __OSGetDIConfig.
 */
#include <dolphin.h>
#include <dolphin/exi.h>
#include <dolphin/os.h>

#include <dolphin/gx.h>
#include <dolphin/hw_regs.h>

#include "__gx.h"

#define STATE_IDLE     0
#define STATE_DMA      1
#define STATE_IMM      2
#define STATE_BUSY     3
#define STATE_SELECTED 4
#define STATE_ATTACHED 8
#define STATE_LOCKED   16

/* Ecb[3] (EXIControl, 0x40 bytes each) at lbl_806DE358; fields as in include/dolphin/exi.h. */
extern EXIControl lbl_806DE358[3];
extern u32 lbl_806EF720;  /* IDSerialPort1 */
extern s32 lbl_806EF728;  /* Chan */
extern u32 lbl_806EF72C;  /* Dev */
extern u32 lbl_806EF730;  /* Enabled */
extern u32 lbl_806EF734;  /* BarnacleEnabled */
extern int lbl_806EF7C8;  /* __OSInIPL */
extern const char* lbl_806EF218;  /* __EXIVersion */
extern u32 lbl_806EF748;  /* __GXShutdown peCount */
extern OSTime lbl_806EF750;  /* __GXShutdown time */
extern u32 lbl_806EF758;  /* __GXShutdown calledOnce */

#define Ecb lbl_806DE358

void fn_80435350(u32 mask);
u32 fn_80434FF0(s32 interrupt);
void fn_80433814(OSContext* context);
void fn_8043364C(OSContext* context);
OSTime fn_80438628(void);
u32 fn_80431828(void);
u32 fn_8043218C(void);

u32 fn_804273F8(s32 chan, int exi, int tc, int ext);
int fn_80426DC4(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
int fn_804271AC(s32 chan);
int fn_804274BC(s32 chan);
int fn_80427764(s32 chan, EXICallback extCallback);
int fn_80427870(s32 chan);
int fn_8042792C(s32 chan, u32 dev, u32 freq);
int fn_80427A58(s32 chan);
int fn_804280EC(s32 chan, u32 dev, EXICallback unlockedCallback);
int fn_804281E0(s32 chan);
void fn_80427B68(__OSInterrupt interrupt, OSContext* context);
void fn_80427C30(__OSInterrupt interrupt, OSContext* context);
void fn_80427E48(__OSInterrupt interrupt, OSContext* context);
void fn_804282D4(s32 chan, OSContext* context);
s32 fn_804282FC(s32 chan, u32 dev, u32* id);
int fn_804286AC(s32 chan, u32 dev, u32* revision);
void fn_80428838(s32 chan, u32 dev);

void fn_80426CD0(s32 chan, EXIControl* exi) {
    EXIControl* exi2;
    exi2 = &Ecb[2];

    switch (chan) {
    case 0:
        if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || (exi->state & STATE_LOCKED)) {
            fn_80435350(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
        } else {
            __OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
        }
        break;
    case 1:
        if (exi->exiCallback == 0 || (exi->state & STATE_LOCKED)) {
            fn_80435350(OS_INTERRUPTMASK_EXI_1_EXI);
        } else {
            __OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
        }
        break;
    case 2:
        if (fn_80434FF0(__OS_INTERRUPT_PI_DEBUG) == 0 || (exi->state & STATE_LOCKED)) {
            fn_80435350(OS_INTERRUPTMASK_PI_DEBUG);
        } else {
            __OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
        }
        break;
    }
}

static void CompleteTransfer(s32 chan) {
    EXIControl* exi;
    u8* buf;
    u32 data;
    int i;
    int len;

    exi = &Ecb[chan];

    if (exi->state & STATE_BUSY) {
        if (exi->state & STATE_IMM) {
            if ((len = exi->immLen) != 0) {
                buf = exi->immBuf;
                data = __EXIRegs[(chan * 5) + 4];
                for (i = 0; i < len; i++) {
                    *buf++ = data >> ((3 - i) * 8);
                }
            }
        }
        exi->state &= ~STATE_BUSY;
    }
}

int fn_80426DC4(s32 chan, void* buf, s32 len, u32 type, EXICallback callback) {
    EXIControl* exi;
    BOOL enabled;
    u32 data;
    int i;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    if ((exi->state & STATE_BUSY) || !(exi->state & STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->tcCallback = callback;
    if (exi->tcCallback) {
        fn_804273F8(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }

    exi->state |= STATE_IMM;
    if (type != 0) {
        data = 0;
        for (i = 0; i < len; i++) {
            data |= ((u8*)buf)[i] << ((3 - i) * 8);
        }
        __EXIRegs[(chan * 5) + 4] = data;
    }

    exi->immBuf = buf;
    exi->immLen = (type != 1) ? len : 0;
    __EXIRegs[(chan * 5) + 3] = (type << 2) | 1 | ((len - 1) << 4);
    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_80427020(s32 chan, void* buf, s32 len, u32 mode) {
    s32 xLen;

    while (len) {
        xLen = (len < 4) ? len : 4;
        if (fn_80426DC4(chan, buf, xLen, mode, 0) == 0) {
            return 0;
        }
        if (fn_804271AC(chan) == 0) {
            return 0;
        }
        ((u8*)buf) += xLen;
        len -= xLen;
    }

    return 1;
}

int fn_804270C0(s32 chan, void* buf, s32 len, u32 type, EXICallback callback) {
    EXIControl* exi;
    BOOL enabled;

    exi = &Ecb[chan];

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_BUSY) || !(exi->state & STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->tcCallback = callback;
    if ((u32)exi->tcCallback) {
        fn_804273F8(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }

    exi->state |= STATE_DMA;
    __EXIRegs[(chan * 5) + 1] = (u32)buf & 0x03FFFFE0;
    __EXIRegs[(chan * 5) + 2] = len;
    __EXIRegs[(chan * 5) + 3] = (type * 4) | 3;

    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_804271AC(s32 chan) {
    EXIControl* exi;
    int rc;
    BOOL enabled;

    exi = &Ecb[chan];
    rc = 0;

    while ((exi->state & STATE_SELECTED)) {
        if (!(__EXIRegs[(chan * 5) + 3] & 1)) {
            enabled = OSDisableInterrupts();
            if (exi->state & STATE_SELECTED) {
                CompleteTransfer(chan);
                if (fn_8043218C() != 0xFF || (fn_80431828() & 0xf0000000) == 0x20000000 || exi->immLen != 4 ||
                    (__EXIRegs[chan * 5] & 0x70) ||
                    (__EXIRegs[(chan * 5) + 4] != 0x01010000 && __EXIRegs[(chan * 5) + 4] != 0x05070000 &&
                     __EXIRegs[(chan * 5) + 4] != 0x04220001) ||
                    __OSDeviceCode == 0x8200) {
                    rc = 1;
                }
            }
            OSRestoreInterrupts(enabled);
            break;
        }
    }

    return rc;
}

u32 fn_804273F8(s32 chan, int exi, int tc, int ext) {
    u32 cpr;
    u32 prev;

    cpr = prev = __EXIRegs[(chan * 5)];
    prev &= 0x7F5;

    if (exi != 0) {
        prev |= 2;
    }

    if (tc != 0) {
        prev |= 8;
    }

    if (ext != 0) {
        prev |= 0x800;
    }

    __EXIRegs[(chan * 5)] = prev;
    return cpr;
}

EXICallback fn_80427440(s32 chan, EXICallback exiCallback) {
    EXIControl* exi;
    EXICallback prev;
    BOOL enabled;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    prev = exi->exiCallback;
    exi->exiCallback = exiCallback;
    if (chan != 2) {
        fn_80426CD0(chan, exi);
    } else {
        fn_80426CD0(0, &Ecb[0]);
    }

    OSRestoreInterrupts(enabled);
    return prev;
}

int fn_804274BC(s32 chan) {
    EXIControl* exi;
    BOOL enabled;
    int rc;
    u32 cpr;
    s32 t;

    exi = &Ecb[chan];
    if (chan == 2) {
        return 1;
    }

    rc = 1;
    enabled = OSDisableInterrupts();
    cpr = __EXIRegs[(chan * 5)];

    if (!(exi->state & STATE_ATTACHED)) {
        if (cpr & 0x800) {
            fn_804273F8(chan, 0, 0, 1);
            __gUnknown800030C0[chan] = exi->idTime = 0;
        }

        if (cpr & 0x1000) {
            t = ((s32)(OSTicksToMilliseconds(fn_80438628()) / 100) + 1);

            if (__gUnknown800030C0[chan] == 0) {
                __gUnknown800030C0[chan] = t;
            }

            if (t - (s32)__gUnknown800030C0[chan] < 3) {
                rc = 0;
            }
        } else {
            __gUnknown800030C0[chan] = exi->idTime = 0;
            rc = 0;
        }
    } else if (!(cpr & 0x1000) || (cpr & 0x800)) {
        __gUnknown800030C0[chan] = exi->idTime = 0;
        rc = 0;
    }

    OSRestoreInterrupts(enabled);
    return rc;
}

int fn_80427630(s32 chan) {
    EXIControl* exi = &Ecb[chan];
    int rc;
    u32 id;

    rc = fn_804274BC(chan);
    if (rc && !exi->idTime) {
        rc = fn_804282FC(chan, 0, &id) ? 1 : 0;
    }

    return rc;
}

s32 fn_804276B0(s32 chan) {
    if (fn_80427630(chan)) {
        return 1;
    }

    if (__gUnknown800030C0[chan]) {
        return 0;
    }

    return -1;
}

static int __EXIAttach(s32 chan, EXICallback extCallback) {
    EXIControl* exi;
    BOOL enabled;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    if ((exi->state & STATE_ATTACHED) || !fn_804274BC(chan)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    fn_804273F8(chan, 1, 0, 0);
    exi->extCallback = extCallback;
    __OSUnmaskInterrupts(0x100000U >> (chan * 3));
    exi->state |= STATE_ATTACHED;

    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_80427764(s32 chan, EXICallback extCallback) {
    EXIControl* exi;
    BOOL enabled;
    int rc;

    exi = &Ecb[chan];

    fn_80427630(chan);
    enabled = OSDisableInterrupts();
    if (exi->idTime == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    rc = __EXIAttach(chan, extCallback);
    OSRestoreInterrupts(enabled);
    return rc;
}

int fn_80427870(s32 chan) {
    EXIControl* exi;
    BOOL enabled;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    if (!(exi->state & STATE_ATTACHED)) {
        OSRestoreInterrupts(enabled);
        return 1;
    }

    if ((exi->state & STATE_LOCKED) && (exi->dev == 0)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~STATE_ATTACHED;
    fn_80435350(0x500000U >> (chan * 3));

    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_8042792C(s32 chan, u32 dev, u32 freq) {
    EXIControl* exi;
    u32 cpr;
    BOOL enabled;

    exi = &Ecb[chan];

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_SELECTED) ||
        ((chan != 2) && (((dev == 0) && !(exi->state & STATE_ATTACHED) && (fn_804274BC(chan) == 0)) ||
                         !(exi->state & STATE_LOCKED) || (exi->dev != dev)))) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state |= STATE_SELECTED;
    cpr = __EXIRegs[(chan * 5)];
    cpr &= 0x405;
    cpr |= (((1 << dev) << 7) | (freq * 0x10));
    __EXIRegs[(chan * 5)] = cpr;

    if (exi->state & STATE_ATTACHED) {
        switch (chan) {
        case 0:
            fn_80435350(0x100000U);
            break;
        case 1:
            fn_80435350(0x20000U);
            break;
        }
    }

    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_80427A58(s32 chan) {
    EXIControl* exi;
    u32 cpr;
    BOOL enabled;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    if (!(exi->state & STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~STATE_SELECTED;
    cpr = __EXIRegs[(chan * 5)];
    __EXIRegs[(chan * 5)] = cpr & 0x405;

    if (exi->state & STATE_ATTACHED) {
        switch (chan) {
        case 0:
            __OSUnmaskInterrupts(0x100000U);
            break;
        case 1:
            __OSUnmaskInterrupts(0x20000U);
            break;
        }
    }

    OSRestoreInterrupts(enabled);

    if ((chan != 2) && (cpr & 0x80)) {
        if (fn_804274BC(chan) != 0) {
            return 1;
        }
        return 0;
    }

    return 1;
}

void fn_80427B68(__OSInterrupt interrupt, OSContext* context) {
    s32 chan;
    EXIControl* exi;
    EXICallback callback;

    chan = (interrupt - 9) / 3;

    exi = &Ecb[chan];
    fn_804273F8(chan, 1, 0, 0);

    callback = exi->exiCallback;
    if (callback) {
        OSContext exceptionContext;

        fn_80433814(&exceptionContext);
        fn_8043364C(&exceptionContext);
        callback(chan, context);
        fn_80433814(&exceptionContext);
        fn_8043364C(context);
    }
}

void fn_80427C30(__OSInterrupt interrupt, OSContext* context) {
    s32 chan;
    EXIControl* exi;
    EXICallback callback;

    chan = (interrupt - 10) / 3;

    exi = &Ecb[chan];
    fn_80435350(0x80000000U >> interrupt);
    fn_804273F8(chan, 0, 1, 0);

    callback = exi->tcCallback;
    if (callback) {
        OSContext exceptionContext;

        exi->tcCallback = NULL;
        CompleteTransfer(chan);

        fn_80433814(&exceptionContext);
        fn_8043364C(&exceptionContext);
        callback(chan, context);
        fn_80433814(&exceptionContext);
        fn_8043364C(context);
    }
}

void fn_80427E48(__OSInterrupt interrupt, OSContext* context) {
    s32 chan;
    EXIControl* exi;
    EXICallback callback;

    chan = (interrupt - 11) / 3;

    fn_80435350(0x500000U >> (chan * 3));
    exi = &Ecb[chan];
    callback = exi->extCallback;
    exi->state &= ~STATE_ATTACHED;

    if (callback) {
        OSContext exceptionContext;

        fn_80433814(&exceptionContext);
        fn_8043364C(&exceptionContext);
        exi->extCallback = NULL;
        callback(chan, context);
        fn_80433814(&exceptionContext);
        fn_8043364C(context);
    }
}

void fn_80427F18(void) {
    u32 id;

    while (((__EXIRegs[3] & 1) == 1) || ((__EXIRegs[8] & 1) == 1) || ((__EXIRegs[13] & 1) == 1)) {
    }

    fn_80435350(0x7F8000U);
    __EXIRegs[0] = 0;
    __EXIRegs[5] = 0;
    __EXIRegs[10] = 0;
    __EXIRegs[0] = 0x2000;
    __OSSetInterruptHandler(9, fn_80427B68);
    __OSSetInterruptHandler(10, fn_80427C30);
    __OSSetInterruptHandler(11, fn_80427E48);
    __OSSetInterruptHandler(12, fn_80427B68);
    __OSSetInterruptHandler(13, fn_80427C30);
    __OSSetInterruptHandler(14, fn_80427E48);
    __OSSetInterruptHandler(15, fn_80427B68);
    __OSSetInterruptHandler(16, fn_80427C30);

    fn_804282FC(0, 2, &lbl_806EF720);

    if (lbl_806EF7C8) {
        __gUnknown800030C0[0] = __gUnknown800030C0[1] = 0;
        Ecb[0].idTime = Ecb[1].idTime = 0;
        fn_804274BC(0);
        fn_804274BC(1);
    } else if (fn_804282FC(0, 0, &id) && id == 0x7010000) {
        fn_80428838(1, 0);
    } else if (fn_804282FC(1, 0, &id) && id == 0x7010000) {
        fn_80428838(0, 2);
    }

    OSRegisterVersion(lbl_806EF218);
}

int fn_804280EC(s32 chan, u32 dev, EXICallback unlockedCallback) {
    EXIControl* exi;
    BOOL enabled;
    int i;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    if (exi->state & STATE_LOCKED) {
        if (unlockedCallback) {
            for (i = 0; i < exi->items; i++) {
                if (exi->queue[i].dev == dev) {
                    OSRestoreInterrupts(enabled);
                    return 0;
                }
            }
            exi->queue[exi->items].callback = unlockedCallback;
            exi->queue[exi->items].dev = dev;
            exi->items++;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state |= STATE_LOCKED;
    exi->dev = dev;
    fn_80426CD0(chan, exi);
    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_804281E0(s32 chan) {
    EXIControl* exi;
    BOOL enabled;
    EXICallback unlockedCallback;

    exi = &Ecb[chan];
    enabled = OSDisableInterrupts();

    if (!(exi->state & STATE_LOCKED)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~STATE_LOCKED;
    fn_80426CD0(chan, exi);
    if (exi->items > 0) {
        unlockedCallback = exi->queue[0].callback;
        if (--exi->items > 0) {
            memmove(&exi->queue[0], &exi->queue[1], exi->items * 8);
        }
        unlockedCallback(chan, 0);
    }

    OSRestoreInterrupts(enabled);
    return 1;
}

u32 fn_804282BC(s32 chan) {
    EXIControl* exi;

    exi = &Ecb[chan];
    return exi->state;
}

void fn_804282D4(s32 chan, OSContext* context) {
    u32 id;
    fn_804282FC(chan, 0, &id);
}

s32 fn_804282FC(s32 chan, u32 dev, u32* id) {
    EXIControl* exi = &Ecb[chan];
    int err;
    u32 cmd;
    s32 startTime;
    BOOL enabled;

    if (chan == 0 && dev == 2 && lbl_806EF720 != 0) {
        *id = lbl_806EF720;
        return 1;
    }

    if ((chan < 2) && (dev == 0)) {
        if ((fn_804274BC(chan) == 0)) {
            return 0;
        }

        if (exi->idTime == __gUnknown800030C0[chan]) {
            *id = exi->id;
            return exi->idTime;
        }

        if (!__EXIAttach(chan, NULL)) {
            return 0;
        }

        startTime = __gUnknown800030C0[chan];
    }

    enabled = OSDisableInterrupts();

    err = !fn_804280EC(chan, dev, (chan < 2 && dev == 0) ? fn_804282D4 : NULL);
    if (err == 0) {
        err = !fn_8042792C(chan, dev, 0);
        if (err == 0) {
            cmd = 0;
            err |= !fn_80426DC4(chan, &cmd, 2, 1, 0);
            err |= !fn_804271AC(chan);
            err |= !fn_80426DC4(chan, id, 4, 0, 0);
            err |= !fn_804271AC(chan);
            err |= !fn_80427A58(chan);
        }

        fn_804281E0(chan);
    }

    OSRestoreInterrupts(enabled);

    if ((chan < 2) && (dev == 0)) {
        fn_80427870(chan);
        enabled = OSDisableInterrupts();
        err |= __gUnknown800030C0[chan] != startTime;

        if (!err) {
            exi->id = *id;
            exi->idTime = startTime;
        }

        OSRestoreInterrupts(enabled);

        if (err) {
            return 0;
        }

        return exi->idTime;
    }

    if (err) {
        return 0;
    }

    return 1;
}

int fn_804286AC(s32 chan, u32 dev, u32* revision) {
    int err;
    u32 cmd;

    if (chan != 2 && dev == 0) {
        if (!fn_80427764(chan, NULL)) {
            return 0;
        }
    }

    err = !fn_804280EC(chan, dev, NULL);
    if (!err) {
        err = !fn_8042792C(chan, dev, 0);
        if (!err) {
            cmd = 0x20011300;
            err = 0;
            err |= !fn_80426DC4(chan, &cmd, 4, 1, NULL);
            err |= !fn_804271AC(chan);
            err |= !fn_80426DC4(chan, revision, 4, 0, NULL);
            err |= !fn_804271AC(chan);
            err |= !fn_80427A58(chan);
        }
        fn_804281E0(chan);
    }

    if (chan != 2 && dev == 0) {
        fn_80427870(chan);
    }

    if (err) {
        return 0;
    }

    return (*revision != 0xFFFFFFFF);
}

void fn_80428838(s32 chan, u32 dev) {
    u32 id;

    if (fn_804282FC(chan, dev, &id)) {
        switch (id) {
        case 0x01010000:
        case 0x01020000:
        case 0x02020000:
        case 0x03010000:
        case 0x04020100:
        case 0x04020200:
        case 0x04020300:
        case 0x04040404:
        case 0x04060000:
        case 0x04120000:
        case 0x04130000:
        case 0x04220000:
        case 4:
        case 8:
        case 0x10:
        case 0x20:
        case 0x80000004:
        case 0x80000008:
        case 0x80000010:
        case 0x80000020:
        case 0xFFFFFFFF:
            break;
        default:
            if (fn_804286AC(chan, dev, &id)) {
                lbl_806EF728 = chan;
                lbl_806EF72C = dev;
                lbl_806EF730 = lbl_806EF734 = 0xA5FF005A;
            }
        }
    }
}

/* GXInit.c part (0x80428C64..): fn_80428C64 __GXDefaultTexRegionCallback, fn_80428D60
 * __GXDefaultTlutRegionCallback, fn_80428D84 __GXShutdown. Placeholder callees: fn_8042A544
 * GXSetBreakPtCallback, fn_8042C62C GXSetDrawSyncCallback, fn_8042C6F8 GXSetDrawDoneCallback,
 * fn_8041A5DC PPCSync, fn_8042C07C __GXAbort. */
void fn_8042A544(void* cb);
void fn_8042C62C(void* cb);
void fn_8042C6F8(void* cb);
void fn_8041A5DC(void);
void fn_8042C07C(void);

GXTexRegion* fn_80428C64(const GXTexObj* t_obj, GXTexMapID id) {
    GXTexFmt fmt;
    u8 mm;

    fmt = GXGetTexObjFmt(t_obj);
    mm = GXGetTexObjMipMap(t_obj);
    id = (GXTexMapID)(id % GX_MAX_TEXMAP);

    switch (fmt) {
    case GX_TF_RGBA8:
        if (mm) {
            return &__GXData->TexRegions2[id];
        }
        return &__GXData->TexRegions1[id];
    case GX_TF_C4:
    case GX_TF_C8:
    case GX_TF_C14X2:
        return &__GXData->TexRegions0[id];
    default:
        if (mm) {
            return &__GXData->TexRegions1[id];
        }
        return &__GXData->TexRegions0[id];
    }
}

GXTlutRegion* fn_80428D60(u32 idx) {
    if (idx >= 20) {
        return NULL;
    }
    return &__GXData->TlutRegions[idx];
}

int fn_80428D84(BOOL final) {
    u32 reg;
    u32 peCountNew;
    OSTime timeNew;

    if (!final) {
        if (!lbl_806EF758) {
            lbl_806EF748 = __GXReadMEMCounterU32(0x28, 0x27);
            lbl_806EF750 = fn_80438628();
            lbl_806EF758 = 1;
            return 0;
        }

        timeNew = fn_80438628();
        peCountNew = __GXReadMEMCounterU32(0x28, 0x27);

        if (timeNew - lbl_806EF750 < 10) {
            return 0;
        }

        if (peCountNew != lbl_806EF748) {
            lbl_806EF748 = peCountNew;
            lbl_806EF750 = timeNew;
            return 0;
        }

    } else {
        fn_8042A544(NULL);
        fn_8042C62C(NULL);
        fn_8042C6F8(NULL);

        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);

        fn_8041A5DC();

        reg = 0;
        GX_SET_CP_REG(1, reg);

        reg = 3;
        GX_SET_CP_REG(2, reg);

        __GXData->abtWaitPECopy = 1;

        fn_8042C07C();
    }

    return 1;
}
