/*
 * Front-end overlay code, .frontend_codeoverlay 0x8047BB8C-0x8047D454 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
extern "C" void fn_8047C35C(FeScrArr2* self);
struct FeWV87 : Unk800C7B40_Data {
    virtual ~FeWV87();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(int a, int b, void* c); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126(); virtual void s127();
};
extern "C" void fn_8047D24C(void* p, void* a, int b);

/* near-miss: 2 slots differ (order of the final m4/mC stores after the vptr store) */
extern "C" FE_OVERLAY FeScrArr2* fn_8047BB8C(FeScrArr2* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_8049A1F0(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80677078);
    self->m398 = -1;
    self->m370 = 0;
    self->m374 = 0;
    self->m378 = 0;
    self->m37C = 0;
    self->m380 = 0;
    self->m384 = 0;
    self->m388 = 0;
    self->m38C = 0;
    self->m390 = 0;
    self->m394 = 0;
    self->m39C = 0;
    FeArr* s = &self->mD78;
    s->m10 = lbl_8064B298;
    s->m0 = self->mD90;
    s->m8 = 0xFA;
    fn_8040074C(s->m0, 0x3E8);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->m10 = lbl_8065C1B0;
    s->mC = 0;
    s->m4 = 0;
    s->m14 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8047BC70(void* p)
{
    FeScrArr2* x = (FeScrArr2*)p;
    fn_800ECE34(x);
    x->fn_vslot32("PROGRESSION", 0);
    x->m38C = (int)fn_800C8060();
    x->fn_vslot32("PLAYERINFO", 0);
    x->m37C = (int)fn_800C8044();
    ((FeW*)x->m37C)->fn_vslot32("NAME", 1);
    x->m380 = (int)fn_800C8040();
    ((FeW*)x->m37C)->fn_vslot32("FACE", 0);
    x->m384 = (int)fn_800C8038();
    ((FeW*)x->m37C)->fn_vslot32("STATS", 1);
    x->m388 = (int)fn_800C8060();
    ((FeW*)x->m37C)->fn_vslot32("TEAMLOGO", 1);
    x->m390 = (int)fn_800C8054();
    ((FeW*)x->m384)->fn_vslot8(0);
    fn_800C3AB4(fn_800C33D0(), 9);
}

//// a
extern "C" FE_OVERLAY void fn_8047BDDC(void* p)
{
    FeScrArr2* x = (FeScrArr2*)p;
    fn_800ECF18(x);
    void* g = lbl_8061930C;
    FePopup* a = (FePopup*)fn_800B7A94(FeGetMgr(), lbl_805F522C);
    x->m374 = (int)a;
    a->m30C = (void*)fn_8047D150;
    x->m378 = (int)fn_800B7A94(FeGetMgr(), lbl_805F4F84);
    fn_80124FA8((void*)x->m378, x);
    fn_801250D8((void*)x->m378);
    fn_801251CC((void*)x->m378, 2, 0x201A, 2);
    fn_801251CC((void*)x->m378, 3, 0x1A2F, 0);
    FePopup* q = fn_800B7AB8(FeGetMgr(), lbl_805F4F8C);
    x->m370 = (int)q;
    fn_80126CF4((FeList*)q, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0);
    x->m394 = (int)fn_8007F7D0__FP13Unk8007F198_BUi(g, 0);
    fn_8047C35C(x);
}

extern "C" FE_OVERLAY void fn_8047BF48(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_8047BF70(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    fn_8035682C(p);
    fn_8040B830(p->name, "ADVANCE", 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
    return 1;
}

extern "C" FE_OVERLAY void fn_8047C004(void* x, int sel)
{
    switch (sel) {
    case 0:
        fn_8047CDC0(x);
        break;
    case 1:
        fn_8047CF5C(x);
        break;
    case 2:
        fn_8047D02C(x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_8047C058(void* x)
{
    FeW* w = FeWp(x, 0x38C);
    int f = w->b1;
    w->fn_vslot16(1);
    FeWp(x, 0x38C)->fn_vslot50();
    FeWp(x, 0x38C)->fn_vslot16(f);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C0E8(void* x)
{
    FeAt(x, 0x38C)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C124(void* x)
{
    FeW* w = FeWp(x, 0x38C);
    int f = w->b1;
    w->fn_vslot16(1);
    FeWp(x, 0x38C)->fn_vslot52();
    FeWp(x, 0x38C)->fn_vslot16(f);
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C1B4(void* x)
{
    FeAt(x, 0x38C)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C1F0(void* x)
{
    FeAt(x, 0x38C)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C22C(void* x)
{
    FeAt(x, 0x38C)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C268(void* x)
{
    FeAt(x, 0x38C)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C2A4(void* x)
{
    FeAt(x, 0x38C)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8047C2E0(void* x, FeW* w, int b, int c, int d)
{
    int r;
    if (w != FeWp(x, 0x38C)) {
        r = 0;
    } else {
        w->fn_vslot67(c, d);
        fn_8047C9A0(x, FePick((char*)FeVp(x, 0xD78), c * 4));
        r = 1;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_8047C35C(FeScrArr2* self)
{
    FeArr* s = &self->mD78;
    void* g = lbl_8061930C;
    fn_8040074C(s->m0, s->m8 * 4);
    s->Reset();
    s->m14 = 0;
    fn_80535360((void**)s, self->m394);
    unsigned n = s->m4;
    unsigned i;
    for (i = 0; i < n; i++) {
        int e = FePick(self->mD78.m0, i * 4);
        float f = ((float (*)(int, int))fn_8007824C)(e, 0);
        int* p = (int*)((char*)self + 0x3A0) + i * 5;
        *p = e;
        fn_8047D1AC(p, f);
        fn_8047D24C(p, g, e);
    }
    self->fn_vslot80(1);
    fn_8049A988(self->m374);
}

extern "C" FE_OVERLAY int fn_8047C444(char* x, int key)
{
    int i;
    int* p = (int*)(x + 0x3A0);
    for (i = 0; i < 0x7E; i++) {
        if (*p == key)
            return i;
        p = (int*)((char*)p + 0x14);
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_8047C900(void* x)
{
    if (FeW24(FeWp(x, 0x370)) < 0)
        fn_801251CC(FeVp(x, 0x378), 3, 0x37A2, 1);
    else
        fn_801251CC(FeVp(x, 0x378), 3, 0x1A2F, 0);
}

extern "C" FE_OVERLAY void fn_8047C958(char* buf, int v)
{
    if (v >= 0)
        fn_804089B4(buf, "+%d", v);
    else
        fn_804089B4(buf, "%d", v);
}

extern "C" FE_OVERLAY void fn_8047CDC0(void* x)
{
    int v = FePick((char*)FeVp(x, 0xD78), FeWp(x, 0x38C)->fn_vslot60() * 4);
    char* s = (char*)FeVp(x, 0x370);
    fn_80126CF4((FeList*)s, FeI(s, 0x164), v, FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
    FeWp(x, 0x370)->fn_vslot8(1);
    fn_8047C900(x);
    FeWp(x, 0x38C)->fn_vslot16(0);
}

extern "C" FE_OVERLAY void fn_8047CE94(void* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x38C)) {
        int v = FePick((char*)FeVp(x, 0xD78), w->fn_vslot60() * 4);
        if (FeWp(x, 0x370)->fn_vslot87() != 0) {
            char* s = (char*)FeVp(x, 0x370);
            fn_80126CF4((FeList*)s, FeI(s, 0x164), v, FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
        }
        fn_8047C9A0(x, v);
    }
}

extern "C" FE_OVERLAY void fn_8047CF5C(void* x)
{
    char* s = (char*)FeVp(x, 0x370);
    fn_80126CF4((FeList*)s, FeI(s, 0x164), 0, FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
    FeWp(x, 0x370)->fn_vslot8(0);
    fn_8047C900(x);
    FeWp(x, 0x38C)->fn_vslot16(1);
    FeWp(x, 0x38C)->fn_vslot14(1);
}

extern "C" FE_OVERLAY void fn_8047D02C(void* p)
{
    FeScrArr2* x = (FeScrArr2*)p;
    int r = FeWp(x, 0x38C)->fn_vslot61();
    if (r != x->m398) {
        x->m398 = r;
        x->m39C = 0;
    }
    if (r == 0) {
        ((FeWV87*)FeWp(x, 0x38C))->s87(1, x->m39C ^ 1, &x->mD78);
    }
    ((FeWV87*)FeWp(x, 0x38C))->s87(r, x->m39C, &x->mD78);
    x->m39C = x->m39C ^ 1;
    fn_8047C9A0(x, FePick((char*)FeVp(x, 0xD78), FeWp(x, 0x38C)->fn_vslot60() * 4));
    if (FeWp(x, 0x370)->fn_vslot87() != 0) {
        fn_8047CDC0(x);
    }
}

extern "C" FE_OVERLAY void fn_8047D150()
{
    fn_8047C47C(fn_800B7A94(FeGetMgr(), lbl_805F619C));
}

extern "C" FE_OVERLAY void fn_8047D1AC(void* x, float v)
{
    FeS(x, 4) = (short)(v * 1000.0f);
}

extern "C" FE_OVERLAY float fn_8047D1DC(void* x)
{
    return (float)FeS(x, 4) * 0.001f;
}

extern "C" FE_OVERLAY void fn_8047D21C(char* x, int i, char v)
{
    char* b = x + 6;
    b[i] = v;
}

extern "C" FE_OVERLAY unsigned char fn_8047D228(char* x, int i)
{
    unsigned char* b = (unsigned char*)x + 6;
    return b[i];
}

extern "C" FE_OVERLAY void fn_8047D234(char* x, int i, char v)
{
    char* b = x + 12;
    b[i] = v;
}

extern "C" FE_OVERLAY unsigned char fn_8047D240(char* x, int i)
{
    unsigned char* b = (unsigned char*)x + 12;
    return b[i];
}

extern "C" FE_OVERLAY void fn_8047D24C(void* p, void* g, int id)
{
    if (fn_8007A270__18Unk8007A4DC_Screeni(g, id) != 0) {
        int i = 0;
        do {
            fn_8047D21C((char*)p, i, ((char (*)(float))fn_800E01C8__Ff)(((float (*)(int, int))fn_800DEE38)(i, id)));
            char t = fn_800DEDC0__Fii(i, id);
            int k = i;
            i++;
            fn_8047D234((char*)p, k, t);
        } while (i <= 4);
        fn_8047D21C((char*)p, 5, fn_8007AB9C__18Unk8007A4DC_Screenii((int)g, 0, id));
    } else {
        fn_8047D21C((char*)p, 0, fn_8007AA84__18Unk8007A4DC_Screeniii((int)g, 1, id, 0));
        fn_8047D21C((char*)p, 1, fn_8007AA84__18Unk8007A4DC_Screeniii((int)g, 0, id, 0));
        fn_8047D21C((char*)p, 2, ((char (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(g, 0xD, id));
        fn_8047D21C((char*)p, 3, fn_8007AA84__18Unk8007A4DC_Screeniii((int)g, 1, id, 1));
        fn_8047D21C((char*)p, 4, fn_8007AA84__18Unk8007A4DC_Screeniii((int)g, 0, id, 1));
        fn_8047D21C((char*)p, 5, ((char (*)(void*, int, int))fn_8007A6A0__18Unk8007A4DC_Screenii)(g, 0xD, id));
    }
}

extern "C" FE_OVERLAY FeScrH* fn_8047D3D0(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80678010);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    FeI(self, 0x13C) = 0;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 0;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = -1;
    FeI(self, 0x154) = -1;
    FeI(self, 0x220) = 0;
    FeI(self, 0x224) = 0;
    FeI(self, 0x228) = 0;
    FeI(self, 0x22C) = 0;
    return self;
}
