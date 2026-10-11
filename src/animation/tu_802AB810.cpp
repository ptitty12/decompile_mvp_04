/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): unity-TU tail, first half: inline getters, implicit dtors (emitted at the end of the TU). Original file boundary unknown; placeholder.
 *
 * .text 0x802AB810-0x802AC2CC only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 *
 * Contents (all of it g++ 2.95's deferred inline functions):
 *  - 0x802AB810..0x802AB838: six inline virtuals (slots 4..9) of the player
 *    object class (vptr at +0x98; vtables 0x8065F7F0, 0x8065FF98, 0x806615A0,
 *    0x80663FB0, 0x80665500, ...). Vtables of many other TUs point at these
 *    addresses, so the retail link kept this TU's copy of each inline function.
 *  - 0x802AB840..0x802AC2CC: 31 animation event classes (cDirtEvent ..
 *    cHandAnimHoldBall). Each contributes its implicit destructor, the slot 3
 *    (class name) and slot 4 (type hash) getters and one or two more tiny
 *    virtuals (slot 14 / 15 / 16, an event id or a flag). The classes are
 *    declared in the events units; the minimal copies here only need the same
 *    virtual layout.
 * The implicit destructors are written out as `X::~X() {}` so that they land in
 * .text order. Each one expands its inline base destructors (Unk8035EA44 and
 * Unk8038B7E4) and ends in a call to the root destructor (0x8037B424), which
 * stores the root vtable and does the delete.
 */


/* Strings ('.rodata' of another part of the TU). */
extern const char lbl_805DBDDC[];    /* "cDirtEvent" */
extern const char lbl_805DBDE8[];    /* "cSpectacularAnimation" */
extern const char lbl_805DBE00[];    /* "cSignatureHRToFirstCelebration" */
extern const char lbl_805DBE20[];    /* "cAccessorize" */
extern const char lbl_805DBE30[];    /* "cReleaseBall" */
extern const char lbl_805DBE40[];    /* "cSwingContactPhase" */
extern const char lbl_805DBE54[];    /* "cSwingMisTimedNonContactPhase" */
extern const char lbl_805DBE74[];    /* "cSwingSweetSpot" */
extern const char lbl_805DBE84[];    /* "cSwingBreaksStrikePlane" */
extern const char lbl_805DBE9C[];    /* "cSwingComplete" */
extern const char lbl_805DBEAC[];    /* "cCatchBall" */
extern const char lbl_805DBEB8[];    /* "cTouchBase" */
extern const char lbl_805DBEC4[];    /* "cFirstTouchBase" */
extern const char lbl_805DBED4[];    /* "cTagRunner" */
extern const char lbl_805DBEE0[];    /* "cBlend1" */
extern const char lbl_805DBEE8[];    /* "cBlend2" */
extern const char lbl_805DBEF0[];    /* "cBlend3" */
extern const char lbl_805DBEF8[];    /* "cLeft" */
extern const char lbl_805DBF00[];    /* "cSlide" */
extern const char lbl_805DBF08[];    /* "cRight" */
extern const char lbl_805DBF10[];    /* "cHitByPitch" */
extern const char lbl_805DBF1C[];    /* "cStartSwing" */
extern const char lbl_805DBF28[];    /* "cEndSlide" */
extern const char lbl_805DBF34[];    /* "cBeginWarp" */
extern const char lbl_805DBF40[];    /* "cEndWarp" */
extern const char lbl_805DBF4C[];    /* "cFacialAnim" */
extern const char lbl_805DBF58[];    /* "cHatAnim" */
extern const char lbl_805DBF64[];    /* "cHandAnim" */
extern const char lbl_805DBF70[];    /* "cHandAnimIdle" */
extern const char lbl_805DBF80[];    /* "cHandAnimClosed" */

/* Lazily computed type hashes (set by fn_802AA7A4) and flags, read by the inline getters. */
extern unsigned int lbl_8068D5C0;
extern unsigned int lbl_8068D5C4;
extern unsigned int lbl_8068D5D0;
extern unsigned int lbl_8068D5D4;
extern unsigned int lbl_8068D5D8;
extern char lbl_806EF9C4;
extern char lbl_806EF9C5;
extern char lbl_806EF9C9;

/* ---- base classes (minimal copies; the real declarations live in other units) ---- */

/* Root of the choosers, warps and events (vtable 0x806849D0, dtor 0x8037B424).
 * Slots 2..5 are pure in the root; 6..9 are empty (0x8037D750..0x8037D75C). */
class Unk8037B3E8 {
public:
    virtual ~Unk8037B3E8();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();    /* class name */
    virtual int fn_vslot4();            /* type hash */
    virtual Unk8037B3E8* fn_vslot5();   /* factory */
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual int fn_vslot10();
};

/* Base of the events (vtable 0x806850A0). Its destructor (0x8038B7E4) is an inline
 * `{}` that every derived destructor expands: vptr store, then the root destructor.
 * Slot 11 is pure here. Signatures of the other slots are unknown. */
class Unk8038B7E4 : public Unk8037B3E8 {
public:
    virtual ~Unk8038B7E4() {}
    virtual void fn_vslot2();           /* 0x8038B81C, empty */
    virtual int fn_vslot10();           /* 0x8038B820, returns 1 */
    virtual int fn_vslot11();
    virtual void fn_vslot12();          /* 0x8037E68C */
    virtual int fn_vslot13();           /* 0x8038B814, returns 0 */
};

/* Events whose slot 11 is the shared inline 0x8035EA80 (calls slot 14). */
class Unk8035EA80 : public Unk8038B7E4 {
public:
    virtual int fn_vslot11();           /* 0x8035EA80 */
    virtual int fn_vslot14();
};

/* Events with slots 13..15 from vtable 0x80663E98 (dtor 0x8035EA44, an inline `{}` too). */
class Unk8035EA44 : public Unk8038B7E4 {
public:
    virtual ~Unk8035EA44() {}
    virtual int fn_vslot13();           /* 0x8035EA74, empty */
    virtual int fn_vslot14();
    virtual int fn_vslot15();           /* 0x8035EA78, returns 0 */
};

/* Events whose slot 11 is the shared inline 0x8035EAB4 (calls slot 16). */
class Unk8035EAB4 : public Unk8035EA44 {
public:
    virtual int fn_vslot11();           /* 0x8035EAB4 */
    virtual int fn_vslot16();
};

/* Player object (vptr at +0x98; see include/game/chooser.h for the fuller picture).
 * Here only the virtual layout up to slot 9 and the three fields the six inline
 * virtuals touch. */
struct Unk80270BA0_XBase {
    char pad0[0x98];
};

class Unk80270BA0_XVirt : public Unk80270BA0_XBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
};

