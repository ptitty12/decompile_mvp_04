/*
 * Game code, .text 0x801DB948-0x801DC918 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801DB948.h"

extern const char lbl_80660BF8[];
extern const float lbl_805D39D0;
extern const float lbl_805D39A4;
extern const float lbl_805D39A8;
extern float lbl_8061D560;

static inline Unk801DB948_Vec3 operator-(const Unk801DB948_Vec3& a, const Unk801DB948_Vec3& b)
{
    Unk801DB948_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
extern "C" float fn_804028E4(float x);
static inline float Len(Unk801DB948_Vec3 v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}
extern int lbl_8061F8F8;
static inline void SetSel(int v) { lbl_8061F8F8 = v; }

struct Unk801DB948_E {
    char pad0[8];
    int m8;
    int mC;
};

struct Unk801DB948_A {
    char pad0[0x68];
    int m68;
};

extern "C" {
void fn_801DAECC(Unk801DB948_A* self);
void* fn_8035AB00(void* self);
Unk801DD660* fn_801DD660(void* mem, int a, int b, Unk801DB948* owner);
void fn_80377408(void* p);
void fn_801DBA54(Unk801DB948* self);
void fn_801DD784(Unk801DD660* self);
void fn_801DDC60(Unk801DD660* self);
void fn_801DDC84(Unk801DD660* self);
void fn_801DDD0C(Unk801DD660* self);
void fn_801DDD18(Unk801DD660* self);
void fn_801DDDA0(Unk801DD660* self);
void fn_801DDDAC(Unk801DD660* self);
void fn_801DDDB8(Unk801DD660* self);
void fn_801DDDDC(Unk801DD660* self);
void fn_801DDDF8(Unk801DD660* self);
void fn_801DDE04(Unk801DD660* self);
void fn_801DDE10(Unk801DD660* self);
void fn_801DDE4C(Unk801DD660* self);
void fn_801DDE90(Unk801DD660* self);
void fn_801DDEE4(Unk801DD660* self);
void fn_801DDF04(Unk801DD660* self);
void fn_801DE028(Unk801DD660* self);
void fn_801DE1F8(Unk801DD660* self);
void fn_801DE21C(Unk801DD660* self);
void fn_801DE2AC(Unk801DD660* self);
void fn_801DE2F4(Unk801DD660* self);
void fn_801E9A74(Unk801DD660* self);
void fn_801E9E60(Unk801DD660* self);
void fn_801EA4D0(Unk801DD660* self);
void fn_801EA880(Unk801DD660* self);
void fn_801EA98C(Unk801DD660* self);
void fn_801F1ED8(Unk801DD660* self);
void fn_801F263C(Unk801DD660* self);
void fn_801F30B8(Unk801DD660* self);
void fn_801F3B54(Unk801DD660* self);
void fn_801DDDD0(Unk801DD660* self, int b);
int fn_801DBF3C(Unk801DB948* self);
Unk801DB948_Game* fn_801DCC0C(Unk801DB948* self);
int fn_801BBF24(int x);
void fn_801EA20C(Unk801DD660* self, int a, int b, int c);
int fn_801DBEC0(Unk801DB948* self);
void fn_801DE0E4(Unk801DD660* self);
void fn_801E16B0(Unk801DD660* self, int a, int b);
int fn_801DE1D8(Unk801DD660* self);
int fn_801DBF30(Unk801DB948* self);
int fn_801E9DE4(Unk801DD660* self);
int fn_801A497C(Unk801DB948_Game* g, int a, int b);
int fn_801E816C(Unk801DD660* self, int a);
void fn_801F3244(Unk801DD660* self, int a, int b);
void fn_801F33BC(Unk801DD660* self, int a, int b);
void fn_801F35EC(Unk801DD660* self, int a, int b);
void fn_801F3934(Unk801DD660* self, int a, int b);
Unk801DB948_Vec3 fn_801F2A44(Unk801DD660* self, Unk801DB948_Obj* o, int c, int d, int e);
Unk801DB948_Vec3 fn_801F2FE0(Unk801DD660* self);
Unk801DB948_Obj* fn_801C1638(Unk801DB948_Game* g, int a);
Unk801DB948_Vec3 fn_8014E388(int idx);
void fn_8023CAF0(Unk801DB948_Obj* o);
float fn_8020EC50(Unk801DD660* self, int idx);
float fn_80250338(void* o, float a, float b);
float fn_80189D88(Unk801DB948_Obj* o, Unk801DB948_Obj* p, Unk801DB948_Vec3* pos, Unk801DB948_Vec3* v, float f);
void fn_801DDADC(Unk801DD660* self, int a, int b, int c);
}

extern "C" void fn_801DB948(Unk801DB948_A* self)
{
    if (self->m68 == 2)
        fn_801DAECC(self);
}

extern "C" Unk801DB948* fn_801DB974(Unk801DB948* self, int a, int b)
{
    fn_8035AB00(self);
    self->m4 = 0;
    self->m0 = lbl_80660BF8;
    self->m4 = fn_801DD660(operator new(0x422C, 0), 1, b, self);
    fn_801DBA54(self);
    return self;
}

extern "C" void fn_801DB9E4(Unk801DB948* self, int chrg)
{
    self->m0 = lbl_80660BF8;
    delete self->m4;
    if (chrg & 1)
        operator delete(self);
}

extern "C" void fn_801DBA54(Unk801DB948* self)
{
    fn_801DD784(self->m4);
}

extern "C" void fn_801DBA78(Unk801DB948* self)
{
    fn_801DBA54(self);
}

extern "C" void fn_801DBA98(Unk801DB948* self)
{
}

extern "C" void fn_801DBA9C(Unk801DB948* self)
{
    fn_801DDC84(self->m4);
}

extern "C" void fn_801DBAC0(Unk801DB948* self)
{
    fn_801DDD0C(self->m4);
}

extern "C" void fn_801DBAE4(Unk801DB948* self)
{
    fn_801DDD18(self->m4);
}

extern "C" void fn_801DBB08(Unk801DB948* self)
{
    fn_801DDC60(self->m4);
}

extern "C" void fn_801DBB2C(Unk801DB948* self)
{
    fn_801DE1F8(self->m4);
}

extern "C" void fn_801DBB50(Unk801DB948* self)
{
    fn_801DDDA0(self->m4);
}

extern "C" void fn_801DBB74(Unk801DB948* self)
{
    fn_801DDDAC(self->m4);
}

extern "C" void fn_801DBB98(Unk801DB948* self)
{
    fn_801DDDB8(self->m4);
}

extern "C" void fn_801DBBBC(Unk801DB948* self, int b)
{
    if (fn_801DBF3C(self) == 0)
        fn_801DDDD0(self->m4, b);
}

extern "C" void fn_801DBC00(Unk801DB948* self)
{
    fn_801DDDDC(self->m4);
}

extern "C" void fn_801DBC24(Unk801DB948* self)
{
    fn_801DDDF8(self->m4);
}

extern "C" void fn_801DBC48(Unk801DB948* self)
{
    fn_801DDE04(self->m4);
}

extern "C" void fn_801DBC6C(Unk801DB948* self)
{
    fn_801DDE10(self->m4);
}

extern "C" void fn_801DBC90(Unk801DB948* self)
{
    fn_801DDE4C(self->m4);
}

extern "C" void fn_801DBCB4(Unk801DB948* self, int a, int b, int c)
{
    if (fn_801BBF24(fn_801DCC0C(self)->m700->m3BC) != 4)
        fn_801EA20C(self->m4, a, b, c);
}

extern "C" void fn_801DBD14(Unk801DB948* self)
{
    fn_801DDE90(self->m4);
}

extern "C" void fn_801DBD38(Unk801DB948* self)
{
    fn_801DDEE4(self->m4);
}

extern "C" void fn_801DBD5C(Unk801DB948* self)
{
    fn_801DDF04(self->m4);
}

extern "C" void fn_801DBD80(Unk801DB948* self)
{
    fn_801DE028(self->m4);
}

extern "C" void fn_801DBDA4(Unk801DB948* self, int a)
{
    fn_801DDADC(self->m4, a, 1, 0);
}

extern "C" void fn_801DBDD0(Unk801DB948* self)
{
    Unk801DB948_Obj* o = fn_801DCC0C(self)->m6CC;
    if (fn_801DBEC0(self) == 0 || o->m36C != 0)
        SetSel(-1);
    fn_801DE0E4(self->m4);
}

extern "C" void fn_801DBE30(Unk801DB948* self, int b, Unk801DB948_E* e)
{
    if (b == 0x77) {
        int w = e->m8;
        int v = e->mC ? 1 : 2;
        fn_801E16B0(self->m4, w, v);
    }
}

extern "C" void fn_801DBE78(Unk801DB948* self)
{
    fn_801E9E60(self->m4);
}

extern "C" void fn_801DBE9C(Unk801DB948* self)
{
    fn_801E9A74(self->m4);
}

static inline int Active(Unk801DB948* self)
{
    return self->m4->m9C->m30 != 0;
}
extern "C" int fn_801DBEC0(Unk801DB948* self)
{
    return Active(self);
}

extern "C" int fn_801DBEE0(Unk801DB948* self)
{
    int s = self->m4->m168;
    if (s == 3 || s == 8)
        return 1;
    int r = 0;
    if (s == 7)
        r = fn_801DE1D8(self->m4);
    return r;
}

extern "C" int fn_801DBF30(Unk801DB948* self)
{
    return self->m4->m168;
}

extern "C" int fn_801DBF3C(Unk801DB948* self)
{
    int s = self->m4->m168;
    int r = 0;
    if (s == 3 || s == 5 || s == 6)
        r = 1;
    return r;
}

extern "C" void fn_801DBF68(Unk801DB948* self)
{
    fn_801F3B54(self->m4);
}

extern "C" int fn_801DBF8C(Unk801DB948* self)
{
    return self->m4->m11C.mC != -1;
}

/* near-miss: retail keeps the 70.0 constant (k) in f31 across the sqrt call;
 * here it is reloaded from its slot (2 instructions shorter, otherwise equal) */
