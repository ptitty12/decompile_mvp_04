/*
 * Game code, .text 0x801DC918-0x801DEC20 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801DB948.h"

typedef Unk801DB948 W;
typedef Unk801DD660 I;
typedef Unk801DB948_Vec3 Vec3;
struct Unk8027C728_Goal;

extern const Vec3 lbl_806055DC;
extern const float lbl_805D39D4;
extern const float lbl_805D3B24;
extern const float lbl_805D3B2C;
extern const float lbl_805D3A14;
extern const float lbl_805D3A20;
extern const float lbl_805D3A24;
extern const float lbl_805D3A30;
extern const float lbl_805D3AD8;
struct Unk805D3B1C_F { float v; };
extern Unk805D3B1C_F lbl_805D3B1C;
extern const float lbl_805D3B20;
extern const float lbl_805D3B28;
extern const float lbl_805D3B30;
extern const Vec3 lbl_805D3A34;
extern const char lbl_805D3A40[];
extern const float lbl_805D3A78;
extern const float lbl_805D3A88;
extern const Vec3 lbl_805D6760[];

extern "C" {
Unk801DB948_Game* fn_801DCC0C(W* self);
int fn_801A2034(Unk801DB948_Game* g, int a);
void fn_801E81C8(I* i);
void fn_801E8068(I* i);
void fn_80221D0C(I* i);
int fn_80221E1C(I* i);
Unk80270BA0_X* fn_801A497C(Unk801DB948_Game* g, int a, int b);
void fn_801EABCC(I* i, int id, Vec3* v, float* f);
void fn_80222084(I* i);
void fn_8020E82C(I* i, int a, int b, int c, int d, int e, int f, int g);
void fn_801F316C(I* i);
void fn_802055F4(Unk801DD660_Ctx* c);
void fn_80205644(Unk801DD660_Ctx* c);
void fn_80205664(Unk801DD660_Ctx* c);
void fn_801F683C(I* i);
void fn_801F67E0(I* i);
void fn_801DD98C(I* i, int a);
void fn_801EA03C(I* i);
int fn_8020543C(Unk801DD660_Ctx* c);
int fn_80235AB8(int x);
int fn_8006BE18(Unk801DB948_T* t);
void fn_801E9E20(I* i);
int fn_8006BDCC(Unk801DB948_T* p);
void fn_801DE7FC(I* i);
void fn_801E9BFC(I* i);
int fn_8033E420(void* p);
void fn_801DE430(I* i);
void fn_801DE5B0(I* i);
void fn_801E9E94(I* i);
void fn_801EA458(I* i);
Unk8027C728_Goal* fn_801E5DF8(Unk801DB948_Game* g, int a, int b);
void fn_8014E09C(Unk801DB948_It* it, Unk801DB948_Game* g, int k);
int fn_80259C00(int x);
void fn_801DD420(Unk801DD660_Sub2* s);
void fn_801E9BE4(I* i);
void fn_80249B08(void* o, int a, float f);
int fn_80259330(int x);
void fn_801E9AC4(I* i);
float fn_801E9C08(I* i);
void fn_8035B718(Unk8035B718* t);
void fn_801DE660(I* i, Unk8035B718* t);
void fn_801DE864(I* i, Unk8035B718* t);
void fn_801DF134(I* i, Unk801DD660_Rec* r, Unk80270BA0_X* p);
void fn_80189300(Unk801DB948_Obj* o, Unk80270BA0_X* a);
Vec3 fn_801837F4(void* p, int f);
void fn_801A656C(Unk801DB948_Game* g, Unk80270BA0_X* p, int k);
void fn_801DDADC(I* i, Unk80270BA0_X* p, int a, int b);
void fn_801DB948(Unk801DB948_A* a);
void fn_801DE570(I* i, Unk801DD660_Rec* a, Unk80270BA0_X* b);
Unk801DB948_Rt* fn_801A6DB8(Unk801DB948_Game* g);
void fn_8024D178(Unk80270BA0_X* p, int a);
int fn_8026D5D0(Unk80270BA0_X* p, int a);
void fn_801DF08C(I* i, Unk801DD660_Rec* r, Unk80270BA0_X* p, int a);
void fn_801DE8F4(I* i, Unk8035B718* t, int a);
void fn_801DEA84(I* i);
void fn_801DEAEC(I* i, Unk8035B718* t);
void fn_801DEF4C(I* i, Unk8035B718* t);
void fn_801DEC20(I* i, Unk8035B718* t);
void fn_801DED34(I* i, Unk8035B718* t);
void fn_801DEE04(I* i, Unk8035B718* t);
void fn_801DEE80(I* i, Unk8035B718* t);
int fn_801DF280(I* i, Unk801DD660_Rec* r, Unk80270BA0_X* p);
void fn_801E0BE0(I* i);
int fn_801BCA0C(int x);
void fn_80235AC4(int x);
void fn_8025004C(Unk801DB948_PlSub* s);
}

void fn_8027D33C(Unk8027C728_Goal* g);
void fn_80286FAC(Unk80270BA0_X* x);

extern "C" void fn_801DC918(W* self)
{
    if (fn_801A2034(fn_801DCC0C(self), 4) == -1) {
        fn_801E81C8(self->m4);
        fn_801E8068(self->m4);
    }
}

extern "C" void fn_801DC964(W* self)
{
    fn_80221D0C(self->m4);
}

extern "C" void fn_801DC988(W* self, Unk80270BA0_X** a, Vec3* b, float* c)
{
    if (a != 0 && b != 0 && c != 0) {
        *a = 0;
        *b = lbl_806055DC;
        *c = lbl_805D39D4;
        if (fn_801DCC0C(self)->m6CC->m36C == 0) {
            int id = fn_80221E1C(self->m4);
            if (id != -1) {
                *a = fn_801A497C(fn_801DCC0C(self), 4, id);
                fn_801EABCC(self->m4, id, b, c);
            }
        }
    }
}

extern "C" void fn_801DCA58(W* self)
{
    fn_80222084(self->m4);
}

extern "C" void fn_801DCA7C(W* self, int a, int b, int c, int d, int e, int f, int g)
{
    fn_8020E82C(self->m4, a, b, c, d, f, g, e);
}

extern "C" void fn_801DCAB0(W* self)
{
    fn_801F316C(self->m4);
}

extern "C" Vec3 fn_801DCAD4(W* self, int idx)
{
    return self->m4->m9C->m6D8[idx].m0;
}

extern "C" float fn_801DCB08(W* self, int idx)
{
    return self->m4->m9C->m6D8[idx].mC;
}

extern "C" void fn_801DCB20(W* self)
{
    fn_802055F4(self->m4->m9C);
}

extern "C" void fn_801DCB48(W* self)
{
    fn_80205644(self->m4->m9C);
}

extern "C" void fn_801DCB70(W* self)
{
    fn_80205664(self->m4->m9C);
}

struct Unk801DC918_P {
    char pad0[0x460];
    int m460;
};

extern "C" void fn_801DCB98(W* self, Unk801DC918_P* p)
{
    if (p != 0) {
        I* i = self->m4;
        int v = p->m460;
        Unk801DD660_Hist* h = &i->mAC;
        if (v != h->m0) {
            h->m4 = h->m0;
            h->m0 = v;
        }
    }
}

extern "C" void fn_801DCBC4(W* self)
{
    fn_801F683C(self->m4);
}

extern "C" void fn_801DCBE8(W* self)
{
    fn_801F67E0(self->m4);
}

extern "C" Unk801DB948_Game* fn_801DCC0C(W* self)
{
    return self->m4->m9C->m0;
}

extern "C" int fn_801DCDCC(Unk801DD660_Sub* s)
{
    int r = 0;
    if (s->mC != -1 && !(s->m10 <= lbl_805D3A14))
        r = (float)s->m0->m9C->m0->m4C * lbl_805D3A20 > s->m10;
    return r;
}

extern "C" int fn_801DCE4C(Unk801DD660_Sub* s)
{
    int r = 0;
    if (s->mC != -1 && !(s->m14 < lbl_805D3A24))
        r = (float)s->m0->m9C->m0->m4C * lbl_805D3A30 > s->m14;
    return r;
}

struct Unk801DCEC8_Gm {
    char pad0[0x65C];
    Unk80270BA0_X* m65C[13];
};
static inline Unk80270BA0_X* PlAt2(I* i, unsigned j)
{
    return j <= 12 ? ((Unk801DCEC8_Gm*)i->m9C->m0)->m65C[j] : 0;
}

/* near-miss: k lands in r0 (retail r11) and p in r9 (retail r4); lfsx operand order differs (17 slots) */
extern "C" int fn_801DCEC8(Unk801DD660_Sub* s, int sel)
{
    int r = 0;
    unsigned k = -1;
    switch (sel) {
    case 0:
        k = 10;
        break;
    case 1:
        k = 11;
        break;
    case 2:
        k = 12;
        break;
    }
    I* i = s->m0;
    Unk80270BA0_X* p = PlAt2(i, k);
    if (p != 0) {
        int idx = fn_80259C00(i->m9C->m0->m700->m3B4);
        Vec3 v = lbl_805D3A34;
        float t;
        volatile int pad;
        float lim = lbl_805D3A78;
        const char* file = lbl_805D3A40;
        unsigned rn = s->m0->m9C->m0->m554->fn_8014D8AC(1000000, file, 0x9D);
        t = (float)rn * lim * lbl_805D3A88;
        r = t < ((float*)&v)[idx];
    }
    return r;
}

