/*
 * Database overlay code, .database_codeoverlay 0x8052CA60-0x8052E4C0 (code-only unit;
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
extern "C" void fn_8052DFDC(Unk8052DD58_Set* self, unsigned i);
extern "C" void fn_8052E158(Unk8052DD58_Ent* self, char a, int b, int c, int d, unsigned e, unsigned f, unsigned g, int h);
extern "C" void fn_8052E10C(Unk8052DD58_Ent* self, char a, int b, int c, int d, int e, int f, int g, char h, int i);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern "C" int fn_8040B6A0(const char* s);
extern "C" char* fn_8040B830(char* dst, const char* src, int n);
extern int lbl_8060133C[];
extern Unk8007B2B0_Screen* lbl_8061930C;
extern Unk8052CF34_Pmf lbl_8060130C[];
extern char lbl_80682810[];
extern char lbl_806841F8[];
struct Unk8052E408_Obj;
extern "C" void fn_80360AB4(Unk8052E408_Obj* self);

extern "C" DB_OVERLAY Unk80071604* fn_8052CA60(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_80684540;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 0x2C, 0);
    fn_8040074C(self->m24, self->m1C * 0x2C);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

extern "C" DB_OVERLAY void fn_8052CADC(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684540;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_8052CB38(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 0x2C, 0x2C);
}

/* Column table: one assignment per case; the dead compares are left by jump2
   (PATTERNS, "Hard-case families 4"). */
extern "C" DB_OVERLAY int fn_8052CB74(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    case 12:
        r = 0;
        break;
    case 13:
        r = 100;
        break;
    case 14:
        r = 100;
        break;
    case 15:
        r = 100;
        break;
    case 16:
        r = 100;
        break;
    }
    return r;
}

extern "C" DB_OVERLAY int fn_8052CC18(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    case 12:
        r = 0;
        break;
    case 13:
        r = 0;
        break;
    case 14:
        r = 0;
        break;
    case 15:
        r = 0;
        break;
    case 16:
        r = 0;
        break;
    }
    return r;
}

extern "C" DB_OVERLAY unsigned fn_8052CC74(Unk80071604* self, unsigned kind, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (kind) {
        case 0:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f0;
            break;
        case 1:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f1;
            break;
        case 2:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f2;
            break;
        case 3:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f3;
            break;
        case 4:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f4;
            break;
        case 5:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f5;
            break;
        case 6:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f6;
            break;
        case 7:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f7;
            break;
        case 8:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f8;
            break;
        case 9:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f9;
            break;
        case 10:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f10;
            break;
        case 11:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f11;
            break;
        case 12:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f12;
            break;
        case 13:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f13;
            break;
        case 14:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f14;
            break;
        case 15:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f15;
            break;
        case 16:
            r = ((Unk8052CA60_Rec*)self->m24)[i].f16;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY char* fn_8052CEB4(Unk80071604* self, int kind, unsigned i, char* out)
{
    if (i < self->m1C) {
        switch (kind) {
        case 0:
            fn_8040B61C(out, self->m24 + i * 0x2C + 0xE);
            break;
        case 1:
            fn_8040B61C(out, self->m24 + i * 0x2C + 0x1A);
            break;
        }
    }
    return out;
}

extern "C" DB_OVERLAY float fn_8052CF34(Unk8052CF34_Obj* o, int i, int a)
{
    float r = (o->*lbl_8060130C[i])(a);
    return r;
}

extern "C" DB_OVERLAY void fn_8052CFCC(Unk80071604* self, unsigned kind, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (kind) {
        case 0: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            if (!(v > 0xFFFF))
                v = v >? 0;
            else
                v = 0xFFFF;
            e->f0 = v;
            break;
        }
        case 1: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x3f ? 0x3f : (v >? 0);
            e->f1 = v;
            break;
        }
        case 2: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xff ? 0xff : (v >? 0);
            e->f2 = v;
            break;
        }
        case 3: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x7f ? 0x7f : (v >? 0);
            e->f3 = v;
            break;
        }
        case 4: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x3ff ? 0x3ff : (v >? 0);
            e->f4 = v;
            break;
        }
        case 5: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xf ? 0xf : (v >? 0);
            e->f5 = v;
            break;
        }
        case 6: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x7 ? 0x7 : (v >? 0);
            e->f6 = v;
            break;
        }
        case 7: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xf ? 0xf : (v >? 0);
            e->f7 = v;
            break;
        }
        case 8: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x1 ? 0x1 : (v >? 0);
            e->f8 = v;
            break;
        }
        case 9: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x1 ? 0x1 : (v >? 0);
            e->f9 = v;
            break;
        }
        case 10: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x1 ? 0x1 : (v >? 0);
            e->f10 = v;
            break;
        }
        case 11: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0xff ? 0xff : (v >? 0);
            e->f11 = v;
            break;
        }
        case 12: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x7 ? 0x7 : (v >? 0);
            e->f12 = v;
            break;
        }
        case 13: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f13 = v;
            break;
        }
        case 14: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f14 = v;
            break;
        }
        case 15: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            v = v > 0x64 ? 0x64 : (v >? 0);
            e->f15 = v;
            break;
        }
        case 16: {
            Unk8052CA60_Rec* e = (Unk8052CA60_Rec*)(i * 0x2C + (int)self->m24);
            e->f16 = v > 100 ? 100 : (v >? 0);
            break;
        }
        }
    }
}

