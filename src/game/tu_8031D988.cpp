/*
 * Game code, .text 0x8031D988-0x80321A78 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern const float lbl_805EA720;
extern const float lbl_805EA724;
extern const float lbl_805EA728;
extern const float lbl_805EA72C;
extern const float lbl_805EA730;
extern const float lbl_805EA734;
extern const float lbl_805EA738;
extern const float lbl_805EA73C;
extern const float lbl_805EA720;
extern const float lbl_805EA724;
extern const float lbl_805EA728;
extern const float lbl_805EA72C;
extern const float lbl_805EA730;
extern const float lbl_805EA734;
extern const float lbl_805EA738;
extern const float lbl_805EA73C;
extern const float lbl_805EA75C;
extern const float lbl_805EA760;
extern const float lbl_805EA770;
extern const float lbl_805EA774;
extern const float lbl_805EA794;
extern const float lbl_805EA7C0;
extern const float lbl_805EA7C4;
extern const float lbl_805EA7C8;
extern const float lbl_805EA7CC;
extern const float lbl_805EA750;
extern int lbl_8061B884;
extern const float lbl_805EA6D0;
extern const float lbl_805EA6D4;
extern const float lbl_805EA740;
extern const float lbl_805EA744;
extern const float lbl_805EA754;
extern const float lbl_805EA758;
extern const float lbl_805EA7B0;
extern const void* const lbl_80665D28[];
extern const void* const lbl_80665CF8[];
extern const void* const lbl_80665CF8[];
extern const char lbl_805EA6D8[];
extern const char lbl_805E7864[];
extern const char lbl_805EA6DC[];
extern const char lbl_805EA6E0[];
extern const char lbl_805EA6E8[];
extern const char lbl_805EA6F0[];
extern const char lbl_805EA6FC[];
extern const char lbl_805EA70C[];
extern const char lbl_805E94C0[];
extern const char lbl_805E7988[];
extern const char lbl_805E7AD0[];
extern FxCtx* lbl_8061FEDC;
extern FxBox lbl_8068F1D4;
extern const void* const lbl_80665110[];
extern const void* const lbl_806650F8[];
struct FxEngine { char pad0[0x3654]; int m3654; };
extern FxEngine* lbl_8061E978;

inline int At(char* base, int off) { return *(int*)(base + off); }

extern FxF3 lbl_806E20E4;
struct Unk80178BBC_T;
struct FxM700 {
    char pad0[0x3AC];
    Unk80178BBC_T* m3AC;
};
struct FxWld {
    char pad0[0x700];
    FxM700* m700;
};
int fn_80179058(Unk80178BBC_T* p);
struct FxSlotP {
    int m0;
    int m4;
};
struct FxKR {
    int m0;
    char pad4[0x1C];
};
struct FxObjX {
    char pad0[0xD8];
    FxKR k[7];
    char pad1B8[0xAC0 - 0x1B8];
    float mAC0;
};
struct FxHit {
    FxObjX* m0;
    float m4;
    int m8;
    int mC;
    float m10;
    int m14;
};
extern int lbl_806E2184[][20];
extern FxSlotP lbl_806E2274[];
extern int lbl_806201B8[];
extern float lbl_806201D8[1];
struct FxLst {
    char pad0[0x58];
    int m58;
    int m5C;
    int m60;
    int a64[1];
};
class FxVT8s {
public:
    char pad0[8];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
};
struct FxP10 {
    char pad0[0x14];
    int m14;
};
struct FxC744 {
    char pad0[0x20];
    int m20;
};
struct FxC1C {
    char pad0[0x744];
    FxC744* m744;
};
struct FxCtxP {
    char pad0[0x6F4];
    int m6F4;
};
struct Unk802CBD04;
float fn_802CBD90(Unk802CBD04* p);
float fn_802D38E8();

struct FxRow {
    int m0;
    float m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
struct FxRowOut {
    int m0;
    float m4;
    int m8;
};
extern const int lbl_805EA96C[];
struct Unk8019F8C0_Owner { char pad0[0x54C]; void* m54C; int m550; };
struct Unk80313C14_P38;
struct FxEng { char pad0[8]; void* m8; };
class FxVT18 {
public:
    char pad0[0x18];
    virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
};
extern const int lbl_80620168[];
class FxObjVB {
public:
    char pad0[0x98];
    virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(int a, int b);
};
class FxObjV : public FxObjVB {
public:
    char pad9C[0x640 - 0x9C];
    int m640[1];
};
struct FxHitV {
    FxObjV* m0;
    float m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
extern int lbl_806201C0;
extern int lbl_806201C4;
extern int lbl_8061D4D8;
struct FxMap { int key; int val; };
extern FxMap lbl_8062023C[4];
extern float lbl_806201CC[];
class FxVT8x {
public:
    char pad0[8];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4();
    virtual int s5(); virtual int s6(); virtual int s7(); virtual int s8();
    virtual int s9(); virtual int s10();
};
struct FxA3C { char pad0[0x3C]; FxVT8x* m3C; };
struct FxEng6F4 { char pad0[0x6F4]; int m6F4; };
extern FxMap lbl_806201EC[4];
extern FxMap lbl_8062020C[4];
extern int lbl_806201BC;
extern FxMap lbl_80620224[];
extern FxMap lbl_80620254[];
extern "C" {
void fn_8037B7E4(void* self, const char* name);
void fn_8037B50C(void* self, const char* name, void* field, const char* list, int flags);
void fn_8037B458(void* self, const char* name, void* field, const char* a, const char* b);
void* fn_8037C7FC();
void* fn_8037CF5C(void* c, unsigned hash, void* obj);
int fn_8037CE98(void* c, unsigned hash, const void* arg, int flags);
void fn_8035F720(void* p);
void fn_8016D128(void* p);
void* fn_8016A0D0(void* mem, int a, void* owner);
void* fn_802D39EC(void* mem, int a, void* owner, int b);
void* fn_802D61F8(void* mem, int a, void* owner);
int fn_80312604(FxCtx* c);
void fn_803125D0(FxCtx* c);
void fn_8031259C(FxCtx* c);
void fn_803E1578(void* p, int flags);
void fn_80377408(void* p);
float fn_80323848(void* p);
int fn_80326E64(void* p, int a);
void* fn_80314740(FxCtx* c);
void fn_8014D9EC(void* p, float a, float b, float c, float d, float e);
int fn_8014DDAC(void* p);
void fn_8031E2EC(FxL* self);
void fn_803E0ACC(void* p, float a, float b, float c, float d, float e, float f);
void fn_8031E9E4(FxL* self, float* a, float* b, float* c, float* d, float* e);
void fn_803E1CDC(void* p, float a, float b, float c);
void fn_803DF74C(void* p);
void fn_803E1C44(void* p, void* q);
void fn_803E2208(void* p, int* v);
void fn_803E1DB0(void* p, float a, float b);
void fn_80314768(FxCtx* c, void* p);
void fn_8031E23C(FxL* self);
void fn_803E1DB0(void* p, float a, float b);
void fn_80314768(FxCtx* c, void* p);
void fn_8031E23C(FxL* self);
float fn_8031E75C(FxL* self);
void* fn_801A4CE8(void* c, int a);
void fn_8031E458(FxL* self, float* a, float* b, float* c, float* d);
int fn_803285A0(int n);
void fn_803E0DD0(void* p, float a, float b, float c, float d);
void fn_8031E878(FxL* self);
// PROTOS-BEGIN
FxK* fn_8031D988(FxK* self);
void fn_8031D9FC(FxK* self);
void* fn_8031DB00(void* s);
int fn_8031DB3C(const char* s);
FxK* fn_8031DB7C();
void fn_8031DBAC(FxK* self);
void fn_8031DC94(FxK* self, FxK* other, float* o1, float* o2, float* o3, float* o4, float t);
FxL* fn_8031DD54(FxL* self, void* a, int b, int c, void* d);
void fn_8031DE38(FxL* self, int a);
void fn_8031DF08(FxL* self);
void fn_8031DF58(FxL* self, int a);
void fn_8031DFA0(FxL* self, int a);
void fn_8031DFEC(FxL* self, int a);
void fn_8031E034(FxL* self);
void fn_8031E110(FxL* self);
void fn_8031E194(FxL* self);
void fn_8031E1A0(FxL* self, const char* s);
void fn_8031E1D4(FxL* self, const char* a);
void fn_8031E23C(FxL* self);
int fn_8031E2C8(FxL* self);
void fn_8031E404(FxL* self, float a, float b, float c, float d);
float fn_8031E6E4(FxL* self);
float fn_8031E86C(FxL* self);
void fn_8031E960(FxL* self);
void fn_8031ED80(FxL* self);
void fn_8031F04C(FxL* self, int v);
void fn_8031F080(FxQ* self, int v);
void fn_8031F0A0(FxQ* self, FxVec* out);
void fn_8031F0EC(FxS* self, int a);
void fn_8031F13C(FxT* self, int a);
int fn_8031F170(FxR* a, FxR* b);
void fn_80320878(void* unused, FxVT8* o, int arg);
void fn_80320CF4(void* unused, int* pcount, FxRow* arr, FxRowOut* out);
void fn_80320DD0(void* unused, Unk8019F8C0_Owner* self);
void* fn_803119C0();
int fn_80328648(void* o);
void fn_803E1E88(void* p);
void fn_803E0F9C(void* p);
void fn_803208E4(void* self, int a, int t, void* arr, int* cnt, int* cnt2);
void qsort(void* a, unsigned n, unsigned es, int (*cmp)());
void fn_8031F1B4(void* self);
int fn_8023ED68(void* o, int a, void* b, int c, int d);
int fn_801A4C74(Unk8019F8C0_Owner* o, int a);
void fn_8031FF00(void* unused, int team, FxHit* out, int* pcount, void* p4, int kind);
void fn_8031F688(void* unused, int team, FxHit* out, int* pcount, FxA3C* a, int kind);
extern int lbl_8061F968;
void fn_8031FC80(void* unused, int team, FxHit* out, int* pcount, FxA3C* a, int kind);
// PROTOS-END
}
FxEng* fn_80314790(Unk80313C14_P38* p);
FxL* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
void fn_80311464(void* p, int a, int b);

// FUNCS-BEGIN

FxK* fn_8031D988(FxK* self) {
    new ((void*)self) Unk8037B3E8(0xE33E6A08U);
    self->m4 = lbl_805EA6D0;
    self->mC = lbl_805EA6D4;
    self->m8 = lbl_805EA6D0;
    self->m0 = lbl_80665D28;
    self->m14 = 0;
    self->m18 = 0;
    self->m10 = lbl_805EA6D4;
    self->m1C = 0;
    return self;
}

void fn_8031D9FC(FxK* self) {
    fn_8037B7E4(self, lbl_805EA6D8);
    fn_8037B50C(self, lbl_805E7864, &self->m4, lbl_805E94C0, 0);
    fn_8037B50C(self, lbl_805EA6DC, &self->m8, lbl_805E94C0, 0);
    fn_8037B50C(self, lbl_805EA6E0, &self->mC, lbl_805E94C0, 0);
    fn_8037B50C(self, lbl_805EA6E8, &self->m10, lbl_805E94C0, 0);
    fn_8037B458(self, lbl_805EA6F0, &self->m14, 0, 0);
    fn_8037B458(self, lbl_805EA6FC, &self->m18, lbl_805E7988, lbl_805E7AD0);
    fn_8037B458(self, lbl_805EA70C, &self->m1C, lbl_805E7988, lbl_805E7AD0);
}

void* fn_8031DB00(void* s) { return fn_8037CF5C(fn_8037C7FC(), 0xE33E6A08, s); }

int fn_8031DB3C(const char* s) { return fn_8037CE98(fn_8037C7FC(), 0xE33E6A08, s, 0); }

FxK* fn_8031DB7C() { return fn_8031D988((FxK*)operator new(0x20, lbl_806EF9B4)); }

void fn_8031DBAC(FxK* self) {
    self->m4 = !(self->m4 > 1.0f) ? (self->m4 >? 0.0f) : 1.0f;
    self->m8 = !(self->m8 > 1.0f) ? (self->m8 >? 0.0f) : 1.0f;
    self->mC = !(self->mC > 1.0f) ? (self->mC >? 0.0f) : 1.0f;
    self->m10 = !(self->m10 > 1.0f) ? (self->m10 >? 0.0f) : 1.0f;
}

void fn_8031DC94(FxK* self, FxK* other, float* o1, float* o2, float* o3, float* o4, float t) {
    if (other == 0) {
        *o1 = self->m4;
        *o2 = self->m8;
        *o3 = self->mC;
        *o4 = self->m10;
    } else {
        t = t > 1.0f ? 1.0f : (t >? 0.0f);
        *o1 = self->m4 + (other->m4 - self->m4) * t;
        *o2 = self->m8 + (other->m8 - self->m8) * t;
        *o4 = self->m10 + (other->m10 - self->m10) * t;
        *o3 = self->mC + (other->mC - self->mC) * t;
    }
}

FxL* fn_8031DD54(FxL* self, void* a, int b, int c, void* d) {
    fn_8035F720(self);
    self->m54 = c;
    self->m8 = d;
    self->m38 = 0;
    self->m3C = 0;
    self->m40 = 0;
    self->m44 = 0;
    self->m1C = a;
    self->mC = 0;
    self->m48 = 0;
    self->m20 = 0;
    self->m2C = 0;
    self->m0 = lbl_80665CF8;
    self->m18 = lbl_805EA730;
    self->m50 = lbl_805EA734;
    self->m4C = lbl_805EA730;
    self->m30 = lbl_805EA730;
    fn_8031E1D4(self, (const char*)b);
    fn_8031E23C(self);
    if (a == 0) fn_803E1DB0(self->m8, lbl_805EA738, lbl_805EA73C);
    self->m34 = 7;
    self->m4 = 1;
    self->m58 = 0;
    return self;
}

void fn_8031DE38(FxL* self, int a) {
    self->m0 = lbl_80665CF8;
    void* p = self->m8;
    if (p && self->m54 == 3) fn_80314768(lbl_8061FEDC, p);
    if (self->m3C) {
        delete self->m3C;
        self->m3C = 0;
    }
    if (self->m40) {
        delete self->m40;
        self->m40 = 0;
    }
    if (a & 1) fn_80377408(self);
}

void fn_8031DF08(FxL* self) {
    self->m4C = lbl_805EA740;
    self->m50 = lbl_805EA744;
    self->m58 = 0;
    if (self->m40) fn_8016D128(self->m40);
}

void fn_8031DF58(FxL* self, int a) { self->m40 = (FxLObj40*)fn_8016A0D0(operator new(0x42A8, 0), a, self); }

void fn_8031DFA0(FxL* self, int a) { self->m3C = (FxLObj3C*)fn_802D39EC(operator new(0x168, 0), a, self, 0); }

void fn_8031DFEC(FxL* self, int a) { self->m3C = (FxLObj3C*)fn_802D61F8(operator new(0x168, 0), a, self); }

void fn_8031E034(FxL* self) {
    float v = (self->m44 != 0 || self->m48 == 0) ? self->m4C : fn_80323848((void*)self->m48);
    float lim;
    v = v + self->m50;
    if (self->m44 != 0) {
        lim = (float)fn_80326E64((char*)self->m1C + 0x50, 0) * lbl_805EA750;
        if (!(v <= lim - lbl_805EA750)) v = lim - lbl_805EA750;
    }
    float w = v;
    self->m4C = w;
}

void fn_8031E110(FxL* self) {
    FxCtx* c = lbl_8061FEDC;
    int flags = self->m34;
    if (self->m38) flags = 2;
    int locked = 0;
    if (flags & 2) {
        locked = fn_80312604(c) == 0;
        fn_803125D0(c);
    }
    fn_803E1578(self->m8, flags);
    if (locked) fn_8031259C(c);
}

void fn_8031E194(FxL* self) { self->m2C = 0; }

void fn_8031E1A0(FxL* self, const char* s) { self->m10 = (void*)fn_8031DB3C(s); }

void fn_8031E1D4(FxL* self, const char* a) {
    if (a) {
        self->m10 = fn_8031DB00((void*)a);
    } else {
        lbl_8068F1D4.m4 = lbl_805EA754;
        lbl_8068F1D4.m8 = lbl_805EA754;
        lbl_8068F1D4.mC = lbl_805EA758;
        lbl_8068F1D4.m10 = lbl_805EA758;
        self->m10 = &lbl_8068F1D4;
    }
}

/* near-miss: retail has the packed int at sp+8 and the color at sp+16 (kept in a saved register); literals give the fmr chain */
void fn_8031E23C(FxL* self) {
    int packed;
    FxColor col;
    FxCtx* ctx = lbl_8061FEDC;
    if (self->m8 == 0) self->m8 = fn_80314740(ctx);
    fn_8014D9EC(&col, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    packed = fn_8014DDAC(&col);
    fn_803E2208(self->m8, &packed);
    fn_8031E2EC(self);
}

int fn_8031E2C8(FxL* self) {
    FxM* o = self->mC;
    if (o) {
        FxN* n = o->mA0;
        if (n) return n->m1C;
    }
    return 0;
}

void fn_8031E2EC(FxL* self) {
    FxCtx* c = lbl_8061FEDC;
    int a;
    int b;
    float v0;
    float v1;
    float v2;
    float v3;
    if (self->m54 != 3) {
        int off = self->m54 * 0x28;
        char* t = (char*)c->m38;
        a = At(t + 0x2C, off);
        b = At(t + 0x30, off);
    } else {
        a = c->m28 != 0 ? c->m2C : c->m14;
        b = lbl_8061FEDC->m28 != 0 ? lbl_8061FEDC->m30 : lbl_8061FEDC->m18;
    }
    fn_8031E458(self, &v0, &v1, &v2, &v3);
    fn_8031E404(self, v0 * (float)a, v1 * (float)b, (v2 - v0) * (float)a, (v3 - v1) * (float)b);
}

void fn_8031E404(FxL* self, float a, float b, float c, float d) {
    fn_803E0ACC(self->m8, a, b, c, d, lbl_805EA770, lbl_805EA774);
}

float fn_8031E6E4(FxL* self) {
    float a = lbl_805EA794, b = lbl_805EA794, c = lbl_805EA794, d = lbl_805EA794, e = lbl_805EA794;
    fn_8031E9E4(self, &a, &b, &c, &d, &e);
    fn_8031E404(self, b, c, d, e);
    return a;
}

float fn_8031E75C(FxL* self) {
    if (((FxP10*)self->m10)->m14 == 0) {
        FxC1C* c = (FxC1C*)self->m1C;
        if (c->m744->m20 != 0) return 20.0f;
        if (((FxVT8s*)fn_801A4CE8(c, 1))->s9() != 0) return 20.0f;
        if (self->mC != 0) {
            if (!(fn_802CBD90((Unk802CBD04*)self->mC) >= 28.0f)) {
                if (((FxVT8s*)fn_801A4CE8(self->m1C, 1))->s9() == 0) {
                    float t = fn_802CBD90((Unk802CBD04*)self->mC);
                    return 360.0f / (t * 0.5f) + 30.0f;
                }
            }
        }
    }
    return 48.0f;
}

float fn_8031E86C(FxL* self) { return lbl_805EA7B0; }

void fn_8031E878(FxL* self) {
    float a = fn_8031E6E4(self);
    float b = 45.0f;
    if (self->mC) b = fn_802CBD90((Unk802CBD04*)self->mC);
    float c = 0.9f;
    if (((FxCtxP*)self->m1C)->m6F4 == 1) c = 1.0f;
    b = b * c;
    b = b * fn_802D38E8();
    fn_803E0DD0(self->m8, b, a, fn_8031E75C(self), fn_8031E86C(self));
}

/* near-miss: 2 slots: retail loads the 250000.0f constant before 1.0f */
void fn_8031E960(FxL* self) {
    fn_8031E6E4(self);
    float v = 45.0f;
    if (self->mC) v = fn_802CBD90((Unk802CBD04*)self->mC);
    FxMat mat;
    FxMat* p = &mat;
    fn_803E1CDC(self->m8, 1.0f, 48.0f, 250000.0f);
    fn_803DF74C(p);
    fn_803E1C44(self->m8, p);
}

void fn_8031ED80(FxL* self) {
    FxMV* m = (FxMV*)self->mC;
    if (m) {
        FxMat mat;
        m->s3(&mat);
        fn_803E1C44(self->m8, &mat);
        FxVec tmp = *(FxVec*)&((FxMV*)self->mC)->m60;
        lbl_806E20E4.x = *(float*)&tmp.x;
        lbl_806E20E4.y = *(float*)&tmp.y;
        lbl_806E20E4.z = *(float*)&tmp.z;
    }
}

void fn_8031F04C(FxL* self, int v) {
    if (self->m8) {
        int tmp = v;
        fn_803E2208(self->m8, &tmp);
    }
}

void fn_8031F080(FxQ* self, int v) {
    self->a64[self->m5C] = v;
    self->m5C = self->m5C + 1;
}

void fn_8031F0A0(FxQ* self, FxVec* out) { *out = self->mC->m60; }

// fn_8031F0C4
FxS::FxS(int a) {
    m8 = lbl_80665110;
    m4 = a;
    m0 = lbl_8061E978->m3654;
}

void fn_8031F0EC(FxS* self, int a) {
    self->m8 = lbl_80665110;
    self->m0 = 0;
    if (a & 1) fn_80377408(self);
}

// fn_8031F128
FxT::FxT() { m0 = lbl_806650F8; }

void fn_8031F13C(FxT* self, int a) {
    self->m0 = lbl_806650F8;
    if (a & 1) fn_80377408(self);
}

int fn_8031F170(FxR* a, FxR* b) {
    if (a->m8 < b->m8) return -1;
    if (a->m8 > b->m8) return 1;
    if (a->m10 < b->m10) return -1;
    return a->m10 > b->m10;
}

void fn_8031F1B4(void* self)
{
    FxHitV arr[200];
    FxRowOut out[200];
    int i = 0;
    int cnt;
    int cnt2;
    lbl_806201C4 = 0;
    lbl_806201C0 = 0;
    cnt2 = 0;
    cnt = 0;
    for (int t = 1; t <= 2; t++) {
        int a = fn_803285A0(t);
        if (a != 0)
            fn_803208E4(self, a, t, arr, &cnt, &cnt2);
    }
    qsort(arr, cnt, 0x18, (int (*)())fn_8031F170);
    for (i = 0; i < cnt; i++) {
        if (arr[i].m8 < lbl_8061D4D8)
            arr[i].m8 = lbl_8061D4D8;
    }
    fn_80320CF4(self, &cnt, (FxRow*)arr, out);
    for (i = 0; i < cnt; i++) {
        FxHitV* e = &arr[i];
        e->m0->s13(e->mC, e->m8);
        arr[i].m0->m640[e->mC] = e->m14;
    }
}

void fn_8031F688(void* unused, int team, FxHit* out, int* pcount, FxA3C* a, int kind)
{
    FxEng6F4* c = (FxEng6F4*)fn_803285A0(team);
    FxVT8x* h = a->m3C;
    int v1 = h->s9();
    int v2 = h->s10();
    FxMap* tb;
    if (c->m6F4 == 3)
        tb = lbl_806201EC;
    else
        tb = lbl_8062020C;
    int* row = lbl_806E2184[team];
    for (int i = 0; i < 1; i++) {
        int n = row[lbl_806201B8[i]];
        while (n > 0) {
            FxSlotP* pr = &lbl_806E2274[n];
            int next = 0;
            if (pr->m0 != 0) {
                FxObjX* o = (FxObjX*)(pr->m0 - 0xA0);
                int k;
                if (kind <= 6) {
                    k = kind;
                    if (kind < 0)
                        k = 0;
                } else
                    k = 6;
                int f = *(int*)((char*)(k * 32 + (int)o) + 0xD8);
                if (f != 0xD && f != 0x11 && fn_8023ED68(o, kind, a, v1, v2) != 0) {
                    int t = 4;
                    int cnt = 4;
                    for (int j = 0; j < cnt; j++) {
                        if (f == tb[j].key) {
                            if (f == 0xE && lbl_806201BC == 0)
                                t = 4;
                            else
                                t = tb[j].val;
                            break;
                        }
                    }
                    FxHit* r = &out[*pcount];
                    r->m0 = o;
                    r->m4 = o->mAC0;
                    r->m8 = t;
                    r->mC = kind;
                    r->m10 = lbl_806201CC[t];
                    if (t != 4)
                        r->m14 = 1;
                    else
                        r->m14 = 0;
                    *pcount = *pcount + 1;
                }
                next = pr->m4;
            }
            n = next;
        }
    }
}

void fn_8031F89C(void* unused, int unused1, FxHit* out, int* pcount, FxLst* list, int kind)
{
    if (list->m58 == 0)
        return;
    int* arr = list->a64;
    int n = list->m5C;
    for (int i = list->m60; i < n; i++) {
        int x = arr[i];
        FxObjX* o = 0;
        if (x != 0)
            o = (FxObjX*)(x - 0xA0);
        int k;
        if (kind <= 6) {
            k = kind;
            if (kind < 0)
                k = 0;
        } else
            k = 6;
        int f = *(int*)((char*)(k * 32 + (int)o) + 0xD8);
        if (f != 0xE) {
            FxHit* r = &out[*pcount];
            r->m0 = o;
            r->m4 = o->mAC0;
            r->m8 = 3;
            r->mC = kind;
            r->m10 = lbl_806201D8[0] + 10000.0f;
            r->m14 = 1;
            *pcount = *pcount + 1;
        }
    }
}

void fn_8031F97C(void* unused, int team, FxHit* out, int* pcount, int unused2, int kind)
{
    int* row = lbl_806E2184[team];
    for (int i = 0; i < 1; i++) {
        int n = row[lbl_806201B8[i]];
        while (n > 0) {
            FxSlotP* pr = &lbl_806E2274[n];
            int next = 0;
            if (pr->m0 != 0) {
                FxObjX* o = (FxObjX*)(pr->m0 - 0xA0);
                int k;
                if (kind <= 6) {
                    k = kind;
                    if (kind < 0)
                        k = 0;
                } else
                    k = 6;
                int t = 4;
                int f = *(int*)((char*)(k * 32 + (int)o) + 0xD8);
                if (f == 0xF)
                    t = 1;
                else if (f == 0x10)
                    t = 2;
                if (t != 4) {
                    FxHit* r = &out[*pcount];
                    r->m0 = o;
                    r->m4 = o->mAC0;
                    r->m8 = t;
                    r->mC = kind;
                    r->m10 = 0.0f;
                    r->m14 = 1;
                    *pcount = *pcount + 1;
                }
                next = pr->m4;
            }
            n = next;
        }
    }
}

void fn_8031FA84(void* unused, int team, FxHit* out, int* pcount, int unused2, int kind)
{
    int* row = lbl_806E2184[team];
    for (int i = 0; i < 1; i++) {
        int n = row[lbl_806201B8[i]];
        while (n > 0) {
            FxSlotP* pr = &lbl_806E2274[n];
            int next = 0;
            if (pr->m0 != 0) {
                FxObjX* o = (FxObjX*)(pr->m0 - 0xA0);
                int k;
                if (kind <= 6) {
                    k = kind;
                    if (kind < 0)
                        k = 0;
                } else
                    k = 6;
                int f = *(int*)((char*)(k * 32 + (int)o) + 0xD8);
                if (f == 0x11) {
                    FxHit* r = &out[*pcount];
                    r->m0 = o;
                    r->m4 = o->mAC0;
                    r->m8 = 0;
                    r->mC = kind;
                    r->m10 = 0.0f;
                    r->m14 = 1;
                    *pcount = *pcount + 1;
                }
                next = pr->m4;
            }
            n = next;
        }
    }
}

void fn_8031FB80(void* unused, int team, FxHit* out, int* pcount, int unused2, int kind)
{
    int target = fn_80179058(((FxWld*)fn_803285A0(team))->m700->m3AC);
    int* row = lbl_806E2184[team];
    for (int i = 0; i < 1; i++) {
        int n = row[lbl_806201B8[i]];
        while (n > 0) {
            FxSlotP* pr = &lbl_806E2274[n];
            int next = 0;
            if (pr->m0 != 0) {
                if (target == pr->m0 - 0xA0) {
                    FxHit* r = &out[*pcount];
                    r->m0 = (FxObjX*)target;
                    r->m4 = ((FxObjX*)target)->mAC0;
                    r->m8 = 0;
                    r->mC = kind;
                    r->m10 = 0.0f;
                    r->m14 = 1;
                    *pcount = *pcount + 1;
                }
                next = pr->m4;
            }
            n = next;
        }
    }
}

void fn_8031FC80(void* unused, int team, FxHit* out, int* pcount, FxA3C* a, int kind)
{
    FxVT8x* h = a->m3C;
    FxMap* tb = 0;
    int cnt = 0;
    int flag = 0;
    FxObjX* cur = 0;
    int v1 = h->s9();
    if (v1 != 0) {
        lbl_8061F968 = 1;
        cnt = 4;
        tb = lbl_80620224;
    }
    int v2 = h->s10();
    if (v2 != 0) {
        tb = lbl_80620254;
        cnt = 4;
        cur = (FxObjX*)fn_801A4C74((Unk8019F8C0_Owner*)fn_803285A0(team), 0);
        flag = 1;
        lbl_8061F968 = 0;
    }
    int* row = lbl_806E2184[team];
    for (int i = 0; i < 1; i++) {
        int n = row[lbl_806201B8[i]];
        while (n > 0) {
            FxSlotP* pr = &lbl_806E2274[n];
            int next = 0;
            if (pr->m0 != 0) {
                FxObjX* o = (FxObjX*)(pr->m0 - 0xA0);
                int k;
                if (kind <= 6) {
                    k = kind;
                    if (kind < 0)
                        k = 0;
                } else
                    k = 6;
                int f = *(int*)((char*)(k * 32 + (int)o) + 0xD8);
                if (f != 0xD && f != 0x11 && f != 0xF && f != 0x10 && fn_8023ED68(o, kind, a, v1, v2) != 0) {
                    int t = 3;
                    for (int j = 0; j < cnt; j++) {
                        if (f == tb[j].key) {
                            t = tb[j].val;
                            break;
                        }
                    }
                    if (flag != 0 && f == 0xE && o != cur)
                        t = 4;
                    if (t != 4) {
                        FxHit* r = &out[*pcount];
                        r->m0 = o;
                        r->m4 = o->mAC0;
                        r->m8 = t;
                        r->mC = kind;
                        r->m10 = lbl_806201CC[t];
                        if (f == 9)
                            r->m10 = 0.0f;
                        if (t != 3)
                            r->m14 = 1;
                        else
                            r->m14 = 0;
                        *pcount = *pcount + 1;
                    }
                }
                next = pr->m4;
            }
            n = next;
        }
    }
}

void fn_8031FF00(void* unused, int team, FxHit* out, int* pcount, void* p4, int kind)
{
    FxMap* tb = lbl_8062023C;
    FxObjX* cur = (FxObjX*)fn_801A4C74((Unk8019F8C0_Owner*)fn_803285A0(team), 0);
    int* row = lbl_806E2184[team];
    for (int i = 0; i < 1; i++) {
        int n = row[lbl_806201B8[i]];
        while (n > 0) {
            FxSlotP* pr = &lbl_806E2274[n];
            int next = 0;
            if (pr->m0 != 0) {
                FxObjX* o = (FxObjX*)(pr->m0 - 0xA0);
                int k;
                if (kind <= 6) {
                    k = kind;
                    if (kind < 0)
                        k = 0;
                } else
                    k = 6;
                int f = *(int*)((char*)(k * 32 + (int)o) + 0xD8);
                if (f != 0xD && f != 0x11 && f != 0xF && f != 0x10 && fn_8023ED68(o, kind, p4, 0, 0) != 0) {
                    int t = 3;
                    int j = 0;
                    int cnt = 4;
                    while (j < cnt) {
                        if (f == tb[j].key) {
                            t = tb[j].val;
                            break;
                        }
                        j++;
                    }
                    if (f == 0xE && o == cur)
                        t = 2;
                    if (t != 4) {
                        FxHit* r = &out[*pcount];
                        r->m0 = o;
                        r->m4 = o->mAC0;
                        r->m8 = t;
                        r->mC = kind;
                        r->m10 = lbl_806201CC[t];
                        if (t != 3)
                            r->m14 = 1;
                        else
                            r->m14 = 0;
                        *pcount = *pcount + 1;
                    }
                }
                next = pr->m4;
            }
            n = next;
        }
    }
}

void fn_80320878(void* unused, FxVT8* o, int arg) {
    if (o) {
        int i = 0;
        int lim = 3;
        do {
            o->s4(arg);
            i++;
            if (i >= lbl_8061B884) break;
        } while (i < lim);
    }
}

void fn_80320CF4(void* unused, int* pcount, FxRow* arr, FxRowOut* out)
{
    int i;
    int k = 0;
    int kind = 0;
    int a = 0;
    int b = 0;
    for (i = 0; i < *pcount; i++) {
        FxRow* p = &arr[i];
        if (p->m8 == 4) {
            *pcount = i;
            break;
        }
        int s = p->m8;
        if (s != kind) {
            a = b;
            kind = s;
            b = 0;
        }
        if (a == lbl_805EA96C[kind]) {
            p->m8 = s + 1;
            if (s + 1 == 4) {
                *pcount = i;
                break;
            }
            b++;
        } else
            a++;
        if (kind == 3) {
            FxRowOut* o = &out[k];
            o->m0 = p->m0;
            o->m4 = p->m4;
            o->m8 = p->mC;
            k++;
        }
    }
}

void fn_80320DD0(void* unused, Unk8019F8C0_Owner* self)
{
    int i = 0;
    FxEng* e = fn_80314790((Unk80313C14_P38*)lbl_8061FEDC);
    fn_803E1E88((void*)e->m8);
    FxL* o = fn_801A04A8(self, 1);
    int team = fn_80328648(self);
    fn_80311464(fn_803119C0(), 1, (int)o);
    self->m54C = o;
    self->m550 = 1;
    fn_8031E878(o);
    fn_803E0F9C((void*)o->m8);
    fn_8031E110(o);
    fn_8031ED80(o);
    int* row = lbl_806E2184[team];
    for (i = 0; i < 18; i++) {
        int cur = row[lbl_80620168[i]];
        while (cur > 0) {
            FxSlotP* pr = &lbl_806E2274[cur];
            int next = 0;
            if (pr->m0 != 0) {
                ((FxVT18*)pr->m0)->s12();
                next = pr->m4;
            }
            cur = next;
        }
    }
    fn_803E1E88((void*)o->m8);
    fn_803E0F9C((void*)e->m8);
}
