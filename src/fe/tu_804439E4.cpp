/*
 * Front-end overlay code, .frontend_codeoverlay 0x804439E4-0x80446CE8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"


struct FeCell2 {
    char pad0[0x20];
    virtual void s1();
    virtual void s2(int a, int b);
};
extern const char lbl_805F4ED4[];
extern const char lbl_805F4EE0[];
extern const char lbl_805F4EE8[];
extern const char lbl_805F4EF4[];
extern const char lbl_805F4EFC[];
extern const char lbl_805F4F0C[];
extern const char lbl_805F4F14[];
extern "C" {
int fn_800C8034(void* p);
void fn_800C2034(void* p, int a);
}


extern int lbl_80621638;
extern "C" {
int fn_80446430(FeScr2* self, int i);
int fn_80446534(void);
}


struct FeDate3 {
    unsigned char a;
    unsigned char b;
    unsigned short c;
};
extern const char lbl_805F4F28[];
extern "C" int fn_8044643C(FeScr2* self, int a, int b);

extern "C" FE_OVERLAY void fn_80444090(void* self, int a)
{
    fn_80330BC8(self, a);
}

extern int lbl_80621630;
extern int lbl_80621634;
extern int lbl_80621638;
extern int lbl_8061A328;

extern "C" FE_OVERLAY int fn_80444714(void)
{
    return lbl_80621630;
}

extern "C" FE_OVERLAY void fn_80444720(void)
{
    lbl_80621634 = lbl_8061A328 + 0x3C;
}

extern "C" FE_OVERLAY void fn_80444738(int a)
{
    if (a != 0) {
        lbl_80621630 = 0;
        fn_80444720();
    } else {
        lbl_80621630 = -1;
    }
}

extern "C" FE_OVERLAY int fn_8044477C(void)
{
    if (lbl_80621630 != -1 && lbl_8061A328 >= lbl_80621634) {
        lbl_80621630 = (lbl_80621630 + 1) % 4;
        fn_80444720();
        return 1;
    }
    return 0;
}

extern char lbl_8067CEB0[];
extern char lbl_8067CBD0[];
/* near-miss: store order: 66 random/structured orderings tried, best 10 slots off */
extern "C" FE_OVERLAY void fn_80444850(FeTimerRaw* self);
/* near-miss: Clear() form gives the right shape but the two zero registers (r11 for the byte stores, r0 for the rest) are scheduled differently; 24 store orders tried */
extern "C" FE_OVERLAY FeTimerRaw* fn_804447F0(FeTimerRaw* self)
{
    self->m20 = lbl_8067CEB0;
    self->mC4.Clear();
    self->m4 = 0;
    self->m0 = 0;
    fn_80444850(self);
    return self;
}

extern int lbl_8062163C;
extern "C" FE_OVERLAY void fn_80444850(FeTimerRaw* self)
{
    self->m8 = 3;
    self->mC = 3;
    self->mD = 0;
    self->mE = 1000;
    lbl_8062163C = 0;
    self->m10 = -1;
    self->m14 = -1;
    self->m18 = -1;
    self->m1C = 0;
}

struct FeDate {
    unsigned short y;
    unsigned short m;
};
extern "C" FE_OVERLAY void fn_80444FE4(FeTimer* self)
{
    FeDate d;
    fn_80329FA0(&d, fn_800A2AE8(lbl_80619948));
    if (*(unsigned short*)&self->mC == d.y && *((unsigned short*)&self->mC + 1) == d.m)
        ((FeObj1*)self->m4)->v17(1);
    else
        ((FeObj1*)self->m4)->v17(0);
}

extern "C" FE_OVERLAY void fn_80445090(FeTimer* self)
{
    int t = self->m8;
    if ((unsigned)(t - 1) <= 1 || (t == 0 && self->m14 != -1) || t == 4)
        self->s12();
    fn_80444FE4(self);
}

extern "C" FE_OVERLAY FeScr2Raw* fn_80445104(FeScr2Raw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067CBD0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 3;
    self->m14C = 0;
    self->m150 = -1;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = -1;
    int one = 1;
    lbl_8061AC54 = one;
    return self;
}