extern "C" DB_OVERLAY void fn_8052D430(Unk80071604* self, int kind, unsigned i, const char* src, int n)
{
    if (i < self->m1C) {
        if (n <= 0)
            n = fn_8040B6A0(src);
        int lim = lbl_8060133C[kind] - 1;
        if (n > lim)
            n = lim;
        switch (kind) {
        case 0:
            fn_8040B830(((Unk8052CA60_Rec*)self->m24)[i].m0E, src, n);
            ((Unk8052CA60_Rec*)self->m24)[i].m0E[n] = 0;
            break;
        case 1:
            fn_8040B830(((Unk8052CA60_Rec*)self->m24)[i].m1A, src, n);
            ((Unk8052CA60_Rec*)self->m24)[i].m1A[n] = 0;
            break;
        }
    }
}

extern "C" DB_OVERLAY float fn_8052D51C(W* self, int a)
{
    float r = (float)(self->v28(1, a) + 0x30);
    return r;
}

extern "C" DB_OVERLAY float fn_8052D588(W* self, int a)
{
    float r = (float)(self->v28(2, a) + 0x64);
    return r;
}

extern "C" DB_OVERLAY float fn_8052D5F4(W* self, int a)
{
    int v = self->v28(0, a);
    return (float)fn_80329FA0(v).m0;
}

extern "C" DB_OVERLAY float fn_8052D664(W* self, int a)
{
    Unk80329FA0_Out o = fn_80329FA0(self->v28(0, a));
    return (float)o.m2;
}

extern "C" DB_OVERLAY float fn_8052D6E0(W* self, int a)
{
    Unk80329FA0_Out o = fn_80329FA0(self->v28(0, a));
    return (float)o.m1;
}

extern "C" DB_OVERLAY float fn_8052D75C(W* self, int a)
{
    int v = self->v28(0xB, a);
    float r = lbl_8061930C->fn_80079A90(v);
    return r;
}

extern "C" DB_OVERLAY void fn_8052D7B0(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C * 0x2C);
}

extern "C" DB_OVERLAY Unk80071604* fn_8052D80C(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_806844D0;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C << 3, 0);
    fn_8040074C(self->m24, self->m1C << 3);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

extern "C" DB_OVERLAY void fn_8052D888(Unk80071604* self, int chrg)
{
    self->m20 = lbl_806844D0;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_8052D8E4(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + (i << 3), 8);
}

