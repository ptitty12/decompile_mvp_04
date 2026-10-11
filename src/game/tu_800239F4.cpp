/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800239F4-0x80026A48 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"

extern const float lbl_805A60B8;
extern const float lbl_805A60C8;
extern const float lbl_805A61C0;
extern const float lbl_805A61E0;
extern const float lbl_805A6068;
extern const float lbl_805A6074;
extern const float lbl_805A6078;
extern const float lbl_805A6088;
extern const float lbl_805A6190;
extern const float lbl_805A61A0;
extern const float lbl_805A613C;
extern const float lbl_805A6140;
extern const float lbl_805A6144;
extern const float lbl_805A6148;
extern const float lbl_805A614C;
extern const float lbl_805A6150;
extern const float lbl_805A6154;

















extern "C" void fn_800243D4(Unk80023AC4_Obj* x);
extern "C" void fn_80023F98(Unk80023AC4_Obj* x);

/* near-miss: 52/52 insns, ~20 slots differ (register allocation of the message pointer and the
 * Vec3 copy temporaries: retail keeps it in r12 and reloads words 1 and 2 of the local copy
 * for the by-value argument). ~10 forms tried (inline getter, order of n and v). */
extern "C" void fn_800239F4(Unk80023AC4_Obj* x, int idx, int kind, Unk8002569C_Msg* msg)
{
    if (kind == 0x50) {
        Unk800239F4_Msg50* m;
        if (msg != 0) {
            m = 0;
            if (kind == msg->m0)
                m = (Unk800239F4_Msg50*)msg;
        } else {
            m = 0;
        }
        int sx, sy;
        Unk801A4B34_Vec3 v = Unk800239F4_Pos(m);
        int n = (int)m->m14;
        fn_800222B4(x->m80[idx], &sx, &sy, v);
        fn_800412AC(fn_8004072C(), 0xE, sx, sy, n, 0);
    }
}

extern "C" void fn_80023AC4(Unk80023AC4_Obj* x)
{
    fn_8001CE80(&x->m160);
    x->m700 = 0;
    float f = (float)x->m80[0]->m48 * lbl_805A6068;
    fn_8002A244(x, 0x13, f);
    for (int i = 0; i <= 8; i++) {
        Unk801A4B34_Pos* p = fn_801A497C(x->m80[0], x->m290->m708, i);
        if (p != 0)
            x->m640[i] = p->m60;
    }
}

extern "C" void fn_80023E18(Unk80023AC4_Obj* x)
{
    Unk801A4B34_Pos* p = x->m80[0]->m6CC;
    float a = fn_80190F0C(p);
    float b = p->m3F4;
    Unk801A4B34_Vec3 d;
    fn_80189618(&d, p, a - b);
    float len = Unk801A4B34_Len(d) * lbl_805A6074;
    int t = (int)(len / p->m3E8 + lbl_805A6078);
    x->m1BC = t;
    x->m2A4[x->m3D4].m14 = t;
}

extern "C" void fn_80023ED8(Unk80023AC4_Obj* x)
{
    for (int i = 0; i < x->m260; i++)
        x->m1D0[i].m14 = -1;
    x->m6CC = (float)x->m80[0]->m4C * lbl_805A6088;
    fn_800243D4(x);
    x->fn_800233B4(0, 10, 0);
    x->mDC = 1;
    fn_80023F98(x);
}

extern "C" void fn_80023F98(Unk80023AC4_Obj* x)
{
    if (x->m70C == 0) {
        Unk80023F98_Vec2 v = fn_80235BE0(x->m80[0]->m700->m3B0);
        x->m2A4[x->m3D4].m0 = v;
        x->m2A4[x->m3D4].m8 = v;
        if (x->m510->fn_vslot24() != 0)
            x->m2A4[x->m3D4].m8.x = -v.x;
        x->m70C = 1;
    }
}

extern "C" void fn_80024320(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x10, (float)x->m80[0]->m48 * lbl_805A60B8);
}

extern "C" void fn_80024378()
{
}

extern "C" void fn_8002437C(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 4, (float)x->m80[0]->m48 * lbl_805A60C8);
}

extern "C" void fn_800244A8()
{
}

extern "C" void fn_800245D0(Unk80023AC4_Obj* x)
{
    x->m568 = fn_803445A0(x->m80[0]->m700->m3A4->m28C);
}

