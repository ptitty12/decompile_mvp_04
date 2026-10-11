/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): unity-TU tail, second half: the inline virtuals and implicit
 * destructors that g++ 2.95 emits at the end of the TU (class-name and type-hash
 * getters of the event, chooser and warp classes, their implicit destructors, and
 * a few other tiny inline virtuals). Original file boundary unknown; placeholder.
 *
 * .text 0x802AC2CC-0x802ACD88 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 *
 * Every class below is a minimal redeclaration (same name and virtual layout up
 * to what these functions touch) of a class whose other methods are in another
 * unit. The first virtual of each class is one of those other methods and is
 * left undefined here, so no vtable is emitted in this object. The functions are
 * defined out of line, in retail .text order. Retail emits them as deferred
 * inline functions; the code is the same.
 */
#include "game/chooser.h"

/* ---- Event classes (vtable 0x806850A0 and its derived classes) ----
 * Root of the events: dtor 0x8037B424 (vptr 0x806849D0, deleting part). The
 * mid class has an inline dtor (vptr store 0x806850A0, then the root dtor with
 * the in-charge argument passed on); every derived class's dtor expands it, so
 * each of them is a separate copy of the same code (0x802AC2D8 and its
 * siblings). Evidence: fn_8038B7E4 (the mid class's own dtor, vtable slot 1 of
 * 0x806850A0) has the same body.
 * Each derived class adds a virtual at vtable slot 14 (an event type id). */
class Unk8037B424 {
public:
    virtual ~Unk8037B424();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual Unk8037B424* fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual int fn_vslot10();
};

class Unk8038B7E4 : public Unk8037B424 {
public:
    virtual ~Unk8038B7E4() {}
    virtual void fn_vslot2();
    virtual const char* fn_vslot3() = 0;
    virtual int fn_vslot4() = 0;
    virtual Unk8037B424* fn_vslot5() = 0;
    virtual int fn_vslot10();
    virtual void fn_vslot11() = 0;
    virtual void fn_vslot12();
    virtual int fn_vslot13();
};

extern const char lbl_805DBF90[];   /* "cHandAnimHoldBall" */
extern const char lbl_805DBFA4[];   /* "cHeadTracking" */
extern unsigned int lbl_8068D5DC;  /* hash of "cHeadTracking" */
extern unsigned int lbl_8068D5E0;  /* hash of "cChangeActionState" */

extern const char lbl_805DBFB4[];          /* "cSwitchBallHand" */
extern const char lbl_805DBFC4[];          /* "cEndCheckSwing" */
extern const char lbl_805DBFD4[];          /* "cAudioTrigger" */
extern const char lbl_805DBFE4[];          /* "cLaunchTwoManMove" */
extern const char lbl_805DBFF8[];          /* "cDropBall" */
extern const char lbl_805DC004[];          /* "cNoPlayerCollisions" */
extern const char lbl_805DC018[];          /* "cLooseBall" */
extern const char lbl_805DC024[];          /* "cLeaveToStand" */
extern const char lbl_805DC034[];          /* "cLeaveToRun" */
extern const char lbl_805DC040[];          /* "cLeaveToThrow" */
extern const char lbl_805DC050[];          /* "cLeaveToTag" */
extern const char lbl_805DC05C[];          /* "cEnterLate" */
extern const char lbl_805DC068[];          /* "cChangeActionState" */
extern const char lbl_805DC07C[];          /* "cCollisionSyncPoint" */

class cHandAnimHoldBall {
public:
    static const char* fn_802AC2CC();
};

class cHeadTracking : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cHeadTracking();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC33C();
};

