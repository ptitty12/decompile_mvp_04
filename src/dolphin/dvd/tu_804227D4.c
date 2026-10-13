/*
 * Dolphin SDK DVD (MWCC GC/1.2.5n, cflags_dolphin_sdk with -char signed),
 * .text 0x804227D4-0x8042575C (code-only unit, 57 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/hw_regs.h>

#include <string.h>

/* dvdfs.c / dvd.c small functions of this unit. Placeholder names kept (symbols.txt); likely SDK names:
 * fn_804227D4 __DVDFSInit, fn_80422B00 DVDFastOpen, fn_80422C3C DVDClose, fn_80422FA4 cbForReadAsync,
 * fn_80422FD4 cbForReadSync (empty), fn_80423E80 / fn_804232A4 / fn_804236C0 / fn_80423DEC / fn_804239D8
 * (state machine starters: DVDLow* with the next state as callback), fn_80423908 / fn_8042393C
 * (DVDLowAudioBufferConfig starters), fn_80425064 DVDGetCommandBlockStatus, fn_8042515C
 * __DVDSetAutoInvalidation-style exchange, fn_80425508 DVDGetCurrentDiskID, fn_804254E4 (wakes the DVD
 * thread queue), fn_80425724 __DVDTestAlarm. Callees: fn_80425438 DVDCancel, fn_804383B8 OSWakeupThread,
 * fn_80426C98 __DVDLowTestAlarm, fn_804263F8 DVDLowRead, fn_80426724 DVDLowWaitCoverClose,
 * fn_80426750 DVDLowReadDiskID, fn_804267F4 DVDLowStopMotor, fn_80426880 DVDLowRequestError,
 * fn_80426ACC DVDLowAudioBufferConfig. */

typedef struct FstEntry {
    u32 isDirAndStringOff;
    u32 parentOrPosition;
    u32 nextEntryOrLength;
} FstEntry;

#define FST_IS_DIR(e) ((((e)->isDirAndStringOff & 0xFF000000) == 0) ? FALSE : TRUE)

extern OSBootInfo* lbl_806EF640;
extern FstEntry* lbl_806EF644;
extern char* lbl_806EF648;
extern u32 lbl_806EF64C;
extern OSThreadQueue lbl_806EF658;
extern DVDDiskID* lbl_806EF664;
extern BOOL lbl_806EF1A4;
typedef struct DvdBss {
    DVDBB2 bb2;
    DVDDiskID tmp;
    DVDCommandBlock dummy;
    OSAlarm resetAlarm;
} DvdBss;
extern DvdBss lbl_806DE160;
extern DVDDiskID lbl_806DE180;
extern OSAlarm lbl_806DE1D0;

int fn_80425438(DVDCommandBlock* block);
void fn_804383B8(OSThreadQueue* queue);
BOOL fn_80426C98(const OSAlarm* alarm);
BOOL fn_804263F8(void* addr, u32 length, u32 offset, DVDLowCallback callback);
BOOL fn_80426724(DVDLowCallback callback);
BOOL fn_80426750(DVDDiskID* diskID, DVDLowCallback callback);
BOOL fn_804267F4(DVDLowCallback callback);
BOOL fn_80426880(DVDLowCallback callback);
BOOL fn_80426ACC(BOOL eventMode, u32 bufferNum, DVDLowCallback callback);

void fn_80423380(u32 intType);
void fn_804236E8(u32 intType);
void fn_80423E1C(u32 intType);
void fn_80423B0C(u32 intType);
void fn_80423BE4(u32 intType);
void fn_80423970(u32 intType);
void fn_80423EA8(u32 intType);

extern s32 lbl_806EF650;
extern OSBootInfo* lbl_806EF668;
extern volatile s32 lbl_806EF66C;
extern volatile s32 lbl_806EF670;
extern DVDCommandBlock* lbl_806EF660;
extern s32 lbl_806EF678;
extern volatile u32 lbl_806EF67C;
extern volatile u32 lbl_806EF680;
extern DVDCBCallback lbl_806EF684;
extern volatile u32 lbl_806EF688;
extern volatile s32 lbl_806EF694;
extern u32 lbl_806EF690;
extern s32 lbl_806EF698;
extern void (*lbl_806EF6B8)(DVDCommandBlock*);
extern DVDCommandBlock lbl_806DE1A0;

#define BB2 (lbl_806DE160.bb2)
#define TMPID (&lbl_806DE160.tmp)

