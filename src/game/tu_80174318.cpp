/*
 * Game code, .text 0x80174318-0x80177C34 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80174318.h"

extern const float lbl_805CBCFC;
struct Unk80273498_Vec3 {
    float x;
    float y;
    float z;
};

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
extern "C" void* fn_8035AB00(void* self);

struct Unk8019F8C0_Owner;
struct Unk80177170_Inner {
    char pad0[0xAF0];
    int mAF0;
};
struct Unk80177170_Obj {
    char pad0[0x448];
    Unk80177170_Inner* m448;
};
Unk80177170_Obj* fn_801A5218(Unk8019F8C0_Owner* o);
extern "C" float fn_804028E4(float x);

struct Unk80177170_T {
    char pad0[8];
    Unk8019F8C0_Owner* m8;
    char padC[4];
    Unk80273498_Vec3 m10;
    Unk80273498_Vec3 m1C;
    Unk80273498_Vec3 m28;
    Unk80273498_Vec3 m34;
    char pad40[4];
    Unk80177170_Obj* m44;
};

extern const Unk80174318_Fn lbl_805CB1CC;
extern int lbl_8061C668;
extern const Unk80174318_Fn lbl_805CB1D4;
extern int lbl_8061C674;
extern char lbl_8065FCF0[];

void fn_80174318(Unk80174318_T* p, int state, Unk80174318_Fn f)
{
    p->m7C = state;
    p->m80 = f;
    Unk80174318_Fn g = lbl_805CB1CC;
    p->m74 = g;
}

void fn_80174348(Unk80174348_T* p)
{
    fn_80174438((Unk80174438_T*)p);
    p->m5C = 0;
    for (unsigned int i = 0; i <= 3; i++) {
        p->m8[i] = new (0x100) Unk8016FF40;
        fn_8017008C(p->m8[i], p->m88);
        for (int j = 1; j < 4; j++) {
            Unk80174318_Pair* v = &p->m1C[j];
            p->m8[i]->m108[j] = v;
        }
    }
}

/* near-miss: retail copies the loaded value into r3 separately (mr r3,r0; 22 instrs); the copy is
 * coalesced here (21). */
int fn_801743E0(int* arr)
{
    int r;
    for (int i = 0; i < 1; i++) {
        int v = arr[i];
        r = v;
        if (v != 0) {
            r = fn_8000587C(v);
            arr[i] = 0;
        }
    }
    return r;
}

void fn_80174438(Unk80174438_T* p)
{
    for (unsigned int i = 0; i <= 3; i++) {
        Unk8016FF40* o = p->m8[i];
        if (o != 0) {
            delete o;
            p->m8[i] = 0;
        }
    }
}

void fn_801744AC(Unk80174318_T* p)
{
    for (int i = 0; i < 4; i++) {
        p->m1C[i].m0 = 0;
        p->m1C[i].m4 = 0;
    }
}

void fn_801744D8(Unk80173274_T* p, int a, int b, int c)
{
    ((Unk80170518*)fn_80173274(p))->fn_80005F4C(a, b, c);
}

