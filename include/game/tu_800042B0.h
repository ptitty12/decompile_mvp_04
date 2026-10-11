#ifndef GAME_TU_800042B0_H
#define GAME_TU_800042B0_H

/*
 * Shared declarations for src/game/tu_800042B0.cpp (disc-status screen handler
 * at 0x800042B0..0x800057D8).
 */

/*
 * Singleton (0x10 bytes) allocated by fn_80004610 and freed by fn_80004658.
 * Evidence: fn_800046A4 (ctor) stores m0 = 0, m4 = 5, mC = 0; fn_800042B0
 * stores m0 = 1 / 0 (screen shown), reads m4 (the status index returned by
 * fn_80004568); fn_80004710 / fn_800047A8 test and set mC. m8 is never touched
 * in this unit (the object is allocated with size 0x10).
 */
struct Unk8060F6F8 {
    int m0;
    int m4;
    int m8;
    int mC;
    Unk8060F6F8();
    ~Unk8060F6F8();
    void fn_80004830();
};

extern Unk8060F6F8* lbl_8060F6F8;   /* the singleton above (null when no screen object exists) */
extern int lbl_8060F6FC;            /* last status value passed to fn_800042B0 */
extern int lbl_8060F704;
extern int lbl_8060F708;

#endif /* GAME_TU_800042B0_H */
