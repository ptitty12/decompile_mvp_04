/*
 * Game code, .text 0x8016BF30-0x8016F45C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80167DCC.h"

struct Unk8016D778_S {
    char pad0[0x24];
    Unk801527C8_Actor* m24;
};
struct Unk8016D850_B {
    char pad0[0x6C];
    int m6C;
};
struct Unk8016D850_G {
    char pad0[8];
    Unk801527C8_Actor* m8;
    Unk801527C8_Actor* mC;
    char pad10[0x10];
    int m20;
    int m24;
};
struct Unk8016D458_P {
    char pad0[0x20];
    int m20;
};
struct Unk8016D458_O {
    char pad0[0x744];
    Unk8016D458_P* m744;
};
struct Unk8017A930_T;
int fn_8016D580(Unk8016D778_S* self);
int fn_8016D778(Unk8016D778_S* self);
void fn_8016D850(Unk8016D778_S* self);
void fn_802D74FC();
int fn_80359964(char* p);
extern "C" int fn_8031C6A8();
extern "C" void fn_8031C6C0(int a, int b, int c, int d);
void fn_8017CD04(Unk8017A930_T* t, int k, int z);
extern Unk8016D850_G* lbl_8061B8C0;
void fn_8016D924(void* self, Unk8016ACAC* m);
#include "game/clampiter.h"

struct Unk8016D128_V6 {
    int m0, m4, m8, mC, m10, m14;
};
extern const Unk8016D128_V6 lbl_805EBA10;
/* One 0xA0-byte element of the script queue (Unk8016ACAC::m3D94). */
struct Unk8016D128_Elem {
    char name[0x3C];
    int m3C, m40, m44, m48, m4C;
    Unk8016D128_V6 m50;
    Unk8016D128_V6 m68;
    Unk8016D128_V6 m80;
    int m98;
    int m9C;
};
struct Unk8019F8C0_Owner;
struct Unk8017A930_T;
Unk8016ACAC* fn_801A6D84(Unk8019F8C0_Owner* o, int i);
Unk801527C8_Actor* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
int fn_801A2034(Unk8019F8C0_Owner* o, int i);
int fn_8017CA14(Unk8017A930_T* t, int i);
extern "C" int fn_802D7DB4(int id, int k);
extern "C" Unk8016D850_B* fn_801A6DB8(Unk8019F8C0_Owner* o);

Unk801A6D84_Obj* fn_801A6D84(Unk801527C8_Actor* a, int i);

extern "C" char* strcat(char* d, const char* s);
extern "C" char* strcpy(char* d, const char* s);
void fn_8037CA20(Unk8037C7FC* mgr, const char* name);

/* Dtor-only views of two script classes whose vtables (0x8065E968, 0x8065E8F0) are emitted elsewhere;
 * the mid class stores vtable 0x8065EC68 and the root dtor follows. */
class Unk8016F38C_Mid : public Unk8037B3E8 {
public:
    Unk8016F38C_Mid(unsigned h) : Unk8037B3E8(h) {}
    virtual ~Unk8016F38C_Mid() {}
    virtual void fn_vslot2() = 0;
    virtual const char* fn_vslot3() = 0;
    virtual int fn_vslot4() = 0;
    virtual Unk8037B3E8* fn_vslot5() = 0;
};
class Unk80151048 {
public:
    ~Unk80151048();
    char m0[4];
};
class Unk8033CD28 {
public:
    ~Unk8033CD28();
    char m0[4];
};
class Unk8016F38C_A : public Unk8016F38C_Mid {
public:
    Unk8016F38C_A(unsigned h);
    virtual const char* fn_vslot3();
    virtual ~Unk8016F38C_A();
    char pad4[8];
    Unk80151048 mC;
};
class Unk8016F400_A : public Unk8016F38C_Mid {
public:
    Unk8016F400_A(unsigned h);
    virtual const char* fn_vslot3();
    virtual ~Unk8016F400_A();
    char pad4[0x58];
    Unk8033CD28 m5C;
};

extern const char lbl_8065EBA8[];
void* fn_803282A8(void* p, int a);

extern float lbl_805CAD78;
extern const char lbl_805CAD7C[];
extern float lbl_805CAD8C;
extern float lbl_805CAD90;

extern const char lbl_805C6244[];

extern float lbl_805CAD38;
extern float lbl_805CAD64;
extern float lbl_805CAD68;
extern const float lbl_805CAD6C;
extern const float lbl_805CAD70;
extern const float lbl_805CAD94;