class Unk80270BA0_XMid : public Unk80270BA0_XVirt {
public:
    virtual int fn_vslot4();
    virtual int fn_vslot5();
    virtual void* fn_vslot6();
    virtual void* fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9(int a);
    char pad9C[0x1A0 - 0x9C];
    char m1A0[0x240 - 0x1A0];
    int m240;
    char pad244[0x264 - 0x244];
    int m264;
};


/* ---- the event classes ----
 * Slot 2 (attributes) and slot 5 (factory) are defined in the events units; only the
 * virtuals this unit defines are declared. Slot 3 = class name, slot 4 = type hash. */
class cDirtEvent : public Unk8035EA80 {
public:
    virtual ~cDirtEvent();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSpectacularAnimation : public Unk8035EA80 {
public:
    virtual ~cSpectacularAnimation();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSignatureHRToFirstCelebration : public Unk8035EA80 {
public:
    virtual ~cSignatureHRToFirstCelebration();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cAccessorize : public Unk8035EAB4 {
public:
    virtual ~cAccessorize();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot16();
    virtual int fn_vslot14();
    virtual int fn_vslot15();
};

class cReleaseBall : public Unk8035EAB4 {
public:
    virtual ~cReleaseBall();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    virtual int fn_vslot16();
};

class cSwingContactPhase : public Unk8035EA80 {
public:
    virtual ~cSwingContactPhase();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSwingMisTimedNonContactPhase : public Unk8035EA80 {
public:
    virtual ~cSwingMisTimedNonContactPhase();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSwingSweetSpot : public Unk8035EA80 {
public:
    virtual ~cSwingSweetSpot();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSwingBreaksStrikePlane : public Unk8035EA80 {
public:
    virtual ~cSwingBreaksStrikePlane();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSwingComplete : public Unk8035EA80 {
public:
    virtual ~cSwingComplete();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cCatchBall : public Unk8035EAB4 {
public:
    virtual ~cCatchBall();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    virtual int fn_vslot16();
};

class cTouchBase : public Unk8035EAB4 {
public:
    virtual ~cTouchBase();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot16();
};

class cFirstTouchBase : public Unk8035EA80 {
public:
    virtual ~cFirstTouchBase();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cTagRunner : public Unk8035EAB4 {
public:
    virtual ~cTagRunner();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    virtual int fn_vslot16();
};

class cBlend1 : public Unk8035EA80 {
public:
    virtual ~cBlend1();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cBlend2 : public Unk8035EA80 {
public:
    virtual ~cBlend2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cBlend3 : public Unk8035EA80 {
public:
    virtual ~cBlend3();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLeft : public Unk8035EA80 {
public:
    virtual ~cLeft();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cSlide : public Unk8035EA80 {
public:
    virtual ~cSlide();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cRight : public Unk8035EA80 {
public:
    virtual ~cRight();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cHitByPitch : public Unk8035EA80 {
public:
    virtual ~cHitByPitch();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cStartSwing : public Unk8035EA80 {
public:
    virtual ~cStartSwing();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cEndSlide : public Unk8035EA80 {
public:
    virtual ~cEndSlide();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802ABFCC();    /* returns "cEndSlide" */
};

class cBeginWarp : public Unk8035EA80 {
public:
    virtual ~cBeginWarp();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC03C();    /* returns "cBeginWarp" */
};

class cEndWarp : public Unk8035EA80 {
public:
    virtual ~cEndWarp();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cFacialAnim : public Unk8035EA80 {
public:
    virtual ~cFacialAnim();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cHatAnim : public Unk8035EA80 {
public:
    virtual ~cHatAnim();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cHandAnim : public Unk8035EA80 {
public:
    virtual ~cHandAnim();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cHandAnimIdle : public Unk8035EA80 {
public:
    virtual ~cHandAnimIdle();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC1EC();    /* returns "cHandAnimIdle" */
};

class cHandAnimClosed : public Unk8035EA80 {
public:
    virtual ~cHandAnimClosed();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC25C();    /* returns "cHandAnimClosed" */
};

class cHandAnimHoldBall : public Unk8035EA80 {
public:
    virtual ~cHandAnimHoldBall();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC2CC();    /* returns "cHandAnimHoldBall" */
};

/* ---- definitions, in .text order ---- */

/* Inline virtuals 4..9 of the player object class (see the header comment). */
int Unk80270BA0_XMid::fn_vslot4() { return 0; }
int Unk80270BA0_XMid::fn_vslot5() { return 0; }
void* Unk80270BA0_XMid::fn_vslot6() { return m1A0; }
void* Unk80270BA0_XMid::fn_vslot7() { return m1A0; }
void Unk80270BA0_XMid::fn_vslot8(int a) { m264 = a; }
void Unk80270BA0_XMid::fn_vslot9(int a) { m240 = a; }

/* cDirtEvent: 0x802AB840 */
cDirtEvent::~cDirtEvent() {}
const char* cDirtEvent::fn_vslot3() { return lbl_805DBDDC; }
int cDirtEvent::fn_vslot4() { return 0xF8FAD63D; }
int cDirtEvent::fn_vslot14() { return 25; }

/* cSpectacularAnimation: 0x802AB890 */
cSpectacularAnimation::~cSpectacularAnimation() {}
const char* cSpectacularAnimation::fn_vslot3() { return lbl_805DBDE8; }
int cSpectacularAnimation::fn_vslot4() { return 0x429055BF; }
int cSpectacularAnimation::fn_vslot14() { return 29; }

/* cSignatureHRToFirstCelebration: 0x802AB8E0 */
cSignatureHRToFirstCelebration::~cSignatureHRToFirstCelebration() {}
const char* cSignatureHRToFirstCelebration::fn_vslot3() { return lbl_805DBE00; }
int cSignatureHRToFirstCelebration::fn_vslot4() { return 0xE80DB2C7; }
int cSignatureHRToFirstCelebration::fn_vslot14() { return 41; }

/* cAccessorize: 0x802AB930 */
cAccessorize::~cAccessorize() {}
const char* cAccessorize::fn_vslot3() { return lbl_805DBE20; }
int cAccessorize::fn_vslot4() { return 0x9E3C3363; }
int cAccessorize::fn_vslot16() { return 26; }
int cAccessorize::fn_vslot14() { return lbl_806EF9C4; }
int cAccessorize::fn_vslot15() { return 1; }

/* cReleaseBall: 0x802AB998 */
cReleaseBall::~cReleaseBall() {}
const char* cReleaseBall::fn_vslot3() { return lbl_805DBE30; }
int cReleaseBall::fn_vslot4() { return 0x2F71A764; }
int cReleaseBall::fn_vslot14() { return lbl_806EF9C5; }
int cReleaseBall::fn_vslot16() { return 9; }

/* cSwingContactPhase: 0x802AB9F8 */
cSwingContactPhase::~cSwingContactPhase() {}
const char* cSwingContactPhase::fn_vslot3() { return lbl_805DBE40; }
int cSwingContactPhase::fn_vslot4() { return 0x9DB287CD; }
int cSwingContactPhase::fn_vslot14() { return 2; }

/* cSwingMisTimedNonContactPhase: 0x802ABA48 */
cSwingMisTimedNonContactPhase::~cSwingMisTimedNonContactPhase() {}
const char* cSwingMisTimedNonContactPhase::fn_vslot3() { return lbl_805DBE54; }
int cSwingMisTimedNonContactPhase::fn_vslot4() { return 0xA47337B4; }
int cSwingMisTimedNonContactPhase::fn_vslot14() { return 6; }

/* cSwingSweetSpot: 0x802ABA98 */
cSwingSweetSpot::~cSwingSweetSpot() {}
const char* cSwingSweetSpot::fn_vslot3() { return lbl_805DBE74; }
int cSwingSweetSpot::fn_vslot4() { return 0xC45471DE; }
int cSwingSweetSpot::fn_vslot14() { return 3; }

/* cSwingBreaksStrikePlane: 0x802ABAE8 */
cSwingBreaksStrikePlane::~cSwingBreaksStrikePlane() {}
const char* cSwingBreaksStrikePlane::fn_vslot3() { return lbl_805DBE84; }
int cSwingBreaksStrikePlane::fn_vslot4() { return 0x4881D4AA; }
int cSwingBreaksStrikePlane::fn_vslot14() { return 1; }

/* cSwingComplete: 0x802ABB38 */
cSwingComplete::~cSwingComplete() {}
const char* cSwingComplete::fn_vslot3() { return lbl_805DBE9C; }
int cSwingComplete::fn_vslot4() { return 0xFCF3F4A9; }
int cSwingComplete::fn_vslot14() { return 4; }

/* cCatchBall: 0x802ABB88 */
cCatchBall::~cCatchBall() {}
const char* cCatchBall::fn_vslot3() { return lbl_805DBEAC; }
int cCatchBall::fn_vslot4() { return 0x971949A6; }
int cCatchBall::fn_vslot14() { return lbl_806EF9C4; }
int cCatchBall::fn_vslot16() { return 10; }

/* cTouchBase: 0x802ABBE8 */
cTouchBase::~cTouchBase() {}
const char* cTouchBase::fn_vslot3() { return lbl_805DBEB8; }
int cTouchBase::fn_vslot4() { return 0x8BF0ACA6; }
int cTouchBase::fn_vslot16() { return 27; }

/* cFirstTouchBase: 0x802ABC38 */
cFirstTouchBase::~cFirstTouchBase() {}
const char* cFirstTouchBase::fn_vslot3() { return lbl_805DBEC4; }
int cFirstTouchBase::fn_vslot4() { return 0xCF4ABDEE; }
int cFirstTouchBase::fn_vslot14() { return 39; }

/* cTagRunner: 0x802ABC88 */
cTagRunner::~cTagRunner() {}
const char* cTagRunner::fn_vslot3() { return lbl_805DBED4; }
int cTagRunner::fn_vslot4() { return 0x440397DE; }
int cTagRunner::fn_vslot14() { return lbl_806EF9C9; }
int cTagRunner::fn_vslot16() { return 28; }

/* cBlend1: 0x802ABCE8 */
cBlend1::~cBlend1() {}
const char* cBlend1::fn_vslot3() { return lbl_805DBEE0; }
int cBlend1::fn_vslot4() { return 0x6A552F3E; }
int cBlend1::fn_vslot14() { return 11; }

/* cBlend2: 0x802ABD38 */
cBlend2::~cBlend2() {}
const char* cBlend2::fn_vslot3() { return lbl_805DBEE8; }
int cBlend2::fn_vslot4() { return 0x6A552F3F; }
int cBlend2::fn_vslot14() { return 11; }

/* cBlend3: 0x802ABD88 */
cBlend3::~cBlend3() {}
const char* cBlend3::fn_vslot3() { return lbl_805DBEF0; }
int cBlend3::fn_vslot4() { return 0x6A552F40; }
int cBlend3::fn_vslot14() { return 11; }

/* cLeft: 0x802ABDD8 */
cLeft::~cLeft() {}
const char* cLeft::fn_vslot3() { return lbl_805DBEF8; }
int cLeft::fn_vslot4() { return 0x0F29E213; }
int cLeft::fn_vslot14() { return 13; }

/* cSlide: 0x802ABE28 */
cSlide::~cSlide() {}
const char* cSlide::fn_vslot3() { return lbl_805DBF00; }
int cSlide::fn_vslot4() { return 0xF4E8B1B9; }
int cSlide::fn_vslot14() { return 12; }

/* cRight: 0x802ABE78 */
cRight::~cRight() {}
const char* cRight::fn_vslot3() { return lbl_805DBF08; }
int cRight::fn_vslot4() { return 0xF4D4EC26; }
int cRight::fn_vslot14() { return 14; }

/* cHitByPitch: 0x802ABEC8 */
cHitByPitch::~cHitByPitch() {}
const char* cHitByPitch::fn_vslot3() { return lbl_805DBF10; }
int cHitByPitch::fn_vslot4() { return 0x6EC29540; }
int cHitByPitch::fn_vslot14() { return 15; }

/* cStartSwing: 0x802ABF18 */
cStartSwing::~cStartSwing() {}
const char* cStartSwing::fn_vslot3() { return lbl_805DBF1C; }
int cStartSwing::fn_vslot4() { return 0x772C427E; }
int cStartSwing::fn_vslot14() { return 16; }

/* cEndSlide: 0x802ABF68 */
cEndSlide::~cEndSlide() {}
const char* cEndSlide::fn_vslot3() { return fn_802ABFCC(); }
int cEndSlide::fn_vslot4() { return lbl_8068D5C0; }
int cEndSlide::fn_vslot14() { return 17; }
const char* cEndSlide::fn_802ABFCC() { return lbl_805DBF28; }

/* cBeginWarp: 0x802ABFD8 */
cBeginWarp::~cBeginWarp() {}
const char* cBeginWarp::fn_vslot3() { return fn_802AC03C(); }
int cBeginWarp::fn_vslot4() { return lbl_8068D5C4; }
int cBeginWarp::fn_vslot14() { return 30; }
const char* cBeginWarp::fn_802AC03C() { return lbl_805DBF34; }

/* cEndWarp: 0x802AC048 */
cEndWarp::~cEndWarp() {}
const char* cEndWarp::fn_vslot3() { return lbl_805DBF40; }
int cEndWarp::fn_vslot4() { return 0xA0756559; }
int cEndWarp::fn_vslot14() { return 31; }

/* cFacialAnim: 0x802AC098 */
cFacialAnim::~cFacialAnim() {}
const char* cFacialAnim::fn_vslot3() { return lbl_805DBF4C; }
int cFacialAnim::fn_vslot4() { return 0x9672E08D; }
int cFacialAnim::fn_vslot14() { return 18; }

/* cHatAnim: 0x802AC0E8 */
cHatAnim::~cHatAnim() {}
const char* cHatAnim::fn_vslot3() { return lbl_805DBF58; }
int cHatAnim::fn_vslot4() { return 0x6A26B94A; }
int cHatAnim::fn_vslot14() { return 19; }

/* cHandAnim: 0x802AC138 */
cHandAnim::~cHandAnim() {}
const char* cHandAnim::fn_vslot3() { return lbl_805DBF64; }
int cHandAnim::fn_vslot4() { return 0xA35FB088; }
int cHandAnim::fn_vslot14() { return 21; }

/* cHandAnimIdle: 0x802AC188 */
cHandAnimIdle::~cHandAnimIdle() {}
const char* cHandAnimIdle::fn_vslot3() { return fn_802AC1EC(); }
int cHandAnimIdle::fn_vslot4() { return lbl_8068D5D0; }
int cHandAnimIdle::fn_vslot14() { return 22; }
const char* cHandAnimIdle::fn_802AC1EC() { return lbl_805DBF70; }

/* cHandAnimClosed: 0x802AC1F8 */
cHandAnimClosed::~cHandAnimClosed() {}
const char* cHandAnimClosed::fn_vslot3() { return fn_802AC25C(); }
int cHandAnimClosed::fn_vslot4() { return lbl_8068D5D4; }
int cHandAnimClosed::fn_vslot14() { return 23; }
const char* cHandAnimClosed::fn_802AC25C() { return lbl_805DBF80; }

/* cHandAnimHoldBall: 0x802AC268 */
cHandAnimHoldBall::~cHandAnimHoldBall() {}
const char* cHandAnimHoldBall::fn_vslot3() { return fn_802AC2CC(); }
int cHandAnimHoldBall::fn_vslot4() { return lbl_8068D5D8; }
int cHandAnimHoldBall::fn_vslot14() { return 24; }
/* cHandAnimHoldBall::fn_802AC2CC() is the first function of the next unit (tu_802AC2CC.cpp). */
