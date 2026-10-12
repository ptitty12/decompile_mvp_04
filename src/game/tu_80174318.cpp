/*
 * Game code, .text 0x80174318-0x80177C34 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80174318.h"

extern const float lbl_805CBCFC;
extern "C" void* fn_8035AB00(void* self);

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

void fn_8017696C(void* self)
{
    fn_801769A8(self, 0);
    fn_801769A8(self, 1);
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
        fn_8017757C(p, c);
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
