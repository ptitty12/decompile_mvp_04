/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8041A6C4-0x8041BC70 (code-only unit: CARDBios.c, 28 functions).
 * Every data object is extern by its lbl_ name.
 * Reference: Nintendo Dolphin SDK 2004 CARDBios.c as published in doldecomp/dolsdk2004 (structure and field names);
 * callees that symbols.txt still names fn_<addr> are declared here under that name with the SDK name in a comment.
 */
#include <dolphin/card.h>

#include "__card.h"

/* EXI */
extern BOOL fn_80426DC4(s32 chan, void* buf, s32 len, u32 type, EXICallback cb); /* EXIImm */
extern BOOL fn_80427020(s32 chan, void* buf, s32 len, u32 type);                 /* EXIImmEx */
extern BOOL fn_804270C0(s32 chan, void* buf, s32 len, u32 type, EXICallback cb); /* EXIDma */
extern BOOL fn_804271AC(s32 chan);                                               /* EXISync */
extern EXICallback fn_80427440(s32 chan, EXICallback cb);                        /* EXISetExiCallback */
extern BOOL fn_80427630(s32 chan);                                               /* EXIProbe */
extern BOOL fn_8042792C(s32 chan, u32 dev, u32 freq);                            /* EXISelect */
extern BOOL fn_80427A58(s32 chan);                                               /* EXIDeselect */
extern BOOL fn_804280EC(s32 chan, u32 dev, EXICallback cb);                      /* EXILock */
extern BOOL fn_804281E0(s32 chan);                                               /* EXIUnlock */
/* OS */
extern void fn_804321CC(void);                                                /* OSInitAlarm */
extern void fn_80432224(OSAlarm* alarm);                                      /* OSCreateAlarm */
extern void fn_80432484(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler); /* OSSetAlarm */
extern void fn_80432568(OSAlarm* alarm);                                      /* OSCancelAlarm */
extern u16 fn_80434DE8(void);                                                 /* OSGetFontEncode */
extern void fn_80437434(OSThreadQueue* queue);                                /* OSInitThreadQueue */
extern void fn_804382CC(OSThreadQueue* queue);                                /* OSSleepThread */
extern void fn_804383B8(OSThreadQueue* queue);                                /* OSWakeupThread */

/* __CARDBlock (2 control blocks) followed by __CARDDiskNone: defined together in CARDBios.c, so MWCC forms
 * &__CARDDiskNone as base+0x220 */
struct CardBss {
    CARDControl block[2];
    DVDDiskID none;
};
extern struct CardBss lbl_806DCF20;
extern const char* lbl_806EF170;    /* __CARDVersion */
extern u16 lbl_806EF600;            /* font encode, set by CARDInit */
extern u16 lbl_806EF602;
extern OSResetFunctionInfo lbl_806334A8; /* ResetFunctionInfo */

static void fn_8041A8EC(s32 chan, OSContext* context);
static void fn_8041A994(s32 chan, OSContext* context);
static void fn_8041AD64(OSAlarm* alarm, OSContext* context);
static s32 fn_8041AE08(s32 chan);
static void fn_8041B0A8(s32 chan, s32 result);
s32 fn_8041AAD8(s32 chan, u8* status);
s32 fn_8041ACB8(s32 chan);
s32 fn_8041B1B8(s32 chan, CARDCallback txCallback, CARDCallback exiCallback);
s32 fn_8041B848(s32 chan, CARDControl** pcard);
void fn_8041B810(const DVDDiskID* diskID);

/* __CARDDefaultApiCallback */
void fn_8041A6C4(s32 chan, s32 result)
{
}

/* __CARDSyncCallback */
void fn_8041A6C8(s32 chan, s32 result)
{
    CARDControl* card;

    card = &lbl_806DCF20.block[chan];
    fn_804383B8(&card->threadQueue);
}

/* __CARDExtHandler */
void fn_8041A6FC(s32 chan, OSContext* context)
{
    CARDControl* card;
    CARDCallback callback;

    card = &lbl_806DCF20.block[chan];
    if (card->attached) {
        card->attached = FALSE;
        fn_80427440(chan, 0);
        fn_80432568(&card->alarm);

        callback = card->exiCallback;
        if (callback) {
            card->exiCallback = NULL;
            callback(chan, CARD_RESULT_NOCARD);
        }

        if (card->result != CARD_RESULT_BUSY) {
            card->result = CARD_RESULT_NOCARD;
        }

        callback = card->extCallback;
        if (callback && CARD_MAX_MOUNT_STEP <= card->mountStep) {
            card->extCallback = NULL;
            callback(chan, CARD_RESULT_NOCARD);
        }
    }
}

