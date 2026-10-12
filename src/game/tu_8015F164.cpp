/*
 * Game code, .text 0x8015F164-0x80163390 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8015F164.h"

extern "C" void fn_80326ED4(Unk801527C8_Sub* s, float* a, float* b);

extern "C" int fn_803270C4(Unk801527C8_Sub* s, int id, int n, float t);
struct V2s80161924 { float x; float y; };
inline int Chk80161924(Unk801527C8_Sub* s, int id, int n, float t) { return fn_803270C4(s, id, n, t) != 0; }
extern "C" int fn_80176FD4__FP13Unk8017706C_Ti(void* t, int i);
extern "C" void fn_801615C0(Unk80159F28* self, int i);
extern "C" Unk8015ABB8_Rec fn_8015AE08(Unk80159F28* self, int a);
extern "C" void fn_8015FC00(Unk80159F28* self, Unk8015ABB8_Rec r, Unk8016D9A0_Rec* rec);
int fn_80166440(void* self, int v);
extern "C" void fn_8015F918(Unk80159F28* self, int a);
int fn_801A4F40(Unk8019F8C0_Owner* o);
int fn_803EE348(int a);
extern "C" int fn_80166BD0(Unk80159F28* self);
void fn_80303CA0(const char* s, float a, float b, float c, ...);
extern "C" int fn_8017706C__FP13Unk8017706C_Ti(void* t, int i);
extern "C" int fn_8025416C__FP13Unk8024EF40_Wi(void* w, int i);
extern "C" unsigned fn_8014D8AC(void* rng, int max, const char* file, int line);
extern const char lbl_805C8C20[];
inline int Pick80162FE4(int f)
{
    int t = 0x29;
    if (f != 0) {
        t = 0;
    }
    return t;
}
extern "C" int fn_80326C20(Unk801527C8_Sub* s);
inline int Chance2_801609EC(void* rng, float k)
{
    const char* nm = lbl_805C8C20;
    unsigned r = fn_8014D8AC(rng, 1000000, nm, 0xAC8);
    return (float)r * k * 0.000001f >= 0.85f;
}
struct Ev8015F348 { int m0; float m4; int m8; int mC; int m10; int m14; };
inline int IsValidId(int id) { return id != 0xC7; }
inline int Has8015F348(int v, int bit) { return (v & bit) != 0; }
int fn_80324D74(void* e, int i);
enum E1_8015F508 { E1_Neg = -1, E1_9 = 9, E1_12 = 12 };
inline int Chance80162C28(void* rng, float k)
{
    const char* nm = lbl_805C8C20;
    unsigned r = fn_8014D8AC(rng, 1000000, nm, 0xDF9);
    return (float)r * k * 0.000001f < 0.7f;
}
struct Obj3AC8015F164 { char pad0[0x14C]; int m14C; };
struct Obj6B8Owner8015F164 { char pad0[0x6B8]; void* m6B8; };
class Obj708Base8015F164 {
public:
    char pad0[0x98];
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual int s22();
};
class Obj708_8015F164 : public Obj708Base8015F164 {
public:
    char pad9C[0x708 - 0x9C];
    int m708;
};
extern "C" Obj708_8015F164* fn_801C1638(Unk801527C8_Actor* a, int i);
int fn_8018240C(void* a, int b);
inline int IsValid(const Unk80326F44_Out& o)
{
    return o.m0 != 0xC7;
}

int Unk80159F28::fn_8015F164(Unk8015F164_Evt* e) /* 8015F164 */
{
    const float c = 0.6f;
    Unk80326F44_Out a = mC->m50.fn_80326F44(0x39, 0, e->m4);
    if (IsValid(a)) {
        if (a.m4 - e->m4 < c) {
            return 1;
        }
    }
    return 0;
}

Unk80326F44_Out Unk80159F28::fn_8015F1F4(Unk8015F164_Evt* e) /* 8015F1F4 */
{
    Unk801527C8_Sub* s = &mC->m50;
    const float c = 0.6f;
    int id;
    switch (e->mC) {
    case 0:
        id = 0xC0;
        break;
    case 1:
        id = 0xC1;
        break;
    case 2:
        id = 0xC2;
        break;
    case 3:
        id = 0xC3;
        break;
    default:
        return lbl_805EBA10;
    }
    Unk80326F44_Out a = s->fn_80326F44(id, 1, e->m4 - c);
    if (IsValid(a)) {
        if (!(a.m4 - e->m4 >= c)) {
            return a;
        }
    }
    return lbl_805EBA10;
}

