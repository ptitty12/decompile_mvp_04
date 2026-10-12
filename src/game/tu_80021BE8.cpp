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

/* near-miss (110/110 insns, one load pair swapped): retail loads m5C before the spilled `a` for the first
 * compare of the block (fcmpu a,m5C); every spelling gives a-first or the swapped fcmpu. Same cause as
 * fn_80022BE0. The goto chain reproduces retail's threaded branch layout. */
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
    if (a <= x->m8C->m5C)
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

/* near-miss (97%): retail loads m20 first and compares fcmpu len1,m20; every spelling tried
 * (len1 > m20, m20 < len1, >=, nested, local) gives len1-first or the swapped branch. */
extern "C" int fn_80022BE0(Unk80021A60_Data* x, Unk801A4B34_Vec3* pos, int mode)
{
    float len1;
    Unk801A4B34_Vec3 d = Unk80022BE0_Sub(lbl_80686DA8, *pos);
    len1 = Unk80022BE0_Len(d);
    float len2 = Unk80022BE0_Len(*pos);
    if (len1 <= x->m8C->m1C || !(Unk80022BE0_Len(*pos) > x->m8C->m1C))
        return 0;
    if (!(len1 > x->m8C->m20))
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
    case 3:
        thr = x->m94 + x->m8C->m24;
        break;
    }
    return len2 > thr ? 3 : 2;
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

/* near-miss: 37/38 insns. Retail keeps the index in r31 inside the `idx == 0` branch
 * (stwx/lwzx with the register); here GCC folds it to 0. Tried <=, unsigned and else forms. */
extern "C" void fn_8002395C(Unk80023AC4_Obj* x, int idx)
{
    if (idx == 0) {
        Unk8001F2C4_World** arr = x->m80;
        char* sub = (char*)x + 0xBC;
        fn_80378ACC(sub, fn_801A4CE8(arr[idx], 1));
        char* q = 0;
        if (arr[idx]->m6E4 != 0)
            q = arr[idx]->m6E4 + 0x360;
        fn_80378ACC(sub, q);
        fn_8003A058(fn_80038EB4(), 0);
        arr[idx] = (Unk8001F2C4_World*)idx;
        x->mCC = idx;
        x->mC8 = (Unk8001F5CC_Tbl*)idx;
        x->m7C = -1;
        fn_8003B378(x->m6C8);
    }
}
