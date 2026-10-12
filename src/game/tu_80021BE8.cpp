/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80021BE8-0x800239F4 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"

extern const float lbl_805A5FFC;
extern int lbl_805B19F0[];

void Unk80021A60::fn_vslot10()
{
    for (int i = 0; i < 10; i++) {
        e[i].m4 = 0;
        e[i].m8 = 0;
        e[i].m0 = -1;
    }
}

extern "C" void fn_80021C1C(void* x, Unk8001F2C4_World* ctx)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, fn_801A4B34(ctx)->m60);
    fn_800412AC(fn_8004072C(), 0xC, sx, sy, 0x64, 0);
}

extern "C" void fn_80021C9C(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Vec3 pos)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, pos);
    fn_800412AC(fn_8004072C(), 1, sx, sy, 0x1F4, 0);
}

extern "C" void fn_80021D04(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Vec3 pos)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, pos);
    fn_800412AC(fn_8004072C(), 2, sx, sy, 0, 0);
}

extern "C" void fn_80021D6C(void* x, Unk8001F2C4_World* ctx, int n)
{
    int sx, sy;
    int v = n;
    Unk801A4B34_Pos* p = fn_801A4B34(ctx);
    if (v > 0x78)
        v = 0x78;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    if (fn_801C3F00(ctx->m700->m3A4)) {
        fn_800412AC(fn_8004072C(), 3, sx, sy, v, 0);
        return;
    }
    fn_800412AC(fn_8004072C(), 0, sx, sy, v, 0);
}

extern "C" void fn_80021E30(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, int n)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, fn_801A4B34(ctx)->m60);
    fn_800412AC(fn_8004072C(), 0xA, sx, sy, n, 0);
}

extern "C" void fn_80021EB4(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, int a, int b, int n)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, ctx->m6CC->m60);
    if (a == 1 && b == 2) {
        fn_800412AC(fn_8004072C(), 7, sx, sy, n, 0);
        return;
    }
    fn_800412AC(fn_8004072C(), 6, sx, sy, n, 0);
}

/* near-miss: 70/70 insns, 2 slots differ: retail loads `li r4,1` before `mr r3,r31` for the
 * fn_801A6D84(ctx, 1) call (plain call, method call and an int temp all give mr first). */
extern "C" void fn_80021F68(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    int flag = 0;
    int id = p->m458;
    if (ctx->m780 != 0 || ctx->m784 != 0)
        flag = 1;
    int one = 1;
    if (flag != 0 || (ctx->fn_801A6D84(one), fn_8016ADC4() != 0)) {
        if (id == 16) {
            fn_800412AC(fn_8004072C(), 7, 0xA, sy, 0x5F, 0);
        } else if (id == 15) {
            fn_800412AC(fn_8004072C(), 6, 0xA, sy, 0x55, 0);
        }
    } else {
        if (id == 1) {
            fn_800412AC(fn_8004072C(), 7, 0xA, sy, 0x5F, 0);
        } else if (id == 0) {
            fn_800412AC(fn_8004072C(), 6, 0xA, sy, 0x55, 0);
        }
    }
}

extern "C" void fn_80022080(void* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    fn_800412AC(fn_8004072C(), 0xB, sx, sy, 0, 0);
}

extern "C" void fn_800220EC(void* x, Unk8001F2C4_World* ctx)
{
    fn_800412AC(fn_8004072C(), 0x33, 0x64, 1, 0, 0);
}

extern "C" void fn_80022124(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p, int a, int n)
{
    int sx, sy;
    fn_800222B4(ctx, &sx, &sy, p->m60);
    if (p != ctx->m6CC)
        sx = 10;
    if (a == 1) {
        fn_800412AC(fn_8004072C(), 5, sx, sy, n, 0);
        return;
    }
    fn_800412AC(fn_8004072C(), 4, sx, sy, n, 0);
}

extern "C" void fn_800221E4(Unk8001E444_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* p, int n)
{
    int sx, sy;
    Unk801A4B34_Vec3 a = p->m60;
    fn_800222B4(ctx, &sx, &sy, a);
    fn_800412AC(fn_8004072C(), 0x40, sx, sy, n, 0);
}

extern "C" void fn_80022270(Unk8001E444_Obj* x, int a, int n)
{
    fn_800412AC(fn_8004072C(), 0x40, 0x12, 0, n, 0);
}

