/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x8037E64C-0x80382BB8 (code-only unit, 47 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "game/chooser.h"
#include "game/tu_80377048.h"



struct VOut {
    virtual ~VOut();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11(int a, int b);
};








struct ThisV11 {
    virtual ~ThisV11();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11();
};

struct VMc {
    char pad0[8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* a, int b, int c, int d);
    virtual void v5();
    virtual void v6(int a);
    virtual void v7(int a);
    virtual void v8();
};

struct KnotBuf2 {
    char pad[12];
};

class Unk8037E73C : public Unk8037B3E8 {
public:
    Unk8037E73C();
    int m4;
    int m8;
    int mC;
    KnotBuf2 m10;
};

class Unk80362DD4 {
public:
    Unk80362DD4();
    char pad0[0x88];
};
class Unk80362D00 {
public:
    Unk80362D00();
    int m0;
    char pad4[0x344 - 4];
};
struct Q5 {
    float a;
    float b;
    float c;
    float d;
    float e;
    void Clear()
    {
        a = 0.0f;
        b = 0.0f;
        c = 0.0f;
        d = 0.0f;
        e = 0.0f;
    }
};

struct Unk80362E30;
void fn_80362E30(Unk80362E30* p);
class Unk803785E4 {
public:
    Unk803785E4();
    char pad0[8];
    virtual void vf();
};
class Unk8037E928 : public Unk803785E4 {
public:
    Unk8037E928(VMc* mc, char b, int x, int y);
    VMc* mC;
    Unk80362DD4 slots[3];
    Unk80362D00 m1A8;
    Unk80362D00 m4EC;
    char pad830[0x854 - 0x830];
    int m854;
    int m858;
    char pad85C[0x862 - 0x85C];
    char m862;
    char pad863[5];
    char m868[0x18];
    int m880;
    int m884;
};
struct Unk8037E9D0 {
    char pad0[8];
    const void* m8;
    VMc* mC;
    Unk80362DD4 slots[3];
    Unk80362D00 m1A8;
    Unk80362D00 m4EC;
    char pad830[4];
    int m834;
    int m838;
    int m83C;
    int m840;
    int m844;
    int m848;
    int m84C;
    int m850;
    int m854;
    int m858;
    int m85C;
    char m860;
    char m861;
    char m862;
    char pad863;
    int m864;
    Q5 q868;
    float m87C;
    int m880;
    int m884;
    float m888;
    int m88C;
};

extern "C" {
void fn_8037E078(KnotBuf2* p);
void fn_8037E0C0(KnotBuf2* p, int chrg);
void fn_8037893C(int a, int b, void* c, int d, int e);
void fn_8037E9D0(Unk8037E9D0* o);
void fn_8037EA7C(Unk8037E9D0* o, int v);
void fn_80380920(char* o);
}
void fn_8037B424(void* p, int c);
extern unsigned lbl_8069593C;
extern char lbl_80685020[];
extern int lbl_806242AC;
extern char lbl_80684F48[];


struct Unk8037E64C {
    char pad0[4];
    int m4;
    char* m8;
};

struct Unk8037E6F4 {
    float m0;
    char m4;
    int m8;
};

struct Unk8037E714 {
    int m0;
    int m4;
    int m8;
};

struct Unk8037ECA4 {
    char pad0[0x2C];
    int m2C;
    int m30;
    int m34;
    char pad38[0x84 - 0x38];
    int m84;
};

struct Unk8037FCE4_Inner {
    char pad0[8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
};

struct Unk8037FCE4 {
    char padC[0xC];
    Unk8037FCE4_Inner* mC;
};

struct U {
    char pad0[0x4000];
};

extern "C" {
int fn_80384A48(void* p);
int fn_80384B70(int o, int a, int* b, int c);
int fn_803809BC(char* o, int a, char* slot, int b, int c, int d);
}

struct Ent68 {
    int m0;
    int m4;
    char pad8[8];
    float m10;
    float m14;
    char pad18[0x68 - 0x18];
};
extern "C" {
void fn_80381A5C(Unk8037E9D0* o);
int fn_803818BC(int a, int b, int c, float f1, float f2);
int fn_80380BB0(char* o, int a);
VOut* fn_80381E08(Unk8037E9D0* o, int a, int b);
}

struct Unk80383C9C_W;
struct VSO {
    virtual ~VSO();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual VSO* s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual Unk80383C9C_W* s18();
};
struct VM884 {
    virtual ~VM884();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual int s8();
    virtual int s9();
};
extern "C" int fn_80383FB0(Unk80383C9C_W* o, int a);

extern "C" {
int fn_803814A4(Unk8037E9D0* o, int a, int b, float f);
int fn_80381BCC(Unk8037E9D0* o, int h);
int fn_80383674(int o);
}

extern "C" int fn_8037E64C(Unk8037E64C* o, int key)
{
    for (int i = 0; i < o->m4; i++) {
        if (*(int*)(o->m8 + i * 16) == key)
            return i;
    }
    return -1;
}

extern "C" void fn_8037E68C(Unk8037E73C* o, int a, int b, float f1, float f2)
{
    fn_8037893C(a, ((ThisV11*)o)->s11(), o, 1, b);
}

extern "C" void fn_8037E6F4(Unk8037E6F4* o)
{
    o->m0 = 60.0f;
    o->m4 = 0;
    o->m8 = 0;
}

extern "C" void fn_8037E714(Unk8037E714* dst, const Unk8037E714* src)
{
    if (src != 0)
        *dst = *src;
}

extern "C" void fn_8037E738() {}

/* 8037E73C */
Unk8037E73C::Unk8037E73C() : Unk8037B3E8(lbl_8069593C)
{
    fn_8037E078(&m10);
}

extern "C" void fn_8037E844(Unk8037E73C* o, int chrg)
{
    *(const void**)o = lbl_80685020;
    fn_8037E0C0(&o->m10, 2);
    fn_8037B424(o, chrg);
}

extern "C" void* fn_8037E894()
{
    return new (lbl_806EF9B4) Unk8037E73C;
}

extern "C" void fn_8037E8C4(void* o)
{
    fn_8037C7FC()->fn_8037CE98(lbl_8069593C, (int)o, 0);
}

extern "C" void fn_8037E904(char* self)
{
    fn_8037E6F4((Unk8037E6F4*)(self + 4));
}

/* 8037E928 */
Unk8037E928::Unk8037E928(VMc* mc, char b, int x, int y) : mC(mc)
{
    m862 = b;
    fn_80362E30((Unk80362E30*)m868);
    m880 = x;
    m884 = y;
    m854 = 0;
    m858 = 0;
    fn_8037E9D0((Unk8037E9D0*)this);
}

extern "C" void fn_8037E9D0(Unk8037E9D0* o)
{
    o->m834 = 0;
    o->m838 = 0;
    o->m83C = 0;
    o->m840 = 0;
    o->m844 = 0;
    o->m848 = 0;
    o->m850 = 0;
    o->m84C = 0;
    fn_8037EA7C(o, 0);
    o->m861 = 0;
    o->m864 = -1;
    o->q868.Clear();
    o->m87C = 0.0f;
    o->m860 = -1;
    fn_80380920((char*)o);
    o->m888 = 0.0f;
    o->m88C = -1;
    o->m1A8.m0 = 0;
    o->m4EC.m0 = 0;
    o->m85C = 0;
}

extern "C" void fn_8037EA7C(Unk8037E9D0* o, int v)
{
    if (v != 0 && o->m854 == 0) {
        if (o->m862 == 0)
            o->mC->v8();
    } else if (o->m862 == 0 && v == 0) {
        o->mC->v6(0);
        o->mC->v7(0);
    }
    o->m854 = v;
}

extern "C" void fn_8037EBE8(Unk8037E9D0* o)
{
    o->mC->v6(0);
    o->mC->v7(0);
    lbl_806242AC = 1;
    o->mC->v6(8);
    o->mC->v7(8);
    lbl_806242AC = 0;
}

extern "C" void fn_8037ECA4(Unk8037ECA4* o, int v)
{
    o->m84 = v;
    if (v == 0) {
        o->m2C = v;
        o->m34 = v;
        o->m30 = v;
    }
}

extern "C" int fn_8037FCE4(Unk8037FCE4* o)
{
    return o->mC->v7();
}

extern "C" void fn_8037FD1C(Unk8037E9D0* o)
{
    if (o->m862 == 0)
        o->mC->v6(8);
    if (o->m862 == 0 || (((VM884*)o->m884)->s8() != 0 && ((VM884*)o->m884)->s9() != 0 && o->m862 == 1))
        o->mC->v4((char*)&o->m4EC + 4, o->m4EC.m0, 10, o->m862);
}

extern "C" void fn_80380920(char* o)
{
    char* p = o + 0x10;
    for (int i = 3; i != 0; i--) {
        fn_8037ECA4((Unk8037ECA4*)p, 0);
        p += 0x88;
    }
}

/* near-miss: retail keeps the byte offset in r11 and forms o + 0x10 only when the slot is used (addi r9,r3,16; lwzx r10,r9,r11); 21 vs 22 insns */
extern "C" int fn_80380964(char* o)
{
    int r = 0;
    int off = (((signed char)o[0x861] + 2) % 3) * 0x88;
    if (*(int*)(o + off + 0x94) != 0) {
        char* b = o + 0x10;
        r = *(int*)(b + off);
    }
    return r;
}

extern "C" int fn_80380BB0(char* o, int a)
{
    return fn_803809BC(o, a, o + 0x10 + (((signed char)o[0x861] + 1) % 3) * 0x88, *(int*)(o + 0x884), 0, 0);
}

extern "C" void fn_80381A5C(Unk8037E9D0* o)
{
    char* base = (char*)o + 0x1C;
    VSO* c = *(VSO**)(base + o->m861 * 0x88);
    Unk80383C9C_W* t = c->s12()->s18();
    VSO** pp = (VSO**)(base + ((o->m861 + 1) % 3) * 0x88);
    VSO* n = *pp;
    o->m848 = fn_80383FB0(t, (int)n->s12());
    if (o->m848 == 0)
        o->m848 = o->m844;
}

extern "C" void fn_80381B38(Unk8037E9D0* o)
{
    o->m844 = (int)fn_80381E08(o, o->m834, o->m838);
    if (fn_80380BB0((char*)o, o->m838) != 0) {
        fn_80381A5C(o);
        if (o->m860 != -1) {
            Ent68* e = (Ent68*)((char*)o + 0x1AC) + o->m860;
            o->m84C = fn_803818BC(o->m848, e->m4, e->m0, e->m14, e->m10);
        }
        o->m850 = 1;
    }
}

extern "C" VOut* fn_80381E08(Unk8037E9D0* o, int a, int b)
{
    if (a == 0)
        a = fn_80384A48((void*)b);
    VOut* out;
    if (fn_80384B70(a, b, (int*)&out, 1) != 0 && out != 0) {
        if (out->s11(o->m83C, o->m884) == b)
            return out;
    }
    return 0;
}

extern "C" int fn_80381E9C(Unk8037E9D0* o, int a, int b, int c)
{
    if (a != 0) {
        if (o->m838 == 0 || (o->m860 == -1 && o->m840 == 0))
            return fn_803814A4(o, a, 0, 0.0f);
        int old = o->m83C;
        if (old != a) {
            int p = o->m840;
            if (p == 0 || p == a) {
                o->m83C = a;
                int h = c ? fn_80383674(c) : 0;
                if (fn_80381BCC(o, h) == 0) {
                    o->m83C = old;
                    return 0;
                }
                if (b != 0)
                    o->m840 = a;
                else
                    o->m840 = b;
            } else
                return 0;
        }
    } else
        fn_8037E9D0(o);
    return 1;
}

extern "C" void fn_80382B94(U* self, void* p)
{
    fn_80384A48(p);
}
