/*
 * Front-end overlay code, .frontend_codeoverlay 0x8047BB8C-0x8047D454 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"

extern "C" FE_OVERLAY void fn_8047BF48(FeScrD* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
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

extern "C" FE_OVERLAY void fn_8047C958(char* buf, int v)
{
    if (v >= 0)
        fn_804089B4(buf, "+%d", v);
    else
        fn_804089B4(buf, "%d", v);
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
