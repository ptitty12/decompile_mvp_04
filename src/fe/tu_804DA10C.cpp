/*
 * Front-end overlay code, .frontend_codeoverlay 0x804DA10C-0x804DC128 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804D08D0.h"

extern "C" {

FE_OVERLAY void fn_804DA10C(FeS804DA10C* x)
{
    fn_800ECE34(x);
    FeW* p;
    if (x->m13C != 0) {
        p = fn_800C8044(x->m140->fn_vslot32(lbl_805F9720, 1));
        x->m160 = lbl_806192E0->m4->m14;
    } else {
        p = fn_800C8044(x->m140->fn_vslot32(lbl_805F972C, 1));
        x->m160 = (FeTeamRec*)((char*)lbl_806192E0->m4->m14 + 0xE64);
    }
    void* g = lbl_8061977C;
    const char* city = fn_80090880__FP11Unk80090880(g, fn_800E18D4__Fi(x->m144));
    fn_800C8040(p->fn_vslot32(lbl_805F9738, 1))->fn_vslot28(city);
    x->m15C = fn_800C8044(p->fn_vslot32(lbl_805F5828, 1));
    x->m158 = fn_800C8060(p->fn_vslot32(lbl_805F9740, 1));
    x->m154 = fn_800C8038(x->m15C->fn_vslot32(lbl_805F55DC, 1));
    x->m154->fn_vslot8(0);
}

FE_OVERLAY void fn_804DA2DC(FeScrD* x)
{
    fn_800ED254(x);
}

FE_OVERLAY int fn_804DA2FC(FeS804DA10C* x)
{
    x->m158->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_804DA338(FeS804DA10C* x)
{
    x->m158->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DA374(FeS804DA10C* x)
{
    x->m158->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_804DA3B0(FeS804DA10C* x)
{
    x->m158->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_804DA3EC(FeS804DA10C* x)
{
    fn_804DA74C(x);
    int id = fn_80097210(x->m160, 0);
    for (int i = 0; i < x->m158->fn_vslot59(); i++) {
        if (x->m168[i] == id) {
            x->m158->fn_vslot68(i);
            return;
        }
    }
}

/* near-miss: ~19 slots; retail computes idx*0xE64 twice and keeps the team-record pointer in r30 (tried 6 forms) */
FE_OVERLAY void fn_804DA494(FeS804DA10C* x)
{
    int id = x->m168[x->m158->fn_vslot60()];
    if (fn_80097210(x->m160, 0) != id) {
        fn_80096830(x->m160, id);
        FeG2* g = lbl_806192E0->m4;
        int a = g->m14->m198;
        int r = fn_8007A6A0__18Unk8007A4DC_Screenii(lbl_8061930C, 9, id);
        FeTeamRec* base = g->m14;
        int idx = (a ^ x->m160->m198) == 0;
        int s = base[idx].m164;
        if (s == 0 || s == 2) {
            s = 0;
            if (r != 0) {
                s = 2;
            }
        } else {
            s = 3;
            if (r == 0) {
                s = 1;
            }
        }
        fn_8009C54C(&base[idx], s);
    }
}

FE_OVERLAY void fn_804DA590(FeS804DA10C* x)
{
    x->m14C = 1;
}

FE_OVERLAY void fn_804DA59C(FeS804DA10C* x)
{
    x->m14C = 0;
}

FE_OVERLAY int fn_804DA5A8(FeS804DA10C* x)
{
    x->m158->fn_vslot52();
    return x->m168[x->m158->fn_vslot60()];
}

FE_OVERLAY int fn_804DA614(FeS804DA10C* x)
{
    x->m158->fn_vslot50();
    return x->m168[x->m158->fn_vslot60()];
}

FE_OVERLAY int fn_804DA680(FeS804DA10C* x)
{
    return x->m168[x->m158->fn_vslot60()];
}

FE_OVERLAY int fn_804DA6D0(FeS804DA10C* x)
{
    return x->m164;
}

FE_OVERLAY void fn_804DA6D8(FeS804DA10C* x)
{
    int idx = x->m158->fn_vslot60();
    lbl_8061B2B8 = x->m13C == 0;
    fn_800E1388(x->m15C, x->m168[idx], 1, 0);
}

FE_OVERLAY int fn_804DAAF0(FeS804DA10C* x)
{
    int r = fn_80097148(x->m160);
    if (r == 1 || r == 3) {
        return 0;
    }
    return 1;
}

FE_OVERLAY void fn_804DAB30(FeS804DA10C* x, int a)
{
    if (a == (int)x->m158) {
        fn_804DA6D8(x);
    }
}

FE_OVERLAY int fn_804DAB5C(void) { return 0; }

FE_OVERLAY void fn_804DAB64(FeS804DA10C* x, int a)
{
    int idx = x->m158->fn_vslot60();
    int f = 0;
    if (a != 0) {
        x->m158->fn_vslot16(1);
    } else {
        f = 1;
        x->m158->fn_vslot16(0);
    }
    int i = 0;
    do {
        FeW* w = x->m158->fn_vslot73(idx, i);
        i++;
        w->fn_vslot16(1);
        ((FeWX*)w)->s17(f);
    } while (i <= 2);
}

