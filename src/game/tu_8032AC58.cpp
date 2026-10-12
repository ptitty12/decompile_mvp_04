/*
 * Game code, .text 0x8032AC58-0x8032ECD8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"
class FxSldW;
class FxPairW;
class FxTripW;

extern const float lbl_805ECD2C;
extern const float lbl_805ECD30;
extern const float lbl_805ECD34;
extern const float lbl_805ED8BC;
extern const char lbl_805ED8C0[];
extern FxApp* lbl_8061B8C0;
extern int lbl_8061B998;
extern FxV2f lbl_80691B00;
extern FxV2f lbl_80691B08;
extern FxCtx* lbl_8061FEDC;
extern int lbl_806203F0;
extern int lbl_806203F4;
extern int lbl_806203F8;
extern int lbl_806203FC;

extern const char lbl_805ED994[];
extern const float lbl_805ED99C;
extern const char lbl_805ED8D4[];
extern const char lbl_805ED8E4[];
extern const char lbl_805ED8F4[];
extern const float lbl_805ED904;
extern const char lbl_805ED918[];
extern const char lbl_805ED934[];
extern const char lbl_805ED950[];
extern const char lbl_805ED96C[];
extern const float lbl_805ED980;
extern "C" {
void fn_801A750C(void* v, int a);
float fn_801C3370(void* p);
float fn_801A0744(FxView* v);
void fn_801A0790(FxView* v, float f);
void fn_80331294(void* p);
void fn_802D7ACC();
void fn_80330BC8();
void fn_8032C1D0(char* p);
void fn_801828AC(FxViewD* d);
int fn_8040B6A0(const char* s);
void fn_8033E958(const char* fmt, ...);
void* fn_8040B830(void* dst, const void* src, int n);
void fn_8032D8F8(void* self, float f);
void fn_80313E94(FxCtx* c, int v);
float fn_80313F28(FxCtx* c, const void* s);
void fn_80330B48(void* p);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_803144A0(FxCtx* c, const char* s, float x, float y, int a, int b);
// PROTOS-BEGIN
void fn_8032B6C0();
void fn_8032B748();
void fn_8032B7B4();
void fn_8032BA5C();
void fn_8032BA7C(FxPages* self);
void fn_8032C1CC();
void fn_8032D29C();
void fn_8032D36C();
void fn_8032D378();
void fn_8032D6E4(FxPages* self);
void fn_8032D7C4();
void fn_8032D868(FxCmd* self, int a);
void fn_8032D880(FxCmd* self, const void* src);
int fn_8032D8C8();
void fn_8032D8D0(void* unused);
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
void fn_8032E968(FxSldF* self);
FxIntD* fn_8032EB84(FxIntD* self, int name, int* a, int b, int c, int d, int e);
FxIntD* fn_8032EC38(FxIntD* self, int name, int a, int b, int c, int d);
FxSldW* fn_8032E70C(FxSldW* self, int name, float a, float b, float c, float d);
FxSldW* fn_8032E7C0(FxSldW* self, int name, float* p, float* q, float a, float b, float c);
FxSldW* fn_8032E894(FxSldW* self, int name, float* p, float a, float b, float c, float d);
FxPairW* fn_8032DC2C(FxPairW* self, int name, FxInt2* a, int b, float* c, FxInt2 d, FxInt2 e, FxInt2 f);
FxPairW* fn_8032DD00(FxPairW* self, int name, int a, FxInt2 d, FxInt2 e, FxInt2 f, float g);
FxTripW* fn_8032E0B4(FxTripW* self, int name, FxInt3* a, int b, float* c, int d, FxInt3 e, FxInt3 f, FxInt3 g);
FxTripW* fn_8032E1DC(FxTripW* self, int name, int a, int b, FxInt3 e, FxInt3 f, FxInt3 g, float h);
void fn_8032DDD0(FxPairW* self);
void fn_803145D8(FxCtx* c, const void* s, int color, float x, float y, int b);
void fn_8032E38C(FxTripW* self);
// PROTOS-END
}

extern const void* const lbl_80666C90[];
extern const void* const lbl_80666CE0[];
extern const void* const lbl_80666D80[];
extern const void* const lbl_80666D30[];
/* Int-triple widget (vtable lbl_80666D30; ctors fn_8032E0B4, fn_8032E1DC). */
class FxTripW : public FxListV {
public:
    int mC;
    char pad10[0x38];
    FxInt3* m48;
    FxInt3 m4C;
    float* m58;
    float m5C;
    FxInt3 m60;
    FxInt3 m6C;
    FxInt3 m78;
    int m84;
    int m88;
    int m8C;
    int m90;
};
inline void FxTripSet(FxTripW* self) {
    FxInt3 v = self->m60;
    fn_8032E344((FxCmd*)self, &v);
}
/* Int-pair widget (vtable lbl_80666D80; ctors fn_8032DC2C, fn_8032DD00). */
class FxPairW;
class FxTripW;
inline void FxPairSet(FxPairW* self, FxInt2 v) { fn_8032E088((FxCmd*)self, &v); }
class FxPairW : public FxListV {
public:
    int mC;
    char pad10[0x38];
    FxInt2* m48;
    FxInt2 m4C;
    float* m54;
    float m58;
    FxInt2 m5C;
    FxInt2 m64;
    FxInt2 m6C;
    int m74;
    int m78;
};
/* Float-entry widget (vtable lbl_80666CE0; ctors fn_8032E70C, fn_8032E7C0, fn_8032E894). */
class FxSldW : public FxListV {
public:
    int mC;
    char pad10[0x38];
    float* m48;
    float m4C;
    int m50;
    float m54;
    float m58;
    float m5C;
    float m60;
};
inline void FxSldSet(FxSldW* self, float v) {
    if (self->m48 == 0) self->m4C = v;
    else *self->m48 = v;
}
/* Inlined mid-level widget ctor (vtable lbl_80666E70): root, mC = 0, set the name. */
inline void FxWidInit(FxListD* self, int name) {
    FxRootInit(self);
    *(const void**)((char*)self + 8) = lbl_80666E70;
    self->mC = 0;
    fn_8032D868((FxCmd*)self, name);
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

void fn_8032D29C() {
    char a[0x2800] = "";
    char b[0x201] = "";
    int pos = 0;
    fn_8032C1D0(a);
    int total = fn_8040B6A0(a);
    while (pos < total) {
        char* p = a + pos;
        int n = fn_8040B6A0(p);
        if (n > 0x200) n = 0x200;
        fn_8040B830(b, p, n);
        pos += n;
        b[n] = 0;
        fn_8033E958(b);
    }
}

void fn_8032D36C() { char buf[0x60]; }

void fn_8032D378() {
    int a = lbl_806203F0;
    int b = lbl_806203F4;
    int c = lbl_806203F8;
    fn_80330BC8();
    if (a != lbl_806203F0 || b != lbl_806203F4 || c != lbl_806203F8) lbl_806203FC = 0;
}

void fn_8032D6E4(FxPages* self) {
    FxView* v = lbl_8061B8C0->m8;
    int zero = 0;
    FxV2f t;
    {
        FxViewD* d = v->m6B8;
        t.x = d->a54;
        t.y = d->a58;
        lbl_80691B00 = t;
    }
    {
        FxViewD* d = v->m6B8;
        t.x = d->a5C;
        t.y = d->a60;
        lbl_80691B08 = t;
    }
    self->m204 = zero;
    self->m208 = zero;
    self->a0[self->m174]->s3();
    self->m174 = zero;
    self->a0[zero]->s2();
}

/* near-miss: rect copy; retail copies the globals through GPRs and the local copy through FPRs */
void fn_8032D7C4() {
    FxViewD* d = lbl_8061B8C0->m8->m6B8;
    FxRect4 r1;
    r1.p = lbl_80691B00;
    r1.q = lbl_80691B08;
    FxRect4 r2 = r1;
    d->a54 = r2.p.x;
    d->a58 = r2.p.y;
    d->a5C = r2.q.x;
    d->a60 = r2.q.y;
    fn_801828AC(d);
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

void fn_8032D8D0(void* unused) { fn_8032D8F8(unused, lbl_805ED8BC); }

/* near-miss (99.86%): only the lis/ori pair building the color constant 0x80606060 differs; the split object has a
 * synthesized reloc to lbl_80606060 (a string that happens to sit at that address), a plain constant cannot reproduce it */
void fn_8032D8F8(void* p, float maxw) {
    FxLabelD* self = (FxLabelD*)p;
    FxCtx** pc = &lbl_8061FEDC;
    float w = fn_80313F28(*pc, (const void*)self->s6());
    if (!(self->m0 + w <= maxw)) {
        ((void (*)(FxCtx*, float, float, const void*, int, int))fn_803145D8)(*pc, self->m0, self->m4, (const void*)self->s6(), self->mC != 0 ? 0x80A0A0A0 : 0x80606060, 0x16);
    } else {
        ((void (*)(FxCtx*, float, float, const void*, int, int))fn_803144A0)(*pc, self->m0, self->m4, (const void*)self->s6(), self->mC, 0x16);
    }
}

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
    fn_803144A0(lbl_8061FEDC, buf, self->m0, self->m4, self->mC, 0x16);
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

FxPairW* fn_8032DC2C(FxPairW* self, int name, FxInt2* a, int b, float* c, FxInt2 d, FxInt2 e, FxInt2 f) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666D80;
    self->m48 = a;
    self->m54 = c;
    self->m58 = *c;
    self->m5C = d;
    self->m64 = e;
    self->m6C = f;
    self->m74 = b;
    self->m78 = 0;
    FxPairSet(self, self->m5C);
    return self;
}

FxPairW* fn_8032DD00(FxPairW* self, int name, int a, FxInt2 d, FxInt2 e, FxInt2 f, float g) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666D80;
    self->m48 = 0;
    self->m54 = 0;
    self->m58 = g;
    self->m5C = d;
    self->m64 = e;
    self->m6C = f;
    self->m74 = a;
    self->m78 = 0;
    FxPairSet(self, self->m5C);
    return self;
}

