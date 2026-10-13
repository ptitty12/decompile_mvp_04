/*
 * Dolphin SDK DVD (MWCC GC/1.2.5n, cflags_dolphin_sdk with -char signed),
 * .text 0x80425954-0x80425AEC (code-only unit, 2 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/os.h>

#include <dolphin/os/OSRtc.h>

OSSramEx* fn_80436AF8(void); /* likely __OSLockSramEx */
int fn_80436EB4(BOOL commit); /* likely __OSUnlockSramEx */

extern u32 lbl_80633F18[];

u8 fn_80425954(u32 errorCode);
void fn_80425A70(u32 error);

u8 fn_80425954(u32 errorCode) {
    u32 i;

    for (i = 0; i < 18; i++) {
        if (errorCode == lbl_80633F18[i]) {
            return (u8)i;
        }
    }
    if (errorCode >= 0x100000 && errorCode <= 0x100008) {
        return 17;
    }
    return 29;
}

void fn_80425A70(u32 error) {
    u8 num;
    OSSramEx* sram;

    if (error == 0x01234567) {
        num = 255;
    } else if (error == 0x01234568) {
        num = 254;
    } else {
        u32 statusCode = error >> 24;
        num = fn_80425954(error & 0x00FFFFFF);
        if (statusCode >= 6) {
            statusCode = 6;
        }
        num = num + statusCode * 30;
    }
    sram = fn_80436AF8();
    sram->dvdErrorCode = num;
    fn_80436EB4(TRUE);
}
