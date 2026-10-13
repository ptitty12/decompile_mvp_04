/*
 * Dolphin SDK EXI (MWCC GC/1.2.5n, cflags_dolphin_dvd = cflags_dolphin_sdk with -char signed: -O4,p),
 * .text 0x804286AC-0x80428C64 (code-only unit, 4 functions; placeholder name).
 * EXIUart.c (shape of the code, with the reference dolsdk2004 EXIUart.c): fn_804286AC EXIGetRevision-like
 * probe, then the UART/barnacle init and write routines. Split off dolphin/exi/tu_80426CD0.c
 * (docs/DECISIONS.md 2026-10-12). Every data object is extern by its lbl_ name.
 */

#include <dolphin.h>
#include <dolphin/exi.h>
#include <dolphin/os.h>

extern s32 lbl_806EF728;  /* Chan */
extern u32 lbl_806EF72C;  /* Dev */
extern u32 lbl_806EF730;  /* Enabled */
extern u32 lbl_806EF734;  /* BarnacleEnabled */

u32 fn_80431828(void);
s32 fn_804282FC(s32 chan, u32 dev, u32* id);
int fn_80426DC4(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
int fn_804271AC(s32 chan);
int fn_80427764(s32 chan, EXICallback extCallback);
int fn_80427870(s32 chan);
int fn_8042792C(s32 chan, u32 dev, u32 freq);
int fn_80427A58(s32 chan);
int fn_804280EC(s32 chan, u32 dev, EXICallback unlockedCallback);
int fn_804281E0(s32 chan);

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

    if (*revision != 0xFFFFFFFF) {
        return 1;
    }
    return 0;
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

u32 fn_804289F4(u32 baudRate) {
    if (lbl_806EF734 == 0xA5FF005A) {
        return 0;
    }

    if (!(fn_80431828() & 0x10000000)) {
        lbl_806EF730 = 0;
        return 2;
    }

    lbl_806EF730 = 0xA5FF005A;
    lbl_806EF728 = 0;
    lbl_806EF72C = 1;
    return 0;
}

static inline int QueueLength(void) {
    u32 cmd;

    if (fn_8042792C(lbl_806EF728, lbl_806EF72C, 3) == 0) {
        return -1;
    }

    cmd = 0x20010000;
    fn_80426DC4(lbl_806EF728, &cmd, 4, 1, 0);
    fn_804271AC(lbl_806EF728);

    fn_80426DC4(lbl_806EF728, &cmd, 1, 0, 0);
    fn_804271AC(lbl_806EF728);

    fn_80427A58(lbl_806EF728);

    return 16 - (cmd >> 24);
}

u32 fn_80428A64(const void* buf, unsigned long len) {
    u32 cmd;
    s32 xLen;
    s32 qLen;
    char* ptr;
    int locked;
    u32 error;
    s32 tmpq;

    if (lbl_806EF730 != 0xA5FF005A) {
        return 2;
    }

    locked = fn_804280EC(lbl_806EF728, lbl_806EF72C, 0);
    if (locked == 0) {
        return 0;
    }

    for (ptr = (char*)buf; ptr - (char*)buf < len; ptr++) {
        if (*ptr == '\n') {
            *ptr = '\r';
        }
    }

    cmd = 0xA0010000;
    error = 0;
    while (len) {
        tmpq = QueueLength();
        qLen = tmpq;
        if (tmpq < 0) {
            error = 3;
            break;
        }
        if (tmpq < 12 && tmpq < len) {
            continue;
        }
        if (fn_8042792C(lbl_806EF728, lbl_806EF72C, 3) == 0) {
            error = 3;
            break;
        }
        fn_80426DC4(lbl_806EF728, &cmd, 4, 1, 0);
        fn_804271AC(lbl_806EF728);
        while (qLen && len) {
            if (qLen < 4 && qLen < len) {
                break;
            }
            xLen = (len < 4) ? (s32)len : 4;
            fn_80426DC4(lbl_806EF728, (void*)buf, xLen, 1, 0);
            (u8*)buf += xLen;
            len -= xLen;
            qLen -= xLen;
            fn_804271AC(lbl_806EF728);
        }
        fn_80427A58(lbl_806EF728);
    }
    fn_804281E0(lbl_806EF728);
    return error;
}