extern "C" void fn_800254C0(Unk80023AC4_Obj* x)
{
    Unk801A4B34_Pos* p = fn_801A497C(x->m80[0], 4, 3);
    float t = Unk801A4B34_Len(p->m60) * lbl_805A613C + lbl_805A6140;
    Unk801A4B34_Pos* q = x->m718;
    if (q != 0 && (unsigned)(q->m460 - 2) <= 3) {
        t = Unk801A4B34_Len(q->m60) * lbl_805A613C;
        t += lbl_805A6140;
    }
    fn_8002559C(x, t);
}

extern "C" float fn_8002559C(Unk80023AC4_Obj* x, float f)
{
    Unk801A4B34_Pos* p = x->m80[0]->m6CC;
    int found = 0;
    float a = lbl_805A6144;
    float b = lbl_805A6148;
    float c = fn_8018A214(p);
    Unk801A4B34_Vec3 v;
    do {
        fn_8018959C(&v, p, b);
        a = Unk801A4B34_Len(v) * lbl_805A614C;
        if (a >= f) {
            found = 1;
            break;
        }
        b += lbl_805A6150;
    } while (b < c);
    if (found == 0)
        b = lbl_805A6154;
    else
        b = b + lbl_805A6150;
    return b;
}

extern "C" void fn_8002569C(Unk80023AC4_Obj* x, Unk8002569C_Msg* m)
{
    x->m7BC = m->mC;
    x->m12C = m->mC;
    x->m130.f = m->m1C;
    x->m13C = m->m18;
    x->m140 = m->m28;
    x->m144 = m->m30;
    x->m148 = m->m2C;
    x->m14C = m->m34;
    int v = m->m8;
    x->m134 = v;
    x->m138 = (v ^ 6) == 0;
}

extern "C" int fn_80026330(Unk80023AC4_Obj* x, Unk8001F2C4_World* ctx, Unk801A4B34_Pos* a, Unk801A4B34_Pos* p)
{
    int r;
    if (ctx->m6CC == a) {
        r = 1;
    } else {
        int flag = 0;
        if (ctx->m780 != 0 || ctx->m784 != 0)
            flag = 1;
        if (flag != 0) {
            r = ctx->m788 == p->m708;
        } else {
            ctx->fn_801A6D84(1);
            if (fn_8016ADC4() != 0)
                r = 1;
            else
                r = (unsigned)p->m458 <= 1;
        }
    }
    return r;
}

/* near-miss: 72/72 insns, 12 slots differ (register numbers of the constant-pool loads and
 * the m1C0 base; same instructions). Tried statement order and pointer-local forms. */
extern "C" void fn_800263D4(Unk80023AC4_Obj* x)
{
    unsigned idx = Unk8002569C_Cast(x->m6BC, 0x6A)->m8;
    x->m6BC = 0;
    if (idx <= 2 && x->m270[idx].m0 != 0) {
        x->m12C = idx;
        x->m3E4 = x->m3E4 + 1;
        x->m1C0[idx] = x->m1C0[idx] + 1;
        x->m578 = 0;
        fn_8002A244(x, 0xC, (float)x->m80[0]->m48 * lbl_805A6190);
        if (x->mD0 != 0)
            fn_80035AE8(x->mD0, x->m514, x->m3E4);
        if (x->m514 == 0)
            fn_8003CC0C(x->m6C8, x->m3E4);
        fn_8003F8A4(x->m6C8);
    }
    x->m6D0 = 1;
}

/* near-miss: 44/44 insns, ~17 slots differ (register numbers and store order of the two
 * constants at the end; swapping the last two statements makes it worse). */
extern "C" void fn_800264F4(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x6F);
    x->m12C = m->m8;
    x->m130.i = m->mC;
    fn_8002A244(x, 0x88, (float)x->m80[0]->m48 * lbl_805A61A0);
    x->m6BC = 0;
    x->m710 = 1;
}

extern "C" void fn_800265A4(Unk80023AC4_Obj* x)
{
    x->m114 = 1;
}

extern "C" void fn_800265B0()
{
}

extern "C" void fn_80026784(Unk80023AC4_Obj* x)
{
    fn_8002A244(x, 0x82, (float)x->m80[0]->m48 * lbl_805A61C0);
}

extern "C" void fn_800269E0(Unk80023AC4_Obj* x)
{
    Unk8001F2C4_World* w = x->m80[0];
    if (w->m6CC->m38C == 3)
        fn_8002A244(x, 0x2B, (float)w->m48 * lbl_805A61E0);
}
