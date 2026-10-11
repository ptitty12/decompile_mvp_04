/*
 * Shared declarations for the animation event classes (reconstructed).
 *
 * Nothing here comes from original headers; see include/game/chooser.h for the
 * conventions. The events share the root class (ctor 0x8037B3E8) with the
 * choosers and warps. chooser.h folds the choosers' own virtuals (slots
 * 11-17) into that root, so the event-only virtuals below are named
 * fn_evslotN with N = their retail vtable slot; in this header they follow the
 * root's 17 chooser slots in the vtable. That doesn't matter while only
 * constructors, slot 2 and the factories are compiled, but it must be fixed
 * (split the root at slot 10) before a unit compiles a virtual call to one of
 * them.
 *
 * Hierarchy, from the vtables at 0x806850A0, 0x80663E98 and the concrete
 * classes' (animation/events/tu_802A79BC.cpp, tu_802A89C8.cpp):
 *
 *   Unk8037B3E8            root (ctor 0x8037B3E8, vtable 0x806849D0, slots 1-10)
 *   Unk8038B7E4            event base, abstract (dtor 0x8038B7E4, vtable 0x806850A0):
 *                          slot 2 empty (0x8038B81C), 3/4/5 pure, 10 returns 1
 *                          (0x8038B820), 11 pure, 12 = 0x8037E68C, 13 returns 0
 *                          (0x8038B814)
 *     Unk8035EA80          typed event, no data: slot 11 forwards to slot 14
 *                          (0x8035EA80); slot 14 pure. Its ctor stores only the
 *                          final vptr in every concrete class (the vptr store of
 *                          the mid classes is dead), so it is data-less.
 *     Unk8035EA44          event with a Vec4 at +0x10 (dtor 0x8035EA44, vtable
 *                          0x80663E98): 13 empty (0x8035EA74), 14 pure, 15 returns
 *                          0 (0x8035EA78). The concrete ctors store this vtable
 *                          (lis 0x8066, 0x3E98) before calling the Vec4 ctor, so
 *                          the store survives there.
 *       Unk8035EAB4        slot 11 forwards to slot 16 (0x8035EAB4); 16 pure.
 *
 * Slot 14 returns the event's type id (a constant, or one of the byte globals
 * .sbss 0x806EF9C4..0x806EF9CB; who writes them is not known yet); slot 16
 * returns a constant. The concrete
 * classes' slot 3/4 getters, slot 14/16 getters and implicit dtors are in the
 * tail of the unity TU (0x802AB840..0x802ABF18), where g++ emits the vtables.
 * Declare slots 3 and 4 first in each class so that no vtable is emitted in the
 * event units.
 *
 * Matching notes:
 *  - The four base classes below have explicit inline virtual dtors. With only
 *    implicit ones, a concrete class's implicit dtor calls its parent's dtor;
 *    with them, it comes out as retail's `vptr = 0x806850A0 (Unk8038B7E4's
 *    vtable); bl root dtor` (checked with a scratch TU that defines slots 3, 4,
 *    14 and 16 of cReleaseBall and cSwingContactPhase; it also gives the mid
 *    classes' inline virtuals as linkonce functions with retail's shapes).
 *  - All virtuals of Unk8035EA80/Unk8035EA44/Unk8035EAB4 are inline, so g++ emits
 *    their vtables as weak data in every unit that stores their vptr (the
 *    event units store Unk8035EA44's), not as references: no key function.
 *  - Slot 14 returns char (the type-id globals are signed bytes).
 */
#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H

#include "game/warp_b.h"

/* Event base. Its virtuals other than slot 12 are inline (copies at
 * 0x8038B7E4..0x8038B820); slot 12 is a real function in another unit. */
class Unk8038B7E4 : public Unk8037B3E8 {
public:
    Unk8038B7E4(unsigned int hash) : Unk8037B3E8(hash) {}
    virtual ~Unk8038B7E4() {}
    virtual void fn_vslot2() {}                     /* 0x8038B81C */
    virtual const char* fn_vslot3() = 0;            /* class name */
    virtual int fn_vslot4() = 0;                    /* class name hash */
    virtual Unk8037B3E8* fn_vslot5() = 0;           /* factory */
    virtual int fn_evslot10() { return 1; }         /* 0x8038B820 */
    virtual int fn_evslot11() = 0;
    /* 0x8037E68C: calls virtual slot 11, then fn_8037893C(a, <slot 11 result>, this, 1, b). */
    virtual void fn_evslot12(void* a, int b, float f1, float f2);
    virtual int fn_evslot13() { return 0; }         /* 0x8038B814 */
};

/* Typed event without data (slot 11 at 0x8035EA80 calls slot 14). */
class Unk8035EA80 : public Unk8038B7E4 {
public:
    Unk8035EA80(unsigned int hash) : Unk8038B7E4(hash) {}
    virtual ~Unk8035EA80() {}
    virtual int fn_evslot11() { return fn_evslot14(); }
    virtual char fn_evslot14() = 0;
};

