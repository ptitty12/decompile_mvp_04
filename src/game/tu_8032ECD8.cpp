/*
 * Game code, .text 0x8032ECD8-0x80331C60 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern const char lbl_805ED9C0[];
extern const float lbl_805ED9E0;
extern const float lbl_805EDAAC;
extern const float lbl_805EDAB0;
extern const float lbl_805EDAB4;
extern const void* const lbl_80666EC0[];
extern const void* const lbl_80666E70[];
extern const void* const lbl_80666C40[];
extern const void* const lbl_80666B70[];
extern const void* const lbl_80666A18[];
extern FxApp* lbl_8061B8C0;
extern int lbl_8061B998;
extern FxCtx* lbl_8061FEDC;
extern char** lbl_80691DC4;
extern FxModal* lbl_80620410;
extern int lbl_80620414;
extern int lbl_8062042C;
extern int lbl_8061EDFC;
extern int lbl_80620298;
extern int lbl_8061EDC0;
extern int lbl_8061FE90;
extern int lbl_8061FDCC;
extern int lbl_8068B4BC;
extern int lbl_8061FE94;
extern int lbl_8061FE9C;
extern int lbl_8061C8F8;
extern int lbl_80620134;
extern int lbl_8061B898;

struct FxViewB { int pad[3]; int mC; int m10; };

extern "C" {
void fn_80313F28(FxCtx* c, const void* s);
int fn_8032D8C8();
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_8032D868(void* self, int a);
int fn_8032F684(FxListD* self, int a, int b);
void fn_803E4B40(void* p, int a);
void fn_80377408(void* p);
void* fn_803774A8(unsigned size, int heap);
void fn_80377488(void* p);
void fn_8040A208(void* base, int n, int size, int (*cmp)(int*, int*));
void fn_8035F8CC(void* idx, int a, int n);
void fn_8035F95C(void* idx, char** names, int n);
void fn_802D8294(int a);
void fn_801A750C(void* v, int a);
FxViewB* fn_801A4CE8(FxView* v, int a);
void fn_802D7ACC();
void fn_8033E6DC();
void fn_80331508();
int fn_8040B574(const char* a, const char* b);
// PROTOS-BEGIN
void fn_8032ED80(FxListD* self);
FxListD* fn_8032F120(FxListD* self, int a, int b);
void fn_8032F574(FxListD* self, int a);
void fn_8032F5AC(FxListD* self);
int fn_8032F5C4(FxListD* self, int k);
int fn_8032F620(FxListD* self, int k);
void fn_8032FB24(FxListD* self);
void fn_8032FB78(FxListD* self, int a);
int fn_8032FBCC(int* a, int* b);
void fn_8032FC0C(int a, char** names, int n);
int fn_80330018(FxCmd* self, int k);
void fn_80330870(FxModal* self, int a);
void fn_80330ACC(FxStack* self, int v);
void fn_80330B08(FxStack* self, int v);
void fn_80330B48(FxModal* self);
void fn_80331234(FxModal* self);
void fn_80331294(FxModal* self);
void fn_803312E0(FxStackF* self);
float fn_80331394();
void fn_803313A0();
void fn_8033140C();
void fn_80331468();
void fn_803314B8();
void fn_80331508();
void fn_80331548();
void fn_80331568();
void fn_803318CC();
// PROTOS-END
}

// FUNCS-BEGIN

/* near-miss: argument evaluation order and frame size */
void fn_8032ED80(FxListD* self) {
    char buf[0x38];
    fn_804089B4(buf, lbl_805ED9C0, self->s6(), self->m48 ? *self->m48 : self->m4C);
    fn_80313F28(lbl_8061FEDC, buf);
}

/* near-miss: retail keeps the first of the two vptr stores; ours drops it */
FxListD* fn_8032F120(FxListD* self, int a, int b) {
    *(const void**)((char*)self + 8) = lbl_80666EC0;
    self->mC = 0;
    *(const void**)((char*)self + 8) = lbl_80666E70;
    self->m4 = self->m0 = lbl_805ED9E0;
    fn_8032D868(self, a);
    self->m48 = 0;
    self->m4C = b;
    *(const void**)((char*)self + 8) = lbl_80666C40;
    self->m50 = b;
    return self;
}

void fn_8032F574(FxListD* self, int a) {
    self->m4C = a;
    self->s11();
}

void fn_8032F5AC(FxListD* self) {
    if (self->m48) *self->m48 = self->m4C;
}

int fn_8032F5C4(FxListD* self, int k) {
    while (k > 0) {
        int j = k - 1;
        if (fn_8032F684(self, j, k) == 0) break;
        k = j;
    }
    return k;
}

int fn_8032F620(FxListD* self, int k) {
    while (k < self->m54 - 1) {
        int j = k + 1;
        if (fn_8032F684(self, k, j) == 0) break;
        k = j;
    }
    return k;
}

