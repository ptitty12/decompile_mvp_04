/*
 * Dolphin SDK DVD (MWCC GC/1.2.5n, cflags_dolphin_sdk with -char signed),
 * .text 0x80425BE4-0x80425E54 (3 functions; TU boundaries approximate, placeholder).
 * The unit owns its strings (.data/.sdata) and fstload.c's two .bss statics (bb2Buf 0x806DE218 and
 * __fstLoad's function-local block 0x806DE258, splits.txt). Its .sbss statics (status, bb2, idTmp at
 * 0x806EF6C8..0x806EF6D4) and dvdFatal.c's FatalFunc stay extern by their lbl_ names: see
 * docs/DECISIONS.md on .sbss splits.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include <dolphin.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>

#include <string.h>

/* callees under their symbols.txt names (likely DVDReadAbsAsyncForBS, DVDReadDiskID, DVDReset,
   DVDGetDriveStatus, OSGetArenaHi, OSSetArenaHi) */
int fn_80424CF0(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback);
int fn_80424DC0(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback);
void fn_80425020(void);
s32 DVDGetDriveStatus(void);
void* OSGetArenaHi(void);
void fn_80432CC4(void* newHi);

extern void (*lbl_806EF6C0)(void);
extern s32 lbl_806EF6C8;
extern DVDBB2* lbl_806EF6CC;
extern DVDDiskID* lbl_806EF6D0;
/* bb2Buf: OSRoundUp32B(sizeof(DVDBB2)) + 31 bytes, 0x3F */
static u8 lbl_806DE218[63];

void fn_80425BE4(void);
void fn_80425C14(s32 result, DVDCommandBlock* block);
void fn_80425CEC(void);

void fn_80425BE4(void) {
    if (lbl_806EF6C0 != NULL) {
        lbl_806EF6C0();
    }
}

void fn_80425C14(s32 result, DVDCommandBlock* block) {
    if (result > 0) {
        switch (lbl_806EF6C8) {
        case 0:
            lbl_806EF6C8 = 1;
            fn_80424CF0(block, lbl_806EF6CC, 32, 0x420, fn_80425C14);
            break;
        case 1:
            lbl_806EF6C8 = 2;
            fn_80424CF0(block, lbl_806EF6CC->FSTAddress, OSRoundUp32B(lbl_806EF6CC->FSTLength), lbl_806EF6CC->FSTPosition, fn_80425C14);
            break;
        }
    } else {
        if (result == -1) {
        } else if (result == -4) {
            lbl_806EF6C8 = 0;
            fn_80425020();
            fn_80424DC0(block, lbl_806EF6D0, fn_80425C14);
        }
    }
}

void fn_80425CEC(void) {
    OSBootInfo* bootInfo;
    DVDDiskID* id;
    u8 idTmpBuf[63];
    static DVDCommandBlock block;
    void* arenaHi;

    arenaHi = OSGetArenaHi();
    lbl_806EF6D0 = (DVDDiskID*)OSRoundUp32B(idTmpBuf);
    lbl_806EF6CC = (DVDBB2*)OSRoundUp32B(lbl_806DE218);
    fn_80425020();
    fn_80424DC0(&block, lbl_806EF6D0, fn_80425C14);
    while (DVDGetDriveStatus() != 0) {
    }
    bootInfo = (OSBootInfo*)0x80000000;
    id = (DVDDiskID*)0x80000000;
    bootInfo->FSTLocation = lbl_806EF6CC->FSTAddress;
    bootInfo->FSTMaxLength = lbl_806EF6CC->FSTMaxLength;
    memcpy(id, lbl_806EF6D0, 32);
    OSReport("\n");
    OSReport("  Game Name ... %c%c%c%c\n", id->gameName[0], id->gameName[1], id->gameName[2], id->gameName[3]);
    OSReport("  Company ..... %c%c\n", id->company[0], id->company[1]);
    OSReport("  Disk # ...... %d\n", id->diskNumber);
    OSReport("  Game ver .... %d\n", id->gameVersion);
    OSReport("  Streaming ... %s\n", id->streaming == 0 ? "OFF" : "ON");
    OSReport("\n");
    fn_80432CC4(lbl_806EF6CC->FSTAddress);
}
