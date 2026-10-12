/*
 * Front-end overlay code, .frontend_codeoverlay 0x80492680-0x804987EC (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_8048E6A0.h"

extern const char lbl_805F6BC4[];
extern const char lbl_805F4ECC[];
extern const char lbl_805F7060[];
extern "C" int sprintf(char*, const char*, ...);
extern "C" int fn_80097210(void* team, int a);
extern "C" void fn_80529150(void);
extern const char lbl_805F6AAC[];
extern const char lbl_805F6AB0[];
extern const char lbl_805F6AB4[];
extern const char lbl_805F6B2C[];
extern const char lbl_805F6B48[];
extern const char lbl_805F6B60[];
extern const char lbl_805F6B84[];
extern const char lbl_805F6BA4[];
extern const char lbl_805F7090[];
struct Fe4F94A {
    int m0;
    unsigned char m4;
    int m8;
};
struct Fe4F94B {
    int a;
    int b;
};
struct Fe4F94 {
    char pad0[0x338];
    Fe4F94A e[4];
    char pad368[0x368 - 0x338 - 48];
    Fe4F94B p[4];
};
extern "C" void fn_80496EE4(void* x, int a, int b, int c, int d, void* w, int e, int f, int g);
extern "C" {

FE_OVERLAY void fn_804933A0(void* x)
{
    fn_804930F8(x);
    fn_80492FB4(x);
}

FE_OVERLAY void fn_804933D4(void* x, int a)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    fn_804031BC(fmt, lbl_805F6B18);
    fn_800DE440(n, a, 1);
    fn_80403DE4(out, fmt, n);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_80493448(void* x, int a, int u, int b)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    char suf[24];
    switch (b % 10) {
    case 1:
        fn_804031BC(suf, lbl_805F6AAC);
        break;
    case 2:
        fn_804031BC(suf, lbl_805F6AB0);
        break;
    case 3:
        fn_804031BC(suf, lbl_805F6AB4);
        break;
    }
    fn_804031BC(fmt, lbl_805F6B2C);
    fn_800DE440(n, a, 1);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, n, b, suf);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_80493544(void* x, int a, int b)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    char suf[24];
    fn_800DE440(n, a, 1);
    switch (b % 10) {
    case 2: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB0);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B48);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 3: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB4);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B48);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 4: {
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B60);
        fn_80403DE4(out, fp, n);
        break;
    }
    }
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_8049364C(void* x, int a)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    fn_804031BC(fmt, lbl_805F6B74);
    fn_800DE440(n, a, 1);
    fn_80403DE4(out, fmt, n);
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_804936C0(void* x, int a, int b)
{
    char n[200];
    char fmt[0x68];
    char out[400];
    char suf[24];
    fn_800DE440(n, a, 1);
    switch (b % 10) {
    case 2: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB0);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B84);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 3: {
        char* sp = suf;
        fn_804031BC(sp, lbl_805F6AB4);
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6B84);
        fn_80403DE4(out, fp, n, b, sp);
        break;
    }
    case 4: {
        char* fp = fmt;
        fn_804031BC(fp, lbl_805F6BA4);
        fn_80403DE4(out, fp, n);
        break;
    }
    }
    fn_80492BA8(x, out);
}

FE_OVERLAY void fn_804937C8(void* x, int a, int b)
{
    char n1[0x40];
    char n2[0x40];
    char fmt[0x80];
    char out[0x100];
    fn_800DE440(n1, a, 1);
    fn_800DE440(n2, b, 1);
    fn_804031BC(fmt, lbl_805F6BC4);
    ((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, n2, n1);
    fn_80492BA8(x, out);
}

//// a
FE_OVERLAY void fn_80494F94(Fe4F94* x)
{
    for (int i = 0; i < 4; i++) {
        if (x->e[i].m0 != 0) {
            char buf[0x68];
            sprintf(buf, lbl_805F7090, i);
            FeW* w = fn_800C8044(FeMem(x, 0x1EC)->fn_vslot32(buf, 1));
            fn_80496EE4(x, x->p[i].a, x->p[i].b, x->p[i].a, x->p[i].b, w, 1, 1, -1);
        }
        x->e[i].m0 = 0;
        x->e[i].m4 = 0xFF;
        x->e[i].m8 = 0;
    }
}

FE_OVERLAY void fn_8049535C(void* x)
{
    char buf[8];
    char* p = buf;
    sprintf(p, lbl_805F4ECC, *(unsigned char*)((char*)FeP(x, 0x1A4) + 0x1CC9));
    ((FeWQ*)fn_800C8040(FeMem(x, 0x1F0)->fn_vslot32(lbl_805F7060, 1)))->s30((int)p);
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
        if (fn_80096988((void*)id, (int)fn_80081B60__FP13Unk8007FF8C_Y(FeP(x, 0x1A4)), 0) == 1) {
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

FE_OVERLAY void fn_804982C0(void* x)
{
    FeW* p = (FeW*)fn_800B7A94(FeGetMgr(), lbl_805F4F0C);
    char* st = (char*)fn_800B555C() + 8;
    FeI(st, 0x620) = fn_80097210((void*)((FeScrB*)x)->m1A8[FeI(x, 0x184)], 0);
    fn_80131F34(p, x, (void (*)(int, void*))fn_804987C0, (int)fn_80529150, 0x37A1, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    p->fn_vslot86();
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