FE_OVERLAY void fn_804DAFE0(FeS804DA10C* x)
{
    if (x->m168[6] > 8 && x->m158->fn_vslot60() > 8) {
        fn_80125084(x->m188, 2);
        fn_80125084(x->m188, 0);
    }
}

FE_OVERLAY int fn_804DB050(FeS804DB050* x)
{
    if (x->m158->fn_vslot60() == 0 && FeW24(x->m168) < 0) {
        fn_8001BC4C()->fn_8001BDAC(0x99);
        x->m168->fn_vslot14(1);
        x->m158->fn_vslot14(0);
    } else if (fn_804DBC40(x) == 0) {
        x->m158->fn_vslot50();
    }
    return 1;
}

FE_OVERLAY int fn_804DB12C(FeS804DB050* x)
{
    x->m158->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_804DB168(FeS804DB050* x)
{
    if (x->m148 == 0) {
        if (FeW24(x->m168) & 0x10000000) {
            fn_8001BC4C()->fn_8001BDAC(0x9A);
            x->m168->fn_vslot14(0);
            x->m158->fn_vslot14(1);
        } else if (fn_804DBC40(x) == 0) {
            x->m158->fn_vslot52();
        }
    }
    return 1;
}

FE_OVERLAY int fn_804DB22C(FeS804DB050* x)
{
    x->m158->fn_vslot53();
    return 1;
}

FE_OVERLAY void fn_804DB268(FeS804DB050* x)
{
    fn_804DB4E0(x, 1);
    if (FeW24(x->m168) < 0) {
        x->m168->fn_vslot14(1);
    } else {
        x->m168->fn_vslot14(0);
    }
    x->m158->fn_vslot14(0);
}

FE_OVERLAY void fn_804DB304(FeS804DB050* x)
{
    x->m14C = 1;
}

FE_OVERLAY void fn_804DB310(FeS804DB050* x)
{
    x->m14C = 0;
}

FE_OVERLAY void fn_804DB31C(FeS804DB050* x)
{
    x->m158->fn_vslot52();
    x->fn_vslot93();
}

FE_OVERLAY void fn_804DB378(FeS804DB050* x)
{
    x->m158->fn_vslot50();
    x->fn_vslot93();
}

FE_OVERLAY int fn_804DB3D4(FeS804DB050* x)
{
    int n = x->m158->fn_vslot60();
    int id;
    if (n > 8) {
        id = x->m18C[n - 1];
    } else {
        id = x->m18C[n];
    }
    return id;
}

FE_OVERLAY int fn_804DB43C(FeS804DB050* x)
{
    return x->m184;
}

FE_OVERLAY void fn_804DB444(FeS804DB050* x)
{
    int n = x->m158->fn_vslot60();
    int id;
    if (n > 8) {
        id = x->m18C[n - 1];
    } else {
        id = x->m18C[n];
    }
    int f = 1;
    if (x->m178 == 1) {
        f = 0;
    }
    lbl_8061B2B8 = x->m13C == 0;
    fn_800E0C38(x->m15C, id, f, 1);
}

FE_OVERLAY int fn_804DB9A4(FeS804DB050* x)
{
    int r = fn_80097148(x->m170);
    if (r == 1 || r == 3) {
        return 0;
    }
    return 1;
}

FE_OVERLAY void fn_804DB9E4(FeS804DB050* x, int a)
{
    if (a == (int)x->m158) {
        fn_804DB444(x);
    }
}

FE_OVERLAY int fn_804DBA10(void) { return 0; }

FE_OVERLAY int fn_804DBA18(void) { return 0; }

FE_OVERLAY void fn_804DBA20(FeS804DB050* x, int a)
{
    if (a != 0) {
        x->m168->fn_vslot16(1);
        x->m158->fn_vslot16(1);
        fn_804DB4E0(x, 0);
        int f = FeW24(x->m168);
        if ((f & 0x10000000) && f < 0) {
            x->m158->fn_vslot14(0);
        } else {
            x->m158->fn_vslot14(1);
        }
        return;
    }
    x->m168->fn_vslot16(0);
    x->m158->fn_vslot16(0);
}

FE_OVERLAY int fn_804DBB24(void) { return 0; }

FE_OVERLAY void fn_804DBB2C(FeS804DB050* x, int a)
{
    ((FeWX*)fn_800C8040(x->m16C->fn_vslot32(lbl_805F9770, 1)))->s29(a);
    x->m16C->fn_vslot8(1);
    x->fn_vslot16(0);
}

FE_OVERLAY void fn_804DBBDC(FeS804DB050* x)
{
    x->fn_vslot16(1);
    x->m16C->fn_vslot8(0);
}

FE_OVERLAY int fn_804DBC40(FeS804DB050* x)
{
    int r = 1;
    FeW* w = x->m16C;
    if (w->b0 == 0) {
        r = 0;
    }
    return r;
}

}