extern "C" void fn_801DD420(Unk801DD660_Sub2* s)
{
    s->m8[0] = 1;
    s->m8[1] = 1;
    s->m4 = lbl_805D3AD8;
    Unk801DB948_It it;
    fn_8014E09C(&it, s->m0->m9C->m0, 3);
    while (it.Cur() != 10) {
        int k = it.Cur();
        int z = 0;
        *(int*)((char*)s + k * 4 + 8) = z;
        it.Next();
    }
}

extern "C" void fn_801DD98C(I* i, int arg1)
{
    if (i->m9C->m0->m6F4 == 9) {
        Unk80270BA0_X* p = fn_801A497C(i->m9C->m0, 4, 5);
        if (p != 0) {
            int f = 1;
            if (p->m458 == 5)
                f = 0;
            fn_801A656C(i->m9C->m0, p, 5);
            fn_801DDADC(i, p, f, arg1);
        }
    } else {
        int k = 0;
        do {
            int ok = 1;
            if (fn_801A6DB8(i->m9C->m0)->mC == 0) {
                ok = k == 0;
            } else if (fn_801A6DB8(i->m9C->m0)->m4 == 0 && (unsigned)k > 1) {
                ok = 0;
            }
            if (ok != 0) {
                Unk80270BA0_X* q = fn_801A497C(i->m9C->m0, 4, k);
                if (q != 0) {
                    int f = 1;
                    if (q->m458 == k)
                        f = 0;
                    fn_801A656C(i->m9C->m0, q, k);
                    fn_801DDADC(i, q, f, arg1);
                }
            }
            k++;
        } while (k <= 8);
    }
}