extern "C" int fn_80022708(int unused, int idx)
{
    int r = -1;
    if (idx != -1 && idx <= 3)
        r = lbl_805B19F0[idx];
    return r;
}

extern "C" int fn_80022730(int unused, int b, int c)
{
    int r = -1;
    if (b == 0)
        r = 0;
    else if (b == 1 || b == 2) {
        r = 2;
        if (c != 0)
            r = 1;
    } else if (b == 3) {
        r = 4;
        if (c != 0)
            r = 3;
    }
    return r;
}

extern const float lbl_805A5FD8;
extern const float lbl_805A5FDC;
extern const float lbl_805A5FE0;
extern const float lbl_805A5FE4;
extern const float lbl_805A5FE8;
extern const float lbl_805A5FEC;
extern const float lbl_805A5FF0;
extern "C" float fn_80410CE8(float y, float x);

/* Field reads through inline accessors: an inline's result is computed while the compare's
 * second operand is expanded, so the field load comes before the spilled float operand, as
 * in retail (fcmpu c,field). A plain `c > m->m4C` loads c first. */
inline float Unk80022780_M4C(const Unk8002118C* m) { return m->m4C; }
inline float Unk80022780_M40(const Unk8002118C* m) { return m->m40; }
inline float Unk80022780_Abs(float v) { return (float)__builtin_fabs(v); }

extern "C" int fn_80022780(Unk80021A60_Data* x, Unk801A4B34_Vec3* pos, int mode, float a, float b, float c, float d, int side, int cnt)
{
    int r = -1;
    float len = fn_804028E4(pos->x * pos->x + pos->z * pos->z);
    if (!(a >= lbl_805A5FD8) && !(a <= lbl_805A5FDC) && !(b <= lbl_805A5FE0) && !(b >= lbl_805A5FE4)) {
        r = 0x10;
    } else if (mode == 1) {
        r = 7;
        if (cnt == 0)
            r = 8;
        if (cnt > 0) {
            float ang = fn_80410CE8(pos->x, pos->z) * lbl_805A5FE8;
            float ad = Unk80022780_Abs(ang - a);
            if (!(ad < x->m8C->m4)) {
                if ((!(ang <= a) && side == 1) || (!(ang >= a) && side == 0))
                    r = 9;
                else
                    r = 10;
            }
        }
    } else if (mode == 2) {
        Unk8002118C* m = x->m8C;
        r = 0xB;
        if (!(d < m->m6C)) {
            r = 0xD;
        } else if (cnt == 1) {
            if (!(d <= lbl_805A5FEC)) {
                float q = len / d;
                if (!(q < m->m64) && !(q > m->m68))
                    r = 0xC;
            }
        }
    } else if (mode == 0) {
        r = 0;
        if (!(b >= lbl_805A5FF0) && !(len > x->m8C->m38) && !(d < x->m8C->m3C)) {
            r = 1;
        } else {
            Unk8002118C* m = x->m8C;
            if (!(len > m->m50) && !(c > Unk80022780_M4C(m)))
                r = 3;
            else if (!(c > Unk80022780_M40(m)))
                r = 6;
            else if (!(c > m->m44) && !(len > m->m48))
                r = 2;
        }
    } else if (mode == 4) {
        r = 0xF;
    } else if (mode == 3) {
        r = 0xE;
    }
    return r;
}

extern Unk801A4B34_Vec3 lbl_80686DA8;

static inline Unk801A4B34_Vec3 Unk80022BE0_Sub(const Unk801A4B34_Vec3& a, const Unk801A4B34_Vec3& b)
{
    Unk801A4B34_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

static inline float Unk80022BE0_Len(const Unk801A4B34_Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.z * v.z);
}

extern const float lbl_805A5FF4;