void fn_80425A70(u32 error);
void fn_80433CE8(const char* file, int line, const char* msg, ...);
void fn_80426B68(void);
void fn_80432FA8(void* addr, u32 nBytes);
void fn_80425BE4(void);
void fn_80423F94(void);
int __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block);
DVDCommandBlock* __DVDPopWaitingQueue(void);
extern void (*lbl_806EF1A8)(DVDCommandBlock*, DVDLowCallback);
extern s32 lbl_806EF674;
void fn_804245BC(u32 intType);
BOOL fn_80426A40(u32 subcmd, DVDLowCallback callback);
BOOL fn_804269A8(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback);
BOOL fn_8042690C(void* addr, DVDLowCallback callback);
int __DVDCheckWaitingQueue(void);
extern s32 lbl_806EF68C;
int __DVDDequeueWaitingQueue(DVDCommandBlock* block);
void fn_80426C24(void);
void* fn_80426C38(void);
BOOL fn_80425510(void);
void fn_80425608(DVDCBCallback callback);
int fn_80424CF0(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback);
int fn_80424DC0(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback);
int fn_80424E94(DVDCommandBlock* block, DVDCBCallback callback);
int fn_80424F50(DVDCommandBlock* block, void* info, DVDCBCallback callback);
s32 fn_804250B0(void);
int fn_804251BC(DVDCommandBlock* block, DVDCBCallback callback);
void fn_804382CC(OSThreadQueue* queue);
void fn_8042427C(DVDCommandBlock* block);
void fn_80423270(void);
void fn_80425020(void);
void fn_804231C4(u32 intType);
void fn_80423144(u32 intType);
void fn_80423640(u32 intType);
void fn_80423A10(u32 intType);
u32 fn_804232CC(u32 error);
void fn_80423D18(void);
void fn_80432224(OSAlarm* alarm);
void fn_80432484(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
BOOL fn_80426690(u32 offset, DVDLowCallback callback);
void fn_80423828(void);
void fn_804230B0(DVDCommandBlock* block);
s32 fn_8042280C(const char* path);
void fn_80423CD4(OSAlarm* alarm, OSContext* context);
BOOL fn_80422E84(const char* path);
void fn_804235E4(u32 intType);
void fn_8042516C(void);

extern s32 lbl_806EF6AC;
extern u32 lbl_806EF6A8;
extern s32 lbl_806EF6A4;
extern const char* lbl_806EF1A0;

BOOL fn_80422B74(const char* fileName, DVDFileInfo* fileInfo);
BOOL fn_80422DC0(char* path, u32 maxlen);
u32 fn_80422C60(s32 entrynum, char* path, u32 maxlen);
BOOL fn_80422EE4(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio);
int fn_80424C14(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback, s32 prio);
void fn_80422FD8(void);
void fn_80425E54(void);
void fn_80425E94(__OSInterrupt interrupt, OSContext* context);
void fn_80437434(OSThreadQueue* queue);
void fn_80425CEC(void);
void __DVDClearWaitingQueue(void);

void fn_804227D4(void);
BOOL fn_80422B00(s32 entrynum, DVDFileInfo* fileInfo);
BOOL fn_80422C3C(DVDFileInfo* fileInfo);
void fn_80422FA4(s32 result, DVDCommandBlock* block);
void fn_80422FD4(s32 result, DVDCommandBlock* block);
void fn_804232A4(void);
void fn_804236C0(void);
void fn_80423908(DVDCommandBlock* block);
void fn_8042393C(DVDCommandBlock* block);
void fn_804239D8(DVDCommandBlock* block);
void fn_80423DEC(DVDCommandBlock* block);
void fn_80423E80(void);
s32 fn_80425064(const DVDCommandBlock* block);
BOOL fn_8042515C(BOOL autoInvalidation);
DVDDiskID* fn_80425508(void);
void fn_804254E4(s32 result, DVDCommandBlock* block);
BOOL fn_80425724(const OSAlarm* alarm);

void fn_804227D4(void) {
    lbl_806EF640 = (OSBootInfo*)OS_BASE_CACHED;
    lbl_806EF644 = (FstEntry*)lbl_806EF640->FSTLocation;
    if (lbl_806EF644) {
        lbl_806EF64C = lbl_806EF644[0].nextEntryOrLength;
        lbl_806EF648 = (char*)&lbl_806EF644[lbl_806EF64C];
    }
}

BOOL fn_80422B00(s32 entrynum, DVDFileInfo* fileInfo) {
    if (entrynum < 0 || entrynum >= lbl_806EF64C || FST_IS_DIR(&lbl_806EF644[entrynum])) {
        return FALSE;
    }
    fileInfo->startAddr = lbl_806EF644[entrynum].parentOrPosition;
    fileInfo->length = lbl_806EF644[entrynum].nextEntryOrLength;
    fileInfo->callback = NULL;
    fileInfo->cb.state = 0;
    return TRUE;
}

BOOL fn_80422B74(const char* fileName, DVDFileInfo* fileInfo) {
    s32 entry;
    char currentDir[128];

    entry = fn_8042280C(fileName);
    if (entry < 0) {
        fn_80422DC0(currentDir, 128);
        OSReport("Warning: DVDOpen(): file '%s' was not found under %s.\n", fileName, currentDir);
        return FALSE;
    }
    if (FST_IS_DIR(&lbl_806EF644[entry])) {
        return FALSE;
    }
    fileInfo->startAddr = lbl_806EF644[entry].parentOrPosition;
    fileInfo->length = lbl_806EF644[entry].nextEntryOrLength;
    fileInfo->callback = NULL;
    fileInfo->cb.state = 0;
    return TRUE;
}

BOOL fn_80422C3C(DVDFileInfo* fileInfo) {
    fn_80425438(&fileInfo->cb);
    return TRUE;
}

BOOL fn_80422E84(const char* path) {
    s32 entry = fn_8042280C(path);

    if (entry < 0 || !FST_IS_DIR(&lbl_806EF644[entry])) {
        return FALSE;
    }
    lbl_806EF650 = entry;
    return TRUE;
}

BOOL fn_80422EE4(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio) {
    if (!((0 <= offset) && (offset <= fileInfo->length))) {
        fn_80433CE8("dvdfs.c", 0x2EE, "DVDReadAsync(): specified area is out of the file  ");
    }
    if (!((0 <= offset + length) && (offset + length < fileInfo->length + 32))) {
        fn_80433CE8("dvdfs.c", 0x2F4, "DVDReadAsync(): specified area is out of the file  ");
    }
    fileInfo->callback = callback;
    fn_80424C14(&fileInfo->cb, addr, length, (s32)(fileInfo->startAddr + offset), fn_80422FA4, prio);
    return TRUE;
}

void fn_80422FA4(s32 result, DVDCommandBlock* block) {
    DVDFileInfo* fileInfo = (DVDFileInfo*)block;

    if (fileInfo->callback) {
        fileInfo->callback(result, fileInfo);
    }
}

void fn_80422FD4(s32 result, DVDCommandBlock* block) {
}

/* near-miss 99.86%: retail frame is 16 bytes, ours 24 (cause unknown; the copy inlined into fn_80423B0C has the 24-byte frame) */
void fn_804230B0(DVDCommandBlock* block) {
    lbl_806EF6B8 = fn_804230B0;
    if (!(lbl_806EF668->FSTMaxLength >= BB2.FSTLength)) {
        fn_80433CE8("dvd.c", 0x295, "DVDChangeDisk(): FST in the new disc is too big.   ");
    }
    fn_804263F8(lbl_806EF668->FSTLocation, OSRoundUp32B(BB2.FSTLength), BB2.FSTPosition, fn_80423144);
}

void fn_804231C4(u32 intType) {
    DVDCommandBlock* finished;

    lbl_806EF660->state = -1;
    if (intType == 0x10) {
        fn_80423270();
    } else {
        fn_80425BE4();
        finished = lbl_806EF660;
        lbl_806EF678 = 1;
        lbl_806EF660 = &lbl_806DE1A0;
        if (finished->callback) {
            finished->callback(-1, finished);
        }
        if (lbl_806EF680) {
            lbl_806EF680 = 0;
            if (lbl_806EF684) {
                lbl_806EF684(0, finished);
            }
        }
        fn_80423F94();
    }
}

static BOOL CheckCancel(u32 resume) {
    DVDCommandBlock* finished;

    if (lbl_806EF680) {
        lbl_806EF688 = resume;
        finished = lbl_806EF660;
        lbl_806EF680 = 0;
        lbl_806EF660 = &lbl_806DE1A0;
        finished->state = 10;
        if (finished->callback) {
            finished->callback(-3, finished);
        }
        if (lbl_806EF684) {
            lbl_806EF684(0, finished);
        }
        fn_80423F94();
        return TRUE;
    }
    return FALSE;
}

void fn_80423270(void) {
    fn_80425A70(0x1234568);
    fn_80425020();
    fn_804231C4(0);
}

void fn_804232A4(void) {
    fn_80426880(fn_80423380);
}

u32 fn_804232CC(u32 error) {
    if (error == 0x20400) {
        lbl_806EF690 = error;
        return 1;
    }
    error &= 0x00FFFFFF;
    if (error == 0x62800 || error == 0x23A00 || error == 0xB5A01) {
        return 0;
    }
    lbl_806EF694++;
    if (lbl_806EF694 == 2) {
        if (error == lbl_806EF690) {
            lbl_806EF690 = error;
            return 1;
        }
        lbl_806EF690 = error;
        return 2;
    }
    lbl_806EF690 = error;
    if (error == 0x31100 || lbl_806EF660->command == 5) {
        return 2;
    }
    return 3;
}

void fn_80423380(u32 intType) {
    u32 error;
    u32 status;
    u32 category;
    u32 state;

    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 2) {
        fn_80425A70(0x1234567);
        fn_804267F4(fn_804231C4);
    } else {
        error = __DIRegs[8];
        status = error & 0xFF000000;
        category = fn_804232CC(error);
        if (category == 1) {
            fn_80425A70(error);
            fn_804267F4(fn_804231C4);
            return;
        }
        if (category == 2 || category == 3) {
            state = 0;
        } else if (status == 0x01000000) {
            state = 4;
        } else if (status == 0x02000000) {
            state = 6;
        } else if (status == 0x03000000) {
            state = 3;
        } else {
            state = 5;
        }
        if (CheckCancel(state)) {
            return;
        }
        if (category == 2) {
            fn_80425A70(error);
            fn_804236C0();
        } else if (category == 3) {
            if ((error & 0x00FFFFFF) == 0x31100) {
                fn_80426690(lbl_806EF660->offset, fn_804235E4);
            } else {
                lbl_806EF6B8(lbl_806EF660);
            }
        } else if (status == 0x01000000) {
            lbl_806EF660->state = 5;
            fn_80423E80();
        } else if (status == 0x02000000) {
            lbl_806EF660->state = 3;
            fn_80423D18();
        } else if (status == 0x03000000) {
            lbl_806EF660->state = 4;
            fn_80423E80();
        } else {
            fn_80425A70(0x1234567);
            fn_804267F4(fn_804231C4);
        }
    }
}