class cSwitchBallHand : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cSwitchBallHand();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cEndCheckSwing : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cEndCheckSwing();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cAudioTrigger : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cAudioTrigger();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLaunchTwoManMove : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cLaunchTwoManMove();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cDropBall : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cDropBall();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cNoPlayerCollisions : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cNoPlayerCollisions();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLooseBall : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cLooseBall();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLeaveToStand : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cLeaveToStand();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLeaveToRun : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cLeaveToRun();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLeaveToThrow : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cLeaveToThrow();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cLeaveToTag : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cLeaveToTag();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cEnterLate : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cEnterLate();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
};

class cChangeActionState : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cChangeActionState();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC76C();
};

class cCollisionSyncPoint : public Unk8038B7E4 {
public:
    virtual void fn_vslot2();
    virtual ~cCollisionSyncPoint();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot14();
    static const char* fn_802AC7DC();
};

const char* cHandAnimHoldBall::fn_802AC2CC()
{
    return lbl_805DBF90;
}

cHeadTracking::~cHeadTracking()
{
}

const char* cHeadTracking::fn_vslot3()
{
    return fn_802AC33C();
}

int cHeadTracking::fn_vslot4()
{
    return lbl_8068D5DC;
}

int cHeadTracking::fn_vslot14()
{
    return 0x20;
}

const char* cHeadTracking::fn_802AC33C()
{
    return lbl_805DBFA4;
}

cSwitchBallHand::~cSwitchBallHand()
{
}

const char* cSwitchBallHand::fn_vslot3()
{
    return lbl_805DBFB4;
}

int cSwitchBallHand::fn_vslot4()
{
    return 0x54bebc90;
}

int cSwitchBallHand::fn_vslot14()
{
    return 0x21;
}

cEndCheckSwing::~cEndCheckSwing()
{
}

const char* cEndCheckSwing::fn_vslot3()
{
    return lbl_805DBFC4;
}

int cEndCheckSwing::fn_vslot4()
{
    return 0xd76c1ac5;
}

int cEndCheckSwing::fn_vslot14()
{
    return 0x05;
}

cAudioTrigger::~cAudioTrigger()
{
}

const char* cAudioTrigger::fn_vslot3()
{
    return lbl_805DBFD4;
}

int cAudioTrigger::fn_vslot4()
{
    return 0x9f4a38ce;
}

int cAudioTrigger::fn_vslot14()
{
    return 0x22;
}

cLaunchTwoManMove::~cLaunchTwoManMove()
{
}

const char* cLaunchTwoManMove::fn_vslot3()
{
    return lbl_805DBFE4;
}

int cLaunchTwoManMove::fn_vslot4()
{
    return 0x05a38d30;
}

int cLaunchTwoManMove::fn_vslot14()
{
    return 0x23;
}

cDropBall::~cDropBall()
{
}

const char* cDropBall::fn_vslot3()
{
    return lbl_805DBFF8;
}

int cDropBall::fn_vslot4()
{
    return 0x122509f8;
}

int cDropBall::fn_vslot14()
{
    return 0x24;
}

cNoPlayerCollisions::~cNoPlayerCollisions()
{
}

const char* cNoPlayerCollisions::fn_vslot3()
{
    return lbl_805DC004;
}

int cNoPlayerCollisions::fn_vslot4()
{
    return 0xdfe56471;
}

int cNoPlayerCollisions::fn_vslot14()
{
    return 0x25;
}

cLooseBall::~cLooseBall()
{
}

const char* cLooseBall::fn_vslot3()
{
    return lbl_805DC018;
}

int cLooseBall::fn_vslot4()
{
    return 0x3f4bf7c5;
}

int cLooseBall::fn_vslot14()
{
    return 0x26;
}

cLeaveToStand::~cLeaveToStand()
{
}

const char* cLeaveToStand::fn_vslot3()
{
    return lbl_805DC024;
}

int cLeaveToStand::fn_vslot4()
{
    return 0xff0d1452;
}

int cLeaveToStand::fn_vslot14()
{
    return 0x0b;
}

cLeaveToRun::~cLeaveToRun()
{
}

const char* cLeaveToRun::fn_vslot3()
{
    return lbl_805DC034;
}

