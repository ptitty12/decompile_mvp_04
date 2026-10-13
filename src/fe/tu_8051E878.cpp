/*
 * Front-end overlay code, .frontend_codeoverlay 0x8051E878-0x80520BE0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_80516990.h"
extern "C" void fn_80087A58__FP13Unk80087A58_Oicii(void* o, int a, int c, int d, int e);
extern "C" void fn_80086D24__FP13Unk80084910_Wii(void* w, int i);
extern "C" int fn_80087A88__FP13Unk80087A58_Oiii(void* o, unsigned a, int w, int flag);
extern "C" int fn_80086D34__FP13Unk80084910_Wi(void* w, int i);
extern "C" int fn_8007DBB0__FP13Unk8007DB74_A(void* g);
extern "C" void fn_8051F584(FeV10B* x, int a);
extern "C" void fn_80086D44__FPcif(char* base, int idx, float f);
extern "C" FeSingle* fn_805210A0(void);
extern "C" int fn_80522890(FeSingle* x, unsigned i);
extern "C" void fn_8051FBD0(FeV10* x, int a);
extern "C" void fn_8051F32C(int a, int b, float c);
extern "C" int fn_8007CF44__18Unk8007B2B0_ScreenUiii(void* g, unsigned i, char* a, int b);
extern const float lbl_805FBB38;
extern const float lbl_805FBB3C;
extern const float lbl_805FBB60;
extern "C" int fn_804089B4(char* dst, const char* fmt, ...);
extern "C" int fn_8007DA28__18Unk8007B2B0_Screen(void* g);
extern "C" float fn_8051F290(int a, int b);
extern const char lbl_805F4ECC[];
extern const char lbl_805F511C[];
extern const float lbl_805FBB4C;
extern const float lbl_805FBB50;

extern const char lbl_805F5648[];
extern const char lbl_805F7944[];
extern const char lbl_805FBB40[];
extern "C" void fn_8052007C(FeV10* x);
extern "C" int fn_804DC75C(void* p, int a, int b, int c, int d);
extern const char lbl_8067A5E8[];
extern const char lbl_8067A2E0[];
extern "C" void fn_8051E878(void* x, int a);
extern "C" int fn_8051E890(void* x, int a, int b, int c, int d);
extern "C" FeW* fn_8051F42C(FeV10* x);
extern "C" void* fn_8051F470(FeV10* x);
extern "C" void* fn_8051F4D8(void* x);
extern "C" FeW* fn_8051F51C(FeV10* x);
extern "C" void fn_8051F6A4(void* x);
extern "C" void fn_8051F6E0(FeV10* x, int a);
extern "C" void fn_8051F748(void* x);
extern "C" void fn_8051F784(FeV10* x, int a);
extern "C" void fn_8051F964(FeV10* x);
extern "C" void fn_8051F9C0(FeV10* x);
extern "C" void fn_8051FE58(FeV10* x);
extern "C" void fn_8051FEA8(FeV10* x);
extern "C" void fn_8052005C(FeScrD* x);
extern "C" void fn_80520128(FeV10* x);
extern "C" void fn_80520178(FeV10* x);
extern "C" void fn_805203B8(FeV10* x);
extern "C" void fn_80520408(FeV10* x);
extern "C" void fn_805206EC(FeV10* x);
extern "C" void fn_8052073C(FeV10* x);
extern "C" void fn_80520794(FeV10* x);
extern "C" void fn_805207E4(FeV10* x);
extern "C" void fn_8052088C(FeV10B* x);
extern "C" void fn_805208E0(FeV10B* x);

extern "C" FE_OVERLAY void fn_8051E878(void* x, int a)
{
    if (FeI(x, 0x5A4) != 0) {
        FeI(x, 0x43C) = a;
        FeI(x, 0x5A0) = a;
    }
}

/* near-miss: retail lays the zero case first (beq to the body, li r3,0, b end); 4 spellings tried */
extern "C" FE_OVERLAY int fn_8051E890(void* x, int a, int b, int c, int d)
{
    if (FeI(x, 0x5A8) == 1) {
        fn_804DC75C((char*)x + 0x2DC, a, b, c, d);
        fn_804DC75C((char*)x + 0x440, a, b, c, d);
        return 1;
    } else {
        return 0;
    }
}