inline float Unk80022A28_M5C(Unk8002118C* m) { return m->m5C; }
extern "C" int fn_80022A28(Unk80021A60_Data* x, Unk801A4B34_Vec3* pos, int mode, float a, float b)
{
    int r = -1;
    float dl;
    Unk801A4B34_Vec3 d = Unk80022BE0_Sub(lbl_80686DA8, *pos);
    dl = Unk80022BE0_Len(d);
    float pl = Unk80022BE0_Len(*pos);
    float lim = x->m8C->m1C + x->m8C->m7C;
    if (mode != 0) {
        r = 4;
        goto end;
    }
    if (a <= Unk80022A28_M5C(x->m8C))
        goto l80;
    if (a <= x->m8C->m78)
        goto l40;
    if (dl <= lim)
        goto l38;
    if (pl > lim)
        goto l40;
l38:
    r = 3;
    goto end;
l40:
    r = 1;
    if (b <= lbl_805A5FF4)
        goto end;
    if (pl / b >= x->m8C->m60)
        goto end;
    r = 2;
    goto end;
l80:
    if (a <= x->m8C->m28)
        goto lac;
    if (pl <= x->m8C->m34)
        goto lac;
    r = 1;
    goto end;
lac:
    if (pl >= x->m8C->m34)
        goto end;
    r = 0;
end:
    return r;
}

inline float Unk80022BE0_M20(const Unk8002118C* m) { return m->m20; }
extern "C" int fn_80022BE0(Unk80021A60_Data* x, Unk801A4B34_Vec3* pos, int mode)
{
    float len1;
    Unk801A4B34_Vec3 d = Unk80022BE0_Sub(lbl_80686DA8, *pos);
    len1 = Unk80022BE0_Len(d);
    float len2 = Unk80022BE0_Len(*pos);
    if (len1 <= x->m8C->m1C || !(Unk80022BE0_Len(*pos) > x->m8C->m1C))
        return 0;
    if (!(len1 > Unk80022BE0_M20(x->m8C)))
        return 1;
    float thr = 0.0f;
    switch (mode) {
    case 0:
        thr = x->m98 + x->m8C->m24;
        break;
    case 2:
        thr = x->m90 + x->m8C->m24;
        break;
    case 1:
        thr = x->m94 + x->m8C->m24;
        break;
    case 3:
        thr = x->m94 + x->m8C->m24;
        break;
    }
    int r = 3;
    if (!(len2 > thr))
        r = 2;
    return r;
}

extern "C" void fn_80022D64(Unk80021A60_Data* x, Unk801A4B34_Vec3 a, Unk801A4B34_Vec3 b, Unk801A4B34_Vec3 c)
{
    x->m90 = fn_804028E4(a.x * a.x + a.z * a.z) * lbl_805A5FFC;
    x->m94 = fn_804028E4(b.x * b.x + b.z * b.z) * lbl_805A5FFC;
    x->m98 = fn_804028E4(c.x * c.x + c.z * c.z) * lbl_805A5FFC;
}

extern "C" float fn_80410CE8(float y, float x);
extern const float lbl_805A6000;
extern const float lbl_805A6004;
extern const float lbl_805A6008;

/* near-miss (99 of 100 insns): everything matches except that retail reloads `b` (lfs f13,8(r1)) after the
 * shared-tail label; here gcse keeps the register from the first compare. Inline-helper tails spill the
 * float parameters (-ffloat-store), so they do not reproduce it either. */
extern "C" int fn_80022DF8(Unk80021A60_Data* x, Unk801A4B34_Vec3* pos, int mode, float b)
{
    int r;
    float ang, dl;
    ang = fn_80410CE8(pos->x, pos->z) * lbl_805A6000;
    Unk801A4B34_Vec3 d = Unk80022BE0_Sub(lbl_80686DA8, *pos);
    dl = Unk80022BE0_Len(d);
    if (dl > x->m8C->m1C)
        goto f04;
    if (mode != 1)
        goto f04;
    if (b > x->mA4)
        goto ee4;
    if (b >= lbl_805A6004)
        goto f24;
    if (b <= x->mA4)
        goto ef4;
ee4:
    if (b <= x->mA8)
        goto f40;
ef4:
    r = 3;
    if (b <= x->mA8)
        goto end1;
    if (b > lbl_805A6008)
        goto end1;
    r = 2;
end1:
    return r;
f04:
    if (ang > x->m9C)
        goto f34;
    if (ang < lbl_805A6004)
        goto f2c;
f24:
    return 0;
f2c:
    if (ang <= x->m9C)
        goto f48;
f34:
    if (ang > x->mA0)
        goto f48;
f40:
    return 1;
f48:
    r = 3;
    if (ang <= x->mA0)
        goto end2;
    if (ang > lbl_805A6008)
        goto end2;
    r = 2;
end2:
    return r;
}

extern float lbl_805A6018;
extern Unk801A4B34_Vec3 lbl_805A600C;

