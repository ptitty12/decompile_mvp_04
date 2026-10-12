/*
 * Game code, .text 0x801F6680-0x801FA73C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801F6680.h"

typedef Unk801F6680_Menu Menu;

extern int lbl_806609D0;
extern const float lbl_805D4F34;

typedef Unk801EE438_Sel Unk801F6680_Sel;

struct Unk805D4EB0_F {
    float v;
};
extern Unk805D4EB0_F lbl_805D4EB0;
extern float lbl_805D4F1C;
extern const float lbl_805D4F28;
extern const float lbl_805D4F2C;
extern const float lbl_805D4F30;
extern int lbl_8061B9C8;

struct Unk801F6680_Cmd {
    int m0;
    int m4;
};

extern const float lbl_805D4F98;

extern "C" {
void fn_801F8E50(Menu* m);
void fn_801F91AC(Menu* m);
void fn_801F9478(Menu* m);
Unk801F6680_Cmd* fn_801FA250(Menu* m);
void fn_801FA65C(Menu* p, Unk801F6680_Cmd* c);
void fn_801FA73C(Menu* m, Unk801F6680_Cmd* c);
void fn_801FAFD0(Menu* m);
void fn_801FB084(Menu* m);
int fn_80211E30(const void* a, const void* b);
void fn_8040A208(void* base, int n, int size, int (*cmp)(const void*, const void*));
float fn_8018A214(Unk801EE438_Game* x);
void fn_80202A24(int g);
void fn_80201864(int g);
void fn_80203EA4(int g);
void fn_802126B8(int g, int a);
void fn_80203288(int g);
void fn_80202FF0(int g);
void fn_8035BED0(Unk801EE438_Rec14* r, int a);
void fn_80227564(Unk801EE438_Scr* p, int k, int a);
int fn_80210C98(Unk801EE438_G** g, int a);
int fn_802055F4(Unk801EE438_G* g);
}

extern char lbl_80649DA0[];
extern char lbl_80660C30[];
extern char lbl_80660C18[];
extern float lbl_805D4EAC;

struct Unk801F6680_Ev {
    int m0;
    const void* vptr;
    int m8;
    int mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
        m8 = 0;
    }
    void Set(int a, int b)
    {
        mC = a;
        m8 = b;
    }
    ~Unk801F6680_Ev() { vptr = lbl_80649DA0; }
};

struct Unk801F6680_Own {
    char pad0[0x6F4];
    int m6F4;
};

struct Unk801F6680_P {
    char pad0[0x460];
    int m460;
};

struct Unk801F6680_Q {
    char pad0[0x56C];
    int m56C;
};

extern "C" void fn_8037893C(void* q, int id, Unk801F6680_Ev* e, int a, int b);

extern "C" void fn_801F6680(Unk801EE438_Scr* s, Unk801F6680_P* a, Unk801F6680_Q* b, int n, int c)
{
    if (b != 0 && n > 1) {
        b->m56C = a->m460;
        Unk801F6680_Ev e;
        Unk801F6680_Ev* p = &e;
        p->Base(0x6F);
        p->Set(n, c);
        p->vptr = lbl_80660C30;
        fn_8037893C((char*)s->m9C->m0 + 0x704, e.m0, p, 0, 0);
    }
    int is9 = ((Unk801F6680_Own*)s->m9C->m0)->m6F4 == 9;
    if (is9 == 1) {
        Unk801F6680_Ev e;
        Unk801F6680_Ev* p = &e;
        p->Base(0x70);
        p->vptr = lbl_80660C18;
        float* q = (float*)((char*)s + 0xC4);
        float x18 = q[2];
        float x1c = q[4];
        float k = lbl_805D4EAC;
        if (!(x18 >= x1c - lbl_805D4EAC)) {
            p->m8 = is9;
        } else {
            int v = 2;
            if (n > 1)
                v = 3;
            p->m8 = v;
        }
        fn_8037893C((char*)s->m9C->m0 + 0x704, e.m0, p, 0, 0);
    }
}

extern "C" void fn_801F67E0(Unk801EE438_Scr* p)
{
    Unk801EE438_Rec14* base = p->m9C->m62C;
    Unk801EE438_Rec14* r = base;
    for (int i = 0; i < 4; i++, r++) {
        r->m0 = 0;
        r->m8 = r->m4 = lbl_805D4EB0.v;
        r->mC = 0;
    }
    fn_8035BED0(base, 0);
}

extern "C" void fn_801F7B60()
{
    double d;
}

extern "C" void fn_801F7DC4(Unk801EE438_Scr* p)
{
    if (!(p->mE8 <= lbl_805D4F1C)) {
        p->mE8 = p->mE8 - (float)lbl_8061B9C8 * lbl_805D4F28;
        if (!(p->mE8 > lbl_805D4F1C)) {
            p->mE8 = lbl_805D4F1C;
            int k = -1;
            Unk801F6680_Sel* o = (Unk801F6680_Sel*)p->m9C->m3A64;
            if (o->m798 > 0)
                k = fn_801E816C(o, 0);
            else if (o->m794 > 0)
                k = fn_801E82CC(o, 0);
            if (k != -1)
                fn_80227564(p, k, 0);
        }
    }
}

extern "C" void fn_801F7EA4()
{
}

extern "C" void fn_801F7EA8(Unk801EE438_Scr* p)
{
    if (!(p->mF4 <= lbl_805D4F2C)) {
        p->mF4 = p->mF4 - lbl_805D4F30;
        if (!(p->mF4 > lbl_805D4F2C)) {
            int r = 0;
            if (p->m9C->m30 != 6)
                r = fn_80210C98(&p->m9C, 0) == 0;
            if (fn_802055F4(p->m9C) == 1)
                r = 0;
            if (r == 1)
                p->m9C->m44 = r;
            else
                p->mF4 = lbl_805D4F30;
        }
    }
}

extern "C" void fn_801F7F60()
{
}

extern "C" void fn_801F7F64(Menu* m)
{
    Unk801EE438_G* s = m->m0;
    int i = 0;
    int* n = &s->m1D8;
    if (i < *n) {
        Unk801EE438_Ent18* e = s->m1DC;
        do {
            i++;
            e->m14 = &lbl_806609D0;
            e++;
        } while (i < *n);
    }
    *n = 0;
    m->m0->m38 = 1;
    m->m4 = lbl_805D4F34;
}

extern "C" void fn_801F7FC4(Menu* m, int f)
{
    if (f & 1)
        m->m0->m48 = 1;
    if (f & 4) {
        m->m0->m4C = 1;
        m->m0->m60 = 1;
    }
    if (f & 8)
        m->m0->m50 = 1;
    if (f & 0x10) {
        m->m0->m54 = 1;
        m->m0->m5C = 1;
    }
    if (f & 0x20)
        m->m0->m58 = 1;
}

/* near-miss (10 slots): stack layout matches (inline setter for the result float); the order of the
 * owner/constant loads and their registers differs. */