void fn_804235E4(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 1) {
        fn_804236C0();
    } else {
        fn_80426880(fn_80423640);
    }
}

void fn_80423640(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 2) {
        fn_80425A70(0x1234567);
        fn_804267F4(fn_804231C4);
    } else {
        fn_80425A70(__DIRegs[8]);
        fn_804267F4(fn_804231C4);
    }
}

void fn_804236C0(void) {
    fn_804267F4(fn_804236E8);
}

void fn_804236E8(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 2) {
        fn_80425A70(0x1234567);
        fn_804267F4(fn_804231C4);
    } else {
        lbl_806EF694 = 0;
        if (lbl_806EF67C == 4 || lbl_806EF67C == 5 || lbl_806EF67C == 13 || lbl_806EF67C == 15) {
            lbl_806EF698 = 1;
        }
        if (CheckCancel(2)) {
            return;
        }
        lbl_806EF660->state = 11;
        fn_80423E80();
    }
}

void fn_80423828(void) {
    DvdBss* b = &lbl_806DE160;
    void* bb;

    switch (lbl_806EF67C) {
    case 3:
        if (DVDCompareDiskID(&b->tmp, lbl_806EF660->id)) {
            memcpy(lbl_806EF664, &b->tmp, 0x20);
            bb = &lbl_806DE160.bb2;
            lbl_806EF660->state = 1;
            fn_80432FA8(bb, 0x20);
            lbl_806EF6B8 = fn_8042393C;
            fn_8042393C(lbl_806EF660);
        } else {
            fn_804267F4(fn_80423A10);
        }
        break;
    default:
        if (memcmp(&b->tmp, lbl_806EF664, 0x20) != 0) {
            fn_804267F4(fn_80423A10);
        } else {
            lbl_806EF6B8 = fn_80423908;
            fn_80423908(lbl_806EF660);
        }
        break;
    }
}