extern "C" DB_OVERLAY int fn_8052D920(void* self)
{
    return 0;
}

extern "C" DB_OVERLAY int fn_8052D928(void* self)
{
    return 0;
}

extern "C" DB_OVERLAY int fn_8052D930(void* self)
{
    return 0;
}

extern "C" DB_OVERLAY int fn_8052D938(int a, int b, int c, int d)
{
    return d;
}

extern "C" DB_OVERLAY float fn_8052D940()
{
    float r;
    return r = lbl_805FE1D0;
}

extern "C" DB_OVERLAY void fn_8052D95C()
{
}

extern "C" DB_OVERLAY void fn_8052D960()
{
}

extern "C" DB_OVERLAY void fn_8052D964(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C << 3);
}

extern "C" DB_OVERLAY char* fn_8052D9C0(Unk80071604* self, int i)
{
    return self->m24 + (i << 3);
}

extern "C" DB_OVERLAY char* fn_8052D9D0(Unk80071604* self, int i)
{
    return self->m24 + (i << 3);
}

extern "C" DB_OVERLAY void* fn_8052DC60(void* self, const void* src)
{
    fn_803FFA60(self, src, 8);
    return self;
}

extern "C" DB_OVERLAY Unk8052DC94_Out* fn_8052DC94(Unk8052DC94_Out* self, Unk8052CA60_Rec* src)
{
    unsigned short ha = fn_80329FA0(1).m2;
    unsigned short hb = fn_80329FA0(src->f0).m2;
    self->b0 = hb - ha;
    self->fa = src->f11;
    self->fb = src->f12;
    return self;
}

extern "C" DB_OVERLAY int fn_8052DD18()
{
    return 3;
}

extern "C" DB_OVERLAY int fn_8052DD20(int i)
{
    Unk8052DD20_Tri t = *(Unk8052DD20_Tri*)lbl_805FE1D4;
    return t.w[i];
}

extern "C" DB_OVERLAY void fn_8052DD58(Unk8052DD58_Ent* self)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    fn_8040074C(&self->mC, 4);
    fn_8040074C(&self->m10, 4);
}

extern "C" DB_OVERLAY void fn_8052DDA8(int* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, self + 1, 4);
    io->v08(a, self + 2, 4);
    io->v08(a, self + 3, 4);
    io->v08(a, self + 4, 4);
}

extern "C" DB_OVERLAY void fn_8052DE88(Unk8052DE88_Rec* self, int v)
{
    self->mC_flag = 1;
    self->m12 = v;
}

extern "C" DB_OVERLAY void fn_8052DE9C(Unk8052DD58_Set* self)
{
    self->m0 = 0;
    unsigned i = 0;
    Unk8052DD58_Ent* p = self->m4;
    do {
        fn_8052DD58(p);
        i++;
        p++;
    } while (i <= 31);
}

extern "C" DB_OVERLAY int fn_8052DEE8(Unk8052DD58_Set* self, Unk8052DD58_Ent* src)
{
    int ret = -1;
    if (self->m0 == 32) {
        unsigned best = 0;
        unsigned bv = (unsigned)-1;
        unsigned i = 0;
        Unk8052DD58_Ent* q = self->m4;
        for (; i < self->m0; i++, q++) {
            unsigned v = q->m12;
            if (v != 0 && v < bv) {
                bv = v;
                best = i;
            }
        }
        fn_8052DFDC(self, best);
    }
    if ((unsigned)self->m0 <= 31) {
        ret = self->m0;
        self->m4[self->m0] = *src;
        self->m0++;
    }
    return ret;
}

extern "C" DB_OVERLAY void fn_8052DFDC(Unk8052DD58_Set* self, unsigned i)
{
    unsigned last = self->m0 - 1;
    unsigned j = i;
    for (; j < last; j++)
        self->m4[j] = self->m4[j + 1];
    fn_8052DD58(&self->m4[j]);
    self->m0--;
}

