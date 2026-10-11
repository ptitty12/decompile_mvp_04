/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): animation event classes, second half. Original file boundary unknown; placeholder.
 *
 * .text 0x802A89C8-0x802A9A04 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 *
 * Classes (names from vtable slot 3 -> name string): cHitByPitch (factory only
 * here), cStartSwing, cEndSlide, cEndWarp, cBeginWarp, cFacialAnim, cHandAnim,
 * cHandAnimIdle, cHandAnimClosed, cHandAnimHoldBall, cHeadTracking, cHatAnim,
 * cSwitchBallHand, cEndCheckSwing, cAudioTrigger, cLaunchTwoManMove, cDropBall,
 * cNoPlayerCollisions, cLooseBall, cLeaveToStand, cLeaveToRun, cLeaveToThrow,
 * cLeaveToTag, cEnterLate. They derive from the event mid class Unk8038B7E4
 * (include/game/events_b.h). Each class's ctor, slot 2 (attributes), slot 12
 * (dispatch) and slot 5 (factory) are here; slots 1 (implicit dtor), 3 (name), 4
 * (hash) and 14 (type id) are in the tail of the unity TU (0x802ABF18..0x802AC700),
 * so each class declares slot 3/4 first and g++ emits no vtable in this unit.
 */
#include "game/events_b.h"


/* cHitByPitch: vtable 0x806633C8, name string 0x805DBF10 (read by slot 3). */
class cHitByPitch : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHitByPitch();
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* size 8 from the factory */
};

/* Ctor (0x802A894C) is in the first half of the events. */
Unk8037B3E8* cHitByPitch::fn_vslot5()
{
    return new (lbl_806EF9B4) cHitByPitch;
}

/* cStartSwing: vtable 0x80663348, name string 0x805DBF1C (read by slot 3). */
class cStartSwing : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cStartSwing();
    virtual Unk8037B3E8* fn_vslot5();
};

cStartSwing::cStartSwing() : Unk8038B7E4(0x772C427Eu)
{
}

Unk8037B3E8* cStartSwing::fn_vslot5()
{
    return new (lbl_806EF9B4) cStartSwing;
}

/* cEndSlide: vtable 0x806632C8, name string 0x805DBF28 (read by slot 3). */
class cEndSlide : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cEndSlide();
    virtual Unk8037B3E8* fn_vslot5();
};

cEndSlide::cEndSlide() : Unk8038B7E4(lbl_8068D5C0)
{
}

Unk8037B3E8* cEndSlide::fn_vslot5()
{
    return new (lbl_806EF9B4) cEndSlide;
}

/* cEndWarp: vtable 0x806631C8, name string 0x805DBF40 (read by slot 3). */
class cEndWarp : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cEndWarp();
    virtual Unk8037B3E8* fn_vslot5();
};

cEndWarp::cEndWarp() : Unk8038B7E4(0xA0756559u)
{
}

Unk8037B3E8* cEndWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cEndWarp;
}

/* cBeginWarp: vtable 0x80663248, name string 0x805DBF34 (read by slot 3). */
class cBeginWarp : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cBeginWarp();
    virtual Unk8037B3E8* fn_vslot5();
};

cBeginWarp::cBeginWarp() : Unk8038B7E4(lbl_8068D5C4)
{
}

Unk8037B3E8* cBeginWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cBeginWarp;
}

/* cFacialAnim: vtable 0x80663148, name string 0x805DBF4C (read by slot 3). */
class cFacialAnim : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cFacialAnim();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);

    int m4;                    /* "AnimState" */
};

cFacialAnim::cFacialAnim() : Unk8038B7E4(0x9672E08Du)
{
    m4 = 0;
}

void cFacialAnim::fn_vslot2()
{
    fn_8037B5FC(lbl_805DE7E4, &m4);
}

void cFacialAnim::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x12, this, m4, t);
}

Unk8037B3E8* cFacialAnim::fn_vslot5()
{
    return new (lbl_806EF9B4) cFacialAnim;
}

/* cHandAnim: vtable 0x80663048, name string 0x805DBF64 (read by slot 3). */
class cHandAnim : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHandAnim();
    virtual void fn_vslot2();
    virtual void fn_vslot8();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);

    int m4;                    /* "AnimState" */
};

cHandAnim::cHandAnim() : Unk8038B7E4(0xA35FB088u)
{
    m4 = 0;
}

void cHandAnim::fn_vslot2()
{
    fn_8037B5FC(lbl_805DE7E4, &m4);
}

void cHandAnim::fn_vslot8()
{
    if (m4 == 0) {
        m4 = 0x5798D3FB;
    } else if (m4 == lbl_8068D5C8 || m4 == lbl_8068D5CC) {
        m4 = 0;
    }
}

Unk8037B3E8* cHandAnim::fn_vslot5()
{
    return new (lbl_806EF9B4) cHandAnim;
}

void cHandAnim::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x15, this, m4, t);
}

/* cHandAnimIdle: vtable 0x80662FC8, name string 0x805DBF70 (read by slot 3). */
class cHandAnimIdle : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHandAnimIdle();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);
};

