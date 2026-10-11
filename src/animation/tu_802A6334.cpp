/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): classes between the warps and the event classes. Original file boundary unknown; placeholder.
 *
 * .text 0x802A6334-0x802A79BC only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 *
 * Contents: a node pool class (Unk802A6334, 0x802A6334..0x802A66A0; its vtable
 * is 0x80664050), the 46 static-destruction functions (__tcf_N,
 * 0x802A66E8..0x802A70C0) and the function holding the 46 static locals they
 * destroy (0x802A70F8). The pool is embedded at +0x20 of Unk802A62CC (the last
 * class of animation/warps/tu_802A4584.cpp, which calls fn_802A6458 on it;
 * that file's Unk802A6458 stub stands for this class).
 *
 * Matching notes:
 *  - Node (header) clears its four fields in the order mC, m8, m0, m4; the
 *    scheduler rotates that to the retail store order m4, mC, m8, m0.
 *  - Ctor field stores in the order mC, m10, m14, m0, m4, m8 give retail's
 *    (a 720-permutation search).
 *  - fn_802A64E8: a separate loop pointer (`n = a`) and `i = 1; i <= d` give
 *    the early `mr r31,r3` and the countdown loop (`a++` in the loop, or
 *    a[i], do not).
 */
#include "game/tu_802A6334.h"

Unk802A6334::Unk802A6334(int count, int step)
{
    mC = 0;
    m10 = 0;
    m14 = 0;
    m0 = 0;
    m4 = 0;
    m8 = step;
    fn_802A64E8(count);
}

Unk802A6334::~Unk802A6334()
{
    Unk802A6334_Node* p = m14;
    while (p) {
        Unk802A6334_Node* next = p->m8;
        delete[] p;
        p = next;
    }
}

void Unk802A6334::fn_802A63F8(Unk802A6334_Node* node)
{
    if (node) {
        m4++;
        fn_802A66A0(node, &mC);
        fn_802A6660(0, m10, &m10, node);
    }
}

Unk802A6334_Node* Unk802A6334::fn_802A6458(void* obj, int key)
{
    Unk802A6334_Node* n = fn_802A65E4();
    n->m0 = obj;
    n->m4 = key;
    Unk802A6334_Node* prev = 0;
    Unk802A6334_Node* p = mC;
    while (p) {
        if (p->m4 > key) {
            fn_802A6660(p->mC, p, &mC, n);
            return n;
        }
        prev = p;
        p = p->m8;
    }
    fn_802A6660(prev, 0, &mC, n);
    return n;
}

void Unk802A6334::fn_802A64E8(int count)
{
    if (count > m0) {
        int d = count - m0;
        m0 = count;
        m4 += d;
        Unk802A6334_Node* a = new (0) Unk802A6334_Node[d + 1];
        a->Clear();
        fn_802A6660(0, m14, &m14, a);
        Unk802A6334_Node* n = a;
        for (int i = 1; i <= d; i++) {
            n++;
            n->Clear();
            fn_802A6660(0, m10, &m10, n);
        }
    }
}

Unk802A6334_Node* Unk802A6334::fn_802A65E4()
{
    if (m4 == 0) {
        fn_802A64E8(m0 + m8);
    }
    Unk802A6334_Node* n = m10;
    fn_802A66A0(n, &m10);
    m4--;
    n->Clear();
    return n;
}

void Unk802A6334::fn_802A6660(Unk802A6334_Node* prev, Unk802A6334_Node* next,
                              Unk802A6334_Node** head, Unk802A6334_Node* node)
{
    if (!node) {
        return;
    }
    if (prev) {
        prev->m8 = node;
    } else {
        if (!next) {
            next = *head;
        }
        *head = node;
    }
    node->mC = prev;
    node->m8 = next;
    if (next) {
        next->mC = node;
    }
}

void Unk802A6334::fn_802A66A0(Unk802A6334_Node* node, Unk802A6334_Node** head)
{
    if (!node) {
        return;
    }
    Unk802A6334_Node* prev = node->mC;
    Unk802A6334_Node* next = node->m8;
    if (prev) {
        prev->m8 = next;
    } else {
        *head = next;
    }
    if (next) {
        next->mC = prev;
    }
    node->Clear();
}

/* Stubs of the event classes that events.h does not define yet (the second
 * half of the events, units 0x802A89C8 and 0x802A9A04), named by their ctor
 * address so they cannot clash with the real classes: replace each by the real
 * class (cEndCheckSwing, ...) once events.h has it. They have only what
 * fn_802A70F8 needs: the ctor (defined in the events units) and overrides of the
 * pure virtuals. Each is as big as the gap between its object and its guard flag
 * in retail's .bss (0x8068CE68..), so the static locals are laid out as in
 * retail.
 *
 * Matching note: the static-destruction functions (__tcf_N) expand the dtor
 * inline only when it is an explicit inline `virtual ~X() {}` (an implicit one
 * is synthesized from inside __tcf and called out of line). Then each vptr store
 * overwrites the previous and only Unk8038B7E4's store (0x806850A0) and the root
 * dtor call (in_chrg 2) remain, as in retail (__tcf_N = 0x802A66E8..).
 * events.h declares the explicit dtors of its classes for that reason. */

class Unk802A933C : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A933C();   /* cEndCheckSwing */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A933C() {}
};

