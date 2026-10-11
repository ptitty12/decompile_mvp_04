/*
 * Game code, .text 0x80317B88-0x8031B354 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
/* chooser.h declares these two with C++ linkage; here they are plain C symbols. */
#define fn_80410634 fn_80410634_cxx
#define fn_8037C7FC fn_8037C7FC_cxx
#include "game/tu_802A6334.h"
#undef fn_80410634
#undef fn_8037C7FC
#include "game/tu_80317B88.h"

extern const char lbl_805E89D4[];
extern const char lbl_805E89E0[];
extern const char lbl_805E89EC[];
extern const char lbl_805E89F0[];
extern const char lbl_805E89F8[];
extern const char lbl_805E8A00[];
extern const char lbl_805E8A0C[];
extern const char lbl_805E79A4[];
extern const char lbl_805E9CC8[];
extern const float lbl_805E9FA4;
extern const float lbl_805E9FA8;
extern const float lbl_805E9FAC;
extern const void* const lbl_806658C0[];
extern const void* const lbl_80664008[];
extern const void* const lbl_80665650[];
extern const void* const lbl_80665828[];
extern const void* const lbl_80665860[];
extern const void* const lbl_806659F8[];
extern const void* const lbl_80693CAC[];
extern char lbl_806EF9DD;
extern int lbl_8061FF54[];
extern int lbl_8061FF64;
extern int lbl_8061FF6C;
extern int lbl_8061FF74;
extern int lbl_8061FF78[];
extern int lbl_8062C290;
extern const float lbl_805EA540;
extern const float lbl_805EA544;
extern const float lbl_805EA564;
extern const char lbl_805E7988[];
extern const char* lbl_8061FF8C[];
extern int lbl_8061FF88;
extern int lbl_80691480[];

extern "C" {
void fn_80328374(void* p, int a);
void fn_803E6B3C(void* p);
void fn_803E6B74(void* p);
void fn_803E6C28(void* p, int n);
void fn_803E69D8(void* p, const char* name, void* data, int size, int count);
void fn_803E6950(void* p, const char* name);
void fn_803E67A0(void* p, void* q);
void fn_803E68B0(void* p, int n);
void fn_803DBDD8(void* p, int n);
void fn_803DBE18(void* p, int n);
void fn_803DBE38(void* p, int n);
void fn_803DBE20(void* p, int n);
void fn_803DBE68(void* p, int n);
void fn_803DBE78(void* p, int n);
void fn_803DBD54(void* p);
void fn_803E6660(void* p);
int fn_8040B574(const char* a, const char* b);
void fn_8040B61C(void* p, int a);
void* fn_803774A8(unsigned size, int heap);
void fn_8035F77C(void* p);
void fn_80328234(void* p, int a, int b);
int fn_803E9B98(const void* a, void* b);
void* fn_8037C7FC();
void* fn_8037CF5C(void* c, unsigned hash, void* obj);
void fn_80377488(void* p);
void fn_80377408(void* p);
void fn_803E6708(void* p, int a);
void fn_803DBD84(void* p, int a);
}

extern "C" {
// PROTOS-BEGIN
void fn_80317B88(Fx* self, int a);
void fn_80317F30(Fx* self, int a);
void fn_8031883C(Fx* self);
void fn_80318890(Fx* self);
void fn_803188C4(Fx* self);
void fn_803188F0(Fx* self);
void fn_803191AC(Fx* self, int tex);
FxList* fn_80319218(FxList* self);
void fn_8031925C(Unk802A6334* self);
Unk802A6334_Node* fn_80319310(Unk802A6334* self, void* obj, int key);
FxP* fn_80319330(Unk802A6334* self, int key);
void fn_80319360(Unk802A6334* self);
void fn_803193F0(FxReg* self, int a);
void fn_80319424(FxReg* self);
int fn_8031945C(FxRegV* self);
int fn_80319490(void* self, int* tbl, int val, int a, int b, int c);
int fn_803194F4(FxReg* self, int a, int b, int c, int d);
FxCfg* fn_80319534(FxCfg* self);
FxCfg* fn_8031984C();
void* fn_8031987C(const char* s);
FxB* fn_80319A58(FxB* self, int n);
void fn_80319B7C(FxB* self, int a);
void fn_80319C2C(FxB* self, int id);
void fn_80319CD4();
void fn_80319D20();
void fn_8031A760(FxB* self, int tex);
FxC* fn_8031A7CC(FxC* self, int a);
void fn_8031A8B0(FxC* self, int a);
int fn_8031A8E0(const char* name);
void fn_8031AC74();
void fn_8031B0E8(FxRec* self, int a);
void fn_8031B0F0(FxC* self, const char* name, int val);
void fn_8031B228(FxC* self, int i);
void fn_8031B250(FxC* self, int i, int a, float f, FxSrc* b);
void fn_8031B27C(FxC* self, int i);
// PROTOS-END
void fn_80319D78(FxB* self);
}

// FUNCS-BEGIN

