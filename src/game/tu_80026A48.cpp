/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80026A48-0x80029000 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800239F4.h"

extern const float lbl_805A61FC;
extern const float lbl_805A6240;
extern const float lbl_805A6250;
extern const float lbl_805A62A0;
extern const float lbl_805A62B0;
extern const float lbl_805A6260;
extern const float lbl_805A6280;
extern const float lbl_805A62C0;
extern const float lbl_805A62D0;










extern "C" void fn_80028CEC(Unk80023AC4_Obj* x);
extern "C" void fn_80028E18(Unk80023AC4_Obj* x);

extern "C" void fn_80026D7C(Unk80023AC4_Obj* x)
{
    fn_803EE7BC();
    if (x->m704 == 0) {
        fn_80048968(fn_800475EC());
        int v = 3;
        fn_800396D0(fn_80038EB4(), 1);
        if (x->mC8->mC->m28 == 0x37)
            v = 6;
        fn_8005C250(fn_8005BA9C(), v);
        fn_8003968C(fn_80038EB4(), v);
        fn_80039854(fn_80038EB4(), 0, fn_8017FA08(x->mCC));
        fn_80039790(fn_80038EB4(), fn_8017FA08(x->mCC));
        fn_800398E4(fn_80038EB4(), lbl_805A61FC);
        fn_800395B0(fn_80038EB4(), v);
        fn_80039790(fn_80038EB4(), fn_8017FA08(x->mCC));
        fn_80048C08((char*)fn_800475EC() + 0xFC);
        x->m704 = 1;
    }
    fn_803EE7BC();
}

extern "C" void fn_80026E7C()
{
}

extern "C" void fn_80026E80()
{
    fn_80030274();
}

extern "C" void fn_80027CCC(Unk80023AC4_Obj* x)
{
    fn_8003EAB0(x->m6C8);
}

extern "C" void fn_80028088(Unk80023AC4_Obj* x)
{
    if (fn_801C3F00(x->m80[0]->m700->m3A4) == 0)
        fn_8002A244(x, 0x65, (float)x->m80[0]->m48 * lbl_805A6240);
}

extern "C" void fn_80028108(Unk80023AC4_Obj* x)
{
    if (x->m724 != 0)
        fn_80022080(x, x->m80[0], x->m724);
}

extern "C" void fn_80028138(Unk80023AC4_Obj* x)
{
    Unk8001F2C4_World* w = x->m80[0];
    Unk801A4B34_Pos* p = w->m6CC;
    if (p->m38C != 1 || p->m388 != 3)
        fn_8002A244(x, 0x23, (float)w->m48 * lbl_805A6250);
}

extern "C" void fn_800281AC(Unk80023AC4_Obj* x)
{
    if (x->m10C == 0) {
        int v = x->m794;
        if (v == (int)x->m510 && x->m160.m44 <= 0) {
            x->m12C = v;
            fn_8002A244(x, 0x32, (float)x->m80[0]->m48 * lbl_805A6260);
            fn_8002F850(x);
            x->m160.m8 = x->m160.m8 + 1;
            return;
        }
        x->m12C = v;
        fn_8002A244(x, 0x20, (float)x->m80[0]->m48 * lbl_805A6260);
    }
}

extern "C" void fn_80028298(Unk80023AC4_Obj* x)
{
    x->m56C = 1;
    x->m564 = fn_801C3E28(x->m80[0]->m700->m3A4);
}

extern "C" void fn_800282DC(Unk80023AC4_Obj* x)
{
    x->m574 = 1;
}

extern "C" void fn_8002847C(Unk80023AC4_Obj* x)
{
    if (x->m11C == 0) {
        x->m11C = 1;
        x->m124 = x->m80[0]->m4C + 2;
        fn_800289F8(x);
        Unk8001F2C4_World* w = x->m80[0];
        if (w->m6F8->m14->m1CD0 == 1) {
            fn_8002A244(x, 0x17, (float)w->m48 * lbl_805A6280);
            return;
        }
        fn_8002A244(x, 0x18, (float)w->m48 * lbl_805A6280);
    }
}

