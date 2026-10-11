/*
 * Game code, .text 0x8014013C-0x80144190 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

/* Object with its vptr at +0x1C (returned by fn_8058F1F0 / fn_8058F11C). */
struct Unk8058F1F0_Data {
    char pad0[0x1C];
};
struct Unk8058F1F0 : Unk8058F1F0_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual int fn_vslot9();
};
struct Unk8061930C {
    char pad0[0x34];
    int m34;
};
extern Unk8061930C* lbl_8061930C;
extern const int lbl_805C1B54[];
extern "C" {
Unk8058F1F0* fn_8058F1F0(int a, int b);
int fn_805901AC(Unk8058F1F0* o, int v);
int fn_8007DA28(Unk8061930C* g);
int fn_8007D41C(Unk8061930C* g, int v, int w);
int fn_8013BBF0(int v);
void fn_8037B424(void* p, int in_chrg);
void* fn_801418B4(void* p);
void fn_80142254(void* p);
void fn_800ED254(void* p);
int fn_80143114(void* x);
void fn_800ECF18(void* p);
int fn_8040B830(int a, const char* s, int n);
void fn_800C8070(void* p);
void fn_802D7EE4();
}
/* Object returned by fn_8058F11C (vptr at +0xC; the data after it starts at +0x10). */
struct Unk8058F11C_Data {
    char pad0[0xC];
};
struct Unk8058F11C : Unk8058F11C_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual int fn_vslot3(int a);
    virtual int fn_vslot4();
};
extern int lbl_8061977C;
extern "C" Unk8058F11C* fn_8058F11C(int a, int b);
extern "C" void* fn_80090880(int a, int b);
Unk8001BC8C* fn_8001BC4C();
struct Unk800B7A94_Ret {
    char pad0[0x24];
    int m24;
};
extern int lbl_8061A328;
extern int lbl_8061A32C;
extern int lbl_80687CDC;
extern const char lbl_805BA230[];
extern const float lbl_805C2C54;
extern "C" {
int fn_80143128();
int fn_800B64BC(void* p);
Unk800B7A94_Ret* fn_800B7A94(int a, const char* s);
void* fn_8005ACE4();
void fn_8005B9D4(void* p, int v);
}
struct Unk80687CC8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
extern Unk80687CC8 lbl_80687CC8;
extern int lbl_8061B86C;
extern const char lbl_8065C4E0[];
extern const char lbl_80649DB8[];
extern const char lbl_8064C820[];
extern const char lbl_8064C848[];
struct Unk801418B4_Sub {      /* second base at +0x134: ctor fn_803785E4, vptr at +8 */
    int m0;
    int m4;
    const void* m8;
};
struct Unk801418B4 : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    Unk801418B4_Sub m134;
    const void* m140;
    char pad144[0x10];
    int m154;
    int m158;
};
extern "C" {
void fn_80143190(Unk801418B4* x, int v);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_803785E4(void* p);
void fn_80378A34(void* p, void* q);
int fn_8005B864(void* p);
int fn_8005B9B0(void* p, int v);
}
extern int lbl_80687CCC;

struct UnkP0 {
    const void* m0;
};

extern const unsigned char lbl_805C2004[];
extern "C" int fn_8014013C(int i) { return lbl_805C2004[i]; }

extern const int lbl_805C2074[];
extern "C" int fn_8014014C(int i) { return lbl_805C2074[i]; }

extern const unsigned char lbl_805C203C[];
extern "C" int fn_80140160(int i) { return lbl_805C203C[i]; }

extern const short lbl_805C2154[];
extern "C" int fn_80140170(int i) { return lbl_805C2154[i]; }

extern "C" int fn_80140184(int i)
{
    if (i == 0x37) {
        Unk8058F1F0* o = fn_8058F1F0(lbl_8061930C->m34, 1);
        return fn_805901AC(o, o->fn_vslot9());
    }
    return lbl_805C1B54[i];
}

extern const int lbl_8061B6AC[];
extern "C" int fn_80140200(int i) { return lbl_8061B6AC[i]; }

extern const int lbl_8061B5CC[];
extern "C" int fn_80140214(int i) { return lbl_8061B5CC[i]; }

extern const int lbl_8061B78C[];
extern "C" int fn_80140228(int i) { return lbl_8061B78C[i]; }

extern const int lbl_805C1F24[];
extern "C" int fn_8014023C(int i) { return lbl_805C1F24[i]; }

