/*
 * Front-end overlay code, .frontend_codeoverlay 0x804DE730-0x804E02E0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"

extern "C" int fn_8007DBB0__FP13Unk8007DB74_A(void* a);
extern "C" int fn_8007DADC__18Unk8007B2B0_ScreenUi(void* g, unsigned i);
struct Unk800D876C_A;
void fn_800DA544(Unk800D876C_A* t, int a);
extern "C" int fn_800D8938(void* t);
extern int lbl_8061B8B8;
extern "C" void fn_804DF634(FeS804DE5F8* x);
extern int lbl_80621580;


extern "C" void fn_800C3A4C(void* t);
extern "C" void fn_800C5080(void* t);
extern "C" void fn_800C5B58(void* t);
extern "C" void fn_800C435C(void* t, int a, int id, int c, float f);
extern int lbl_8061A5AC[];
extern float lbl_805F989C;
extern "C" char* strcat(char* dst, const char* src);
extern "C" void fn_802B0638(void* g, char* s, int a);
extern void* lbl_8061E978;
extern "C" void fn_800C3ED4(void* t, FeW* w, int v);
extern "C" int fn_804DEA48();
extern "C" void fn_804DFA08(int a, FeW* x);
extern "C" char* strcpy(char*, const char*);
extern "C" int fn_800D87C4__FP13Unk800D876C_A(void* p);
extern "C" void fn_80086278(void* t, void* v);
struct FeLinkM {
    char pad0[0x120];
    int m120;
};
extern "C" int fn_8052977C();
struct FeMgr134 {
    char pad0[0x134];
    FeW* m134;
};
extern "C" int strcmp(const char* a, const char* b);

extern "C" void fn_80535650(FeTmp18* t, int v);

extern "C" {

FE_OVERLAY void fn_804DE730(FeS804DE5F8* x)
{
    fn_800ECF18(x);
    if (((FeStateB*)fn_800B555C())->m0 == 0x32) {
        x->m14C = (int)fn_800ED2B0(x, "ENTERSPECIAL");
        if (x->m14C != 0) {
            x->fn_vslot16(0);
            fn_800CFB38((void*)x->m14C);
        }
    } else {
        fn_800CFB38(fn_800ED2B0(x, "ENTERREGULAR"));
    }
    fn_800D878C__FP13Unk800D876C_A((char*)x + 0x138);
    x->m134 = (int)fn_800B7AB8(FeGetMgr(), "POPUP");
    FeW* nav = (FeW*)fn_800B7A94(FeGetMgr(), "NAVBAR");
    fn_80124FA8(nav, x);
    x->fn_vslot32("GCMENU", 1)->fn_vslot16(1);
    x->fn_vslot32("GCMENU", 1)->fn_vslot8(1);
    fn_801250D8(nav);
    fn_800E25E0__Fii(nav, 0);
    char buf[0x80] = "title.";
    strcat(buf, "gsh");
    fn_802B0638(lbl_8061E978, buf, 1);
    strcpy(buf, "license.");
    strcat(buf, "gsh");
    fn_802B0638(lbl_8061E978, buf, 1);
    if (lbl_8061ABD8 != 0)
        x->fn_vslot32("ODMTEST", 1)->fn_vslot8(1);
}

FE_OVERLAY void fn_804DE9B8(void)
{
    if (lbl_8061ABD8 != 0) {
        fn_800C33D0();
        fn_800C3BE0();
    }
}

FE_OVERLAY unsigned fn_804DE9EC(unsigned n)
{
    return (unsigned)fn_804027DC() % n;
}

FE_OVERLAY unsigned fn_804DEA24(void)
{
    return fn_804DE9EC(0x57);
}

FE_OVERLAY int fn_804DEA48(void)
{
    int v = fn_800B548C(fn_804DE9EC(0x79));
    FeTmp18 t;
    int buf[0x28];
    FeTmp18* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A4C8);
    fn_8040074C(q->m0, q->m8 << 2);
    q->m4 = 0;
    q->mC = 0;
    q->m14 = 0;
    fn_80535650(q, v);
    int r = q->At(fn_804DE9EC(q->Count()));
    t.D();
    return r;
}

FE_OVERLAY void fn_804DEB28(FeW* x)
{
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE1", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE2", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE3", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE4", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    if ((int)fn_804DE9EC(0x64) <= 9) {
        fn_800C3A4C(fn_800C33D0());
        int n = 200;
        unsigned k;
        do {
            k = fn_804DEA24();
            fn_800C435C(fn_800C33D0(), 0, lbl_8061A5AC[k], 1, lbl_805F989C);
            k = fn_804DEA24();
            fn_800C435C(fn_800C33D0(), 0, lbl_8061A5AC[k], 1, lbl_805F989C);
            fn_800C5080(fn_800C33D0());
        } while (--n != 0);
        fn_800C5B58(fn_800C33D0());
        fn_800C3A4C(fn_800C33D0());
    }
    if ((int)fn_804DE9EC(0x3E8) <= 0x1F3)
        fn_800B7ADC(FeGetMgr(), x);
}

FE_OVERLAY void fn_804DED40(FeS804DE5F8* x)
{
    fn_800ECAA4(x);
    if ((FeW24(x) & 0x40000000) == 0) {
        int* t = (int*)x->m14C;
        if (t != 0 && *t == 0) {
            if (fn_800ED2B0(x, "ENTERSPECIAL2") != 0) {
                fn_800CFB38(fn_800ED2B0(x, "ENTERSPECIAL2"));
            }
            if ((FeW24((void*)x->m134) & 0x40000000) == 0
                && (fn_8007DBB0__FP13Unk8007DB74_A(lbl_8061930C) == 0
                    || fn_8007DADC__18Unk8007B2B0_ScreenUi(lbl_8061930C, 0) != 0)
                && x->m158 == 0) {
                if (lbl_80621580 != 0)
                    fn_804DF634(x);
                x->m158 = 1;
            }
            if ((FeW24((void*)x->m134) & 0x40000000) == 0) {
                x->fn_vslot16(1);
                fn_800D878C__FP13Unk800D876C_A((char*)x + 0x138);
            }
        }
    }
    if ((FeW24(x) & 0x40000000) != 0) {
        if (fn_800D8938((char*)x + 0x138) != 0) {
            fn_800DA544((Unk800D876C_A*)((char*)FeGetMgr() + 0x24), 0);
            fn_800B7ADC(FeGetMgr(), x);
            lbl_8061B8B8 += 1;
        }
    }
    if (lbl_8061ABD8 != 0)
        fn_804DEB28(x);
}

FE_OVERLAY void fn_804DEEF4(FeS804DE5F8* x)
{
    int z = 0;
    fn_802D7EE4(fn_800C8070(x));
    if (x->m150 != 0 || (fn_802D7EE4(fn_800C8070(x)), x->m154 != 0)) {
        fn_800D878C__FP13Unk800D876C_A(x->m138);
        fn_802D7EE4(fn_800C8070(x));
        x->m150 = z;
        fn_802D7EE4(fn_800C8070(x));
        x->m154 = z;
    }
}

FE_OVERLAY int fn_804DEF74(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    return 1;
}

FE_OVERLAY int fn_804DEF9C(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DF010(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DF084(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DF0F8(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_804DF16C(FeS804DE5F8* x, int a)
{
    ((FeState*)fn_800B555C())->m570 = a;
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY int fn_804DF1D4(void) { return 1; }

FE_OVERLAY void fn_804DF1DC(void) {}

FE_OVERLAY int fn_804DF1E0(FeMgr134* x, FeW* w)
{
    fn_800D878C__FP13Unk800D876C_A((char*)x + 0x138);
    if (w == fn_800C8060(((FeW*)x)->fn_vslot32("CELL", 1))) {
        if (strcmp((char*)w->fn_vslot70()->fn_vslot33(5, 1) + 0xC, "QUIT") == 0) {
            fn_80131F34(x->m134, x, (void (*)(int, void*))fn_804DF1DC, (int)fn_8052977C, 0x3B77, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            x->m134->fn_vslot86();
            return 0;
        }
        fn_800B7ADC(FeGetMgr(), x);
        return 1;
    }
    return 0;
}

FE_OVERLAY void fn_804DF33C(FeW* x, char* out)
{
    if (lbl_8061ABD8 != 0) {
        strcpy(out, "GAMEMODES");
        return;
    }
    if (fn_800D87C4__FP13Unk800D876C_A((char*)x + 0x138) != 0) {
        *out = lbl_805F36A0.c0;
    } else {
        fn_8040B830(out, (char*)fn_800C8060(x->fn_vslot32("CELL", 1))->fn_vslot70()->fn_vslot33(5, 1) + 0xC, 16);
    }
    FeLinkM* l = (FeLinkM*)lbl_806192E0->m4->m10;
    if (l->m120 == 0)
        fn_80086278(l, fn_8007FE04((Unk8007F198_D*)lbl_8061930C));
}

FE_OVERLAY void fn_804DF460(FeS804DE5F8* x, int a)
{
    fn_800ED310(x, a);
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot14(a);
}

/* near-miss: registers/branch layout only (switch and if-else forms tried) */
FE_OVERLAY void fn_804DF4D4(FeS804DE5F8* x, signed char a)
{
    FeMsg m;
    FeMsg* mp = &m;
    switch (a) {
    case 0:
        fn_800D878C__FP13Unk800D876C_A(x->m138);
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F5B98, 15);
        mp->name[15] = a;
        fn_800B7B4C(FeGetMgr(), mp, x);
        return;
    case 1:
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F98D4, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        return;
    }
}