int fn_8040B6A0(const char* s);
void* fn_803272D0(Unk801527C8_Sub* s, unsigned int idx);
int fn_80169DC4(const char* b);
int fn_8040B574(const char* a, const char* b);
void fn_80359948(Unk8016C1C4_List* l, int a);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_80303BC4(const char* fmt, ...);
char* fn_8040B61C(char* d, const char* s);
void fn_8037EBE8(void* p);
void fn_803814A4(void* p, float f, int a, int b);
void fn_8017C75C(void* a, Unk8016C788_Obj* o);
Unk8016C788_Obj* fn_80178E6C(void* sl, int a, int b);
extern const float lbl_805CAD74;
struct Unk8016CF38_X {
    char pad0[0x700];
    void* m700;
};
void fn_802AEBCC(void* mgr, const char* s);
void fn_80244A64(Unk8016C788_Obj* o, int a, int b);
extern void* lbl_8061E978;
void fn_80359910(Unk8016C1C4_List* l);
void fn_803596DC(void* p);

void fn_8016BF30(void* self, const char* s) /* 8016BF30 */
{
    char buf[0x50];
    strcpy(buf, "script_");
    strcat(buf, s);
    strcat(buf, ".txt");
    fn_8037CA20(fn_8037C7FC(), buf);
}

float Unk8016C1C4_List::fn_8016BF94() /* 8016BF94 */
{
    float x = lbl_805CAD38;
    float a = fn_8016C248(1);
    float b = this[1].fn_8016C248(0);
    x = a >? b;
    return x;
}

inline int CurId(Unk8016C1C4_List* l)
{
    if (l->mCur >= 0) {
        return l->m4[l->mCur].m0;
    }
    return 0;
}

extern "C" char* fn_801519D8(int id);
extern "C" int fn_80151A18(char* h, int j);
extern "C" int fn_80151A28(char* h, int j);
extern "C" int fn_80151A38(char* h, int j);
extern "C" void fn_803295F0();
extern "C" void fn_803296AC();
struct Unk8016C004_X {
    char pad0[0x120];
    int m120;
};
struct Unk8016C004_W {
    char pad0[0x10];
    Unk8016C004_X* m10;
};
struct Unk8016C004_G {
    char pad0[4];
    Unk8016C004_W* m4;
};
extern Unk8016C004_G* lbl_806192E0;

/* near-miss (99.9%): only the registers of the two strided list pointers in the last loop are swapped
 * (retail r27 = +0x15C, r28 = +0x158; here the other way round). The CR0 save (mfcr/mtcrf) comes from the
 * redundant second test of h. */
void Unk8016C1C4_List::fn_8016C004(int a, int b) /* 8016C004 */
{
    char* h = fn_801519D8(a);
    if (h == 0) {
        ((Unk8016ACAC_Slot*)this)->fn_8016C6DC();
        return;
    }
    if (b != 0) {
        int p = (int)this;
        int end = p + 0x968;
        do {
            fn_80359948((Unk8016C1C4_List*)p, 0);
            ((Unk8016C1C4_List*)p)->mCur = 0;
            p += 0xAC;
        } while (p <= end);
    }
    for (int j = 0; j <= 0xC; j++) {
        ((Unk801527C8_Ctx*)this)->fn_8016CE5C(j + 2);
    }
    fn_803295F0();
    fn_803296AC();
    if (h != 0) {
        int one = 1;
        if (mCur >= 0) {
            m4[mCur].m0 = one;
        }
        fn_8016C620(0, (int)h + 4);
        Unk8016C1C4_List* l1 = this + 1;
        if (l1->mCur >= 0) {
            l1->m4[l1->mCur].m0 = one;
        }
        fn_8016C620(1, (int)h + 0x14);
        for (int j = 0; j <= 0xC; j++) {
            if (fn_80151A28(h, j) != 0) {
                char* pe = (char*)this + 0x15C + j * 0xAC;
                int* pc = (int*)((char*)this + 0x158 + j * 0xAC);
                int c = *pc;
                int w = 1;
                if (c >= 0) {
                    *(int*)(pe + c * 0x14) = w;
                }
                int n = j + 2;
                ((Unk801527C8_Ctx*)this)->fn_8016D038(n, fn_80151A38(h, j));
                fn_8016C620(n, fn_80151A18(h, j));
            }
        }
    }
    ((Unk8016ACAC_Slot*)this)->mA20 = a;
    if (lbl_806192E0->m4->m10->m120 == 1) {
        *(float*)fn_801A6D84(((Unk801527C8_Ctx*)this)->mA4C, 1) = -1.0f;
    }
}

int Unk8016C1C4_List::fn_8016C1C4(int idx) /* 8016C1C4 */
{
    return CurId(this + idx);
}

int Unk8016C1C4_List::fn_8016C1EC() /* 8016C1EC */
{
    if (CurId(this) == 0) {
        if (CurId(this + 1) == 0) {
            return 0;
        }
    }
    return 1;
}

