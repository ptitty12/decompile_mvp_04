/*
 * Front-end overlay code, .frontend_codeoverlay 0x804EA2E4-0x804ECDE0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

/* Q16-DECL-BEGIN */
extern "C" void fn_800B8268(FeB8144* b, float a, float c, float d, float e);
struct FeP4SlotX {
    int a;
    unsigned char b;
    int c;
};
struct FeP4RecX {
    int m0;
    int m4;
    unsigned m8;
    int mC;
    FeP4SlotX s[0x68];
    int m4F0;
};
struct FeP4TabX {
    int m0;
    FeP4RecX e[4];
};
/* Q16-DECL-END */

extern char lbl_80667378[];
extern char lbl_80667390[];

extern char lbl_8066B4E0[];

extern "C" FE_OVERLAY FeScrRaw* fn_804EA2E4(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B4E0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804EA33C(FeS12* self)
{
    fn_800ECF18(self);
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(p, self);
    fn_80125100(p);
    self->m138 = fn_800C8060(self->v32("STATS", 1));
    self->m13C = fn_800C805C(self->m138->v32("SG1", 1));
    fn_804EA6D0(self);
}

extern "C" FE_OVERLAY int fn_804EA410(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA498(FeW138* self)
{
    self->m138->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA4D4(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA510(FeW138* self)
{
    self->m138->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA54C(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA588(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA5C4(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA600(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA63C(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA678(FeS12* self, FeObj2* a, int b, int c, int d)
{
    if ((FeObj*)a == self->m138) {
        a->v67(c, d);
        return 1;
    } else
        return 0;
}

extern "C" FE_OVERLAY void fn_804EAD3C(void* self, int* out)
{
    for (int i = 4; i > 0; i--)
        out[i - 1] = i;
}

extern "C" FE_OVERLAY void fn_804EADC4(FeP4Tab* t, int idx, int v)
{
    FeSetAt((char*)t + 8, idx * 0x4F4, v);
}

extern "C" FE_OVERLAY void fn_804EAEE0(FeP4Tab* t)
{
    for (int i = 0; i < 4; i++) {
        t->e[i].m0 = 0;
        t->e[i].m8 = 0;
        t->e[i].m4F0 = 0;
    }
    t->m0 = 0;
}

extern "C" FE_OVERLAY void fn_804EAF18(FeP4Tab* t)
{
    for (int i = 0; i < 4; i++) {
        if (t->e[i].m4F0 * (t->e[i].m4 + 1) == 0)
            t->e[i].m0 = 0;
    }
}

extern "C" FE_OVERLAY int fn_804EAF54(FeP4Tab* t)
{
    int n = 0;
    for (int i = 0; i < 4; i++) {
        if (t->e[i].m0 != 0)
            n++;
    }
    return n;
}

extern "C" FE_OVERLAY int fn_804EAF88(FeP4Tab* t)
{
    for (int i = 0; i < 4; i++) {
        if (t->e[i].m0 != 0)
            return i;
    }
    return -1;
}

extern "C" FE_OVERLAY FeRaw1D8* fn_804EAFC0(FeRaw1D8* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80135180(self, a, b, c, d, e, f, g, h, 1);
    self->m17C = lbl_80667378;
    self->m3C = lbl_80667390;
    self->m1D8 = 1;
    self->m1DC = 0;
    self->m1E0 = 0;
    self->m1E4 = 0;
    self->m1E8 = 0;
    self->m1EC = 0;
    self->m1F0 = 0;
    self->m1FC = 0;
    self->m200 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804EB040(FeRaw1D8* self, int chrg)
{
    self->m17C = lbl_80667378;
    self->m3C = lbl_80667390;
    fn_80135200(self, chrg);
}

extern "C" FE_OVERLAY void fn_804EB078(FeS13* self)
{
    ((FeMsgMgrB*)UiGetMsgMgr())->mC0 = 0;
    self->m1E4 = 0;
    ((FeObj1*)self->v32("LOADING", 1))->v8(0);
    self->m1DC = lbl_8061A328;
    if (self->m1E4 != 0) {
        self->m1D8 = 8;
    } else {
        self->m1D8 = self->m1E4;
        fn_804EB2C8(self);
    }
    ((FeObj1*)self->v32("LEGAL", 1))->v8(0);
}

extern "C" FE_OVERLAY int fn_804EB184(FeS13* self)
{
    switch (self->m1D8) {
    case 6:
    case 7:
        fn_800B8144()->m1C = 0;
        fn_800B82D0(fn_800B8144(), -1, 1);
        self->m1E0 = 1;
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        fn_804EB2C8(self);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804EB1FC(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_804EB204(FeObj1* self)
{
    self->v45(-1);
}

/* near-miss: retail keeps a in r3 and stores a fresh li r0,1; ours CSEs the constant with a (r31). switch / constant-in-local spellings tried (26 vs 25 insns) */
extern "C" FE_OVERLAY void fn_804EB23C(int a, FeS13* self)
{
    if (a == 0)
        fn_80313634(lbl_8061FEDC);
    else if (a == 1) {
        fn_803136A0(lbl_8061FEDC);
        self->m200 = 1;
        self->m1FC = 1;
    }
    fn_804EB2C8(self);
}

extern "C" FE_OVERLAY void fn_804EB2A4(int a, void* b)
{
    fn_804EB2C8(b);
}

extern "C" FE_OVERLAY void fn_804EB834(void)
{
    ((FeS13*)fn_800B7A94(UiGetMsgMgr(), "TITLE"))->m1E0 = 1;
}

extern char lbl_80681448[];
extern "C" FE_OVERLAY FeRaw14* fn_804EB894(FeRaw14* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80681448;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m134 = (int)fn_800B5E68(fn_803773D8(0xB98), lbl_806221E4);
    return self;
}

extern "C" FE_OVERLAY void fn_804EB940(FeRawD* self, int chrg)
{
    self->m3C = lbl_80681448;
    if (self->m134 != 0) {
        delete self->m134;
        self->m134 = 0;
    }
    self->m134 = 0;
    fn_800E2BCC();
    fn_8035686C(self, chrg);
}

extern "C" FE_OVERLAY void fn_804EBC74(FeScrRaw* s, int v)
{
    s->m15C = v;
}

extern "C" FE_OVERLAY void fn_804EBC7C(FeS14* self)
{
    int n = self->m158 + 1;
    if (n >= self->m134->mB90) {
        self->m158 = 0;
        self->m15C = 0;
    } else {
        self->m158 = n;
        self->m15C = 0;
    }
}

extern "C" FE_OVERLAY void fn_804EBCB4(FeS16* self)
{
    ((FeObj1*)self->m140)->v8(0);
    ((FeObj1*)self->m144)->v8(0);
    FeD64* o = fn_80528400(self, self->m158);
    if (o->s2() != 0)
        fn_804EBD68(self, o);
    else
        fn_804EC68C(self, o);
}

extern "C" FE_OVERLAY void fn_804EC68C(FeS16* self, FeD64* o)
{
    if (o->s4() != 0 || o->s3() != 0)
        fn_804EBF7C(self, o);
    else if (o->s5() != 0)
        fn_804EC294(self, o);
}

extern "C" FE_OVERLAY int fn_804EC980(FeS15* s, int v)
{
    if (s->m160 + 1 <= 0x18) {
        s->m1E0[s->m160] = v;
        int r = s->m17C[s->m160];
        s->m160++;
        return r;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804EC9C4(FeS15* s)
{
    FeObj1* top = (FeObj1*)s->m17C[0];
    top->v10(0x1A4);
    s->m17C[0] = 0;
    for (int i = 0; i < 24; i++) {
        s->m1E0[i] = s->m1E0[i + 1];
        s->m17C[i] = s->m17C[i + 1];
    }
    s->m1E0[24] = 0;
    s->m17C[24] = (int)top;
    s->m160--;
}

extern "C" FE_OVERLAY int fn_804ECC0C(FeObj* self)
{
    fn_800B8144()->m1C = 0;
    fn_800B82D0(fn_800B8144(), -1, 1);
    fn_800B82AC(fn_800B8144());
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804ECC8C(FeS15* self)
{
    if (self->m178 != 0) {
        fn_804EBCB4((FeS16*)self);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        self->m164 = lbl_8061A328 + 0xB4;
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804ECCE4(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_804ECCEC(FeS15* self)
{
    if (self->m178 != 0) {
        int t;
        if (self->m16C != 0) {
            fn_80125180((FeObj*)((FeS12*)self)->m13C, 3, 0x39F9);
            t = 0;
        } else {
            fn_80125180((FeObj*)((FeS12*)self)->m13C, 3, 0x389E);
            t = 1;
        }
        self->m16C = t;
        fn_8001BC4C()->fn_8001BDAC(0xA3);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_804ECD6C()
{
    fn_800B82D0(fn_800B8144(), -1, 1);
    fn_800B8144()->m1C = (FeVf)fn_804ECD6C;
    fn_800B82D0(fn_800B8144(), 8, 0);
    fn_800B8268(fn_800B8144(), 260.0f, 115.0f, 340.0f, 215.0f);
}