struct Unk80090880;
char* fn_80090880(Unk80090880* p);
typedef char* (*DbLook174530)(Unk80090880*, int);
unsigned fn_800734D4(void* s, unsigned flags);
extern void* lbl_8061930C;
extern Unk80090880* lbl_8061977C;
extern int lbl_8061C670;
extern const Unk80174318_Fn lbl_805CB154;
struct Unk80174530_V {
    char pad0[0x38];
    Unk8016FF40* m38;
    char pad3C[0x40 - 0x3C];
    int m40;
    char pad44[0x50 - 0x44];
    int m50;
};
extern "C" void fn_80174530(Unk80174318_T* p) /* 80174530 */
{
    void* g = lbl_8061930C;
    Unk80090880* t = lbl_8061977C;
    Unk8016FF40 info;
    for (int j = 1; j < 4; j++) {
        Unk80174318_Pair* v = &p->m1C[j];
        info.m108[j] = v;
    }
    ((Unk80174530_V*)fn_80173274((Unk80173274_T*)p))->m38 = &info;
    int a = fn_800734D4(g, 0x10000000) + 0xB0;
    int id = (int)fn_800734D4(g, 0x1101311) > (int)fn_800734D4(g, 0x2131311) ? 0x610 : 0x61E;
    fn_801744D8((Unk80173274_T*)p, (int)((DbLook174530)fn_80090880)(t, id), a, 1);
    a = fn_800734D4(g, 0x20000000) + 0xB0;
    id = (int)fn_800734D4(g, 0x1101311) < (int)fn_800734D4(g, 0x2131311) ? 0x610 : 0x61E;
    fn_801744D8((Unk80173274_T*)p, (int)((DbLook174530)fn_80090880)(t, id), a, 0);
    a = fn_800734D4(g, 0x100) + 0xB0;
    fn_801744D8((Unk80173274_T*)p, (int)((DbLook174530)fn_80090880)(t, 0x60F), a, 0);
    a = fn_800734D4(g, 0x11) + 0xB0;
    fn_801744D8((Unk80173274_T*)p, (int)((DbLook174530)fn_80090880)(t, 0x60E), a, 0);
    a = fn_800734D4(g, 0x200000) + 0xB0;
    fn_801744D8((Unk80173274_T*)p, (int)((DbLook174530)fn_80090880)(t, 0x60D), a, 0);
    ((Unk80174530_V*)p)->m50 = 0;
    ((Unk80174530_V*)p)->m40 = 1;
    if (lbl_8061C670 == 0) {
        ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80170668(0, 6);
        lbl_8061C670 = 1;
        fn_80174318(p, 0x14, lbl_805CB154);
    }
}

void fn_80174760(Unk80174318_T* p)
{
    fn_80174318(p, 6, lbl_805CB1D4);
}

int fn_801747A0()
{
    return lbl_8061C668;
}

/* near-miss: only the order of `li r4,1` / `mr r3,r31` before fn_80402DE4 differs (2 slots); treating the
 * callee as a method call did not change it. */
int fn_801747AC(const char* name)
{
    char buf[128];
    int r = fn_802B9300((int)name, 0x100, 0xE, 0);
    if (r == 0) {
        fn_804089B4(buf, lbl_805CB1DC, name);
    }
    fn_80402DE4(r, 1);
    fn_80402BEC(r, 0, 0);
    return r;
}

void fn_80174824(int a)
{
    fn_80402CAC(lbl_8061C674, a);
}

struct Unk80174850_Cfg {
    Unk80174850_Cfg()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
        mC = 0;
    }
    int m0;
    int m4;
    int m8;
    void (*mC)(int);
};

void fn_80174850()
{
    Unk80174850_Cfg c;
    fn_8040074C(&c, 0x10);
    c.m0 = fn_80359BAC();
    c.m8 = fn_80359C58();
    c.m4 = fn_80359E94();
    c.mC = fn_80174824;
    lbl_8061C674 = fn_801747AC(lbl_805CB208);
    fn_803EE8F8(&c);
}

void fn_801748D8(Unk801748D8_Obj* o)
{
    if (lbl_8061C674 != 0) {
        fn_803EDA0C(lbl_8061C674);
        lbl_8061C674 = 0;
    }
    if (o != 0) {
        o->vslot2();
    }
}

int fn_801757C0(void* p, int a)
{
    return a;
}

int fn_801757C8()
{
    return 0;
}

void fn_801757D0() {}

int fn_801757D4(Unk801757D4_T* p)
{
    return p->mC0;
}

void fn_801757DC() {}

void fn_801757E0() {}

void fn_801757E4()
{
    fn_8017493C(1, 0xFFFF);
}

void fn_801765F4()
{
    fn_80175810(1, 0xFFFF);
}

/* near-miss: 6 slots, all in the first entry-init loop. Retail emits m0 first (before the -1.0f load), then
 * m44, the float at +4, m8, mC, m40; the best of all 720 store orders (and the literal / extern float spellings)
 * gives m44, f4, m0 in the middle. Second loop and ctor frame match. */