void fn_80423908(DVDCommandBlock* block) {
    fn_80426ACC(lbl_806EF664->streaming, 10, fn_80423BE4);
}

void fn_8042393C(DVDCommandBlock* block) {
    fn_80426ACC(lbl_806EF664->streaming, 10, fn_80423970);
}

void fn_80423970(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 1) {
        lbl_806EF694 = 0;
        fn_804239D8(lbl_806EF660);
    } else {
        fn_80426880(fn_80423380);
    }
}

void fn_804239D8(DVDCommandBlock* block) {
    fn_804263F8(&lbl_806DE160.bb2, 0x20, 0x420, fn_80423B0C);
}

void fn_80423A10(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 2) {
        fn_80425A70(0x1234567);
        fn_804267F4(fn_804231C4);
    } else {
        lbl_806EF694 = 0;
        if (CheckCancel(1)) {
            return;
        }
        lbl_806EF660->state = 6;
        fn_80423E80();
    }
}

void fn_80423B0C(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 1) {
        lbl_806EF694 = 0;
        fn_804230B0(lbl_806EF660);
    } else {
        fn_80426880(fn_80423380);
    }
}

void fn_80423BE4(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 1) {
        lbl_806EF694 = 0;
        if (CheckCancel(0)) {
            return;
        }
        lbl_806EF660->state = 1;
        fn_8042427C(lbl_806EF660);
    } else {
        fn_80426880(fn_80423380);
    }
}