float Unk8016C1C4_List::fn_8016C248(int flag) /* 8016C248 */
{
    float sum = lbl_805CAD64;
    for (int i = mCur; i >= 0; i--) {
        float v = m4[i].fn_8016C2D0(flag);
        if (!(v < lbl_805CAD64)) {
            sum += v;
        }
    }
    return sum;
}

float Unk8016C1C4_Ent::fn_8016C2D0(int flag) /* 8016C2D0 */
{
    float r = lbl_805CAD68;
    if (m0 != 0) {
        Unk8016C2D0_Obj* o = m4;
        if (o != 0) {
            if (flag != 0) {
                r = o->mC - mC;
            } else {
                r = fn_801510A8(o, m8, m10);
            }
        }
    }
    return r;
}

int Unk8016ACAC::fn_8016C344() /* 8016C344 */
{
    for (int i = 0; i <= 2; i++) {
        if (m1E28[i].mLists[0].fn_8016C1EC() != 0) {
            return 1;
        }
    }
    return 0;
}

inline int AllEmpty(char (*s)[0xA0])
{
    for (int i = 0; i <= 7; i++) {
        if (fn_8040B6A0(s[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

int Unk8016ACAC::fn_8016C39C() /* 8016C39C */
{
    if (m4.m1E00 != 0) {
        return 1;
    }
    if (fn_8016C344() != 0) {
        return 1;
    }
    return !AllEmpty(m3D94);
}

inline void ClearCur(Unk8016C1C4_List* l)
{
    if (l->mCur >= 0) {
        l->m4[l->mCur].m0 = 0;
    }
}

void Unk8016C1C4_List::fn_8016C424(int idx) /* 8016C424 */
{
    ClearCur(this + idx);
}

void Unk8016ACAC_Slot::fn_8016C448() /* 8016C448 */
{
    int p = (int)this;
    int end = p + 0x968;
    do {
        fn_80359948((Unk8016C1C4_List*)p, 0);
        ((Unk8016C1C4_List*)p)->mCur = 0;
        p += 0xAC;
    } while (p <= end);
    fn_8016A6AC();
}

void Unk8016ACAC::fn_8016C4A0() /* 8016C4A0 */
{
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 3; i != 0; i--, s++) {
        s->fn_8016C448();
    }
    m4.fn_8016DFD0();
    fn_8016A880();
    fn_8016D128();
}

void Unk8016ACAC::fn_8016C4FC() /* 8016C4FC */
{
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 3; i != 0; i--, s++) {
        s->fn_8016C448();
    }
    Unk8016D128_Elem* e = (Unk8016D128_Elem*)m3D94;
    for (int j = 0; j < 8; j++, e++) {
        e->name[0] = 0;
        e->m3C = 0;
        e->m40 = 0;
        e->m44 = 0;
        e->m48 = 0;
        e->m4C = 0;
        e->m50 = lbl_805EBA10;
        e->m68 = lbl_805EBA10;
        e->m80 = lbl_805EBA10;
        e->m98 = 0;
        e->m9C = 0xAE;
    }
    fn_8016A880();
}

void Unk8016C1C4_List::fn_8016C620(int idx, int p) /* 8016C620 */
{
    int base = idx * 0xAC;
    int cur = *(int*)((char*)this + base);
    int off = cur * 0x14 + base;
    int* p8 = (int*)((char*)this + 8);
    float* p10 = (float*)((char*)this + 0x10);
    int* pC = (int*)((char*)this + 0xC);
    float* p14 = (float*)((char*)this + 0x14);
    *(int*)((char*)p8 + off) = p;
    *(float*)((char*)p10 + off) = lbl_805CAD6C;
    *(int*)((char*)pC + off) = 0;
    *(float*)((char*)p14 + off) = lbl_805CAD6C;
}

void Unk8016C1C4_List::fn_8016C660(int idx) /* 8016C660 */
{
    int base = idx * 0xAC;
    int cur = *(int*)((char*)this + base);
    int off = cur * 0x14 + base;
    float* p10 = (float*)((char*)this + 0x10);
    int* pC = (int*)((char*)this + 0xC);
    float* p14 = (float*)((char*)this + 0x14);
    *(float*)((char*)p10 + off) = lbl_805CAD70;
    *(int*)((char*)pC + off) = 0;
    *(float*)((char*)p14 + off) = lbl_805CAD70;
}

void Unk8016C1C4_List::fn_8016C698(int a) /* 8016C698 */
{
    for (int i = 0; i < 15; i++) {
        this[i].mCur = this[i].mCur + 1;
    }
    fn_8016C004(a, 0);
}

void Unk8016ACAC_Slot::fn_8016C6DC() /* 8016C6DC */
{
    int i;
    for (i = 0; i < 15; i++) {
        int c = mLists[i].mCur;
        if (c == 0) {
            fn_80359948(&mLists[i], 0);
            mLists[i].mCur = c;
        } else {
            mLists[i].mCur = c - 1;
        }
    }
    for (i = 0; i <= 12; i++) {
        ((Unk801527C8_Ctx*)this)->fn_8016CE5C(i + 2);
    }
}

int Unk8016ACAC::fn_8016C764(int idx) /* 8016C764 */
{
    return m1E28[0].mLists[0].fn_8016C788(idx);
}

int Unk8016C1C4_List::fn_8016C788(int idx) /* 8016C788 */
{
    int* p = &mA4;
    int off = idx * 0xAC;
    return *(int*)((char*)p + off);
}

int Unk8016C1C4_List::fn_8016C798(int idx) /* 8016C798 */
{
    int* p = &mA8;
    int off = idx * 0xAC;
    return *(int*)((char*)p + off);
}

inline void* GetPtr(void** arr, unsigned int i)
{
    return arr[i];
}

/* near-miss: same code; the shifted index lives in r0 here, retail uses r11 (inline index helper, ternary, cast forms tried) */
void* Unk801527C8_Ctx::fn_8016C7A8(unsigned int idx) /* 8016C7A8 */
{
    if (mA54->m44 == 0) {
        void* r;
        Unk801527C8_Actor* a = mA4C;
        if (idx <= 12) {
            r = a->m65C[idx];
        } else {
            r = 0;
        }
        return r;
    }
    return fn_803272D0(&mA4C->m50, idx);
}

struct Unk8019F8C0_Owner;
int fn_801A4A94(Unk8019F8C0_Owner* o, int a);
int fn_801A4C74(Unk8019F8C0_Owner* o, int a);
int fn_801A4C20(Unk8019F8C0_Owner* o);
int fn_801A4C3C(Unk8019F8C0_Owner* o, int a, int b);
extern "C" int fn_801A497C(Unk801527C8_Actor* a, int b, int c);
extern "C" int fn_80097190(void* s, int a);
extern "C" int fn_80097300(void* s, int a);

Unk80189300* Unk801527C8_Ctx::fn_8016C804(int id)
{
    Unk801527C8_Actor* a = mA4C;
    Unk80189300* r = 0;
    switch (id) {
    case 0:
        r = (Unk80189300*)fn_8016C7A8(0);
        break;
    case 1:
        r = (Unk80189300*)fn_8016C7A8(1);
        break;
    case 2:
        r = (Unk80189300*)fn_8016C7A8(2);
        break;
    case 3:
        r = (Unk80189300*)fn_8016C7A8(3);
        break;
    case 4:
        r = (Unk80189300*)fn_8016C7A8(4);
        break;
    case 5:
        r = (Unk80189300*)fn_8016C7A8(5);
        break;
    case 6:
        r = (Unk80189300*)fn_8016C7A8(6);
        break;
    case 7:
        r = (Unk80189300*)fn_8016C7A8(7);
        break;
    case 8:
        r = (Unk80189300*)fn_8016C7A8(8);
        break;
    case 9:
        break;
    case 10:
        r = (Unk80189300*)fn_8016C7A8(9);
        break;
    case 59:
    {
        Unk801527C8_Teams* p = a->m6F8->m14;
        int side = 0;
        if (p->m1CD0 != 0)
            side = 1;
        void* s = (char*)p + side * 0xE64;
        r = (Unk80189300*)fn_801A4A94((Unk8019F8C0_Owner*)a, fn_80097300(s, fn_80097190(s, 1)));
        break;
    }
    case 54:
        r = (Unk80189300*)fn_8016C7A8(10);
        break;
    case 55:
        r = (Unk80189300*)fn_8016C7A8(11);
        break;
    case 56:
        r = (Unk80189300*)fn_8016C7A8(12);
        break;
    case 11:
        r = (Unk80189300*)fn_801A497C(a, 3, 0);
        break;
    case 12:
        r = (Unk80189300*)fn_801A497C(a, 3, 1);
        break;
    case 13:
        r = (Unk80189300*)fn_801A497C(a, 3, 2);
        break;
    case 14:
        r = (Unk80189300*)fn_801A497C(a, 3, 3);
        break;
    case 15:
        r = (Unk80189300*)fn_801A497C(a, 3, 4);
        break;
    case 16:
        r = (Unk80189300*)fn_801A497C(a, 3, 5);
        break;
    case 17:
        r = (Unk80189300*)fn_801A497C(a, 3, 6);
        break;
    case 18:
        r = (Unk80189300*)fn_801A497C(a, 3, 7);
        break;
    case 19:
        r = (Unk80189300*)fn_801A497C(a, 3, 8);
        break;
    case 20:
        r = (Unk80189300*)fn_801A497C(a, 3, 9);
        break;
    case 21:
        r = (Unk80189300*)fn_801A4C74((Unk8019F8C0_Owner*)a, 0);
        break;
    case 22:
        r = (Unk80189300*)fn_801A4C74((Unk8019F8C0_Owner*)a, 1);
        break;
    case 23:
        r = (Unk80189300*)fn_801A4C74((Unk8019F8C0_Owner*)a, 2);
        break;
    case 24:
        r = (Unk80189300*)fn_801A4C74((Unk8019F8C0_Owner*)a, 3);
        break;
    case 25:
        r = (Unk80189300*)fn_801A4C20((Unk8019F8C0_Owner*)a);
        break;
    case 26:
        r = (Unk80189300*)fn_801A497C(a, 0, 0);
        break;
    case 27:
        r = (Unk80189300*)fn_801A497C(a, 0, 1);
        break;
    case 28:
        r = (Unk80189300*)fn_801A497C(a, 0, 2);
        break;
    case 29:
        r = (Unk80189300*)fn_801A497C(a, 0, 3);
        break;
    case 30:
        r = (Unk80189300*)fn_801A497C(a, 0, 4);
        break;
    case 31:
        r = (Unk80189300*)fn_801A497C(a, 0, 5);
        break;
    case 32:
        r = (Unk80189300*)fn_801A497C(a, 0, 6);
        break;
    case 33:
        r = (Unk80189300*)fn_801A497C(a, 0, 7);
        break;
    case 34:
        r = (Unk80189300*)fn_801A497C(a, 0, 8);
        break;
    case 35:
        r = (Unk80189300*)fn_801A497C(a, 0, 9);
        break;
    case 36:
        r = (Unk80189300*)fn_801A497C(a, 1, 0);
        break;
    case 37:
        r = (Unk80189300*)fn_801A497C(a, 1, 1);
        break;
    case 38:
        r = (Unk80189300*)fn_801A497C(a, 1, 2);
        break;
    case 39:
        r = (Unk80189300*)fn_801A497C(a, 1, 3);
        break;
    case 40:
        r = (Unk80189300*)fn_801A497C(a, 1, 4);
        break;
    case 41:
        r = (Unk80189300*)fn_801A497C(a, 1, 5);
        break;
    case 42:
        r = (Unk80189300*)fn_801A497C(a, 1, 6);
        break;
    case 43:
        r = (Unk80189300*)fn_801A497C(a, 1, 7);
        break;
    case 44:
        r = (Unk80189300*)fn_801A497C(a, 1, 8);
        break;
    case 46:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 1);
        break;
    case 47:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 2);
        break;
    case 48:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 3);
        break;
    case 49:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 4);
        break;
    case 50:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 5);
        break;
    case 51:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 6);
        break;
    case 52:
        r = (Unk80189300*)fn_80178E6C(a->m700->m3AC, mA50->m3D44, 7);
        break;
    case 53:
        r = (Unk80189300*)fn_801A4C3C((Unk8019F8C0_Owner*)a, 0, mA50->m3D44);
        break;
    }
    return r;
}