inline void SetT8D34(Menu* m, float v)
{
    m->m4 = v;
}

extern "C" void fn_801F8D34(Menu* m)
{
    Unk801EE438_G* g = m->m0;
    int a = g->m48;
    int n = g->m1D8;
    if (a == 1)
        g->m6C = a;
    fn_801F8E50(m);
    if (n > 1)
        fn_8040A208(m->m0->m1DC, n, 0x18, fn_80211E30);
    fn_801FB084(m);
    fn_801F91AC(m);
    fn_801F9478(m);
    Unk801F6680_Cmd* c = fn_801FA250(m);
    fn_801FA65C(m, c);
    fn_801FA73C(m, c);
    fn_801FAFD0(m);
    float f = fn_8018A214(m->m0->m0->m6CC);
    SetT8D34(m, f + (float)m->m0->m0->m4C * lbl_805D4F98);
}

extern "C" void fn_801F8E40(Menu* m)
{
    m->m0->m38 = 0;
}

extern "C" void fn_801FA65C(Menu* p, Unk801F6680_Cmd* c)
{
    fn_80205450(p->m0, c->m0);
    switch (c->m4) {
    case 1:
        fn_80202A24(p->m0->m3A64);
        break;
    case 2:
        fn_80201864(p->m0->m3A64);
        break;
    case 4:
        fn_80203EA4(p->m0->m3A64);
        break;
    case 6:
        fn_802126B8(p->m0->m3A64, 4);
        break;
    case 3:
        fn_80203288(p->m0->m3A64);
        break;
    case 7:
        fn_80202FF0(p->m0->m3A64);
        break;
    }
}
