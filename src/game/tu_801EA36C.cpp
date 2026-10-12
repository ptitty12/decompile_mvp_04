/*
 * Game code, .text 0x801EA36C-0x801EE438 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801DB948.h"

typedef Unk801DD660 I;
typedef Unk80270BA0_X P;

/* View of the context object used by the state handlers below (offsets only). */
struct Unk801EA36C_Cx {
    char pad0[0x6A8];
    int m6A8;
    int m6AC;
    int m6B0;
};

struct Unk801EA36C_Slot {
    int m0;
    char pad4[0x514 - 4];
};
struct Unk801EA36C_Tbl {
    char pad0[0xCA8];
    Unk801EA36C_Slot mCA8[9];
};

struct Unk801EA36C_Cx3 {
    char pad0[0x8C];
    P* m8C;
    int m90;
    char pad94[0x3A64 - 0x94];
    I* m3A64;
};
struct Unk801EA36C_E5C {
    Unk801DB948_Vec3 v1;
    int pad0C;
    float f1;
    int i1;
    char pad18[0x30 - 0x18];
    Unk801DB948_Vec3 v2;
    float f2;
    char pad40[0x5C - 0x40];
};
struct Unk801EA36C_Cx2 {
    char pad0[0x6C0];
    Unk801EA36C_E5C m6C0[8];
};
extern const float lbl_805D4A84;
typedef void (Unk801DD660::*Unk801EA36C_Pmf)();
extern Unk801EA36C_Pmf lbl_8061CCE4[];
extern int lbl_8061CF14[];
extern int lbl_8061F8F8;

extern "C" {
int fn_801E816C(I* s, int i);
void fn_801F7F60(void* p, int k, int v);
void fn_80235AD4(int x);
int fn_802281D0(I* s, int v, int a, int b);
int fn_80205644(Unk801DD660_Ctx* c);
void fn_80227564(I* s, int a, int b);
void fn_801EC5F8(I* s, int v);
int fn_802055F4(Unk801DD660_Ctx* c);
void fn_801EBBAC(I* s);
void fn_801EBCE4(I* s);
void fn_801EBC70(I* s);
void fn_801EBD98(I* s);
void fn_801EBC44(I* s);
int fn_8017C94C(Unk801DB948_J* j);
void fn_80208C84(void* p, int a, int b);
void fn_80204AC8(void* p);
void fn_80206B08(void* p);
void fn_80207B00(void* p);
void fn_80208060(void* p);
void fn_8020883C(void* p);
void fn_801EDEF4(I* s, int e, int a);
void fn_8014E09C(Unk801DB948_It* it, Unk801DB948_Game* g, int k);
}

extern "C" void fn_801EA36C(I* s, int a, P* p)
{
    fn_801EC5F8(s, p->m460);
}

extern "C" void fn_801EA390(I* s, P* a, int b)
{
    Unk801EA36C_Cx3* c = (Unk801EA36C_Cx3*)s->m9C;
    if (c->m8C == 0) {
        c->m8C = a;
        int v = -1;
        ((Unk801EA36C_Cx3*)s->m9C)->m90 = b;
        if (((Unk801EA36C_Cx3*)s->m9C)->m3A64->m798 > 0)
            v = fn_801E816C(((Unk801EA36C_Cx3*)s->m9C)->m3A64, 0);
        if (v == ((Unk801EA36C_Cx3*)s->m9C)->m8C->m460) {
            int h = lbl_8061F8F8;
            if (h == -1)
                h = fn_802281D0(s, v, 1, 0);
            fn_80227564(s, h, fn_80205644(((Unk801EA36C_Cx3*)s->m9C)->m3A64->m9C) == 1);
        }
    }
}

extern "C" int fn_801EA458(I* s)
{
    int r = 0;
    Unk801EA36C_Cx* c = (Unk801EA36C_Cx*)s->m9C;
    if (c->m6A8 != 0 || c->m6AC != 0)
        r = 1;
    if (r == 1 && fn_802055F4(s->m9C) == 1 && ((Unk801EA36C_Cx*)s->m9C)->m6B0 == 1)
        r = 0;
    return r;
}

struct Unk801EAAE0_El {
    int m0;
    float m4;
    float m8;
};

extern const char lbl_80660A90[];

struct Unk801EAAE0_Obj {
    int m0;
    int m4;
    const void* m8;
    Unk801EAAE0_El mC[9];
    ~Unk801EAAE0_Obj() { m8 = lbl_80660A90; }
};

struct Unk801EAAE0_Cx {
    char pad0[8];
    P* m8[10];
};

extern "C" Unk801EAAE0_Obj* fn_802116B4(Unk801EAAE0_Obj* o, Unk801DD660_Ctx* g);
extern "C" void fn_8021183C(Unk801EAAE0_Obj* o, Unk801DB948_Vec3* pos, int flag);

