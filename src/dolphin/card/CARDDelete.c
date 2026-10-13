/* Imported from emoose/re4 @ feb6805b (src/lib/CARDDelete.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, card library; names are Nintendo's. */
#include <dolphin/card.h>

#include "__card.h"

extern void fn_8041A6C4(s32 chan, s32 result); /* __CARDDefaultApiCallback */
extern void fn_8041A6C8(s32 chan, s32 result); /* __CARDSyncCallback */
extern s32 fn_8041B848(s32 chan, CARDControl** pcard); /* __CARDGetControlBlock */
extern s32 fn_8041B900(CARDControl* card, s32 result); /* __CARDPutControlBlock */
extern s32 fn_8041BB38(s32 chan); /* __CARDSync */
extern CARDControl lbl_806DCF20[2]; /* __CARDBlock */


// prototypes
static void DeleteCallback(s32 chan, s32 result);

static void DeleteCallback(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &lbl_806DCF20[chan];
    callback = card->apiCallback;
    card->apiCallback = NULL;

    if (result < 0)
        goto error;

    result = __CARDFreeBlock(chan, card->startBlock, callback);
    if (result < 0)
        goto error;
    return;

error:
    fn_8041B900(card, result);
    if (callback)
        callback(chan, result);
}

s32 CARDFastDeleteAsync(s32 chan, s32 fileNo, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;

    ASSERTLINE(133, 0 <= fileNo && fileNo < CARD_MAX_FILE);
    ASSERTLINE(134, 0 <= chan && chan < 2);

    if (fileNo < 0 || CARD_MAX_FILE <= fileNo)
        return CARD_RESULT_FATAL_ERROR;

    result = fn_8041B848(chan, &card);
    if (result < 0)
        return result;

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileNo];
    result = __CARDIsWritable(card, ent);
    if (result < 0)
        return fn_8041B900(card, result);

    if (__CARDIsOpened(card, fileNo))
        return fn_8041B900(card, CARD_RESULT_BUSY);

    card->startBlock = ent->startBlock;
    memset(ent, 0xff, sizeof(CARDDir));

    card->apiCallback = callback ? callback : fn_8041A6C4;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0)
        fn_8041B900(card, result);
    return result;
}

s32 CARDFastDelete(s32 chan, s32 fileNo) {
    s32 result = CARDFastDeleteAsync(chan, fileNo, fn_8041A6C8);
    if (result < 0) {
        return result;
    }

    return fn_8041BB38(chan);
}

s32 CARDDeleteAsync(s32 chan, const char* fileName, CARDCallback callback) {
    CARDControl* card;
    s32 fileNo;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    result = fn_8041B848(chan, &card);
    if (result < 0)
        return result;
    result = __CARDGetFileNo(card, fileName, &fileNo);
    if (result < 0)
        return fn_8041B900(card, result);
    if (__CARDIsOpened(card, fileNo))
        return fn_8041B900(card, CARD_RESULT_BUSY);

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileNo];
    card->startBlock = ent->startBlock;
    memset(ent, 0xff, sizeof(CARDDir));

    card->apiCallback = callback ? callback : fn_8041A6C4;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0)
        fn_8041B900(card, result);
    return result;
}

s32 CARDDelete(s32 chan, const char* fileName) {
    s32 result = CARDDeleteAsync(chan, fileName, fn_8041A6C8);
    if (result < 0)
        return result;

    return fn_8041BB38(chan);
}