void fn_80423CD4(OSAlarm* alarm, OSContext* context) {
    fn_80425020();
    fn_80432FA8(&lbl_806DE180, 0x20);
    lbl_806EF6B8 = fn_80423DEC;
    fn_80423DEC(lbl_806EF660);
}

void fn_80423D18(void) {
    DvdBss* b = &lbl_806DE160;
    DVDCommandBlock* finished;

    switch (lbl_806EF67C) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        finished = lbl_806EF660;
        lbl_806EF660 = &b->dummy;
        if (finished->callback) {
            finished->callback(-4, finished);
        }
        fn_80423F94();
        break;
    default:
        lbl_806EF6A8 = 0;
        fn_80425020();
        fn_80432224(&b->resetAlarm);
        fn_80432484(&b->resetAlarm, OSMillisecondsToTicks(1150), fn_80423CD4);
        break;
    }
}

void fn_80423DEC(DVDCommandBlock* block) {
    fn_80426750(&lbl_806DE180, fn_80423E1C);
}

void fn_80423E1C(u32 intType) {
    if (intType == 0x10) {
        fn_80423270();
    } else if (intType & 1) {
        lbl_806EF694 = 0;
        fn_80423828();
    } else {
        fn_80426880(fn_80423380);
    }
}

void fn_80423E80(void) {
    fn_80426724(fn_80423EA8);
}

void fn_80423EA8(u32 intType) {
    DvdBss* b = &lbl_806DE160;
    DVDCommandBlock* finished;

    __DIRegs[1] = 0;
    lbl_806EF660->state = 3;
    switch (lbl_806EF67C) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        finished = lbl_806EF660;
        lbl_806EF660 = &b->dummy;
        if (finished->callback) {
            finished->callback(-4, finished);
        }
        fn_80423F94();
        break;
    default:
        lbl_806EF6A8 = 0;
        fn_80425020();
        fn_80432224(&b->resetAlarm);
        fn_80432484(&b->resetAlarm, OSMillisecondsToTicks(1150), fn_80423CD4);
        break;
    }
}

void fn_80423F94(void) {
    DvdBss* b = &lbl_806DE160;
    DVDCommandBlock* finished;

    if (__DVDCheckWaitingQueue() == 0) {
        lbl_806EF660 = NULL;
        return;
    }
    if (lbl_806EF66C) {
        lbl_806EF670 = 1;
        lbl_806EF660 = NULL;
        return;
    }
    lbl_806EF660 = __DVDPopWaitingQueue();
    if (lbl_806EF678) {
        lbl_806EF660->state = -1;
        finished = lbl_806EF660;
        lbl_806EF660 = &b->dummy;
        if (finished->callback) {
            finished->callback(-1, finished);
        }
        fn_80423F94();
        return;
    }
    lbl_806EF67C = lbl_806EF660->command;
    if (lbl_806EF688) {
        switch (lbl_806EF688) {
        case 2:
            lbl_806EF660->state = 11;
            fn_80426724(fn_80423EA8);
            break;
        case 3:
            lbl_806EF660->state = 4;
            fn_80426724(fn_80423EA8);
            break;
        case 4:
            lbl_806EF660->state = 5;
            fn_80426724(fn_80423EA8);
            break;
        case 1:
        case 6:
        case 7:
            lbl_806EF660->state = 3;
            switch (lbl_806EF67C) {
            case 4:
            case 5:
            case 13:
            case 15:
                __DVDClearWaitingQueue();
                finished = lbl_806EF660;
                lbl_806EF660 = &b->dummy;
                if (finished->callback) {
                    finished->callback(-4, finished);
                }
                fn_80423F94();
                break;
            default:
                lbl_806EF6A8 = 0;
                fn_80425020();
                fn_80432224(&b->resetAlarm);
                fn_80432484(&b->resetAlarm, OSMillisecondsToTicks(1150), fn_80423CD4);
                break;
            }
            break;
        case 5:
            fn_80425A70(lbl_806EF68C);
            fn_804267F4(fn_804231C4);
            break;
        }
        lbl_806EF688 = 0;
    } else if (lbl_806EF6A8 == 0) {
        lbl_806EF660->state = 1;
        fn_8042427C(lbl_806EF660);
    } else {
        switch (lbl_806EF67C) {
        case 4:
        case 5:
        case 13:
        case 15:
            __DVDClearWaitingQueue();
            finished = lbl_806EF660;
            lbl_806EF660 = &b->dummy;
            if (finished->callback) {
                finished->callback(-4, finished);
            }
            fn_80423F94();
            break;
        default:
            lbl_806EF6A8 = 0;
            fn_80425020();
            fn_80432224(&b->resetAlarm);
            fn_80432484(&b->resetAlarm, OSMillisecondsToTicks(1150), fn_80423CD4);
            break;
        }
    }
}

