/*
 * Front-end overlay code, .frontend_codeoverlay 0x804BFB3C-0x804C19EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern "C" void fn_804C1100(void* x);
extern "C" void fn_804C13F8(FeScrN* x);
extern const char lbl_806703A0[];
extern const char lbl_8067CEB0[];
extern int lbl_80621964;
extern int lbl_8062196C;
extern int lbl_80621640;
extern "C" void fn_80377408(void* p);
extern "C" int fn_8056A5B0(int a, int b, int c, int d);
extern "C" void fn_804BFD98(FeObjP* x);
extern "C" void* fn_804C0620(char* p, int i, int j);
extern "C" void fn_804C0BD8(FeScrN* x);
extern "C" void fn_804C10D4(int a, void* x);
extern "C" void fn_804C1484(FeScrN* x);
extern "C" int fn_804C1640(FeScrN* x);
extern "C" int fn_804C1778(FeScrN* x);
extern "C" int fn_804C19AC(FeScrN* x);
extern "C" void fn_804C0298(FeVt20* x);
extern "C" void fn_804BFB3C(FeD20* self, int c);
extern "C" char* fn_804C05E0(char* p, int i);
extern "C" int fn_804BFDE8(FeObj10* x);

extern "C" FE_OVERLAY void fn_804BFB3C(FeD20* self, int c)
{
    self->m20 = lbl_806703A0;
    lbl_80621964 = 0;
    lbl_80621968 = 0;
    lbl_8062196C = 0;
    self->m20 = lbl_8067CEB0;
    lbl_80621640 = 0;
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" FE_OVERLAY void fn_804BFD98(FeObjP* x)
{
    x->m24->fn_vslot8(0);
    fn_80444890(x);
}

extern "C" FE_OVERLAY int fn_804BFDE8(FeObj10* x)
{
    if (x->m10 != -1
        && fn_8056A5B0(((Fe19948X*)lbl_80619948)->m28, ((FeStateX*)fn_800B555C())->m608, x->m10, lbl_8062163C) == 0) {
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804C0298(FeVt20* x)
{
    fn_800E5404(lbl_80621968, x->s13(), lbl_8062163C);
}

extern "C" FE_OVERLAY char* fn_804C05E0(char* p, int i)
{
    return p + ((i / 7) * 0x118 + 0x168) + (i % 7) * 0x28;
}

extern "C" FE_OVERLAY void* fn_804C0620(char* p, int i, int j)
{
    return p + (i * 0x118 + 0x168) + j * 0x28;
}

extern "C" FE_OVERLAY void fn_804C0BD8(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804C10D4(int a, void* x)
{
    if (a == 1) {
        fn_804C1100(x);
    }
}

extern "C" FE_OVERLAY void fn_804C1484(FeScrN* x)
{
    fn_804C13F8(x);
}

extern "C" FE_OVERLAY int fn_804C1640(FeScrN* x)
{
    x->m14C->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C1778(FeScrN* x)
{
    x->m14C->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C19AC(FeScrN* x)
{
    x->m144->fn_vslot40(1);
    return 1;
}