void Unk801527C8_Ctx::fn_8016CE5C(int idx) /* 8016CE5C */
{
    int off = idx * 0xAC;
    int* pA8 = (int*)((char*)this + 0xA8);
    if (*(int*)((char*)pA8 + off) == 0x39) {
        void* sl = mA4C->m700->m3AC;
        int k = 0;
        do {
            Unk8016C788_Obj* o = fn_80178E6C(sl, 0, k);
            k++;
            fn_8016CF38(o);
        } while (k <= 7);
    } else if (*(int*)((char*)pA8 + off) == 0x3A) {
        void* sl = mA4C->m700->m3AC;
        int k = 0;
        do {
            Unk8016C788_Obj* o = fn_80178E6C(sl, 1, k);
            k++;
            fn_8016CF38(o);
        } while (k <= 7);
    } else {
        int* pA4 = (int*)((char*)this + 0xA4);
        fn_8016CF38(*(Unk8016C788_Obj**)((char*)pA4 + off));
    }
    int* pA4b = (int*)((char*)this + 0xA4);
    *(int*)((char*)pA4b + off) = 0;
    *(int*)((char*)pA8 + off) = 0;
}

void Unk801527C8_Ctx::fn_8016CF38(Unk8016C788_Obj* o) /* 8016CF38 */
{
    if (o != 0) {
        fn_80244A64(o, 0, 0);
        fn_8037EBE8(*(void**)((char*)o + 0x618));
        fn_803814A4(*(void**)((char*)o + 0x618), lbl_805CAD74, 0, 0);
        *(unsigned int*)((char*)o + 0x71C) &= ~0x1000;
        if (mA4C->m700 != 0) {
            fn_8017C75C(((Unk8016CF38_X*)*(void**)((char*)o + 0x44C))->m700, o);
        }
    }
}

