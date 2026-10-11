/*
 * Game code, .text 0x8031B354-0x8031D988 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern const float lbl_805EA5E4;
extern const float lbl_805EA5E8;
extern const float lbl_805EA624;
extern const float lbl_805EA628;
extern const float lbl_805EA62C;
extern const float lbl_805EA630;
extern const float lbl_805EA634;
extern const float lbl_805EA650;
extern const float lbl_805EA654;
extern const float lbl_805EA658;
extern const float lbl_805EA668;
extern const float lbl_805EA56C;
extern const float lbl_805EA6A0;
extern const float lbl_805EA6A4;
extern const float lbl_805EA6B0;
extern const float lbl_805EA6B4;
extern const float lbl_805EA570;
extern const float lbl_805EA574;
extern const float lbl_805EA578;
extern const float lbl_805EA59C;
extern const float lbl_805EA5A0;
extern const float lbl_805EA5D8;
extern const float lbl_805EA5DC;
extern const float lbl_805EA5E0;
extern const void* const lbl_80665968[];
extern const void* const lbl_80665128[];
extern const void* const lbl_806651B8[];
extern const char* lbl_8061FF8C[];
extern int lbl_80620138;
extern int lbl_8062013C;
extern FxH* lbl_80620140;
extern FxI* lbl_80620144;
extern FxCtx* lbl_8061FEDC;
extern FxHooks lbl_80699B94;
extern int lbl_8061E9F4;

extern "C" {
void fn_8031259C(FxCtx* c);
void fn_803125D0(FxCtx* c);
void fn_8014D9EC(void* p, float a, float b, float c, float d, float e);
void fn_80314B4C(FxCtx* p);
void fn_80314854(FxCtx* p);
void fn_803ED5E0();
void fn_803EDA0C();
FxI* fn_8031CED8(FxI* self);
void fn_8038D9B4(int p, int a);
void fn_803E57F0(void* p, int a);
void fn_80328234(void* p, int a, int b);
void fn_80328374(void* p, int a);
void fn_8040B61C(void* p, int a);
int fn_8040B574(const char* a, const char* b);
int fn_8040B3B4(const char* a, const char* b);
void fn_80377408(void* p);
void fn_8031AB8C(FxRec* rec, int a, int b);
// PROTOS-BEGIN
int fn_8031B354(FxItem* self, float t);
float fn_8031B3E0(FxRec* self, float t);
void fn_8031B470(FxC* self, int id, int a, int b);
FxD* fn_8031B4EC(FxD* self, int a);
void fn_8031B5B0(FxD* self, int a);
int fn_8031B5E0(const char* name);
void fn_8031B880(FxE* self);
void fn_8031B8E4(FxE* self);
void fn_8031B93C(FxE* self, int a);
void fn_8031BE94();
void fn_8031BF58(FxD* self, int i);
void fn_8031BF80(FxD* self, int i, int a, float f, FxSrcD* b);
void fn_8031BFAC(FxD* self, int i);
void fn_8031BFD8(FxD* self, int i);
int fn_8031C074(FxItemD* self, float t);
int fn_8031C1E4(FxD* self, int id);
FxRec2* fn_8031C228(FxD* self, const char* name);
int fn_8031C2A4(FxD* self, int id, int* found, float t);
void fn_8031C454(FxD* self, int id);
FxG* fn_8031C62C(FxG* self);
void fn_8031C678(FxG* self, int a);
int fn_8031C6A8();
void fn_8031C6B4(FxG* self);
void fn_8031C6C0(FxG* self, int a, int b, int c);
void fn_8031C714(FxG* self);
void fn_8031CB4C(void* unused, float* out);
void fn_8031CBF4();
void fn_8031CBF8(void* unused, float* out);
void* fn_8031CC2C(void* self, float t);
void* fn_8031CC78(void* self, float t);
int fn_8031CCC8(FxG* self);
FxH* fn_8031CD88(FxH* self);
void fn_8031CDD4(FxH* self, int a);
FxH* fn_8031CE04();
void fn_8031CE10();
void fn_8031CE14(FxH* self);
void fn_8031CE5C(FxH* self);
void fn_8031CE68();
FxI* fn_8031CECC();
void fn_8031D014(FxI* self);
void fn_8031D0A4(FxI* self, int a);
void fn_8031D0F0();
void fn_8031D134(FxI* self);
void fn_8031D494(FxI* self, float a, float b, float c, float d);
void fn_8031D54C(FxI* self);
void fn_8031D610(FxI* self);
void fn_8031D61C(FxI* self);
// PROTOS-END
}

// FUNCS-BEGIN

int fn_8031B354(FxItem* self, float t) {
    if (self->m10 == 0) {
        FxRec* r = self->m0;
        switch (r->m38) {
        case -1:
            return 1;
        case 0:
        case 1:
            return 0;
        case 2: {
            float d = t - self->m4;
            if (d * r->m30 > lbl_805EA56C || d * r->m34 > lbl_805EA56C) return 1;
            return 0;
        }
        }
    }
    return 1;
}

float fn_8031B3E0(FxRec* self, float t) {
    switch (self->m38) {
    case 0:
    case 2:
        return lbl_805EA570;
    case 1: {
        float x = t * self->m30;
        float r = (int)x & 1 ? lbl_805EA574 : lbl_805EA570;
        return r;
    }
    }
    return lbl_805EA578;
}

void fn_8031B470(FxC* self, int id, int a, int b) {
    for (int i = 0; i < self->m70; i++) {
        FxRec* r = (FxRec*)(i * 0x40 + (int)self->m24);
        if (r->m24 == id) fn_8031AB8C(r, a, b);
    }
}

/* near-miss: retail materialises li/lis/lfs inside both item loops; ours hoists them */
FxD* fn_8031B4EC(FxD* self, int a) {
    fn_80328234(self, 0xE, a);
    self->m28 = 0;
    self->m18 = lbl_80665968;
    self->m24 = 0;
    for (int i = 0; i < 5; i++) {
        self->a2C[i].m0 = 0;
        self->a2C[i].m8 = 1;
        self->a2C[i].m4 = lbl_805EA59C;
    }
    for (int i = 0; i < 5; i++) {
        self->a68[i].m0 = 0;
        self->a68[i].m8 = 1;
        self->a68[i].m4 = lbl_805EA59C;
    }
    self->m14 = 0;
    fn_8040B61C(self, lbl_80620138);
    return self;
}

