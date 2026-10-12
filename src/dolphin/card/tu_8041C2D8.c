/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x8041C2D8-0x8041E534 (code-only unit: CARDCheck.c, CARDMount.c and CARDFormat.c, 18 functions).
 * File boundaries from the inlining pattern: CARDCheck.c 0x8041C2D8-0x8041D240, CARDMount.c 0x8041D240-0x8041DD44,
 * CARDFormat.c 0x8041DD44-0x8041E534 (__CARDCheckSum is inlined only inside CARDCheck.c).
 * Every data object is extern by its lbl_ name.
 * Reference: Nintendo Dolphin SDK 2004 (structure and field names as published in doldecomp/dolsdk2004);
 * callees that symbols.txt still names fn_<addr> are declared here under that name with the SDK name in a comment.
 */
#include <dolphin/card.h>
#include <string.h>

#include "__card.h"

/* EXI / OS */
extern BOOL fn_804280EC(s32 chan, u32 dev, EXICallback cb); /* EXILock */
extern BOOL fn_804281E0(s32 chan);                           /* EXIUnlock */
extern s32 fn_804276B0(s32 chan);                            /* EXIProbeEx */
extern BOOL fn_80427764(s32 chan, EXICallback cb);           /* EXIAttach */
extern BOOL fn_80427870(s32 chan);                           /* EXIDetach */
extern u32 fn_804282BC(s32 chan);                            /* EXIGetState */
extern s32 fn_804282FC(s32 chan, u32 dev, u32* id);          /* EXIGetID */
extern EXICallback fn_80427440(s32 chan, EXICallback cb);    /* EXISetExiCallback */
extern BOOL fn_80427630(s32 chan);                           /* EXIProbe */
extern void fn_80432568(OSAlarm* alarm);                     /* OSCancelAlarm */
extern void fn_80432FA8(void* addr, u32 nBytes);             /* DCInvalidateRange */
extern void fn_80433004(void* addr, u32 nBytes);             /* DCStoreRange */
extern void* fn_80436A9C(void);                              /* __OSLockSram */
extern void* fn_80436AF8(void);                              /* __OSLockSramEx */
extern void fn_80436E90(BOOL commit);                        /* __OSUnlockSram */
extern void fn_80436EB4(BOOL commit);                        /* __OSUnlockSramEx */
extern OSTime fn_80438628(void);                             /* OSGetTime */

/* CARDBios.c (tu_8041A6C4) */
extern s32 fn_8041B848(s32 chan, CARDControl** pcard);             /* __CARDGetControlBlock */
extern s32 fn_8041B900(CARDControl* card, s32 result);             /* __CARDPutControlBlock */
extern s32 fn_8041AA18(s32 chan, BOOL enable);                     /* __CARDEnableInterrupt */
extern s32 fn_8041AAD8(s32 chan, u8* status);                      /* __CARDReadStatus */
extern s32 fn_8041ABC8(s32 chan, u16* id);                         /* __CARDReadVendorID */
extern s32 fn_8041ACB8(s32 chan);                                  /* __CARDClearStatus */
extern s32 fn_8041B64C(s32 chan, u32 addr, CARDCallback callback); /* __CARDEraseSector */
extern u16 fn_8041B808(void);                                      /* __CARDGetFontEncode */
extern BOOL fn_8041BC54(void);
extern void fn_8041A6C4(s32 chan, s32 result);         /* __CARDDefaultApiCallback */
extern void fn_8041A6FC(s32 chan, OSContext* context); /* __CARDExtHandler */
extern void fn_8041A7D4(s32 chan, OSContext* context); /* __CARDExiHandler */
extern void fn_8041A994(s32 chan, OSContext* context); /* __CARDUnlockedHandler (static there) */
extern void fn_8041A6C8(s32 chan, s32 result);         /* __CARDSyncCallback */
extern s32 fn_8041BB38(s32 chan);                      /* __CARDSync */

struct CardBss {
    CARDControl block[2];
    DVDDiskID none;
};
extern struct CardBss lbl_806DCF20; /* __CARDBlock */
extern s32 lbl_806334B8[8];         /* SectorSizeTable */
extern s32 lbl_806334D8[8];         /* LatencyTable */
extern u16 lbl_806EF178;            /* __CARDVendorID */

static void fn_8041D8DC(s32 chan, s32 result);
static void fn_8041DBFC(s32 chan, s32 result);
static void fn_8041DD44(s32 chan, s32 result);
static s32 fn_8041D488(s32 chan);

