/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80387E28-0x8038B938 (code-only unit, 38 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "game/chooser.h"

struct DtorAt0 { const void* m; };

/* Slot pools of a gamelib object: two arrays of 15 slots (0x14 bytes each), at +0x1C and
 * +0x148; bit 3 of the flags argument selects the second. Evidence: fn_80387E28 zeroes m0 of
 * 15 slots from +0x1C or +0x148; fn_80387EEC claims the first slot with m4 == 0. */
struct GlSlot { int m0; int m4; int m8; int mC; int m10; };

struct GlCb {
    virtual void v1(int, int, int);
    virtual void v2(int, int, int);
    virtual void v3(int, int, int);
};

struct GlPool {
    char pad0[0x10];
    int m10;
    char pad14[0x1C - 0x14];
    GlSlot a1C[15];
    GlSlot a148[15];
    char pad274[0x288 - 0x274];
    char m288;
    char m289;
};

extern GlCb* lbl_80624278;

extern "C" void fn_80387E28(GlPool* self, int flags)
{
    GlSlot* b = (flags & 8) ? self->a148 : self->a1C;
    for (int i = 0; i < 15; i++)
        b[i].m0 = 0;
}

extern "C" void fn_80387E58(GlPool* self, int flags)
{
    GlSlot* b = (flags & 8) ? self->a148 : self->a1C;
    for (int i = 0; i < 15; i++) {
        GlSlot* s = &b[i];
        if (s->m0 == 0 && s->m4 != 0) {
            lbl_80624278->v3(s->m4, s->m8, s->mC);
            s->m4 = 0;
            s->m8 = 0;
            s->mC = 0;
        }
    }
}

extern "C" int fn_80387EEC(GlPool* self, int flags)
{
    GlSlot* b = (flags & 8) ? self->a148 : self->a1C;
    int i;
    for (i = 0; i < 15; i++) {
        GlSlot* s = &b[i];
        if (s->m4 == 0) {
            s->m0 = 1;
            return i;
        }
    }
    for (i = 0; i < 15; i++) {
        GlSlot* s = &b[i];
        if (s->m0 == 0) {
            lbl_80624278->v3(s->m4, s->m8, s->mC);
            s->m0 = 1;
            s->m4 = 0;
            s->m8 = 0;
            s->mC = 0;
            return i;
        }
    }
    return -1;
}

extern "C" int fn_80387FC8(GlPool* self, int flags, int id, float f)
{
    GlSlot* b = (flags & 8) ? self->a148 : self->a1C;
    for (int i = 0; i < 15; i++) {
        GlSlot* s = &b[i];
        if (id == s->m4) {
            s->m0 = 1;
            return i;
        }
    }
    return -1;
}

extern "C" void fn_80388020(GlPool* self, int flags)
{
    if (flags & 8)
        self->m10 = 0;
    else
        self->m10 = 1;
    fn_80387E28(self, flags);
    self->m288 = 0;
}

extern "C" void fn_803BB7A8(int a, int b, int c, int d, void* e, float f);
extern char lbl_80699B14[];

extern float lbl_80605DB4;
extern float lbl_80605DB8;
extern float lbl_80605DBC;

extern "C" void fn_803895A4(void* self, char* a, float* out, float f0, float f1)
{
    float* v = 0;
    if (a != 0)
        v = (float*)(a + 4);
    float t10, t14, t18, t1c, t20;
    t10 = f0 - lbl_80605DB4;
    t18 = lbl_80605DB8;
    t1c = lbl_80605DB4;
    t14 = *out * t10;
    if (v != 0) {
        t18 = *v;
        t1c = lbl_80605DB4;
    }
    if (!(t18 > lbl_80605DB8))
        t18 = lbl_80605DBC;
    if (!(t1c > lbl_80605DB8))
        t1c = lbl_80605DB4;
    t20 = f1 * t18 * t1c;
    t14 += t20;
    *out = t14 / t10;
}

extern "C" void fn_803899CC(GlPool* self, float f, int a, int b, int idx)
{
    fn_803BB7A8(self->m289, b, a, a, lbl_80699B14 + idx * 32, f);
}

struct GlV3 { float x, y, z; };
struct GlB40 { char d[0x40]; };
struct GlB28 { GlV3 v; char pad[0x28 - 12]; };

extern "C" void fn_80389BD8(void* a, int b, void* c, int d);
extern "C" void fn_803DF9C8(void* m, void* a, void* b);
extern "C" void fn_803DE51C(void* m, int a, void* b);

extern "C" int fn_80389B34(void* x, int a, GlV3* p1, GlV3* p2, int p3, int flags);

extern "C" void fn_80389B10(void* x, int a, GlV3* p1, GlV3* p2, int p3)
{
    fn_80389B34(x, a, p1, p2, p3, 3);
}

extern "C" int fn_80389B34(void* x, int a, GlV3* p1, GlV3* p2, int p3, int flags)
{
    GlB40 m;
    GlB28 t;
    GlV3 u;
    fn_80389BD8(x, a, &m, flags);
    if (p3 == 0) {
        void* q = p2;
        if (q == 0)
            q = &t;
        void* r = p1;
        if (r == 0)
            r = &u;
        fn_803DF9C8(&m, q, r);
    } else {
        fn_803DE51C(&m, p3, &t);
        if (p1 != 0)
            *p1 = t.v;
    }
    return 1;
}


struct GlVt13 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_806850A0[];
extern char lbl_80684E18[];
extern char lbl_806626C0[];
extern char lbl_80684F48[];
extern char lbl_806059C0[];
extern int lbl_8069593C;

extern "C" void fn_8037B424(void* p, int c);
extern "C" void fn_80378620(void*, int);

extern "C" void fn_8038B7E4(void* self, int c)
{
    PUT(0x0, lbl_806850A0);
    fn_8037B424(self, c);
}

extern "C" int fn_8038B814()
{
    return 0;
}

extern "C" void fn_8038B81C()
{
}

extern "C" int fn_8038B820()
{
    return 1;
}

extern "C" const char* fn_8038B854(DtorAt0*, int);

extern "C" void fn_8038B828(DtorAt0* s, int chrg)
{
    fn_8038B854(s, chrg);
}

extern "C" int fn_8038B848()
{
    return lbl_8069593C;
}

extern "C" const char* fn_8038B854(DtorAt0*, int)
{
    return lbl_806059C0;
}

extern "C" int fn_8038B860()
{
    return 0;
}

extern "C" int fn_8038B868(GlVt13* self)
{
    return self->v13();
}

extern "C" int fn_8038B89C()
{
    return 0;
}

extern "C" int fn_8038B8A4()
{
    return 0;
}

extern "C" void fn_8038B8AC(void* self, int c)
{
    PUT(0x8, lbl_80684F48);
    fn_80378620(self, c);
}

extern "C" void fn_8038B8DC(void* self, int c)
{
    PUT(0x0, lbl_80684E18);
    ((Unk80384F28*)((char*)self + 4))->Unk80384F28::~Unk80384F28();
    PUT(0x0, lbl_806626C0);
    fn_8037B424(self, c);
}