extern "C" float fn_801DBFA8(Unk801DB948* self, int idx)
{
    Unk801DB948_Obj* o = fn_801C1638(fn_801DCC0C(self), 0);
    Unk801DB948_Vec3* pos = &o->m60;
    Unk801DB948_Vec3 sp = fn_8014E388(idx);
    fn_8023CAF0(o);
    sp.y = lbl_8061D560 * lbl_805D39A4 + sp.y;
    float a = fn_8020EC50(self->m4, idx);
    const float k = lbl_805D39A8;
    float c = fn_80250338((char*)o + 0x4D8, Len(*pos - sp), k);
    float r = fn_80189D88(fn_801DCC0C(self)->m6CC, o, pos, &sp, c);
    return a + r;
}

extern "C" void fn_801DC0E8(Unk801DB948* self)
{
    fn_801DE21C(self->m4);
}

extern "C" int fn_801DC10C(Unk801DB948* self)
{
    return self->m4->m78C;
}

extern "C" void fn_801DC118(Unk801DB948* self)
{
    fn_801F1ED8(self->m4);
}

extern "C" void fn_801DC13C(Unk801DB948* self)
{
    fn_801DE2AC(self->m4);
}

extern "C" void fn_801DC160(Unk801DB948* self)
{
    fn_801DE2F4(self->m4);
}

