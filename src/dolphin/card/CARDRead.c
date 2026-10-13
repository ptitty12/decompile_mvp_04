/* Imported from emoose/re4 @ feb6805b (src/lib/CARDRead.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, card library; names are Nintendo's. */
#include <dolphin/card.h>

#include "__card.h"

extern s32 fn_8041B848(s32 chan, CARDControl** pcard); /* __CARDGetControlBlock */
extern s32 fn_8041B900(CARDControl* card, s32 result); /* __CARDPutControlBlock */
extern void fn_80432FA8(void* addr, u32 nBytes); /* DCInvalidateRange */
extern void fn_8041A6C4(s32 chan, s32 result); /* fn_8041A6C4 */
extern void fn_8041A6C8(s32 chan, s32 result); /* fn_8041A6C8 */
extern s32 fn_8041BB38(s32 chan); /* __CARDSync */
extern CARDControl lbl_806DCF20[2]; /* __CARDBlock */

#define TRUNC(n, a) (((u32)(n)) & ~((a)-1))

// prototypes
static void ReadCallback(s32 chan, s32 result);

s32 __CARDSeek(CARDFileInfo* fileInfo, s32 length, s32 offset, CARDControl** pcard) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    u16* fat;

    ASSERTLINE(98, 0 <= fileInfo->chan && fileInfo->chan < 2);
    ASSERTLINE(99, 0 <= fileInfo->fileNo && fileInfo->fileNo < CARD_MAX_FILE);

    result = fn_8041B848(fileInfo->chan, &card);
    if (result < 0)
        return result;

    ASSERTLINE(106, CARDIsValidBlockNo(card, fileInfo->iBlock));
    ASSERTLINE(107, fileInfo->offset < card->cBlock * card->sectorSize);

    if (!CARDIsValidBlockNo(card, fileInfo->iBlock) || card->cBlock * card->sectorSize <= fileInfo->offset)
        return fn_8041B900(card, CARD_RESULT_FATAL_ERROR);

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileInfo->fileNo];

    ASSERTLINE(117, ent->gameName[0] != 0xff);

    if (ent->length * card->sectorSize <= offset || ent->length * card->sectorSize < offset + length)
        return fn_8041B900(card, CARD_RESULT_LIMIT);

    card->fileInfo = fileInfo;
    fileInfo->length = length;
    if (offset < fileInfo->offset) {
        fileInfo->offset = 0;
        fileInfo->iBlock = ent->startBlock;
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock))
            return fn_8041B900(card, CARD_RESULT_BROKEN);
    }

    fat = __CARDGetFatBlock(card);
    while (fileInfo->offset < TRUNC(offset, card->sectorSize)) {
        fileInfo->offset += card->sectorSize;
        fileInfo->iBlock = fat[fileInfo->iBlock];
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock))
            return fn_8041B900(card, CARD_RESULT_BROKEN);
    }

    fileInfo->offset = offset;

    *pcard = card;
    return CARD_RESULT_READY;
}

static void ReadCallback(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    u16* fat;
    CARDFileInfo* fileInfo;
    s32 length;

    card = &lbl_806DCF20[chan];
    if (result < 0)
        goto error;

    fileInfo = card->fileInfo;
    if (fileInfo->length < 0) {
        result = CARD_RESULT_CANCELED;
        goto error;
    }

    length = TRUNC(fileInfo->offset + card->sectorSize, card->sectorSize) - fileInfo->offset;
    fileInfo->length -= length;
    if (fileInfo->length <= 0)
        goto error;

    fat = __CARDGetFatBlock(card);
    fileInfo->offset += length;
    fileInfo->iBlock = fat[fileInfo->iBlock];
    if (!CARDIsValidBlockNo(card, fileInfo->iBlock)) {
        result = CARD_RESULT_BROKEN;
        goto error;
    }

    ASSERTLINE(199, OFFSET(fileInfo->length, CARD_SEG_SIZE) == 0);
    ASSERTLINE(200, OFFSET(fileInfo->offset, card->sectorSize) == 0);

    result = __CARDRead(chan, card->sectorSize * (u32)fileInfo->iBlock,
                        (fileInfo->length < card->sectorSize) ? fileInfo->length : card->sectorSize, card->buffer,
                        ReadCallback);
    if (result < 0)
        goto error;

    return;

error:
    callback = card->apiCallback;
    card->apiCallback = NULL;
    fn_8041B900(card, result);
    ASSERTLINE(217, callback);
    callback(chan, result);
}

s32 CARDReadAsync(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset, CARDCallback callback) {
    CARDControl* card;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    ASSERTLINE(250, buf && OFFSET(buf, 32) == 0);
    ASSERTLINE(251, OFFSET(offset, CARD_SEG_SIZE) == 0);
    ASSERTLINE(252, 0 < length && OFFSET(length, CARD_SEG_SIZE) == 0);

    if (OFFSET(offset, CARD_SEG_SIZE) != 0 || OFFSET(length, CARD_SEG_SIZE) != 0)
        return CARD_RESULT_FATAL_ERROR;

    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0)
        return result;

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDIsReadable(card, ent);
    if (result < 0)
        return fn_8041B900(card, result);

    fn_80432FA8(buf, (u32)length);
    card->apiCallback = callback ? callback : fn_8041A6C4;

    offset = (s32)OFFSET(fileInfo->offset, card->sectorSize);
    length = (length < card->sectorSize - offset) ? length : card->sectorSize - offset;
    result = __CARDRead(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock + offset, length, buf, ReadCallback);
    if (result < 0)
        fn_8041B900(card, result);
    return result;
}

s32 CARDRead(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset) {
    s32 result = CARDReadAsync(fileInfo, buf, length, offset, fn_8041A6C8);
    if (result < 0) {
        return result;
    }

    return fn_8041BB38(fileInfo->chan);
}

