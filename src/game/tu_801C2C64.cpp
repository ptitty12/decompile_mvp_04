/*
 * Game code, .text 0x801C2C64-0x801C6D2C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801C2C64.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Z Z;

extern "C" {
float fn_801C34F4(Z* z);
Vec3 fn_801C5C70(void* u, const Vec3* i, const Vec3* n);
int fn_801C3F00(Z* z);
void fn_801CF1BC(Z* z);
void fn_801C34AC(Z* z, int s);
struct Unk801C2C64_Rec* fn_801A6DB8(P* ctx);
int fn_8017C94C(void* p);
void fn_80249B40(P* p, float f, int a, int b, int c);
int fn_801BBF0C(Unk801B7FB0_Ai* a);
void* fn_8024D218(P* p);
void fn_80303BC4(const char* fmt, ...);
void fn_801C4F98(Z* z);
P* fn_801A4B34(P* ctx);
int fn_801A2034(P* ctx, int k);
int fn_802D7DB4(int a, int b);
int fn_801D5974(void* p);
int fn_801C4128(Z* z);
}

struct Unk801C2C64_Rec {
    int m0;
    int m4;
};
struct Unk801C2C64_Sim {
    char pad0[0x3BC];
    Unk801B7FB0_Ai* m3BC;
};
extern int lbl_8061CBC8;
extern const char lbl_805D137C[];
extern const char lbl_805D1384[];
extern const char lbl_805D1390[];
extern float lbl_805D1398;
extern float lbl_805D139C;
extern float lbl_805D13A0;
extern float lbl_805D13A4;
inline Vec3 Scale(const Vec3* v, float s)
{
    Vec3 r;
    r.x = v->x * s;
    r.y = v->y * s;
    r.z = v->z * s;
    return r;
}

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

float fn_80410CE8(float y, float x);
float fn_804028E4(float x);
Vec3 fn_80189618(P* p, float f);
extern float lbl_8068C4C4;
extern Vec3 lbl_8068C3DC;
extern Vec3 lbl_8068C3E8;
extern "C" {
void fn_801C2284(Z* z);
void fn_801D7AC4(void* p, P* q);
void fn_801D6108(void* p);
Vec3* fn_801C34D0(Vec3* out, Z* z);
Vec3* fn_801C342C(Vec3* out, Z* z);
}

struct Unk801C2C64_G {
    float m0;
    char pad4[8];
    float mC;
    char pad10[0x60 - 0x10];
    float m60;
    char pad64[0x2A0 - 0x64];
};
extern Unk801C2C64_G lbl_8068C420;

extern "C" void fn_801C3330(Z* z)
{
    fn_801C2284(z);
    fn_801D7AC4(z->m8, z->m204);
    fn_801D6108(z->m20C);
}

extern "C" float fn_801C3370(void) { return lbl_8068C4C4; }

extern "C" float fn_801C337C(void* self, int i)
{
    if (i <= 3) {
        if (i < 0)
            i = 0;
    } else
        i = 3;
    char* b = (char*)&lbl_8068C420;
    b += 0x224;
    return *(float*)(b + i * 0x2C);
}

extern "C" void fn_801C33B0(Z* z, Vec3* a, Vec3* b)
{
    Vec3 v;
    fn_801C34D0(&v, z);
    *a = v;
    fn_801C342C(&v, z);
    *b = v;
}

extern "C" Vec3* fn_801C342C(Vec3* out, Z* z)
{
    P* p = fn_801A4B34(z->m204);
    *out = p->v24() == 1 ? lbl_8068C3DC : lbl_8068C3E8;
    return out;
}

extern "C" void fn_801C34AC(Z* z, int s)
{
    if (z->m204->m6F4 == 2 && s == 9)
        s = 0;
    z->m208 = s;
}

extern "C" Vec3* fn_801C34D0(Vec3* out, Z* z)
{
    *out = z->m29C[1].a;
    return out;
}

extern "C" int fn_801C38F0(Z* z, float f)
{
    if (fn_801A6DB8(z->m204)->m4 != 0 && fn_801A4B34(z->m204)->m5CC != 0 && fn_8017C94C(z->m204->m700) != 1) {
        z->m294 = !(f <= 0.0f) ? (float)z->m204->m4C * 0.016666668f + f : 0.0f;
        if (fn_801C3F00(z))
            fn_801CF1BC(z);
        fn_801C34AC(z, 7);
        return 1;
    }
    return 0;
}

extern "C" int fn_801C3E28(Z* z)
{
    if (z->m144 >= 1.0f)
        return 0;
    if (z->m144 <= -1.0f)
        return 2;
    return 1;
}

extern "C" int fn_801C3E68(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p) {
        int h = p->m618->m838;
        if (fn_801C3F00(z) != 0 || h == (int)0x94C34DBD || h == 0x18A18DEB) {
            fn_80249B40(p, 0.2f, 0, 0, 0);
            return 1;
        }
    }
    return 0;
}

extern "C" int fn_801C3F00(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p) {
        int h = p->m618->m838;
        if (h == 0x294A8535 || h == (int)0xCF78E0F8)
            return 1;
    }
    return 0;
}

extern "C" int fn_801C3F60(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p) {
        int h = p->m618->m838;
        if (h == 0x18A18DEB || h == 0x0AB6992B || h == 0x128EDBC5)
            return 1;
    }
    return 0;
}

extern "C" int fn_801C4128(Z* z) { return fn_801A2034(z->m204, 3) == -1; }

extern "C" int fn_801C415C(Z* z)
{
    if (fn_801C4128(z) == 0)
        return fn_802D7DB4(fn_801A2034(z->m204, 3), 0xBA) != 0;
    return fn_801D5974(z->m20C);
}

extern "C" int fn_801C4474(Z* z)
{
    int r = 0;
    Unk801C2C64_Sim* q = (Unk801C2C64_Sim*)z->m204->m700;
    if (q) {
        if (fn_801BBF0C(q->m3BC) != 0 || fn_8017C94C(q) != 0)
            r = 1;
    }
    if (r)
        return r;
    P* t = z->m204->m65C[1];
    if (t) {
        char* x = (char*)fn_8024D218(t);
        if (x) {
            int k = *(int*)(x + 0x78);
            if (k == 3 || k == 7 || k == 4 || k == 5)
                return 1;
        }
    }
    return 0;
}

/* near-miss: same code, but retail puts the fn_801C34D0 result at 0x20 and the difference at 0x10. */
extern "C" int fn_801C4C3C(Z* z)
{
    P* p = fn_801A4B34(z->m204);
    if (p) {
        const float k = 180.0f;
        const Vec3& pos = p->m60;
        Vec3 q;
        fn_801C34D0(&q, z);
        Vec3 d = pos - q;
        if (fn_804028E4(d.x * d.x + d.z * d.z) < k)
            return 1;
    }
    return 0;
}

