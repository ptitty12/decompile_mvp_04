/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): code between the event classes and the static initializer
 * (fn_802AA7A4). Original file boundary unknown; placeholder.
 *
 * .text 0x802A9A04-0x802AA7A4 only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data/.bss split for this unit).
 *
 * Contents, in .text order:
 *  - two event classes' ctors and factories: cChangeActionState (vtable
 *    0x806627C8; name "cChangeActionState" from fn_802AC738's string) with its
 *    attribute function (slot 2) and slot 12, and cCollisionSyncPoint (vtable
 *    0x80662748, name "cCollisionSyncPoint" via fn_802AC7DC);
 *  - nine tiny non-virtual setters (0x802A9B68..0x802A9C34) of event structs
 *    built on the stack by other code (base vtable 0x80649DA0, id at +0,
 *    vptr at +4, fields from +8). They are inline members that were called
 *    before their definition, so this TU emitted out-of-line copies;
 *  - 0x802A9C60..0x802AA1E4: the 29 static destructors (__tcf_N) that g++
 *    2.95 emits for the function-local statics of fn_802AA210, which comes last:
 *    29 `static Class obj;` with ctor, guard, atexit(__tcf_N). Per-object
 *    .bss: the object followed by its 4-byte guard (0x8068D114 .. 0x8068D4C8).
 * Classes defined in other units are redeclared minimally. A class whose
 * destructor is inlined into its __tcf stub (the implicit dtors of cMatrixChooser,
 * cLinearChooser, cCircleChooser and cShortestPathChooser in retail) is
 * declared here with an inline `virtual ~X() {}`: the synthesized implicit dtor
 * would not be inlined at its first use.
 */

void* operator new(unsigned int size, int heap);      /* 0x80377428 */

extern int lbl_806EF9B4;                    /* default heap passed to new */
extern unsigned int lbl_8068D5E0;           /* cChangeActionState type hash (set by fn_802AA7A4) */
extern const char lbl_805DE904[];           /* "ActionState" */
extern const char lbl_805DC180[];           /* "?,_dontcare_,_unchanged_,idle,idle_ready,pitch,..." */

/* ---- base classes (minimal copies; the real declarations live in other units) ---- */

/* Root of the choosers, warps and events (vtable 0x806849D0, ctor 0x8037B3E8,
 * dtor 0x8037B424). Chooser-only slots 11..17 are omitted. */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
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
    /* Attribute registration (0x8037B674): name, field, enum values, flags. */
    void fn_8037B674(const char* name, int* field, const char* values, int flags);
};

/* Base of the events (vtable 0x806850A0). Inline ctor and dtor: the derived
 * ctors and dtors expand them. Signatures of the other slots are unknown. */
class Unk8038B7E4 : public Unk8037B3E8 {
public:
    Unk8038B7E4(unsigned int hash) : Unk8037B3E8(hash) {}
    virtual ~Unk8038B7E4() {}
    virtual void fn_vslot2();           /* 0x8038B81C, empty */
    virtual int fn_vslot10();           /* 0x8038B820, returns 1 */
    virtual int fn_vslot11();
    virtual void fn_vslot12(void* queue, float f1, float f2, int b);   /* 0x8037E68C */
    virtual int fn_vslot13();           /* 0x8038B814, returns 0 */
};

/* Events whose slot 11 is the shared inline 0x8035EA80 (calls slot 14). */
class Unk8035EA80 : public Unk8038B7E4 {
public:
    Unk8035EA80(unsigned int hash) : Unk8038B7E4(hash) {}
    virtual int fn_vslot11();           /* 0x8035EA80 */
    virtual int fn_vslot14();
};

void fn_8037893C(void* queue, int id, Unk8037B3E8* ev, int a, int b);

/* ---- event classes ---- */

/* vtable 0x806627C8; dtor, slots 3, 4 and 14 are in the next unit. */
class cChangeActionState : public Unk8035EA80 {
public:
    /* Declared first and defined in the next unit, so the vtable is emitted there. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cChangeActionState();
    virtual Unk8037B3E8* fn_vslot5();   /* 0x802A9A50 */
    virtual void fn_vslot2();           /* 0x802A9A80 */
    virtual void fn_vslot12(void* queue, float f1, float f2, int b);   /* 0x802A9AB8 */
    virtual int fn_vslot14();