void fn_8031B5B0(FxD* self, int a) {
    self->m18 = lbl_80665968;
    fn_80328374(self, a);
}

int fn_8031B5E0(const char* name) {
    for (int i = 0; i <= 0x69; i++) {
        if (fn_8040B574(name, lbl_8061FF8C[i]) == 0) return i;
    }
    return -1;
}

void fn_8031B880(FxE* self) {
    self->m20 = 1;
    self->m28 = -1;
    self->m24 = lbl_805EA5A0;
    self->m11C = 0;
    self->m120 = 0;
    self->m124 = lbl_805EA5A0;
    for (int i = 0; i < 20; i++) {
        self->a2C[i].x = lbl_805EA5A0;
        self->a2C[i].y = lbl_805EA5A0;
        self->a2C[i].z = lbl_805EA5A0;
    }
}

void fn_8031B8E4(FxE* self) {
    if (self->m120) {
        delete self->m120;
        self->m120 = 0;
    }
}

void fn_8031B93C(FxE* self, int a) {
    fn_8031B8E4(self);
    if (a & 1) fn_80377408(self);
}

void fn_8031BE94() {}

void fn_8031BF58(FxD* self, int i) {
    int off = i * 12 + 0xA4;
    FxSlotD* s = (FxSlotD*)((char*)self + off);
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = lbl_805EA5D8;
}

void fn_8031BF80(FxD* self, int i, int a, float f, FxSrcD* b) {
    int off = i * 12 + 0xA4;
    FxSlotD* s = (FxSlotD*)((char*)self + off);
    s->m0 = a;
    s->m4 = b;
    s->m8 = f;
}

void fn_8031BFAC(FxD* self, int i) {
    int off = i * 12 + 0xA4;
    *(FxSlotD*)((char*)self + off) = self->aA4[1];
}

