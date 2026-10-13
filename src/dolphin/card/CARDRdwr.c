/* Imported from emoose/re4 @ feb6805b (src/lib/CARDRdwr.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, card library; names are Nintendo's. */
#include <dolphin/card.h>

#include "__card.h"

extern CARDControl lbl_806DCF20[2];
extern s32 fn_8041B900(CARDControl* card, s32 result);
extern s32 fn_8041B3DC(s32 chan, CARDCallback callback);
extern s32 fn_8041B510(s32 chan, CARDCallback callback);

// prototypes
static void BlockReadCallback(s32 chan, s32 result);
static void BlockWriteCallback(s32 chan, s32 result);

static void BlockReadCallback(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &lbl_806DCF20[chan];

    if ((result >= 0)) {
        card->xferred += 0x200;
        card->addr += 0x200;
        ((u8*)card->buffer) += 0x200;

        if (--card->repeat > 0) {
            result = fn_8041B3DC(chan, BlockReadCallback);
            if (result >= 0) {
                return;
            }
        }
    }

    if (!card->apiCallback) {
        fn_8041B900(card, result);
    }

    callback = card->xferCallback;
    if (callback) {
        card->xferCallback = NULL;
        callback(chan, result);
    }
}

s32 __CARDRead(s32 chan, u32 addr, s32 length, void* dst, CARDCallback callback) {
    CARDControl* card;

    ASSERTLINE(91, 0 < length && length % CARD_SEG_SIZE == 0);
    ASSERTLINE(92, 0 <= chan && chan < 2);

    card = &lbl_806DCF20[chan];
    if (card->attached == 0) {
        return CARD_RESULT_NOCARD;
    }
    card->xferCallback = callback;
    card->repeat = (length / 512u);
    card->addr = addr;
    card->buffer = dst;
    return fn_8041B3DC(chan, BlockReadCallback);
}

static void BlockWriteCallback(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &lbl_806DCF20[chan];
    if (result >= 0) {
        card->xferred += card->pageSize;
        card->addr += card->pageSize;
        ((u8*)card->buffer) += card->pageSize;

        if (--card->repeat > 0) {
            result = fn_8041B510(chan, BlockWriteCallback);
            if (result >= 0) {
                return;
            }
        }
    }

    if (!card->apiCallback) {
        fn_8041B900(card, result);
    }

    callback = card->xferCallback;
    if (callback) {
        card->xferCallback = NULL;
        callback(chan, result);
    }
}

s32 __CARDWrite(s32 chan, u32 addr, s32 length, void* dst, CARDCallback callback) {
    CARDControl* card;
    card = &lbl_806DCF20[chan];

    ASSERTLINE(153, 0 < length && length % card->pageSize == 0);
    ASSERTLINE(154, 0 <= chan && chan < 2);
    
    if (card->attached == 0) {
        return CARD_RESULT_NOCARD;
    }
    card->xferCallback = callback;
    card->repeat = (length / card->pageSize);
    card->addr = addr;
    card->buffer = dst;
    return fn_8041B510(chan, BlockWriteCallback);
}

