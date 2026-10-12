/*
 * Front-end overlay code, .frontend_codeoverlay 0x804A721C-0x804AA58C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY int fn_804A721C(FeScrB* x)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_800B7ADC(lbl_8061A32C, x);
    return 1;
}

FE_OVERLAY void fn_804A7278(void* a, char* p)
{
    *p = 0;
}

FE_OVERLAY void fn_804A7284(void) {}

FE_OVERLAY FeScrH* fn_804A7288(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80681F30);
    self->m130 = 0;
    FeI(self, 0x140) = 1;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    return self;
}

FE_OVERLAY void fn_804A740C(FeW* x)
{
    fn_800ECF18(x);
    if (fn_800B57EC(fn_800B555C()) == 0) {
        x->fn_vslot8(0);
        x->fn_vslot16(0);
    } else {
        fn_804A7760(x);
    }
}

FE_OVERLAY void fn_804A748C(void* x, int a)
{
    fn_800ECDCC(x, a);
    fn_804A763C(x, a ^ 1);
}

FE_OVERLAY void fn_804A74C8(FeW* x, int v)
{
    if (v == *(int*)((char*)x + 0x144)) {
        fn_804A7874(x, v);
    }
}

FE_OVERLAY int fn_804A74F4(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        FeMem(x, 0x144)->fn_vslot40(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A7548(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        ((FeWV*)FeMem(x, 0x144))->s41();
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A7598(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        FeMem(x, 0x144)->fn_vslot38(1);
        r = 1;
    }
    return r;
}

FE_OVERLAY int fn_804A75EC(void* x)
{
    int r;
    if (FeI(x, 0x140) == 0) {
        r = 0;
    } else {
        FeMem(x, 0x144)->fn_vslot39();
        r = 1;
    }
    return r;
}

FE_OVERLAY void fn_804A763C(void* x, int a)
{
    int v = a ^ 1;
    FeMem(x, 0x144)->fn_vslot8(v);
    FeI(x, 0x140) = v;
}

FE_OVERLAY void fn_804A7760(FeW* x)
{
    if (FeW24(x) < 0) {
        fn_804A77AC(x, fn_800C203C((char*)fn_800B555C() + 8));
    }
}

FE_OVERLAY void fn_804A77AC(void* x, int a)
{
    ((FeSubB*)((char*)FeP(x, 0x134) + 0xDC))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x138) + 0xDC))->s20(a, 0);
    ((FeSubB*)((char*)FeP(x, 0x13C) + 0x98))->s20(a, 0);
    ((FeSub*)((char*)FeP(x, 0x148) + 0xDC))->s6(FeI(FeP(x, 0x134), 0xE8));
}

FE_OVERLAY void fn_804A7DD4(void* x)
{
    fn_804A8750(x);
    fn_804A89D0(x);
}

FE_OVERLAY int fn_804A7E08(char* x, int a)
{
    if (a == *(int*)(x + 0x140) || a == *(int*)(x + 0x144)) {
        fn_804A8004(x, a);
    }
    return 0;
}

FE_OVERLAY void fn_804A7E44(void* a, int b, int c)
{
    fn_804A7FBC(a, c);
}

FE_OVERLAY void fn_804A7E68(void) {}

FE_OVERLAY int fn_804A7E6C(void* x)
{
    FeMem(x, 0x204)->fn_vslot50();
    return 0;
}

FE_OVERLAY int fn_804A7EA8(void* x)
{
    FeMem(x, 0x204)->fn_vslot52();
    return 0;
}

FE_OVERLAY int fn_804A7EE4(void* x)
{
    FeMem(x, 0x204)->fn_vslot51();
    return 0;
}

FE_OVERLAY int fn_804A7F20(void* x)
{
    FeMem(x, 0x204)->fn_vslot53();
    return 0;
}

FE_OVERLAY int fn_804A7F5C(char* x)
{
    fn_804A8004(x, *(int*)(x + 0x144));
    return 0;
}

FE_OVERLAY int fn_804A7F84(char* x)
{
    fn_804A8004(x, *(int*)(x + 0x140));
    return 0;
}

FE_OVERLAY int fn_804A7FAC(void) { return 0; }

FE_OVERLAY int fn_804A7FB4(void) { return 0; }

FE_OVERLAY void fn_804A7FBC(void* x, int a)
{
    FeI(x, 0x148) = a;
    fn_804A80E4(x);
    fn_804A8750(x);
    fn_804A89D0(x);
}

FE_OVERLAY int fn_804A7FFC(void* x)
{
    return FeI(x, 0x148);
}

FE_OVERLAY int fn_804A80DC(void* x)
{
    return FeI(x, 0x204);
}

FE_OVERLAY void fn_804A80E4(void* x)
{
    fn_804A8118(x);
    fn_804A83D0(x);
}

FE_OVERLAY void fn_804A8B9C(void* x)
{
    int id = fn_804A7FFC(x);
    int idx = FeMem(x, 0x140)->fn_vslot60();
    int o = idx * 4;
    fn_8007F3E8__FP13Unk8007F198_Aii(lbl_8061930C, id, *(int*)((char*)FeP(x, 0x14C) + o));
    fn_804A8F98(x);
    fn_804A86BC(x);
    fn_804A83D0(x);
}

FE_OVERLAY void fn_804A8ED4(void* x)
{
    if (fn_804A80DC(x) == FeI(x, 0x140)) {
        FeList* l = (FeList*)FeP(x, 0x138);
        fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    } else {
        FeList* l = (FeList*)FeP(x, 0x138);
        fn_80126CF4(l, 0, FeI(l, 0x168), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    }
    fn_804A89D0(x);
}

FE_OVERLAY void fn_804A8F98(void* x)
{
    FeList* l = (FeList*)FeP(x, 0x138);
    fn_80126CF4(l, l->m164, 0, l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    l = (FeList*)FeP(x, 0x138);
    fn_80126CF4(l, 0, FeI(l, 0x168), l->m134, l->m16C, l->m170, 0, l->m138, l->m13C, l->m148, l->m14C);
    fn_804A89D0(x);
}

FE_OVERLAY void fn_804A91FC(int a, void* b)
{
    if (a == 1) {
        fn_804A8B9C(b);
    }
}

FE_OVERLAY void fn_804A93B8(int a, void* b)
{
    if (a == 1) {
        fn_804A8C1C(b);
    }
}

FE_OVERLAY FeScrH* fn_804A93E4(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806735E0);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    return self;
}

FE_OVERLAY void fn_804A9620(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY void fn_804A9648(FeScrD* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY void fn_804A9668(FeW* x)
{
    if (x) {
        ((FeWV*)x)->s8();
    }
}

FE_OVERLAY void fn_804AA554(FeScrL* x)
{
    x->fn_vslot8(0);
}

}
