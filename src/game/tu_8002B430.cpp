/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8002B430-0x8002D15C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"

extern const float lbl_805A63F0;
extern const float lbl_805A6400;
extern const float lbl_805A6410;
extern const float lbl_805A6420;
extern const float lbl_805A6488;
extern const float lbl_805A6440;
extern const float lbl_805A6468;
extern const float lbl_805A64B0;
extern const float lbl_805A64C0;

extern "C" int fn_8002B82C(Unk80023AC4_Obj* x)
{
    int v = x->m160.m48;
    int r = 0;
    if (v == 1)
        r = 1;
    else if (v > 1)
        r = 2;
    return r;
}

extern Unk801A4B34_Vec3 lbl_805B1A00;
extern "C" int fn_80022708(int unused, int idx);
void fn_80035420(int a, int b, int c, int d);

static inline Unk801A4B34_Vec3 Unk8002B850_Sub(const Unk801A4B34_Vec3& a, const Unk801A4B34_Vec3& b)
{
    Unk801A4B34_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

extern "C" void fn_8002B850(Unk80023AC4_Obj* x)
{
    Unk801A4B34_Pos* p = x->m80[0]->m6CC;
    Unk801A4B34_Vec3 pos = p->m60;
    if (p->m38C == 1 && x->mF0 == 0 && p->m388 != 1 && x->mF8 == 0) {
        float len;
        Unk801A4B34_Vec3 d = Unk8002B850_Sub(lbl_805B1A00, pos);
        len = fn_804028E4(d.x * d.x + d.z * d.z) * 0.083333336f;
        if (!(pos.x <= 0.0f) && !(pos.z <= 0.0f) && !(len <= x->m8C->m1C)) {
            int dd = x->mD0;
            if (dd != 0) {
                int c = x->m514;
                int v = fn_80022708((int)x, 1);
                fn_80035420(dd, c, v, fn_8002A2D4(x));
            }
            fn_8002A244(x, 0x49, (float)x->m80[0]->m48 * 0.016666668f);
        }
    }
}

extern "C" void fn_8002BA00(Unk80023AC4_Obj* x)
{
    x->m160.m4C = 0;
    for (int i = 0; i < x->m260; i++) {
        Unk801A4B34_Rec58C* r = &((Unk801A4B34_Pos*)x->m1D0[i].m0)->m58C;
        if ((r->m4 & 0x20000000) == 0) {
            if (r->m30 > x->m1D0[i].m8)
                x->m160.m4C = x->m160.m4C + 1;
        }
    }
    if (x->m160.m4C > 0 && x->m6E8 == 0)
        fn_8002A244(x, 0x50, (float)x->m80[0]->m48 * lbl_805A63F0);
}

extern "C" int fn_8002BAD8(Unk80023AC4_Obj* x, int a, int b)
{
    int r = 0;
    for (int i = 0; i < x->m260; i++) {
        Unk80023ED8_Ent* e = &x->m1D0[i];
        if (e->m0 == a) {
            int v = e->m8;
            if (e->m14 == v + 1 && v == b)
                r = 1;
            e->m20 = 1;
            break;
        }
    }
    return r;
}

/* near-miss: 68/68 insns, ~10 slots differ (scheduling of the m130/m12C stores around the
 * duration conversion; same family as fn_800264F4 in tu_800239F4.cpp). */
extern "C" void fn_8002BB3C(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x80);
    int id = m->mC;
    if (x->m71C == id) {
        x->m12C = id;
        fn_8002A244(x, 0x59, (float)x->m80[0]->m48 * lbl_805A6400);
    }
    if (fn_8002BAD8(x, id, m->m8) != 0) {
        x->m12C = id;
        x->m130.i = m->m8;
        fn_8002A244(x, 0x51, (float)x->m80[0]->m48 * lbl_805A6400);
    }
    x->m6BC = 0;
}

extern "C" void fn_8002BC4C(Unk80023AC4_Obj* x)
{
    Unk801A4B34_Pos* p = (Unk801A4B34_Pos*)Unk8002569C_Cast(x->m6BC, 0x81)->m8;
    if (fn_8002BAD8(x, (int)p, p->m58C.m38) != 0) {
        x->m12C = (int)p;
        fn_8002A244(x, 0x52, (float)x->m80[0]->m48 * lbl_805A6410);
    }
    x->m6BC = 0;
}

extern "C" int fn_8002BD04(Unk80023AC4_Obj* x, Unk80023F98_Pl* y)
{
    int r = 0;
    if (x->m160.m44 > 0) {
        r = 3;
    } else if (x->mFC == 1) {
        if (x->mDC == 0) {
            if (x->m52C > 3)
                r = 2;
            if (x->mF4 == 1)
                r = 4;
        } else if (x->m10C == 1) {
            r = 1;
        }
    }
    if (y == x->m510)
        r = 1;
    return r;
}