inline P* PlAt801EAAE0(void** a, int i)
{
    int o = i * 4;
    return *(P**)((char*)a + o);
}

/* near-miss (1 slot): retail starts the inner counter with mr r10,r8 (copy of the found flag) where ours has li r10,0 */
extern "C" P* fn_801EAAE0(I* s, Unk801DB948_Vec3* pos, P** list, int n)
{
    Unk801EAAE0_Obj o;
    fn_802116B4(&o, s->m9C);
    P* r = 0;
    fn_8021183C(&o, pos, 1);
    for (int i = 0; i < 9; i++) {
        if (o.mC[i].m0 != -1) {
            int found = 0;

            for (int j = 0; j < n; j++) {
                if (o.mC[i].m0 == list[j]->m460) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                r = PlAt801EAAE0((void**)((Unk801EAAE0_Cx*)s->m9C)->m8, o.mC[i].m0);
                break;
            }
        }
    }
    return r;
}

extern "C" void fn_801EABCC(I* s, int k, Unk801DB948_Vec3* out, float* f)
{
    Unk801EA36C_Cx2* c = (Unk801EA36C_Cx2*)s->m9C;
    if (c->m6C0[k].i1 >= 0 && !(c->m6C0[k].f1 < lbl_805D4A84)) {
        *out = c->m6C0[k].v1;
        *f = ((Unk801EA36C_Cx2*)s->m9C)->m6C0[k].f1;
    } else {
        *out = c->m6C0[k].v2;
        *f = ((Unk801EA36C_Cx2*)s->m9C)->m6C0[k].f2;
    }
}

struct Unk801EADD4_Jx {
    char pad0[0x41C];
    int m41C;
};

extern const float lbl_805D4A98;
extern const float lbl_805D4A9C;
extern const float lbl_805D4AA0;
extern const float lbl_805D4AA4;
extern float lbl_8061D5B8;

extern "C" void fn_802121D0(int* s);
extern "C" void fn_8023CAF0(P* p);
extern "C" void fn_801E8068(I* o);
extern "C" void fn_801E81C8(I* o);

/* near-miss: control flow and calls match; retail stores the three zero ints with a fresh li r0,0 (not the r30 result flag) and
   schedules the float constant loads and the mF8 block stores differently */
extern "C" int fn_801EADD4(I* s)
{
    int r = 0;
    fn_802121D0(&s->m9C->m30);
    s->m9C->m3A68 = 0;
    s->m9C->m3A6C = 0;
    s->mB8 = 0;
    Unk801DB948_Obj* o = s->m9C->m4;
    P* pl = o->m36C;
    s->mEC = lbl_805D4A98;
    s->mE8 = lbl_805D4A98;
    s->mF0 = lbl_805D4A98;
    fn_8023CAF0(((Unk801EAAE0_Cx*)s->m9C)->m8[0]);
    float t = lbl_8061D5B8;
    s->mF4 = t;
    Unk801DD660_Blk* b = &s->mF8;
    s->mF8.m0 = lbl_805D4A9C;
    b->m10 = lbl_805D4A9C;
    b->m4 = 0;
    b->m8 = lbl_805D4A9C;
    b->mC = lbl_805D4A9C;
    b->m14 = lbl_805D4AA0;
    b->m20 = 1;
    b->m18 = lbl_805D4AA4;
    b->m1C = 0;
    fn_801E8068(((Unk801EA36C_Cx3*)s->m9C)->m3A64);
    fn_801E81C8(((Unk801EA36C_Cx3*)s->m9C)->m3A64);
    int v;
    if (pl == 0) {
        Unk801DB948_Game* g = s->m9C->m0;
        if (o->m38C != 1 && g->m6F4 != 9) {
            if (((Unk801EADD4_Jx*)g->m700)->m41C != 0xA) {
                v = 4;
                r = 1;
            } else {
                v = 2;
                r = 1;
            }
        } else {
            v = 1;
        }
    } else {
        if (pl->m460 == 0) {
            v = 3;
            r = 1;
        } else if (pl->m460 == 1) {
            v = 2;
            r = 1;
        } else {
            v = 1;
        }
    }
    s->m9C->m34 = v;
    return r;
}

extern "C" int fn_801EAF38(I* s)
{
    int r = 0;
    switch (s->m9C->m34) {
    case 0:
        break;
    case 1:
        fn_801EBBAC(s);
        break;
    case 3:
        fn_801EBCE4(s);
        r = 1;
        break;
    case 2:
        fn_801EBC70(s);
        r = 1;
        if (fn_8017C94C(s->m9C->m0->m700) != 0)
            fn_80208C84((char*)s + 0xA8, 0, 1);
        break;
    case 4:
        fn_801EBD98(s);
        r = 1;
        break;
    }
    s->mC0 = 2;
    return r;
}