void fn_8042427C(DVDCommandBlock* block) {
    DVDCommandBlock* finished;

    lbl_806EF6B8 = fn_8042427C;
    switch (block->command) {
    case 5:
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = 0x20;
        fn_80426750(block->addr, fn_804245BC);
        break;
    case 1:
    case 4:
        if (block->length == 0) {
            finished = lbl_806EF660;
            lbl_806EF660 = &lbl_806DE1A0;
            finished->state = 0;
            if (finished->callback) {
                finished->callback(0, finished);
            }
            fn_80423F94();
            break;
        }
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = (block->length - block->transferredSize > 0x80000) ? 0x80000 : block->length - block->transferredSize;
        fn_804263F8((u8*)block->addr + block->transferredSize, block->currTransferSize, block->offset + block->transferredSize, fn_804245BC);
        break;
    case 2:
        __DIRegs[1] = __DIRegs[1];
        fn_80426690(block->offset, fn_804245BC);
        break;
    case 3:
        fn_804267F4(fn_804245BC);
        break;
    case 15:
        fn_804267F4(fn_804245BC);
        break;
    case 6:
        __DIRegs[1] = __DIRegs[1];
        if (lbl_806EF674) {
            lbl_806EF660->currTransferSize = 0;
            fn_80426A40(0, fn_804245BC);
        } else {
            lbl_806EF660->currTransferSize = 1;
            fn_804269A8(0, block->length, block->offset, fn_804245BC);
        }
        break;
    case 7:
        __DIRegs[1] = __DIRegs[1];
        fn_804269A8(0x10000, 0, 0, fn_804245BC);
        break;
    case 8:
        __DIRegs[1] = __DIRegs[1];
        lbl_806EF674 = 1;
        fn_804269A8(0, 0, 0, fn_804245BC);
        break;
    case 9:
        __DIRegs[1] = __DIRegs[1];
        fn_80426A40(0, fn_804245BC);
        break;
    case 10:
        __DIRegs[1] = __DIRegs[1];
        fn_80426A40(0x10000, fn_804245BC);
        break;
    case 11:
        __DIRegs[1] = __DIRegs[1];
        fn_80426A40(0x20000, fn_804245BC);
        break;
    case 12:
        __DIRegs[1] = __DIRegs[1];
        fn_80426A40(0x30000, fn_804245BC);
        break;
    case 13:
        __DIRegs[1] = __DIRegs[1];
        fn_80426ACC(block->offset, block->length, fn_804245BC);
        break;
    case 14:
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = 0x20;
        fn_8042690C(block->addr, fn_804245BC);
        break;
    case 16:
        __DIRegs[1] = __DIRegs[1];
        fn_804267F4(fn_804245BC);
        break;
    default:
        lbl_806EF1A8(block, fn_804245BC);
        break;
    }
}

int fn_80424C14(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback, s32 prio) {
    BOOL idle;
    BOOL enabled;
    u32 pad[2];

    block->command = 1;
    block->addr = addr;
    block->length = length;
    block->offset = offset;
    block->transferredSize = 0;
    block->callback = callback;
    if (lbl_806EF1A4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
        fn_80432FA8(block->addr, block->length);
    }
    enabled = OSDisableInterrupts();
    block->state = 2;
    idle = __DVDPushWaitingQueue(prio, block);
    if (lbl_806EF660 == NULL && lbl_806EF66C == 0) {
        fn_80423F94();
    }
    OSRestoreInterrupts(enabled);
    return idle;
}