extern "C" FE_OVERLAY int fn_8051E910(int a, int b)
{
    int i = 0;
    unsigned t = a - 0x54;
    if (t <= 0x58) {
        return fn_80087A88__FP13Unk80087A58_Oiii((void*)b, t, 0, 1);
    }
    switch (a) {
    case 0x0:
        return FeI((void*)b, 0x1C);
    case 0x1:
        return FeI((void*)b, 0xC);
    case 0x2:
        return FeI((void*)b, 0x124);
    case 0x3:
        return FeI((void*)b, 0x124);
    case 0x4:
        return FeI((void*)b, 0x128);
    case 0x5:
        return FeI((void*)b, 0x30);
    case 0x6:
        return FeI((void*)b, 0x34);
    case 0x7:
        return FeI((void*)b, 0x50);
    case 0x8:
        return FeI((void*)b, 0x38);
    case 0x9:
        return FeI((void*)b, 0x12C);
    case 0xA:
        return FeI((void*)b, 0x130);
    case 0xB:
        return FeI((void*)b, 0x134);
    case 0xC:
        return FeI((void*)b, 0x138);
    case 0xD:
        return FeI((void*)b, 0x13C);
    case 0xE:
        return FeI((void*)b, 0x140);
    case 0xF:
        return FeI((void*)b, 0x144);
    case 0x10:
        return FeI((void*)b, 0x20);
    case 0x11:
        return FeI((void*)b, 0x24);
    case 0x12:
        return FeI((void*)b, 0x28);
    case 0x13:
        return FeI((void*)b, 0x10);
    case 0x14:
        return FeI((void*)b, 0x2C);
    case 0x15:
        return FeI((void*)b, 0x1D4);
    case 0x16:
        return FeI((void*)b, 0x1D8);
    case 0x17:
        return FeI((void*)b, 0x1DC);
    case 0x18:
        return FeI((void*)b, 0x1E0);
    case 0x19:
        return FeI((void*)b, 0x1E4);
    case 0x1A:
        return FeI((void*)b, 0x1E8);
    case 0x1B:
        return FeI((void*)b, 0x44);
    case 0x1C:
        return FeI((void*)b, 0x4C);
    case 0x1D:
        return FeI((void*)b, 0x48);
    case 0x1E:
        return FeI((void*)b, 0x1EC);
    case 0x1F:
        return FeI((void*)b, 0x1F0);
    case 0x20:
        return FeI((void*)b, 0x1F4);
    case 0x21:
        return FeI((void*)b, 0x18C);
    case 0x22:
        return FeI((void*)b, 0x190);
    case 0x23:
        return FeI((void*)b, 0x184);
    case 0x24:
        return FeI((void*)b, 0x188);
    case 0x25:
        return FeI((void*)b, 0x10);
    case 0x26:
        return FeI((void*)b, 0x148);
    case 0x27:
        return FeI((void*)b, 0x14C);
    case 0x28:
        return FeI((void*)b, 0x230);
    case 0x29:
        return FeI((void*)b, 0x150);
    case 0x2A:
        return FeI((void*)b, 0x14);
    case 0x2B:
        return fn_80086D34__FP13Unk80084910_Wi((void*)b, 0);
    case 0x2C:
        return fn_80086D34__FP13Unk80084910_Wi((void*)b, 1);
    case 0x2D:
        return fn_80086D34__FP13Unk80084910_Wi((void*)b, 2);
    case 0x2E:
        return fn_80086D34__FP13Unk80084910_Wi((void*)b, 3);
    case 0x2F:
        return FeI((void*)(b + (i << 2)), 0x15C);
    case 0x30:
        return FeI((void*)(b + (i << 2)), 0x164);
    case 0x31:
        return FeI((void*)(b + (i << 2)), 0x154);
    case 0x32:
        return FeI((void*)(b + (i << 2)), 0x16C);
    case 0x33:
        return FeI((void*)b, 0x174);
    case 0x34:
        return FeI((void*)(b + (i << 2)), 0x17C);
    case 0x3A:
        return FeI((void*)b, 0x194);
    case 0x3B:
        return FeI((void*)b, 0x198);
    case 0x3C:
        return FeI((void*)b, 0x19C);
    case 0x3D:
        return FeI((void*)b, 0x1A4);
    case 0x3E:
        return FeI((void*)b, 0x1A0);
    case 0x3F:
        return FeI((void*)b, 0x1B0);
    case 0x40:
        return FeI((void*)b, 0x1B4);
    case 0x41:
        return FeI((void*)b, 0x1B8);
    case 0x42:
        return FeI((void*)b, 0x1BC);
    case 0x43:
        return FeI((void*)b, 0x1A8);
    case 0x44:
        return FeI((void*)b, 0x1AC);
    case 0x45:
        return FeI((void*)b, 0x1C0);
    case 0x46:
        return FeI((void*)b, 0x1C4);
    case 0x47:
        return FeI((void*)b, 0x1C8);
    case 0x48:
        return FeI((void*)b, 0x1CC);
    case 0x49:
        return FeI((void*)b, 0x1D0);
    default:
        return 0;
    }
}