cHandAnimIdle::cHandAnimIdle() : Unk8038B7E4(lbl_8068D5D0)
{
}

Unk8037B3E8* cHandAnimIdle::fn_vslot5()
{
    return new (lbl_806EF9B4) cHandAnimIdle;
}

void cHandAnimIdle::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x16, this, 0, t);
}

/* cHandAnimClosed: vtable 0x80662F48, name string 0x805DBF80 (read by slot 3). */
class cHandAnimClosed : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHandAnimClosed();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);
};

cHandAnimClosed::cHandAnimClosed() : Unk8038B7E4(lbl_8068D5D4)
{
}

Unk8037B3E8* cHandAnimClosed::fn_vslot5()
{
    return new (lbl_806EF9B4) cHandAnimClosed;
}

void cHandAnimClosed::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x17, this, 0, t);
}

/* cHandAnimHoldBall: vtable 0x80662EC8, name string 0x805DBF90 (read by slot 3). */
class cHandAnimHoldBall : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHandAnimHoldBall();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);
};

cHandAnimHoldBall::cHandAnimHoldBall() : Unk8038B7E4(lbl_8068D5D8)
{
}

Unk8037B3E8* cHandAnimHoldBall::fn_vslot5()
{
    return new (lbl_806EF9B4) cHandAnimHoldBall;
}

void cHandAnimHoldBall::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x18, this, 0, t);
}

/* cHeadTracking: vtable 0x80662E48, name string 0x805DBFA4 (read by slot 3). */
class cHeadTracking : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHeadTracking();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);

    int m4;                    /* "HeadTrackingOnOff" */
    float m8;                  /* "DurationSeconds" */
    float mC;                  /* "SecondsToTurn" */
};

cHeadTracking::cHeadTracking() : Unk8038B7E4(lbl_8068D5DC)
{
    m4 = 1;
    mC = m8 = lbl_805DE7F0;
}

void cHeadTracking::fn_vslot2()
{
    fn_8037B458(lbl_805DE7F4, &m4, lbl_805DBC10, lbl_805DCD6C);
    fn_8037B50C(lbl_805DE808, &m8, lbl_805DE818, lbl_805DCD6C);
    fn_8037B50C(lbl_805DE824, &mC, lbl_805DE834, lbl_805DCD6C);
}

Unk8037B3E8* cHeadTracking::fn_vslot5()
{
    return new (lbl_806EF9B4) cHeadTracking;
}

void cHeadTracking::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x20, this, 0, t);
}

/* cHatAnim: vtable 0x806630C8, name string 0x805DBF58 (read by slot 3). */
class cHatAnim : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHatAnim();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);

    int m4;                    /* "LaunchHat" */
};

cHatAnim::cHatAnim() : Unk8038B7E4(0x6A26B94Au)
{
    m4 = 0;
}

void cHatAnim::fn_vslot2()
{
    fn_8037B458(lbl_805DE83C, &m4, lbl_805DBC10, lbl_805DBD58);
}

Unk8037B3E8* cHatAnim::fn_vslot5()
{
    return new (lbl_806EF9B4) cHatAnim;
}

void cHatAnim::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    if (m4 == 0) {
        fn_8037893C(mgr, 0x13, this, (int)b * 2, t);
    } else {
        fn_8037893C(mgr, 0x14, this, (int)b * 2, t);
    }
}

/* cSwitchBallHand: vtable 0x80662DC8, name string 0x805DBFB4 (read by slot 3). */
class cSwitchBallHand : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cSwitchBallHand();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();

    float m4;                  /* "DurationSeconds" */
};

cSwitchBallHand::cSwitchBallHand() : Unk8038B7E4(0x54BEBC90u)
{
    m4 = lbl_805DE848;
}

void cSwitchBallHand::fn_vslot2()
{
    fn_8037B50C(lbl_805DE808, &m4, lbl_805DE818, lbl_805DCD6C);
}

Unk8037B3E8* cSwitchBallHand::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwitchBallHand;
}

/* cEndCheckSwing: vtable 0x80662D48, name string 0x805DBFC4 (read by slot 3). */
class cEndCheckSwing : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cEndCheckSwing();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);
};

/* fn_vslot2 (0x802A9380) is an empty function. */
cEndCheckSwing::cEndCheckSwing() : Unk8038B7E4(0xD76C1AC5u)
{
}

void cEndCheckSwing::fn_vslot2()
{
}

void cEndCheckSwing::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 5, this, 0, t);
}

Unk8037B3E8* cEndCheckSwing::fn_vslot5()
{
    return new (lbl_806EF9B4) cEndCheckSwing;
}

/* cAudioTrigger: vtable 0x80662CC8, name string 0x805DBFD4 (read by slot 3). */
class cAudioTrigger : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cAudioTrigger();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);

    int m4;                    /* "TriggerType" */
    int m8;                    /* size 0xC from the factory; unused here */
};

cAudioTrigger::cAudioTrigger() : Unk8038B7E4(0x9F4A38CEu)
{
}