/* __CARDExiHandler */
void fn_8041A7D4(s32 chan, OSContext* context)
{
    CARDControl* card;
    CARDCallback callback;
    u8 status;
    s32 result;

    card = &lbl_806DCF20.block[chan];

    fn_80432568(&card->alarm);

    if (!card->attached) {
        return;
    }

    if (!fn_804280EC(chan, 0, 0)) {
        result = CARD_RESULT_FATAL_ERROR;
        goto fatal;
    }

    if ((result = fn_8041AAD8(chan, &status)) >= 0 && (result = fn_8041ACB8(chan)) >= 0) {
        result = (status & 0x18) ? CARD_RESULT_IOERROR : CARD_RESULT_READY;
        if (result == CARD_RESULT_IOERROR && --card->retry > 0) {
            result = fn_8041AE08(chan);
            if (result >= 0) {
                return;
            }
            goto fatal;
        }
    }

    fn_804281E0(chan);

fatal:
    callback = card->exiCallback;
    if (callback) {
        card->exiCallback = NULL;
        callback(chan, result);
    }
}

/* __CARDTxHandler */
static void fn_8041A8EC(s32 chan, OSContext* context)
{
    CARDControl* card;
    CARDCallback callback;
    BOOL err;

    card = &lbl_806DCF20.block[chan];
    err = !fn_80427A58(chan);
    fn_804281E0(chan);
    callback = card->txCallback;
    if (callback) {
        card->txCallback = NULL;
        callback(chan, (!err && fn_80427630(chan)) ? CARD_RESULT_READY : CARD_RESULT_NOCARD);
    }
}

/* __CARDUnlockedHandler */
static void fn_8041A994(s32 chan, OSContext* context)
{
    CARDControl* card;
    CARDCallback callback;

    card = &lbl_806DCF20.block[chan];
    callback = card->unlockCallback;
    if (callback) {
        card->unlockCallback = NULL;
        callback(chan, fn_80427630(chan) ? CARD_RESULT_UNLOCKED : CARD_RESULT_NOCARD);
    }
}

