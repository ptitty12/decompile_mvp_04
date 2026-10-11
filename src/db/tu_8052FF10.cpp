/*
 * Database overlay code, .database_codeoverlay 0x8052FF10-0x80531A20 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8052A220.h"
#include "game/tu_8007A4DC.h"

extern char lbl_80684540[];
extern char lbl_806844D0[];
extern const char lbl_805FE19C[];
extern const float lbl_805FE1D0;
extern char lbl_805FE1D4[];
extern "C" void* fn_803774A8(unsigned n, int heap);
extern "C" void* fn_803FFA60(void* d, const void* s, unsigned n);
extern "C" void fn_8052DD58(Unk8052DD58_Ent* e);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern char lbl_80682810[];
struct Unk8052E408_Obj;
extern "C" void fn_80360AB4(Unk8052E408_Obj* self);

extern char lbl_805FE624[];
extern "C" int fn_8040B6A0(const char* s);
extern "C" char* fn_8040B830(char* dst, const char* src, int n);
extern int lbl_80601374[];
extern Unk8007B2B0_Screen* lbl_8061930C;
extern char lbl_80684460[];
extern char lbl_806843F0[];
extern const float lbl_805FE620;

extern "C" DB_OVERLAY Unk80071604* fn_8052FF10(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_80684460;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 0x2C, 0);
    fn_8040074C(self->m24, self->m1C * 0x2C);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

extern "C" DB_OVERLAY void fn_8052FF8C(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684460;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_8052FFE8(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 0x2C, 0x2C);
}

extern "C" DB_OVERLAY unsigned fn_80530134(Unk80071604* self, unsigned kind, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (kind) {
        case 0:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f0;
            break;
        case 1:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f1;
            break;
        case 2:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f2;
            break;
        case 3:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f3;
            break;
        case 4:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f4;
            break;
        case 5:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f5;
            break;
        case 6:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f6;
            break;
        case 7:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f7;
            break;
        case 8:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f8;
            break;
        case 9:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f9;
            break;
        case 10:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f10;
            break;
        case 11:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f11;
            break;
        case 12:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f12;
            break;
        case 13:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f13;
            break;
        case 14:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f14;
            break;
        case 15:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f15;
            break;
        case 16:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f16;
            break;
        case 17:
            r = ((Unk8052FF10_Rec*)self->m24)[i].f17;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY char* fn_80530398(Unk80071604* self, int kind, unsigned i, char* out)
{
    if (i < self->m1C) {
        switch (kind) {
        case 0:
            fn_8040B61C(out, self->m24 + i * 0x2C + 0xF);
            break;
        case 1:
            fn_8040B61C(out, self->m24 + i * 0x2C + 0x1B);
            break;
        }
    }
    return out;
}

extern Unk8052CF34_Pmf lbl_80601344[];

extern "C" DB_OVERLAY float fn_80530418(Unk8052CF34_Obj* o, int i, int a)
{
    float r = (o->*lbl_80601344[i])(a);
    return r;
}

extern "C" DB_OVERLAY void fn_805304B0(Unk80071604* self, unsigned kind, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (kind) {
        case 0: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            if (!(v > 0xFFFF))
                v = v >? 0;
            else
                v = 0xFFFF;
            e->f0 = v;
            break;
        }
        case 1: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x1 ? 0x1 : (v >? 0);
            e->f1 = v;
            break;
        }
        case 2: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x3f ? 0x3f : (v >? 0);
            e->f2 = v;
            break;
        }
        case 3: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xff ? 0xff : (v >? 0);
            e->f3 = v;
            break;
        }
        case 4: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x7f ? 0x7f : (v >? 0);
            e->f4 = v;
            break;
        }
        case 5: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x3ff ? 0x3ff : (v >? 0);
            e->f5 = v;
            break;
        }
        case 6: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xf ? 0xf : (v >? 0);
            e->f6 = v;
            break;
        }
        case 7: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x7 ? 0x7 : (v >? 0);
            e->f7 = v;
            break;
        }
        case 8: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xf ? 0xf : (v >? 0);
            e->f8 = v;
            break;
        }
        case 9: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x1 ? 0x1 : (v >? 0);
            e->f9 = v;
            break;
        }
        case 10: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x1 ? 0x1 : (v >? 0);
            e->f10 = v;
            break;
        }
        case 11: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xff ? 0xff : (v >? 0);
            e->f11 = v;
            break;
        }
        case 12: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x7 ? 0x7 : (v >? 0);
            e->f12 = v;
            break;
        }
        case 13: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f13 = v;
            break;
        }
        case 14: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f14 = v;
            break;
        }
        case 15: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f15 = v;
            break;
        }
        case 16: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f16 = v;
            break;
        }
        case 17: {
            Unk8052FF10_Rec* e = (Unk8052FF10_Rec*)(i * 0x2C + (int)self->m24);
            e->f17 = v > 100 ? 100 : (v >? 0);
            break;
        }
        }
    }
}

extern "C" DB_OVERLAY void fn_8053095C(Unk80071604* self, int kind, unsigned i, const char* src, int n)
{
    if (i < self->m1C) {
        if (n <= 0)
            n = fn_8040B6A0(src);
        int lim = lbl_80601374[kind] - 1;
        if (n > lim)
            n = lim;
        switch (kind) {
        case 0:
            fn_8040B830(((Unk8052FF10_Rec*)self->m24)[i].m0F, src, n);
            ((Unk8052FF10_Rec*)self->m24)[i].m0F[n] = 0;
            break;
        case 1:
            fn_8040B830(((Unk8052FF10_Rec*)self->m24)[i].m1B, src, n);
            ((Unk8052FF10_Rec*)self->m24)[i].m1B[n] = 0;
            break;
        }
    }
}

extern "C" DB_OVERLAY float fn_80530A48(W* self, int a)
{
    float r = (float)(self->v28(2, a) + 0x30);
    return r;
}

extern "C" DB_OVERLAY float fn_80530AB4(W* self, int a)
{
    float r = (float)(self->v28(3, a) + 0x64);
    return r;
}

extern "C" DB_OVERLAY float fn_80530B20(W* self, int a)
{
    int v = self->v28(0, a);
    return (float)fn_80329FA0(v).m0;
}

extern "C" DB_OVERLAY float fn_80530B90(W* self, int a)
{
    Unk80329FA0_Out o = fn_80329FA0(self->v28(0, a));
    return (float)o.m2;
}

extern "C" DB_OVERLAY float fn_80530C0C(W* self, int a)
{
    Unk80329FA0_Out o = fn_80329FA0(self->v28(0, a));
    return (float)o.m1;
}

extern "C" DB_OVERLAY float fn_80530C88(W* self, int a)
{
    int v = self->v28(0xB, a);
    float r = lbl_8061930C->fn_80079A90(v);
    return r;
}

extern "C" DB_OVERLAY void fn_80530CDC(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C * 0x2C);
}

extern "C" DB_OVERLAY Unk80071604* fn_80530D38(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_806843F0;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C << 3, 0);
    fn_8040074C(self->m24, self->m1C << 3);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

extern "C" DB_OVERLAY void fn_80530DB4(Unk80071604* self, int chrg)
{
    self->m20 = lbl_806843F0;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_80530E10(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + (i << 3), 8);
}

extern "C" DB_OVERLAY int fn_80530E4C(void* self)
{
    return 0;
}

extern "C" DB_OVERLAY int fn_80530E54(void* self)
{
    return 0;
}

extern "C" DB_OVERLAY int fn_80530E5C(void* self)
{
    return 0;
}

extern "C" DB_OVERLAY int fn_80530E64(int a, int b, int c, int d)
{
    return d;
}

extern "C" DB_OVERLAY float fn_80530E6C()
{
    float r;
    return r = lbl_805FE620;
}

extern "C" DB_OVERLAY void fn_80530E88()
{
}

extern "C" DB_OVERLAY void fn_80530E8C()
{
}

extern "C" DB_OVERLAY void fn_80530E90(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C << 3);
}

extern "C" DB_OVERLAY char* fn_80530EEC(Unk80071604* self, int i)
{
    return self->m24 + (i << 3);
}

extern "C" DB_OVERLAY char* fn_80530EFC(Unk80071604* self, int i)
{
    return self->m24 + (i << 3);
}

extern "C" DB_OVERLAY void* fn_805311A4(void* self, const void* src)
{
    fn_803FFA60(self, src, 8);
    return self;
}

extern "C" DB_OVERLAY Unk8052DC94_Out* fn_805311D8(Unk8052DC94_Out* self, Unk8052FF10_Rec* src)
{
    unsigned short ha = fn_80329FA0(1).m2;
    unsigned short hb = fn_80329FA0(src->f0).m2;
    self->b0 = hb - ha;
    self->fa = src->f11;
    self->fb = src->f12;
    return self;
}

extern "C" DB_OVERLAY int fn_8053125C()
{
    return 5;
}

extern "C" DB_OVERLAY int fn_80531264(int i)
{
    Unk80531264_Five t = *(Unk80531264_Five*)lbl_805FE624;
    return t.w[i];
}

extern "C" DB_OVERLAY void fn_805312AC(Unk805312AC_Tbl* self)
{
    unsigned a;
    for (a = 0; a <= 1; a++) {
        unsigned b;
        for (b = 0; b <= 1; b++) {
            unsigned k;
            for (k = 0; k <= 2; k++) {
                int d;
                for (d = 0; d < 9; d++) {
                    self->m8[d + k * 16 + b * 0x30 + a * 0x60] = 0;
                    self->m11[k * 16 + b * 0x30 + a * 0x60] = 0x21;
                    self->m12[k * 16 + b * 0x30 + a * 0x60] = 0x22;
                    self->m13[k * 16 + b * 0x30 + a * 0x60] = 0x21;
                    self->m14[k * 16 + b * 0x30 + a * 0x60] = 0;
                    self->m15[k * 16 + b * 0x30 + a * 0x60] = 0x21;
                    self->m16[k * 16 + b * 0x30 + a * 0x60] = 0x21;
                    self->m17[k * 16 + b * 0x30 + a * 0x60] = 0x21;
                }
            }
        }
    }
}

extern "C" DB_OVERLAY unsigned char fn_80531718(Unk80531718_Tbl* self, int a, int b, int c, int d)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m8[d + k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_80531774(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m11[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_805317CC(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m12[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_80531824(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m13[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_8053187C(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m14[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_805318D4(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m15[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_8053192C(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m16[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY unsigned char fn_80531984(Unk80531774_Tbl* self, int a, int b, int c)
{
    int k = 2;
    if (c <= 0x3B)
        k = 0;
    else if (c <= 0x4F)
        k = 1;
    if (b > 1) {
        if (a == 1)
            b = 0;
        else
            b = 1;
    }
    return self->m17[k * 16 + b * 0x30 + a * 0x60];
}

extern "C" DB_OVERLAY void fn_805319DC(int* a, int* b, int* c, int d)
{
    int sum = *a + *b + *c;
    *a = d * *a / sum;
    *b = d * *b / sum;
    *c = d - (*a + *b);
}