int cLeaveToRun::fn_vslot4()
{
    return 0x989091ad;
}

int cLeaveToRun::fn_vslot14()
{
    return 0x0b;
}

cLeaveToThrow::~cLeaveToThrow()
{
}

const char* cLeaveToThrow::fn_vslot3()
{
    return lbl_805DC040;
}

int cLeaveToThrow::fn_vslot4()
{
    return 0xff18e0cc;
}

int cLeaveToThrow::fn_vslot14()
{
    return 0x0b;
}

cLeaveToTag::~cLeaveToTag()
{
}

const char* cLeaveToTag::fn_vslot3()
{
    return lbl_805DC050;
}

int cLeaveToTag::fn_vslot4()
{
    return 0x98909794;
}

int cLeaveToTag::fn_vslot14()
{
    return 0x0b;
}

cEnterLate::~cEnterLate()
{
}

const char* cEnterLate::fn_vslot3()
{
    return lbl_805DC05C;
}

int cEnterLate::fn_vslot4()
{
    return 0x84cebe2c;
}

int cEnterLate::fn_vslot14()
{
    return 0x0b;
}

cChangeActionState::~cChangeActionState()
{
}

const char* cChangeActionState::fn_vslot3()
{
    return fn_802AC76C();
}

int cChangeActionState::fn_vslot4()
{
    return lbl_8068D5E0;
}

int cChangeActionState::fn_vslot14()
{
    return 0x28;
}

const char* cChangeActionState::fn_802AC76C()
{
    return lbl_805DC068;
}

cCollisionSyncPoint::~cCollisionSyncPoint()
{
}

const char* cCollisionSyncPoint::fn_vslot3()
{
    return fn_802AC7DC();
}

int cCollisionSyncPoint::fn_vslot4()
{
    return 0xa5422c1b;
}

int cCollisionSyncPoint::fn_vslot14()
{
    return 0x0b;
}

const char* cCollisionSyncPoint::fn_802AC7DC()
{
    return lbl_805DC07C;
}

/* ---- Chooser classes (root: Unk8037B3E8 in game/chooser.h) ---- */
extern const char* lbl_8061E640;   /* "cMatrixChooser" */
extern const char* lbl_8061E644;   /* "cRandom" */
extern const char* lbl_8061E648;   /* "ICommonPlayerID" */
extern const char* lbl_8061E64C;   /* "cSignatureChooser" */
extern const char* lbl_8061E650;   /* "cEventChooser" */
extern const char* lbl_8061E654;   /* "cHandChooser" */
extern const char* lbl_8061E660;   /* "cPitchChooser" */
extern const char* lbl_8061E66C;   /* "cCircleChooser" */
extern const char* lbl_8061E670;   /* "cLinearChooser" */
extern const char* lbl_8061E674;   /* "cFitnessChooser" */
extern const char* lbl_8061E698;   /* "cRandomLoaded" */
extern const char* lbl_8061E69C;   /* "cShortestPathChooser" */
extern unsigned int lbl_8068D578;  /* ICommonPlayerID type hash */
extern unsigned int lbl_8068D57C;  /* cEventChooser type hash */
extern unsigned int lbl_8068D580;  /* cRandomLoaded type hash */
extern unsigned int lbl_806EF9D8;  /* cShortestPathChooser type hash */

/* Embedded helpers (their dtors are in other units). */
class Unk8026DDE8 : public Unk80356798 {      /* cMatrixChooser +0xC */
public:
    virtual ~Unk8026DDE8();
};
class Unk80271F14 : public Unk80356798 {      /* cCircleChooser +0xC */
public:
    virtual ~Unk80271F14();
};
class Unk80272B20 : public Unk80356798 {      /* cLinearChooser +0xC */
public:
    virtual ~Unk80272B20();
};
class Unk8027130C : public Unk80356798 {      /* cSignatureChooser +0x8 */
public:
    virtual ~Unk8027130C();
    int fn_802715D8(int index);
};