/* Event with a Vec4 at +0x10. Evidence: the concrete ctors call the Vec4 default
 * ctor (0x80379324) on this+0x10 right after the root ctor and the first vptr
 * store; the 12 bytes at +0x4..+0xC are never written by any ctor here. */
class Unk8035EA44 : public Unk8038B7E4 {
public:
    Unk8035EA44(unsigned int hash) : Unk8038B7E4(hash) {}
    virtual ~Unk8035EA44() {}
    virtual int fn_evslot13() {}                    /* 0x8035EA74, empty */
    virtual char fn_evslot14() = 0;
    virtual int fn_evslot15() { return 0; }         /* 0x8035EA78 */

    char pad4[0x10 - 0x4];
    Unk80379324 m10;
};

/* Slot 11 at 0x8035EAB4 calls slot 16. */
class Unk8035EAB4 : public Unk8035EA44 {
public:
    Unk8035EAB4(unsigned int hash) : Unk8035EA44(hash) {}
    virtual ~Unk8035EAB4() {}
    virtual int fn_evslot11() { return fn_evslot16(); }
    virtual int fn_evslot16() = 0;
};

/* ---- Concrete events, first half (animation/events/tu_802A79BC.cpp) ----
 * Each lists slots 3 and 4 first (defined in the unity-TU tail), then its
 * ctor, then the slots defined in the event unit, then those in the tail. */

class cReleaseBall : public Unk8035EAB4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cReleaseBall();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
    virtual int fn_evslot16();

    float m20;                 /* "ThrowSpeedMPH" */
    int m24;                   /* "ThrowDifficulty" */
};

class cSwingContactPhase : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSwingContactPhase();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cSwingMisTimedNonContactPhase : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSwingMisTimedNonContactPhase();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cSwingSweetSpot : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSwingSweetSpot();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cSwingBreaksStrikePlane : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSwingBreaksStrikePlane();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cSwingComplete : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSwingComplete();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cCatchBall : public Unk8035EAB4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cCatchBall();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(void* a, int b, float f1, float f2);
    virtual char fn_evslot14();
    virtual int fn_evslot16();

    int m20;                   /* "Type_StJmpDvClmb" */
    int m24;                   /* "Difficulty" */
    float m28;                 /* "Direction" */
    float m2C;                 /* "CatchSpread" */
    int m30;                   /* "Juggle" */
    int m34;                   /* "BackHand" */
    int m38;                   /* "BareHand" */
    int m3C;                   /* "OverShoulder" */
    int m40;                   /* "UseDuration" */
    int m44;                   /* "Drop" */
    float m48;                 /* set from slot 12's second float when m40 is set */
};

class cTouchBase : public Unk8035EAB4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cTouchBase();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
    virtual int fn_evslot16();

    int m20;                   /* "Limb_RfLfRhLh" */
};

class cFirstTouchBase : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cFirstTouchBase();
    virtual void fn_vslot2();                       /* empty, own function (0x802A80AC) */
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cTagRunner : public Unk8035EAB4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cTagRunner();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
    virtual int fn_evslot16();

    int m20;                   /* "TagDirection" */
    int m24;                   /* "TagSpread" */
};

class cBlend1 : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cBlend1();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cBlend2 : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cBlend2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cBlend3 : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cBlend3();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cLeft : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cLeft();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();

    float m4;                  /* "PlayerSpeed" */
    float m8;                  /* "PlayerLeaning" */
};

class cSlide : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSlide();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cDirtEvent : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cDirtEvent();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();

    int m4;                    /* "Left_Butt" */
    int m8;                    /* "Right_Butt" */
    int mC;                    /* "Left_Quad" */
    int m10;                   /* "Right_Quad" */
    int m14;                   /* "Left_Shin" */
    int m18;                   /* "Right_Shin" */
    int m1C;                   /* "Chest" */
    int m20;                   /* "Front_Left_Rip" */
    int m24;                   /* "Front_Right_Rip" */
    int m28;                   /* "Back_Left_Rip" */
    int m2C;                   /* "Back_Right_Rip" */
};

class cSpectacularAnimation : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSpectacularAnimation();
    virtual void fn_vslot2();                       /* empty, own function (0x802A86F0) */
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cSignatureHRToFirstCelebration : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cSignatureHRToFirstCelebration();
    virtual void fn_vslot2();                       /* empty, own function (0x802A8768) */
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
};

class cAccessorize : public Unk8035EAB4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cAccessorize();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();
    virtual int fn_evslot15();                      /* returns 1 (0x802AB990) */
    virtual int fn_evslot16();

    int m20;                   /* "BatInHand" */
};

class cRight : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cRight();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual char fn_evslot14();

    float m4;                  /* "PlayerSpeed" */
    float m8;                  /* "PlayerLeaning" */
};

class cHitByPitch : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    cHitByPitch();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();              /* 0x802A89C8 (second half) */
    virtual char fn_evslot14();

    int m4;                    /* "hitwhere" */
};

#endif /* GAME_EVENTS_H */