extern "C" int fn_80140250(void* self, int a)
{
    Unk8061930C* g = lbl_8061930C;
    int s = fn_8007DA28(g);
    int idx = fn_8013BBF0(a);
    if (idx != -1 && (s == -1 || fn_8007D41C(g, s, idx) == 0)) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_80140718()
{
    Unk8058F11C* o = fn_8058F11C(lbl_8061930C->m34, 0);
    int v = o->fn_vslot4();
    if (v == 0) {
        return (char*)o + 0x10;
    }
    return fn_80090880(lbl_8061977C, o->fn_vslot3(v));
}

extern const int lbl_805C3C00[];
extern "C" int fn_80141710(int i) { return lbl_805C3C00[i]; }

struct Unk8014188C {
    char pad0[0x1D4];
    int m1D4;
    int m1D8;
};
extern "C" int fn_8014188C(Unk8014188C* x, int a)
{
    if (a == x->m1D4 || a == x->m1D8) {
        return 1;
    }
    return 0;
}

extern const char lbl_8064B738[];
extern "C" void fn_801421D4(UnkP0* x, int chrg)
{
    x->m0 = lbl_8064B738;
    fn_8037B424(x, chrg);
}

extern "C" void* fn_80142204()
{
    return fn_801418B4(operator new(0xFC, lbl_806EF9B4));
}

extern "C" void fn_80142234(void* x)
{
    fn_80142254(x);
}

extern int lbl_8061B870;
extern "C" int fn_80142410() { return lbl_8061B870; }

/* near-miss: 73/74 insns; retail keeps the zero in r29 and &m134 in r30 (swapped here), and takes
 * &lbl_80687CC8 into a callee-saved register before the fn_8005B9B0 call. Tried local pointers. */
extern "C" Unk801418B4* fn_8014241C(Unk801418B4* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065C4E0);
    fn_803785E4(&self->m134);
    self->m134.m8 = lbl_80649DB8;
    self->m140 = lbl_8064C820;
    self->SetVptr(lbl_8064C848);
    lbl_8061B870 = (int)self;
    self->m158 = 0;
    fn_80378A34(&self->m134, fn_8005ACE4());
    if (lbl_8061B86C != 0) {
        int r = fn_8005B864(fn_8005ACE4());
        if (r != 0) {
            int t = 0;
            if (fn_8005B9B0(fn_8005ACE4(), r - 1) != 0) {
                t = 1;
            }
            lbl_80687CC8.m4 = t;
        } else {
            lbl_80687CCC = r;
        }
        fn_80143190(self, r);
        self->m154 = 0;
        lbl_80687CC8.m18 = 1;
        lbl_8061B86C = 0;
        lbl_80687CC8.m14 = -1;
        lbl_80687CC8.m8 = 1;
        lbl_80687CC8.m10 = -1;
    }
    return self;
}

extern "C" void fn_801427C8(Unk800C7B40_Widget* x)
{
    fn_800ECF18(x);
    if (fn_80143114(x) == 0) {
        x->fn_vslot8(0);
    }
}

extern "C" void fn_80142F08(Unk800C7B40_Widget* x)
{
    x->fn_vslot39();
    fn_800ED254(x);
}

struct Unk80142F50_Slot {
    char pad0[0x110];
    short m110;
    short m112;
};
struct Unk80142F50_Mgr {
    int m0;
    struct Unk80142F50_Inner {
        char pad0[0x10];
        Unk80142F50_Slot* m10;
    }* m4;
};
struct Unk80142F50 : Unk800C7B40_Widget {
    char pad40[0x100];
    Unk800C7B40_Data* m140;
    char pad144[8];
    int m14C;
    int m150;
    int pad154;
    int m158;
};
extern Unk80142F50_Mgr* lbl_806192E0;
extern "C" void fn_80142F50(Unk80142F50* x)
{
    Unk80142F50_Slot* s = lbl_806192E0->m4->m10;
    int a = x->m140->m26;
    s->m110 = a;
    int b = x->m140->m28;
    s->m112 = b;
    x->m158 = 0;
    x->m14C = 0;
    x->m150 = 0;
}

extern "C" int fn_80142F8C()
{
    if (fn_80143128() != 0 && lbl_8061A328 >= lbl_80687CDC - 0x12C) {
        if (lbl_8061A32C == 0) {
            lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
        }
        Unk800B7A94_Ret* t = fn_800B7A94(lbl_8061A32C, lbl_805BA230);
        if (t == 0 || t->m24 >= 0) {
            if (!(fn_8001BC4C()->fn_8001C048(3) <= lbl_805C2C54)) {
                fn_8001BC4C()->fn_8001BDAC(0x9D);
            }
            fn_8005B9D4(fn_8005ACE4(), 0);
        }
    }
    return 0;
}

extern "C" int fn_8014305C(void* x)
{
    if (fn_80143114(x) != 0) {
        fn_800C8070(x);
        fn_802D7EE4();
        return 0;
    }
    return 0;
}

extern const char lbl_805B6F58[];
extern "C" int fn_801430A4(void* self, int a)
{
    return fn_8040B830(a, lbl_805B6F58, 16);
}

extern int lbl_80687CD0;
extern "C" void fn_801430D4(Unk800C7B40_Widget* x)
{
    x->fn_vslot39();
    lbl_80687CD0 = 1;
}

extern int lbl_80687CD0;
extern "C" int fn_80143114(void* x) { return lbl_80687CD0 == 0; }

extern int lbl_80687CE0;
extern "C" int fn_80143128() { return lbl_80687CE0; }

struct Unk80143134_Msg {
    int m0;
    int m4;
    int m8;
};
extern int lbl_80687CCC;
static inline Unk80143134_Msg* Cast(int id, Unk80143134_Msg* m)
{
    if (m != 0) {
        if (m->m0 == id) {
            return m;
        }
        return 0;
    }
    return 0;
}
/* near-miss: 23/23 insns, 7 differ: retail compares the message id in r4 against m->m0 (cmpw r4,r0); here the known id 0xA3 is folded into cmpwi r0,163 */
extern "C" void fn_80143134(Unk801418B4* self, int msg, Unk80143134_Msg* m)
{
    if (msg == 0xA3) {
        Unk80143134_Msg* mm = Cast(msg, m);
        lbl_80687CCC = 1;
        fn_80143190(self, mm->m8);
    }
}

extern "C" void fn_80143190(Unk801418B4* x, int v)
{
    lbl_80687CC8.m0 = v;
    x->m154 = 1;
}

extern "C" void fn_801431A4() {}