/* near-miss: slot address: add + displacement in retail, addi + lwzx here */
void fn_8031BFD8(FxD* self, int i) {
    FxSrcD* src = self->aA4[i].m4;
    for (int k = 0; k < 5; k++) {
        self->a68[k].m0 = 0;
        self->a68[k].m4 = lbl_805EA5DC;
        self->a68[k].m8 = 1;
    }
    if (src) {
        for (int j = 0; j < src->m0; j++) self->a68[j] = (&src->m4)[j];
    }
}

int fn_8031C074(FxItemD* self, float t) {
    if (self->m8 == 0) {
        switch (self->m0->m28) {
        case -1:
            return 1;
        case 0:
        case 1:
            return 0;
        case 2:
        case 3: {
            float d = t - self->m4;
            int f = d * self->m0->m24 > lbl_805EA5E0;
            return f;
        }
        }
    }
    return 1;
}

int fn_8031C1E4(FxD* self, int id) {
    int n = self->m28;
    for (int i = 0; i < n; i++) {
        FxRec2* r = (FxRec2*)((char*)self->m24 + i * 0x128);
        if (r->m20 == id) return (int)r;
    }
    return 0;
}

FxRec2* fn_8031C228(FxD* self, const char* name) {
    for (int i = 0; i < self->m28; i++) {
        if (fn_8040B3B4((char*)self->m24 + i * 0x128, name) == 0) return (FxRec2*)((char*)self->m24 + i * 0x128);
    }
    return 0;
}

int fn_8031C2A4(FxD* self, int id, int* found, float t) {
    *found = 0;
    for (int i = 0; i <= 4; i++) {
        FxRec2* r = self->a68[i].m0;
        if (r != 0 && r->m20 == id) {
            *found = 1;
            return fn_8031C074(&self->a68[i], t) ^ 1;
        }
    }
    return 0;
}

void fn_8031C454(FxD* self, int id) {
    for (int i = 0; i < 5; i++) {
        if (self->a2C[i].m8 == 0 && self->a2C[i].m0->m20 == id) self->a2C[i].m8 = 1;
    }
}

FxG* fn_8031C62C(FxG* self) {
    fn_80328234(self, 8, 0);
    self->m2C = 0;
    self->m18 = lbl_80665128;
    return self;
}

void fn_8031C678(FxG* self, int a) {
    self->m18 = lbl_80665128;
    fn_80328374(self, a);
}

int fn_8031C6A8() { return lbl_8062013C; }

void fn_8031C6B4(FxG* self) { self->m2C = 0; }

void fn_8031C6C0(FxG* self, int a, int b, int c) {
    if (self->m2C == 0 || c != 0) {
        self->m28 = b;
        self->m24 = lbl_8061E9F4;
        self->m2C = a;
        if (a == 1) fn_8031CE5C(fn_8031CE04());
    }
}

void fn_8031C714(FxG* self) {
    if (self->m24 + self->m28 < lbl_8061E9F4) {
        self->m2C = 0;
        fn_80314B4C(lbl_8061FEDC);
    }
}

/* near-miss: float temporaries: retail has one stack slot, ours three */
void fn_8031CB4C(void* unused, float* out) {
    FxCtx* c = lbl_8061FEDC;
    if (c->m204 != 0 && c->m208 == 0) {
        float a = lbl_805EA624;
        float b = lbl_805EA62C;
        float z = lbl_805EA628;
        out[7] = b;
        out[3] = z;
        out[6] = a + b;
        out[4] = -a;
        out[0] = -a;
        out[1] = z;
        out[2] = a + b;
        out[5] = b;
    } else {
        float z = lbl_805EA628;
        float b = lbl_805EA62C;
        out[4] = z;
        out[7] = b;
        out[0] = z;
        out[1] = z;
        out[2] = b;
        out[3] = z;
        out[5] = b;
        out[6] = b;
    }
}

void fn_8031CBF4() {}

/* near-miss: eight float stores; store order not found */
void fn_8031CBF8(void* unused, float* out) {
    out[4] = lbl_805EA630;
    out[7] = lbl_805EA634;
    out[0] = lbl_805EA630;
    out[1] = lbl_805EA630;
    out[2] = lbl_805EA634;
    out[3] = lbl_805EA630;
    out[5] = lbl_805EA634;
    out[6] = lbl_805EA634;
}

