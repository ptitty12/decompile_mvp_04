/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80420228-0x80420354 (code-only unit, 2 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/card.h>

#include "__card.h"

extern u8 lbl_806EF17A;

s32 fn_80420228(s32 chan, s32 fileNo, u8 attr, CARDCallback callback);
s32 fn_8042030C(s32 chan, s32 fileNo, u8 attr);
void fn_8041A6C8(s32 chan, s32 result);
s32 fn_8041BB38(s32 chan);

s32 fn_80420228(s32 chan, s32 fileNo, u8 attr, CARDCallback callback) {
    CARDDir dirent;
    s32 result;

    if (attr & ~lbl_806EF17A) {
        return CARD_RESULT_NOPERM;
    }
    result = __CARDGetStatusEx(chan, fileNo, &dirent);
    if (result < 0) {
        return result;
    }
    if (((dirent.permission & CARD_ATTR_GLOBAL) != 0 && (attr & CARD_ATTR_GLOBAL) == 0) ||
        ((dirent.permission & CARD_ATTR_COMPANY) != 0 && (attr & CARD_ATTR_COMPANY) == 0)) {
        return CARD_RESULT_NOPERM;
    }
    if (((attr & CARD_ATTR_GLOBAL) != 0 && (attr & CARD_ATTR_COMPANY) != 0) ||
        ((attr & CARD_ATTR_GLOBAL) != 0 && (dirent.permission & CARD_ATTR_COMPANY) != 0) ||
        ((attr & CARD_ATTR_COMPANY) != 0 && (dirent.permission & CARD_ATTR_GLOBAL) != 0)) {
        return CARD_RESULT_NOPERM;
    }
    dirent.permission = attr;
    return __CARDSetStatusExAsync(chan, fileNo, &dirent, callback);
}

s32 fn_8042030C(s32 chan, s32 fileNo, u8 attr) {
    s32 result = fn_80420228(chan, fileNo, attr, fn_8041A6C8);
    if (result < 0) {
        return result;
    }
    return fn_8041BB38(chan);
}