    int m4;                             /* "ActionState" enum */
};

/* vtable 0x80662748; dtor, slots 3, 4 and 14 are in the next unit. */
class cCollisionSyncPoint : public Unk8035EA80 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cCollisionSyncPoint();
    virtual Unk8037B3E8* fn_vslot5();   /* 0x802A9B38 */
    virtual int fn_vslot14();
};

/* ---- event structs built on the stack (id at +0, vptr at +4) ---- */

class Unk80649DA0 {
public:
    Unk80649DA0() {}
    int m0;
    virtual ~Unk80649DA0();
};

struct Unk802A9BAC_Obj {
    char pad0[0x5BC];
    int m5BC;
};

class Unk802A9B68 : public Unk80649DA0 {
public:
    void fn_802A9B68(int a);
    int m8;
};

class Unk802A9B70 : public Unk80649DA0 {
public:
    void fn_802A9B70(int a);
    int m8;
};

class Unk802A9B78 : public Unk80649DA0 {
public:
    void fn_802A9B78(int a, int b);
    void fn_802A9B84(float f);
    int m8;
    int mC;
    float m10;
};

class Unk802A9B9C : public Unk80649DA0 {
public:
    void fn_802A9B9C(int a);
    void fn_802A9BA4(int a);
    int m8;
    int mC;
};

class Unk802A9BAC : public Unk80649DA0 {
public:
    void fn_802A9BAC(int a, Unk802A9BAC_Obj* b, int c, int d);
    int m8;
    Unk802A9BAC_Obj* mC;
    int m10;
    int m14;
};

class Unk802A9C20 : public Unk80649DA0 {
public:
    void fn_802A9C20(int a, int b, int c, int d);
    int m8;
    int mC;
    int m10;
    int m14;
};

class Unk802A9C34 : public Unk80649DA0 {
public:
    void fn_802A9C34(int a, float f, char b, int c, char d, char e);
    int m8;
    int mC;
    float m10;
    char m14;
    char m15;
    char m16;
};

/* ---- classes of the 29 function-local statics (sizes from the .bss layout) ---- */

class Unk8037E73C { public: Unk8037E73C(); ~Unk8037E73C(); char pad0[0x1C]; };
class Unk80383C9C { public: Unk80383C9C(); ~Unk80383C9C(); char pad0[0x20]; };
class Unk803853F8 { public: Unk803853F8(); ~Unk803853F8(); char pad0[0xC]; };
class Unk80384858 { public: Unk80384858(); ~Unk80384858(); char pad0[0x40]; };

/* Container embedded in event/hand/pitch choosers (ctor 0x80384F28, dtor 0x8038501C). */
class Unk80384F28 { public: Unk80384F28(); ~Unk80384F28(); char pad0[0x10]; };

/* Static 5 (0x8068D1AC; ctor 0x80383B24): its dtor is inlined in the stub. */
class Unk80383B24 : public Unk8037B3E8 {
public:
    Unk80383B24();
    virtual ~Unk80383B24() {}
    virtual void fn_vslot2();
    char pad4[0x18];
};

/* Static 6 (0x8068D1CC; ctor 0x80383548): derived from an abstract event-like base
 * (vtable 0x806626C0, dtor 0x8035EB18); both dtors are inlined in the stub. */
class Unk8035EB18 : public Unk8037B3E8 {
public:
    Unk8035EB18(unsigned int hash) : Unk8037B3E8(hash) {}
    virtual ~Unk8035EB18() {}
    virtual void fn_vslot2();
};
class Unk80383548 : public Unk8035EB18 {
public:
    Unk80383548();
    virtual ~Unk80383548() {}
    virtual void fn_vslot2();
    Unk80384F28 m4;
    char pad14[0x10];
};

/* Base of the choosers (dtor 0x80362C2C, out of line; see game/chooser.h). The
 * inline chooser dtors below end in a call to it. */
class Unk80362C2C : public Unk8037B3E8 {
public:
    Unk80362C2C(unsigned int hash) : Unk8037B3E8(hash) {}
    virtual ~Unk80362C2C();
};

