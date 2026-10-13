/* Imported from emoose/re4 @ feb6805b (src/lib/CARDWrite.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, card library; names are Nintendo's. */
#include <dolphin/card.h>

#include "__card.h"

extern void fn_80433004(void* addr, u32 nBytes); /* DCStoreRange */
extern OSTime fn_80438628(void); /* OSGetTime */
extern void fn_8041A6C4(s32 chan, s32 result); /* __CARDDefaultApiCallback */
extern void fn_8041A6C8(s32 chan, s32 result); /* __CARDSyncCallback */
extern s32 fn_8041B64C(s32 chan, u32 addr, CARDCallback callback); /* __CARDEraseSector */
extern s32 fn_8041B900(CARDControl* card, s32 result); /* __CARDPutControlBlock */
extern s32 fn_8041BB38(s32 chan); /* __CARDSync */
extern CARDControl lbl_806DCF20[2]; /* __CARDBlock */


// prototypes
static void fn_8041F430(s32 chan, s32 result);
static void fn_8041F5A0(s32 chan, s32 result);

static void fn_8041F430(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    u16* fat;
    CARDDir* dir;
    CARDDir* ent;
    CARDFileInfo* fileInfo;

    card = &lbl_806DCF20[chan];
    if (result >= 0) {
        fileInfo = card->fileInfo;
        if (fileInfo->length < 0) {
            result = CARD_RESULT_CANCELED;
            goto after;
        }
        fileInfo->length -= card->sectorSize;
        if (fileInfo->length <= 0) {
            dir = __CARDGetDirBlock(card);
            ent = dir + fileInfo->fileNo;
            ent->time = fn_80438628()/(__OSBusClock/4);
            callback = card->apiCallback;
            card->apiCallback = NULL;
            result = __CARDUpdateDir(chan, callback);
            goto check;
        } else {
            fat = __CARDGetFatBlock(card);
            fileInfo->offset += card->sectorSize;
            fileInfo->iBlock = fat[fileInfo->iBlock];
            if ((fileInfo->iBlock < 5) || (fileInfo->iBlock >= card->cBlock)) {
                result = CARD_RESULT_BROKEN;
                goto after;
            }
            result = fn_8041B64C(chan, card->sectorSize * fileInfo->iBlock, fn_8041F5A0);
check:;
            if (result < 0) {
                goto after;
            }
        }
    } else {
after:;
        callback = card->apiCallback;
        card->apiCallback = NULL;
        fn_8041B900(card, result);
        ASSERTLINE(0x86, callback);
        callback(chan, result);
    }
}

static void fn_8041F5A0(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    CARDFileInfo* fileInfo;

    card = &lbl_806DCF20[chan];
    if (result >= 0) {
        fileInfo = card->fileInfo;
        ASSERTLINE(161, OFFSET(fileInfo->offset, card->sectorSize) == 0);
        result = __CARDWrite(chan, card->sectorSize * fileInfo->iBlock, card->sectorSize, card->buffer, fn_8041F430);
        if (result < 0) {
            goto after;
        }
    } else {
after:;
        callback = card->apiCallback;
        card->apiCallback = NULL;
        fn_8041B900(card, result);
        ASSERTLINE(175, callback);
        callback(chan, result);
    }
}

s32 CARDWriteAsync(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset, CARDCallback callback) {
    CARDControl* card;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    ASSERTLINE(210, buf && ((u32) buf % 32) == 0);
    ASSERTLINE(211, 0 < length);

    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0) {
        return result;
    }

    ASSERTLINE(217, OFFSET(offset, card->sectorSize) == 0);
    ASSERTLINE(218, OFFSET(length, card->sectorSize) == 0);

    if (OFFSET(offset, card->sectorSize) != 0 || OFFSET(length, card->sectorSize) != 0)
        return fn_8041B900(card, CARD_RESULT_FATAL_ERROR);

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDIsWritable(card, ent);
    if (result < 0)
        return fn_8041B900(card, result);

    fn_80433004((void*)buf, (u32)length);
    card->apiCallback = callback ? callback : fn_8041A6C4;
    card->buffer = (void*)buf;

    result = fn_8041B64C(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock, fn_8041F5A0);
    if (result < 0)
        fn_8041B900(card, result);
    return result;
}

s32 CARDWrite(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset) {
    s32 result = CARDWriteAsync(fileInfo, buf, length, offset, fn_8041A6C8);
    if (result < 0) {
        return result;
    }

    return fn_8041BB38(fileInfo->chan);
}