extern "C" void fn_801DDADC(I* i, Unk80270BA0_X* p, int a, int b)
{
    p->v8(0);
    p->m908 = 0;
    fn_8024D178(p, 0);
    p->m8F0 = 0;
    int r = 0;
    if (a != 0)
        r = 1;
    if (i->m9C->m0->m700->m418 != 0)
        r = 1;
    int st = p->m458;
    if (st == 0) {
        if (fn_8026D5D0(p, 0) == 0)
            r = 1;
    } else if (st == 1) {
        unsigned h = p->m618->m838;
        if (h != 0x0AA2B889 && h != 0xB3991323 && h != 0xC3FB7E21)
            r = 1;
    }
    if (r != 0) {
        if (fn_8006BE18(i->m9C->m0->m6F8) == 1) {
            Unk801DD660_Rec* b = i->m16C.m0;
            Unk801DD660_Rec* rec = b + p->m460;
            fn_801DF134(i, rec, p);
            fn_801DE570(i, rec, p);
            return;
        }
        Unk801DD660_Rec* b2 = i->m16C.m0;
        Unk801DD660_Rec* rec2 = b2 + p->m460;
        fn_801DF08C(i, rec2, p, b);
        fn_801DE570(i, rec2, p);
    }
}

extern "C" void fn_801DDC60(I* i)
{
    fn_801DD98C(i, 0);
}