/* Choosers (the real declarations are in animation/choosers/*.cpp). */
class cEventChooser : public Unk80362C2C {
public:
    cEventChooser();
    virtual ~cEventChooser();
    int m4;
    Unk80384F28 m8;
};
class cHandChooser : public Unk80362C2C {
public:
    cHandChooser();
    virtual ~cHandChooser();
    int m4;
    Unk80384F28 m8;
};

/* Matrix chooser helper (dtor 0x8026DE5C, size 0x48). */
class Unk8026DDE8 { public: Unk8026DDE8(); ~Unk8026DDE8(); char pad0[0x48]; };
class cMatrixChooser : public Unk80362C2C {
public:
    cMatrixChooser();
    virtual ~cMatrixChooser() {}
    virtual const char* fn_vslot3();
    int m4;
    int m8;
    Unk8026DDE8 mC;
    int m54;
    int m58;
    int m5C;
};

class cPitchChooser : public Unk80362C2C {
public:
    cPitchChooser();
    virtual ~cPitchChooser();
    int m4;
    Unk80384F28 m8;
};
class ICommonPlayerID : public Unk80362C2C {
public:
    ICommonPlayerID();
    virtual ~ICommonPlayerID();
    char pad4[0x1C];
};
class cSignatureChooser : public Unk80362C2C {
public:
    cSignatureChooser();
    virtual ~cSignatureChooser();
    char pad4[0x20];
};
class cRandom : public Unk80362C2C {
public:
    cRandom();
    virtual ~cRandom();
    char pad4[0x18];
};
class cRandomLoaded : public Unk80362C2C {
public:
    cRandomLoaded();
    virtual ~cRandomLoaded();
    char pad4[0x14];
};

/* Linear chooser helper (size 0x1C) and circle chooser helper (size 0x30). */
class Unk80272B20 { public: Unk80272B20(); ~Unk80272B20(); char pad0[0x1C]; };
class Unk80271F14 { public: Unk80271F14(); ~Unk80271F14(); char pad0[0x30]; };
class cLinearChooser : public Unk80362C2C {
public:
    cLinearChooser();
    virtual ~cLinearChooser() {}
    virtual const char* fn_vslot3();
    int m4;
    int m8;
    Unk80272B20 mC;
};
class cCircleChooser : public Unk80362C2C {
public:
    cCircleChooser();
    virtual ~cCircleChooser() {}
    virtual const char* fn_vslot3();
    int m4;
    int m8;
    Unk80271F14 mC;
};
class cShortestPathChooser : public Unk80362C2C {
public:
    cShortestPathChooser();
    virtual ~cShortestPathChooser() {}
    virtual const char* fn_vslot3();
};

/* Warps (the real declarations are in animation/warps/*.cpp). */
class cCycleTimeWarp : public Unk8037B3E8 {
public:
    cCycleTimeWarp();
    virtual ~cCycleTimeWarp();
    char pad4[4];
};
class cGeneralRotationWarp : public Unk8037B3E8 {
public:
    cGeneralRotationWarp();
    virtual ~cGeneralRotationWarp();
    char pad4[4];
};
class cSetPosRotWarp : public Unk8037B3E8 {
public:
    cSetPosRotWarp();
    virtual ~cSetPosRotWarp();
    char pad4[8];
};
class cFudgePosRotWarp : public Unk8037B3E8 {
public:
    cFudgePosRotWarp();
    virtual ~cFudgePosRotWarp();
    char pad4[0x10];
};
class cSwingTimeWarp : public Unk8037B3E8 {
public:
    cSwingTimeWarp();
    virtual ~cSwingTimeWarp();
    char pad4[8];
};
class cTimeWarp : public Unk8037B3E8 {
public:
    cTimeWarp();
    virtual ~cTimeWarp();
    char pad4[8];
};
class Unk80276DB8 { public: Unk80276DB8(); ~Unk80276DB8(); char pad0[0x34]; };   /* dtor 0x80276F4C */
class cGenericTimeWarp : public Unk8037B3E8 {
public:
    cGenericTimeWarp();
    virtual ~cGenericTimeWarp();
    char pad4[8];
};
class cCycleTimeSpaceWarp : public Unk8037B3E8 {
public:
    cCycleTimeSpaceWarp();
    virtual ~cCycleTimeSpaceWarp();
    char pad4[0x20];
};
class cLimbLockWarp : public Unk8037B3E8 {
public:
    cLimbLockWarp();
    virtual ~cLimbLockWarp();
    char pad4[0x14];
};
class cHeadingWarp : public Unk8037B3E8 {
public:
    cHeadingWarp();
    virtual ~cHeadingWarp();
    char pad4[0x14];
};
class cTranslationWarp : public Unk8037B3E8 {
public:
    cTranslationWarp();
    virtual ~cTranslationWarp();
    char pad4[0x10];
};