extern "C" void fn_801C4D04(void)
{
    if (lbl_8061CBC8) {
        fn_80303BC4(lbl_805D137C, lbl_805D1398, lbl_805D139C, lbl_8068C420.m0);
        fn_80303BC4(lbl_805D1384, lbl_805D1398, lbl_805D13A0, lbl_8068C420.mC);
        fn_80303BC4(lbl_805D1390, lbl_805D1398, lbl_805D13A4, lbl_8068C420.m60);
    }
}

extern "C" void fn_801C53D8(void) {}

extern "C" float fn_801C36AC(Z* z)
{
    const float k = 2.0f;
    float r = fn_801C34F4(z);
    return r + k;
}

extern "C" void fn_801C53DC(Z* z) { fn_801C4F98(z); }

extern "C" Vec3 fn_801C5C70(void* u, const Vec3* i, const Vec3* n)
{
    return *i - Scale(n, (n->z * i->z + (n->x * i->x + n->y * i->y)) * 2.0f);
}

extern "C" Vec3 fn_801C5BD4(Z* z)
{
    P* c = z->m204->m6CC;
    float t = z->m180 - (float)z->m204->m4C * 0.016666668f;
    if (!(t >= 0.0f))
        t = 0.0f;
    return fn_80189618(c, t);
}

extern "C" float fn_801C5D20(void* a, const Vec3* b, const Vec3* c)
{
    Vec3 t = fn_801C5C70(a, b, c);
    float r = fn_80410CE8(t.x, t.z);
    return r * 57.295773f;
}