extern "C" FE_OVERLAY void fn_8051EDDC(int a, int b, int c)
{
    unsigned t = a - 0x54;
    if (t <= 0x58) {
        fn_80087A58__FP13Unk80087A58_Oicii((void*)b, t, c, 0, 1);
        return;
    }
    switch (a) {
    case 0x0:
        FeI((void*)b, 0x1C) = c;
        break;
    case 0x1:
        FeI((void*)b, 0xC) = c;
        break;
    case 0x2:
        FeI((void*)b, 0x124) = c;
        break;
    case 0x3:
        FeI((void*)b, 0x124) = c;
        break;
    case 0x4:
        FeI((void*)b, 0x128) = c;
        break;
    case 0x5:
        FeI((void*)b, 0x30) = c;
        break;
    case 0x6:
        FeI((void*)b, 0x34) = c;
        break;
    case 0x7:
        FeI((void*)b, 0x50) = c;
        break;
    case 0x8:
        FeI((void*)b, 0x38) = c;
        break;
    case 0x9:
        FeI((void*)b, 0x12C) = c;
        break;
    case 0xA:
        FeI((void*)b, 0x130) = c;
        break;
    case 0xB:
        FeI((void*)b, 0x134) = c;
        break;
    case 0xC:
        FeI((void*)b, 0x138) = c;
        break;
    case 0xD:
        FeI((void*)b, 0x13C) = c;
        break;
    case 0xE:
        FeI((void*)b, 0x140) = c;
        break;
    case 0xF:
        FeI((void*)b, 0x144) = c;
        break;
    case 0x10:
        FeI((void*)b, 0x20) = c;
        break;
    case 0x11:
        FeI((void*)b, 0x24) = c;
        break;
    case 0x12:
        FeI((void*)b, 0x28) = c;
        break;
    case 0x13:
        FeI((void*)b, 0x10) = c;
        break;
    case 0x14:
        FeI((void*)b, 0x2C) = c;
        break;
    case 0x15:
        FeI((void*)b, 0x1D4) = c;
        break;
    case 0x16:
        FeI((void*)b, 0x1D8) = c;
        break;
    case 0x17:
        FeI((void*)b, 0x1DC) = c;
        break;
    case 0x18:
        FeI((void*)b, 0x1E0) = c;
        break;
    case 0x19:
        FeI((void*)b, 0x1E4) = c;
        break;
    case 0x1A:
        FeI((void*)b, 0x1E8) = c;
        break;
    case 0x1B:
        FeI((void*)b, 0x44) = c;
        break;
    case 0x1C:
        FeI((void*)b, 0x4C) = c;
        break;
    case 0x1D:
        FeI((void*)b, 0x48) = c;
        break;
    case 0x1E:
        FeI((void*)b, 0x1EC) = c;
        break;
    case 0x1F:
        FeI((void*)b, 0x1F0) = c;
        break;
    case 0x20:
        FeI((void*)b, 0x1F4) = c;
        break;
    case 0x21:
        FeI((void*)b, 0x18C) = c;
        break;
    case 0x22:
        FeI((void*)b, 0x190) = c;
        break;
    case 0x23:
        FeI((void*)b, 0x184) = c;
        break;
    case 0x24:
        FeI((void*)b, 0x188) = c;
        break;
    case 0x25:
        FeI((void*)b, 0x10) = c;
        break;
    case 0x26:
        FeI((void*)b, 0x148) = c;
        break;
    case 0x27:
        FeI((void*)b, 0x14C) = c;
        break;
    case 0x28:
        FeI((void*)b, 0x230) = c;
        break;
    case 0x29:
        FeI((void*)b, 0x150) = c;
        break;
    case 0x2A:
        FeI((void*)b, 0x14) = c;
        FeI((void*)b, 0x18) = c;
        break;
    case 0x2B:
        fn_80086D24__FP13Unk80084910_Wii((void*)b, 0);
        break;
    case 0x2C:
        fn_80086D24__FP13Unk80084910_Wii((void*)b, 1);
        break;
    case 0x2D:
        fn_80086D24__FP13Unk80084910_Wii((void*)b, 2);
        break;
    case 0x2E:
        fn_80086D24__FP13Unk80084910_Wii((void*)b, 3);
        break;
    case 0x2F:
        FeI((void*)b, 0x15C) = c;
        FeI((void*)b, 0x160) = c;
        break;
    case 0x30:
        FeI((void*)b, 0x164) = c;
        FeI((void*)b, 0x168) = c;
        break;
    case 0x31:
        FeI((void*)b, 0x154) = c;
        FeI((void*)b, 0x158) = c;
        break;
    case 0x32:
        FeI((void*)b, 0x16C) = c;
        FeI((void*)b, 0x170) = c;
        break;
    case 0x33:
        FeI((void*)b, 0x174) = c;
        FeI((void*)b, 0x178) = c;
        break;
    case 0x34:
        FeI((void*)b, 0x17C) = c;
        FeI((void*)b, 0x180) = c;
        break;
    case 0x3A:
        FeI((void*)b, 0x194) = c;
        break;
    case 0x3B:
        FeI((void*)b, 0x198) = c;
        break;
    case 0x3C:
        FeI((void*)b, 0x19C) = c;
        break;
    case 0x3D:
        FeI((void*)b, 0x1A4) = c;
        break;
    case 0x3E:
        FeI((void*)b, 0x1A0) = c;
        break;
    case 0x3F:
        FeI((void*)b, 0x1B0) = c;
        break;
    case 0x40:
        FeI((void*)b, 0x1B4) = c;
        break;
    case 0x41:
        FeI((void*)b, 0x1B8) = c;
        break;
    case 0x42:
        FeI((void*)b, 0x1BC) = c;
        break;
    case 0x43:
        FeI((void*)b, 0x1A8) = c;
        break;
    case 0x44:
        FeI((void*)b, 0x1AC) = c;
        break;
    case 0x45:
        FeI((void*)b, 0x1C0) = c;
        break;
    case 0x46:
        FeI((void*)b, 0x1C4) = c;
        break;
    case 0x47:
        FeI((void*)b, 0x1C8) = c;
        break;
    case 0x48:
        FeI((void*)b, 0x1CC) = c;
        break;
    case 0x49:
        FeI((void*)b, 0x1D0) = c;
        break;
    }
}