/* ---- definitions, in .text order ---- */

cChangeActionState::cChangeActionState() : Unk8035EA80(lbl_8068D5E0)
{
    m4 = 1;
}

Unk8037B3E8* cChangeActionState::fn_vslot5()
{
    return new (lbl_806EF9B4) cChangeActionState;
}

void cChangeActionState::fn_vslot2()
{
    fn_8037B674(lbl_805DE904, &m4, lbl_805DC180, 0);
}

void cChangeActionState::fn_vslot12(void* queue, float f1, float f2, int b)
{
    fn_8037893C(queue, 0x28, this, m4, b);
}

cCollisionSyncPoint::cCollisionSyncPoint() : Unk8035EA80(0xA5422C1B)
{
}

Unk8037B3E8* cCollisionSyncPoint::fn_vslot5()
{
    return new (lbl_806EF9B4) cCollisionSyncPoint;
}

void Unk802A9B68::fn_802A9B68(int a)
{
    m8 = a;
}

void Unk802A9B70::fn_802A9B70(int a)
{
    m8 = a;
}

void Unk802A9B78::fn_802A9B78(int a, int b)
{
    m8 = a;
    mC = b;
}

void Unk802A9B78::fn_802A9B84(float f)
{
    m10 = f;
}

void Unk802A9B9C::fn_802A9B9C(int a)
{
    m8 = a;
}

void Unk802A9B9C::fn_802A9BA4(int a)
{
    mC = a;
}

void Unk802A9BAC::fn_802A9BAC(int a, Unk802A9BAC_Obj* b, int c, int d)
{
    mC = b;
    m10 = -1;
    m8 = a;
    if (a < b->m5BC) {
        m10 = 4;
    } else if (c == 2) {
        m10 = 0;
    } else if (c == 4) {
        m10 = 1;
    } else if (c == 5) {
        m10 = 2;
    } else if (c == 6 || c == 3) {
        m10 = 3;
    }
    m14 = d;
}

void Unk802A9C20::fn_802A9C20(int a, int b, int c, int d)
{
    mC = a;
    m10 = b;
    m8 = c;
    m14 = d;
}

void Unk802A9C34::fn_802A9C34(int a, float f, char b, int c, char d, char e)
{
    m14 = b;
    m15 = d;
    m16 = e;
    m8 = a;
    m10 = f;
    mC = c;
}

/* 29 function-local statics: g++ 2.95 emits the static destructor stubs (__tcf_0
 * .. __tcf_28, 0x802A9C60..0x802AA1E4) just before this function. */
void fn_802AA210()
{
    static Unk8037E73C s0;
    static Unk80383C9C s1;
    static Unk803853F8 s2;
    static Unk80384858 s3;
    static Unk80383B24 s4;
    static Unk80383548 s5;
    static cEventChooser s6;
    static cHandChooser s7;
    static cMatrixChooser s8;
    static cPitchChooser s9;
    static ICommonPlayerID s10;
    static cSignatureChooser s11;
    static cRandom s12;
    static cRandomLoaded s13;
    static cLinearChooser s14;
    static cCircleChooser s15;
    static cShortestPathChooser s16;
    static cCycleTimeWarp s17;
    static cGeneralRotationWarp s18;
    static cSetPosRotWarp s19;
    static cFudgePosRotWarp s20;
    static cSwingTimeWarp s21;
    static cTimeWarp s22;
    static Unk80276DB8 s23;
    static cGenericTimeWarp s24;
    static cCycleTimeSpaceWarp s25;
    static cLimbLockWarp s26;
    static cHeadingWarp s27;
    static cTranslationWarp s28;
}
