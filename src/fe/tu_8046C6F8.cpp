/*
 * Front-end overlay code, .frontend_codeoverlay 0x8046C6F8-0x8046F770 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80459228.h"
extern "C" {
int fn_8057CF60(void* s, int a);
void fn_80556348(void* p);
int fn_8057CE00(int a);
int fn_805559D4(void* buf, int n, int a);
int fn_805563C4(void* p);
int fn_80556410(void* p);
char* fn_80403DE4(char* dst, const char* fmt, ...);
void fn_80529028(int a, void* x);
}
extern "C" {
int strcmp(const char* a, const char* b);
char* strncpy(char* a, const char* b, unsigned n);
}


struct FeState608 {
    char pad0[0x608];
    int m608;
};
struct FeFlags4D4 {
    char pad0[0x4D4];
    int m4D4;
    int m4D8;
    int m4DC;
};
extern const char lbl_805F5A88[];
extern const char lbl_805F5AD0[];
extern const char lbl_805F5B10[];
extern const char lbl_805F5B20[];
extern const char lbl_805F5B30[];
extern const char lbl_805F5B3C[];
extern const char lbl_805F5B44[];
extern "C" {
int fn_8057CE00(int v);
int fn_8007F980__FP13Unk8007F198_Ci(void* g, int a);
int fn_800A2E6C(void* g);
}
extern const char lbl_805F5324[];
extern const char lbl_805F5AB0[];
extern "C" {
FeW* fn_800C8040(FeW* w);
void fn_80329FA0(void*, ...);
void fn_800DD44C__FP13Unk800DD610_PPvi(void*, void*, int);
}
extern const char lbl_805F5B88[];
extern const char lbl_805F5ADC[];
extern const char lbl_805F5258[];
extern "C" {
void* fn_8007F7D0__FP13Unk8007F198_BUi(void*, int);
void fn_8007B780__18Unk8007B2B0_Screen(void*, void*, int);
void fn_8055EAFC(void*);
int fn_800A1A6C(void* g);
}
typedef void (*FeCbF)(int, void*);
extern void* lbl_8061977C;
extern "C" {
const char* fn_80090880__FP11Unk80090880(void* t, int id);
void fn_800E4234__FiiPUs(int a, int b, char* out);
void fn_800DFF0C(char* a, const char* b);
void fn_801321D4(FeW* o, void* self, FeCbF cb, int a, void* b, int c, int d, int e, const char* s1, const char* s2,
                 const char* s3, int f, int g, int h);
int fn_800B5758(FeState* s);
int fn_80529020();
void fn_8046EC60(int a, FeScrJ* x);
void fn_8046E2A8(int a, FeScrJ* x);
}
extern const char lbl_805F522C[];
extern const char lbl_805F4F0C[];
extern const char lbl_805F5ABC[];
extern "C" {
void fn_8046F29C(void* u, int a);
}
extern "C" {
void fn_80562E34(int a);
int fn_800A3270(void* g, int* a, int* b);
int fn_800A3430(void* g);
void fn_8046E144(FeScrJ* x);
void fn_8046E354(int a, FeScrJ* x);
void fn_8046E39C(int a, FeScrJ* x);
}
extern "C" {
void fn_8046EFB8(int a, FeScrJ* x);
}
extern "C" {
int fn_800A2EB4(void* g);
int fn_800B56C4(FeState* s);
void fn_8049A6C4(FeScrL* x);
void fn_8046F0B0(FeScrJ* x);
void fn_8046F188(FeScrJ* x);
}
extern const char lbl_805F5B4C[];
extern const char lbl_805F5B58[];
extern const char lbl_805F5B98[];

extern "C" {

FE_OVERLAY void fn_8046D988(void)
{
    ((FeObj144*)fn_800B7A94(FeGetMgr(), lbl_805F5AA4))->m144 = 1;
}

FE_OVERLAY void fn_8046D9E8(FeScrJ* x)
{
    fn_80470710(x->m144, 0);
}

FE_OVERLAY void fn_8046DA10(FeScrJ* x)
{
    char sp8[0x40];
    int d1;
    int d2;
    FeW* a = fn_800C8040(x->m13C->fn_vslot32(lbl_805F5324, 1));
    FeW* b = fn_800C8040(x->m13C->fn_vslot32(lbl_805F5AB0, 1));
    fn_80329FA0(&d1, fn_800A2AE8(lbl_80619948));
    fn_80329FA0(&d2, fn_800C2248((char*)fn_800B555C() + 8));
    fn_800DD44C__FP13Unk800DD610_PPvi(&d1, sp8, 1);
    ((FeWV*)a)->s28(sp8);
    fn_800DD44C__FP13Unk800DD610_PPvi(&d2, sp8, 1);
    ((FeWV*)b)->s28(sp8);
}

FE_OVERLAY void fn_8046DB30(FeScrJ* x)
{
    fn_8046DA10(x);
}

FE_OVERLAY void fn_8046DB50(FeScrJ* x)
{
    fn_800ECAA4(x);
}

FE_OVERLAY int fn_8046DB70(FeScrJ* x)
{
    x->m138->fn_vslot52();
    return 1;
}

FE_OVERLAY int fn_8046DBAC(FeScrJ* x)
{
    x->m138->fn_vslot53();
    return 1;
}

FE_OVERLAY int fn_8046DBE8(FeScrJ* x)
{
    x->m138->fn_vslot50();
    return 1;
}

FE_OVERLAY int fn_8046DC24(FeScrJ* x)
{
    x->m138->fn_vslot51();
    return 1;
}

FE_OVERLAY int fn_8046DC60(FeScrJ* x)
{
    fn_8046EB7C(x);
    return 1;
}

FE_OVERLAY void fn_8046E048(FeScrJ* x, int a, int b)
{
    char buf[0x7D0];
    fn_800E4234__FiiPUs(a, b, buf);
    fn_800DFF0C(buf, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x44D1));
    x->m134 = a;
    ((FeWV*)x->m140)->s84(1);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4((FeW*)x->m140, x, (FeCbF)fn_8046E2A8, 0, buf, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046E144(FeScrJ* x)
{
    ((FeWV*)x->m140)->s84(0);
    fn_80131F34((FeW*)x->m140, x, (void (*)(int, void*))fn_8046E354, 0, 0x4D4E, 2, -1, 1, 0x3E8, 0x3E9, 0, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046E1F4(FeScrJ* x)
{
    ((FeWV*)x->m140)->s84(0);
    fn_80131F34((FeW*)x->m140, x, (void (*)(int, void*))fn_8046E39C, 0, 0x5CC8, 3, -1, 1, 0x3E8, 0x3E9, 0x4DA6, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046E2A8(int a, FeScrJ* x)
{
    FeGlobal80619948* g = lbl_80619948;
    if (a != 0) {
        if (a == 1) {
            fn_80562E34(x->m134);
            int sp8 = 0;
            int spC = 0;
            if (fn_800A3270(g, &sp8, &spC) == 0) {
                if (fn_800A3430(g) == 0) {
                    fn_8046E144(x);
                    return;
                }
                x->fn_vslot80(1);
                fn_8046D9E8(x);
            }
        }
    }
}

FE_OVERLAY void fn_8046E354(int a, FeScrJ* x)
{
    if (a == 0) {
        fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->m1E0 = a;
    }
    fn_8046D9E8(x);
}

FE_OVERLAY void fn_8046E39C(int a, FeScrJ* x)
{
    switch (a) {
    case 0: {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 0);
        x->fn_vslot80(1);
        break;
    }
    case 1: {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 0);
        break;
    }
    case 2: {
        void* s = lbl_8061930C;
        fn_8007B780__18Unk8007B2B0_Screen(s, fn_8007F7D0__FP13Unk8007F198_BUi(s, 0), 0);
        fn_8055EAFC(fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0));
        x->fn_vslot80(1);
        break;
    }
    }
    fn_8046D9E8(x);
}

FE_OVERLAY int fn_8046E4AC(FeScrJ* x, int v)
{
    fn_800B555C()->m570 = v;
    fn_8046DC84(x);
    return 1;
}

FE_OVERLAY void fn_8046E8F8(FeScrJ* x, char* dst)
{
    int r0 = strcmp(x->m150, "");
    int f = 1;
    if (r0 == 0)
        f = 0;
    if (f == 0) {
        fn_8046F3A8(x, (char*)x->m138->fn_vslot70()->fn_vslot33(5, 1) + 0xC);
        if (strcmp(x->m150, "SCOUTINGREPORT") == 0) {
            int r = fn_8057CE00(((FeState608*)fn_800B555C())->m608);
            if (r == 3) {
                fn_8046F3A8(x, "PLAYOFFAWARDS");
            } else if (r == -1 && fn_8007F980__FP13Unk8007F198_Ci(lbl_8061930C, 0) == 1) {
                fn_8046F3A8(x, "SEASONAWARDS");
            }
        }
        if (strcmp(x->m150, "TEAMGOALS") == 0) {
            if (fn_800A2E6C(lbl_80619948) != 0) {
                fn_8046F3A8(x, "MINIGAMES");
            } else if (fn_800B5758(fn_800B555C()) != 0) {
                fn_8046F3A8(x, "ORGINFO");
            }
        }
    }
    char* nm = x->m150;
    if (strcmp(nm, "SAVE") == 0) {
        if (fn_800B56C4(fn_800B555C()) != 0) {
            const char* s = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x610);
            FeFlags4D4* g = (FeFlags4D4*)((char*)fn_800B555C() + 8);
            g->m4D4 = 1;
            g->m4D8 = 0x01101311;
            g->m4DC = (int)s;
        } else {
            const char* s = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x61E);
            FeFlags4D4* g = (FeFlags4D4*)((char*)fn_800B555C() + 8);
            g->m4D4 = 1;
            g->m4D8 = 0x02131311;
            g->m4DC = (int)s;
        }
    }
    strncpy(dst, nm, 15);
    dst[15] = 0;
}

FE_OVERLAY int fn_8046EB00(FeScrJ* x, FeW* w, int c, int d, int e)
{
    if (w != x->m138) {
        return 0;
    }
    if ((FeW24(w->fn_vslot73(d, e)) & 0x40000000) != 0) {
        fn_8046DC84(x);
        return 1;
    }
    return 0;
}

FE_OVERLAY void fn_8046EB7C(FeScrJ* x)
{
    int id = 8;
    if (fn_800B56C4(fn_800B555C()) != 0) {
        id = 0x4FBA;
    } else if (fn_800B5758(fn_800B555C()) != 0) {
        id = 0x5740;
    }
    ((FeWV*)x->m140)->s84(1);
    fn_80131F34((FeW*)x->m140, x, (void (*)(int, void*))fn_8046EC60, (int)fn_80529020, id, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046EC60(int a, FeScrJ* x)
{
    if (lbl_8061A48C != 0) {
        a = 1;
    }
    if (a != 0) {
        if (a == 1) {
            fn_800A2030(lbl_80619948, 1);
            x->fn_vslot80(1);
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F5ABC, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, x);
        }
    }
}

FE_OVERLAY void fn_8046ED34(int a, FeScrJ* x)
{
    if (lbl_8061A48C != 0) {
        a = 1;
    }
    if (a != 0) {
        if (a == 1) {
            if (fn_800A2EB4(lbl_80619948) != 0) {
                fn_8046F0B0(x);
            } else {
                fn_8046F188(x);
            }
        }
    }
}

FE_OVERLAY void fn_8046EDA8(FeScrJ* x)
{
    ((FeWV*)x->m140)->s84(1);
    fn_80131F34((FeW*)x->m140, x, (void (*)(int, void*))fn_8046EFB8, 0, 0x3912, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046EE58(FeScrJ* x)
{
    ((FeWV*)x->m140)->s84(1);
    fn_80131F34((FeW*)x->m140, x, (void (*)(int, void*))fn_8046ED34, 0, 0x39D2, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046EF08(FeScrJ* x)
{
    ((FeWV*)x->m140)->s84(1);
    fn_80131F34((FeW*)x->m140, x, (void (*)(int, void*))fn_8046ED34, 0, 0x39C7, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    ((FeW*)x->m140)->fn_vslot86();
}

FE_OVERLAY void fn_8046EFB8(int a, FeScrJ* x)
{
    if (lbl_8061A48C != 0) {
        a = 1;
    }
    if (a != 0) {
        if (a == 1) {
            fn_8046F000(x);
        }
    }
}

FE_OVERLAY void fn_8046F000(FeScrJ* x)
{
    fn_8046F3A8(x, lbl_805F5240);
    fn_804705F0(x->m144, 0, 1, -1);
}

FE_OVERLAY void fn_8046F048(FeScrJ* x)
{
    fn_804704EC(x->m144, 0, 1, 2, -1);
}

FE_OVERLAY void fn_8046F07C(FeScrJ* x)
{
    fn_80470558(x->m144, 0, 1, 1, -1);
}

FE_OVERLAY void fn_8046F0B0(FeScrJ* x)
{
    if (fn_800B56C4(fn_800B555C()) != 0) {
        fn_8046F3A8(x, lbl_805F5B4C);
    } else {
        fn_8046F3A8(x, lbl_805F5B58);
    }
    x->fn_vslot80(1);
    fn_8049A6C4(x->m144);
}

FE_OVERLAY void fn_8046F130(FeScrJ* x)
{
    fn_8046F3A8(x, lbl_805F5B68);
    x->fn_vslot80(1);
    fn_8049A760(x->m144);
}

FE_OVERLAY void fn_8046F188(FeScrJ* x)
{
    fn_8046F3A8(x, lbl_805F5B78);
    x->fn_vslot80(1);
    fn_8049A7E4(x->m144);
}

FE_OVERLAY void fn_8046F1E0(FeScrJ* x)
{
    FePopup* p = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F522C);
    x->m144 = (FeScrL*)p;
    p->m30C = (void*)fn_8046F29C;
    FeW* w = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    x->m140 = (int)w;
    ((FeWV*)w)->s84(0);
}

FE_OVERLAY void fn_8046F29C(void* u, int a)
{
    FePopup* p = fn_800B7AB8(FeGetMgr(), lbl_805F5B88);
    if (a != 0) {
        if (fn_800B56C4(fn_800B555C()) != 0) {
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            ((FeWV*)p)->s79(mp);
            if (fn_8040B574(mp->name, lbl_805F5ADC) == 0 && fn_800A1A6C(lbl_80619948) != 0) {
                fn_8046F3A8((FeScrJ*)p, lbl_805F5258);
            }
        }
        fn_800B7ADC(FeGetMgr(), p);
    }
}

FE_OVERLAY void fn_8046F3A8(FeScrJ* x, const char* s)
{
    if (s != 0) {
        fn_8040B830(x->m150, s, 16);
    }
}

FE_OVERLAY void fn_8046F3D8(FeScrJ* x, int a)
{
    fn_800ED310(x, a);
    x->m138->fn_vslot14(a);
}

FE_OVERLAY void fn_8046F428(int a, int b)
{
    if (b == 0) {
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F5B98, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, (void*)a);
    }
}

FE_OVERLAY void fn_8046F4B0(void)
{
    fn_800E25E0(fn_800B7A94(FeGetMgr(), lbl_805F4F84), 0);
}

}

/* near-miss: 98.65%, same 152 insns and CTR/mfctr loop shape; only callee-saved register numbers differ (retail t=r25 h=r29 i=r24 off2=r31, ours t=r24 h=r31 i=r27 off2=r25). */
extern "C" FE_OVERLAY void fn_8046F510(FeScrJ* x)
{
    int sp20[4];
    int sp30[4];
    char sp40[0x1E0];
    char buf[0x320];
    int i;
    void* t = lbl_8061977C;
    void* h = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    for (i = 0; i <= 3; i++) {
        sp20[i] = 0;
        sp30[i] = fn_8057CF60(h, i);
    }
    char* p = sp40;
    int k = 11;
    do {
        fn_80556348(p);
        p += 0x28;
    } while (k-- != 0);
    for (i = 0; i <= 3; i++) {
        sp20[i] = 0x4635;
        fn_8057CE00(i);
        int n = fn_805559D4(sp40, 12, i);
        if (n > 0) {
            int off2 = 0;
            int c = n;
            do {
                char* e = sp40 + off2;
                if (fn_805563C4(e) == fn_80556410(e) && fn_80556410(e) == sp30[i]) {
                    sp20[i] = 0x5DC0;
                } else {
                    char* e2 = sp40 + off2;
                    if (fn_805563C4(e2) == sp30[i] || fn_80556410(e2) == sp30[i]) {
                        sp20[i] = 0x5DC1;
                    }
                }
                off2 += 0x28;
            } while (--c != 0);
        }
    }
    const char* s0 = fn_80090880__FP11Unk80090880(t, 0x38F0);
    const char* s1 = fn_80090880__FP11Unk80090880(t, sp20[0]);
    const char* s2 = fn_80090880__FP11Unk80090880(t, sp20[1]);
    const char* s3 = fn_80090880__FP11Unk80090880(t, sp20[2]);
    fn_80403DE4(buf, s0, s1, s2, s3, fn_80090880__FP11Unk80090880(t, sp20[3]));
    fn_801321D4((FeW*)x->m140, x, (FeCbF)fn_80529028, 0, buf, 1, -1, 1, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x26DE), 0, 0, 0, 1, 0);
    ((FeW*)x->m140)->fn_vslot86();
}
