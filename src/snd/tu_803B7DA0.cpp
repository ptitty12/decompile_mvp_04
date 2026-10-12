/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803B7DA0-0x803B998C (code-only unit, 29 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

struct SndPair {
    float a;
    float b;
};

struct SndT3 {
    int a;
    int b;
    int c;
};

/* 0xA8-byte sample-stream object (fn_803B826C initialises it). */
struct SndStream {
    int pad0;
    int m4;
    int m8;
    int mC;
    char pad10[0x88];
    float m98;
    float m9C;
    void* mA0;
};

/* 0xD68-byte decoder object (fn_803B9448 initialises it). */
struct SndDec {
    int pad0;
    int m4;
    char pad8[0xD3C];
    int mD44;
    char padD48[8];
    short mD50;
    short mD52;
    int mD54;
    int mD58;
    int mD5C;
    int mD60;
    int mD64;
};

extern void* (*lbl_806AA884)();
extern void (*lbl_806AA888)();

extern "C" void* fn_803B8214()
{
    return lbl_806AA884();
}

extern "C" void fn_803B8240()
{
    lbl_806AA888();
}

extern "C" SndStream* fn_803B826C(SndStream* o)
{
    o->mC = 0;
    o->m8 = 0;
    o->m4 = 0;
    o->m98 = 0.0f;
    o->m9C = 0.0f;
    return o;
}

extern "C" int fn_803B8294(SndStream* o, void* data, int bytes, int cnt)
{
    if (data == 0)
        return -1;
    if (o->m8 != 0)
        return -1;
    o->m8 = cnt;
    o->mC = bytes;
    o->mA0 = data;
    return 0;
}

extern "C" SndPair fn_803B8488(SndStream* o)
{
    SndPair t;
    t.a = o->m98;
    t.b = o->m9C;
    return t;
}

extern "C" void fn_803B84B8(SndStream* o, SndPair* p)
{
    o->m98 = p->a;
    o->m9C = p->b;
}

extern "C" void* fn_803B84CC()
{
    return lbl_806AA884();
}

extern "C" void fn_803B84F8()
{
    lbl_806AA888();
}

extern "C" SndDec* fn_803B9448(SndDec* d)
{
    d->mD44 = 0;
    d->mD54 = 0;
    d->mD64 = 1;
    d->mD58 = 0;
    d->mD50 = 0;
    d->mD52 = 0;
    d->mD5C = 0;
    d->mD60 = 0;
    return d;
}

extern "C" SndT3 fn_803B9730(SndDec* d)
{
    SndT3 t;
    t.a = d->m4;
    t.c = d->mD5C;
    t.b = d->mD44;
    return t;
}

extern "C" void fn_803B9770(SndDec* d, SndT3* t, int unused)
{
    d->m4 = t->a;
    d->mD5C = t->c;
    d->mD44 = t->b;
}

extern "C" void fn_803B978C(SndDec* d, int v)
{
    d->mD64 = v;
}