/* near-miss: retail uses r0 for both the loaded m6F4 and the 9/1 select (1 slot pair) */
extern "C" void fn_801DDC84(I* i)
{
    fn_801E8068(i);
    fn_801E81C8(i);
    fn_801E9BE4(i);
    fn_801DD420(&i->m134);
    fn_80286FAC(fn_801A497C(i->m9C->m0, 4, 0));
    i->m168 = i->m9C->m0->m6F4 == 9 ? 9 : 1;
    fn_801DD98C(i, 1);
}

extern "C" void fn_801DDD0C(I* i)
{
    i->m11C.m4 = 0;
}

/* lbl_805D3B1C is a one-float struct so its load stays below the int stores through s */
extern "C" void fn_801DDD18(I* i)
{
    Unk801DD660_Sub* s = &i->m11C;
    s->m8 = 0;
    s->mC = -1;
    s->m14 = s->m10 = lbl_805D3B1C.v;
    fn_801DD420(&i->m134);
    i->m168 = 2;
    fn_801DD98C(i, 1);
    void* o = i->m9C->mC;
    if (o != 0)
        fn_80249B08(o, 0, lbl_805D3B20);
}

extern "C" void fn_801DDDA0(I* i)
{
    i->m168 = 7;
}

extern "C" void fn_801DDDAC(I* i)
{
    i->m168 = 5;
}

extern "C" void fn_801DDDB8(I* i)
{
    if (i->m168 != 8)
        i->m168 = 7;
}

extern "C" void fn_801DDDD0(I* i)
{
    i->m168 = 8;
}

extern "C" void fn_801DDDDC(I* i, int a, int b)
{
    if (a == 1 || b == 1)
        i->m168 = 8;
}

extern "C" void fn_801DDDF8(I* i)
{
    i->m168 = 7;
}

extern "C" void fn_801DDE04(I* i)
{
    i->m168 = 7;
}

extern "C" void fn_801DDE10(I* i)
{
    Unk80270BA0_X* p = i->m9C->m0->m660;
    if (p != 0) {
        Unk801DB948_PlSub* s = &p->m4D8;
        if ((unsigned)(s->m70 - 10) <= 7)
            s->m70 = 10;
    }
    i->m168 = 7;
}

extern "C" void fn_801DDE4C(I* i)
{
    fn_801EA03C(i);
    if (fn_8020543C(i->m9C) > 2)
        i->m168 = 8;
}

extern "C" void fn_801DDE90(I* i)
{
    i->m168 = 8;
    fn_801E9E20(i);
    if (fn_8006BDCC(i->m9C->m0->m6F8) == 1)
        fn_801DE7FC(i);
}

extern "C" void fn_801DDEE4(I* i)
{
    fn_801E9BFC(i);
}

extern "C" void fn_801DDF04(I* i)
{
    if (i->m9C->m4->m36C != 0)
        fn_80189300(i->m9C->m4, 0);
    if (fn_8006BE18(i->m9C->m0->m6F8) == 0) {
        int f = i->m9C->m0->m6F8->m14->m1CD0 == 0;
        Vec3 v = fn_801837F4(i->m9C->m0->m6B8, f);
        Unk801DB948_It it;
        fn_8014E09C(&it, i->m9C->m0, 1);
        while (it.m8 != 10) {
            Unk80270BA0_X* p = fn_801A497C(i->m9C->m0, f, it.m8);
            fn_801A656C(i->m9C->m0, p, 0xD);
            p->v3(v);
            p->v8(1);
            fn_8014E108(&it);
        }
        i->m168 = 1;
    }
}

extern "C" void fn_801DE028(I* i)
{
    if (i->m9C->m0->m6F4 == 9) {
        i->m168 = 8;
        fn_801E9E20(i);
        if (i->m9C->m4->m36C != 0)
            fn_80189300(i->m9C->m4, 0);
        Unk801DB948_It it;
        fn_8014E09C(&it, i->m9C->m0, 1);
        while (it.Cur() != 10) {
            fn_801DDADC(i, fn_801A497C(i->m9C->m0, 4, it.Cur()), 1, 0);
            it.Next();
        }
    }
}