inline float Unk80022F88_M18(const Unk8002118C* m) { return m->m18; }
extern "C" int fn_80022F88(Unk80021A60_Data* x, int a, Unk801A4B34_Vec3* pos, int mode, int kind, float f,
                           Unk8001F2C4_World* w)
{
    int fl = 0;
    if (!(pos->x < 0.0f))
        fl = pos->z >= 0.0f;
    float ang = fn_80410CE8(pos->x, pos->z) * 57.295773f;
    float len = Unk80022BE0_Len(Unk80022BE0_Sub(lbl_80686DA8, *pos));
    Unk801A4B34_Pos* c = w->m6CC;
    float p3 = fn_8018CDB8(c, 3, 0.0f);
    float pA = fn_8018CDB8(c, 0xA, 0.0f);
    float pB = fn_8018CDB8(c, 0xB, 0.0f);
    Unk801A4B34_Vec3 e = lbl_805A600C;
    if (kind == 3) {
        if (!(p3 <= 0.0f) && p3 < pB) {
            Unk801A4B34_Vec3 t;
            fn_8018959C(&t, c, p3 - c->m3F4);
            e = t;
        } else if (!(pA <= lbl_805A6018) && !(pA >= pB)) {
            Unk801A4B34_Vec3 t;
            fn_8018959C(&t, c, pA - c->m3F4);
            e = t;
        }
    }
    switch (mode) {
    case 0:
        if (fl == 1) {
            if (!(pos->x > x->m8C->m14) && !(ang > Unk80022F88_M18(x->m8C)))
                return 2;
            int r = 3;
            if (!(len <= x->m8C->m20) && !(ang < x->mAC))
                r = 4;
            return r;
        }
        return a == 0;
    case 1:
        return 5;
    case 2:
        if (fl == 1) {
            if (!(pos->z > x->m8C->m14) && !(ang < 90.0f - x->m8C->m18))
                return 8;
            int r = 7;
            if (!(len <= x->m8C->m20) && !(ang > x->mB0))
                r = 6;
            return r;
        }
        {
            int r = 9;
            if (a != 0)
                r = 0xA;
            return r;
        }
    case 3: {
        int r = 0xB;
        if (a != 0)
            r = 0xC;
        return r;
    }
    default:
        return -1;
    }
}

int Unk80021A60::fn_800232A0(int kind, int v)
{
    int r = 1;
    switch (kind) {
    case 0:
        if ((float)v >= m8C->m54)
            r = 2;
        else if (!((float)v > m8C->m58))
            r = 0;
        break;
    case 1:
        if ((float)v >= m8C->m2C)
            r = 2;
        else if (!((float)v > m8C->m30))
            r = 0;
        break;
    case 2:
        if (!((float)v < m8C->m70))
            r = 2;
        else if (!((float)v > m8C->m74))
            r = 0;
        break;
    case 3:
        break;
    default:
        r = -1;
        break;
    }
    return r;
}

int Unk80021A60::fn_800233B4(int a, int b, int c)
{
    int ok = 0;
    for (int i = 0; i < 10; i++) {
        if (e[i].m4 == 0) {
            e[i].m4 = b;
            e[i].m0 = a;
            ok = 1;
            e[i].m8 = c;
            mB4++;
            break;
        }
    }
    return ok;
}

int Unk80021A60::fn_80023430(int key, int unused, int* out)
{
    int found = 0;
    if (mB4) {
        for (int i = 0; i <= 9; i++) {
            if (key == e[i].m0 && e[i].m4 != 0) {
                if (out)
                    *out = e[i].m4;
                found = 1;
                break;
            }
        }
    }
    return found;
}

void Unk80021A60::fn_80023490(int key, int unused)
{
    if (mB4 == 0)
        return;
    for (int i = 0; i < 10; i++) {
        if (key == e[i].m0 && e[i].m4 != 0)
            e[i].m4 = 0;
    }
}

class Unk80039B04_Mgr;
class Unk80306AC0_Obj;
class Unk8003A5DC;
class Unk8003A5DC_Ctx;
int fn_80039FD4(Unk80039B04_Mgr* self, Unk80306AC0_Obj* o);
void fn_8003B2DC(Unk8003A5DC* self, Unk8003A5DC_Ctx* ctx);
void fn_8003B394(Unk8003A5DC* self, int v);
void fn_8003B3B8(Unk8003A5DC* self, int v);
/* retail passes a third argument that the (2-parameter) definition ignores */
void fn_8003B23C(Unk8003A5DC* self, int i);
typedef void (*Unk80023838_Fn3)(Unk8003A5DC*, int, int);
extern "C" void fn_80378A34(void* sub, void* o);

