/*
 * Front-end overlay code, .frontend_codeoverlay 0x804A721C-0x804AA58C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

struct FeArrL { char* m0; int m4; int m8; int mC; const void* m10; int m14; };
extern const char lbl_80673888[];
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A4C8[];
extern "C" void fn_8040074C(void* p, int n);
extern "C" int fn_8057CF60(void* l, int a);
struct FeHoldDC { char pad0[0xDC]; FeSub mDC; };
extern "C" void fn_800C2034(void* p, int a);
extern "C" void fn_8007F438__FP13Unk8007F198_Aii(void* g, int a, int b);
extern "C" void fn_804A90C8(void* x);
extern "C" void fn_804A9228(void* x);
extern "C" void fn_804A8CE8(void* x);
extern "C" void fn_804A89D0(void* x);
extern "C" int fn_804A9048(int x, int v);
extern "C" int fn_8007F488__FP13Unk8007F198_A(void* g, int a);
extern "C" int fn_8007F4D0__FP13Unk8007F198_Aii(void* g, int a, int b);
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

FE_OVERLAY void fn_804A72E4(FeW* x)
{
    fn_800ECE34(x);
    FeP(x, 0x134) = fn_800C8058(x->fn_vslot32("TEAMNAME", 1));
    FeP(x, 0x138) = fn_800C8058(x->fn_vslot32("TEAMNAMESHD", 1));
    FeP(x, 0x13C) = fn_800C8054(x->fn_vslot32("TEAMLOGO", 1));
    FeW* t = fn_800C805C(x->fn_vslot32("LEAGUESG", 1));
    FeP(x, 0x144) = t;
    FeP(x, 0x148) = fn_800C8058(t->fn_vslot32("LEAGUE", 1));
    FeMem(x, 0x144)->fn_vslot8(FeI(x, 0x140));
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

FE_OVERLAY void fn_804A768C(void* x)
{
    FeMem(x, 0x134)->fn_vslot8(0);
    FeMem(x, 0x138)->fn_vslot8(0);
    FeMem(x, 0x13C)->fn_vslot8(0);
    ((FeW*)x)->fn_vslot32("FC2", 1)->fn_vslot8(0);
    fn_804A763C(x, 1);
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

FE_OVERLAY void fn_804A7874(void* x, int unused)
{
    FeHoldDC* hh = (FeHoldDC*)FeMem(x, 0x148);
    int a = ((FeSub*)&hh->mDC)->s5();
    void* lst = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    int b = fn_8057CF60(lst, a);
    fn_800C2034((char*)fn_800B555C() + 8, a);
    void* l = FeP(FeGetMgr(), 0xA0);
    int i = 0;
    if (i < FeI(l, 0x1C4)) {
        int o = 0;
        do {
            char* t = (char*)l + 0x34;
            FeWR* e = *(FeWR**)(t + o);
            i++;
            o += 4;
            e->s70(a, b);
        } while (i < FeI(l, 0x1C4));
    }
    fn_804A7760((FeW*)x);
}

FE_OVERLAY FeScrH* fn_804A7970(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    FeArrL* s = (FeArrL*)((char*)self + 0x14C);
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80673888);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    s->m10 = lbl_8064B298;
    s->m0 = (char*)self + 0x164;
    s->m8 = 0x28;
    fn_8040074C(s->m0, 0xA0);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->m4 = 0;
    s->mC = 0;
    s->m14 = 0;
    s->m10 = lbl_8064A4C8;
    FeI(self, 0x204) = 0;
    return self;
}

FE_OVERLAY void fn_804A7CEC(void* x, int k)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8035682C(p);
    switch (k) {
    case 0:
        fn_8040B830(p->name, lbl_805F4450, 15);
        p->name[15] = k;
        fn_800B7B4C(FeGetMgr(), p, x);
        break;
    case 1:
        fn_804A90C8(x);
        break;
    case 2:
        fn_804A9228(x);
        break;
    case 3:
        fn_804A8CE8(x);
        break;
    case 4:
        fn_804A8ED4(x);
        break;
    }
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

FE_OVERLAY int fn_804A8004(void* x, int a)
{
    FeI(x, 0x204) = a;
    FeW* w = FeMem(x, 0x140);
    ((FeWQ*)w)->s14(a == (int)w);
    FeW* w2 = FeMem(x, 0x144);
    ((FeWQ*)w2)->s14(FeI(x, 0x204) == (int)w2);
    ((FeWR*)FeMem(x, 0x138))->s84(a == FeI(x, 0x140), 0);
    ((FeWQ*)x)->s69(a);
    fn_804A89D0(x);
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

struct FeVecI {
    int* d;
    unsigned n;
};
FE_OVERLAY void fn_804A86BC(void* x)
{
    unsigned i = 0;
    FeVecI* v = (FeVecI*)((char*)x + 0x14C);
    int id = fn_804A7FFC(x);
    if (i < v->n) {
        int o = 0;
        do {
            int e = *(int*)((char*)FeP(x, 0x14C) + o);
            o += 4;
            int c = fn_804A9048(id, e);
            ((FeW3*)FeMem(x, 0x140))->s90(i, 1, c);
            i++;
        } while (i < v->n);
    }
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

FE_OVERLAY void fn_804A8C1C(void* x)
{
    void* g = lbl_8061930C;
    int id = fn_804A7FFC(x);
    int w = fn_804A80DC(x);
    int v;
    if (w == FeI(x, 0x144))
        v = fn_8007F4D0__FP13Unk8007F198_Aii(g, id, ((FeWI*)w)->s60());
    else {
        int o = ((FeWI*)FeMem(x, 0x140))->s60() * 4;
        v = *(int*)((char*)FeP(x, 0x14C) + o);
    }
    fn_8007F438__FP13Unk8007F198_Aii(g, id, v);
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

FE_OVERLAY int fn_804A9048(int x, int v)
{
    void* g = lbl_8061930C;
    int n = fn_8007F488__FP13Unk8007F198_A(g, x);
    int i = 0;
    if (i < n) {
        do {
            if (fn_8007F4D0__FP13Unk8007F198_Aii(g, x, i) == v)
                return 1;
            i++;
        } while (i < n);
    }
    return 0;
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