extern "C" FE_OVERLAY void fn_80445190(FeScr2* x)
{
    fn_800ECE34(x);
    FeObj* p = fn_800B7AB8(UiGetMsgMgr(), lbl_805F4ED4);
    x->m134 = fn_800C805C(fn_800C8044(p->v32(lbl_805F4EE0, 1))->v32(lbl_805F4EE8, 1));
    x->m138 = fn_800C8060(fn_800C8044(p->v32(lbl_805F4ED4, 1))->v32(lbl_805F4EF4, 1));
    x->m13C = fn_800C8060(p->v32(lbl_805F4EFC, 1));
    x->m140 = (int)fn_800B7AB8(UiGetMsgMgr(), lbl_805F4F0C);
    if (fn_800A2E6C(lbl_80619948) != 0) {
        fn_800C2034((char*)fn_800B555C() + 8, 0);
    }
    int i = 0;
    do {
        int j = 0;
        do {
            FeCell2* cell = (FeCell2*)((FeObjP2*)x)->v90(i, j);
            cell->s2((int)((FeObjP2*)x->m138)->v73(i, j),
                     fn_800C8034(((FeObj*)((FeObjP2*)x->m13C)->v73(i, j))->v32(lbl_805F4F14, 1)));
            j++;
        } while (j <= 6);
        i++;
    } while (i <= 4);
    ((FeObj1*)x->m138)->v104(0);
    x->m14C = fn_800C203C((char*)fn_800B555C() + 8);
    x->m160 = fn_8057CE00(lbl_8061930C->fn_80078A38(x->m14C));
    int z = 0;
    lbl_80621638 = z;
}

extern "C" FE_OVERLAY void fn_80445454(void* self)
{
    fn_800ECF18(self);
    if (fn_800A2E6C(lbl_80619948) != 0)
        fn_804A763C(fn_800B7AB8(UiGetMsgMgr(), "FTOPBAR"), 1);
}

extern "C" FE_OVERLAY void fn_804454CC(void* s, int a)
{
    FeScr2* self = (FeScr2*)s;
    fn_800ED310(self, a);
    if (a != 0) {
        ((FeObj1*)self->m13C)->v14(1);
        ((FeObj1*)self->m134)->v14(0);
    } else {
        ((FeObj1*)self)->v14(0);
    }
}

extern "C" FE_OVERLAY void fn_80445564(FeScr2* self, int a, int b)
{
    self->m14C = b;
    ((FeObj1*)self)->v88(b);
    fn_80445DA8(self);
}

/* near-miss: retail loads the vptr before the m14C store and shares one zero register for the three locals (12 slots; 5 spellings tried) */
extern "C" FE_OVERLAY void fn_804459D0(FeScr2* self)
{
    self->m14C = fn_800C203C((char*)fn_800B555C() + 8);
    ((FeObj*)self)->v87();
    if ((fn_800B555C()->m4 & 1) != 0) {
        fn_80445B18(self);
    } else {
        int a = 0;
        int b = 0;
        int c = 0;
        fn_800C1FD8((char*)fn_800B555C() + 8, &a, &b, &c);
        self->m144 = a;
        int x = fn_80445D5C((int)self, b);
        int y = fn_80445D7C((int)self, b);
        ((FeObj2*)self->m138)->v67(x, y);
        ((FeObj2*)self->m13C)->v67(x, y);
        ((FeObj1*)self->m134)->v37(c);
        ((FeObj1*)self)->v88(self->m14C);
        fn_80445DA8(self);
    }
}

extern "C" FE_OVERLAY void fn_80445B18(FeScr2* self)
{
    ((FeObj1*)self)->v88(self->m14C);
    ((FeObj*)self)->v84();
}

extern "C" FE_OVERLAY void fn_80445B74(FeScr2* self)
{
    fn_80445BB4(self, fn_800A2AE8(lbl_80619948));
}