/* __CARDCheckSum */
void fn_8041C2D8(void* ptr, int length, u16* checksum, u16* checksumInv)
{
    u16* p;
    int i;

    length /= sizeof(u16);
    *checksum = *checksumInv = 0;
    for (i = 0, p = ptr; i < length; i++, p++) {
        *checksum += *p;
        *checksumInv += ~*p;
    }
    if (*checksum == 0xFFFF) {
        *checksum = 0;
    }
    if (*checksumInv == 0xFFFF) {
        *checksumInv = 0;
    }
}

/* VerifyID
 * `s64 >> 16` is the MWCC runtime helper __shr2i, which symbols.txt still calls fn_80406CCC (it tail-jumps to the
 * libgcc arithmetic shift). */
static s32 fn_8041C488(CARDControl* card)
{
    CARDID* id;
    u16 checkSum;
    u16 checkSumInv;
    OSSramEx* sram;
    s64 rand;
    int i;

    id = (CARDID*)card->workArea;

    if (id->deviceID != 0 || id->size != card->size) {
        return CARD_RESULT_BROKEN;
    }

    fn_8041C2D8(id, sizeof(CARDID) - sizeof(u32), &checkSum, &checkSumInv);
    if (id->checkSum != checkSum || id->checkSumInv != checkSumInv) {
        return CARD_RESULT_BROKEN;
    }

    rand = *(u64*)&id->serial[12];
    sram = fn_80436AF8();
    for (i = 0; i < 12; i++) {
        rand = (rand * 1103515245 + 12345) >> 16;
        if (id->serial[i] != (u8)(rand + sram->flashID[card - lbl_806DCF20.block][i])) {
            fn_80436EB4(FALSE);
            return CARD_RESULT_BROKEN;
        }
        rand = ((rand * 1103515245 + 12345) >> 16) & 0x7FFF;
    }
    fn_80436EB4(FALSE);

    if (id->encode != fn_8041B808()) {
        return CARD_RESULT_ENCODING;
    }
    return CARD_RESULT_READY;
}

/* VerifyDir */
static s32 fn_8041C70C(CARDControl* card, int* outCurrent)
{
    CARDDir* dir[2];
    CARDDirCheck* check[2];
    u16 checkSum;
    u16 checkSumInv;
    int errors;
    int current;
    int i;

    errors = 0;
    for (i = 0, current = 0; i < 2; i++) {
        dir[i] = (CARDDir*)((u8*)card->workArea + (1 + i) * CARD_SYSTEM_BLOCK_SIZE);
        check[i] = CARDGetDirCheck(dir[i]);
        fn_8041C2D8(dir[i], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &checkSum, &checkSumInv);
        if (check[i]->checkSum != checkSum || check[i]->checkSumInv != checkSumInv) {
            ++errors;
            current = i;
            card->currentDir = 0;
        }
    }

    if (0 == errors) {
        if (card->currentDir == 0) {
            if (check[0]->checkCode - check[1]->checkCode < 0) {
                current = 0;
            } else {
                current = 1;
            }
            card->currentDir = dir[current];
            memcpy(dir[current], dir[current ^ 1], CARD_SYSTEM_BLOCK_SIZE);
        } else {
            current = (card->currentDir == dir[0]) ? 0 : 1;
        }
    }

    if (outCurrent) {
        *outCurrent = current;
    }
    return errors;
}

/* VerifyFAT */
static s32 fn_8041C94C(CARDControl* card, int* outCurrent)
{
    u16* fat[2];
    u16* fatp;
    u16 nBlock;
    u16 cFree;
    int i;
    u16 checkSum;
    u16 checkSumInv;
    int errors;
    int current;

    errors = 0;
    current = 0;
    for (i = 0; i < 2; i++) {
        fatp = fat[i] = (u16*)((u8*)card->workArea + (3 + i) * CARD_SYSTEM_BLOCK_SIZE);
        fn_8041C2D8(&fatp[CARD_FAT_CHECKCODE], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &checkSum, &checkSumInv);
        if (fatp[CARD_FAT_CHECKSUM] != checkSum || fatp[CARD_FAT_CHECKSUMINV] != checkSumInv) {
            ++errors;
            current = i;
            card->currentFat = 0;
            continue;
        }

        cFree = 0;
        for (nBlock = CARD_NUM_SYSTEM_BLOCK; nBlock < card->cBlock; nBlock++) {
            if (fatp[nBlock] == CARD_FAT_AVAIL) {
                cFree++;
            }
        }
        if (cFree != fatp[CARD_FAT_FREEBLOCKS]) {
            ++errors;
            current = i;
            card->currentFat = 0;
            continue;
        }
    }

    if (0 == errors) {
        if (card->currentFat == 0) {
            if ((s16)fat[0][CARD_FAT_CHECKCODE] - (s16)fat[1][CARD_FAT_CHECKCODE] < 0) {
                current = 0;
            } else {
                current = 1;
            }
            card->currentFat = fat[current];
            memcpy(fat[current], fat[current ^ 1], CARD_SYSTEM_BLOCK_SIZE);
        } else {
            current = (card->currentFat == fat[0]) ? 0 : 1;
        }
    }

    if (outCurrent) {
        *outCurrent = current;
    }
    return errors;
}

