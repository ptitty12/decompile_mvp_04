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
extern u8 lbl_806DE160[];
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

void fn_804227D4(void);
BOOL fn_80422B00(s32 entrynum, DVDFileInfo* fileInfo);
BOOL fn_80422C3C(DVDFileInfo* fileInfo);
void fn_80422FA4(s32 result, DVDCommandBlock* block);
void fn_80422FD4(s32 result, DVDCommandBlock* block);
void fn_804232A4(void);
void fn_804236C0(void);
void fn_80423908(void);
void fn_8042393C(void);
void fn_804239D8(void);
void fn_80423DEC(void);
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

void fn_80422FA4(s32 result, DVDCommandBlock* block) {
    DVDFileInfo* fileInfo = (DVDFileInfo*)block;

    if (fileInfo->callback) {
        fileInfo->callback(result, fileInfo);
    }
}

void fn_80422FD4(s32 result, DVDCommandBlock* block) {
}

void fn_804232A4(void) {
    fn_80426880(fn_80423380);
}

void fn_804236C0(void) {
    fn_804267F4(fn_804236E8);
}

void fn_80423908(void) {
    fn_80426ACC(lbl_806EF664->streaming, 10, fn_80423BE4);
}

void fn_8042393C(void) {
    fn_80426ACC(lbl_806EF664->streaming, 10, fn_80423970);
}

void fn_804239D8(void) {
    fn_804263F8(lbl_806DE160, 0x20, 0x420, fn_80423B0C);
}

void fn_80423DEC(void) {
    fn_80426750(&lbl_806DE180, fn_80423E1C);
}

void fn_80423E80(void) {
    fn_80426724(fn_80423EA8);
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

DVDDiskID* fn_80425508(void) {
    return (DVDDiskID*)OS_BASE_CACHED;
}

void fn_804254E4(s32 result, DVDCommandBlock* block) {
    fn_804383B8(&lbl_806EF658);
}

BOOL fn_80425724(const OSAlarm* alarm) {
    if (alarm == &lbl_806DE1D0) {
        return TRUE;
    }
    return fn_80426C98(alarm);
}
