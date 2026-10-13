/* Imported from emoose/re4 @ feb6805b (src/lib/CARDDir.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, card library; names are Nintendo's. */
#include <dolphin/card.h>

#include "__card.h"

extern void fn_80433004(void* addr, u32 nBytes); /* DCStoreRange */
extern void fn_8041C2D8(void* ptr, int length, u16* checksum, u16* checksumInv); /* __CARDCheckSum */
extern s32 fn_8041B64C(s32 chan, u32 addr, CARDCallback callback); /* __CARDEraseSector */
extern s32 fn_8041B900(CARDControl* card, s32 result); /* __CARDPutControlBlock */
extern CARDControl lbl_806DCF20[2]; /* __CARDBlock */


// prototypes
static void fn_8041C07C(s32 chan, s32 result);
static void fn_8041C14C(s32 chan, s32 result);

CARDDir* __CARDGetDirBlock(CARDControl* card) {
    ASSERTLINE(54, card->currentDir);
    return card->currentDir;
}

static void fn_8041C07C(s32 chan, s32 result) {
    CARDControl* card = &lbl_806DCF20[chan];
    CARDCallback callback;

    if (result >= 0) {
        CARDDir* dir0 = (CARDDir*)((u8*)card->workArea + 0x2000);
        CARDDir* dir1 = (CARDDir*)((u8*)card->workArea + 0x4000);

        ASSERTLINE(79, card->currentDir);

        if (card->currentDir == dir0) {
            card->currentDir = dir1;
            memcpy(dir1, dir0, 0x2000);
        } else {
            ASSERTLINE(87, card->currentDir == dir1);
            card->currentDir = dir0;
            memcpy(dir0, dir1, 0x2000);
        }
    }

    if (!card->apiCallback)
        fn_8041B900(card, result);

    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = NULL;
        callback(chan, result);
    }
}

static void fn_8041C14C(s32 chan, s32 result) {
    CARDControl* card = &lbl_806DCF20[chan];
    CARDCallback callback;
    CARDDir* dir;
    u32 addr;

    if (result >= 0) {
        dir = __CARDGetDirBlock(card);
        addr = ((u32)dir - (u32)card->workArea) / 0x2000 * card->sectorSize;
        result = __CARDWrite(chan, addr, 0x2000, dir, fn_8041C07C);
        if (result >= 0)
            return;
    }

    if (!card->apiCallback)
        fn_8041B900(card, result);

    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = NULL;
        callback(chan, result);
    }
}

s32 __CARDUpdateDir(s32 chan, CARDCallback callback) {
    CARDControl* card;
    CARDDirCheck* check;
    u32 addr;
    CARDDir* dir;

    ASSERTLINE(173, 0 <= chan && chan < 2);

    card = &lbl_806DCF20[chan];
    if (!card->attached)
        return CARD_RESULT_NOCARD;

    dir = __CARDGetDirBlock(card);
    check = CARDGetDirCheck(dir);
    ++check->checkCode;
    fn_8041C2D8(dir, 0x2000 - sizeof(u32), &check->checkSum, &check->checkSumInv);
    fn_80433004(dir, 0x2000);

    card->eraseCallback = callback;
    addr = ((u32)dir - (u32)card->workArea) / 0x2000 * card->sectorSize;
    return fn_8041B64C(chan, addr, fn_8041C14C);
}