/* __CARDVerify */
s32 fn_8041CBD0(CARDControl* card)
{
    s32 result;
    int errors;

    result = fn_8041C488(card);
    if (result < 0) {
        return result;
    }

    errors = fn_8041C70C(card, 0);
    errors += fn_8041C94C(card, 0);
    switch (errors) {
    case 0:
        return CARD_RESULT_READY;
    case 1:
        return CARD_RESULT_BROKEN;
    default:
        return CARD_RESULT_BROKEN;
    }
}

/* CARDCheckExAsync */
static s32 fn_8041CC5C(s32 chan, s32* xferBytes, CARDCallback callback)
{
    CARDControl* card;
    CARDDir* dir[2];
    u16* map;
    u16* fat[2];
    u16 cFree;
    u16 nBlock;
    u16 iBlock;
    int fileNo;
    int errors;
    int currentFat;
    int currentDir;
    int updateFat = FALSE;
    int updateDir = FALSE;
    int updateOrphan = FALSE;
    s32 result;

    if (xferBytes) {
        *xferBytes = 0;
    }

    result = fn_8041B848(chan, &card);
    if (result < 0) {
        return result;
    }

    result = fn_8041C488(card);
    if (result < 0) {
        return fn_8041B900(card, result);
    }

    errors = fn_8041C70C(card, &currentDir);
    errors += fn_8041C94C(card, &currentFat);
    if (1 < errors) {
        return fn_8041B900(card, CARD_RESULT_BROKEN);
    }

    dir[0] = (CARDDir*)((u8*)card->workArea + 0x2000);
    fat[0] = (u16*)((u8*)card->workArea + 0x6000);
    dir[1] = (CARDDir*)((u8*)card->workArea + 0x4000);
    fat[1] = (u16*)((u8*)card->workArea + 0x8000);

    switch (errors) {
    case 0:
        break;
    case 1:
        if (card->currentDir == 0) {
            card->currentDir = dir[currentDir];
            memcpy(dir[currentDir], dir[currentDir ^ 1], CARD_SYSTEM_BLOCK_SIZE);
            updateDir = TRUE;
        } else {
            card->currentFat = fat[currentFat];
            memcpy(fat[currentFat], fat[currentFat ^ 1], CARD_SYSTEM_BLOCK_SIZE);
            updateFat = TRUE;
        }
        break;
    }

    map = fat[currentFat ^ 1];
    memset(map, 0, CARD_SYSTEM_BLOCK_SIZE);
    for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
        CARDDir* ent;

        ent = &card->currentDir[fileNo];
        if (ent->gameName[0] == 0xFF) {
            continue;
        }

        for (iBlock = ent->startBlock, nBlock = 0; iBlock != 0xFFFF && nBlock < ent->length; iBlock = card->currentFat[iBlock], ++nBlock) {
            if (!CARDIsValidBlockNo(card, iBlock) || 1 < ++map[iBlock]) {
                return fn_8041B900(card, CARD_RESULT_BROKEN);
            }
        }

        if (nBlock != ent->length || iBlock != 0xFFFF) {
            return fn_8041B900(card, CARD_RESULT_BROKEN);
        }
    }

    cFree = 0;
    for (nBlock = CARD_NUM_SYSTEM_BLOCK; nBlock < card->cBlock; nBlock++) {
        u16 fatBlock = card->currentFat[nBlock];
        if (map[nBlock] == 0) {
            if (fatBlock != CARD_FAT_AVAIL) {
                card->currentFat[nBlock] = CARD_FAT_AVAIL;
                updateOrphan = TRUE;
            }
            cFree++;
        } else if (!CARDIsValidBlockNo(card, fatBlock) && fatBlock != 0xFFFF) {
            return fn_8041B900(card, CARD_RESULT_BROKEN);
        }
    }
    if (cFree != card->currentFat[CARD_FAT_FREEBLOCKS]) {
        card->currentFat[CARD_FAT_FREEBLOCKS] = cFree;
        updateOrphan = TRUE;
    }

    if (updateOrphan) {
        fn_8041C2D8(&card->currentFat[CARD_FAT_CHECKCODE], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32),
                    &card->currentFat[CARD_FAT_CHECKSUM], &card->currentFat[CARD_FAT_CHECKSUMINV]);
    }

    memcpy(fat[currentFat ^ 1], fat[currentFat], CARD_SYSTEM_BLOCK_SIZE);

    if (updateDir) {
        if (xferBytes) {
            *xferBytes = CARD_SYSTEM_BLOCK_SIZE;
        }
        return __CARDUpdateDir(chan, callback);
    }
    if (updateFat | updateOrphan) {
        if (xferBytes) {
            *xferBytes = CARD_SYSTEM_BLOCK_SIZE;
        }
        return __CARDUpdateFatBlock(chan, card->currentFat, callback);
    }

    fn_8041B900(card, CARD_RESULT_READY);
    if (callback) {
        BOOL enabled = OSDisableInterrupts();
        callback(chan, CARD_RESULT_READY);
        OSRestoreInterrupts(enabled);
    }
    return CARD_RESULT_READY;
}