extern "C" FE_OVERLAY void fn_80445BB4(FeScr2* self, int a)
{
    FeDate3 d;
    fn_80329FA0(&d, a);
    int r = fn_8044643C(self, d.a - 1, d.b);
    FeWidgetS* month = (FeWidgetS*)fn_800C8058(self->m134->v32(lbl_805F4F28, 1));
    FeSub* s = &month->mDC;
    if (r < s->s13()) {
        ((FeObj1*)self->m134)->v37(r);
        self->m144 = d.a - 1;
        int t = fn_804464B0(self, d.a);
        int v;
        if (t > 0 && t <= d.b)
            v = d.b - t;
        else {
            int w = fn_8032A130(d.a - 1, 1, d.c) - 1;
            v = d.b + w;
        }
        ((FeObj2*)self->m138)->v67(fn_80445D5C((int)self, v), fn_80445D7C((int)self, v));
        ((FeObj2*)self->m13C)->v67(fn_80445D5C((int)self, v), fn_80445D7C((int)self, v));
        fn_80445DA8(self);
    }
}

extern "C" FE_OVERLAY int fn_80445D5C(int a, int idx)
{
    return idx / 7;
}

extern "C" FE_OVERLAY int fn_80445D7C(int a, int idx)
{
    return idx % 7;
}

extern "C" FE_OVERLAY void fn_80445DA8(FeScr2* self)
{
    int r = 0;
    int c;
    fn_80444738(0);
    do {
        c = 0;
        do {
            fn_80444850((FeTimerRaw*)((FeObjP2*)self)->v90(r, c));
            c++;
        } while (c <= 6);
        r++;
    } while (r <= 4);
    ((FeObj2*)self)->v90(0, 0);
    lbl_8062163C = self->m14C;
    int t = fn_804464B0(self, self->m144);
    if (t == 0) {
        fn_80445EF4(self, 0);
    } else {
        fn_80445EF4(self, fn_804461A0(self, self->m144 - 1, t, 0));
    }
    r = 0;
    do {
        c = 0;
        do {
            ((FeTimer*)((FeObjP2*)self)->v90(r, c))->s4();
            c++;
        } while (c <= 6);
        r++;
    } while (r <= 4);
    fn_804469DC(self, 1);
}

extern "C" FE_OVERLAY int fn_80446334(FeScr2* self, int* arr, int n, int target, int* out1, int* out2, int g)
{
    FeDate3 d;
    FeDate3 t;
    FeDate3* pd = &d;
    int i;
    int r;
    *out1 = -1;
    *out2 = -1;
    d.a = 0;
    Unk8007F198_C* gm = (Unk8007F198_C*)lbl_8061930C;
    pd->b = 0;
    pd->c = 0;
    for (i = 0; i < n; i++) {
        fn_80329FA0(&t, fn_8007FBC0(gm, arr[i], g));
        d = t;
        if (target == pd->b) {
            if (*out1 != -1) {
                *out2 = arr[i];
                fn_80444738(1);
                break;
            }
            *out1 = arr[i];
        }
    }
    r = 0;
    if (*out1 != -1)
        r = 1;
    return r;
}

extern "C" FE_OVERLAY int fn_80446430(FeScr2* self, int i)
{
    return self->m148 + i;
}