extern "C" FE_OVERLAY float fn_8051F290(int a, int b)
{
    unsigned char* p = (unsigned char*)b;
    switch (a) {
    case 0x35:
        return (float)p[4] * 0.003921569f;
    case 0x36:
        return (float)p[7] * 0.003921569f;
    case 0x37:
        return (float)p[5] * 0.003921569f;
    case 0x38:
        return (float)p[8] * 0.003921569f;
    case 0x39:
        return (float)p[6] * 0.003921569f;
    }
    return 0.0f;
}

extern "C" FE_OVERLAY void fn_8051F32C(int a, int b, float f)
{
    switch (a) {
    case 0x35:
        fn_80086D44__FPcif((char*)b, 0, f);
        fn_8001BC4C()->fn_8001C05C(0, f, 1);
        break;
    case 0x36:
        fn_80086D44__FPcif((char*)b, 3, f);
        fn_8001BC4C()->fn_8001C05C(3, f, 1);
        break;
    case 0x37:
        fn_80086D44__FPcif((char*)b, 1, f);
        fn_8001BC4C()->fn_8001C05C(1, f, 1);
        break;
    case 0x38:
        fn_80086D44__FPcif((char*)b, 4, f);
        fn_8001BC4C()->fn_8001C05C(4, f, 1);
        break;
    case 0x39:
        fn_80086D44__FPcif((char*)b, 2, f);
        fn_8001BC4C()->fn_8001C05C(2, f, 1);
        break;
    }
}

extern "C" FE_OVERLAY FeW* fn_8051F42C(FeV10* x)
{
    return FePool(x);
}