void Unk80159F28::fn_8016CFC4(Unk8016C788_Obj* o) /* 8016CFC4 */
{
    if (o != 0) {
        *(unsigned int*)((char*)o + 0x71C) |= 0x1000;
        fn_80244A64(o, 0, 1);
        ((Unk80189300*)((char*)o + 0))->fn_v8(0);
        fn_80244A64(o, 0, 1);
    }
}

void Unk801527C8_Ctx::fn_8016D038(int idx, int id) /* 8016D038 */
{
    if (id == 0x39) {
        void* sl = mA4C->m700->m3AC;
        int k = 0;
        do {
            Unk8016C788_Obj* o = fn_80178E6C(sl, 0, k);
            k++;
            ((Unk80159F28*)this)->fn_8016CFC4(o);
        } while (k <= 7);
    } else if (id == 0x3A) {
        void* sl = mA4C->m700->m3AC;
        int k = 0;
        do {
            Unk8016C788_Obj* o = fn_80178E6C(sl, 1, k);
            k++;
            ((Unk80159F28*)this)->fn_8016CFC4(o);
        } while (k <= 7);
    } else {
        Unk8016C788_Obj* o = (Unk8016C788_Obj*)fn_8016C804(id);
        if (o != 0) {
            int* pA4 = (int*)((char*)this + 0xA4);
            *(Unk8016C788_Obj**)((char*)pA4 + idx * 0xAC) = o;
            ((Unk80159F28*)this)->fn_8016CFC4(o);
        }
    }
    int* pA8 = (int*)((char*)this + 0xA8);
    *(int*)((char*)pA8 + idx * 0xAC) = id;
}