class cMatrixChooser : public Unk8037B3E8 {
public:
    cMatrixChooser();
    virtual void fn_vslot2();
    virtual ~cMatrixChooser();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    int m4;
    int m8;
    Unk8026DDE8 mC;
};

class cRandom : public Unk8037B3E8 {
public:
    cRandom();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

class ICommonPlayerID : public Unk8037B3E8 {
public:
    ICommonPlayerID();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

class cSignatureChooser : public Unk8037B3E8 {
public:
    cSignatureChooser();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot18(int a);

    int m4;
    Unk8027130C m8;
};

class cEventChooser : public Unk8037B3E8 {
public:
    cEventChooser();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

class cHandChooser : public Unk8037B3E8 {
public:
    cHandChooser();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual void fn_vslot15();

    int m4;
    Unk80384F28 m8;
};

class cPitchChooser : public Unk8037B3E8 {
public:
    cPitchChooser();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

class cCircleChooser : public Unk8037B3E8 {
public:
    cCircleChooser();
    virtual void fn_vslot2();
    virtual ~cCircleChooser();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    int m4;
    int m8;
    Unk80271F14 mC;
};

class cLinearChooser : public Unk8037B3E8 {
public:
    cLinearChooser();
    virtual void fn_vslot2();
    virtual ~cLinearChooser();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    int m4;
    int m8;
    Unk80272B20 mC;
};

class cFitnessChooser : public Unk8037B3E8 {
public:
    cFitnessChooser();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

class cRandomLoaded : public Unk8037B3E8 {
public:
    cRandomLoaded();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

class cShortestPathChooser : public Unk8037B3E8 {
public:
    cShortestPathChooser();
    virtual void fn_vslot2();
    virtual ~cShortestPathChooser();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual int fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f);
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
};

cMatrixChooser::~cMatrixChooser()
{
}

const char* cMatrixChooser::fn_vslot3()
{
    return lbl_8061E640;
}

int cMatrixChooser::fn_vslot4()
{
    return 0x42d34230;
}

int cRandom::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

int cRandom::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return 0;
}

const char* cRandom::fn_vslot3()
{
    return lbl_8061E644;
}

int cRandom::fn_vslot4()
{
    return 0x8ee57249;
}

int ICommonPlayerID::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

int ICommonPlayerID::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return 0;
}

const char* ICommonPlayerID::fn_vslot3()
{
    return lbl_8061E648;
}

int ICommonPlayerID::fn_vslot4()
{
    return lbl_8068D578;
}

int cSignatureChooser::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return 0;
}

const char* cSignatureChooser::fn_vslot3()
{
    return lbl_8061E64C;
}

int cSignatureChooser::fn_vslot4()
{
    return 0x29505a6d;
}

int cSignatureChooser::fn_vslot18(int a)
{
    return m8.fn_802715D8(a);
}

int cEventChooser::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return fn_vslot17(out, obj, 2, 0, 0, f);
}

int cEventChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return fn_vslot17(out, obj, 3, 0, 0, 0);
}

const char* cEventChooser::fn_vslot3()
{
    return lbl_8061E650;
}

int cEventChooser::fn_vslot4()
{
    return lbl_8068D57C;
}

int cHandChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

const char* cHandChooser::fn_vslot3()
{
    return lbl_8061E654;
}

int cHandChooser::fn_vslot4()
{
    return 0xc8316bb6;
}

void cHandChooser::fn_vslot15()
{
    m8.fn_803852E4();
}

int cPitchChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

int cPitchChooser::fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return fn_vslot17(out, obj, 1, 0, 0, 0);
}

const char* cPitchChooser::fn_vslot3()
{
    return lbl_8061E660;
}

int cPitchChooser::fn_vslot4()
{
    return 0x19a55653;
}

cCircleChooser::~cCircleChooser()
{
}