extern "C" FE_OVERLAY void* fn_8051F470(FeV10* x)
{
    return fn_800C8048(FePool(x)->fn_vslot29(lbl_805F5648));
}

extern "C" FE_OVERLAY void* fn_8051F4D8(void* x)
{
    return fn_800C8058(fn_8051F51C((FeV10*)x)->fn_vslot29(lbl_805FBB40));
}

extern "C" FE_OVERLAY FeW* fn_8051F51C(FeV10* x)
{
    return fn_800C805C(FePool(x)->fn_vslot29(lbl_805F7944));
}

extern "C" FE_OVERLAY void fn_8051F584(FeV10B* x, int a)
{
    if (x->mC != a) {
        x->mC = a;
        if (lbl_80622644 != 0) {
            if (x->s2() >= x->mC) {
                x->s3(x->mC - 1);
            }
            x->s8();
            if (x->mC == 1) {
                if (FeI(fn_8051F42C((FeV10*)x), 0x24) & 0x40000000) {
                    fn_8051F42C((FeV10*)x)->fn_vslot16(0);
                }
            } else if (!(FeI(fn_8051F42C((FeV10*)x), 0x24) & 0x40000000)) {
                fn_8051F42C((FeV10*)x)->fn_vslot16(1);
            }
        }
    }
}

extern "C" FE_OVERLAY void fn_8051F6A4(void* x)
{
    FeSubOf(x)->s5();
}

extern "C" FE_OVERLAY void fn_8051F6E0(FeV10* x, int a)
{
    FeSubOf(x)->s6(a);
    x->s9();
}

extern "C" FE_OVERLAY void fn_8051F748(void* x)
{
    FeSubOf(x)->s11();
}

/* near-miss: the else-arm FeSubOf(x)->s8(a) call gets the two-register delta form in ours, retail uses add r3,r3,r0 (int/void s8 both tried) */
extern "C" FE_OVERLAY void fn_8051F784(FeV10* x, int a)
{
    if (FeSubOf(x)->s7(a) == -1) {
        FeSubOf(x)->s6(0);
    } else {
        FeSubOf(x)->s8(a);
        x->s9();
    }
}

extern "C" FE_OVERLAY void fn_8051F848(FeV10E* x)
{
    ((FeWV*)fn_8051F470((FeV10*)x))->s29(x->m8);
    void* w = fn_8051F4D8(x);
    ((FeSub24*)((char*)w + 0xDC))->s15();
    for (int i = 0; i < x->mC; i++) {
        ((FeWV*)w)->s51(x->s11(i), x->s12(i));
    }
    if (x->mC == 1) {
        fn_8051F42C((FeV10*)x)->fn_vslot16(0);
    }
}

extern "C" FE_OVERLAY void fn_8051F964(FeV10* x)
{
    x->s5(fn_8051E910(x->m4, lbl_80622648));
}

/* near-miss: retail loads x->m4 and lbl into callee-saved regs between fn_8051F4D8 and the vcall; ours reorders (4 spellings tried) */
extern "C" FE_OVERLAY void fn_8051F9C0(FeV10* x)
{
    FeSub24* s = FeSubOf(x);
    fn_8051EDDC(x->m4, lbl_80622648, s->s11());
}

extern "C" FE_OVERLAY void fn_8051FA24(FeV10* x, int a)
{
    if (FeSubOf(x)->s7(a) == -1) {
        FeSubOf(x)->s6(0);
    } else {
        FeSubOf(x)->s8(a);
    }
    x->s9();
}

extern "C" FE_OVERLAY void fn_8051FAE8(FeV10* x)
{
    FeV10* h = (FeV10*)fn_80522890(fn_805210A0(), 1);
    int t = x->s4();
    if (h != 0) {
        switch (t) {
        case 0:
            h->s5(2);
            break;
        case 1:
            h->s5(1);
            break;
        case 2:
            h->s5(1);
            break;
        case 3:
            h->s5(0);
            break;
        }
    }
    FeI(x, 0x18) = x->s4();
}

extern "C" FE_OVERLAY void fn_8051FBD0(FeV10* x, int a)
{
    FeI(x, 0x18) = a;
    if (a != 0) {
        ((FeWV*)fn_8051F4D8(x))->s29(0x3EB);
        fn_8051F42C(x)->fn_vslot16(0);
        return;
    }
    FeSubOf(x)->s6(FeSubOf(x)->s5());
    fn_8051F42C(x)->fn_vslot16(1);
}

