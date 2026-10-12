/*
 * Game code, .text 0x80321A78-0x80324A48 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80317B88.h"

extern int lbl_8061C900;
extern int lbl_8061F968;
extern int lbl_8061C908;
extern int lbl_8061C904;
extern int lbl_80620284;
extern int lbl_8062156C;
extern int lbl_80620288;
extern int lbl_8062028C;
extern int lbl_8062014C;
extern int lbl_8061FF68;
extern int lbl_8061FE14;
extern int lbl_8061FE18;
extern const float lbl_805EA8F8;
extern const float lbl_805EA8FC;
extern const char lbl_805EA87C[];
extern const char lbl_805EA8B0[];
extern const char lbl_805EA8CC[];
extern const char lbl_805EA8D8[];
extern const char lbl_805EA8EC[];
extern const char lbl_805E9B64[];
extern const char lbl_805E7E08[];
extern const char lbl_805E8A24[];
extern const char lbl_805E8A38[];
extern const void* const lbl_80665248[];
extern const void* const lbl_80665558[];
extern const float lbl_806E10E4[];

extern "C" {
void fn_8033E958(const char* fmt, ...);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_8035F86C(void* p);
void fn_80377408(void* p);
void fn_80328374(void* p, int a);
void fn_803E1DB0(void* p, float a, float b);
void fn_803E0F9C(void* p);
void fn_803E1E88(void* p);
void fn_80313D9C(void* p, int a);
void fn_80313E00(void* p, int a);
int fn_80314790(void* p);
void fn_803145D8(void* a, int b, int c, float d, float e, int f);
int fn_8040ABA0();
void fn_8032222C(int a, int x, char* buf1, int d, char* buf2, int f);
FxW* fn_803224E8(FxW* self);
void fn_80322530(int a, int b);
void fn_80323B3C(int a, int b);
// PROTOS-BEGIN
void fn_80321A78(int unused, int a, int b, int c, int d, int e, int f, int g);
void fn_803220F4(FxU* a, char* b, int c, char* d, int e);
void fn_80322164(FxU* a, char* b, int c, char* d, int e);
void fn_803221D4(int unused, char* a, int c, char* d);
void fn_8032222C(int a, int x, char* buf1, int d, char* buf2, int f);
int fn_80322290(FxU* self);
int fn_8032234C(FxU* self);
int fn_8032241C(FxU* self);
int fn_80322424(FxU* self);
int fn_8032242C(FxU* self);
int fn_80322434(FxU* self);
void fn_8032243C();
void fn_80322440();
float fn_80322444();
void fn_80322450();
void fn_80322498();
void fn_803224C8();
FxW* fn_803224E8(FxW* self);
int fn_80323830();
int fn_8032383C();
float fn_80323848(FxV* self);
float fn_8032388C(FxV* self);
void fn_803238D0(FxX* self, float a, float b);
void fn_80323904(FxX* self);
void fn_80323928(FxX* self);
int fn_8032394C();
void fn_80323954();
int fn_80323958();
int fn_80323964();
void fn_80323970();
int fn_80323974();
int fn_80323980();
int fn_8032398C();
int fn_80323998();
const char* fn_803239A4();
int fn_803239B0();
void fn_803239BC();
void fn_803239C0();
void fn_803239C4(void* self);
void fn_803239E8(void* self);
int fn_80323A0C(void* self);
void fn_80323A2C(void* a, int b, int c, float d, float e);
void fn_80323A60(void* self, int a);
const char* fn_80323A90();
int fn_80323A9C();
const char* fn_80323AA8();
int fn_80323AB4();
float fn_80323AC0(void* unused, int* idx);
void fn_80323AE0();
void fn_80323AE4();
void fn_80323B10();
void fn_803249A8();
int fn_803249D4(FxY* a, FxY* b);
int fn_80324A24(FxY* a);
// PROTOS-END
}

// FUNCS-BEGIN

void fn_80321A78(int unused, int a, int b, int c, int d, int e, int f, int g) {
    lbl_8061C900 = a;
    lbl_8061F968 = b;
    lbl_8061C908 = c;
    lbl_8061C904 = d;
    lbl_80620284 = e;
    lbl_8062156C = f;
    lbl_80620288 = g;
}

// fn_803220E0
FxU::FxU() : m0(-1), m4(-1) {
}

void fn_803220F4(FxU* a, char* b, int c, char* d, int e) {
    fn_8032222C((int)a, fn_8032234C(a), b, c, d, e);
    fn_8033E958(lbl_805EA87C, b, d);
}

void fn_80322164(FxU* a, char* b, int c, char* d, int e) {
    fn_8032222C((int)a, fn_80322290(a), b, c, d, e);
    fn_8033E958(lbl_805EA87C, b, d);
}

void fn_803221D4(int unused, char* a, int c, char* d) {
    fn_804089B4(a, lbl_805EA8B0);
    fn_804089B4(d, lbl_805EA8CC, lbl_805E9B64);
}

void fn_8032222C(int a, int x, char* buf1, int d, char* buf2, int f) {
    fn_804089B4(buf1, lbl_805EA8D8, x);
    fn_804089B4(buf2, lbl_805EA8EC, x, lbl_805E9B64);
}

int fn_80322290(FxU* self) {
    int v = self->m0;
    if (v == -1) {
        int r;
        if (fn_80322424(self) - fn_8032241C(self) + 1 > 0) {
            int rnd = fn_8040ABA0();
            r = rnd % (fn_80322424(self) - fn_8032241C(self) + 1);
        } else {
            r = 0;
        }
        self->m0 = r;
    } else {
        int n = v + 1;
        if (n > fn_80322424(self)) n = fn_8032241C(self);
        self->m0 = n;
    }
    return self->m0;
}

/* near-miss: retail keeps (base + 1) separate; g++ reassociates it */
int fn_8032234C(FxU* self) {
    int v = self->m4;
    if (v == -1) {
        int base = fn_80322424(self);
        int r;
        if (fn_80322434(self) - fn_8032242C(self) + 1 > 0) {
            int rnd = fn_8040ABA0();
            r = base + 1 + rnd % (fn_80322434(self) - fn_8032242C(self) + 1);
        } else {
            r = base + 1;
        }
        self->m4 = r;
    } else {
        int n = v + 1;
        if (n > fn_80322434(self)) n = fn_8032242C(self);
        self->m4 = n;
    }
    return self->m4;
}