const char* cCircleChooser::fn_vslot3()
{
    return lbl_8061E66C;
}

int cCircleChooser::fn_vslot4()
{
    return 0x3df2690d;
}

cLinearChooser::~cLinearChooser()
{
}

const char* cLinearChooser::fn_vslot3()
{
    return lbl_8061E670;
}

int cLinearChooser::fn_vslot4()
{
    return 0xf8eb0036;
}

int cFitnessChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

int cFitnessChooser::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return 0;
}

const char* cFitnessChooser::fn_vslot3()
{
    return lbl_8061E674;
}

int cFitnessChooser::fn_vslot4()
{
    return 0x293e00f7;
}

int cRandomLoaded::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

int cRandomLoaded::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return 0;
}

const char* cRandomLoaded::fn_vslot3()
{
    return lbl_8061E698;
}

int cRandomLoaded::fn_vslot4()
{
    return lbl_8068D580;
}

cShortestPathChooser::~cShortestPathChooser()
{
}

int cShortestPathChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return 0;
}

int cShortestPathChooser::fn_vslot12(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int f)
{
    return 0;
}

const char* cShortestPathChooser::fn_vslot3()
{
    return lbl_8061E69C;
}

int cShortestPathChooser::fn_vslot4()
{
    return lbl_806EF9D8;
}

/* ---- Warp classes (the unit's slot 3/4 getters only) ---- */
extern const char* lbl_8061E86C;   /* "cCycleTimeWarp" */
extern const char* lbl_8061E870;   /* "cGeneralRotationWarp" */
extern const char* lbl_8061E874;   /* "cSetPosRotWarp" */
extern const char* lbl_8061E878;   /* "cFudgePosRotWarp" */
extern const char* lbl_8061E87C;   /* "cSwingTimeWarp" */
extern const char* lbl_8061E880;   /* "cTimeWarp" */
extern const char* lbl_8061E884;   /* "cGenericTimeWarp" */
extern const char* lbl_8061E888;   /* "cCycleTimeSpaceWarp" */
extern const char* lbl_8061E894;   /* "cLimbLockWarp" */
extern const char* lbl_8061E898;   /* "cHeadingWarp" */
extern const char* lbl_8061E89C;   /* "cTranslationWarp" */
extern unsigned int lbl_8068D5A4;  /* cGeneralRotationWarp type hash */
extern unsigned int lbl_8068D5A8;  /* cSetPosRotWarp type hash */


