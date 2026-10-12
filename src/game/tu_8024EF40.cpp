/*
 * Game code, .text 0x8024EF40-0x802520F8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"
#include "game/chooser.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_W W;

inline Unk8024EF40_P* Unk8024F810_At(Unk8024EF40_Q* q, unsigned t)
{
    return t <= 12 ? q->m65C[t] : 0;
}

/* Object of fn_8024EF40: float at +0x98, owner player at +0xA0. */
struct Unk8024EF40_Obj {
    char pad0[0x98];
    float m98;
    char pad9C[4];
    P* mA0;
};

inline float Unk80251000_Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

struct Unk8024F048_Obj {
    char pad0[0xA0];
    P* mA0;
};
struct Unk8024F048_Tbl {
    float v[4];
};
struct Unk80087A58_O;
extern Unk8024F048_Tbl lbl_805D9794;
extern float lbl_8062030C;
float fn_80088EA4(Unk80087A58_O* o);
int fn_802536D0(P* x);

/* Views for fn_8024FE4C: the world's context at +0x700 (table object at +0x3A4) and the player's +0x56C id. */
struct Unk8024FE4C_Ctx {
    char pad0[0x3A4];
    char* m3A4;
};
struct Unk8024FE4C_Q {
    char pad0[0x700];
    Unk8024FE4C_Ctx* m700;
};
struct Unk8024FE4C_P {
    char pad0[0x56C];
    int m56C;
};

/* Per-class weight table: 0x4C-byte rows of ints starting at +0x28 / +0x34 (fn_8024F40C, fn_8024F4AC). */
struct Unk8024F40C_Mgr {
    char pad0[0x28];
    int m28[8][19];
};
struct Unk8024F4AC_Mgr {
    char pad0[0x34];
    int m34[8][19];
};
struct Unk8024F40C_Mid {
    char pad0[0xC];
    void* mC;
};
struct Unk8024F40C_Sub {
    char pad0[0xC];
    Unk8024F40C_Mid* mC;
};
extern float fn_80088E74(void* o);

/* Views of the world's m6F8 record used by fn_80250AC4: +0xC object (flag word at +0x84), +0x10 table (kind at +0x20),
   +0x14 per-player records (byte at +0x234 of the 0xE64-byte entry). */
struct Unk80250AC4_C {
    char pad0[0x84];
    int m84;
};
struct Unk80250AC4_K {
    char pad0[0x20];
    int m20;
};
struct Unk80250AC4_S {
    char pad0[0xC];
    Unk80250AC4_C* mC;
    Unk80250AC4_K* m10;
    Unk8024EF40_Ent* m14;
};