extern "C" int fn_8015F348(Unk80159F28* self, Ev8015F348* e) /* 8015F348 */
{
    if (IsValidId(e->m0)) {
        int fl = e->m14;
        if (Has8015F348(fl, 4) || Has8015F348(fl, 0x200) || Has8015F348(fl, 8) || Has8015F348(fl, 0x10) || Has8015F348(fl, 0x80)) {
            return 1;
        }
        int v = 0;
        {
            Unk80326F44_Out a = self->fn_8015F1F4((Unk8015F164_Evt*)e);
            if (IsValid(a) || self->fn_8015F164((Unk8015F164_Evt*)e) != 0) {
                v = 1;
            }
        }
        if (v != 0) {
            return 1;
        }
        if (fn_80324D74(e, 0) != 0 || Has8015F348(e->m14, 0x200)) {
            Unk801527C8_Sub* s = &self->mC->m50;
            Unk80326F44_Out b = s->fn_80326F44(0xAD, 1, -1.0f);
            if (!(e->m4 >= b.m4)) {
                return 1;
            }
            if (Chk80161924(s, 0x7F, 1, e->m4) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

extern "C" Unk80326F44_Out fn_8015F508(Unk80159F28* self, Unk8015F164_Evt* e) /* 8015F508 */
{
    Unk801527C8_Sub* s = &self->mC->m50;
    int id1 = 0xC7;
    switch ((E1_8015F508)e->m8) {
    case 9:
        id1 = 0xBC;
        break;
    case 10:
        id1 = 0xBD;
        break;
    case 11:
        id1 = 0xBE;
        break;
    case 12:
        id1 = 0xBF;
        break;
    }
    int id2 = 0xC7;
    switch (e->mC) {
    case 0:
        break;
    case 1:
        id2 = 0xC0;
        break;
    case 2:
        id2 = 0xC1;
        break;
    case 3:
        id2 = 0xC2;
        break;
    }
    Unk80326F44_Out a = lbl_805EBA10;
    if (id2 != 0xC7) {
        a = s->fn_80326FC4(id2, 1, 2000000.0f);
        while (IsValid(a) && a.m8 != e->m8) {
            a = s->fn_80326FC4(id2, 1, a.m4);
        }
    }
    if (IsValid(a)) {
        return a;
    }
    if (id1 != 0xC7) {
        return s->fn_80326F44(id1, 1, -1.0f);
    }
    return lbl_805EBA10;
}

int Unk80159F28::fn_8015F744(Unk8015F744_Evt* e) /* 8015F744 */
{
    int k = e->m0 == 0x39;
    switch (e->mC) {
    case 3:
        return k ? 0x3F : 0x3E;
    case 0:
        return k ? 0x35 : 0x34;
    case 1:
        if (!k) {
            return 0x36;
        }
    default:
        return 0x37;
    case 2:
        return k ? 0x3B : 0x3A;
    }
}

int Unk80159F28::fn_8015F7D0(Unk8015F744_Evt* e) /* 8015F7D0 */
{
    int k = e->m0 == 0x5F;
    switch (e->mC) {
    case 3:
        return k ? 0x40 : 0x41;
    case 1:
        if (!k) {
            return 0x39;
        }
    default:
        return 0x38;
    case 2:
        return k ? 0x3C : 0x3D;
    }
}

int Unk80159F28::fn_8015F840() /* 8015F840 */
{
    return fn_801A4B34(mC)->fn_v4();
}

void Unk80159F28::fn_8015F87C() /* 8015F87C */
{
    Unk801527C8_Actor* a = mC;
    if (!((float)*(unsigned int*)&a->m4C * 0.016666668f > 21600.0f)) {
        Unk801527C8_Mgr* m = a->m6F8;
        int r = m->m10->m13C;
        if (m->fn_8006BE18() != 0 && r != 0) {
            r = 4;
        }
        ::fn_8015F918(this, r);
    }
}

extern "C" void fn_8015F918(Unk80159F28* self, int a) /* 8015F918 */
{
    Unk8015ABB8_Rec r = fn_8015AE08(self, a);
    if (r.w[0] != 0 && fn_80166440(self, r.w[0]) == 0) {
        RecObj8015F164 rec;
        fn_8015FC00(self, r, (Unk8016D9A0_Rec*)&rec);
        fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    }
}

void Unk80159F28::fn_8015FB08(int a, int b, Unk8015FB08_Rec rec) /* 8015FB08 */
{
    fn_80157514(a, b, 0, rec.m0, 0, rec.m4);
}

void Unk80159F28::fn_8015FB84(int a, int b, Unk8015FB08_Rec rec) /* 8015FB84 */
{
    fn_80157514(a, b, 0, 0, 0, rec.m4);
}

extern "C" void fn_80160640(Unk80159F28* self) /* 80160640 */
{
    if (fn_803EE348(0) > 0x1B7FF) {
        int r = fn_80166BD0(self);
        fn_80303CA0("End of game intensity %d", 4.0f, 0.4f, 0.4f, r + 1);
        if (r != 3) {
            int f = 0;
            if (r != 2) {
                if (r <= 2) {
                    f = r >= 0;
                }
            }
            RecObj8015F164 rec;
            if (f != 0) {
                self->fn_80157514(0x53, (int)&rec, 1, 4, 0, lbl_8068B828);
            } else {
                self->fn_80157514(0x54, (int)&rec, 1, 4, 0, lbl_8068B828);
            }
            self->fn_80157514(8, (int)&rec, 1, 0x15, 1, lbl_8068B828);
            self->fn_80157514(0x39, (int)&rec, 1, 4, 1, lbl_8068B828);
            fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
            self->m48 = 1;
        }
    }
}

/* near-miss (99.3%): instruction stream identical; retail keeps idx/sa/ta in r8/r7/r6 across the two sum loops, here r10/r8/r7 (same allocation issue as fn_80160E64; 11 declaration orders and 3 counter forms tried) */
extern "C" void fn_801609EC(Unk80159F28* self) /* 801609EC */
{
    self->m48 = 0;
    Unk801527C8_Sub* s = &self->mC->m50;
    if (fn_80326C20(s) != 0) {
        V2s80161924 v;
        fn_80326ED4(s, &v.x, &v.y);
        Unk80326F44_Out a = s->fn_80326F44(0xB1, 1, -1.0f);
        if (IsValid(a)) {
            Obj708_8015F164* o = (Obj708_8015F164*)fn_801A4B34(self->mC);
            if (o != 0) {
                Unk801527C8_Mgr* m = self->mC->m6F8;
                if (m->fn_8006BE18() == 1) {
                    fn_80160640(self);
                } else {
                    RecObj8015F164 rec;
                    int id = 0x52;
                    int idx = o->m708;
                    Unk801527C8_Team* ta = &m->m14->m0[idx];
                    int sa = 0;
                    for (int i = 0; i < 128; i++) {
                        sa += ta->m1B4[(unsigned char)i];
                    }
                    int z = idx == 0;
                    Unk801527C8_Team* tb = &m->m14->m0[z];
                    int sb = 0;
                    for (int i = 0; i < 128; i++) {
                        sb += tb->m1B4[(unsigned char)i];
                    }
                    if (ta->m198 == 0xB87DA69) {
                        if (sa == sb || sa == sb + 1) {
                            id = 0x51;
                        }
                    }
                    switch (fn_8025416C__FP13Unk8024EF40_Wi((char*)o + 0x588, 0)) {
                    case 0x153:
                        id = 0x4D;
                        break;
                    case 0x294:
                        id = 0x4F;
                        break;
                    case 0x2D4:
                        id = 0x4E;
                        break;
                    case 0x340:
                        id = 0x4C;
                        break;
                    case 0x4D7:
                        id = 0x50;
                        break;
                    }
                    int roll = 1;
                    if (id == 0x52) {
                        roll = Chance2_801609EC(self->mC->m554, 1.0f);
                    }
                    if (roll != 0) {
                        self->fn_80157514(id, (int)&rec, 1, 0, 0, lbl_8068B828);
                        fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
                    }
                }
            }
        }
    }
}

int Unk80159F28::fn_80160DEC() /* 80160DEC */
{
    int r = fn_80160E64();
    if (r > 2) {
        return 0xD;
    }
    if (r == 2) {
        return 0xB;
    }
    return 9;
}

int Unk80159F28::fn_80160E28() /* 80160E28 */
{
    int r = fn_80160E64();
    if (r > 2) {
        return 0xC;
    }
    if (r == 2) {
        return 0xA;
    }
    return 8;
}

/* near-miss: same code except the register allocation of mC/the sums (retail keeps mC in r7, c in r5); 6 source orderings tried */
int Unk80159F28::fn_80160E64() /* 80160E64 */
{
    Unk801527C8_Teams* t0 = mC->m6F8->m14;
    int c = t0->m1CC8;
    int a = 0;
    for (int i = 0; i < 128; i++) {
        a += t0->m0[0].m1B4[(unsigned char)i];
    }
    int b = 0;
    Unk801527C8_Team* t1 = &mC->m6F8->m14->m0[1];
    for (int i = 0; i < 128; i++) {
        b += t1->m1B4[(unsigned char)i];
    }
    int d = __builtin_abs(a - b);
    if (c > 7 && d <= 1) {
        return 3;
    }
    if (c > 5 && d <= 1) {
        return 2;
    }
    return 1;
}

extern "C" void fn_801615C0(Unk80159F28* self, int which) /* 801615C0 */
{
    if ((unsigned)which <= 1) {
        int g = fn_8017706C__FP13Unk8017706C_Ti(self->mC->m700->m3A8, which);
        RecObj8015F164 rec;
        if (which == 1) {
            if (g == 1) {
                self->fn_80157514(1, (int)&rec, 1, 0xB, 0, lbl_8068B828);
            } else {
                self->fn_80157514(2, (int)&rec, 1, 0xB, 0, lbl_8068B828);
            }
        } else {
            if (g == 1) {
                self->fn_80157514(3, (int)&rec, 1, 0xC, 0, lbl_8068B828);
            } else {
                self->fn_80157514(4, (int)&rec, 1, 0xC, 0, lbl_8068B828);
            }
        }
        fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    }
}

extern "C" void fn_80161924(Unk80159F28* self) /* 80161924 */
{
    int r = self->mC->m6F8->fn_8006BE18();
    if (r == 0) {
        Unk801527C8_Sub* s = &self->mC->m50;
        V2s80161924 v;
        fn_80326ED4(s, &v.x, &v.y);
        int ok = Chk80161924(s, 0x42, 1, -1.0f);
        if (ok != 0 && self->mC->m6F8->m14->m1CC9 != 3) {
            if (self->m2C != 0) {
                self->m2C = 0;
                if (fn_80176FD4__FP13Unk8017706C_Ti(self->mC->m700->m3A8, 1) != 0) {
                    fn_801615C0(self, 1);
                }
            } else if (self->m28 != 0) {
                self->m28 = 0;
                if (fn_80176FD4__FP13Unk8017706C_Ti(self->mC->m700->m3A8, 0) != 0) {
                    fn_801615C0(self, 0);
                }
            }
        }
    }
}

void Unk80159F28::fn_80161A34() /* 80161A34 */
{
    for (int i = 0; i < 7; i++) {
        m30C[i] = 0;
    }
    m328 = 0;
}

int* Unk80159F28::fn_80161A5C(int a, int b) /* 80161A5C */
{
    return (int*)((char*)this + 0x50 + a * 0x64 + b * 4);
}

extern "C" int fn_80161FBC(Unk80159F28* self) /* 80161FBC */
{
    if (self->m10 != 0 || self->m4C == -1) {
        return 0;
    }
    Unk801527C8_Actor* ac = self->mC;
    if (ac->m6F8->fn_8006BE18() != 0) {
        return 0;
    }
    Unk801527C8_Sub* s = &self->mC->m50;
    V2s80161924 v;
    fn_80326ED4(s, &v.x, &v.y);
    int ok = Chk80161924(s, 0x42, 1, -1.0f);
    if (ok == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    int tbl[7] = { 13, 14, 15, 16, 17, 18, 19 };
    self->fn_80157514(0xF, (int)&rec, 0, tbl[self->m4C], 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" void fn_80162264(Unk80159F28* self) /* 80162264 */
{
    self->m330 = -1.0f;
    RecObj8015F164 rec;
    ElemView8015F164* e = (ElemView8015F164*)&rec;
    for (int j = 0; j < 8; j++, e++) {
        e->name[0] = 0;
        e->m3C = 0;
        e->m40 = 0;
        e->m44 = 0;
        e->m48 = 0;
        e->m4C = 0;
        e->m50 = lbl_805EBA10;
        e->m68 = lbl_805EBA10;
        e->m80 = lbl_805EBA10;
        e->m98 = 0;
        e->m9C = 0xAE;
    }
    if (self->mC->m700->m3BC->m24 != 0) {
        fn_801A4F40((Unk8019F8C0_Owner*)self->mC);
    } else {
        fn_80169BF8((Unk8016D9A0_Rec*)&rec, "walk_live", 0, 0, 0, 0, lbl_8068B828, 0);
    }
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    if (fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->m3D40 != 0) {
        fn_801A4F40((Unk8019F8C0_Owner*)self->mC);
    }
}

int Unk80159F28::fn_80162534() /* 80162534 */
{
    if (fn_801A6D84(mC, 1)->m3D90 != 0 || fn_801A6D84(mC, 5)->m3D90 != 0) {
        return 0;
    }
    return 1;
}

int Unk80159F28::fn_80162598() /* 80162598 */
{
    if (fn_801A6D84(mC, 1)->m3D90 != 0 || fn_801A6D84(mC, 5)->m3D90 != 0) {
        return 0;
    }
    return 1;
}

int Unk80159F28::fn_801625FC() /* 801625FC */
{
    int r = 0;
    if (fn_80162664() != 0) {
        r = 1;
    }
    if (fn_80162850() != 0) {
        r = 1;
    }
    if (fn_80162A3C() != 0) {
        r = 1;
    }
    return r;
}

extern "C" int fn_80162664(Unk80159F28* self) /* 80162664 */
{
    if (self->m1C == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    self->fn_80157514(0x63, (int)&rec, 1, 0x26, 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" int fn_80162850(Unk80159F28* self) /* 80162850 */
{
    if (self->m20 == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    self->fn_80157514(0x64, (int)&rec, 1, 0x27, 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" int fn_80162A3C(Unk80159F28* self) /* 80162A3C */
{
    if (self->m24 == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    self->fn_80157514(0x65, (int)&rec, 1, 0x28, 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" int fn_80162C28(Unk80159F28* self) /* 80162C28 */
{
    if (self->m10 == 0 || self->m38 != 0) {
        return 0;
    }
    RecObj8015F164 rec;
    ElemView8015F164* e = (ElemView8015F164*)&rec;
    for (int j = 0; j < 8; j++, e++) {
        e->name[0] = 0;
        e->m3C = 0;
        e->m40 = 0;
        e->m44 = 0;
        e->m48 = 0;
        e->m4C = 0;
        e->m50 = lbl_805EBA10;
        e->m68 = lbl_805EBA10;
        e->m80 = lbl_805EBA10;
        e->m98 = 0;
        e->m9C = 0xAE;
    }
    int flag = 0;
    Unk80189300* o = fn_801A4B34(self->mC);
    if (o != 0 && fn_8025416C__FP13Unk8024EF40_Wi((char*)o + 0x588, 0x21) != 0) {
        flag = Chance80162C28(self->mC->m554, 1.0f);
    }
    if (flag != 0) {
        self->fn_80157514(0x4B, (int)&rec, 1, 1, 0, lbl_8068B828);
    } else {
        self->fn_80157514(0x4A, (int)&rec, 1, 1, 0, lbl_8068B828);
    }
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}

extern "C" int fn_80162FE4(Unk80159F28* self) /* 80162FE4 */
{
    if (self->m14 == 0) {
        return 0;
    }
    RecObj8015F164 rec;
    ElemView8015F164* e = (ElemView8015F164*)&rec;
    for (int j = 0; j < 8; j++, e++) {
        e->name[0] = 0;
        e->m3C = 0;
        e->m40 = 0;
        e->m44 = 0;
        e->m48 = 0;
        e->m4C = 0;
        e->m50 = lbl_805EBA10;
        e->m68 = lbl_805EBA10;
        e->m80 = lbl_805EBA10;
        e->m98 = 0;
        e->m9C = 0xAE;
    }
    int f = 0;
    if (((Obj3AC8015F164*)self->mC->m700->m3AC)->m14C != 0 && self->m18 != 0) {
        f = 1;
    }
    if (f != 0) {
        Obj708_8015F164* o = fn_801C1638(self->mC, 0);
        int v = o->m708;
        int w = o->s22();
        int id;
        if (fn_8018240C(((Obj6B8Owner8015F164*)self->mC)->m6B8, v) != 0) {
            id = w != 0 ? 0x69 : 0x6A;
        } else {
            id = w != 0 ? 0x67 : 0x68;
        }
        self->fn_80157514(id, (int)&rec, 1, 0x29, v, lbl_8068B828);
    }
    self->fn_80157514(0x66, (int)&rec, 1, Pick80162FE4(f), 0, lbl_8068B828);
    fn_801A6D84((Unk8019F8C0_Owner*)self->mC, 1)->fn_8016A7A8((Unk8016D9A0_Rec*)&rec);
    return 1;
}