class cCycleTimeWarp : public Unk8037B3E8 {
public:
    cCycleTimeWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cGeneralRotationWarp : public Unk8037B3E8 {
public:
    cGeneralRotationWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cSetPosRotWarp : public Unk8037B3E8 {
public:
    cSetPosRotWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cFudgePosRotWarp : public Unk8037B3E8 {
public:
    cFudgePosRotWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cSwingTimeWarp : public Unk8037B3E8 {
public:
    cSwingTimeWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cTimeWarp : public Unk8037B3E8 {
public:
    cTimeWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cGenericTimeWarp : public Unk8037B3E8 {
public:
    cGenericTimeWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cCycleTimeSpaceWarp : public Unk8037B3E8 {
public:
    cCycleTimeSpaceWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cLimbLockWarp : public Unk8037B3E8 {
public:
    cLimbLockWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cHeadingWarp : public Unk8037B3E8 {
public:
    cHeadingWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

class cTranslationWarp : public Unk8037B3E8 {
public:
    cTranslationWarp();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
};

const char* cCycleTimeWarp::fn_vslot3()
{
    return lbl_8061E86C;
}

int cCycleTimeWarp::fn_vslot4()
{
    return 0x395ee741;
}

const char* cGeneralRotationWarp::fn_vslot3()
{
    return lbl_8061E870;
}

int cGeneralRotationWarp::fn_vslot4()
{
    return lbl_8068D5A4;
}

const char* cSetPosRotWarp::fn_vslot3()
{
    return lbl_8061E874;
}

int cSetPosRotWarp::fn_vslot4()
{
    return lbl_8068D5A8;
}

const char* cFudgePosRotWarp::fn_vslot3()
{
    return lbl_8061E878;
}

int cFudgePosRotWarp::fn_vslot4()
{
    return 0x1b26d314;
}

const char* cSwingTimeWarp::fn_vslot3()
{
    return lbl_8061E87C;
}

int cSwingTimeWarp::fn_vslot4()
{
    return 0xdea30859;
}

const char* cTimeWarp::fn_vslot3()
{
    return lbl_8061E880;
}

int cTimeWarp::fn_vslot4()
{
    return 0x1c105b31;
}

const char* cGenericTimeWarp::fn_vslot3()
{
    return lbl_8061E884;
}

int cGenericTimeWarp::fn_vslot4()
{
    return 0xbfeb4cce;
}

const char* cCycleTimeSpaceWarp::fn_vslot3()
{
    return lbl_8061E888;
}

int cCycleTimeSpaceWarp::fn_vslot4()
{
    return 0x05b43fad;
}

const char* cLimbLockWarp::fn_vslot3()
{
    return lbl_8061E894;
}

int cLimbLockWarp::fn_vslot4()
{
    return 0x1ce0ff4f;
}

const char* cHeadingWarp::fn_vslot3()
{
    return lbl_8061E898;
}

int cHeadingWarp::fn_vslot4()
{
    return 0x688fb392;
}

const char* cTranslationWarp::fn_vslot3()
{
    return lbl_8061E89C;
}

int cTranslationWarp::fn_vslot4()
{
    return 0xf394ea31;
}

/* ---- Two classes of the 0x802A6250..0x802A6334 region (see
 * animation/warps/tu_802A4584.cpp for their other methods): a list holder
 * (vtable 0x80661900) and a container (vtable 0x806618A0). Their dtors are the
 * first two functions here; the container's four tiny virtuals follow.
 * Layout from the dtors: Unk802A6334 (ctor 0x802A6334, dtor 0x802A638C) has its
 * vptr at +0x18. Unk802A6250 holds one at +0 and puts its own vptr after 0x24
 * bytes of data (vptr at +0x24, member dtor with in-charge 2, then the deleting
 * part). Unk802A62CC derives from a class with an inline dtor (vtable
 * 0x80664020, vptr at +0x18: its dtor stores that vptr again and does the
 * deleting part) and adds m1C and a Unk802A6334 at +0x20. */
class Unk802A6334_Data {
    char pad0[0x18];
};
class Unk802A6334 : public Unk802A6334_Data {
public:
    virtual ~Unk802A6334();
};

class Unk802A6250_Base {
public:
    ~Unk802A6250_Base() {}
    Unk802A6334 m0;
    char pad1C[8];
};
class Unk802A6250 : public Unk802A6250_Base {
public:
    virtual void fn_vslot2();
    virtual ~Unk802A6250();
};

class Unk8035E98C_Data {
    char pad0[0x18];
};
class Unk8035E98C : public Unk8035E98C_Data {
public:
    virtual ~Unk8035E98C() {}
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
};
class Unk802A62CC : public Unk8035E98C {
public:
    virtual void fn_vslot7(float dt);
    virtual ~Unk802A62CC();
    virtual void fn_vslot5(float a);
    virtual void fn_vslot6();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();

    int m1C;
    Unk802A6334 m20;
};

Unk802A6250::~Unk802A6250()
{
}

Unk802A62CC::~Unk802A62CC()
{
}

void Unk802A62CC::fn_vslot5(float a)
{
}

void Unk802A62CC::fn_vslot6()
{
}

void Unk802A62CC::fn_vslot9()
{
    m1C = 1;
}

void Unk802A62CC::fn_vslot10()
{
    m1C = 0;
}