int fn_8032241C(FxU* self) { return 0; }

int fn_80322424(FxU* self) { return 7; }

int fn_8032242C(FxU* self) { return 8; }

int fn_80322434(FxU* self) { return 0x30; }

void fn_8032243C() {}

void fn_80322440() {}

float fn_80322444() { return lbl_805EA8F8; }

void fn_80322450() {
    if (lbl_8062028C == 0) lbl_8062028C = (int)fn_803224E8((FxW*)operator new(0x10, 0));
}

void fn_80322498() {
    if (lbl_8062028C) fn_80377408((void*)lbl_8062028C);
}

void fn_803224C8() { fn_80322498(); }

FxW* fn_803224E8(FxW* self) {
    fn_8035F86C(self);
    self->m4 = lbl_80665248;
    self->m8 = lbl_805EA8FC;
    return self;
}

int fn_80323830() { return lbl_8062014C; }

int fn_8032383C() { return 0xE33E6A08; }

/* near-miss: retail has a frame and a call (17 insns); this leaf version is shorter and only approximates the control flow */
float fn_80323848(FxV* self) {
    if (self->m44 == 0 && self->m48 != 0) return fn_80323848(self->m48);
    return self->m4C;
}

/* near-miss: same as the neighbouring function */
float fn_8032388C(FxV* self) {
    if (self->m44 == 0 && self->m48 != 0) return fn_8032388C(self->m48);
    return self->m50;
}

void fn_803238D0(FxX* self, float a, float b) { fn_803E1DB0(self->m8, a, b); }

void fn_80323904(FxX* self) { fn_803E0F9C(self->m8); }

void fn_80323928(FxX* self) { fn_803E1E88(self->m8); }

int fn_8032394C() { return 0x1A; }

void fn_80323954() {}

int fn_80323958() { return lbl_8061FF68; }

int fn_80323964() { return 0xCED26CE8; }

void fn_80323970() {}

int fn_80323974() { return lbl_8061FE14; }

int fn_80323980() { return 0xABA1DAEF; }

int fn_8032398C() { return lbl_8061FE18; }

int fn_80323998() { return 0xC22CAFD4; }

const char* fn_803239A4() { return lbl_805E7E08; }

int fn_803239B0() { return 0x10B3208E; }

void fn_803239BC() {}

void fn_803239C0() {}

void fn_803239C4(void* self) { fn_80313D9C(self, 3); }

void fn_803239E8(void* self) { fn_80313E00(self, 3); }

int fn_80323A0C(void* self) { return fn_80314790(self); }

void fn_80323A2C(void* a, int b, int c, float d, float e) { fn_803145D8(a, b, c, d, e, 0x16); }

void fn_80323A60(void* self, int a) {
    ((FxHdr*)self)->m18 = lbl_80665558;
    fn_80328374(self, a);
}

const char* fn_80323A90() { return lbl_805E8A24; }

int fn_80323A9C() { return 0xD99143B6; }

const char* fn_80323AA8() { return lbl_805E8A38; }

int fn_80323AB4() { return 0x77F3B9AB; }

/* near-miss: retail loads before the index increment */
float fn_80323AC0(void* unused, int* idx) {
    return lbl_806E10E4[(*idx)++ & 0x3FF];
}

void fn_80323AE0() {}

void fn_80323AE4() { fn_80322530(1, 0xFFFF); }

void fn_80323B10() { fn_80322530(0, 0xFFFF); }

void fn_803249A8() { fn_80323B3C(1, 0xFFFF); }

int fn_803249D4(FxY* a, FxY* b) {
    int r = 0;
    if (a->m0 == b->m0 && a->m4 == b->m4 && a->m8 == b->m8) r = a->mC == b->mC;
    return r;
}

int fn_80324A24(FxY* a) {
    int r = 0;
    if (a->m0 == 0xAD) r = a->m8 == 0;
    return r;
}