/* CARDCheckEx */
static s32 fn_CheckEx(s32 chan, s32* xferBytes)
{
    s32 result;

    result = fn_8041CC5C(chan, xferBytes, fn_8041A6C8);
    if (result >= 0) {
        if (xferBytes == NULL) {
            return result;
        }
        result = fn_8041BB38(chan);
    }
    return result;
}

/* CARDCheck */
s32 fn_8041D1EC(s32 chan)
{
    s32 xferBytes;

    return fn_CheckEx(chan, &xferBytes);
}

/* IsCard */
static BOOL fn_8041D240(u32 id)
{
    u32 size;
    s32 sectorSize;

    if ((id & 0xFFFF0000) && (id != 0x80000004 || lbl_806EF178 == 0xFFFF)) {
        return FALSE;
    }

    if (id & 3) {
        return FALSE;
    }

    size = id & 0xFC;
    switch (size) {
    case 4:
    case 8:
    case 16:
    case 32:
    case 64:
    case 128:
        break;
    default:
        return FALSE;
    }

    sectorSize = lbl_806334B8[(id & 0x00003800) >> 11];
    if (sectorSize == 0) {
        return FALSE;
    }

    if ((size * 1024 * 1024 / 8) / sectorSize < 8) {
        return FALSE;
    }
    return TRUE;
}