void fn_8032FB24(FxListD* self) {
    if (self->m48) *self->m48 = self->s9();
}

void fn_8032FB78(FxListD* self, int a) {
    for (int i = 0; i < self->m54; i++) {
        if (self->m60[i] == a) {
            fn_8032F574(self, i);
            break;
        }
    }
}

int fn_8032FBCC(int* a, int* b) {
    return fn_8040B574(lbl_80691DC4[*a], lbl_80691DC4[*b]);
}

void fn_8032FC0C(int a, char** names, int n) {
    int* idx = (int*)fn_803774A8(n * 4, 0x100);
    for (int i = 0; i < n; i++) idx[i] = i;
    lbl_80691DC4 = names;
    fn_8040A208(idx, n, 4, fn_8032FBCC);
    fn_8035F8CC(idx, a, n);
    fn_8035F95C(idx, names, n);
    if (idx) fn_80377488(idx);
}

/* near-miss: switch tree (retail splits at <3 / >4 and reuses the compare with 3 in cr7) */
int fn_80330018(FxCmd* self, int k) {
    int r = fn_8032D8C8();
    if (r == 0) {
        switch (k) {
        case 3:
            ((FxEmb*)((char*)self + 0x48))->s7();
            r = 1;
            break;
        case 4:
            ((FxEmb*)((char*)self + 0x48))->s6();
            r = 1;
            break;
        case 7:
            r = 1;
            break;
        }
    }
    return r;
}

/* near-miss: store order of lbl_80620410 / lbl_80620414 clears */
void fn_80330870(FxModal* self, int a) {
    *(const void**)((char*)self + 0x2DC) = lbl_80666A18;
    if (self == lbl_80620410) {
        lbl_80620414 = 0;
        lbl_80620410 = 0;
    }
    fn_803E4B40((char*)self + 0x210, 2);
    if (a & 1) fn_80377408(self);
}

void fn_80330ACC(FxStack* self, int v) {
    self->a0[self->m178] = v;
    self->m178 = self->m178 + 1;
    fn_803312E0((FxStackF*)self);
}

void fn_80330B08(FxStack* self, int v) {
    self->a17C[self->m1FC] = v;
    self->m1FC = self->m1FC + 1;
    fn_803312E0((FxStackF*)self);
}

void fn_80330B48(FxModal* self) {
    FxModal* cur = lbl_80620410;
    if (cur != 0 && lbl_80620414 != 0) cur->s3();
    lbl_80620410 = self;
    self->s2();
}

void fn_80331234(FxModal* self) {
    lbl_80620414 = 1;
    self->s2();
    if (lbl_8061EDFC) lbl_8062042C = lbl_8061EDFC;
    fn_802D8294(4);
}

void fn_80331294(FxModal* self) {
    lbl_80620414 = 0;
    self->s3();
    fn_802D8294(lbl_8062042C);
}

void fn_803312E0(FxStackF* self) {
    self->m20C = lbl_805EDAAC;
    for (int i = 0; i < self->m178; i++) {
        float v = self->a0[i]->s7();
        if (!(v <= self->m20C)) self->m20C = v;
    }
    self->m20C = self->m20C >? lbl_805EDAB0;
}

float fn_80331394() { return lbl_805EDAB4; }

void fn_803313A0() {
    FxView* v = lbl_8061B8C0->m8;
    int arg = 1;
    if (v->m744->m20 == 1) arg = 0;
    fn_801A750C(v->m744, arg);
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_8033140C() {
    int t = 1;
    if (lbl_80620298 == 1) t = 0;
    lbl_80620298 = t;
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_80331468() {
    FxApp* a = lbl_8061B8C0;
    a->m20 = 3;
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    a->m24 = 0;
    fn_802D7ACC();
}

void fn_803314B8() {
    FxApp* a = lbl_8061B8C0;
    a->m20 = 1;
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    a->m24 = 0;
    fn_802D7ACC();
}

void fn_80331508() {
    fn_80331294((FxModal*)((char*)lbl_8061B998 + 0x24));
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_80331548() { fn_8033E6DC(); }

void fn_80331568() {
    lbl_8061EDC0 = 0;
    FxView* v = lbl_8061B8C0->m8;
    int t = 1;
    if (fn_801A4CE8(v, 1)->mC == 1) t = 0;
    fn_801A4CE8(v, 1)->m10 = 0;
    fn_801A4CE8(v, 1)->mC = t;
    fn_80331508();
}

void fn_803318CC() {
    lbl_8061FE9C = 0;
    lbl_8061FE90 = 1;
    lbl_80620134 = 0;
    lbl_8061FDCC = 0;
    lbl_8061FE94 = 1;
    lbl_8061B898 = 0;
    lbl_8068B4BC = 0;
    lbl_8061C8F8 = 0;
}