/* near-miss: same fmr chain as fn_8031CC2C */
void* fn_8031CC78(void* self, float t) {
    fn_8014D9EC(self, lbl_805EA654, lbl_805EA654, lbl_805EA654, t, lbl_805EA658);
    return self;
}

/* near-miss: switch tree: retail has a dead compare for case 1 and a [6,7] range test */
int fn_8031CCC8(FxG* self) {
    int kind = self->m2C;
    int now = lbl_8061E9F4;
    switch (kind) {
    case 0:
    case 1:
        return 0;
    case 2:
    case 3:
        return 1;
    case 6:
    case 7: {
        float ratio = (float)(now - self->m24) / (float)self->m28;
        if (ratio < lbl_805EA668) return 1;
        return 0;
    }
    }
    return 0;
}

FxH* fn_8031CD88(FxH* self) {
    fn_80328234(self, 9, 0);
    self->m24 = 0;
    self->m18 = lbl_806651B8;
    return self;
}

void fn_8031CDD4(FxH* self, int a) {
    self->m18 = lbl_806651B8;
    fn_80328374(self, a);
}

FxH* fn_8031CE04() { return lbl_80620140; }

void fn_8031CE10() {}

void fn_8031CE14(FxH* self) {
    if (self->m24 != 0) {
        fn_80314854(lbl_8061FEDC);
        self->m24 = 0;
    }
}

void fn_8031CE5C(FxH* self) { self->m24 = 1; }

void fn_8031CE68() {
    FxI** pp = &lbl_80620144;
    lbl_80699B94.m0 = (void*)fn_803ED5E0;
    lbl_80699B94.m4 = (void*)fn_803EDA0C;
    lbl_80699B94.m8 = 0x100;
    *pp = fn_8031CED8((FxI*)operator new(0x1B0, 0));
}

FxI* fn_8031CECC() { return lbl_80620144; }

void fn_8031D014(FxI* self) {
    self->m0 = 0;
    if (self->m10) {
        delete self->m10;
        self->m10 = 0;
    }
    if (self->m8) {
        fn_8038D9B4(self->m8, 3);
        self->m8 = 0;
    }
    if (self->mC) {
        fn_8038D9B4(self->mC, 3);
        self->mC = 0;
    }
    self->m4 = 0;
}

void fn_8031D0A4(FxI* self, int a) {
    fn_8031D014(self);
    fn_803E57F0(self->mCC, 2);
    if (a & 1) fn_80377408(self);
}

void fn_8031D0F0() {
    if (lbl_80620144) {
        fn_8031D0A4(lbl_80620144, 3);
        lbl_80620144 = 0;
    }
}

void fn_8031D134(FxI* self) {
    self->m34 = 1;
    self->m0 = 0;
}

void fn_8031D494(FxI* self, float a, float b, float c, float d) {
    self->m24 = a;
    self->m28 = b;
    self->m2C = c / self->m14;
    self->m30 = d / self->m18;
    self->m10->s2(self->m24, self->m28, lbl_805EA6A0);
    self->m10->s3(self->m2C, self->m30);
}

/* near-miss: int-to-float constant/lis scheduling */
void fn_8031D54C(FxI* self) {
    self->m28 = self->m24 = lbl_805EA6A4;
    self->m2C = (float)(lbl_8061FEDC->m28 ? lbl_8061FEDC->m2C : lbl_8061FEDC->m14) * lbl_805EA6B0;
    self->m30 = (float)(lbl_8061FEDC->m28 ? lbl_8061FEDC->m30 : lbl_8061FEDC->m18) * lbl_805EA6B4;
}

void fn_8031D610(FxI* self) { self->m1A8 = 1; }

void fn_8031D61C(FxI* self) {
    fn_8031259C(lbl_8061FEDC);
    if (self->m40) {
        self->m10->s5();
    } else {
        self->m10->s4(self->m48);
        self->m40 = 1;
    }
    fn_803125D0(lbl_8061FEDC);
}