void fn_80317B88(Fx* self, int a) {
    self->m18 = lbl_806658C0;
    if (self->m13C) { fn_80377488(self->m13C); self->m13C = 0; }
    if (self->m140) { fn_80377488(self->m140); self->m140 = 0; }
    if (self->m144) { fn_80377488(self->m144); self->m144 = 0; }
    for (int i = 0; i < 6; i++) {
        if (self->m148[i]) { fn_80377488(self->m148[i]); self->m148[i] = 0; }
    }
    if (self->m30) fn_80377488(self->m30);
    if (self->m34) fn_80377488(self->m34);
    if (self->m38) fn_80377488(self->m38);
    lbl_8061FF44 = 0;
    fn_803E6708(self->mB8, 2);
    fn_803DBD84(self->m7C, 2);
    fn_80328374(self, a);
}

void fn_80317F30(Fx* self, int a) { self->m24 = a; }

void fn_8031883C(Fx* self) {
    if (self->m24 != 0) fn_803188F0(self);
    else fn_803188C4(self);
    lbl_8061FF50 = 0;
    self->m24 = 0;
}

void fn_80318890(Fx* self) {
    fn_803188C4(self);
    fn_803188F0(self);
}

void fn_803188C4(Fx* self) {
    for (int i = 0; i < 6; i++) self->m124[i] = 0;
    self->m118 = 0;
    self->m120 = 0;
}

void fn_803188F0(Fx* self) { self->m11C = 0; }

/* Texture-state refresh: rebuilds the vertex description (fn_803191AC, fn_8031A760). */
void fn_803191AC(Fx* self, int tex) {
    char* r = self->mB8;
    fn_803E6B3C(r);
    fn_803E69D8(r, lbl_805E8A0C, (void*)tex, 0x58, -1);
    fn_803E6B74(r);
    fn_803E6C28(r, self->m28 * 6);
}

FxList* fn_80319218(FxList* self) {
    self->m1C = lbl_80664008;
    new ((void*)self) Unk802A6334(0, 5);
    return self;
}

void fn_8031925C(Unk802A6334* self) {
    Unk802A6334_Node* n = self->mC;
    int first = 0;
    while (n) {
        FxP* p = (FxP*)n->m0;
        if (first == 0) {
            first = 1;
            p->s2();
        }
        if (p->m4 == 0x19) p->s5(lbl_806EF9DD);
        else p->s4();
        n = n->m8;
    }
}

Unk802A6334_Node* fn_80319310(Unk802A6334* self, void* obj, int key) {
    return self->fn_802A6458(obj, key);
}

FxP* fn_80319330(Unk802A6334* self, int key) {
    for (Unk802A6334_Node* n = self->mC; n; n = n->m8) {
        if (((FxP*)n->m0)->m4 == key) return (FxP*)n->m0;
    }
    return 0;
}

void fn_80319360(Unk802A6334* self) {
    Unk802A6334_Node* n;
    while ((n = self->mC) != 0) {
        FxP* p = (FxP*)n->m0;
        self->fn_802A63F8(n);
        if (p) delete p;
    }
}

// fn_803193CC
FxReg::FxReg() {
    m4 = lbl_80665828;
    m0 = 0;
    lbl_8061FF64 = (int)this;
}

void fn_803193F0(FxReg* self, int a) {
    self->m4 = lbl_80665828;
    if (a & 1) fn_80377408(self);
}

void fn_80319424(FxReg* self) { self->m0 = (int)fn_8031987C(lbl_805E9CC8); }

int fn_8031945C(FxRegV* self) { return self->s5(); }

int fn_80319490(void* self, int* tbl, int val, int a, int b, int c) {
    int k = 0;
    if (a) k = 2;
    if (b) k = 1;
    if (c) k = 3;
    for (int i = 0; i < 3; i++) {
        char* base = (char*)tbl + 4;
        int off = i * 4 + k * 12;
        if (val > *(int*)(base + off)) return i;
    }
    return 3;
}

int fn_803194F4(FxReg* self, int a, int b, int c, int d) {
    return fn_80319490(self, (int*)self->m0, a, b, c, d);
}

FxCfg* fn_80319534(FxCfg* self) {
    new ((void*)self) Unk8037B3E8(0xCED26CE8U);
    self->m0 = lbl_80665860;
    self->m34 = 0;
    self->m38 = 1;
    self->m3C = 1;
    self->m40 = 1;
    self->m44 = 0;
    self->m48 = 1;
    self->m4C = 1;
    self->m50 = 1;
    self->m54 = 1;
    self->m58 = 1;
    return self;
}

FxCfg* fn_8031984C() { return fn_80319534((FxCfg*)operator new(0x5C, lbl_806EF9B4)); }

void* fn_8031987C(const char* s) { return fn_8037CF5C(fn_8037C7FC(), 0xCED26CE8, (void*)s); }