extern "C" void fn_801DC184(Unk801DB948* self)
{
    fn_801EA4D0(self->m4);
}

extern "C" void fn_801DC1A8(Unk801DB948* self)
{
    fn_801EA880(self->m4);
}


extern "C" int fn_801DC570(Unk801DB948* self)
{
    int r = fn_801E9DE4(self->m4);
    if (r == -1)
        return 0;
    return fn_801A497C(fn_801DCC0C(self), 4, r);
}

extern "C" float fn_801DC5C4(Unk801DB948* self)
{
    return self->m4->m9C->mA8;
}

extern "C" int fn_801DC5D4(Unk801DB948* self)
{
    int r;
    if (self->m4->m798 != 0) {
        int t = fn_801E816C(self->m4, 0);
        r = fn_801A497C(fn_801DCC0C(self), 4, t);
    } else
        r = 0;
    return r;
}

extern "C" void fn_801DC634(Unk801DB948* self)
{
    fn_801EA98C(self->m4);
}

extern "C" void fn_801DC658(Unk801DB948* self)
{
    fn_801F30B8(self->m4);
}

extern "C" int fn_801DC67C(Unk801DB948* self)
{
    int r = 0;
    if (fn_801DCC0C(self)->m6CC->m38C != 1 || self->m4->mC0 == 3)
        r = 1;
    return r;
}

extern "C" int fn_801DC6D4(Unk801DB948* self)
{
    return self->m4->m9C->m1B8;
}

extern "C" void fn_801DC6E4(Unk801DB948* self, int a, int b)
{
    if (fn_801DBF30(self) == 7)
        fn_801F3244(self->m4, a, b);
}

extern "C" void fn_801DC730(Unk801DB948* self, int a, int b)
{
    if (fn_801DBF30(self) == 7)
        fn_801F33BC(self->m4, a, b);
}

extern "C" void fn_801DC77C(Unk801DB948* self, int a, int b)
{
    if (fn_801DBF30(self) == 7)
        fn_801F35EC(self->m4, a, b);
}

extern "C" void fn_801DC7C8(Unk801DB948* self, int a, int b)
{
    if (fn_801DBF30(self) == 7)
        fn_801F3934(self->m4, a, b);
}

extern "C" Unk801DB948_Vec3 fn_801DC814(Unk801DB948* self, Unk801DB948_Obj* o, int c, int d)
{
    if (Active(self) == 1)
        return fn_801F2A44(self->m4, o, c, d, 0);
    return o->m60;
}

extern "C" Unk801DB948_Vec3 fn_801DC890(Unk801DB948* other)
{
    return fn_801F2FE0(other->m4);
}

extern "C" void fn_801DC8C4(Unk801DB948* self)
{
    fn_801F263C(self->m4);
}

/* near-miss: retail compares in r9 and schedules li r0,0 before the lis (6 slots) */
extern "C" void fn_801DC8E8(Unk801DB948* self)
{
    Unk801DD660_Sub* s = &self->m4->m11C;
    if (s->mC != -1)
        return;
    s->m8 = 0;
    s->m14 = s->m10 = lbl_805D39D0;
}
