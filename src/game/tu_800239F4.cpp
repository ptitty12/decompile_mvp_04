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
extern float lbl_805A60DC;
extern const float lbl_805A60E0;
extern const float lbl_805A60CC;
extern const float lbl_805A60D8;
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





















extern "C" void fn_8002F160(Unk80023AC4_Obj* x);

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
    x->m294[x->m3D4].m24 = t;
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
        x->m294[x->m3D4].m10 = v;
        x->m294[x->m3D4].m18 = v;
        if (x->m510->fn_vslot24() != 0)
            x->m294[x->m3D4].m18.x = -v.x;
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

/* Frames to seconds through an inline: the constant-pool loads the inliner copies are not
 * unchanging, so sched1 keeps the lfd/lfs below the preceding stores while their lis halves
 * are hoisted above them (retail's lis cluster). */
inline float Unk800239F4_Secs(unsigned n)
{
    return (float)n * 0.016666668f;
}

extern "C" void fn_800243D4(Unk80023AC4_Obj* x)
{
    float a, b, c;
    fn_8018CA5C(x->m80[0]->m6CC, &a, &b, &c);
    x->m51C = 1;
    c = c * lbl_805A60CC;
    x->m528 = x->m80[0]->m700->m3A4->m1F8;
    x->m520 = Unk800239F4_Secs(x->m80[0]->m48);
    int t = (int)c;
    x->m1BC = t;
    fn_80021D6C(x, x->m80[0], t);
    fn_8002F160(x);
}

extern "C" void fn_800244A8()
{
}

extern "C" void fn_800244AC(Unk8001E444_Obj* x, Unk801A4B34_Pos* p, float f)
{
    if (p != 0 && fn_8024D408(p) != 0) {
        if (x->m444 == 8 || x->m444 == 0) {
            Unk801A4B34_Pos* pp = x->m130->m44C->m6CC;
            int n = 0;
            float g = fn_8018CDB8(pp, 2, lbl_805A60DC);
            if (!(g >= f)) {
                x->m444 = 6;
            } else {
                float t = lbl_805A60DC;
                for (int i = 0; i <= 4; i++) {
                    float g2 = fn_8018CDB8(pp, 0xB, t);
                    if (!(g2 >= f)) {
                        n++;
                        t = g2 + lbl_805A60E0;
                        continue;
                    }
                    break;
                }
                if (n == 0)
                    x->m444 = n;
                else if (n == 1)
                    x->m444 = 4;
                else if (n == 2)
                    x->m444 = 5;
            }
        }
    }
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

extern "C" void fn_800256F8(Unk80023AC4_Obj* x, Unk8002569C_Msg* m)
{
    int z = 0;
    x->m12C = m->mC;
    x->m140 = m->m24;
    x->m13C = m->m18;
    x->m144 = m->m28;
    x->m148 = m->m30;
    x->m14C = m->m2C;
    x->m150 = m->m34;
    int t = m->m8;
    x->m138 = z;
    x->m130.i = t;
    x->m134 = z;
    x->m15C = x->m6B8->m0;
    x->m158 = m->m3C;
    if (t == 6 || t == 8) {
        x->m150 = z;
        x->m108 = 1;
    } else if (t == 3 || t == 5) {
        x->m108 = 1;
    }
    Unk801A4B34_Pos* p = (Unk801A4B34_Pos*)m->mC;
    if (p != 0 && fn_8024D408(p) != 0 && x->m6B8->m0 == 3 && m->m44 != -1
        && fn_80257EA8(p->m44C->m700->m3B4, m->m44) != 0) {
        x->m134 = 1;
        if (m->m40 == -1)
            x->m138 = 1;
    }
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

extern "C" void fn_800263D4(Unk80023AC4_Obj* x)
{
    unsigned idx = Unk8002569C_Cast(x->m6BC, 0x6A)->m8;
    x->m6BC = 0;
    if (idx <= 2 && x->m270[idx].m0 != 0) {
        x->m12C = idx;
        x->m3E4 = x->m3E4 + 1;
        x->m1C0[idx] = x->m1C0[idx] + 1;
        x->m578 = 0;
        fn_8002A244(x, 0xC, Unk800239F4_Secs(x->m80[0]->m48));
        if (x->mD0 != 0)
            fn_80035AE8(x->mD0, x->m514, x->m3E4);
        if (x->m514 == 0)
            fn_8003CC0C(x->m6C8, x->m3E4);
        fn_8003F8A4(x->m6C8);
    }
    x->m6D0 = 1;
}

extern "C" void fn_800264F4(Unk80023AC4_Obj* x)
{
    Unk8002569C_Msg* m = Unk8002569C_Cast(x->m6BC, 0x6F);
    x->m12C = m->m8;
    x->m130.i = m->mC;
    fn_8002A244(x, 0x88, Unk800239F4_Secs(x->m80[0]->m48));
    x->m710 = 1;
    x->m6BC = 0;
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