FxB* fn_80319A58(FxB* self, int n) {
    char* sub = (char*)self + 0x38;
    int k = n - 1;
    int zero = 0;
    char tmp[8];
    fn_80328234(self, 0x13, 0);
    self->m18 = lbl_80665650;
    self->m38 = lbl_80693CAC;
    *(int*)(sub + 4) = zero;
    *(int*)(sub + 0x14) = fn_803E9B98(lbl_805E79A4, tmp);
    *(int*)(sub + 0x10) = 1;
    fn_803DBD54(self->m78);
    fn_803E6660(self->mB4);
    lbl_8061FF74 = (int)self;
    self->m28 = zero;
    self->mF0 = n;
    FxPart* arr = (FxPart*)fn_803774A8(n * 0x98, 0);
    FxPart* q = arr;
    if (n != 0) {
        do {
            fn_8035F77C(q);
            q++;
        } while (k-- != 0);
    }
    int n6 = n * 6;
    self->mF8 = arr;
    self->mF4 = 0;
    self->m24 = 0;
    self->m2C = (char*)fn_803774A8(n * 0x48, 0);
    self->m30 = (char*)fn_803774A8(n6 * 8, 0);
    self->m34 = (char*)fn_803774A8(n6 * 4, 0);
    self->mF4 = 0;
    fn_80319D78(self);
    return self;
}

void fn_80319B7C(FxB* self, int a) {
    self->m18 = lbl_80665650;
    if (self->mF8) { fn_80377488(self->mF8); self->mF8 = 0; }
    if (self->m2C) fn_80377488(self->m2C);
    if (self->m30) fn_80377488(self->m30);
    if (self->m34) fn_80377488(self->m34);
    lbl_8061FF74 = 0;
    fn_803E6708(self->mB4, 2);
    fn_803DBD84(self->m78, 2);
    fn_80328374(self, a);
}

void fn_80319C2C(FxB* self, int id) {
    int i = 0;
    while (i < self->mF4) {
        FxPart* d = &self->mF8[i];
        if (d->m90 == id) {
            int n = --self->mF4;
            FxPart* s = (FxPart*)(n * 0x98 + (int)self->mF8);
            *d = *s;
        } else {
            i++;
        }
    }
}

void fn_80319CD4() {
    if (lbl_8061FF74 == 0) lbl_8061FF74 = (int)fn_80319A58((FxB*)operator new(0xFC, 0), 0x5D);
}

void fn_80319D20() {
    FxBV* o = (FxBV*)lbl_8061FF74;
    if (o) {
        delete o;
        lbl_8061FF74 = 0;
    }
}

void fn_8031A760(FxB* self, int tex) {
    char* r = self->mB4;
    fn_803E6B3C(r);
    fn_803E69D8(r, lbl_805E8A0C, (void*)tex, 0x58, -1);
    fn_803E6B74(r);
    fn_803E6C28(r, self->m24 * 6);
}

FxC* fn_8031A7CC(FxC* self, int a) {
    fn_80328234(self, 0xD, a);
    self->m70 = 0;
    self->m18 = lbl_806659F8;
    self->m24 = 0;
    for (int i = 0; i < 5; i++) {
        self->a74[i].m0 = 0;
        self->a74[i].m4 = lbl_805EA540;
        self->a74[i].mC = lbl_805EA544;
        self->a74[i].m8 = lbl_805EA544;
        self->a74[i].m10 = 1;
    }
    for (int i = 0; i < 5; i++) {
        self->aD8[i].m0 = 0;
        self->aD8[i].m4 = lbl_805EA540;
        self->aD8[i].mC = lbl_805EA544;
        self->aD8[i].m8 = lbl_805EA544;
        self->aD8[i].m10 = 1;
    }
    self->m14 = 0;
    fn_8040B61C(self, lbl_8061FF88);
    return self;
}

void fn_8031A8B0(FxC* self, int a) {
    self->m18 = lbl_806659F8;
    fn_80328374(self, a);
}

/* Name/value lookup in lbl_8061FF8C (0x6A entries), -1 if absent. */
int fn_8031A8E0(const char* name) {
    for (int i = 0; i <= 0x69; i++) {
        if (fn_8040B574(name, lbl_8061FF8C[i]) == 0) return i;
    }
    return -1;
}

// fn_8031AC48
FxRec::FxRec() {
    m3C = 0;
    m38 = -1;
    m28 = 0;
    m2C = 0;
    name[0] = lbl_805E7988[0];
}

void fn_8031AC74() {}

void fn_8031B0E8(FxRec* self, int a) { self->m3C = (float*)a; }

void fn_8031B0F0(FxC* self, const char* name, int val) {
    for (int i = 0; i < self->m70; i++) {
        if (fn_8040B574((char*)self->m24 + i * 0x40, name) == 0) fn_8031B0E8((FxRec*)((char*)self->m24 + i * 0x40), val);
    }
}

void fn_8031B228(FxC* self, int i) {
    int off = i * 12 + 0x28;
    FxSlot* s = (FxSlot*)((char*)self + off);
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = lbl_805EA564;
}

void fn_8031B250(FxC* self, int i, int a, float f, FxSrc* b) {
    int off = i * 12 + 0x28;
    FxSlot* s = (FxSlot*)((char*)self + off);
    s->m0 = a;
    s->m4 = b;
    s->m8 = f;
}

void fn_8031B27C(FxC* self, int i) {
    int off = i * 12 + 0x28;
    *(FxSlot*)((char*)self + off) = self->a28[1];
}