extern "C++" {
extern char lbl_805D990C[];
int fn_80250AC4(P* x);
int fn_80250A90(P* x, int k);
float fn_80251000(P* x, int k);
void* fn_8023CB44(P* x);
void fn_80250B28(P* x, int k);
extern float lbl_8061DC08;
extern int lbl_80691CAC;
extern float lbl_8061DC0C;
extern int lbl_80691CB0;
extern float lbl_8061DC10;
extern int lbl_80691CB4;
extern float lbl_8061DC14;
extern int lbl_80691CB8;
extern float lbl_8061DC18;
extern int lbl_80691CBC;
extern float lbl_8061DC1C;
extern int lbl_80691CC0;
extern float lbl_8061DC2C;
extern int lbl_80691CE0;
extern float lbl_8061DC3C;
extern int lbl_80691CF0;
extern int lbl_8061DC54;

inline float G_8061DC08(void* p) { return lbl_8061DC08; }

inline float G_8061DC0C(void* p) { return lbl_8061DC0C; }

inline float G_8061DC10(void* p) { return lbl_8061DC10; }

inline float G_8061DC14(void* p) { return lbl_8061DC14; }

inline float G_8061DC18(void* p) { return lbl_8061DC18; }

inline float G_8061DC1C(void* p) { return lbl_8061DC1C; }

inline float G_8061DC2C(void* p) { return lbl_8061DC2C; }

inline float G_8061DC3C(void* p) { return lbl_8061DC3C; }

extern int lbl_8061D51C[];
extern int lbl_8061D4DC[];
extern char lbl_8068CD00[];
extern char lbl_80660F50[];
extern char lbl_80660F38[];
extern char lbl_80660F20[];
extern char lbl_80660F08[];
void fn_8033CD74(void* p);
int fn_8017EEB0(void* p, int a, int b);
struct Unk8024F6F4_C {
    const void* m0;
    Unk8024F6F4_C();
};
struct Unk8024F708_C {
    const void* m0;
    Unk8024F708_C();
};
struct Unk8024F71C_C {
    const void* m0;
    Unk8024F71C_C();
};
struct Unk8024F730_C {
    const void* m0;
    Unk8024F730_C();
};
struct Unk8024FD00_S {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Unk80250244_S {
    int m0;
    int m4;
    Unk8024FD00_S m8[4];
    const void* m58;
    float m5C;
    float m60;
    float m64;
    float m68;
    float m6C;
    int m70;
    float m74;
    int m78;
    int m7C;
    float m80;
    int m84;
    int m88;
    float m8C;
    char pad90[4];
    int m94;
    int m98;
    int m9C;
    float mA0;
    P* mA4;
};
float fn_8025454C(void* p, int idx);
int fn_801BA4AC(int a);
void fn_8024FD00(Unk8024FD00_S* self);
float fn_802503E8(Unk80250244_S* self, float a, float b, float c);
void fn_8023CB08(P* x);
int fn_8024FD38(Unk8024FD00_S* e, int k);
void fn_8024FE4C(Unk8024FD00_S* e, int k);
void fn_8024FCF8(void** self, void* a);
void fn_8024F7C8(Unk80250244_S* self);
void fn_80250244(Unk80250244_S* self);
void fn_8025068C(Unk80250244_S* self, int a);
void fn_802456C8(P* x, int a, int b, float f);
int fn_8026D6D8(P* x, int a);
extern const char lbl_805D97F4[];
extern const char lbl_805D97F8[];
extern const char lbl_805D9804[];
extern const char lbl_805D9814[];
extern char lbl_80660F68[];
extern char lbl_806614E0[];
extern int lbl_8068CB64;
extern float lbl_8068CB60;
extern float lbl_8061D630;
extern float lbl_8061DC50;
extern "C" void fn_8037B7E4(Unk8037B3E8* self, const char* name);
}
inline void* operator new(unsigned int, void* p) { return p; }

extern int lbl_80620308;
extern float lbl_80620314;
extern int fn_801A2034(Unk8024EF40_Q* q, int k);
extern float fn_8024D0F8(P* x, int k);
extern "C" float fn_8024EF40(Unk8024EF40_Obj* self, Unk8024EF40_Q* q, int k)
{
    float s = 0.0f;
    if (lbl_80620308 != 0) {
        s = lbl_80620314;
    } else {
        s = self->m98;
        float w;
        if (fn_801A2034(q, k) == -1)
            w = fn_8024D0F8(self->mA0, 0xE);
        else
            w = fn_8024D0F8(self->mA0, 0xD);
        w = Unk80251000_Lerp(0.8f, w, 1.2f);
        s = s * w;
    }
    s = !(s > 1.0f) ? (s >? 0.0f) : 1.0f;
    return s;
}

/* near-miss (98.2%): 4 slots; retail stores word 0 of the table copy (stw r11,24(r1)) before loading the other three words */
extern "C" float fn_8024F048(Unk8024F048_Obj* self, int i, Unk8024EF40_Q* q, int k, int flag)
{
    float s = 0.0f;
    if (lbl_80620308 != 0)
        s = lbl_8062030C;
    else
        s = *(float*)((char*)self + i * 0x4C);
    float m = 1.0f;
    if (flag == 0) {
        float w;
        if (fn_801A2034(q, k) == -1) {
            w = fn_8024D0F8(self->mA0, 0xC);
            Unk8024F048_Tbl t = lbl_805D9794;
            w += t.v[fn_802536D0(self->mA0)];
        } else {
            w = fn_8024D0F8(self->mA0, 0xB);
        }
        w = Unk80251000_Lerp(0.8f, w, 1.2f);
        s = s * w;
        m = fn_80088EA4((Unk80087A58_O*)((Unk8024F40C_Sub*)q->m6F8)->mC->mC);
        m = !(m > 1.25f) ? (m >? 1.0f) : 1.25f;
        s = s * m;
    }
    s = !(s > 1.0f) ? (s >? 0.0f) : 1.0f;
    return s;
}

int fn_8024F40C(Unk8024F40C_Mgr* self, int a, Unk8024EF40_Q* q, int k)
{
    Unk8024F40C_Mid* m = ((Unk8024F40C_Sub*)q->m6F8)->mC;
    float f = 1.0f - fn_80088E74(m->mC);
    return (int)((float)self->m28[a][k] * f);
}

int fn_8024F4AC(Unk8024F4AC_Mgr* self, int a, Unk8024EF40_Q* q, int k)
{
    Unk8024F40C_Mid* m = ((Unk8024F40C_Sub*)q->m6F8)->mC;
    float f = 1.0f - fn_80088E74(m->mC);
    return (int)((float)self->m34[a][k] * f);
}

int fn_8024F54C(int k)
{
    int r = 0;
    switch (k) {
    case 1:
    case 2:
    case 3:
        r = 2;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = 1;
        break;
    case 8:
    case 9:
        r = 0;
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        r = 2;
        break;
    case 15:
        r = 0;
        break;
    }
    return r;
}

int fn_8024F59C(int x)
{
    if (x <= 15) {
        if (x < 0)
            x = 0;
    } else {
        x = 15;
    }
    return lbl_8061D51C[x];
}

int fn_8024F5CC(int x)
{
    if (x <= 15) {
        if (x < 0)
            x = 0;
    } else {
        x = 15;
    }
    return lbl_8061D4DC[x];
}

extern "C" void* fn_8024F5FC(void* p)
{
    new (p) Unk8037B3E8(0x4DACE415U);
    *(const void**)p = lbl_80660F68;
    return p;
}

void fn_8024F640(Unk8037B3E8* self)
{
    fn_8037B7E4(self, lbl_805D97F4);
    self->fn_8037B728(lbl_805D97F8, lbl_805D9804, lbl_8068CD00, (int)lbl_805D9814);
}

extern "C" void* fn_8024F5FC(void* p);

extern int lbl_806EF9B4;

extern "C" void* fn_8024F69C()
{
    return fn_8024F5FC(operator new(0x4, lbl_806EF9B4));
}

void fn_8024F6CC()
{
    fn_8033CD74(lbl_8068CD00);
}

Unk8024F6F4_C::Unk8024F6F4_C()
{
    m0 = lbl_80660F50;
}

Unk8024F708_C::Unk8024F708_C()
{
    m0 = lbl_80660F38;
}

Unk8024F71C_C::Unk8024F71C_C()
{
    m0 = lbl_80660F20;
}

Unk8024F730_C::Unk8024F730_C()
{
    m0 = lbl_80660F08;
}

Unk80250244_S* fn_8024F744(Unk80250244_S* self, int a)
{
    self->m0 = a;
    self->m58 = lbl_806614E0;
    Unk8024FD00_S* e = self->m8;
    int k = 3;
    do {
        fn_8024FD00(e);
        e++;
    } while (k-- != 0);
    for (int j = 0; j < 4; j++)
        fn_8024FCF8((void**)&self->m8[j], self);
    fn_8024F7C8(self);
    return self;
}

void fn_8024F7C8(Unk80250244_S* self)
{
    self->m4 = 0;
    for (int i = 0; i < 4; i++)
        fn_8024FD00(&self->m8[i]);
}

extern void fn_801D865C(char* a);
extern void fn_8024FAE0(Unk80250244_S* self, int arg);
extern void fn_8024FD1C(Unk8024FD00_S* self, int a, int b);
extern int fn_8035E318(A* a);
void fn_8024F810(Unk80250244_S* self, int arg, int unused, int slot, int mode)
{
    if (self->m4 == 0) {
        fn_801D865C(((Unk8024FE4C_Ctx*)((P*)self->m0)->m44C->m700)->m3A4 + 0xE0);
        if (*(int*)(((Unk8024FE4C_Ctx*)((P*)self->m0)->m44C->m700)->m3A4 + 0xF8) != 0) {
            fn_8024FAE0(self, arg);
            return;
        }
        int i = 0;
        do {
            if (i + 9 == slot) {
                P* p = Unk8024F810_At(((P*)self->m0)->m44C, slot);
                if (mode == 1)
                    fn_8024FD1C(&self->m8[i], (int)p, fn_8035E318(&p->m58C));
                else
                    fn_8024FD1C(&self->m8[i], (int)p, p->m58C.m38);
                self->m4 = arg;
            } else {
                fn_8024FD00(&self->m8[i]);
            }
            i++;
        } while (i <= 3);
    }
}

extern int fn_80255028(A* a);
extern "C" void fn_8024FBEC(Unk80250244_S* self, int k)
{
    int f = 0;
    for (int i = 0; i < 4; i++) {
        int r = fn_8024FD38(&self->m8[i], k);
        f = (f | (r != 0)) != 0;
    }
    if (f == 0)
        self->m4 = f;
}

void fn_8024FC74(Unk80250244_S* self)
{
    fn_8024F7C8(self);
}

/* near-miss: loop shape matches; retail keeps the cursor in r3 and the copy in r9 (ours the reverse), 6 slots */
extern "C" void fn_8024FC94(Unk80250244_S* self)
{
    Unk8024FD00_S* e = self->m8;
    for (int i = 0; i <= 3; i++) {
        Unk8024FD00_S* c = e++;
        if (c->m4 == 2) {
            fn_8024FE4C(c, self->m4);
            fn_8024F7C8(self);
            break;
        }
    }
}

void fn_8024FCF8(void** self, void* a)
{
    *self = a;
}

void fn_8024FD00(Unk8024FD00_S* self)
{
    self->m4 = 0;
    self->m8 = 0;
    self->mC = -1;
    self->m10 = -1;
}

void fn_8024FD1C(Unk8024FD00_S* self, int a, int b)
{
    if (b <= 2) {
        self->mC = b;
        self->m8 = a;
        self->m4 = 1;
    }
}

extern void fn_8024FE3C(Unk8024FD00_S* self, int a);
extern int fn_8026DAE8(P* x, int a);
extern int fn_8026DD60(P* x, int a);
extern int fn_80254EA4(A* a, int b);
extern int fn_80247858(P* x, int a);
int fn_8024FD38(Unk8024FD00_S* e, int k)
{
    if (e->m4 == 1) {
        P* p = (P*)e->m8;
        A* a = &p->m58C;
        if (a->b2) {
            fn_8024FD00(e);
        } else {
            int m38 = a->m38;
            int t = fn_80254EA4(a, 0);
            if (m38 > e->mC && (t == -1 || t >= m38)) {
                fn_8024FE3C(e, m38);
            } else if (k == 1) {
                int z = fn_80247858(p, 0);
                int u = fn_80255028(a);
                if (z == e->mC) {
                    if (u == z)
                        fn_8024FD00(e);
                    else if (fn_8026DAE8(p, 0) != 0 && fn_8026DD60(p, 0) == 0)
                        fn_8024FD00(e);
                }
            }
        }
    }
    return e->m4;
}

void fn_8024FE3C(Unk8024FD00_S* self, int a)
{
    self->m10 = a;
    self->m4 = 2;
}

/* near-miss: 63 vs 63 insns, 5 differ: retail loads e->m10 (r5) before e->m8 (r4) for the fn_801D869C call and keeps the +0x56C id in r5 (ours r9). Tried temporaries for both args, return-type toggles of every callee */
extern void fn_801D869C(char* a, int b, int c);
extern P* fn_801A497C(Unk8024EF40_Q* q, int k);
extern void fn_80253B1C(W* w, int a);
extern void fn_80253BFC(W* w, int a);
extern void fn_80253C38(W* w, int a);
void fn_8024FE4C(Unk8024FD00_S* e, int k)
{
    int ok = 1;
    P* pl = *(P**)e->m0;
    Unk8024EF40_Q* q = pl->m44C;
    if (q != 0) {
        Unk8024EF40_T10* t = q->m6F8->m10;
        if (t != 0 && *(int*)((char*)t + 0x28) == 0)
            ok = 0;
    }
    if (ok == 1) {
        fn_801D869C(((Unk8024FE4C_Q*)q)->m700->m3A4 + 0xE0, e->m8, e->m10);
        P* tgt;
        int id = ((Unk8024FE4C_P*)pl)->m56C;
        if (id != -1 && id != pl->m460)
            tgt = fn_801A497C(q, pl->m708);
        else
            tgt = pl;
        switch (k) {
        case 0:
            break;
        case 1:
            fn_80253B1C((W*)((char*)tgt + 0x580), e->m8);
            break;
        case 2:
            fn_80253BFC((W*)((char*)tgt + 0x580), e->m8);
            break;
        case 3:
            fn_80253C38((W*)((char*)tgt + 0x580), e->m8);
            break;
        }
    }
}

void fn_8024FF48(Unk80250244_S* self)
{
    self->m5C = fn_8025454C(&self->mA4->m588, 0xF);
    self->m60 = fn_8025454C(&self->mA4->m588, 0xE);
    self->m68 = fn_8025454C(&self->mA4->m588, 0x10);
    self->m6C = fn_8025454C(&self->mA4->m588, 0x11);
}

void fn_8024FFC0(Unk80250244_S* self)
{
    fn_8024F7C8(self);
    self->m5C = 0.0f;
    self->m60 = 0.0f;
    self->m68 = 0.0f;
    self->m6C = 0.0f;
    self->mA0 = 0.0f;
    self->m64 = 0.0f;
    self->m80 = 0.0f;
    SetF(&self->m74, 0.0f);
    self->m9C = -1;
    self->m94 = -1;
    self->m70 = 0;
    self->m78 = 0;
    self->m7C = 0;
    fn_80250244(self);
    self->m8C = 0.0f;
}

extern "C" void fn_8025004C(Unk80250244_S* self)
{
    int m1 = -1;
    fn_80250244(self);
    self->m94 = m1;
    fn_8024F7C8(self);
    self->m78 = 0;
    self->m70 = 0;
    SetF(&self->m74, 0.0f);
    fn_802456C8(self->mA4, 0, 0, 0.0f);
    fn_8025068C(self, 4);
    self->mA4->m730 = m1;
}

int fn_802500D0(Unk80250244_S* self)
{
    float tbl[3];
    tbl[0] = 0.2f;
    tbl[1] = 0.4f;
    tbl[2] = 0.2f;
    if (fn_8026D6D8(self->mA4, 0) == 1)
        tbl[2] = 0.4f;
    return Secs(self->mA4->m44C) - self->m74 < tbl[2];
}

void fn_80250180(Unk80250244_S* self, int a)
{
    const float k = 0.2f;
    self->m80 = Secs(self->mA4->m44C) + k;
    self->m84 = a;
    self->m88 = 0;
}

void fn_802501E0(Unk80250244_S* self)
{
    const float k = 0.5f;
    self->m80 = Secs(self->mA4->m44C) + k;
    self->m88 = 1;
    self->m84 = -1;
}

void fn_80250244(Unk80250244_S* self)
{
    self->m84 = -1;
    self->m88 = 0;
    self->m80 = 0.0f;
}

int fn_80250264(Unk80250244_S* self)
{
    int r = -1;
    if (!(Secs(self->mA4->m44C) >= self->m80)) {
        if (self->m84 != -1)
            return self->m84;
    }
    return r;
}

int fn_802502D0(Unk80250244_S* self)
{
    if (!(Secs(self->mA4->m44C) >= self->m80) && self->m88 == 1)
        return 1;
    return 0;
}

extern "C" float fn_80250338(Unk80250244_S* self, float a, float b)
{
    if (lbl_8068CB64 == 0) {
        fn_8023CB08(self->mA4);
        lbl_8068CB60 = lbl_8061D630;
        lbl_8068CB64 = 1;
    }
    return fn_802503E8(self, lbl_8068CB60, a, b);
}

float fn_802503B0(Unk80250244_S* self, float a, float b)
{
    return fn_802503E8(self, lbl_8061DC50, a, b);
}

void fn_8025068C(Unk80250244_S* self, int a)
{
    if (a != self->m9C) {
        self->m9C = a;
        self->mA0 = Secs(self->mA4->m44C);
    }
}

void fn_802506E4(Unk80250244_S* self)
{
    P* p = self->mA4;
    self->m98 = 1;
    if (p != 0)
        fn_801BA4AC(p->m44C->m700->m3BC);
}

int fn_80250A90(P* self, int a)
{
    return fn_8017EEB0((char*)self->m44C->m700 + 0x228, *(int*)((char*)self + 0x704), a);
}

int fn_80250AC4(P* x)
{
    Unk8024EF40_Q* q = x->m44C;
    Unk80250AC4_S* s = (Unk80250AC4_S*)q->m6F8;
    int i = x->m708;
    if (q->m6F4 == 0) {
        int t = s->m10->m20;
        if (t == 1 || (t == 2 && s->mC->m84 == 0)) {
            int o = i * 0xE64;
            if (*((unsigned char*)s->m14 + o + 0x234) != 0)
                return 1;
        }
    }
    return 0;
}

float fn_80251000(P* x, int k)
{
    float s = fn_8024D0F8(x, k);
    s = s * s;
    s = !(s > 1.0f) ? (s >? 0.0f) : 1.0f;
    s = s * 4.0f;
    float w = fn_8025454C(&x->m588, 0x12);
    w = !(w > 1.0f) ? (w >? 0.0f) : 1.0f;
    w = Unk80251000_Lerp(0.70710677f, 1.0f - w, 1.4142135f);
    w = w * w;
    s = s * w;
    return s;
}

void fn_80251124(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x433);
        float t = fn_80251000(x, 0x29) * G_8061DC08(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CAC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0);
    }
}