Unk80176C0C_T* fn_80176654(Unk80176C0C_T* self, int a, Unk80176C0C_Ctx* ctx) /* 80176654 */
{
    fn_8035AB00(self);
    *(const void**)self = lbl_8065FCF0;
    for (int i = 0; i < 5; i++) {
        Unk80176C0C_Entry* e = &self->mC[i];
        e->m0 = 0;
        *(float*)&e->m4 = -1.0f;
        e->m8 = 0;
        e->mC = 0;
        *(int*)((char*)e + 0x40) = 0;
        e->m44 = 0;
    }
    *(int*)((char*)self + 4) = a;
    self->m8 = ctx;
    Unk80176C0C_Entry* q = self->mC;
    for (int j = 0; j < 5; j++, q++) {
        q->m8 = (int)ctx;
    }
    fn_80176C0C(self);
    return self;
}

class Unk80176620 {
public:
    virtual ~Unk80176620();
};

Unk80176620::~Unk80176620() {}

void fn_801766F8() {}

void fn_801766FC(void* self)
{
    fn_80176C0C(self);
}

void fn_8017671C(char* self)
{
    fn_80177B40(self + 0x12C);
}

void fn_80176740(Unk80176C0C_T* p)
{
    if (fn_801A7020(p->m8) == 0) {
        fn_80177B40((char*)p + 0x12C);
    }
}

struct Unk8017DD64_T;
struct Unk802531FC_C;
void fn_8017DD80(Unk8017DD64_T* s, int k, int* a, int* b);
void fn_80253220(Unk802531FC_C* p);
extern "C" char* fn_801A497C(void* ctx, int a, int b);

struct Unk80176780_T {
    char pad0[4];
    Unk8017DD64_T* m4;
    void* m8;
};

void fn_80176780(Unk80176780_T* p) /* 80176780 */
{
    char* x = fn_801A497C(p->m8, 0, 0);
    int a = 0;
    int b = 0;
    fn_8017DD80(p->m4, 0, &a, &b);
    if (x != 0) {
        fn_80253220((Unk802531FC_C*)(x + 0x480));
    }
    if (a != 0) {
        fn_80253220((Unk802531FC_C*)(a + 0x480));
    }
    if (b != 0) {
        fn_80253220((Unk802531FC_C*)(b + 0x480));
    }
    x = fn_801A497C(p->m8, 1, 0);
    a = 0;
    b = 0;
    fn_8017DD80(p->m4, 1, &a, &b);
    if (x != 0) {
        fn_80253220((Unk802531FC_C*)(x + 0x480));
    }
    if (a != 0) {
        fn_80253220((Unk802531FC_C*)(a + 0x480));
    }
    if (b != 0) {
        fn_80253220((Unk802531FC_C*)(b + 0x480));
    }
}

class Unk80176884_Obj {
public:
    char pad0[0x98];
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3(const Unk80177A90_V3& v);
};
struct Unk80150FC0_Rec {
    int m0;
    Unk80177A90_V3 m4;
};
extern "C" Unk80150FC0_Rec* fn_80150FC0(unsigned int hash);
void fn_80177A48(Unk80177B74_T* p, void* a, void* b, int c);

inline Unk80177A90_V3 PosOf(const Unk80150FC0_Rec* r) { return r->m4; }
void fn_80176884(Unk80176C0C_T* p) /* 80176884 */
{
    if (fn_801A7020(p->m8) == 0) {
        Unk80176C0C_Ctx* c = p->m8;
        Unk80176C0C_Rec* r = c->m6F8->m14;
        if (r->m1CC8 == 0 && r->m1CD0 == 1) {
            Unk80176884_Obj* o = (Unk80176884_Obj*)c->m65C.m0;
            Unk80150FC0_Rec* d = fn_80150FC0(0x6750DDAA);
            if (d == 0) {
                o->fn_vslot3(lbl_806055AC);
            } else {
                o->fn_vslot3(PosOf(d));
            }
            fn_80177A48((Unk80177B74_T*)((char*)p + 0x12C), o, (void*)p->m8->m65C.m4, 0);
        }
    }
}

void fn_8017696C(void* self)
{
    fn_801769A8(self, 0);
    fn_801769A8(self, 1);
}