void fn_8032DDD0(FxPairW* self) {
    char buf[0x30];
    FxV2f v = ((FxV2f (*)(FxCmd*))fn_8032E054)((FxCmd*)self);
    if (self->m74 == 0) {
        if (self->m78 == 0)
            fn_804089B4(buf, lbl_805ED8D4, v.x, v.y);
        else
            fn_804089B4(buf, lbl_805ED8E4, v.x, v.y);
    } else {
        fn_804089B4(buf, lbl_805ED8F4, v.x, v.y);
    }
    float w = lbl_805ED904 - fn_80313F28(lbl_8061FEDC, buf);
    fn_8032D8F8(self, w);
    fn_803144A0(lbl_8061FEDC, buf, w, self->m4, self->mC, 0x16);
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

/* near-miss: order of the three loads/stores in the struct copy */
FxTripW* fn_8032E0B4(FxTripW* self, int name, FxInt3* a, int b, float* c, int d, FxInt3 e, FxInt3 f, FxInt3 g) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666D30;
    self->m48 = a;
    self->m58 = c;
    self->m5C = *c;
    self->m60 = e;
    self->m6C = f;
    self->m78 = g;
    self->m84 = b;
    self->m88 = 0;
    self->m8C = 3;
    self->m90 = d;
    FxTripSet(self);
    return self;
}