/* __CARDEnableInterrupt */
s32 fn_8041AA18(s32 chan, BOOL enable)
{
    BOOL err;
    u32 cmd;

    if (!fn_8042792C(chan, 0, 4)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = enable ? 0x81010000 : 0x81000000;
    err = FALSE;
    err |= !fn_80426DC4(chan, &cmd, 2, 1, 0);
    err |= !fn_804271AC(chan);
    err |= !fn_80427A58(chan);
    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/* __CARDReadStatus */
s32 fn_8041AAD8(s32 chan, u8* status)
{
    BOOL err;
    u32 cmd;

    if (!fn_8042792C(chan, 0, 4)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = 0x83000000;
    err = FALSE;
    err |= !fn_80426DC4(chan, &cmd, 2, 1, 0);
    err |= !fn_804271AC(chan);
    err |= !fn_80426DC4(chan, status, 1, 0, 0);
    err |= !fn_804271AC(chan);
    err |= !fn_80427A58(chan);
    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/* __CARDReadVendorID */
s32 fn_8041ABC8(s32 chan, u16* id)
{
    BOOL err;
    u32 cmd;

    if (!fn_8042792C(chan, 0, 4)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = 0x85000000;
    err = FALSE;
    err |= !fn_80426DC4(chan, &cmd, 2, 1, 0);
    err |= !fn_804271AC(chan);
    err |= !fn_80426DC4(chan, id, 2, 0, 0);
    err |= !fn_804271AC(chan);
    err |= !fn_80427A58(chan);
    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/* __CARDClearStatus */
s32 fn_8041ACB8(s32 chan)
{
    BOOL err;
    u32 cmd;

    if (!fn_8042792C(chan, 0, 4)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = 0x89000000;
    err = FALSE;
    err |= !fn_80426DC4(chan, &cmd, 1, 1, 0);
    err |= !fn_804271AC(chan);
    err |= !fn_80427A58(chan);
    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/* TimeoutHandler */
static void fn_8041AD64(OSAlarm* alarm, OSContext* context)
{
    s32 chan;
    CARDControl* card;
    CARDCallback callback;

    for (chan = 0; chan < 2; ++chan) {
        card = &lbl_806DCF20.block[chan];
        if (alarm == &card->alarm) {
            break;
        }
    }

    if (!card->attached) {
        return;
    }

    fn_80427440(chan, 0);
    callback = card->exiCallback;
    if (callback) {
        card->exiCallback = NULL;
        callback(chan, CARD_RESULT_IOERROR);
    }
}

/* Retry */
static s32 fn_8041AE08(s32 chan)
{
    CARDControl* card;

    card = &lbl_806DCF20.block[chan];

    if (!fn_8042792C(chan, 0, 4)) {
        fn_804281E0(chan);
        return CARD_RESULT_NOCARD;
    }

    fn_80432568(&card->alarm);

    switch (card->cmd[0]) {
    case 0xF3:
        break;
    case 0xF2:
        fn_80432484(&card->alarm, OSMillisecondsToTicks(100), fn_8041AD64);
        break;
    case 0xF4:
        if (card->pageSize > 0x80) {
            fn_80432484(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->cBlock / 0x40), fn_8041AD64);
            break;
        }
    case 0xF1:
        fn_80432484(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->sectorSize / 0x2000), fn_8041AD64);
        break;
    }

    if (!fn_80427020(chan, card->cmd, card->cmdlen, 1)) {
        fn_80427A58(chan);
        fn_804281E0(chan);
        return CARD_RESULT_NOCARD;
    }

    if (card->cmd[0] == 0x52 && !fn_80427020(chan, (u8*)card->workArea + 0x200, card->latency, 1)) {
        fn_80427A58(chan);
        fn_804281E0(chan);
        return CARD_RESULT_NOCARD;
    }

    if (card->mode == 0xFFFFFFFF) {
        fn_80427A58(chan);
        fn_804281E0(chan);
        return CARD_RESULT_READY;
    }

    if (!fn_804270C0(chan, card->buffer, card->cmd[0] == 0x52 ? 0x200 : card->pageSize, card->mode, fn_8041A8EC)) {
        fn_80427A58(chan);
        fn_804281E0(chan);
        return CARD_RESULT_NOCARD;
    }

    return CARD_RESULT_READY;
}

/* UnlockedCallback */
static void fn_8041B0A8(s32 chan, s32 result)
{
    CARDCallback callback;
    CARDControl* card;

    card = &lbl_806DCF20.block[chan];
    if (result >= 0) {
        card->unlockCallback = (CARDCallback)fn_8041B0A8;
        if (!fn_804280EC(chan, 0, (EXICallback)fn_8041A994)) {
            result = CARD_RESULT_READY;
        } else {
            card->unlockCallback = NULL;
            result = fn_8041AE08(chan);
        }
    }

    if (result < 0) {
        switch (card->cmd[0]) {
        case 0x52:
            callback = card->txCallback;
            if (callback) {
                card->txCallback = NULL;
                callback(chan, result);
            }
            break;
        case 0xF3:
            break;
        case 0xF1:
        case 0xF2:
        case 0xF4:
            callback = card->exiCallback;
            if (callback) {
                card->exiCallback = NULL;
                callback(chan, result);
            }
            break;
        }
    }
}

/* __CARDStart */
s32 fn_8041B1B8(s32 chan, CARDCallback txCallback, CARDCallback exiCallback)
{
    BOOL enabled;
    CARDControl* card;
    s32 result;

    enabled = OSDisableInterrupts();
    card = &lbl_806DCF20.block[chan];
    if (!card->attached) {
        result = CARD_RESULT_NOCARD;
    } else {
        if (txCallback) {
            card->txCallback = txCallback;
        }
        if (exiCallback) {
            card->exiCallback = exiCallback;
        }

        card->unlockCallback = (CARDCallback)fn_8041B0A8;
        if (!fn_804280EC(chan, 0, (EXICallback)fn_8041A994)) {
            result = CARD_RESULT_BUSY;
        } else {
            card->unlockCallback = NULL;

            if (!fn_8042792C(chan, 0, 4)) {
                fn_804281E0(chan);
                result = CARD_RESULT_NOCARD;
            } else {
                fn_80432568(&card->alarm);

                switch (card->cmd[0]) {
                case 0xF3:
                    break;
                case 0xF2:
                    fn_80432484(&card->alarm, OSMillisecondsToTicks(100), fn_8041AD64);
                    break;
                case 0xF4:
                    if (card->pageSize > 0x80) {
                        fn_80432484(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->cBlock / 0x40), fn_8041AD64);
                        break;
                    }
                case 0xF1:
                    fn_80432484(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->sectorSize / 0x2000), fn_8041AD64);
                    break;
                }

                result = CARD_RESULT_READY;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return result;
}

/* __CARDReadSegment */
s32 fn_8041B3DC(s32 chan, CARDCallback callback)
{
    CARDControl* card;
    s32 result;

    card = &lbl_806DCF20.block[chan];
    card->cmd[0] = 0x52;
    card->cmd[1] = (u8)((card->addr >> 17) & 0x7F);
    card->cmd[2] = (u8)(card->addr >> 9);
    card->cmd[3] = (u8)((card->addr >> 7) & 3);
    card->cmd[4] = (u8)(card->addr & 0x7F);
    card->cmdlen = 5;
    card->mode = 0;
    card->retry = 0;

    result = fn_8041B1B8(chan, callback, 0);
    if (result == CARD_RESULT_BUSY) {
        return CARD_RESULT_READY;
    }
    if (result >= 0) {
        if (!fn_80427020(chan, card->cmd, card->cmdlen, 1)
            || !fn_80427020(chan, (u8*)card->workArea + 0x200, card->latency, 1)
            || !fn_804270C0(chan, card->buffer, 0x200, card->mode, fn_8041A8EC)) {
            card->txCallback = 0;
            fn_80427A58(chan);
            fn_804281E0(chan);
            return CARD_RESULT_NOCARD;
        }
        result = CARD_RESULT_READY;
    }

    return result;
}

/* __CARDWritePage
 * near-miss: same length; the `addi r5,r4,0` (exiCallback argument) is scheduled first instead of after `addi r3,r30,0`;
 * all 6 orders of the last three stores tried. */
s32 fn_8041B510(s32 chan, CARDCallback callback)
{
    CARDControl* card;
    s32 result;

    card = &lbl_806DCF20.block[chan];
    card->cmd[0] = 0xF2;
    if (card->pageSize > 0x80) {
        card->cmd[1] = (u8)(((card->addr >> 17) & 0x7F) | 0x80);
    } else {
        card->cmd[1] = (u8)((card->addr >> 17) & 0x7F);
    }
    card->cmd[2] = (u8)(card->addr >> 9);
    card->cmd[3] = (u8)((card->addr >> 7) & 3);
    card->cmd[4] = (u8)(card->addr & 0x7F);
    card->cmdlen = 5;
    card->mode = 1;
    card->retry = 3;

    result = fn_8041B1B8(chan, 0, callback);
    if (result == CARD_RESULT_BUSY) {
        return CARD_RESULT_READY;
    }
    if (result >= 0) {
        if (!fn_80427020(chan, card->cmd, card->cmdlen, 1)
            || !fn_804270C0(chan, card->buffer, card->pageSize, card->mode, fn_8041A8EC)) {
            card->exiCallback = 0;
            fn_80427A58(chan);
            fn_804281E0(chan);
            return CARD_RESULT_NOCARD;
        }
        result = CARD_RESULT_READY;
    }

    return result;
}

/* __CARDEraseSector
 * near-miss: same length; the cmd[2] byte temp lands in r0 instead of r3 (all 120 orders of the five stores tried). */
s32 fn_8041B64C(s32 chan, u32 addr, CARDCallback callback)
{
    CARDControl* card;
    s32 result;

    card = &lbl_806DCF20.block[chan];

    if (card->pageSize > 0x80) {
        if (callback) {
            callback(chan, CARD_RESULT_READY);
        }
        return CARD_RESULT_READY;
    }

    card->cmd[0] = 0xF1;
    card->cmd[1] = (u8)((addr >> 17) & 0x7F);
    card->cmd[2] = (u8)(addr >> 9);
    card->cmdlen = 3;
    card->mode = 0xFFFFFFFF;
    card->retry = 3;

    result = fn_8041B1B8(chan, 0, callback);
    if (result == CARD_RESULT_BUSY) {
        result = CARD_RESULT_READY;
    } else if (result >= 0) {
        if (!fn_80427020(chan, card->cmd, card->cmdlen, 1)) {
            card->exiCallback = 0;
            result = CARD_RESULT_NOCARD;
        } else {
            result = CARD_RESULT_READY;
        }

        fn_80427A58(chan);
        fn_804281E0(chan);
    }

    return result;
}

/* CARDInit
 * near-miss: 45 vs 43; retail keeps &__CARDBlock in the callee-saved loop pointer (r30) from the diskID tests on, ours
 * re-forms it after them (early-return, local-pointer and if-body spellings tried). */
void fn_8041B75C(void)
{
    s32 chan;

    if (lbl_806DCF20.block[0].diskID && lbl_806DCF20.block[1].diskID) {
        return;
    }

    lbl_806EF600 = fn_80434DE8();
    OSRegisterVersion(lbl_806EF170);
    DSPInit();
    fn_804321CC();
    for (chan = 0; chan < 2; ++chan) {
        CARDControl* card = &lbl_806DCF20.block[chan];
        card->result = CARD_RESULT_NOCARD;
        fn_80437434(&card->threadQueue);
        fn_80432224(&card->alarm);
    }
    fn_8041B810((const DVDDiskID*)0x80000000);
    OSRegisterResetFunction(&lbl_806334A8);
}

/* __CARDGetFontEncode */
u16 fn_8041B808(void)
{
    return lbl_806EF600;
}

/* __CARDSetDiskID */
void fn_8041B810(const DVDDiskID* diskID)
{
    struct CardBss* b = &lbl_806DCF20;

    b->block[0].diskID = diskID ? diskID : &b->none;
    b->block[1].diskID = diskID ? diskID : &b->none;
}

/* __CARDGetControlBlock */
s32 fn_8041B848(s32 chan, CARDControl** pcard)
{
    BOOL enabled;
    s32 result;
    CARDControl* card;

    card = &lbl_806DCF20.block[chan];
    if (chan < 0 || chan >= 2 || card->diskID == NULL) {
        return CARD_RESULT_FATAL_ERROR;
    }

    enabled = OSDisableInterrupts();
    if (!card->attached) {
        result = CARD_RESULT_NOCARD;
    } else if (card->result == CARD_RESULT_BUSY) {
        result = CARD_RESULT_BUSY;
    } else {
        card->result = CARD_RESULT_BUSY;
        result = CARD_RESULT_READY;
        card->apiCallback = NULL;
        *pcard = card;
    }
    OSRestoreInterrupts(enabled);

    return result;
}

/* __CARDPutControlBlock */
s32 fn_8041B900(CARDControl* card, s32 result)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (card->attached) {
        card->result = result;
    } else if (card->result == CARD_RESULT_BUSY) {
        card->result = result;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

/* CARDFreeBlocks */
s32 fn_8041B964(s32 chan, s32* byteNotUsed, s32* filesNotUsed)
{
    CARDControl* card;
    u16* fat;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    u16 fileNo;

    result = fn_8041B848(chan, &card);
    if (result < 0) {
        return result;
    }

    fat = __CARDGetFatBlock(card);
    dir = __CARDGetDirBlock(card);
    if (fat == NULL || dir == NULL) {
        return fn_8041B900(card, CARD_RESULT_BROKEN);
    }

    if (byteNotUsed) {
        *byteNotUsed = (s32)(card->sectorSize * fat[3]);
    }

    if (filesNotUsed) {
        *filesNotUsed = 0;
        for (fileNo = 0; fileNo < 127; fileNo++) {
            ent = &dir[fileNo];
            if (ent->fileName[0] == 0xFF) {
                (*filesNotUsed)++;
            }
        }
    }

    return fn_8041B900(card, CARD_RESULT_READY);
}

/* CARDGetSectorSize */
s32 fn_8041BAB4(s32 chan, u32* size)
{
    CARDControl* card;
    s32 result;

    result = fn_8041B848(chan, &card);
    if (result < 0) {
        return result;
    }

    *size = card->sectorSize;
    return fn_8041B900(card, CARD_RESULT_READY);
}

static inline s32 CardGetResultCode(s32 chan)
{
    if (chan < 0 || chan >= 2) {
        return CARD_RESULT_FATAL_ERROR;
    }
    return lbl_806DCF20.block[chan].result;
}

/* __CARDSync */
s32 fn_8041BB38(s32 chan)
{
    CARDControl* card;
    s32 result;
    BOOL enabled;

    card = &lbl_806DCF20.block[chan];
    enabled = OSDisableInterrupts();
    while ((result = CardGetResultCode(chan)) == CARD_RESULT_BUSY) {
        fn_804382CC(&card->threadQueue);
    }
    OSRestoreInterrupts(enabled);
    return result;
}

extern s32 fn_8041DC98(s32 chan);

s32 fn_8041BBD0(s32 mode)
{
    if (mode == 0 && (fn_8041DC98(0) == -1 || fn_8041DC98(1) == -1)) {
        return 0;
    }
    return 1;
}

BOOL fn_8041BC20(BOOL enable)
{
    u16 prev = lbl_806EF602;
    lbl_806EF602 = enable ? 1 : 0;
    return prev ? TRUE : FALSE;
}

BOOL fn_8041BC54(void)
{
    return lbl_806EF602 ? TRUE : FALSE;
}