struct Unk80177974_T;
void fn_80177974(Unk80177974_T* p);
struct Unk801769A8_Obj {
    char pad0[0x38C];
    int m38C;
    char pad390[0x458 - 0x390];
    int m458;
};
void fn_80176ADC(Unk80176C0C_T* p, Unk80176ADC_Obj* a, int idx);
/* near-miss 96.6%: retail computes `f * 0x48` once into r9 and copies it (`mr r3,r9`) before the `add r9,r9,r31`
 * for the second use; here the product lives in r3 and the sum goes to r9 (75 instrs vs 77; 6 variants of the
 * address spelling tried, the permuter found nothing closer). */
void fn_801769A8(void* self, int a) /* 801769A8 */
{
    Unk80176C0C_T* p = (Unk80176C0C_T*)self;
    Unk80176ADC_Obj* x = 0;
    Unk80176ADC_Obj* y = 0;
    fn_8017DD80((Unk8017DD64_T*)((Unk80176780_T*)p)->m4, a, (int*)&x, (int*)&y);
    int k0;
    int k1;
    if (a == 1) {
        k0 = 2;
        k1 = 3;
    } else {
        k0 = 0;
        k1 = 1;
    }
    if (x != 0) {
        int t = 0;
        if (((Unk801769A8_Obj*)x)->m458 != 1) {
            t = ((Unk801769A8_Obj*)x)->m38C;
        }
        int f;
        int g;
        if (t == 0) {
            f = k1;
            g = k0;
        } else {
            f = k0;
            g = k1;
        }
        int off = f * 0x48;
        if (*(void**)((char*)p + off + 0x18) != x) {
            fn_80177974((Unk80177974_T*)((char*)p + (off + 0xC)));
        }
        int off2 = g * 0x48;
        if (*(void**)((char*)p + off2 + 0x18) != y) {
            fn_80177974((Unk80177974_T*)((char*)p + (off2 + 0xC)));
        }
        fn_80176ADC(p, x, f);
        if (y != 0) {
            fn_80176ADC(p, y, g);
        }
    } else {
        fn_80177974((Unk80177974_T*)((char*)p + (k0 * 0x48 + 0xC)));
        fn_80177974((Unk80177974_T*)((char*)p + (k1 * 0x48 + 0xC)));
    }
}

/* near-miss: retail recomputes `off + this` for each use (37 instrs); the byte-offset and entry-pointer
 * spellings tried CSE it (34-35). */
void fn_80176ADC(Unk80176C0C_T* p, Unk80176ADC_Obj* a, int idx)
{
    fn_801A656C(p->m8, a, 0xF);
    int off = idx * 0x48;
    if (*(void**)((char*)p + off + 0x18) != a) {
        fn_80177B74((Unk80177B74_T*)((char*)p + off + 0xC), a, 1);
        return;
    }
    if (a->m618->m838 == 0 || a->m264 != 0) {
        fn_80177B74((Unk80177B74_T*)((char*)p + off + 0xC), a, 1);
    }
}

void fn_80176B70(void* self)
{
    fn_8017696C(self);
}

/* near-miss: register numbering (ctx in r4/r11 here, r11/r9 in retail) and the placement of the
 * &c->m65C addi; 4 variants tried. */
void fn_80176B90(Unk80176C0C_T* p)
{
    if (fn_801A7020(p->m8) == 0) {
        Unk80176C0C_Ctx* c = p->m8;
        Unk80176C0C_Rec* r = c->m6F8->m14;
        Unk80176C0C_Pair* q = &c->m65C;
        if (r->m1CC8 == 0 && r->m1CD0 == 0 && q->m0 != 0) {
            fn_80177A48((char*)p + 0x12C, q->m0, q->m4, 1);
        }
    }
}

void fn_80176C0C(Unk80176C0C_T* p)
{
    Unk80176C0C_Entry* e = p->mC;
    for (int i = 0; i < 5; i++) {
        fn_80177A90(e);
        e++;
    }
}

struct Unk8019F8C0_Owner;
void* fn_801A4C5C(Unk8019F8C0_Owner* o, int a, int b);
extern "C" Unk80273498_Vec3 fn_80183A44(void* obj, int a, int b);
extern const Unk80177A90_V3 lbl_805D0058;
void fn_80177170(Unk80177170_T* p);
struct Unk80176C4C_Ctx {
    char pad0[0x6B8];
    void* m6B8;
};