FxTripW* fn_8032E1DC(FxTripW* self, int name, int a, int b, FxInt3 e, FxInt3 f, FxInt3 g, float h) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666D30;
    self->m48 = 0;
    self->m58 = 0;
    self->m5C = h;
    self->m60 = e;
    self->m6C = f;
    self->m78 = g;
    self->m84 = a;
    self->m88 = 0;
    self->m8C = 3;
    self->m90 = b;
    FxTripSet(self);
    return self;
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

void fn_8032E38C(FxTripW* self) {
    FxF3 v = ((FxF3 (*)(FxCmd*))fn_8032E2FC)((FxCmd*)self);
    char buf[0x30];
    char fmt[0x30];
    if (self->m84 == 0) {
        switch (self->m88) {
        case 0:
            fn_804089B4(fmt, lbl_805ED918, self->m90, self->m90, self->m90);
            break;
        case 1:
            fn_804089B4(fmt, lbl_805ED934, self->m90, self->m90, self->m90);
            break;
        case 2:
            fn_804089B4(fmt, lbl_805ED950, self->m90, self->m90, self->m90);
            break;
        }
        fn_804089B4(buf, fmt, v.x, v.y, v.z);
    } else {
        fn_804089B4(buf, lbl_805ED96C, v.x, v.y, v.z);
    }
    char* p = buf;
    float w = lbl_805ED980 - fn_80313F28(lbl_8061FEDC, p);
    fn_8032D8F8(self, w);
    fn_803144A0(lbl_8061FEDC, p, w, self->m4, self->mC, 0x16);
}

