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

/* Stubs of the 46 event classes whose static locals fn_802A70F8 constructs.
 * Their ctors and the rest of the classes are in the events units
 * (0x802A79BC..); each class derives from Unk8038B7E4 and is as big as the gap
 * between its object and its guard flag in retail's .bss (0x8068CE68..).
 * Matching notes:
 *  - The dtor must be an explicit inline `virtual ~X() {}`. With the implicit
 *    one, the static-destruction function (__tcf_N) calls the out-of-line
 *    dtor; with the inline one it is expanded there, and since each vptr store
 *    overwrites the previous, only Unk8038B7E4's store (0x806850A0) and the
 *    root dtor call (in_chrg 2) remain, as in retail (__tcf_N = 0x802A66E8..).
 *  - The static locals are laid out object, guard, object, guard ... exactly
 *    as retail's .bss (0x8068CE68..0x8068D114), so the sizes are right.
 *  - fn_vslot3 (declared, undefined here) keeps the vtables out of this unit. */
/* Static local of fn_802A70F8 (object lbl_8068CE68, 0x28 bytes); ctor 0x802A79BC is in the events unit. */
class Unk802A79BC : public Unk8038B7E4 {
public:
    Unk802A79BC();
    virtual const char* fn_vslot3();
    virtual ~Unk802A79BC() {}
    char pad4[0x24];
};

/* Static local of fn_802A70F8 (object lbl_8068CE94, 0x4 bytes); ctor 0x802A7AAC is in the events unit. */
class Unk802A7AAC : public Unk8038B7E4 {
public:
    Unk802A7AAC();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7AAC() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CE9C, 0x4 bytes); ctor 0x802A7B20 is in the events unit. */
class Unk802A7B20 : public Unk8038B7E4 {
public:
    Unk802A7B20();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7B20() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CEA4, 0x4 bytes); ctor 0x802A7C08 is in the events unit. */
class Unk802A7C08 : public Unk8038B7E4 {
public:
    Unk802A7C08();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7C08() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CEAC, 0x4 bytes); ctor 0x802A7B94 is in the events unit. */
class Unk802A7B94 : public Unk8038B7E4 {
public:
    Unk802A7B94();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7B94() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CEB4, 0x4 bytes); ctor 0x802A7C7C is in the events unit. */
class Unk802A7C7C : public Unk8038B7E4 {
public:
    Unk802A7C7C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7C7C() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CEBC, 0x4 bytes); ctor 0x802A933C is in the events unit. */
class Unk802A933C : public Unk8038B7E4 {
public:
    Unk802A933C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A933C() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CEC4, 0x4C bytes); ctor 0x802A7CF0 is in the events unit. */
class Unk802A7CF0 : public Unk8038B7E4 {
public:
    Unk802A7CF0();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7CF0() {}
    char pad4[0x48];
};

/* Static local of fn_802A70F8 (object lbl_8068CF14, 0x4 bytes); ctor 0x802A81D4 is in the events unit. */
class Unk802A81D4 : public Unk8038B7E4 {
public:
    Unk802A81D4();
    virtual const char* fn_vslot3();
    virtual ~Unk802A81D4() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF1C, 0x4 bytes); ctor 0x802A8248 is in the events unit. */
class Unk802A8248 : public Unk8038B7E4 {
public:
    Unk802A8248();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8248() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF24, 0x4 bytes); ctor 0x802A82BC is in the events unit. */
class Unk802A82BC : public Unk8038B7E4 {
public:
    Unk802A82BC();
    virtual const char* fn_vslot3();
    virtual ~Unk802A82BC() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF2C, 0x4 bytes); ctor 0x802A8B54 is in the events unit. */
class Unk802A8B54 : public Unk8038B7E4 {
public:
    Unk802A8B54();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8B54() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF34, 0x4 bytes); ctor 0x802A8AE0 is in the events unit. */
class Unk802A8AE0 : public Unk8038B7E4 {
public:
    Unk802A8AE0();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8AE0() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF3C, 0xC bytes); ctor 0x802A8330 is in the events unit. */
class Unk802A8330 : public Unk8038B7E4 {
public:
    Unk802A8330();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8330() {}
    char pad4[0x8];
};

/* Static local of fn_802A70F8 (object lbl_8068CF4C, 0x4 bytes); ctor 0x802A841C is in the events unit. */
class Unk802A841C : public Unk8038B7E4 {
public:
    Unk802A841C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A841C() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF54, 0xC bytes); ctor 0x802A8860 is in the events unit. */
class Unk802A8860 : public Unk8038B7E4 {
public:
    Unk802A8860();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8860() {}
    char pad4[0x8];
};