void fn_80176C4C(Unk80176C0C_T* p) /* 80176C4C */
{
    fn_80176C0C(p);
    ((Unk80177170_T*)&p->mC[0])->m10 = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 0, 0);
    ((Unk80177170_T*)&p->mC[0])->m1C = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 0, 2);
    ((Unk80177170_T*)&p->mC[1])->m10 = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 0, 1);
    ((Unk80177170_T*)&p->mC[1])->m1C = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 0, 3);
    ((Unk80177170_T*)&p->mC[2])->m10 = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 1, 0);
    ((Unk80177170_T*)&p->mC[2])->m1C = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 1, 2);
    ((Unk80177170_T*)&p->mC[3])->m10 = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 1, 1);
    ((Unk80177170_T*)&p->mC[3])->m1C = fn_80183A44(((Unk80176C4C_Ctx*)p->m8)->m6B8, 1, 3);
    ((Unk80177170_T*)&p->mC[4])->m10 = *(const Unk80273498_Vec3*)&lbl_805D0058;
    ((Unk80177170_T*)&p->mC[4])->m1C = *(const Unk80273498_Vec3*)&lbl_806055AC;
    fn_80177BCC(&p->mC[0], fn_801A4C5C((Unk8019F8C0_Owner*)p->m8, 0, 0));
    fn_80177BCC(&p->mC[1], fn_801A4C5C((Unk8019F8C0_Owner*)p->m8, 0, 1));
    fn_80177BCC(&p->mC[2], fn_801A4C5C((Unk8019F8C0_Owner*)p->m8, 1, 0));
    fn_80177BCC(&p->mC[3], fn_801A4C5C((Unk8019F8C0_Owner*)p->m8, 1, 1));
    int n = 5;
    Unk80176C0C_Entry* e = &p->mC[0];
    do {
        fn_80177170((Unk80177170_T*)e);
        e++;
        n--;
    } while (n != 0);
    p->m174 = n;
}

void fn_80176F04(Unk80176C0C_T* p, int a)
{
    Unk80176C0C_Entry* e = p->mC;
    for (int i = 0; i < 5; i++) {
        fn_8017739C(e, a);
        e++;
    }
}

void fn_80176F4C(Unk80176C0C_T* p)
{
    Unk80176C0C_Ctx* c = p->m8;
    if (fn_8006BE18(c->m6F8) != 0) {
        fn_801766FC(p);
    }
    if (fn_801A2400(p->m8) != 0) {
        Unk80176C0C_Entry* e = p->mC;
        p->m174 = p->m174 + lbl_8061B9C8;
        for (int i = 0; i < 5; i++) {
            fn_8017772C(e);
            e++;
        }
    }
}

void fn_80176FD0() {}

int fn_80176FD4(Unk8017706C_T* p, int a)
{
    int r;
    if (a == 0) {
        r = 0;
        bool b = p->m18;
        if (!b) {
            bool c = p->m60;
            if (c) {
                goto yes;
            }
        } else {
yes:
            r = 1;
        }
        return r;
    }
    r = 0;
    bool b = p->mA8;
    if (!b) {
        bool c = p->mF0;
        if (c) {
            goto yes2;
        }
    } else {
yes2:
        r = 1;
    }
    return r;
}

int fn_8017706C(Unk8017706C_T* p, int a)
{
    int r = 0;
    if (a == 0) {
        bool b = p->m18;
        if (b) {
            r = 1;
        }
        bool c = p->m60;
        if (c) {
            r += 1;
        }
    } else {
        bool b = p->mA8;
        if (b) {
            r = 1;
        }
        bool c = p->mF0;
        if (c) {
            r += 1;
        }
    }
    return r;
}

int fn_801770E8(Unk8017706C_T* p, int a)
{
    if (a == 0) {
        int t = p->m18;
        bool b = t;
        if (b) {
            return t;
        }
        return p->m60;
    }
    int u = p->mA8;
    bool c = u;
    if (c) {
        return u;
    }
    return p->mF0;
}

int fn_80177148(int* p, int a)
{
    if (p[0x60 / 4] == a || p[0xF0 / 4] == a) {
        return 1;
    }
    return 0;
}