extern char lbl_80649940[];
extern char lbl_80649968[];
extern char lbl_80649DB8[];
extern "C" void fn_8005C75C(Unk80038EB4_Obj* o, int a, int b);
extern "C" void fn_8037866C(void* p);
extern "C" void fn_80377408(void* p);
extern "C" void fn_80378620(void* p, int a);
extern "C" void fn_80021BB4(Unk80023AC4_Obj* self, int chrg);
struct Unk8034449C;
void fn_80344504(Unk8034449C* p, int a);

extern "C" void fn_80023758(Unk80023AC4_Obj* x, int chrg)
{
    *(const void**)((char*)x + 0xC4) = lbl_80649940;
    char* sub = (char*)x + 0xBC;
    *(const void**)((char*)x + 0xB8) = lbl_80649968;
    fn_80048968(fn_800475EC());
    fn_8005C75C(fn_8005BA9C(), 0, 0x12C);
    fn_8005C75C(fn_8005BA9C(), 1, 0x12C);
    fn_8005C75C(fn_8005BA9C(), 3, 0x12C);
    fn_800396D0(fn_80038EB4(), 1);
    x->m80[0] = 0;
    x->mC8 = 0;
    x->mCC = 0;
    x->mD0 = 0;
    fn_8037866C(sub);
    fn_80377408(x->m6B8);
    fn_80344504((Unk8034449C*)((char*)x + 0x728), 2);
    *(const void**)(sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_80021BB4(x, chrg);
}

extern "C" int fn_80023838(Unk80023AC4_Obj* x, Unk8001F2C4_World* w)
{
    int r = -1;
    if (x->m7C < 0) {
        x->m7C = 0;
        x->m80[x->m7C] = w;
        fn_80039FD4((Unk80039B04_Mgr*)fn_80038EB4(), (Unk80306AC0_Obj*)w);
        r = x->m7C;
        x->mC8 = w->m6F8;
        x->mCC = (int)((char*)w->m700 + 0x24);
        fn_80378A34(x->padBC, (char*)w + 0x704);
        fn_80378A34(x->padBC, w->m6E4 ? w->m6E4 + 0x360 : 0);
        int b = x->mC8->m14->e[1].m198;
        int a = x->mC8->m14->e[0].m198;
        fn_8003B2DC((Unk8003A5DC*)x->m6C8, (Unk8003A5DC_Ctx*)w);
        fn_8003B394((Unk8003A5DC*)x->m6C8, (int)fn_801A4B34(w));
        fn_8003B3B8((Unk8003A5DC*)x->m6C8, (int)fn_801A497C(w, w->m6F8->m14->m1CD0 == 0, 0));
        ((Unk80023838_Fn3)fn_8003B23C)((Unk8003A5DC*)x->m6C8, 0, a);
        ((Unk80023838_Fn3)fn_8003B23C)((Unk8003A5DC*)x->m6C8, 1, b);
    }
    return r;
}

/* In the idx == 0 branch CSE knows idx is 0: the zero stores take idx's register (r31), and the
 * slot is addressed as arr + idx (an unscaled offset, equal to arr[0] there), as retail's
 * lwzx/stwx with r31 show. A scaled arr[idx] folds to a plain 128(x) access, and so does the
 * offset when it goes through an inline parameter. */
extern "C" void fn_8002395C(Unk80023AC4_Obj* x, int idx)
{
    if (idx == 0) {
        Unk8001F2C4_World** arr = x->m80;
        char* sub = (char*)x + 0xBC;
        fn_80378ACC(sub, fn_801A4CE8(*(Unk8001F2C4_World**)((char*)arr + idx), 1));
        char* q = 0;
        if ((*(Unk8001F2C4_World**)((char*)arr + idx))->m6E4 != 0)
            q = (*(Unk8001F2C4_World**)((char*)arr + idx))->m6E4 + 0x360;
        fn_80378ACC(sub, q);
        fn_8003A058(fn_80038EB4(), 0);
        *(Unk8001F2C4_World**)((char*)arr + idx) = 0;
        x->mC8 = 0;
        x->mCC = 0;
        x->m7C = -1;
        fn_8003B378(x->m6C8);
    }
}