extern "C" void fn_8016D128(void* p) /* 8016D128 */
{
    Unk8016ACAC* self = (Unk8016ACAC*)p;
    self->m4298 = 0;
    Unk8016ACAC_Slot* s = self->m1E28;
    for (int i = 3; i != 0; i--, s++) {
        s->mLists[0].fn_8016D258();
    }
    Unk8016D128_Elem* e = (Unk8016D128_Elem*)self->m3D94;
    for (int j = 0; j < 8; j++, e++) {
        e->name[0] = 0;
        e->m3C = 0;
        e->m40 = 0;
        e->m44 = 0;
        e->m48 = 0;
        e->m4C = 0;
        e->m50 = lbl_805EBA10;
        e->m68 = lbl_805EBA10;
        e->m80 = lbl_805EBA10;
        e->m98 = 0;
        e->m9C = 0xAE;
    }
    self->m3D90 = self->fn_8016C39C();
}

void Unk8016C1C4_List::fn_8016D258() /* 8016D258 */
{
    int p = (int)this;
    int end = p + 0x968;
    do {
        int z = 0;
        ((Unk8016C1C4_List*)p)->mCur = z;
        fn_80359910((Unk8016C1C4_List*)p);
        ((Unk8016C1C4_List*)p)->mA4 = z;
        p += 0xAC;
    } while (p <= end);
}

void Unk8016ACAC::fn_8016D2A4() /* 8016D2A4 */
{
    float t = lbl_805CAD78;
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 3; i != 0; i--, s++) {
        s->fn_8016D368(&t);
    }
}

/* near-miss: retail enters the loop through its condition (pre-header jump) and keeps the previous pointer in r30; for/while forms tried */
void Unk801527C8_Ctx::fn_8016D2F4(const char* s) /* 8016D2F4 */
{
    char* p = mA24[0];
    for (int i = 0; i <= 3; i++, p += 10) {
        if (fn_8040B6A0(p) == 0) {
            fn_8040B61C(p, s);
            break;
        }
    }
    fn_802AEBCC(lbl_8061E978, s);
}

void Unk8016ACAC_Slot::fn_8016D368(float* t) /* 8016D368 */
{
    if (mA20 != 0) {
        char buf[32];
        fn_804089B4(buf, lbl_805CAD7C, mA20);
        fn_80303BC4(buf, lbl_805CAD8C, *t);
    }
    *t = *t + lbl_805CAD90;
}

void Unk8016C1C4_List::fn_8016D3DC(int idx) /* 8016D3DC */
{
    int base = idx * 0xAC;
    int* pC = (int*)((char*)this + 0xC);
    float* p14 = (float*)((char*)this + 0x14);
    int cur = *(int*)((char*)this + base);
    int off = cur * 0x14 + base;
    *(int*)((char*)pC + off) = *(int*)((char*)pC + off) + 1;
    *(float*)((char*)p14 + off) = lbl_805CAD94;
}

void* fn_8016D410(void* self, int a) /* 8016D410 */
{
    fn_803282A8(self, 0);
    *(const void**)((char*)self + 0x18) = lbl_8065EBA8;
    *(int*)((char*)self + 0x24) = a;
    return self;
}