extern "C" void fn_80028560()
{
}

extern "C" void fn_80028944(Unk80023AC4_Obj* x)
{
    if (x->fn_80023430(0xA, 0, 0) == 0) {
        if (x->m118 == 0 && x->m104 == 0) {
            fn_8002A244(x, 0x2A, (float)x->m80[0]->m48 * lbl_805A62A0);
            x->fn_800233B4(0x1E, 0x46, 0);
        }
        x->m104 = 1;
    }
}

extern "C" void fn_80028B94(Unk80023AC4_Obj* x)
{
    fn_80038EB4();
    fn_80039F04();
    fn_8002A244(x, 0x53, (float)x->m80[0]->m48 * lbl_805A62B0);
    fn_8003C9A0(x->m6C8);
    fn_800289F8(x);
    if (x->mD0 != 0)
        fn_80035E94(x->mD0);
}

extern "C" void fn_80028C24(Unk80023AC4_Obj* x)
{
    x->fn_800233B4(8, 4, 0);
}

extern "C" void fn_80028C50(Unk80023AC4_Obj* x)
{
    Unk8001F2C4_World* w = x->m80[0];
    if (w != 0 && fn_8006BE18(w->m6F8) != 0 && x->m7F4 == 0) {
        int r = x->fn_80023430(0x22, 0, 0);
        if (r == 0) {
            x->fn_80023490(0xA, 0);
            x->fn_80023490(7, 0);
            x->m6FC = r;
        }
    } else {
        fn_80028CEC(x);
    }
}

extern "C" void fn_80028CEC(Unk80023AC4_Obj* x)
{
    if (x->m100 == 0) {
        x->fn_800233B4(7, 0x1E, 0);
        if (x->fn_80023430(0xA, 0, 0) == 0)
            fn_80028E18(x);
    } else if (x->fn_80023430(0xA, 0, 0) == 1) {
        x->fn_800233B4(7, 0x1E, 0);
    } else {
        x->m118 = x->m118 + 1;
        if (x->m118 <= 1) {
            x->m128 = x->m80[0]->m4C + 2;
            fn_80344494(x->m80[0]->fn_801A6D84(1) + 1, 0);
            fn_8002A244(x, 0x16, (float)x->m80[0]->m48 * lbl_805A62C0);
        }
    }
    if (x->m638 == 2)
        fn_8003F974(x->m6C8);
}

extern "C" void fn_80028E18(Unk80023AC4_Obj* x)
{
    if (x->m100 == 0) {
        x->m100 = 1;
        x->fn_800233B4(0xA, 0x23, 0);
    }
}

extern "C" void fn_80028E5C(Unk80023AC4_Obj* x)
{
    if (x->m100 == 1 && x->m80[0]->m700->m3B4->mC == 1) {
        fn_8002B5B0();
        if (x->m104 == 0)
            fn_8002A244(x, 0x29, (float)x->m80[0]->m48 * lbl_805A62D0);
    } else {
        x->fn_800233B4(0xA, 0x2D, 0);
    }
}

extern "C" void fn_80028F10(Unk80023AC4_Obj* x)
{
    int v = 1;
    fn_800289F8(x);
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        Unk800B555C_Quad q = fn_800B555C()->m688;
        v = q.m0 == -1;
    }
    fn_8003C804(x->m6C8, v);
    if (x->mD0 != 0)
        fn_80035E94(x->mD0);
}

extern "C" void fn_80028FA8(Unk80023AC4_Obj* x)
{
    if (fn_801C3F00(x->m80[0]->m700->m3A4) != 0) {
        x->m56C = 1;
        return;
    }
    fn_80021C1C(x, x->m80[0]);
}