inline Unk80273498_Vec3 operator+(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Unk80273498_Vec3 Scale(const Unk80273498_Vec3& v, float k)
{
    Unk80273498_Vec3 r;
    r.x = v.x * k;
    r.y = v.y * k;
    r.z = v.z * k;
    return r;
}

inline Unk80273498_Vec3 Normalize(const Unk80273498_Vec3& v, float len)
{
    Unk80273498_Vec3 r;
    float inv = 1.0f / len;
    r.x = v.x * inv;
    r.y = v.y * inv;
    r.z = v.z * inv;
    return r;
}

inline Unk80273498_Vec3 NormalizeOrDefault(const Unk80273498_Vec3& v)
{
    float len = fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len != 0.0f) {
        return Normalize(v, len);
    }
    return *(const Unk80273498_Vec3*)&lbl_806055AC;
}

void fn_80177170(Unk80177170_T* p) /* 80177170 */
{
    Unk80273498_Vec3 d = p->m1C - p->m10;
    d.y = 0.0f;
    p->m28 = NormalizeOrDefault(d);
    p->m34 = p->m1C + Scale(p->m28, 66.0f);
    if (p->m44 == 0) {
        p->m44 = fn_801A5218(p->m8);
    }
    p->m44->m448->mAF0 = 0;
}

void fn_8017739C(Unk80176C0C_Entry* p, int a)
{
    if (p->m44 == a) {
        if (p->m0 == 3) {
            fn_80178720(p);
        } else if (p->m0 == 5) {
            fn_80178944(p);
        }
    }
}

struct Unk80270BA0_X;
void fn_80299B98(Unk80270BA0_X* x, const Unk80273498_Vec3& pos, float* ang);
void fn_80244858(Unk80270BA0_X* x, float f);
extern "C" float atan2f(float y, float x);
void fn_80177EE0(void* p);

class Unk8017757C_Obj {
public:
    char pad0[0x98];
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
};
struct Unk8017757C_T {
    char pad0[0xC];
    Unk80270BA0_X* mC;
    Unk80273498_Vec3 m10;
    char pad1C[0x28 - 0x1C];
    float m28;
    char pad2C[4];
    float m30;
    char pad34[0x44 - 0x34];
    void* m44;
};

struct Unk8017757C_View {
    char pad0[0x320];
    Unk80273498_Vec3 m320;
};
inline void SetPos(Unk8017757C_View* o, Unk80273498_Vec3 v) { o->m320 = v; }
struct Unk80270BA0_X;
struct Unk8016C788_Obj;
extern "C" float atan2f(float y, float x);
void fn_80299B98(Unk80270BA0_X* x, const Unk80273498_Vec3& pos, float* ang);

struct Unk8027C728_Goal {
    char pad0[0x10];
    int m10;
    char pad14[0x28 - 0x14];
    Unk80273498_Vec3 m28;
    char pad34[0x40 - 0x34];
    int m40;
};
extern "C" Unk8027C728_Goal* fn_802448F4(Unk8016C788_Obj* o, int a);
void fn_8027C728(Unk8027C728_Goal* g);
void fn_8027D33C(Unk8027C728_Goal* g);

struct Unk80287D70 {
    void fn_80287DB8(int a);
    char pad0[0x28];
    int m28;
};
struct Unk8027A84C {
    void fn_8027A898(const Unk80273498_Vec3* v);
};

class Unk801773E4_Obj {
public:
    char pad0[0x98];
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
};
struct Unk801773E4_T {
    char pad0[8];
    void* m8;
    char padC[0x28 - 0xC];
    Unk80273498_Vec3 m28;
    Unk80273498_Vec3 m34;
    Unk801773E4_Obj* m40;
};

inline void SetPos28(Unk8027C728_Goal* g, Unk80273498_Vec3 v)
{
    g->m28 = v;
}

/* near-miss (2 slots): `li r4,12` precedes `mr r3,r29` before the fn_80287DB8 call in retail; here the order is
 * swapped. Everything else matches (stack layout needs ang declared before the scoped Vec3). */