void fn_8025124C(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 1) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x445);
        float t = fn_80251000(x, 0x29) * G_8061DC0C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CB0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 1);
    }
}

void fn_80251374(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 2) != 0) {
        float t = 20.0f;
        float p = RandPct(x, lbl_805D990C, 0x457);
        if (lbl_8061DC54 != 0 || lbl_80691CB4 != 0)
            p = 0.0f;
        if (!(p >= 20.0f))
            fn_80250B28(x, 2);
    }
}

void fn_8025147C(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 2) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x468);
        float t = fn_80251000(x, 0x29) * G_8061DC10(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CB4 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 2);
    }
}

void fn_802515A4(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 3) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x47B);
        float t = fn_80251000(x, 0x2C) * G_8061DC14(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CB8 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 3);
    }
}

void fn_802516CC(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 4) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x48D);
        float t = fn_80251000(x, 0x2A) * G_8061DC18(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CBC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 4);
    }
}

void fn_802517F4(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 5) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x49F);
        float t = fn_80251000(x, 0x2A) * G_8061DC1C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CC0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 5);
    }
}

void fn_80251D58(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0xD) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x52F);
        float t = fn_80251000(x, 0x2C) * G_8061DC2C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CE0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0xD);
    }
}

extern float lbl_8061DC38;
extern int lbl_80691CEC;
extern int fn_8026D8E8(P* x, int a);
extern int fn_8026D914(P* x, int a);
inline float G_8061DC38(void* p) { return lbl_8061DC38; }
void fn_80251E80(P* x)
{
    if ((fn_8026D8E8(x, 0) != 0 || fn_8026D914(x, 0) != 0) && fn_80250AC4(x) != 0 && fn_80250A90(x, 0x10) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x56D);
        float t = fn_80251000(x, 0x2C) * G_8061DC38(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CEC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0x10);
    }
}

void fn_80251FD0(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0x11) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x57F);
        float t = fn_80251000(x, 0x2C) * G_8061DC3C(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CF0 != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0x11);
    }
}