int fn_80424CF0(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback) {
    BOOL idle;
    BOOL enabled;
    u32 pad[2];

    block->command = 4;
    block->addr = addr;
    block->length = length;
    block->offset = offset;
    block->transferredSize = 0;
    block->callback = callback;
    if (lbl_806EF1A4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
        fn_80432FA8(block->addr, block->length);
    }
    enabled = OSDisableInterrupts();
    block->state = 2;
    idle = __DVDPushWaitingQueue(2, block);
    if (lbl_806EF660 == NULL && lbl_806EF66C == 0) {
        fn_80423F94();
    }
    OSRestoreInterrupts(enabled);
    return idle;
}

int fn_80424DC0(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback) {
    BOOL idle;
    BOOL enabled;
    u32 pad[2];

    block->command = 5;
    block->addr = diskID;
    block->length = 0x20;
    block->offset = 0;
    block->transferredSize = 0;
    block->callback = callback;
    if (lbl_806EF1A4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
        fn_80432FA8(block->addr, block->length);
    }
    enabled = OSDisableInterrupts();
    block->state = 2;
    idle = __DVDPushWaitingQueue(2, block);
    if (lbl_806EF660 == NULL && lbl_806EF66C == 0) {
        fn_80423F94();
    }
    OSRestoreInterrupts(enabled);
    return idle;
}

int fn_80424E94(DVDCommandBlock* block, DVDCBCallback callback) {
    BOOL idle;
    BOOL enabled;
    u32 pad[2];

    block->command = 7;
    block->callback = callback;
    if (lbl_806EF1A4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
        fn_80432FA8(block->addr, block->length);
    }
    enabled = OSDisableInterrupts();
    block->state = 2;
    idle = __DVDPushWaitingQueue(1, block);
    if (lbl_806EF660 == NULL && lbl_806EF66C == 0) {
        fn_80423F94();
    }
    OSRestoreInterrupts(enabled);
    return idle;
}

int fn_80424F50(DVDCommandBlock* block, void* info, DVDCBCallback callback) {
    BOOL idle;
    BOOL enabled;
    u32 pad[2];

    block->command = 14;
    block->addr = info;
    block->length = 0x20;
    block->transferredSize = 0;
    block->callback = callback;
    if (lbl_806EF1A4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
        fn_80432FA8(block->addr, block->length);
    }
    enabled = OSDisableInterrupts();
    block->state = 2;
    idle = __DVDPushWaitingQueue(2, block);
    if (lbl_806EF660 == NULL && lbl_806EF66C == 0) {
        fn_80423F94();
    }
    OSRestoreInterrupts(enabled);
    return idle;
}

void fn_80425020(void) {
    fn_80426B68();
    __DIRegs[0] = 0x2A;
    __DIRegs[1] = __DIRegs[1];
    lbl_806EF698 = 0;
    lbl_806EF688 = 0;
}

