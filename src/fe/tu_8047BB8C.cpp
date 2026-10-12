/*
 * Front-end overlay code, .frontend_codeoverlay 0x8047BB8C-0x8047D454 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

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
