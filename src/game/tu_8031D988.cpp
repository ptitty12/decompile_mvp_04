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
float fn_802CBD90(void* p);
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
float fn_8031E86C();
void fn_8031E960(FxL* self);
void fn_8031F04C(FxL* self, int v);
void fn_8031F080(FxQ* self, int v);
void fn_8031F0A0(FxQ* self, FxVec* out);
void fn_8031F0EC(FxS* self, int a);
void fn_8031F13C(FxT* self, int a);
int fn_8031F170(FxR* a, FxR* b);
// PROTOS-END
}

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

/* near-miss: retail reloads the clamp constants (lis) for every field; ours CSEs them */
void fn_8031DBAC(FxK* self) {
    self->m4 = self->m4 > lbl_805EA720 ? lbl_805EA720 : (self->m4 >? lbl_805EA724);
    self->m8 = self->m8 > lbl_805EA720 ? lbl_805EA720 : (self->m8 >? lbl_805EA724);
    self->mC = self->mC > lbl_805EA720 ? lbl_805EA720 : (self->mC >? lbl_805EA724);
    self->m10 = self->m10 > lbl_805EA720 ? lbl_805EA720 : (self->m10 >? lbl_805EA724);
}

/* near-miss: clamp of a float parameter: retail compares in f0/f13 the other way round */
void fn_8031DC94(FxK* self, FxK* other, float* o1, float* o2, float* o3, float* o4, float t) {
    if (other == 0) {
        *o1 = self->m4;
        *o2 = self->m8;
        *o3 = self->mC;
        *o4 = self->m10;
    } else {
        t = t > lbl_805EA728 ? lbl_805EA728 : (t >? lbl_805EA72C);
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

/* near-miss: stack layout: retail has the packed int at sp+8 and the color at sp+16; fmr chain */
void fn_8031E23C(FxL* self) {
    if (self->m8 == 0) self->m8 = fn_80314740(lbl_8061FEDC);
    FxColor col;
    fn_8014D9EC(&col, lbl_805EA75C, lbl_805EA75C, lbl_805EA75C, lbl_805EA760, lbl_805EA760);
    int packed = fn_8014DDAC(&col);
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

void fn_8031E404(FxL* self, float a, float b, float c, float d) {
    fn_803E0ACC(self->m8, a, b, c, d, lbl_805EA770, lbl_805EA774);
}

float fn_8031E6E4(FxL* self) {
    float a = lbl_805EA794, b = lbl_805EA794, c = lbl_805EA794, d = lbl_805EA794, e = lbl_805EA794;
    fn_8031E9E4(self, &a, &b, &c, &d, &e);
    fn_8031E404(self, b, c, d, e);
    return a;
}

float fn_8031E86C() { return lbl_805EA7B0; }

/* near-miss: retail loads lbl_805EA7C8 before lbl_805EA7CC */
void fn_8031E960(FxL* self) {
    fn_8031E6E4(self);
    float v = lbl_805EA7C0;
    if (self->mC) v = fn_802CBD90(self->mC);
    FxMat mat;
    FxMat* p = &mat;
    fn_803E1CDC(self->m8, lbl_805EA7CC, lbl_805EA7C4, lbl_805EA7C8);
    fn_803DF74C(p);
    fn_803E1C44(self->m8, p);
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
    m4 = a;
    m8 = lbl_80665110;
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
