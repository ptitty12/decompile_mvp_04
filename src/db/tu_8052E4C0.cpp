/*
 * Database overlay code, .database_codeoverlay 0x8052E4C0-0x8052FF10 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8052A220.h"
#include "game/clampiter.h"

extern char lbl_80684778[];
extern char lbl_806846F0[];
extern char lbl_806846C0[];
extern const char lbl_805FE454[];
extern const float lbl_805FE458;
extern const float lbl_805FE45C;
extern "C" void fn_8052E504(Unk8052E4C0_Obj* self);
extern "C" void fn_8052E560(Unk8052E4C0_Obj* self, int a, int b, int c, int d, int e);
extern "C" void fn_8052E5FC(Unk8052E4C0_Obj* self);
extern "C" void fn_8052FB70(Unk8052FA84_List* self);
extern "C" void* fn_803774A8(unsigned n, int heap);

extern "C" DB_OVERLAY Unk8052E4C0_Obj* fn_8052E4C0(Unk8052E4C0_Obj* self)
{
    self->flag = 0;
    self->n = 0;
    fn_8052E504(self);
    fn_8052E5FC(self);
    return self;
}

extern "C" DB_OVERLAY void fn_8052E504(Unk8052E4C0_Obj* self)
{
    Unk8006A138_It<9> it(0);
    int i = 0;
    do {
        unsigned char j = 0;
        do {
            self->m0[it.v][j] = 0;
            j++;
        } while (j <= 9);
        i = it.Next();
    } while (i <= 9);
}

extern "C" DB_OVERLAY void fn_8052E560(Unk8052E4C0_Obj* self, int a, int b, int c, int d, int e)
{
    if (self->n <= 24) {
        self->m190[self->n].m0 = a;
        self->m190[self->n].m4 = b;
        self->m190[self->n].m8 = c;
        self->m190[self->n].mC = e;
        self->m190[self->n].m10 = d;
        self->n = self->n + 1;
    }
}

extern "C" DB_OVERLAY void fn_8052E5FC(Unk8052E4C0_Obj* self)
{
    self->n = 0;
    int i;
    for (i = 0; i < 25; i++) {
        self->m190[i].m0 = 0;
        self->m190[i].m4 = 13;
        self->m190[i].m8 = 0;
        self->m190[self->n].mC = 0;
    }
}

extern "C" DB_OVERLAY Unk80071604* fn_8052E654(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_80684778;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 0x54, 0);
    self->m14 = fn_800736EC(lbl_805FE454);
    return self;
}

extern "C" DB_OVERLAY void fn_8052E6BC(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684778;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_8052E718(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 0x54, 0x54);
}

extern "C" DB_OVERLAY unsigned fn_8052E9C4(Unk80071604* self, unsigned kind, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (kind) {
        case 0:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m0;
            break;
        case 1:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m4;
            break;
        case 2:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m8;
            break;
        case 3:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].mC;
            break;
        case 4:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m10;
            break;
        case 5:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m14;
            break;
        case 6:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m18;
            break;
        case 7:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m1C;
            break;
        case 8:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m20;
            break;
        case 9:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m24;
            break;
        case 10:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m28;
            break;
        case 11:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m2C;
            break;
        case 12:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m30;
            break;
        case 13:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].m34;
            break;
        case 14:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f14;
            break;
        case 15:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f15;
            break;
        case 16:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f16;
            break;
        case 17:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f17;
            break;
        case 18:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f18;
            break;
        case 19:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f19;
            break;
        case 20:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f20;
            break;
        case 21:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s21;
            break;
        case 22:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s22;
            break;
        case 23:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s23;
            break;
        case 24:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s24;
            break;
        case 25:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s25;
            break;
        case 26:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s26;
            break;
        case 27:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s27;
            break;
        case 28:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s28;
            break;
        case 29:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s29;
            break;
        case 30:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s30;
            break;
        case 31:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].s31;
            break;
        case 32:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f32;
            break;
        case 33:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f33;
            break;
        case 34:
            r = ((Unk8052E9C4_Rec*)self->m24)[i].f34;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY float fn_8052EE08()
{
    return lbl_805FE458;
}

extern "C" DB_OVERLAY void fn_8052EE14(Unk80071604* self, unsigned kind, unsigned i, unsigned v)
{
    if (i < self->m1C) {
        switch (kind) {
        case 0: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m0 = v;
            break;
        }
        case 1: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m4 = v;
            break;
        }
        case 2: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m8 = v;
            break;
        }
        case 3: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->mC = v;
            break;
        }
        case 4: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m10 = v;
            break;
        }
        case 5: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m14 = v;
            break;
        }
        case 6: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m18 = v;
            break;
        }
        case 7: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m1C = v;
            break;
        }
        case 8: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m20 = v;
            break;
        }
        case 9: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m24 = v;
            break;
        }
        case 10: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m28 = v;
            break;
        }
        case 11: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m2C = v;
            break;
        }
        case 12: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m30 = v;
            break;
        }
        case 13: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            e->m34 = v;
            break;
        }
        case 14: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x1)
                v = 0x1;
            e->f14 = v;
            break;
        }
        case 15: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x1f)
                v = 0x1f;
            e->f15 = v;
            break;
        }
        case 16: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x7)
                v = 0x7;
            e->f16 = v;
            break;
        }
        case 17: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x1)
                v = 0x1;
            e->f17 = v;
            break;
        }
        case 18: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x3)
                v = 0x3;
            e->f18 = v;
            break;
        }
        case 19: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x7)
                v = 0x7;
            e->f19 = v;
            break;
        }
        case 20: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x1)
                v = 0x1;
            e->f20 = v;
            break;
        }
        case 21: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s21 = v;
            break;
        }
        case 22: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s22 = v;
            break;
        }
        case 23: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s23 = v;
            break;
        }
        case 24: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s24 = v;
            break;
        }
        case 25: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s25 = v;
            break;
        }
        case 26: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s26 = v;
            break;
        }
        case 27: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s27 = v;
            break;
        }
        case 28: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s28 = v;
            break;
        }
        case 29: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s29 = v;
            break;
        }
        case 30: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s30 = v;
            break;
        }
        case 31: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0xffff)
                v = 0xffff;
            e->s31 = v;
            break;
        }
        case 32: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x7fff)
                v = 0x7fff;
            e->f32 = v;
            break;
        }
        case 33: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x7fff)
                v = 0x7fff;
            e->f33 = v;
            break;
        }
        case 34: {
            Unk8052E9C4_Rec* e = (Unk8052E9C4_Rec*)(i * 0x54 + (int)self->m24);
            if (v > 0x3)
                v = 0x3;
            e->f34 = v;
            break;
        }
        }
    }
}

extern "C" DB_OVERLAY void fn_8052F3F8(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C * 0x54);
}

extern "C" DB_OVERLAY Unk80071604* fn_8052F454(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_806846F0;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C << 4, 0);
    self->m14 = fn_800736EC(lbl_805FE454);
    return self;
}

extern "C" DB_OVERLAY void fn_8052F4BC(Unk80071604* self, int chrg)
{
    self->m20 = lbl_806846F0;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_8052F518(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + (i << 4), 0x10);
}

extern "C" DB_OVERLAY unsigned fn_8052F5CC(Unk80071604* self, unsigned kind, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (kind) {
        case 0:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f0;
            break;
        case 1:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f1;
            break;
        case 2:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f2;
            break;
        case 3:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f3;
            break;
        case 4:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f4;
            break;
        case 5:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f5;
            break;
        case 6:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f6;
            break;
        case 7:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f7;
            break;
        case 8:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f8;
            break;
        case 9:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f9;
            break;
        case 10:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f10;
            break;
        case 11:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f11;
            break;
        case 12:
            r = ((Unk8052F5CC_Rec*)self->m24)[i].f12;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY float fn_8052F790()
{
    return lbl_805FE45C;
}

extern "C" DB_OVERLAY void fn_8052F79C(Unk80071604* self, unsigned kind, unsigned i, unsigned v)
{
    if (i < self->m1C) {
        switch (kind) {
        case 0: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f0 = v;
            break;
        }
        case 1: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f1 = v;
            break;
        }
        case 2: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f2 = v;
            break;
        }
        case 3: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f3 = v;
            break;
        }
        case 4: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f4 = v;
            break;
        }
        case 5: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f5 = v;
            break;
        }
        case 6: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f6 = v;
            break;
        }
        case 7: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f7 = v;
            break;
        }
        case 8: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f8 = v;
            break;
        }
        case 9: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f9 = v;
            break;
        }
        case 10: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7f)
                v = 0x7f;
            e->f10 = v;
            break;
        }
        case 11: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7ff)
                v = 0x7ff;
            e->f11 = v;
            break;
        }
        case 12: {
            int b = (int)self->m24;
            Unk8052F5CC_Rec* e = (Unk8052F5CC_Rec*)(i * 16 + b);
            if (v > 0x7ff)
                v = 0x7ff;
            e->f12 = v;
            break;
        }
        }
    }
}

extern "C" DB_OVERLAY void fn_8052FA28(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C << 4);
}

extern "C" DB_OVERLAY Unk8052FA84_List* fn_8052FA84(Unk8052FA84_List* self, int n)
{
    self->m0 = n;
    self->m4 = 0;
    *(const void**)((char*)self + 8) = lbl_806846C0;
    self->m4 = new (0) Unk8052E4C0_Obj[n];
    fn_8052FB70(self);
    return self;
}

extern "C" DB_OVERLAY void fn_8052FB10(Unk8052FA84_List* self, int chrg)
{
    *(const void**)((char*)self + 8) = lbl_806846C0;
    if (self->m4) {
        delete[] self->m4;
        self->m4 = 0;
    }
    if (chrg & 1)
        delete self;
}

extern "C" DB_OVERLAY void fn_8052FB70(Unk8052FA84_List* self)
{
    unsigned i;
    for (i = 0; i < (unsigned)self->m0; i++)
        self->v10(i);
}

extern "C" DB_OVERLAY void fn_8052FBCC(Unk8052FA84_List* self, unsigned i)
{
    if (i < (unsigned)self->m0) {
        fn_8052E504(self->m4 + i);
        fn_8052E5FC(self->m4 + i);
    }
}

extern "C" DB_OVERLAY int fn_8052FC1C(Unk8052FA84_List* self, int a, int row, int col)
{
    return self->m4->m0[row][col];
}

extern "C" DB_OVERLAY void fn_8052FC34(Unk8052FA84_List* self, int a, int row, int col, int v)
{
    self->m4->m0[row][col] = v;
}

extern "C" DB_OVERLAY unsigned fn_8052FDC8(Unk8052FA84_List* self)
{
    return self->m4->flag;
}

extern "C" DB_OVERLAY void fn_8052FDD8(Unk8052FA84_List* self, int a, int c)
{
    Unk8052E4C0_Obj* o = self->m4;
    int t = 0;
    if (c != 0)
        t = 1;
    o->flag = t;
}

extern "C" DB_OVERLAY unsigned fn_8052FDFC(Unk8052FA84_List* self)
{
    return self->m4->n;
}

extern "C" DB_OVERLAY int fn_8052FE0C(Unk8052FA84_List* self, int a, int i)
{
    return self->m4->m190[i].m0;
}

extern "C" DB_OVERLAY int fn_8052FE20(Unk8052FA84_List* self, int a, int i)
{
    return self->m4->m190[i].m4;
}

extern "C" DB_OVERLAY int fn_8052FE34(Unk8052FA84_List* self, int a, int i)
{
    return self->m4->m190[i].m8;
}

extern "C" DB_OVERLAY int fn_8052FE48(Unk8052FA84_List* self, int a, int i)
{
    return self->m4->m190[i].mC;
}

extern "C" DB_OVERLAY int fn_8052FE5C(Unk8052FA84_List* self, int a, int i)
{
    return self->m4->m190[i].m10;
}

extern "C" DB_OVERLAY void fn_8052FE70(Unk8052FA84_List* self)
{
    fn_8052E5FC(self->m4);
}

extern "C" DB_OVERLAY void fn_8052FE94(Unk8052FA84_List* self, int a, int b, int c, int d, int e, int f)
{
    fn_8052E560(self->m4, b, c, d, e, f);
}

extern "C" DB_OVERLAY void fn_8052FECC(Unk8052FA84_List* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self->m4, self->m0 * 0x388);
}