void cAudioTrigger::fn_vslot2()
{
    fn_8037B674(lbl_805DE84C, &m4, lbl_805DE858, 0);
}

Unk8037B3E8* cAudioTrigger::fn_vslot5()
{
    return new (lbl_806EF9B4) cAudioTrigger;
}

void cAudioTrigger::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x22, this, 0, t);
}

/* cLaunchTwoManMove: vtable 0x80662C48, name string 0x805DBFE4 (read by slot 3). */
class cLaunchTwoManMove : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLaunchTwoManMove();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);

    int m4;                    /* "AnimState" */
};

cLaunchTwoManMove::cLaunchTwoManMove() : Unk8038B7E4(0x05A38D30u)
{
    m4 = 0;
}

Unk8037B3E8* cLaunchTwoManMove::fn_vslot5()
{
    return new (lbl_806EF9B4) cLaunchTwoManMove;
}

void cLaunchTwoManMove::fn_vslot2()
{
    fn_8037B5FC(lbl_805DE7E4, &m4);
}

void cLaunchTwoManMove::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x23, this, m4, t);
}

/* cDropBall: vtable 0x80662BC8, name string 0x805DBFF8 (read by slot 3). */
class cDropBall : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cDropBall();
    virtual Unk8037B3E8* fn_vslot5();
};

cDropBall::cDropBall() : Unk8038B7E4(0x122509F8u)
{
}

Unk8037B3E8* cDropBall::fn_vslot5()
{
    return new (lbl_806EF9B4) cDropBall;
}

/* cNoPlayerCollisions: vtable 0x80662B48, name string 0x805DC004 (read by slot 3). */
class cNoPlayerCollisions : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cNoPlayerCollisions();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);
};

cNoPlayerCollisions::cNoPlayerCollisions() : Unk8038B7E4(0xDFE56471u)
{
}

Unk8037B3E8* cNoPlayerCollisions::fn_vslot5()
{
    return new (lbl_806EF9B4) cNoPlayerCollisions;
}

void cNoPlayerCollisions::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x25, this, (int)b * 2, t);
}

/* cLooseBall: vtable 0x80662AC8, name string 0x805DC018 (read by slot 3). */
class cLooseBall : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLooseBall();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b);
};

cLooseBall::cLooseBall() : Unk8038B7E4(0x3F4BF7C5u)
{
}

Unk8037B3E8* cLooseBall::fn_vslot5()
{
    return new (lbl_806EF9B4) cLooseBall;
}

void cLooseBall::fn_evslot12(Unk8037893C_Mgr* mgr, Unk8037893C_Target* t, float a, float b)
{
    fn_8037893C(mgr, 0x26, this, (int)b * 2, t);
}

/* cLeaveToStand: vtable 0x80662A48, name string 0x805DC024 (read by slot 3). */
class cLeaveToStand : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLeaveToStand();
    virtual Unk8037B3E8* fn_vslot5();
};

cLeaveToStand::cLeaveToStand() : Unk8038B7E4(0xFF0D1452u)
{
}

Unk8037B3E8* cLeaveToStand::fn_vslot5()
{
    return new (lbl_806EF9B4) cLeaveToStand;
}

/* cLeaveToRun: vtable 0x806629C8, name string 0x805DC034 (read by slot 3). */
class cLeaveToRun : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLeaveToRun();
    virtual Unk8037B3E8* fn_vslot5();
};

cLeaveToRun::cLeaveToRun() : Unk8038B7E4(0x989091ADu)
{
}

Unk8037B3E8* cLeaveToRun::fn_vslot5()
{
    return new (lbl_806EF9B4) cLeaveToRun;
}

/* cLeaveToThrow: vtable 0x80662948, name string 0x805DC040 (read by slot 3). */
class cLeaveToThrow : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLeaveToThrow();
    virtual Unk8037B3E8* fn_vslot5();
};

cLeaveToThrow::cLeaveToThrow() : Unk8038B7E4(0xFF18E0CCu)
{
}

Unk8037B3E8* cLeaveToThrow::fn_vslot5()
{
    return new (lbl_806EF9B4) cLeaveToThrow;
}

/* cLeaveToTag: vtable 0x806628C8, name string 0x805DC050 (read by slot 3). */
class cLeaveToTag : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLeaveToTag();
    virtual Unk8037B3E8* fn_vslot5();
};

cLeaveToTag::cLeaveToTag() : Unk8038B7E4(0x98909794u)
{
}

Unk8037B3E8* cLeaveToTag::fn_vslot5()
{
    return new (lbl_806EF9B4) cLeaveToTag;
}

/* cEnterLate: vtable 0x80662848, name string 0x805DC05C (read by slot 3). */
class cEnterLate : public Unk8038B7E4 {
public:
    /* Slots 3/4: tail of the unity TU; declared first so no vtable is emitted here. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cEnterLate();
    virtual Unk8037B3E8* fn_vslot5();
};

cEnterLate::cEnterLate() : Unk8038B7E4(0x84CEBE2Cu)
{
}

Unk8037B3E8* cEnterLate::fn_vslot5()
{
    return new (lbl_806EF9B4) cEnterLate;
}