extern "C" void fn_801DE0E4(I* i)
{
    if (fn_8033E420(i->m9C->m0->m560) == 0) {
        i->m7B4 = 0;
        fn_801DE430(i);
        fn_801DE5B0(i);
    }
}

extern "C" int fn_801DE138(I* i)
{
    int r = 1;
    switch (i->m168) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 9:
        r = 1;
        break;
    case 7:
        if (i->m9C->m38 != 1) {
            if (fn_80259330(i->m9C->m0->m700->m3B4) != 1 || i->m9C->m70 != 0)
                r = 0;
        }
        break;
    case 8:
        r = 0;
        break;
    }
    return r;
}

extern "C" void fn_801DE1D8(I* i)
{
    fn_801E9E94(i);
}

extern "C" void fn_801DE1F8(I* i)
{
    float t;
    i->m168 = 4;
    t = i->m778 = lbl_805D3B24;
}

extern "C" float fn_801DE21C(I* i)
{
    if (i->m7B4 == 0 || !(i->m7B8 >= lbl_805D3B28)) {
        float t = lbl_805D3B28;
        if (i->m9C->m0->m6CC->m36C == 0)
            t = fn_801E9C08(i);
        i->m7B4 = 1;
        i->m7B8 = t;
    }
    return i->m7B8;
}

extern "C" int fn_801DE2AC(I* i)
{
    int r = 0;
    if (i->m9C->m0->m6CC->m38C != 1) {
        r = 1;
    } else if (i->m7B4 != 0 && !(i->m7B8 < lbl_805D3B2C)) {
        r = 1;
    }
    return r;
}

extern "C" void fn_801DE2F4(I* i)
{
    fn_801EA458(i);
}

/* near-miss: register assignment (this/o swapped), volatile slot and lfsux form differ (~38 slots) */
extern "C" int fn_801DE314(I* i, Unk80270BA0_X* o, int k)
{
    if (fn_801BCA0C(i->m9C->m0->m700->m3BC) == k)
        return 1;
    int found = 0;
    volatile int sp10;
    sp10 = 9;
    int e = sp10;
    for (;;) {
        if (e > 12)
            break;
        Unk801DD660_Tbl* sb = &i->m9C->m2B4;
        Unk801DD660_E2C* en = 0;
        if ((unsigned)(e - 9) <= 3)
            en = &sb->m128[e];
        if (en->m4 == k && en->m24 != 0) {
            found = 1;
            break;
        }
        int c = e;
        int t;
        if (c > 0x15)
            t = c;
        else
            t = c + 1;
        sp10 = t;
        e = sp10;
    }
    if (found == 1) {
        const float eps = lbl_805D3B30;
        const Vec3* v = &lbl_805D6760[k];
        float d2 = (v->x - o->m60.x) * (v->x - o->m60.x) + (v->z - o->m60.z) * (v->z - o->m60.z);
        if (d2 <= eps)
            return 1;
    }
    return 0;
}

extern "C" void fn_801DE430(I* i)
{
    Unk8035B718 buf;
    fn_8035B718(&buf);
    fn_801DE660(i, &buf);
    switch (i->m168) {
    case 1:
        fn_801DE8F4(i, &buf, 0);
        break;
    case 2:
        fn_801DE8F4(i, &buf, 1);
        break;
    case 9:
        fn_801DEA84(i);
        break;
    case 3:
        fn_801DEAEC(i, &buf);
        break;
    case 4:
        fn_801DEF4C(i, &buf);
        break;
    case 5:
        fn_801DEC20(i, &buf);
        break;
    case 6:
        fn_801DED34(i, &buf);
        break;
    case 7:
        fn_801DEE04(i, &buf);
        break;
    case 8:
        fn_801DEE80(i, &buf);
        break;
    }
    Unk8035B718_Assign(&buf, &i->m16C);
}