/* Static local of fn_802A70F8 (object lbl_8068CF64, 0x8 bytes); ctor 0x802A894C is in the events unit. */
class Unk802A894C : public Unk8038B7E4 {
public:
    Unk802A894C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A894C() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068CF70, 0x4 bytes); ctor 0x802A89F8 is in the events unit. */
class Unk802A89F8 : public Unk8038B7E4 {
public:
    Unk802A89F8();
    virtual const char* fn_vslot3();
    virtual ~Unk802A89F8() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF78, 0x4 bytes); ctor 0x802A8A6C is in the events unit. */
class Unk802A8A6C : public Unk8038B7E4 {
public:
    Unk802A8A6C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8A6C() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CF80, 0x24 bytes); ctor 0x802A879C is in the events unit. */
class Unk802A879C : public Unk8038B7E4 {
public:
    Unk802A879C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A879C() {}
    char pad4[0x20];
};

/* Static local of fn_802A70F8 (object lbl_8068CFA8, 0x30 bytes); ctor 0x802A8490 is in the events unit. */
class Unk802A8490 : public Unk8038B7E4 {
public:
    Unk802A8490();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8490() {}
    char pad4[0x2C];
};

/* Static local of fn_802A70F8 (object lbl_8068CFDC, 0x4 bytes); ctor 0x802A86AC is in the events unit. */
class Unk802A86AC : public Unk8038B7E4 {
public:
    Unk802A86AC();
    virtual const char* fn_vslot3();
    virtual ~Unk802A86AC() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CFE4, 0x4 bytes); ctor 0x802A8724 is in the events unit. */
class Unk802A8724 : public Unk8038B7E4 {
public:
    Unk802A8724();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8724() {}
};

/* Static local of fn_802A70F8 (object lbl_8068CFEC, 0x24 bytes); ctor 0x802A7F24 is in the events unit. */
class Unk802A7F24 : public Unk8038B7E4 {
public:
    Unk802A7F24();
    virtual const char* fn_vslot3();
    virtual ~Unk802A7F24() {}
    char pad4[0x20];
};

/* Static local of fn_802A70F8 (object lbl_8068D014, 0x28 bytes); ctor 0x802A814C is in the events unit. */
class Unk802A814C : public Unk8038B7E4 {
public:
    Unk802A814C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A814C() {}
    char pad4[0x24];
};

/* Static local of fn_802A70F8 (object lbl_8068D040, 0x10 bytes); ctor 0x802A8FF4 is in the events unit. */
class Unk802A8FF4 : public Unk8038B7E4 {
public:
    Unk802A8FF4();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8FF4() {}
    char pad4[0xC];
};

/* Static local of fn_802A70F8 (object lbl_8068D054, 0x8 bytes); ctor 0x802A9280 is in the events unit. */
class Unk802A9280 : public Unk8038B7E4 {
public:
    Unk802A9280();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9280() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068D060, 0xC bytes); ctor 0x802A93F4 is in the events unit. */
class Unk802A93F4 : public Unk8038B7E4 {
public:
    Unk802A93F4();
    virtual const char* fn_vslot3();
    virtual ~Unk802A93F4() {}
    char pad4[0x8];
};

/* Static local of fn_802A70F8 (object lbl_8068D070, 0x4 bytes); ctor 0x802A9638 is in the events unit. */
class Unk802A9638 : public Unk8038B7E4 {
public:
    Unk802A9638();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9638() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D078, 0x8 bytes); ctor 0x802A8BC8 is in the events unit. */
class Unk802A8BC8 : public Unk8038B7E4 {
public:
    Unk802A8BC8();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8BC8() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068D084, 0x8 bytes); ctor 0x802A8CAC is in the events unit. */
class Unk802A8CAC : public Unk8038B7E4 {
public:
    Unk802A8CAC();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8CAC() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068D090, 0x4 bytes); ctor 0x802A8DD8 is in the events unit. */
class Unk802A8DD8 : public Unk8038B7E4 {
public:
    Unk802A8DD8();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8DD8() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D098, 0x4 bytes); ctor 0x802A8E8C is in the events unit. */
class Unk802A8E8C : public Unk8038B7E4 {
public:
    Unk802A8E8C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8E8C() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0A0, 0x4 bytes); ctor 0x802A8F40 is in the events unit. */
class Unk802A8F40 : public Unk8038B7E4 {
public:
    Unk802A8F40();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8F40() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0A8, 0x8 bytes); ctor 0x802A9148 is in the events unit. */
class Unk802A9148 : public Unk8038B7E4 {
public:
    Unk802A9148();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9148() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068D0B4, 0x8 bytes); ctor 0x802A94E0 is in the events unit. */
class Unk802A94E0 : public Unk8038B7E4 {
public:
    Unk802A94E0();
    virtual const char* fn_vslot3();
    virtual ~Unk802A94E0() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068D0C0, 0x4 bytes); ctor 0x802A95C4 is in the events unit. */
