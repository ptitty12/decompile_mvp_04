/*
 * Game code, .text 0x8032AC58-0x8032ECD8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern const float lbl_805ECD2C;
extern const float lbl_805ECD30;
extern const float lbl_805ECD34;
extern const float lbl_805ED8BC;
extern const char lbl_805ED8C0[];
extern FxApp* lbl_8061B8C0;
extern int lbl_8061B998;
extern FxCtx* lbl_8061FEDC;
extern int lbl_806203F0;
extern int lbl_806203F4;
extern int lbl_806203F8;
extern int lbl_806203FC;

extern "C" {
void fn_801A750C(void* v, int a);
float fn_801C3370(void* p);
float fn_801A0744(FxView* v);
void fn_801A0790(FxView* v, float f);
void fn_80331294(void* p);
void fn_802D7ACC();
void fn_80330BC8();
void* fn_8040B830(void* dst, const void* src, int n);
void fn_8032D8F8(float f);
void fn_80313E94(FxCtx* c, int v);
void fn_80313F28(FxCtx* c, const void* s);
void fn_80330B48(void* p);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_803144A0(FxCtx* c, const char* s, int a, float x, float y, int b);
// PROTOS-BEGIN
void fn_8032B6C0();
void fn_8032B748();
void fn_8032B7B4();
void fn_8032BA5C();
void fn_8032BA7C(FxPages* self);
void fn_8032C1CC();
void fn_8032D36C();
void fn_8032D378();
void fn_8032D868(FxCmd* self, int a);
void fn_8032D880(FxCmd* self, const void* src);
int fn_8032D8C8();
void fn_8032D8D0();
void fn_8032DA14(FxLabelD* self);
void fn_8032DA64(FxLabelD* self);
int fn_8032DAB4(FxCmd* self, int b);
void fn_8032DB00(FxLabelD* self);
void fn_8032DB5C(FxLabelD* self);
int fn_8032DBD4(FxCmd* self, int b);
void fn_8032E054(FxInt2* out, FxCmd* src);
void fn_8032E088(FxCmd* self, FxInt2* v);
void fn_8032E2FC(FxF3* out, FxCmd* src);
void fn_8032E344(FxCmd* self, FxInt3* v);
// PROTOS-END
}

// FUNCS-BEGIN

void fn_8032B6C0() {
    FxView* v = lbl_8061B8C0->m8;
    if (v->m744->m20 == 0) fn_801A750C(v->m744, 1);
    fn_801A0790(v, fn_801C3370(v->m700->m3A4) - lbl_805ECD2C);
    fn_80331294((char*)lbl_8061B998 + 0x24);
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

void fn_8032B748() {
    int zero = 0;
    FxView* v = lbl_8061B8C0->m8;
    fn_801A0790(v, fn_801A0744(v) - lbl_805ECD30);
    fn_80331294((char*)lbl_8061B998 + 0x24);
    lbl_8061B8C0->m24 = zero;
    fn_802D7ACC();
}

void fn_8032B7B4() {
    int zero = 0;
    FxView* v = lbl_8061B8C0->m8;
    fn_801A0790(v, fn_801A0744(v) + lbl_805ECD34);
    fn_80331294((char*)lbl_8061B998 + 0x24);
    lbl_8061B8C0->m24 = zero;
    fn_802D7ACC();
}

void fn_8032BA5C() { fn_80330BC8(); }

void fn_8032BA7C(FxPages* self) {
    int zero = 0;
    self->m204 = zero;
    self->m208 = zero;
    self->a0[self->m174]->s3();
    self->m174 = zero;
    self->a0[zero]->s2();
}

void fn_8032C1CC() {}

void fn_8032D36C() { char buf[0x60]; }

void fn_8032D378() {
    int a = lbl_806203F0;
    int b = lbl_806203F4;
    int c = lbl_806203F8;
    fn_80330BC8();
    if (a != lbl_806203F0 || b != lbl_806203F4 || c != lbl_806203F8) lbl_806203FC = 0;
}

void fn_8032D868(FxCmd* self, int a) {
    self->m40 = a;
    self->m10[0] = 0;
    self->m44 = 1;
}

void fn_8032D880(FxCmd* self, const void* src) {
    fn_8040B830(self->m10, src, 0x30);
    self->m10[0x2F] = 0;
    self->m40 = 0;
    self->m44 = 0;
}

int fn_8032D8C8() { return 0; }

void fn_8032D8D0() { fn_8032D8F8(lbl_805ED8BC); }

void fn_8032DA14(FxLabelD* self) {
    FxCtx* c = lbl_8061FEDC;
    fn_80313E94(c, self->s6());
}

void fn_8032DA64(FxLabelD* self) {
    FxCtx* c = lbl_8061FEDC;
    fn_80313F28(c, (const void*)self->s6());
}

int fn_8032DAB4(FxCmd* self, int b) {
    int r = fn_8032D8C8();
    if (r == 0 && b == 0xC) {
        fn_80330B48(self->m48);
        r = 1;
    }
    return r;
}

void fn_8032DB00(FxLabelD* self) {
    char buf[0x38];
    fn_804089B4(buf, lbl_805ED8C0, self->s6());
    fn_80313F28(lbl_8061FEDC, buf);
}

void fn_8032DB5C(FxLabelD* self) {
    char buf[0x38];
    fn_804089B4(buf, lbl_805ED8C0, self->s6());
    fn_803144A0(lbl_8061FEDC, buf, self->mC, self->m0, self->m4, 0x16);
}

typedef void (*FxCb)();
int fn_8032DBD4(FxCmd* self, int b) {
    int r = fn_8032D8C8();
    if (r == 0 && b == 0xC) {
        FxCb cb = (FxCb)self->m48;
        if (cb) cb();
        r = 1;
    }
    return r;
}

void fn_8032E054(FxInt2* out, FxCmd* src) {
    FxInt2* p = (FxInt2*)src->m48;
    if (p) {
        *out = *p;
    } else {
        *out = *(FxInt2*)&src->m4C;
    }
}

void fn_8032E088(FxCmd* self, FxInt2* v) {
    FxInt2 t = *v;
    FxInt2* p = (FxInt2*)self->m48;
    if (p) *p = t;
    else *(FxInt2*)&self->m4C = t;
}

void fn_8032E2FC(FxF3* out, FxCmd* src) {
    FxF3* p = (FxF3*)src->m48;
    if (p) {
        *out = *p;
    } else {
        *out = *(FxF3*)&src->m4C;
    }
}

void fn_8032E344(FxCmd* self, FxInt3* v) {
    FxInt3* p = (FxInt3*)self->m48;
    if (p) {
        *p = *v;
    } else {
        *(FxInt3*)&self->m4C = *v;
    }
}