void fn_8016D458(Unk8016D778_S* self) /* 8016D458 */
{
    int f = 0;
    if (((Unk8016D458_O*)self->m24)->m744->m20 == 0 && lbl_8061B8C0->m24 == 0 && lbl_8061B8C0->m20 != 1) {
        f = 1;
    }
    int a = fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1)->m3D90;
    if (f != 0 && a != 0) {
        int r = fn_8016D580(self);
        int k = fn_8016D778(self);
        if (r != 0 || k != 2) {
            fn_802D74FC();
            fn_8016D850(self);
        }
        if (r != 0) {
            if (fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1)->m3D90 != 0) {
                if (fn_80359964((char*)fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1) + 4) == 1) {
                    fn_8031C6C0(fn_8031C6A8(), 1, 0xC, 0);
                }
            }
        }
        if (k != 2) {
            fn_8017CD04((Unk8017A930_T*)self->m24->m700, k, 0);
        }
    }
}

int fn_8016D580(Unk8016D778_S* self) /* 8016D580 */
{
    if (fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1)->fn_8016AF4C() != 0) {
        return 0;
    }
    int flag = 0;
    int c;
    int d;
    int a = fn_801A2034((Unk8019F8C0_Owner*)self->m24, 4);
    int b = fn_801A2034((Unk8019F8C0_Owner*)self->m24, 3);
    if (lbl_806192E0->m4->m10->m120 == 1) {
        if (*(float*)fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1) != -1.0f) {
            *(float*)fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1) -= 1.0f;
            flag = *(float*)fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1) < 0.0f;
        }
    }
    if (a == -1 && b == -1) {
        int i;
        for (i = 0; i <= 3; i++) {
            if (fn_802D7DB4(i, 0x5A) != 0 || fn_802D7DB4(i, 0xB8) != 0) {
                flag = 1;
                break;
            }
        }
    } else {
        c = 0;
        d = 0;
        if (a != -1) {
            if (fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1)->fn_8016AD7C(4) != 0) {
                c = 1;
            }
        }
        if (b != -1) {
            if (fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1)->fn_8016AD7C(3) != 0) {
                d = 1;
            }
        }
        if (c != 0 && (fn_802D7DB4(a, 0x5A) != 0 || fn_802D7DB4(a, 0xB8) != 0)) {
            flag = 1;
        }
        if (d != 0 && (fn_802D7DB4(b, 0x5A) != 0 || fn_802D7DB4(b, 0xB8) != 0)) {
yes:
            flag = 1;
        }
    }
    return flag;
}

/* near-miss: frame layout only (8 slots): retail has the two ids at sp+8/0xC and the clamp iterator at sp+0x10;
 * here the iterator (dtor object) gets sp+8 and the ids sp+0x10. Declaration order, scopes, volatile counter and
 * dtor-bearing id struct tried. */
int fn_8016D778(Unk8016D778_S* self) /* 8016D778 */
{
    if (fn_801A04A8((Unk8019F8C0_Owner*)self->m24, 1)->m44 != 0) {
        int ids[2];
        ids[1] = fn_801A2034((Unk8019F8C0_Owner*)self->m24, 1);
        ids[0] = fn_801A2034((Unk8019F8C0_Owner*)self->m24, 0);
        Unk8006A138_It<1> it(0);
        int idx = 0;
        while (idx <= 1) {
            if (fn_8017CA14((Unk8017A930_T*)self->m24->m700, idx) != 0 && ids[it.v] != -1 && fn_802D7DB4(ids[it.v], 0x5B) != 0) {
                return it.v;
            }
            idx = it.Next();
        }
    }
    return 2;
}

void fn_8016D850(Unk8016D778_S* self) /* 8016D850 */
{
    if (fn_801A6DB8((Unk8019F8C0_Owner*)self->m24)->m6C != 0) {
        Unk8016D850_G* g = lbl_8061B8C0;
        Unk801527C8_Actor* a = g->m8;
        Unk801527C8_Actor* b = g->mC;
        if (a != 0) {
            fn_8016D924(self, fn_801A6D84((Unk8019F8C0_Owner*)a, 1));
        }
        if (b != 0) {
            fn_8016D924(self, fn_801A6D84((Unk8019F8C0_Owner*)b, 1));
        }
    } else {
        fn_8016D924(self, fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 1));
        if (fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 5)->m3D90 != 0) {
            fn_8016D924(self, fn_801A6D84((Unk8019F8C0_Owner*)self->m24, 5));
        }
    }
}

void fn_8016D924(void* self, Unk8016ACAC* m) /* 8016D924 */
{
    int ok = 1;
    if (m->m4298 <= 0) {
        ok = 0;
    }
    if (ok == 0) {
        int v = 4;
        if ((void*)m == (void*)fn_801A6D84(m->m3D3C, 1) && m->fn_8016B174() != 0) {
            m->fn_8016B95C();
            v = 0x1B;
        }
        m->m4298 = v;
    }
}

