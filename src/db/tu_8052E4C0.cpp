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

extern "C" DB_OVERLAY float fn_8052EE08()
{
    return lbl_805FE458;
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