/* near-miss: retail forms a - (m148 - 1) after the call; ours folds it to (a + 1) - m148 and reuses a + 1 (5 slots) */
extern "C" FE_OVERLAY int fn_8044643C(FeScr2* self, int a, int b)
{
    int r = 0;
    if (a >= self->m148) {
        int t = fn_804464B0(self, a + 1);
        if (t != 0 && b >= t)
            return a - (self->m148 - 1);
        r = a - self->m148;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_804464B0(FeScr2* self, int a)
{
    int n = a - 1;
    int x = fn_8032A130(n, 1, self->m152);
    if (fn_8032A2CC(n, self->m152) == 0x1E && x > 5)
        return 0x24 - x;
    if (fn_8032A2CC(n, self->m152) == 0x1F && x > 4)
        return 0x24 - x;
    return 0;
}

extern "C" FE_OVERLAY int fn_80446534(void)
{
    if ((fn_8044477C() != 0 && lbl_80621638 == 0) || lbl_80621638 == 1)
        return 1;
    return 0;
}

extern "C" FE_OVERLAY void fn_80446588(FeScr2* self)
{
    if (self->m24 & 0x40000000) {
        int r = 0;
        FeWidgetS* month = (FeWidgetS*)fn_800C8058(self->m134->v32(lbl_805F4F28, 1));
        FeSub* ms = (FeSub*)&month->mDC;
        int a = ms->s5();
        int g = lbl_8061930C->fn_80078A38(self->m14C);
        int b = fn_80446430(self, a);
        int c = fn_8057CE00(g);
        if (b != self->m144) {
            self->m144 = b;
            r = 1;
        }
        if (r != 0) {
            fn_80445DA8(self);
        } else if (((int (*)(FeScr2*))fn_80446534)(self) != 0) {
            lbl_80621638 = r;
            if (c == -1) {
                if (fn_8007FB2C((Unk8007F198_C*)lbl_8061930C, g) > self->m154) {
                    fn_800B555C()->m4 = 1;
                    ((FeObj*)self)->v87();
                    ((FeObj*)self)->v84();
                } else {
                    int i = 0;
                    do {
                        int j = 0;
                        do {
                            fn_80445090((FeTimer*)((FeObjP2*)self)->v90(i, j));
                            j++;
                        } while (j <= 6);
                        i++;
                    } while (i <= 4);
                    ((FeObj*)self)->v85();
                }
            } else if (self->m160 < 0) {
                self->m160 = r;
                fn_800B555C()->m4 = 1;
                ((FeObj*)self)->v78();
            } else {
                fn_800B555C()->m4 = r;
                FeDate3 d;
                int k = fn_8007FB2C((Unk8007F198_C*)lbl_8061930C, g) - 1;
                fn_80329FA0(&d, fn_8007FBC0((Unk8007F198_C*)lbl_8061930C, k, g));
                FeWidgetS* m2 = (FeWidgetS*)fn_800C8058(self->m134->v32(lbl_805F4F28, 1));
                FeSub* ms2 = (FeSub*)&m2->mDC;
                int q = ms2->s13();
                if (d.a - 1 > fn_80446430(self, q - 1))
                    ((FeObj*)self)->v87();
                fn_80445DA8(self);
            }
        }
        fn_804469DC(self, 0);
    }
}

/* near-miss: retail evaluates self->m144 before the MONTH lookup call (4 slots) */
extern "C" FE_OVERLAY void fn_80446820(FeScr2* self)
{
    int a = ((FeObjI*)self->m138)->v60();
    int idx = a * 7 + ((FeObjI*)self->m138)->v61();
    char* st = (char*)fn_800B555C() + 8;
    FeWidgetS* month = (FeWidgetS*)fn_800C8058(self->m134->v32("MONTH", 1));
    int d = self->m144;
    FeSub* s = (FeSub*)&month->mDC;
    fn_800C1FC8(st, d, idx, s->s5());
}

extern "C" FE_OVERLAY int fn_804468F8(FeScr2* self, FeRec1C* rec)
{
    if (rec->m1C == 1 && fn_8040B574(rec->mC, "SELECTED") == 0) {
        ((FeObj2*)self)->v67(-1, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80446974(FeScr2* self)
{
    self->m158 = ((FeObjI*)self->m13C)->v60();
    self->m15C = ((FeObjI*)self->m13C)->v61();
}

/* near-miss: retail does not CSE m158/m15C with the vcall results x/y in the equal branch (1 slot) */
extern "C" FE_OVERLAY void fn_804469DC(FeScr2* self, int a)
{
    int x = ((FeObjI*)self->m13C)->v60();
    int y = ((FeObjI*)self->m13C)->v61();
    if (self->m158 == x && self->m15C == y) {
        if (a == 0)
            return;
        ((FeTimer*)((FeObjP2*)self)->v90(self->m158, self->m15C))->s4();
    }
    ((FeTimer*)((FeObjP2*)self)->v90(x, y))->s3();
}

extern "C" FE_OVERLAY FeTimer* fn_80446AD4(void* s)
{
    FeScr2* self = (FeScr2*)s;
    return (FeTimer*)((FeObjP2*)self)->v90(((FeObjI*)self->m138)->v60(), ((FeObjI*)self->m138)->v61());
}

extern "C" FE_OVERLAY void fn_80446B60(FeScr2* self, int k)
{
    switch (k) {
    case -2: {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    case -1: {
        void* o = ((FeObjP2*)self)->v90(((FeObjI*)self->m13C)->v60(), ((FeObjI*)self->m13C)->v61());
        ((FeObj2*)self->m138)->v67(((FeObjI*)self->m13C)->v60(), ((FeObjI*)self->m13C)->v61());
        ((FeObj1*)self)->v86((int)o);
        break;
    }
    }
}