class Unk802A95C4 : public Unk8038B7E4 {
public:
    Unk802A95C4();
    virtual const char* fn_vslot3();
    virtual ~Unk802A95C4() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0C8, 0x4 bytes); ctor 0x802A8068 is in the events unit. */
class Unk802A8068 : public Unk8038B7E4 {
public:
    Unk802A8068();
    virtual const char* fn_vslot3();
    virtual ~Unk802A8068() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0D0, 0x4 bytes); ctor 0x802A96FC is in the events unit. */
class Unk802A96FC : public Unk8038B7E4 {
public:
    Unk802A96FC();
    virtual const char* fn_vslot3();
    virtual ~Unk802A96FC() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0D8, 0x4 bytes); ctor 0x802A97C0 is in the events unit. */
class Unk802A97C0 : public Unk8038B7E4 {
public:
    Unk802A97C0();
    virtual const char* fn_vslot3();
    virtual ~Unk802A97C0() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0E0, 0x4 bytes); ctor 0x802A9834 is in the events unit. */
class Unk802A9834 : public Unk8038B7E4 {
public:
    Unk802A9834();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9834() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0E8, 0x4 bytes); ctor 0x802A98A8 is in the events unit. */
class Unk802A98A8 : public Unk8038B7E4 {
public:
    Unk802A98A8();
    virtual const char* fn_vslot3();
    virtual ~Unk802A98A8() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0F0, 0x4 bytes); ctor 0x802A991C is in the events unit. */
class Unk802A991C : public Unk8038B7E4 {
public:
    Unk802A991C();
    virtual const char* fn_vslot3();
    virtual ~Unk802A991C() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D0F8, 0x4 bytes); ctor 0x802A9990 is in the events unit. */
class Unk802A9990 : public Unk8038B7E4 {
public:
    Unk802A9990();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9990() {}
};

/* Static local of fn_802A70F8 (object lbl_8068D100, 0x8 bytes); ctor 0x802A9A04 is in the events unit. */
class Unk802A9A04 : public Unk8038B7E4 {
public:
    Unk802A9A04();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9A04() {}
    char pad4[0x4];
};

/* Static local of fn_802A70F8 (object lbl_8068D10C, 0x4 bytes); ctor 0x802A9AF4 is in the events unit. */
class Unk802A9AF4 : public Unk8038B7E4 {
public:
    Unk802A9AF4();
    virtual const char* fn_vslot3();
    virtual ~Unk802A9AF4() {}
};

void fn_802A70F8()
{
    static Unk802A79BC s802A79BC;
    static Unk802A7AAC s802A7AAC;
    static Unk802A7B20 s802A7B20;
    static Unk802A7C08 s802A7C08;
    static Unk802A7B94 s802A7B94;
    static Unk802A7C7C s802A7C7C;
    static Unk802A933C s802A933C;
    static Unk802A7CF0 s802A7CF0;
    static Unk802A81D4 s802A81D4;
    static Unk802A8248 s802A8248;
    static Unk802A82BC s802A82BC;
    static Unk802A8B54 s802A8B54;
    static Unk802A8AE0 s802A8AE0;
    static Unk802A8330 s802A8330;
    static Unk802A841C s802A841C;
    static Unk802A8860 s802A8860;
    static Unk802A894C s802A894C;
    static Unk802A89F8 s802A89F8;
    static Unk802A8A6C s802A8A6C;
    static Unk802A879C s802A879C;
    static Unk802A8490 s802A8490;
    static Unk802A86AC s802A86AC;
    static Unk802A8724 s802A8724;
    static Unk802A7F24 s802A7F24;
    static Unk802A814C s802A814C;
    static Unk802A8FF4 s802A8FF4;
    static Unk802A9280 s802A9280;
    static Unk802A93F4 s802A93F4;
    static Unk802A9638 s802A9638;
    static Unk802A8BC8 s802A8BC8;
    static Unk802A8CAC s802A8CAC;
    static Unk802A8DD8 s802A8DD8;
    static Unk802A8E8C s802A8E8C;
    static Unk802A8F40 s802A8F40;
    static Unk802A9148 s802A9148;
    static Unk802A94E0 s802A94E0;
    static Unk802A95C4 s802A95C4;
    static Unk802A8068 s802A8068;
    static Unk802A96FC s802A96FC;
    static Unk802A97C0 s802A97C0;
    static Unk802A9834 s802A9834;
    static Unk802A98A8 s802A98A8;
    static Unk802A991C s802A991C;
    static Unk802A9990 s802A9990;
    static Unk802A9A04 s802A9A04;
    static Unk802A9AF4 s802A9AF4;
}
