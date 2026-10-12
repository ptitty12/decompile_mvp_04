/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80382BB8-0x80383E00 (code-only unit, 42 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "game/chooser.h"
#include "game/tu_80317B88.h"
#include "game/tu_80377048.h"

struct Unk80382BB8 {
    char pad0[0x14];
    float m14;
    char pad18[0x1A8 - 0x18];
    int m1A8;
    char pad1AC[8];
    int m1B4;
    char pad1B8[0x830 - 0x1B8];
    int m830;
    char pad834[0x854 - 0x834];
    int m854;
    char pad858[0x861 - 0x858];
    signed char m861;
    char pad862[0x888 - 0x862];
    float m888;
    int m88C;
};

struct Unk80383394 {
    int m0;
    int m4;
    int m8;
};

struct Unk803833B4 {
    int key;
    int v[2];
};

struct Unk80383C78 {
    char padC[0xC];
    float mC;
    float m10;
    int m14;
    int m18;
};

struct Unk80383DC0 {
    char pad0[0x1C];
    unsigned m1C;
};

extern "C" {
int fn_80385120(Unk80384F28* c, int a, int b);
int fn_803852E4(Unk80384F28* c);
}

extern const char lbl_80605A30[];
extern const char lbl_80605A3C[];
extern const char lbl_80605A50[];
extern const char lbl_80605BB0[];
extern const char lbl_80605BB8[];
extern const char lbl_80605BBC[];
extern const char lbl_80605BCC[];
extern const char lbl_80605BD0[];
extern const char lbl_80605BDC[];
extern const char lbl_80605BE8[];
extern const char lbl_80605BF0[];
extern const char lbl_80605C00[];
extern const char lbl_80605C0C[];
extern const char lbl_80605C14[];
extern const char lbl_80605C24[];
extern const char lbl_80605C30[];
extern const char lbl_80605C44[];
extern const char lbl_80605C50[];
extern const char lbl_80605C5C[];
extern const char lbl_80605C6C[];
extern const char lbl_80605C7C[];
extern unsigned lbl_80695960;
extern unsigned lbl_80695964;
extern unsigned lbl_80695968;
extern unsigned lbl_8069595C;
extern unsigned lbl_806242B0;
extern unsigned lbl_806242B4;
extern unsigned lbl_806242B8;


class Unk80383548 : public Unk8037B3E8 {
public:
    Unk80383548();
    virtual void fn_vslot2();
    Unk80384F28 m4;
    int m14;
    int m18;
    int m1C;
    int m20;
};

class Unk803837F8 : public Unk8037B3E8 {
public:
    Unk803837F8();
    virtual void fn_vslot2();
    Unk80384F28 m4;
    Unk80384F28 m14;
    int m24;
    int m28;
    VCls* m2C;
    int m30;
};

class Unk80383B24 : public Unk8037B3E8 {
public:
    Unk80383B24();
    virtual void fn_vslot2();
    int m4;
    int m8;
    float mC;
    float m10;
    int m14;
    int m18;
};

class Unk80383C9C : public Unk8037B3E8 {
public:
    Unk80383C9C();
    virtual void fn_vslot2();
    Unk80384F28 m4;
    int m14;
    int m18;
    unsigned m1C;
};

extern "C" {
void fn_803836DC(Unk80383548* p);
void fn_80383928(Unk803837F8* p);
}

extern "C" float fn_80382BB8(Unk80382BB8* o)
{
    return o->m888;
}

extern "C" void fn_80382BC0(Unk80382BB8* o, float f)
{
    o->m888 = f;
}

extern "C" int fn_80382C8C(Unk80382BB8* o)
{
    return o->m1A8;
}

extern "C" int fn_80382C94(Unk80382BB8* o)
{
    int n = o->m1A8;
    int* e = (int*)((char*)o + 0x1AC);
    for (int i = 0; i < n; i++) {
        if (e[2] != 0)
            return 1;
    }
    return 0;
}

extern "C" void fn_80382CD0(Unk80382BB8* o, int v)
{
    int b = o->m861;
    if (v == b) {
        o->m88C = 0;
    } else if (v == (b + 2) % 3) {
        o->m88C = 2;
    } else if (v == (b + 1) % 3) {
        o->m88C = 1;
    } else {
        o->m88C = -1;
    }
}

extern "C" void fn_80382D60(Unk80382BB8* o, int v)
{
    if (v != 0)
        o->m830 = v;
}

extern "C" int fn_80382D70(Unk8037B3E8* s, Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int a, int b)
{
    return s->fn_vslot17(out, obj, 0, a, b, 0);
}

int fn_80383334(unsigned int hash)
{
    const char* name = lbl_80605A3C;
    int r = fn_8037C7FC()->fn_8037CDE0(name, hash);
    if (r == 0) {
        name = lbl_80605A50;
        r = fn_8037C7FC()->fn_8037CDE0(name, hash);
    }
    return r;
}

/* near-miss: retail copies the pointer to r11 (end pointer kept as an int, cmpw); 7 vs 8 insns */
extern "C" void fn_80383394(Unk80383394* buf)
{
    Unk80383394* last = buf;
    for (Unk80383394* p = buf; p <= last; p++)
        p->m0 = 0;
}

extern "C" int fn_803833B4(Unk803833B4* t, int key, int idx)
{
    int off = 0;
    for (int i = 0; i <= 0; i++) {
        if (*(int*)(off + (int)t) == key) {
            int o = idx * 4;
            char* b = (char*)t + 4;
            return *(int*)(b + (o + off));
        }
        off += 12;
    }
    return 0;
}

extern "C" int fn_803833F4(Unk803833B4* t, int key, int n, int* vals)
{
    int f = -1;
    int i = 0;
    Unk803833B4* p = t;
    do {
        int k = p->key;
        p++;
        if (k == key)
            f = i;
        i++;
    } while (i <= 0 && f < 0);
    i = 0;
    if (f < 0) {
        p = t;
        do {
            int k = p->key;
            p++;
            if (k == 0)
                f = i;
            i++;
        } while (i <= 0 && f < 0);
        if (f < 0)
            f = 0;
    }
    for (int j = 0; j < n; j++) {
        char* b4 = (char*)t + 4;
        *(int*)(b4 + (f * 12 + j * 4)) = vals[j];
    }
    char* b8 = (char*)t + 8;
    *(int*)(b8 + f * 12) = n;
    *(int*)((char*)t + f * 12) = key;
    return 1;
}

extern "C" void fn_803834AC(Unk803833B4* t, int key)
{
    for (int i = 0; i < 1; i++) {
        if (t[i].key == key)
            t[i].key = 0;
    }
}

/* 80383548 */
Unk80383548::Unk80383548() : Unk8037B3E8(lbl_8069595C)
{
    lbl_806242B0 = fn_80378568(lbl_80605BB0, 0);
    lbl_806242B4 = fn_80378568(lbl_80605BB8, 0);
    lbl_806242B8 = fn_80378568(lbl_80605BBC, 0);
    m14 = 0;
    m1C = 0;
    m20 = 0;
}

/* 803835EC */
void Unk80383548::fn_vslot2()
{
    fn_8037B5FC(lbl_80605BCC, &m14);
    fn_8037B728(lbl_80605BD0, lbl_80605BDC, &m4, 0);
}

extern int lbl_806EF9B4;

extern "C" void* fn_80383644()
{
    return new (lbl_806EF9B4) Unk80383548;
}

extern "C" int fn_80383674(Unk80383548* o)
{
    return fn_8037C7FC()->fn_8037CE98(lbl_8069595C, (int)o, 0);
}

extern "C" void fn_803836B4(Unk80383548* o, int a)
{
    fn_80385120(&o->m4, a, 0);
}

extern "C" void fn_803836DC(Unk80383548* o)
{
    int f = o->m1C;
    if (f == 0) {
        o->m1C = 1;
        Unk80384F28* c = &o->m4;
        c->fn_80385344(lbl_80605A30);
        int n = fn_803852E4(c);
        o->m20 = f;
        int i = n - 1;
        if (n != 0) {
            do {
                int v = c->fn_803852FC(i)[5] > 0;
                o->m20 = v;
                if (v)
                    break;
            } while (i-- != 0);
        }
    }
}

extern "C" int fn_8038377C(Unk80383548* o)
{
    fn_803836DC(o);
    return o->m20;
}

extern "C" void fn_803837AC(Unk80383548* o, int a)
{
    fn_803836DC(o);
    o->m4.fn_803851A0(a, 0);
}

extern "C" void fn_803837EC(char* o)
{
    *(int*)(o + 0x1C) = 0;
}

/* 803837F8 */
Unk803837F8::Unk803837F8() : Unk8037B3E8(lbl_80695960)
{
    m24 = 0;
    m28 = 0;
    m2C = 0;
}

/* 8038385C */
void Unk803837F8::fn_vslot2()
{
    fn_8037B728(lbl_80605BD0, lbl_80605BDC, &m4, 0);
    fn_8037B728(lbl_80605BE8, lbl_80605BE8, &m14, 0);
    fn_8037B5FC(lbl_80605BF0, &m30);
}

extern "C" void* fn_803838D0()
{
    return new (lbl_806EF9B4) Unk803837F8;
}

extern "C" void fn_80383900(Unk803837F8* o, int a)
{
    fn_80385120(&o->m4, a, 0);
}

extern "C" void fn_80383928(Unk803837F8* o)
{
    int f = o->m24;
    if (f == 0) {
        o->m24 = 1;
        Unk80384F28* c = &o->m4;
        c->fn_80385344(lbl_80605A30);
        int n = fn_803852E4(c);
        o->m28 = f;
        int i = n - 1;
        if (n != 0) {
            do {
                int v = c->fn_803852FC(i)[5] > 0;
                o->m28 = v;
                if (v)
                    break;
            } while (i-- != 0);
        }
    }
}

extern "C" int fn_803839C8(Unk803837F8* o)
{
    fn_80383928(o);
    return o->m28;
}

extern "C" void fn_803839F8(Unk803837F8* o, int a)
{
    fn_80383928(o);
    o->m4.fn_803851A0(a, 0);
}

extern "C" void fn_80383A38(char* o)
{
    *(int*)(o + 0x24) = 0;
}

extern "C" int fn_80383A44(Unk803837F8* o, int a, int b)
{
    if (o->m2C == 0)
        o->m2C = (VCls*)fn_8037C7FC()->fn_8037D028(o->m30);
    ResBig r;
    o->m2C->s11(&r, b, 0, 0);
    int v;
    if (r.type == 1)
        v = ((VCls2*)r.id)->s11()->m38;
    else
        v = fn_80385120(&o->m14, a, 0);
    return v;
}

/* 80383B24 */
Unk80383B24::Unk80383B24() : Unk8037B3E8(lbl_80695964)
{
    m10 = 0.0f;
    mC = 0.0f;
    m18 = 0;
    m14 = 0;
    m8 = 0;
    m4 = 0;
}

/* 80383B8C */
void Unk80383B24::fn_vslot2()
{
    fn_8037B5FC(lbl_80605C00, &m4);
    fn_8037B5FC(lbl_80605C0C, &m8);
    fn_8037B50C(lbl_80605C14, &mC, 0, 0);
    fn_8037B50C(lbl_80605C24, &m10, 0, 0);
    fn_8037B494(lbl_80605C30, &m18, 0, 0);
    fn_8037B494(lbl_80605C44, &m14, 0, 0);
}

extern "C" void* fn_80383C48()
{
    return new (lbl_806EF9B4) Unk80383B24;
}

extern "C" void fn_80383C78(Unk80383C78* o, float* a, float* b, int* c, int* d)
{
    *a = o->mC;
    *b = o->m10;
    *c = o->m14;
    *d = o->m18;
}

/* 80383D04 */
void Unk80383C9C::fn_vslot2()
{
    fn_8037B5FC(lbl_80605C50, &m14);
    fn_8037B5FC(lbl_80605C5C, &m18);
    fn_8037B728(lbl_80605C6C, lbl_80605C7C, &m4, 0);
}

struct Unk80383D70 {
    const void* m0;
    Unk80384F28 m4;
};

extern char lbl_80684C50[];

struct DtorAt0 {
    const void* m;
};
void fn_80362EAC(DtorAt0* s, int chrg);

extern "C" void fn_80383D70(Unk80383D70* s, int chrg)
{
    s->m0 = lbl_80684C50;
    s->m4.Unk80384F28::~Unk80384F28();
    fn_80362EAC((DtorAt0*)s, chrg);
}

extern "C" void fn_80383DC0(Unk80383DC0* o)
{
    o->m1C = o->m1C & 0xFFFDFFFF;
}

extern "C" void* fn_80383DD0() { return new (lbl_806EF9B4) Unk80383C9C; }