extern "C" void fn_8002BD80()
{
}

extern "C" void fn_8002BD84()
{
}

extern "C" void fn_8002BD88(Unk80023AC4_Obj* x)
{
    x->m6E4 = 1;
}

extern "C" void fn_8002BD94(Unk80023AC4_Obj* x)
{
    fn_80048914(fn_800475EC(), x->m80[0]);
}

extern "C" void fn_8002BDC8(Unk80023AC4_Obj* x)
{
    int v = Unk8002569C_Cast(x->m6BC, 0x6E)->m8;
    if (x->m71C != v)
        x->m71C = v;
    x->m6BC = 0;
}

/* near-miss: 68/68 insns, ~10 slots differ (same scheduling difference as fn_8002BB3C). */
extern "C" void fn_8002BE10(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x73);
    if (m->m10 != 0) {
        Unk8001F2C4_World* w = x->m80[0];
        if (w->m6CC->m38C == 1) {
            x->m12C = m->m8;
            x->m130.i = m->m14;
            fn_8002A244(x, 0x2E, (float)w->m48 * lbl_805A6420);
        }
    } else {
        Unk8001F2C4_World* w = x->m80[0];
        x->m12C = m->m8;
        fn_8002A244(x, 0x2D, (float)w->m48 * lbl_805A6420);
    }
    x->mF8 = 0;
}

/* near-miss: 54/54 insns, ~16 slots differ (message pointer in r6 vs r7; same family). */
extern "C" void fn_8002BF20(Unk80023AC4_Obj* x)
{
    if (x->m514 == 0)
        fn_8003C9F4(x->m6C8);
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x8C);
    x->m12C = m->m8;
    x->m130.i = m->mC;
    fn_8002A244(x, 0x45, (float)x->m80[0]->m48 * lbl_805A6440);
    x->m724 = (Unk801A4B34_Pos*)x->m12C;
    x->fn_800233B4(0x33, 0x1E, 0);
    x->m6BC = 0;
}

extern "C" void fn_8002C274(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x43, (float)x->m80[0]->m48 * lbl_805A6468);
}

extern "C" void fn_8002C2CC()
{
}

extern "C" void fn_8002C51C(Unk80023AC4_Obj* x)
{
    fn_8003E8E4(x->m6C8);
}

/* near-miss: 75/75 insns, 14 slots differ (placement of the conversion constant loads
 * relative to the m160.m20[] increment; same family as fn_800243D4). */
extern "C" void fn_8002C540(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x84);
    int id = m->mC;
    Unk8001F2C4_World* w = x->m80[0];
    x->m160.m44 = x->m160.m44 + 1;
    Unk8001F218_Pair* base = w->m6F8->m14;
    Unk801A4B34_Pos* p = fn_801A497C(w, base->m1CD0 == 0, id);
    x->m12C = (int)p;
    x->m160.m20[p->m708] = x->m160.m20[p->m708] + 1;
    fn_8002A244(x, 0x38, (float)x->m80[0]->m48 * lbl_805A6488);
    fn_8003CC54(x->m6C8, id);
    int v = fn_80097A70(&x->m80[0]->m6F8->m14->e[p->m708], 1, p->m70C, 0);
    fn_8003CA24(x->m6C8, v);
    x->m6BC = 0;
}

extern "C" void fn_8002C66C(Unk80023AC4_Obj* x)
{
    int d = x->mD0;
    if (d != 0) {
        Unk8001F2C4_World* w = x->m80[0];
        int c = x->m514;
        unsigned n = fn_8002A4C0(x, w);
        fn_8003538C(d, c, n, fn_8002A2D4(x));
    }
}

extern "C" void fn_8002C6CC(Unk80023AC4_Obj* x)
{
    if (x->m6F8 != 0)
        fn_8002C6F8(x);
}

extern "C" void fn_8002C6F8(Unk80023AC4_Obj* x)
{
    x->m6E0 = 0;
    if (x->m6F0 == 0)
        fn_80026D7C(x);
    x->fn_800233B4(0x12, 0xA, 0);
}

extern "C" void fn_8002C74C(Unk80023AC4_Obj* x)
{
    if (x->fn_80023430(0x11, 0, 0) == 1 || x->fn_80023430(7, 0, 0) == 1 || x->fn_80023430(8, 0, 0) == 1
        || x->fn_80023430(0xA, 0, 0) == 1 || x->fn_80023430(0x16, 0, 0) == 1 || x->m80[0]->m4C < x->m128) {
        x->fn_800233B4(0x12, 1, 0);
        return;
    }
    fn_8002C830(x);
}

extern "C" void fn_8002CC7C(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x30, (float)x->m80[0]->m48 * lbl_805A64B0);
}

extern "C" void fn_8002CCD4(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x31, (float)x->m80[0]->m48 * lbl_805A64C0);
}