void Unk8016D9A0::fn_8016D9A0(Unk8016D9A0_Rec* rec) /* 8016D9A0 */
{
    if (m1E00 <= 5) {
        m0[m1E00] = *rec;
        m1E00 = m1E00 + 1;
        fn_8016E0E8((char*)rec);
    }
}

void Unk8016D9A0::fn_8016DA48(Unk8016D9A0_Rec* rec) /* 8016DA48 */
{
    if (m1E00 <= 5) {
        for (int i = m1E00; i > 0; i--) {
            m0[i] = m0[i - 1];
        }
        m0[0] = *rec;
        m1E00 = m1E00 + 1;
        fn_8016E0E8((char*)rec);
    }
}

int fn_8016DB74(const char* s) /* 8016DB74 */
{
    return fn_8040B574(s, lbl_805C6244) == 0;
}

int Unk8016DBAC_Obj::fn_8016DBA4() /* 8016DBA4 */
{
    return m98;
}

void Unk8016DBAC_Obj::fn_8016DBAC() /* 8016DBAC */
{
    if (fn_8016DB74((char*)this) != 0) {
        fn_803596DC(this);
        m98 = 1;
    }
}

int Unk8016D9A0::fn_8016DBF0() /* 8016DBF0 */
{
    for (int i = 0; i < m1E00; i++) {
        if (fn_80169DC4(m0[i].m) != 0) {
            return 1;
        }
    }
    return 0;
}

void Unk8016D9A0::fn_8016DFD0() /* 8016DFD0 */
{
    int p = (int)this;
    int end = p + 0x1900;
    do {
        Unk8016D128_Elem* e = (Unk8016D128_Elem*)p;
        for (int j = 0; j < 8; j++, e++) {
            e->name[0] = 0;
            e->m3C = 0;
            e->m40 = 0;
            e->m44 = 0;
            e->m48 = 0;
            e->m4C = 0;
            e->m50 = lbl_805EBA10;
            e->m68 = lbl_805EBA10;
            e->m80 = lbl_805EBA10;
            e->m98 = 0;
            e->m9C = 0xAE;
        }
        p += 0x500;
    } while (p <= end);
    m1E00 = 0;
    fn_8016E18C();
}

/* near-miss: retail keeps a separate copy of the previous offset (r29 = r27) for the loop update; 4 loop forms tried */
void Unk8016D9A0::fn_8016E0E8(const char* rec) /* 8016E0E8 */
{
    if (m1E20 != 0 && m1E1C <= 5) {
        int p = (int)rec;
        int off = 0;
        int end = (int)rec + 0x460;
        while (p <= end) {
            int cur = off;
            if (fn_8040B6A0((char*)p) != 0) {
                int* q = (int*)(rec + 0x44);
                int v = *(int*)((char*)q + off);
                if (v != 0) {
                    m1E04[m1E1C] = v;
                    m1E1C = m1E1C + 1;
                }
                break;
            }
            off = cur + 0xA0;
            p += 0xA0;
        }
    }
}

void Unk8016D9A0::fn_8016E18C() /* 8016E18C */
{
    for (int i = 0; i < 6; i++) {
        m1E04[i] = 0;
    }
    m1E1C = 0;
}

/*
 * Tail of the unity TU: virtual slot 3 (class-name string) / slot 4 (name hash)
 * getters of the script classes whose vtables are emitted here (cLocationObject,
 * cDepthOfFieldParameters, cActorScriptConditional, ...). The classes are declared
 * in the previous range; these are written as free functions with the same code.
 */
extern const char* lbl_8061BE10;
extern const char* lbl_8061BE18;
extern const char lbl_805C626C[];
extern const char lbl_805C7958[];

void fn_8016F340() /* 8016F340 */
{
}

const char* fn_8016F344() /* 8016F344 */
{
    return lbl_8061BE10;
}

int fn_8016F350() /* 8016F350 */
{
    return 0x149EF3D8;
}

const char* fn_8016F35C() /* 8016F35C */
{
    return lbl_805C626C;
}

int fn_8016F368() /* 8016F368 */
{
    return 0x916112DD;
}

const char* fn_8016F374() /* 8016F374 */
{
    return lbl_8061BE18;
}

int fn_8016F380() /* 8016F380 */
{
    return 0x37EF0C2A;
}

Unk8016F38C_A::~Unk8016F38C_A() /* 8016F38C */
{
}

const char* fn_8016F3E8() /* 8016F3E8 */
{
    return lbl_805C7958;
}

int fn_8016F3F4() /* 8016F3F4 */
{
    return 0x323DA6EA;
}

Unk8016F400_A::~Unk8016F400_A() /* 8016F400 */
{
}