extern "C" DB_OVERLAY void fn_8052E07C(Unk8052DD58_Set* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    unsigned i = 0;
    do {
        self->m4[i].v10(a, io);
        i++;
    } while (i <= 31);
}

/* near-miss: ours builds a frame (r30) for the ninth argument; retail stays in caller-saved registers
 * (statement order searched with a hill climb, best 22 slots). */
extern "C" DB_OVERLAY void fn_8052E10C(Unk8052DD58_Ent* self, char a, int b, int c, int d, int e, int f, int g, char h, int i)
{
    self->mC.a = a;
    self->m0 = b;
    self->mC.h = h;
    self->mC.e = e;
    self->mC.f = f;
    self->mC.g = g;
    self->m4 = c;
    self->m8 = d;
    self->mC.p = 0;
    self->m10 = i;
    self->m12 = 0;
}

extern "C" DB_OVERLAY void fn_8052E158(Unk8052DD58_Ent* self, char a, int b, int c, int d, unsigned e, unsigned f, unsigned g, int h)
{
    fn_8052E10C(self, a, b, c, d, e & 0x3F, (e >> 6) & 0x3F, f & 0x3F, g & 0x3F, h);
}

extern "C" DB_OVERLAY Unk8052DD58_Ent* fn_8052E198(Unk8052DD58_Ent* self, char a, int b, int c, int d, int e, int f, int g, char h, int i)
{
    *(const void**)((char*)self + 0x14) = lbl_806841F8;
    fn_8052DD58(self);
    *(const void**)((char*)self + 0x14) = lbl_80682810;
    fn_8052E10C(self, a, b, c, d, e, f, g, h, i);
    return self;
}

extern "C" DB_OVERLAY Unk8052DD58_Ent* fn_8052E234(Unk8052DD58_Ent* self, char a, int b, int c, int d, unsigned e, unsigned f, unsigned g, int h)
{
    *(const void**)((char*)self + 0x14) = lbl_806841F8;
    fn_8052DD58(self);
    *(const void**)((char*)self + 0x14) = lbl_80682810;
    fn_8052E158(self, a, b, c, d, e, f, g, h);
    return self;
}

extern "C" DB_OVERLAY Unk8052DD58_Ent* fn_8052E2C4(Unk8052DD58_Ent* self, char a, int b, int c, int d, unsigned e, unsigned f, unsigned g, char h, int i)
{
    *(const void**)((char*)self + 0x14) = lbl_806841F8;
    fn_8052DD58(self);
    *(const void**)((char*)self + 0x14) = lbl_80682810;
    fn_8052E158(self, a, b, (d << 16) | c, e, f, g, h, i);
    return self;
}

extern "C" DB_OVERLAY Unk8052DD58_Ent* fn_8052E360(Unk8052DD58_Ent* self, char a, int b, int c, int d, int e, int f, int g, char h, char h2, int i)
{
    *(const void**)((char*)self + 0x14) = lbl_806841F8;
    fn_8052DD58(self);
    *(const void**)((char*)self + 0x14) = lbl_80682810;
    fn_8052E10C(self, a, b, (d << 16) | c, e, f, g, h, h2, i);
    return self;
}

extern "C" DB_OVERLAY Unk8052E408_Obj* fn_8052E408(Unk8052E408_Obj* self)
{
    fn_80360AB4(self);
    self->m14 = lbl_80682810;
    return self;
}

extern "C" DB_OVERLAY Unk8052DD58_Ent* fn_8052E444(Unk8052DD58_Ent* self, char a)
{
    *(const void**)((char*)self + 0x14) = lbl_806841F8;
    fn_8052DD58(self);
    *(const void**)((char*)self + 0x14) = lbl_80682810;
    fn_8052E10C(self, a, 0, 0, 0, 0, 0, 0, 0, 0);
    return self;
}
