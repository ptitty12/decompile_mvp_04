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
extern s32 lbl_806EF67C;
extern volatile u32 lbl_806EF680;
extern DVDCBCallback lbl_806EF684;
extern volatile s32 lbl_806EF688;
extern volatile s32 lbl_806EF694;
extern s32 lbl_806EF698;
extern void (*lbl_806EF6B8)(DVDCommandBlock*);
extern DVDCommandBlock lbl_806DE1A0;

#define BB2 (lbl_806DE160.bb2)
#define TMPID (&lbl_806DE160.tmp)

void fn_80425A70(u32 error);
void fn_80426B68(void);
void fn_80432FA8(void* addr, u32 nBytes);
void fn_80425BE4(void);
void fn_80423F94(void);
void fn_8042427C(DVDCommandBlock* block);
void fn_80423270(void);
void fn_80425020(void);
void fn_804231C4(u32 intType);
void fn_80423144(u32 intType);
void fn_80423640(u32 intType);
void fn_80423A10(u32 intType);
void fn_80423828(void);
void fn_804230B0(DVDCommandBlock* block);
s32 fn_8042280C(const char* path);
void fn_80423CD4(s32 result, DVDCommandBlock* block);
BOOL fn_80422E84(const char* path);
void fn_804235E4(u32 intType);
void fn_8042516C(void);

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
        OSPanic("dvd.c", 0x295, "DVDChangeDisk(): FST in the new disc is too big.   ");
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

void fn_80423CD4(s32 result, DVDCommandBlock* block) {
    fn_80425020();
    fn_80432FA8(&lbl_806DE180, 0x20);
    lbl_806EF6B8 = fn_80423DEC;
    fn_80423DEC(lbl_806EF660);
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

void fn_804254E4(s32 result, DVDCommandBlock* block) {
    fn_804383B8(&lbl_806EF658);
}

DVDDiskID* fn_80425508(void) {
    return (DVDDiskID*)OS_BASE_CACHED;
}

BOOL fn_80425724(const OSAlarm* alarm) {
    if (alarm == &lbl_806DE1D0) {
        return TRUE;
    }
    return fn_80426C98(alarm);
}