FE_OVERLAY void fn_804DF5CC(FeS804DE5F8* x)
{
    fn_800D878C__FP13Unk800D876C_A(x->m138);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_800E25E0__Fii(p, 0);
}

FE_OVERLAY void fn_804DF634(FeS804DE5F8* x)
{
    fn_80131F34((FeW*)x->m134, x, fn_804DF6E4, 0, 0x56C3, 2, 0x1C2, 1, 0x3E8, 0x3E9, 0, 0, 0, 0);
    ((FeWY*)x->m134)->s84(1);
    ((FeW*)x->m134)->fn_vslot86();
}

FE_OVERLAY void fn_804DF6E4(int a, void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    if (a != 1) {
        fn_8040B830(mp->name, lbl_805F98E0, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
}

FE_OVERLAY void fn_804DF774(FeS804DE5F8* x)
{
    if (lbl_8061ABD8 != 0) {
        fn_800C3AB4(fn_800C33D0(), 9);
        x->fn_vslot32(lbl_805F9874, 1)->fn_vslot8(1);
    }
    fn_800ECF18(x);
    void* p = fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
}

FE_OVERLAY int fn_804DF850(FeScrK* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_800B7B4C(FeGetMgr(), mp, x);
    return 1;
}

FE_OVERLAY int fn_804DF8BC(FeW* x, int a)
{
    fn_800B555C()->m570 = a;
    FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), "POPUP");
    if (fn_800C8060(x->fn_vslot29("GCPC/TEXT/MENU"))->fn_vslot60() == 5) {
        fn_80131F34(p, x, (void (*)(int, void*))fn_804DFA08, 0, 0x4F6A, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        p->fn_vslot86();
        return 0;
    }
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY void fn_804DFA08(int a, FeW* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F8034, 15);
    mp->name[15] = 0;
    if (a != 0) {
        if (a == 1) {
            x->fn_vslot80(1);
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

FE_OVERLAY int fn_804DFABC(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DFB1C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DFB7C(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DFBDC(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_804DFC3C(FeS804DE5F8* x, char* out)
{
    if (lbl_8061ABD8 != 0) {
        fn_8040B830(out, lbl_805F4450, 16);
        return;
    }
    FeW* w = fn_800C8060(x->fn_vslot32(lbl_805F7B70, 1))->fn_vslot70();
    fn_8040B830(out, (char*)w->fn_vslot33(1, 1) + 0xC, 16);
    if (fn_8040B574(out, lbl_805F98FC) == 0) {
        fn_8040B830(out, lbl_805F9908, 16);
    }
}

FE_OVERLAY int fn_804DFD2C(FeW* x)
{
    if (strcmp((char*)fn_800C8060(x->fn_vslot32("MENU", 1))->fn_vslot70()->fn_vslot33(1, 1) + 0xC, "MANAGER") == 0) {
        FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), "POPUP");
        fn_80131F34(p, x, (void (*)(int, void*))fn_804DFA08, 0, 0x4F6A, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
        p->fn_vslot86();
        return 0;
    }
    fn_800B7ADC(FeGetMgr(), x);
    return 1;
}

FE_OVERLAY void fn_804DFE9C(FeW* x)
{
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE1", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE2", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE3", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    {
        FeW* a = fn_800C8038(x->fn_vslot32("FACE4", 1));
        void* b = fn_800C33D0();
        fn_800C3ED4(b, a, fn_804DEA48());
    }
    if ((int)fn_804DE9EC(0x3E8) <= 0x1F3)
        fn_800B7ADC(FeGetMgr(), x);
}

FE_OVERLAY void fn_804E0024(FeW* x)
{
    fn_800ECAA4(x);
    if (lbl_8061ABD8 != 0) {
        fn_804DFE9C(x);
    }
}

FE_OVERLAY void fn_804E0068(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

FE_OVERLAY FeS804E008C* fn_804E008C(FeS804E008C* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066DD00);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

FE_OVERLAY void fn_804E00DC(FeS804E008C* x)
{
    fn_800ECF18(x);
    x->m134 = 0;
    void* p = fn_800B7AB8(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8(p, x);
    fn_80125100(p);
    fn_801250D8(p);
}

FE_OVERLAY int fn_804E0160(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804E01C0(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804E0220(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804E0280(FeW* x)
{
    fn_800C8060(x->fn_vslot32(lbl_805F4EF4, 1))->fn_vslot53();
    return 1;
}

}