extern "C" FE_OVERLAY void fn_8051FCC4(FeV10* x)
{
    int t = fn_80522890(fn_805210A0(), 10);
    if (t != 0) {
        if (x->s4() == 3) {
            fn_8051FBD0((FeV10*)t, 1);
        } else if (!(FeI(fn_8051F42C((FeV10*)t), 0x24) & 0x40000000)) {
            fn_8051FBD0((FeV10*)t, 0);
        }
    }
}

extern "C" FE_OVERLAY void fn_8051FD50(FeV10* x)
{
    float f = fn_8051F290(x->m4, lbl_80622648);
    x->s5((int)(f * lbl_805FBB4C + lbl_805FBB50));
}

extern "C" FE_OVERLAY void fn_8051FDC8(FeV10* x)
{
    void* w = fn_8051F4D8(x);
    float f = (float)((FeSub24*)((char*)w + 0xDC))->s11() * lbl_805FBB60;
    fn_8051F32C(x->m4, lbl_80622648, f);
}

extern "C" FE_OVERLAY void fn_8051FE58(FeV10* x)
{
    x->s5(FeGetSet()->m520);
}

extern "C" FE_OVERLAY void fn_8051FEA8(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m520 = x->s4();
}

//@8051FEF4
FE_OVERLAY FeRecA::FeRecA(int a)
{
    m0 = -1;
    m4 = a;
    m8 = 0x3BEE;
    mC = 0;
    m10 = lbl_8067A5E8;
}

extern "C" FE_OVERLAY void fn_8051FF24(FeV10* x)
{
    x->s5(fn_8007DA28__18Unk8007B2B0_Screen(lbl_8061930C));
    fn_8052007C(x);
}

extern "C" FE_OVERLAY void fn_8051FF84(void) {}

extern "C" FE_OVERLAY void fn_8051FF88(FeV10* x)
{
    int i = 0;
    ((FeWV*)fn_8051F470(x))->s29(x->m8);
    void* w = fn_8051F4D8(x);
    ((FeSub24*)((char*)w + 0xDC))->s15();
    int n = fn_8007DBB0__FP13Unk8007DB74_A(lbl_8061930C);
    ((FeWV*)w)->s51(0x3FB5, -1);
    for (; i < n; i++) {
        ((FeWV*)w)->s51(8, i);
    }
    fn_8051F584((FeV10B*)x, n + 1);
    fn_8052007C(x);
}

extern "C" FE_OVERLAY void fn_8052005C(FeScrD* x)
{
    fn_8052007C((FeV10*)x);
}

extern "C" FE_OVERLAY void fn_8052007C(FeV10* x)
{
    char buf[24];
    int r = x->s4();
    if (r == -1) {
        ((FeWV*)fn_8051F4D8(x))->s29(0x3FB5);
    } else {
        fn_8007CF44__18Unk8007B2B0_ScreenUiii(lbl_8061930C, r, buf, 0);
        ((FeWV*)fn_8051F4D8(x))->s28(buf);
    }
}

extern "C" FE_OVERLAY void fn_80520128(FeV10* x)
{
    x->s5(FeGetSet()->m580);
}

extern "C" FE_OVERLAY void fn_80520178(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m580 = x->s4();
}

extern "C" FE_OVERLAY void fn_805201C4(FeV10* x)
{
    ((FeWV*)fn_8051F470(x))->s29(x->m8);
    void* w = fn_8051F4D8(x);
    ((FeSub24*)((char*)w + 0xDC))->s15();
    ((FeWV*)w)->s51(0x3E9, 0);
    ((FeWV*)w)->s51(0x46DC, 1);
    ((FeWV*)w)->s51(0x46DD, 2);
    ((FeWV*)w)->s51(0x46DE, 3);
    ((FeWV*)w)->s51(0x5CAB, 4);
}

extern "C" FE_OVERLAY void fn_805202D4(FeV10* x)
{
    FeV10* h = (FeV10*)fn_80522890(fn_805210A0(), 0x50);
    ((FeWV*)lbl_80622644)->s101(h->m0, x->s4() != 0);
    ((FeWV*)fn_8051F51C(h))->s44(x->s4() != 0);
}