s32 fn_80425064(const DVDCommandBlock* block) {
    BOOL enabled;
    s32 retVal;

    enabled = OSDisableInterrupts();
    if (block->state == 3) {
        retVal = 1;
    } else {
        retVal = block->state;
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

s32 fn_804250B0(void) {
    BOOL enabled;
    s32 retVal;
    DVDCommandBlock* c;

    enabled = OSDisableInterrupts();
    if (lbl_806EF678) {
        retVal = -1;
    } else if (lbl_806EF670) {
        retVal = 8;
    } else {
        c = lbl_806EF660;
        if (c == NULL) {
            retVal = 0;
        } else if (c == &lbl_806DE1A0) {
            retVal = 0;
        } else {
            retVal = fn_80425064(c);
        }
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

BOOL fn_8042515C(BOOL autoInvalidation) {
    BOOL prev = lbl_806EF1A4;

    lbl_806EF1A4 = autoInvalidation;
    return prev;
}

void fn_8042516C(void) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    lbl_806EF66C = 0;
    if (lbl_806EF670) {
        lbl_806EF670 = 0;
        fn_80423F94();
    }
    OSRestoreInterrupts(enabled);
}

int fn_804251BC(DVDCommandBlock* block, DVDCBCallback callback) {
    BOOL enabled;
    void* old;
    u32 pad[2];

    enabled = OSDisableInterrupts();
    switch (block->state) {
    case -1:
    case 0:
    case 10:
        if (callback) {
            callback(0, block);
        }
        break;
    case 1:
        if (lbl_806EF680) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        lbl_806EF684 = callback;
        lbl_806EF680 = 1;
        if (block->command == 4 || block->command == 1) {
            fn_80426C24();
        }
        break;
    case 2:
        __DVDDequeueWaitingQueue(block);
        block->state = 10;
        if (block->callback) {
            block->callback(-3, block);
        }
        if (callback) {
            callback(0, block);
        }
        break;
    case 3:
        switch (block->command) {
        case 4:
        case 5:
        case 13:
        case 15:
            if (callback) {
                callback(0, block);
            }
            break;
        default:
            if (lbl_806EF680) {
                OSRestoreInterrupts(enabled);
                return 0;
            }
            lbl_806EF684 = callback;
            lbl_806EF680 = 1;
            break;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        old = fn_80426C38();
        if (old != fn_80423EA8) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        if (block->state == 4) {
            lbl_806EF688 = 3;
        }
        if (block->state == 5) {
            lbl_806EF688 = 4;
        }
        if (block->state == 6) {
            lbl_806EF688 = 1;
        }
        if (block->state == 11) {
            lbl_806EF688 = 2;
        }
        if (block->state == 7) {
            lbl_806EF688 = 7;
        }
        lbl_806EF660 = &lbl_806DE1A0;
        block->state = 10;
        if (block->callback) {
            block->callback(-3, block);
        }
        if (callback) {
            callback(0, block);
        }
        fn_80423F94();
        break;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

int fn_80425438(DVDCommandBlock* block) {
    BOOL enabled;
    s32 state;
    u32 command;

    if (fn_804251BC(block, fn_804254E4) == 0) {
        return -1;
    }
    enabled = OSDisableInterrupts();
    while (1) {
        state = block->state;
        if (state == 0 || state == -1 || state == 10) {
            break;
        }
        if (state == 3) {
            command = block->command;
            if (command - 4 <= 1 || command == 13 || command == 15) {
                break;
            }
        }
        fn_804382CC(&lbl_806EF658);
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

void fn_804254E4(s32 result, DVDCommandBlock* block) {
    fn_804383B8(&lbl_806EF658);
}

DVDDiskID* fn_80425508(void) {
    return (DVDDiskID*)OS_BASE_CACHED;
}

BOOL fn_80425510(void) {
    BOOL enabled;
    BOOL retVal;
    s32 state;
    DVDCommandBlock* c;
    u32 cover;

    enabled = OSDisableInterrupts();
    if (lbl_806EF678) {
        state = -1;
    } else if (lbl_806EF670) {
        state = 8;
    } else {
        c = lbl_806EF660;
        if (c == NULL) {
            state = 0;
        } else if (c == &lbl_806DE1A0) {
            state = 0;
        } else {
            state = c->state;
        }
    }
    switch (state) {
    case 1:
    case 2:
    case 9:
    case 10:
        retVal = TRUE;
        break;
    case -1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        retVal = FALSE;
        break;
    case 0:
    case 8:
        cover = __DIRegs[1];
        if (((cover >> 2) & 1) || (cover & 1)) {
            retVal = FALSE;
        } else if (lbl_806EF688) {
            retVal = FALSE;
        } else {
            retVal = TRUE;
        }
        break;
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

/* near-miss 96.5%: callee-saved registers permuted (retail callback r30, inner enabled r31; ours the reverse); tried declaration orders and an inline Pause helper */
void fn_80425608(DVDCBCallback callback) {
    BOOL enabled;
    BOOL enabled2;
    BOOL e;
    DVDCommandBlock* p;

    enabled = OSDisableInterrupts();
    __DVDClearWaitingQueue();
    if (lbl_806EF680) {
        lbl_806EF684 = callback;
    } else {
        if (lbl_806EF660) {
            lbl_806EF660->callback = NULL;
        }
        enabled2 = OSDisableInterrupts();
        e = OSDisableInterrupts();
        lbl_806EF66C = 1;
        if (lbl_806EF660 == NULL) {
            lbl_806EF670 = 1;
        }
        OSRestoreInterrupts(e);
        while ((p = __DVDPopWaitingQueue()) != NULL) {
            fn_804251BC(p, NULL);
        }
        if (lbl_806EF660) {
            fn_804251BC(lbl_806EF660, callback);
        } else if (callback) {
            callback(0, NULL);
        }
        fn_8042516C();
        OSRestoreInterrupts(enabled2);
    }
    OSRestoreInterrupts(enabled);
}

BOOL fn_80425724(const OSAlarm* alarm) {
    if (alarm == &lbl_806DE1D0) {
        return TRUE;
    }
    return fn_80426C98(alarm);
}
