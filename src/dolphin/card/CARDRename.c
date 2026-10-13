/* Imported from doldecomp/dolsdk2004 @ 2328b416 (src/card/CARDRename.c). Nintendo Dolphin SDK 2004 Patch 1, card library; names are Nintendo's. */
#include <dolphin/card.h>

#include "__card.h"

extern OSTime fn_80438628(void); /* OSGetTime */
extern void fn_8041A6C8(s32 chan, s32 result); /* __CARDSyncCallback */
extern s32 fn_8041B848(s32 chan, CARDControl** pcard); /* __CARDGetControlBlock */
extern s32 fn_8041B900(CARDControl* card, s32 result); /* __CARDPutControlBlock */
extern s32 fn_8041BB38(s32 chan); /* __CARDSync */


s32 CARDRenameAsync(s32 chan, const char* old, const char* new, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    int fileNo;
    int newNo;
    int oldNo;

    ASSERTLINE(0x56, 0 <= chan && chan < 2);
    ASSERTLINE(0x57, *old != 0xff && *new != 0xff);
    ASSERTLINE(0x58, *old != 0x00 && *new != 0x00);

    if (old[0] == 0xFF || new[0] == 0xFF || old[0] == 0 || new[0] == 0)
        return CARD_RESULT_FATAL_ERROR;
    if (CARD_FILENAME_MAX < (u32)strlen(old) || CARD_FILENAME_MAX < (u32)strlen(new))
        return CARD_RESULT_NAMETOOLONG;

    result = fn_8041B848(chan, &card);
    if (result < 0)
        return result;

    newNo = oldNo = -1;
    dir = __CARDGetDirBlock(card);
    for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
        ent = &dir[fileNo];
        if (ent->gameName[0] == 0xFF)
            continue;

        if (memcmp(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) != 0
         || memcmp(ent->company, card->diskID->company, sizeof(ent->company)) != 0)
            continue;

        if (__CARDCompareFileName(ent, old))
            oldNo = fileNo;
        if (__CARDCompareFileName(ent, new))
            newNo = fileNo;
    }

    if (oldNo == -1)
        return fn_8041B900(card, CARD_RESULT_NOFILE);
    if (newNo != -1)
        return fn_8041B900(card, CARD_RESULT_EXIST);

    ent = &dir[oldNo];
    result = __CARDIsWritable(card, ent);
    if (result < 0)
        return fn_8041B900(card, result);

    strncpy((char*)ent->fileName, new, CARD_FILENAME_MAX);
    ent->time = (u32)OSTicksToSeconds(fn_80438628());

    result = __CARDUpdateDir(chan, callback);
    if (result < 0)
        fn_8041B900(card, result);

    return result;
}

s32 CARDRename(s32 chan, const char* old, const char* new) {
	s32 result = CARDRenameAsync(chan, old, new, fn_8041A6C8);
	if (result < 0)
		return result;

	return fn_8041BB38(chan);
}