class Unk802A8B54 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8B54();   /* cBeginWarp */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8B54() {}
};

class Unk802A8AE0 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8AE0();   /* cEndWarp */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8AE0() {}
};

class Unk802A89F8 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A89F8();   /* cStartSwing */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A89F8() {}
};

class Unk802A8A6C : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8A6C();   /* cEndSlide */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8A6C() {}
};

class Unk802A8FF4 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8FF4();   /* cHeadTracking */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8FF4() {}
    char pad4[0xC];
};

class Unk802A9280 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9280();   /* cSwitchBallHand */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9280() {}
    char pad4[0x4];
};

class Unk802A93F4 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A93F4();   /* cAudioTrigger */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A93F4() {}
    char pad4[0x8];
};

class Unk802A9638 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9638();   /* cNoPlayerCollisions */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9638() {}
};

class Unk802A8BC8 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8BC8();   /* cFacialAnim */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8BC8() {}
    char pad4[0x4];
};

class Unk802A8CAC : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8CAC();   /* cHandAnim */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8CAC() {}
    char pad4[0x4];
};

class Unk802A8DD8 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8DD8();   /* cHandAnimIdle */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8DD8() {}
};

class Unk802A8E8C : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8E8C();   /* cHandAnimClosed */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8E8C() {}
};

class Unk802A8F40 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A8F40();   /* cHandAnimHoldBall */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A8F40() {}
};

class Unk802A9148 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9148();   /* cHatAnim */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9148() {}
    char pad4[0x4];
};

class Unk802A94E0 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A94E0();   /* cLaunchTwoManMove */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A94E0() {}
    char pad4[0x4];
};

class Unk802A95C4 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A95C4();   /* cDropBall */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A95C4() {}
};

class Unk802A96FC : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A96FC();   /* cLooseBall */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A96FC() {}
};

class Unk802A97C0 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A97C0();   /* cLeaveToStand */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A97C0() {}
};

class Unk802A9834 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9834();   /* cLeaveToRun */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9834() {}
};

class Unk802A98A8 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A98A8();   /* cLeaveToThrow */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A98A8() {}
};

class Unk802A991C : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A991C();   /* cLeaveToTag */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A991C() {}
};

class Unk802A9990 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9990();   /* cEnterLate */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9990() {}
};

class Unk802A9A04 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9A04();   /* class not named yet */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9A04() {}
    char pad4[0x4];
};

class Unk802A9AF4 : public Unk8038B7E4 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    Unk802A9AF4();   /* class not named yet */
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_evslot11();
    virtual ~Unk802A9AF4() {}
};

void fn_802A70F8()
{
    static cReleaseBall scReleaseBall;
    static cSwingContactPhase scSwingContactPhase;
    static cSwingMisTimedNonContactPhase scSwingMisTimedNonContactPhase;
    static cSwingBreaksStrikePlane scSwingBreaksStrikePlane;
    static cSwingSweetSpot scSwingSweetSpot;
    static cSwingComplete scSwingComplete;
    static Unk802A933C sUnk802A933C;
    static cCatchBall scCatchBall;
    static cBlend1 scBlend1;
    static cBlend2 scBlend2;
    static cBlend3 scBlend3;
    static Unk802A8B54 sUnk802A8B54;
    static Unk802A8AE0 sUnk802A8AE0;
    static cLeft scLeft;
    static cSlide scSlide;
    static cRight scRight;
    static cHitByPitch scHitByPitch;
    static Unk802A89F8 sUnk802A89F8;
    static Unk802A8A6C sUnk802A8A6C;
    static cAccessorize scAccessorize;
    static cDirtEvent scDirtEvent;
    static cSpectacularAnimation scSpectacularAnimation;
    static cSignatureHRToFirstCelebration scSignatureHRToFirstCelebration;
    static cTouchBase scTouchBase;
    static cTagRunner scTagRunner;
    static Unk802A8FF4 sUnk802A8FF4;
    static Unk802A9280 sUnk802A9280;
    static Unk802A93F4 sUnk802A93F4;
    static Unk802A9638 sUnk802A9638;
    static Unk802A8BC8 sUnk802A8BC8;
    static Unk802A8CAC sUnk802A8CAC;
    static Unk802A8DD8 sUnk802A8DD8;
    static Unk802A8E8C sUnk802A8E8C;
    static Unk802A8F40 sUnk802A8F40;
    static Unk802A9148 sUnk802A9148;
    static Unk802A94E0 sUnk802A94E0;
    static Unk802A95C4 sUnk802A95C4;
    static cFirstTouchBase scFirstTouchBase;
    static Unk802A96FC sUnk802A96FC;
    static Unk802A97C0 sUnk802A97C0;
    static Unk802A9834 sUnk802A9834;
    static Unk802A98A8 sUnk802A98A8;
    static Unk802A991C sUnk802A991C;
    static Unk802A9990 sUnk802A9990;
    static Unk802A9A04 sUnk802A9A04;
    static Unk802A9AF4 sUnk802A9AF4;
}