/* CARDProbeEx */
s32 fn_8041D30C(s32 chan, s32* memSize, s32* sectorSize)
{
    CARDControl* card;
    u32 id;
    BOOL enabled;
    s32 result;
    int probe;

    if (chan < 0 || 2 <= chan) {
        return CARD_RESULT_FATAL_ERROR;
    }

    if (*(u8*)0x800030E3 & 0x80) {
        return CARD_RESULT_NOCARD;
    }

    card = &lbl_806DCF20.block[chan];

    enabled = OSDisableInterrupts();
    probe = fn_804276B0(chan);
    if (probe == -1) {
        result = CARD_RESULT_NOCARD;
    } else if (probe == 0) {
        result = CARD_RESULT_BUSY;
    } else if (card->attached) {
        if (card->mountStep < 1) {
            result = CARD_RESULT_BUSY;
        } else {
            if (memSize) {
                *memSize = card->size;
            }
            if (sectorSize) {
                *sectorSize = card->sectorSize;
            }
            result = CARD_RESULT_READY;
        }
    } else if ((fn_804282BC(chan) & 0x08)) {
        result = CARD_RESULT_WRONGDEVICE;
    } else if (!fn_804282FC(chan, 0, &id)) {
        result = CARD_RESULT_BUSY;
    } else if (fn_8041D240(id)) {
        if (memSize) {
            *memSize = (s32)(id & 0xFC);
        }
        if (sectorSize) {
            *sectorSize = lbl_806334B8[(id & 0x00003800) >> 11];
        }
        result = CARD_RESULT_READY;
    } else {
        result = CARD_RESULT_WRONGDEVICE;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

/* DoMount */
static s32 fn_8041D488(s32 chan)
{
    CARDControl* card;
    u32 id;
    u8 status;
    s32 result;
    OSSramEx* sram;
    int i;
    u8 checkSum;
    int step;

    card = &lbl_806DCF20.block[chan];

    if (card->mountStep == 0) {
        if (fn_804282FC(chan, 0, &id) == 0) {
            result = CARD_RESULT_NOCARD;
        } else if (fn_8041D240(id)) {
            result = CARD_RESULT_READY;
        } else {
            result = CARD_RESULT_WRONGDEVICE;
        }
        if (result < 0) {
            goto error;
        }

        card->cid = id;
        card->size = (u16)(id & 0xFC);
        card->sectorSize = lbl_806334B8[(id & 0x00003800) >> 11];
        card->cBlock = (u16)((card->size * 1024 * 1024 / 8) / card->sectorSize);
        card->latency = lbl_806334D8[(id & 0x00000700) >> 8];

        result = fn_8041ABC8(chan, &card->vendorID);
        if (result < 0) {
            goto error;
        }

        if (fn_8041BC54() && (card->vendorID >> 8) == 0xEC) {
            card->pageSize = 512;
        } else {
            card->pageSize = 128;
        }

        result = fn_8041ACB8(chan);
        if (result < 0) {
            goto error;
        }

        result = fn_8041AAD8(chan, &status);
        if (result < 0) {
            goto error;
        }

        if (!fn_80427630(chan)) {
            result = CARD_RESULT_NOCARD;
            goto error;
        }

        if (!(status & 0x40)) {
            result = __CARDUnlock(chan, card->id);
            if (result < 0) {
                goto error;
            }

            sram = fn_80436AF8();
            checkSum = 0;
            for (i = 0; i < 12; i++) {
                sram->flashID[chan][i] = card->id[i];
                checkSum += card->id[i];
            }
            sram->flashIDCheckSum[chan] = (u8)~checkSum;
            fn_80436EB4(TRUE);

            return result;
        } else {
            card->mountStep = 1;

            sram = fn_80436AF8();
            checkSum = 0;
            for (i = 0; i < 12; i++) {
                checkSum += sram->flashID[chan][i];
            }
            fn_80436EB4(FALSE);
            if (sram->flashIDCheckSum[chan] != (u8)~checkSum) {
                result = CARD_RESULT_IOERROR;
                goto error;
            }
        }
    }

    if (card->mountStep == 1) {
        if (card->cid == 0x80000004) {
            u16 vendorID;

            sram = fn_80436AF8();
            vendorID = *(u16*)sram->flashID[chan];
            fn_80436EB4(FALSE);
            if (lbl_806EF178 == 0xFFFF || vendorID != lbl_806EF178) {
                result = CARD_RESULT_WRONGDEVICE;
                goto error;
            }
        }

        card->mountStep = 2;

        result = fn_8041AA18(chan, TRUE);
        if (result < 0) {
            goto error;
        }

        fn_80427440(chan, fn_8041A7D4);
        fn_804281E0(chan);

        fn_80432FA8(card->workArea, CARD_WORKAREA_SIZE);
    }

    step = card->mountStep - 2;
    result = __CARDRead(chan, (u32)card->sectorSize * step, CARD_SYSTEM_BLOCK_SIZE, (u8*)card->workArea + (CARD_SYSTEM_BLOCK_SIZE * step), fn_8041D8DC);
    if (result < 0) {
        fn_8041B900(card, result);
    }
    return result;

error:
    fn_804281E0(chan);
    fn_8041DBFC(chan, result);
    return result;
}

/* __CARDMountCallback */
static void fn_8041D8DC(s32 chan, s32 result)
{
    CARDControl* card;
    CARDCallback callback;

    card = &lbl_806DCF20.block[chan];

    switch (result) {
    case CARD_RESULT_READY:
        if (++card->mountStep < CARD_MAX_MOUNT_STEP) {
            result = fn_8041D488(chan);
            if (0 <= result) {
                return;
            }
        } else {
            result = __CARDVerify(card); /* out of line in retail (CARDMount.c is its own TU); fn_8041CBD0 in symbols.txt */
        }
        break;
    case CARD_RESULT_UNLOCKED:
        card->unlockCallback = fn_8041D8DC;
        if (!fn_804280EC(chan, 0, fn_8041A994)) {
            return;
        }
        card->unlockCallback = 0;
        result = fn_8041D488(chan);
        if (0 <= result) {
            return;
        }
        break;
    case CARD_RESULT_IOERROR:
    case CARD_RESULT_NOCARD:
        fn_8041DBFC(chan, result);
        break;
    }

    callback = card->apiCallback;
    card->apiCallback = 0;
    fn_8041B900(card, result);
    callback(chan, result);
}

/* CARDMountAsync */
static s32 fn_8041DA14(s32 chan, void* workArea, CARDCallback detachCallback, CARDCallback attachCallback)
{
    CARDControl* card;
    BOOL enabled;

    if (chan < 0 || 2 <= chan) {
        return CARD_RESULT_FATAL_ERROR;
    }

    if (*(u8*)0x800030E3 & 0x80) {
        return CARD_RESULT_NOCARD;
    }

    card = &lbl_806DCF20.block[chan];

    enabled = OSDisableInterrupts();
    if (card->result == CARD_RESULT_BUSY) {
        OSRestoreInterrupts(enabled);
        return CARD_RESULT_BUSY;
    }

    if (!card->attached && (fn_804282BC(chan) & 0x08)) {
        OSRestoreInterrupts(enabled);
        return CARD_RESULT_WRONGDEVICE;
    }

    card->result = CARD_RESULT_BUSY;
    card->workArea = workArea;
    card->extCallback = detachCallback;
    card->apiCallback = attachCallback ? attachCallback : fn_8041A6C4;
    card->exiCallback = 0;

    if (!card->attached && !fn_80427764(chan, fn_8041A6FC)) {
        card->result = CARD_RESULT_NOCARD;
        OSRestoreInterrupts(enabled);
        return CARD_RESULT_NOCARD;
    }

    card->mountStep = 0;
    card->attached = TRUE;

    fn_80427440(chan, 0);
    fn_80432568(&card->alarm);

    card->currentDir = 0;
    card->currentFat = 0;

    OSRestoreInterrupts(enabled);

    card->unlockCallback = fn_8041D8DC;
    if (!fn_804280EC(chan, 0, fn_8041A994)) {
        return CARD_RESULT_READY;
    }

    card->unlockCallback = 0;
    return fn_8041D488(chan);
}

/* CARDMount */
s32 fn_8041DBB4(s32 chan, void* workArea, CARDCallback detachCallback)
{
    s32 result;

    result = fn_8041DA14(chan, workArea, detachCallback, fn_8041A6C8);
    if (result < 0) {
        return result;
    }
    return fn_8041BB38(chan);
}

/* DoUnmount */
static void fn_8041DBFC(s32 chan, s32 result)
{
    CARDControl* card;
    BOOL enabled;

    card = &lbl_806DCF20.block[chan];
    enabled = OSDisableInterrupts();
    if (card->attached) {
        fn_80427440(chan, 0);
        fn_80427870(chan);
        fn_80432568(&card->alarm);
        card->attached = FALSE;
        card->result = result;
        card->mountStep = 0;
    }
    OSRestoreInterrupts(enabled);
}

/* CARDUnmount */
s32 fn_8041DC98(s32 chan)
{
    CARDControl* card;
    s32 result;

    result = fn_8041B848(chan, &card);
    if (result < 0) {
        return result;
    }
    fn_8041DBFC(chan, CARD_RESULT_NOCARD);
    return CARD_RESULT_READY;
}

/* FormatCallback */
static void fn_8041DD44(s32 chan, s32 result)
{
    CARDControl* card;
    CARDCallback callback;
    int fmtStep;

    card = &lbl_806DCF20.block[chan];
    if (0 <= result) {
        card->formatStep++;
        fmtStep = card->formatStep;
        if (fmtStep < CARD_NUM_SYSTEM_BLOCK) {
            result = fn_8041B64C(chan, card->sectorSize * fmtStep, fn_8041DD44);
            if (result >= 0) {
                return;
            }
        } else if (fmtStep < 2 * CARD_NUM_SYSTEM_BLOCK) {
            int idx = fmtStep - CARD_NUM_SYSTEM_BLOCK;
            result = __CARDWrite(chan, card->sectorSize * idx, CARD_SYSTEM_BLOCK_SIZE, (u8*)card->workArea + (CARD_SYSTEM_BLOCK_SIZE * idx), fn_8041DD44);
            if (result >= 0) {
                return;
            }
        } else {
            card->currentDir = (CARDDir*)((u8*)card->workArea + 0x2000);
            memcpy(card->currentDir, (u8*)card->workArea + 0x4000, CARD_SYSTEM_BLOCK_SIZE);
            card->currentFat = (u16*)((u8*)card->workArea + 0x6000);
            memcpy(card->currentFat, (u8*)card->workArea + 0x8000, CARD_SYSTEM_BLOCK_SIZE);
        }
    }

    callback = card->apiCallback;
    card->apiCallback = 0;
    fn_8041B900(card, result);
    callback(chan, result);
}

/* __CARDFormatRegionAsync
 * near-miss: the code is the same except that fn_8041C2D8 (__CARDCheckSum) is inlined five times here (710 vs 406
 * instructions). Retail calls it out of line: CARDFormat.c is its own translation unit and only sees the extern
 * declaration. Needs a split at 0x8041DD44 (and CARDMount.c at 0x8041D240) to match. */
static s32 fn_8041DE88(s32 chan, u16 encode, CARDCallback callback)
{
    CARDControl* card;
    CARDID* id;
    CARDDir* dir;
    CARDDirCheck* check;
    u16* fat;
    s16 i;
    s32 result;
    OSSram* sram;
    OSTime time;
    u8* flashID;
    s64 rand;
    u16 viDimming;

    result = fn_8041B848(chan, &card);
    if (result < 0) {
        return result;
    }

    id = (CARDID*)card->workArea;
    memset(id, 0xFF, CARD_SYSTEM_BLOCK_SIZE);
    viDimming = *(u16*)0xCC00206E;
    id->encode = encode;
    sram = fn_80436A9C();
    *(u32*)&id->serial[20] = sram->counterBias;
    *(u32*)&id->serial[24] = sram->language;
    fn_80436E90(FALSE);
    time = fn_80438628();
    rand = time;
    flashID = (u8*)fn_80436AF8() + chan * 12;
    for (i = 0; i < 12; i++) {
        rand = (rand * 1103515245 + 12345) >> 16;
        id->serial[i] = (u8)(flashID[i] + rand);
        rand = ((rand * 1103515245 + 12345) >> 16) & 0x7FFF;
    }
    fn_80436EB4(FALSE);

    *(u32*)&id->serial[28] = viDimming;
    *(OSTime*)&id->serial[12] = time;
    id->deviceID = 0;
    id->size = card->size;
    fn_8041C2D8(id, sizeof(CARDID) - sizeof(u32), &id->checkSum, &id->checkSumInv);

    for (i = 0; i < 2; i++) {
        dir = (CARDDir*)((u8*)card->workArea + (1 + i) * CARD_SYSTEM_BLOCK_SIZE);
        memset(dir, 0xFF, CARD_SYSTEM_BLOCK_SIZE);
        check = CARDGetDirCheck(dir);
        check->checkCode = i;
        fn_8041C2D8(dir, CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &check->checkSum, &check->checkSumInv);
    }

    for (i = 0; i < 2; i++) {
        fat = (u16*)((u8*)card->workArea + (3 + i) * CARD_SYSTEM_BLOCK_SIZE);
        memset(fat, 0, CARD_SYSTEM_BLOCK_SIZE);
        fat[CARD_FAT_CHECKCODE] = i;
        fat[CARD_FAT_FREEBLOCKS] = (u16)(card->cBlock - CARD_NUM_SYSTEM_BLOCK);
        fn_8041C2D8(&fat[CARD_FAT_CHECKCODE], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &fat[CARD_FAT_CHECKSUM], &fat[CARD_FAT_CHECKSUMINV]);
    }

    card->apiCallback = callback ? callback : fn_8041A6C4;

    fn_80433004(card->workArea, CARD_WORKAREA_SIZE);

    card->formatStep = 0;
    result = fn_8041B64C(chan, card->sectorSize * card->formatStep, fn_8041DD44);
    if (result < 0) {
        fn_8041B900(card, result);
    }
    return result;
}

/* CARDFormat */
s32 fn_8041E4E0(s32 chan)
{
    s32 result;

    result = fn_8041DE88(chan, fn_8041B808(), fn_8041A6C8);
    if (result < 0) {
        return result;
    }
    return fn_8041BB38(chan);
}
