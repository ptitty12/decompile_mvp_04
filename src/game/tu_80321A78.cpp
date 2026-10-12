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
extern float lbl_806E10E4[];

/* Layouts seen through fn_80321AC4 (the first argument of fn_801A04A8 is the state owner, Unk8019F8C0_Owner). */
struct Unk8019F8C0_Owner;
struct Unk80321AC4_R { char pad0[0x3D90]; int m3D90; };
struct Unk80321AC4_S { char pad0[0x40]; Unk80321AC4_R* m40; int m44; };
struct Unk80321AC4_X { char pad0[0x14]; int m14; };
struct Unk80321AC4_Y { char pad0[0x20]; int m20; };
struct Unk80321AC4_V { float x; float y; float z; };
struct Unk80321AC4_P { char pad0[0x60]; Unk80321AC4_V m60; };
struct Unk80321AC4_Ctx {
    char pad0[0x564];
    Unk80321AC4_X* m564;
    char pad568[0x6CC - 0x568];
    Unk80321AC4_P* m6CC;
    char pad6D0[0x6F4 - 0x6D0];
    int m6F4;
    char pad6F8[0x744 - 0x6F8];
    Unk80321AC4_Y* m744;
    char pad748[0x780 - 0x748];
    int m780;
    int m784;
};
Unk80321AC4_S* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
extern int lbl_806201C8;
struct Unk80321BD4_D { int m0; int m4; };
class Unk80321BD4_V : public Unk80321BD4_D {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual int s10();
};
struct Unk80321BD4_O { char pad0[0x3C]; Unk80321BD4_V* m3C; };
extern int lbl_806201BC;
extern int lbl_806201C0;

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

extern "C" void fn_80321AC4(int unused, Unk80321AC4_Ctx* ctx) {
    lbl_806201C8 = 0;
    if (ctx->m6F4 != 1) {
        Unk80321AC4_S* s = fn_801A04A8((Unk8019F8C0_Owner*)ctx, 1);
        if (ctx->m564->m14 != 4 && ctx->m744->m20 == 0 && s->m44 == 0) {
            int busy = 0;
            if (ctx->m780 != 0 || ctx->m784 != 0) busy = 1;
            if (busy == 0 && s->m40->m3D90 == 0) {
                Unk80321AC4_P* p = ctx->m6CC;
                if (p != 0) {
                    Unk80321AC4_V v = p->m60;
                    if (!(v.x >= 600.0f) && !(v.z >= 600.0f)) lbl_806201C8 = 1;
                }
            }
        }
    }
}

extern "C" void fn_80321BD4(int arg0, Unk80321BD4_O* o, int kind, int f1, int f2, int f3) {
    if (o != 0) {
        Unk80321BD4_V* v = o->m3C;
        if (v != 0) {
            int x = lbl_806201C0;
            switch (kind) {
            case 0:
                fn_80321A78(arg0, 0, 0, 1, 1, 1, 0, 0);
                break;
            case 1:
                if (f1 != 0) {
                    int r = v->s10();
                    lbl_806201BC = 0;
                    fn_80321A78(arg0, 0, 0, r, r, r ^ 1, 0, 1);
                } else if (f2 != 0) {
                    lbl_806201BC = kind;
                    fn_80321A78(arg0, 0, 1, 0, 0, 1, 0, 1);
                } else if (f3 != 0) {
                    fn_80321A78(arg0, 0, x ^ 1, x, 0, 1, 1, 1);
                } else {
                    fn_80321A78(arg0, 1, x ^ 1, x, 0, 1, 1, x ^ 1);
                }
                break;
            case 5:
                fn_80321A78(arg0, 1, 1, 0, 0, 1, 0, 1);
                break;
            case 2:
            case 3:
            case 4:
                fn_80321A78(arg0, 0, 0, 1, 1, 0, 0, 0);
                break;
            }
        }
    }
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

int fn_8032234C(FxU* self) {
    int v = self->m4;
    if (v == -1) {
        int base = fn_80322424(self);
        int r;
        if (fn_80322434(self) - fn_8032242C(self) + 1 > 0) {
            int rnd = fn_8040ABA0();
            int rem = rnd % (fn_80322434(self) - fn_8032242C(self) + 1);
            int b1 = base + 1;
            r = b1 + rem;
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

/* The recursive call goes through an inline wrapper: a direct `return f(...)` is turned into a jump by g++'s
   tail-recursion pass, retail keeps the call and the frame. */
inline float Rec80323848(FxV* v) { return fn_80323848(v); }
float fn_80323848(FxV* self) {
    if (self->m44 != 0 || self->m48 == 0) return self->m4C;
    return Rec80323848(self->m48);
}

inline float Rec8032388C(FxV* v) { return fn_8032388C(v); }
float fn_8032388C(FxV* self) {
    if (self->m44 != 0 || self->m48 == 0) return self->m50;
    return Rec8032388C(self->m48);
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