extern "C" FE_OVERLAY void fn_805203B8(FeV10* x)
{
    x->s5(FeGetSet()->m588);
}

extern "C" FE_OVERLAY void fn_80520408(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m588 = x->s4();
}

extern "C" FE_OVERLAY void fn_80520454(FeV10* x)
{
    ((FeWV*)fn_8051F470(x))->s29(x->m8);
    void* w = fn_8051F4D8(x);
    ((FeSub24*)((char*)w + 0xDC))->s15();
    ((FeWV*)w)->s51(0x3E9, 0);
    ((FeWV*)w)->s51(0x3E8, 1);
}

extern "C" FE_OVERLAY void fn_80520504(FeV10* x)
{
    FeV10* h = (FeV10*)fn_80522890(fn_805210A0(), 0x51);
    ((FeWV*)lbl_80622644)->s101(h->m0, x->s4() != 0);
    ((FeWV*)fn_8051F51C(h))->s44(x->s4() != 0);
}

extern "C" FE_OVERLAY void fn_805205E8(FeV10* x)
{
    if (FeI(x, 0x18) != 0) {
        x->s5(FeGetSet()->m58C);
    } else {
        x->s5(FeGetSet()->m584);
    }
}

extern "C" FE_OVERLAY void fn_8052066C(FeV10* x)
{
    if (FeI(x, 0x18) != 0) {
        FeSet* st = FeGetSet();
        st->m58C = x->s4();
    } else {
        FeSet* st = FeGetSet();
        st->m584 = x->s4();
    }
}

extern "C" FE_OVERLAY void fn_805206EC(FeV10* x)
{
    x->s5(FeGetSet()->m524);
}

extern "C" FE_OVERLAY void fn_8052073C(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m524 = x->s4() == 1;
}

extern "C" FE_OVERLAY void fn_80520794(FeV10* x)
{
    x->s5(FeGetSet()->m528);
}

extern "C" FE_OVERLAY void fn_805207E4(FeV10* x)
{
    FeSet* st = FeGetSet();
    st->m528 = x->s4() == 1;
}

//@8052083C
FE_OVERLAY FeRecC::FeRecC(int a, int b, int c, int d, int e)
{
    m0 = -1;
    m4 = a;
    m8 = b;
    m10 = lbl_8067A2E0;
    m14 = c;
    m18 = d;
    m1C = e;
    m20 = 0;
    mC = d / e;
}

extern "C" FE_OVERLAY void fn_8052088C(FeV10B* x)
{
    int v = fn_8051E910(x->m4, lbl_80622648);
    x->s3(v);
}

extern "C" FE_OVERLAY void fn_805208E0(FeV10B* x)
{
    fn_8051EDDC(x->m4, lbl_80622648, x->s2());
}

extern "C" FE_OVERLAY void fn_8052093C(FeV10* x)
{
    ((FeWV*)fn_8051F470(x))->s29(x->m8);
    void* w = fn_8051F4D8(x);
    ((FeSub24*)((char*)w + 0xDC))->s15();
    ((FeWV*)w)->s51(8, 0);
    x->s11();
}

extern "C" FE_OVERLAY void fn_805209E4(FeV10D* x, int a)
{
    if (a == 0) {
        x->m20 = x->m20 - x->m1C;
        if (x->m20 < x->m14) {
            x->m20 = x->m18;
        }
    } else if (a == 1) {
        x->m20 = x->m20 + x->m1C;
        if (x->m20 > x->m18) {
            x->m20 = x->m14;
        }
    }
    x->s11();
}

extern "C" FE_OVERLAY void fn_80520A74(FeV10D* x)
{
    char buf[32];
    fn_804089B4(buf, lbl_805F4ECC, x->m20);
    ((FeWV*)fn_8051F4D8(x))->s30(buf);
}

extern "C" FE_OVERLAY void fn_80520AD8(FeV10B* x)
{
    char buf[32];
    int h = x->mC / 2;
    fn_804089B4(buf, lbl_805F4ECC, x->s2() - h);
    ((FeWV*)fn_8051F4D8(x))->s30(buf);
}

extern "C" FE_OVERLAY void fn_80520B64(FeV10B* x)
{
    char buf[32];
    fn_804089B4(buf, lbl_805F511C, x->s2());
    ((FeWV*)fn_8051F4D8(x))->s30(buf);
}