void fn_801773E4(Unk801773E4_T* p) /* 801773E4 */
{
    fn_801A656C(p->m8, p->m40, 0x10);
    p->m40->fn_vslot8(0);
    float ang;
    {
        Unk80273498_Vec3 v = Scale(p->m28, -1.0f);
        ang = atan2f(v.x, v.z);
    }
    fn_80299B98((Unk80270BA0_X*)p->m40, p->m34, &ang);
    Unk8027C728_Goal* g = fn_802448F4((Unk8016C788_Obj*)p->m40, 1);
    g->m10 = 2;
    fn_8027C728(g);
    Unk80287D70* s = (Unk80287D70*)((char*)g + 0x18);
    s->fn_80287DB8(0xC);
    SetPos28(g, p->m34);
    s->m28 = 1;
    Unk80273498_Vec3 w = Scale(p->m28, -1.0f);
    ((Unk8027A84C*)s)->fn_8027A898(&w);
    fn_8027D33C(g);
}

void fn_8017757C(Unk8017757C_T* self, int a) /* 8017757C */
{
    fn_80177C74(self, 1);
    if (a != 0) {
        fn_80299B98(self->mC, self->m10, 0);
    }
    SetPos((Unk8017757C_View*)self->mC, self->m10);
    fn_80244858(self->mC, atan2f(self->m28, self->m30));
    fn_80189300(self->m44, (int)self->mC);
    ((Unk8017757C_Obj*)self->mC)->fn_vslot8(0);
    fn_80177EE0(self);
}

struct Unk8026C414_O;
struct Unk8026C414_X;
int fn_8026D5FC(Unk8026C414_O* o, Unk8026C414_X* x);

struct Unk80177654_Obj {
    char pad0[0x60];
    Unk80273498_Vec3 m60;
    char pad6C[0x450 - 0x6C];
    int m450;
};
struct Unk80177654_T {
    char pad0[0xC];
    Unk80177654_Obj* mC;
    Unk80273498_Vec3 m10;
};

int fn_80177654(Unk80177654_T* self) /* 80177654 */
{
    Unk80177654_Obj* o = self->mC;
    Unk80273498_Vec3 p = o->m60;
    if (o->m450 != 0) {
        Unk80273498_Vec3 d = p - self->m10;
        if (!(d.x * d.x + d.z * d.z >= 144.0f)) {
            if (fn_8026D5FC((Unk8026C414_O*)o, 0) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

void fn_80177900(void* self, Unk80177900_Obj* o)
{
    if (o) {
        fn_80244A64(o, 0, 0);
        fn_8037EBE8(o->m618);
        fn_803814A4(o->m618, 0, 0, lbl_805CBD24);
        o->m908 = 0;
        fn_8024D178(o, 0);
        o->m8F0 = 0;
    }
}

void fn_80177974(Unk80177974_T* p)
{
    fn_80177BF4((Unk80177B74_T*)p, 0);
    fn_80177C74(p, 0);
    if (p->m44 != 0) {
        fn_80189300(p->m44, 0);
        p->m44->fn_vslot8(1);
    }
    Unk80177974_Obj* o = p->m40;
    if (o != 0) {
        o->fn_vslot8(1);
    }
}

void fn_80177A0C(void* self)
{
    fn_80177C34(self, 0);
    fn_80177C74(self, 0);
}

void fn_80177A48(Unk80177B74_T* p, void* a, void* b, int c)
{
    fn_80177BCC(p, b);
    fn_80177B74(p, a, c);
}

void fn_80177A90(Unk80177A90_T* p)
{
    fn_80177B40(p);
    fn_80177C74(p, 0);
    p->m10 = lbl_806055AC;
    p->m1C = lbl_806055AC;
    p->m28 = lbl_806055AC;
    p->m34 = lbl_806055AC;
}

void fn_80177B40(void* self)
{
    fn_80177974(self);
    fn_80177A0C(self);
}

void fn_80177B74(Unk80177B74_T* p, void* a, int c)
{
    if (a && p->m40 != 0) {
        fn_80177BF4(p, a);
        fn_8017757C((Unk8017757C_T*)p, c);
        fn_801773E4(p);
    }
}

void fn_80177BCC(void* self, void* a)
{
    if (a) {
        fn_80177C34(self, a);
    }
}

void fn_80177BF4(Unk80177B74_T* p, void* a)
{
    if (a != p->mC) {
        fn_80177900(p, p->mC);
        p->mC = a;
    }
}