extern "C" void fn_801DE570(I* i, Unk801DD660_Rec* a, Unk80270BA0_X* b)
{
    Unk8027C728_Goal* g = fn_801E5DF8(i->m9C->m0, (int)b, (int)a);
    if (g != 0)
        fn_8027D33C(g);
}

extern "C" void fn_801DE5B0(I* i)
{
    int k = fn_80235AB8(i->m9C->m0->m700->m3B0) != 0 ? 2 : 1;
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, k);
    while (it.Cur() != 10) {
        Unk80270BA0_X* p = fn_801A497C(i->m9C->m0, 4, it.Cur());
        if (p != 0) {
            Unk801DD660_Rec* b = i->m16C.m0;
            fn_801DE570(i, b + it.Cur(), p);
        }
        it.Next();
    }
}

extern "C" void fn_801DE7FC(I* i)
{
    Unk8035B718 buf;
    fn_8035B718(&buf);
    fn_801DE660(i, &buf);
    fn_801DE864(i, &buf);
    Unk8035B718_Assign(&buf, &i->m16C);
    fn_801DE5B0(i);
}

extern "C" void fn_801DE864(I* i, Unk8035B718* buf)
{
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 1);
    while (it.Cur() != 10) {
        Unk801DD660_Rec* rec = &buf->m0[it.Cur()];
        Unk80270BA0_X* p = fn_801A497C(i->m9C->m0, 4, it.Cur());
        if (p != 0)
            fn_801DF134(i, rec, p);
        it.Next();
    }
}

extern "C" void fn_801DE8F4(I* i, Unk8035B718* t, int mode)
{
    fn_801E9AC4(i);
    int allok = 1;
    fn_801DD420(&i->m134);
    int first = 1;
    fn_801E8068(i);
    fn_801E81C8(i);
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 1);
    Unk801DB948_It* ip;
    if (it.m8 != 10) {
        do {
            ip = &it;
            Unk801DD660_Rec* rec = &t->m0[ip->m8];
            Unk80270BA0_X* p = fn_801A497C(i->m9C->m0, 4, ip->m8);
            if (p != 0) {
                fn_8025004C(&p->m4D8);
                p->m710 = p->m60;
                p->v8(0);
                int r = fn_801DF280(i, rec, p) == 0;
                int a = 1;
                if (allok == 0)
                    a = 0;
                int b = 1;
                if (r == 0)
                    b = 0;
                allok = a & b;
                if (p->m460 == 0)
                    first = r;
            }
            fn_8014E108(&it);
        } while (ip->m8 != 10);
    }
    if (mode == 1) {
        if (first == 1 && fn_80235AB8(i->m9C->m0->m700->m3B0) == 0)
            fn_80235AC4(i->m9C->m0->m700->m3B0);
        if (allok == 1)
            i->m168 = 3;
    }
}

extern "C" void fn_801DEA84(I* i)
{
    fn_801E9AC4(i);
    fn_801DD420(&i->m134);
    fn_801E8068(i);
    fn_801E81C8(i);
    if (i->m9C->m0->m71C->m68 == 2)
        fn_801DB948(i->m9C->m0->m71C);
    i->m168 = 7;
}

extern "C" void fn_801DEAEC(I* i, Unk8035B718* t)
{
    Unk801DB948_It it;
    fn_8014E09C(&it, i->m9C->m0, 1);
    while (it.Cur() != 10) {
        Unk801DD660_Rec* rec = &t->m0[it.Cur()];
        Unk80270BA0_X* p = fn_801A497C(i->m9C->m0, 4, it.Cur());
        if (p != 0)
            fn_801DF280(i, rec, p);
        it.Next();
    }
    if (fn_801A6DB8(i->m9C->m0)->m4 == 1) {
        Unk801DB948_Obj* o = i->m9C->m0->m6CC;
        Unk80270BA0_X* p0 = fn_801A497C(i->m9C->m0, 4, 0);
        if (o->m36C != p0) {
            o->v3(p0->m60);
            fn_80189300(o, p0);
            Unk801DD660* h = i->m9C->m0->m700->m3B8->m4;
            h->mAC.m0 = -1;
            h->mAC.m4 = -1;
        }
        fn_801E0BE0(i);
    }
    fn_80235AC4(i->m9C->m0->m700->m3B0);
}