FxSldW* fn_8032E70C(FxSldW* self, int name, float a, float b, float c, float d) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666CE0;
    self->m48 = 0;
    self->m50 = 0;
    self->m54 = b;
    self->m58 = a;
    self->m5C = c;
    self->m60 = d;
    FxSldSet(self, self->m58);
    return self;
}

FxSldW* fn_8032E7C0(FxSldW* self, int name, float* p, float* q, float a, float b, float c) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666CE0;
    self->m48 = p;
    self->m4C = *p;
    self->m50 = (int)q;
    self->m54 = *q;
    self->m58 = a;
    self->m5C = b;
    self->m60 = c;
    FxSldSet(self, self->m58);
    return self;
}

FxSldW* fn_8032E894(FxSldW* self, int name, float* p, float a, float b, float c, float d) {
    FxWidInit((FxListD*)self, name);
    *(const void**)((char*)self + 8) = lbl_80666CE0;
    self->m48 = p;
    self->m4C = *p;
    self->m50 = 0;
    self->m54 = b;
    self->m58 = a;
    self->m5C = c;
    self->m60 = d;
    FxSldSet(self, self->m58);
    return self;
}

void fn_8032E968(FxSldF* self) {
    char buf[0x30];
    fn_804089B4(buf, lbl_805ED994, self->m48 == 0 ? self->m4C : *self->m48);
    float w = lbl_805ED99C - fn_80313F28(lbl_8061FEDC, buf);
    fn_8032D8D0(self);
    fn_803144A0(lbl_8061FEDC, buf, w, self->m4, self->mC, 0x16);
}

FxIntD* fn_8032EB84(FxIntD* self, int name, int* a, int b, int c, int d, int e) {
    FxWidInit((FxListD*)self, name);
    self->m50 = c;
    *(const void**)((char*)self + 8) = lbl_80666C90;
    self->m58 = d;
    self->m5C = e;
    self->m48 = (int)a;
    self->m54 = b;
    self->m60 = 1;
    self->m64 = 0;
    if (a) *a = b;
    else self->m4C = b;
    return self;
}

FxIntD* fn_8032EC38(FxIntD* self, int name, int a, int b, int c, int d) {
    FxWidInit((FxListD*)self, name);
    self->m50 = b;
    *(const void**)((char*)self + 8) = lbl_80666C90;
    self->m58 = c;
    self->m5C = d;
    self->m48 = 0;
    self->m54 = a;
    self->m60 = 1;
    self->m64 = 0;
    self->m4C = a;
    return self;
}
