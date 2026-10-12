/*
 * Front-end overlay code, .frontend_codeoverlay 0x80492680-0x804987EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern "C" {

FE_OVERLAY void fn_804933A0(void* x)
{
    fn_804930F8(x);
    fn_80492FB4(x);
}

FE_OVERLAY void fn_804933D4(void* x, int a)
{
    /* near-miss (3 slots): retail sets r4, r5 and then r3 (addi r3,r1,8) for the name call. */
    char n[200];
    char fmt[0x68];
    char out[400];
    fn_804031BC(fmt, lbl_805F6B18);
    fn_800DE440(n, a, 1);
    fn_80403DE4(out, fmt, n);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_8049364C(void* x, int a)
{
    /* near-miss (3 slots): retail sets r4, r5 and then r3 (addi r3,r1,8) for the name call. */
    char n[200];
    char fmt[0x68];
    char out[400];
    fn_804031BC(fmt, lbl_805F6B74);
    fn_800DE440(n, a, 1);
    fn_80403DE4(out, fmt, n);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_80496560(void* x)
{
    int k = FeI(x, 0x184);
    if ((k == 0 && FeI(x, 0x140) == 0) || (k == 1 && FeI(x, 0x140) != 0)) {
        fn_8001BC4C()->fn_8001C190(0, FeI(x, 0x180), 0);
    } else {
        fn_8001BC4C()->fn_8001C190(2, FeI(x, 0x180), 0);
    }
}

FE_OVERLAY void fn_8049693C(char* x)
{
    if (FeI(x, 0x188) != FeI(x, 0x184)) {
        char* b = x + 0x1A8;
        int o = FeI(x, 0x188) * 4;
        int id = *(int*)(b + o);
        if (fn_80096988((void*)id, (int)fn_80081B60(FeP(x, 0x1A4)), 0) == 1) {
            fn_804982C0(x);
        }
    }
}

FE_OVERLAY int fn_804977FC(char* x)
{
    int i;
    for (i = 0; i < 8; i++) {
        char* b = x + 0x38C;
        int o = i * 0x44;
        if (*(int*)(b + o) != 0) {
            return 0;
        }
    }
    return 1;
}

FE_OVERLAY void fn_80497B74(char* x, int idx)
{
    int o = idx * 0x44;
    FeSt(x + 0x388, o, -1);
    FeSt(x + 0x38C, o, 0);
    FeSt(x + 0x390, o, 0);
    FeSt(x + 0x394, o, 0);
    FeSt(x + 0x398, o, 1);
    FeSt(x + 0x3A4, o, -1);
    FeSt(x + 0x3A8, o, -1);
    FeSt(x + 0x39C, o, -1);
    FeSt(x + 0x3A0, o, -1);
    FeSt(x + 0x3B0, o, -1);
    FeSt(x + 0x3AC, o, -1);
    FeSt(x + 0x3B4, o, 0);
    char* bf = x + 0x3B8;
    *(float*)(bf + o) = lbl_805F7110;
    FeSt(x + 0x3BC, o, 0);
    FeSt(x + 0x3C8, o, -1);
}

FE_OVERLAY void fn_80497C08(void* x, int a)
{
    switch (a) {
    case -1:
        break;
    case 0:
        fn_80495248(x);
        break;
    case 1:
        fn_8049535C(x);
        break;
    }
}

FE_OVERLAY void fn_80497C48(void* x)
{
    FeMsg m;
    FeMsg* p = &m;
    fn_80498438((char*)x);
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805F7114, 15);
    p->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), p, x);
}

FE_OVERLAY void fn_804983A8(void) {}

FE_OVERLAY void fn_804983AC(void* x)
{
    FeI(x, 0x32C) = FeI(fn_800B555C(), 0x634);
    FeI(fn_800B555C(), 0x634) = 0;
    short* p = (short*)FeP(x, 0x32C);
    if (p == 0) {
        short* a = (short*)fn_803774A8(0x4E22, FeI(FeGetMgr(), 0x38) | 0x100);
        *a = 0;
        FeP(x, 0x32C) = a;
    }
}

FE_OVERLAY void fn_80498438(char* x)
{
    if (*(void**)(x + 0x32C) != 0) {
        fn_80377488(*(void**)(x + 0x32C));
        *(int*)(x + 0x32C) = 0;
    }
}

FE_OVERLAY void fn_80498580(void) {}

FE_OVERLAY void fn_80498584(void)
{
    char buf[0xA0];
}

FE_OVERLAY void fn_80498590(int a, void* x)
{
    if (a == 1) {
        FeMsg m;
        FeMsg* p = &m;
        fn_80498438((char*)x);
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805F5ABC, 15);
        p->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), p, 0);
    }
}

FE_OVERLAY void fn_804987C0(void* a, void* b)
{
    fn_804920B8(b, 1);
}

FE_OVERLAY void fn_804987E8(void) {}

}