extern "C" int fn_801EB00C(I* s)
{
    int r = 0;
    switch (s->m9C->m34) {
    case 0:
        r = 1;
        break;
    case 1:
        fn_801EBC44(s);
        break;
    case 2:
    case 3:
    case 4:
        r = 1;
        break;
    }
    return r;
}

static inline void ClearSlots(Unk801DD660_Ctx* c)
{
    Unk801EA36C_Slot* e = ((Unk801EA36C_Tbl*)c)->mCA8;
    int cnt = 9;
    do {
        int n = e->m0;
        for (int j = 0; j < n; j++) {
        }
        e->m0 = 0;
        e++;
        cnt--;
    } while (cnt != 0);
}

extern "C" void fn_801EBBAC(I* s)
{
    ClearSlots(s->m9C);
    void* sub = (char*)s + 0xA8;
    fn_80204AC8((char*)s->m9C + 0x6A8);
    s->m9C->m30 = 1;
    fn_80206B08(sub);
    fn_80207B00(sub);
    fn_80208060(sub);
    fn_8020883C(sub);
}

extern "C" void fn_801EBC44(I* s)
{
    fn_80208C84((char*)s + 0xA8, 0, 0);
}

extern "C" void fn_801EBC70(I* s)
{
    ClearSlots(s->m9C);
    fn_80204AC8((char*)s->m9C + 0x6A8);
    s->m9C->m30 = 4;
}

extern "C" void fn_801EBCE4(I* s)
{
    Unk801DB948_Vec3 v = *(Unk801DB948_Vec3*)((char*)s->m9C + 0xC88);
    ClearSlots(s->m9C);
    fn_80204AC8((char*)s->m9C + 0x6A8);
    s->m9C->m30 = 4;
    *(Unk801DB948_Vec3*)((char*)s->m9C + 0xC88) = v;
}

extern "C" void fn_801EBD98(I* s)
{
    ClearSlots(s->m9C);
    fn_80204AC8((char*)s->m9C + 0x6A8);
    s->m9C->m30 = 2;
    fn_80208C84((char*)s + 0xA8, 0, 1);
}

extern "C" void fn_801EBE1C(I* s, int k)
{
    Unk801EA36C_Pmf f = lbl_8061CCE4[k];
    fn_801F7F60((char*)s + 0xA0, k, lbl_8061CF14[k]);
    (s->*f)();
    if (k != 1)
        fn_80235AD4(s->m9C->m0->m700->m3B0);
}

extern "C" P* fn_801EDE4C(I* s, Unk801DB948_Obj* o)
{
    P* r = o->m36C;
    if (r == 0 && o->m38C == 3 && o->m380 == 0)
        r = o->m378;
    return r;
}

extern "C" void fn_801EDE78(I* s, int a)
{
    if (s->m9C->m0->m6F4 != 9) {
        volatile int sp8 = 0;
        int e = 0;
        do {
            fn_801EDEF4(s, e, a);
            int c = sp8;
            int t;
            if (c > 3)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 3);
    }
}

struct U;
void fn_8035C1B0(U* self);

struct Unk801EDEF4_E {
    int m0;
    int m4;
    int m8;
};

struct Unk801EDEF4_Cx {
    char pad0[0x3A5C];
    int m3A5C;
};

struct Unk801EDEF4_Obj {
    int m0;
    int m4;
    int m8;
    Unk801EDEF4_E mC[4];
};

extern "C" void fn_80204714(Unk801EDEF4_Obj* o);
extern "C" void fn_801EDFE4(I* s, int e);
extern "C" void fn_801EE438(I* s, int e);
extern "C" void fn_80205450(Unk801DD660_Ctx* c, int i);

inline int SlotAt801EDEF4(int* a, int i)
{
    if (i == -1)
        return -1;
    return a[i];
}

/* near-miss (13 slots): same control flow and calls; retail keeps the slot value in r5 and the found flag in r11, and loads
   the zero for o.m0 into r10 early */
extern "C" void fn_801EDEF4(I* s, int e, int a)
{
    Unk801EDEF4_Obj o;
    Unk801EDEF4_Obj* p = &o;
    int saved = ((Unk801EDEF4_Cx*)s->m9C)->m3A5C;
    Unk801DB948_J* j = s->m9C->m0->m700;
    p->m0 = 0;
    p->m4 = (int)j->m3B8;
    p->m8 = (int)j->m3B4;
    fn_8035C1B0((U*)p);
    fn_80204714(p);
    int g = SlotAt801EDEF4((int*)((char*)s->m9C + 0xC0), e);
    int f = 0;
    if (o.mC[e].m0 == 0 && a == 0) {
        if (g != -1)
            f = 1;
    }
    if (g == -1 && f == 0)
        fn_801EDFE4(s, e);
    else
        fn_801EE438(s, e);
    fn_80205450(s->m9C, saved);
}
