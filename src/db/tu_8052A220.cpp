/*
 * Database overlay code, .database_codeoverlay 0x8052A220-0x8052CA60 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8052A220.h"
#include "game/clampiter.h"

extern const float lbl_805FDC3C;
extern const float lbl_805FDC40;
extern const float lbl_805FDC44;
extern const float lbl_805FDC48;
extern const float lbl_805FDC50[];
extern const float lbl_805FDC58;
extern const float lbl_805FDC5C;
extern const float lbl_805FDC60;
extern float lbl_805FDC64;
extern const float lbl_805FDC68;
extern int lbl_806228B8[];
extern int lbl_805FDF40[];
extern int lbl_806228D0[];
extern int lbl_805FDF78[];
extern int lbl_806228E0[];
extern int lbl_805FDFA0[];
extern int lbl_806228F0[];
extern int lbl_805FDFC4[];
extern int lbl_806228F8[];
extern int lbl_805FDFDC[];
extern "C" void fn_8052C694(Unk8052B978_Tbl* self, int a, int b);
extern "C" void fn_80378FB0(char** p, int a, int b);
extern "C" int fn_8052BE28(Unk8052B978_Tbl* self, int a, int b, int c, int d, int e);
extern "C" void fn_8052BA70(Unk8052B978_Tbl* self);
extern "C" void fn_8052B644(Unk8052B5C4_Ent* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_803792AC(char** p, int* n);
extern "C" double fn_80410634(double x);
extern "C" int fn_8052A35C(Unk8052A220_PalData* self, float a, float b);
extern "C" float fn_8052A3C0(Unk8052A220_PalData* self, float a, int b);
extern "C" void fn_8052A220(Unk8052A220_PalData* p);
extern "C" void* fn_803FFA60(void* d, const void* s, unsigned n);

/* Q18 types */
struct Db8052A220_S12 {
    int w0;
    int w1;
    int w2;
};
/* end Q18 types */

extern "C" {
/* Q18 protos */
void fn_8052A220(Unk8052A220_PalData* p);
int fn_8052A35C(Unk8052A220_PalData* self, float a, float b);
float fn_8052A3C0(Unk8052A220_PalData* self, float a, int b);
void fn_8052A404(Unk8052A220_PalData* p, float v, unsigned idx);
float fn_8052A894(Unk8052A220_PalData* p, unsigned idx);
void fn_8052AD9C(Unk8052A220_Pal* self, int a, Unk80070DDC_Stream* io);
void fn_8052ADDC(Unk8052A220_Pal* self);
void fn_8052AE1C(Unk8052A220_Pal* self, int a, Unk80070DDC_Stream* io);
void fn_8052B1DC(Unk8052B1DC_Sub* p);
void fn_8052B204(Unk8052B1DC_Sub* self, int a, Unk80070DDC_Stream* io);
Unk8052A220_PalData* fn_8052B568(Unk8052A220_PalData* self, const Unk8052A220_PalData* src);
void fn_8052B59C(Unk8052B5C4_Ent* p);
void fn_8052B5C4(Unk8052B5C4_Ent* e, int v);
void fn_8052B5E8(Unk8052B5C4_Ent* e, int v);
void fn_8052B624(Unk8052B5C4_Ent* e, int v);
void fn_8052B644(Unk8052B5C4_Ent* self, int a, Unk80070DDC_Stream* io);
Unk8052B978_Tbl* fn_8052B978(Unk8052B978_Tbl* self, int n);
void fn_8052BA1C(Unk8052B978_Tbl* self, int chrg);
void fn_8052BA70(Unk8052B978_Tbl* self);
void fn_8052BAA8(Unk8052B978_Tbl* self, int idx);
void fn_8052BAFC(Unk8052B978_Tbl* self, int idx);
void fn_8052BB50(Unk8052B978_Tbl* self, int idx);
void fn_8052BBA4(Unk8052B978_Tbl* self, int idx);
void fn_8052BBF8(Unk8052B978_Tbl* self, int idx);
void fn_8052BC4C(Unk8052B978_Tbl* self, int v);
unsigned fn_8052BCC8(Unk8052B978_Tbl* self);
int fn_8052BD40(Unk8052B978_Tbl* self);
Db8052A220_S12 fn_8052BD58(Unk8052B978_Tbl* t);
int fn_8052BE28(Unk8052B978_Tbl* self, int a, int b, int c, int d, int e);
void fn_8052BED8(Unk8052B978_Tbl* self, int i);
int fn_8052C390(Unk8052B978_Tbl* self, int key);
void fn_8052C494(Unk8052B978_Tbl* self, int a, Unk80070DDC_Stream* io);
void fn_8052C520(Unk8052B978_Tbl* self, char** pp, Unk80070DDC_Stream* io);
void fn_8052C9B0(char** pp);
void fn_8052CA10(char** pp);
/* end Q18 protos */
}

extern "C" DB_OVERLAY void fn_8052A220(Unk8052A220_PalData* p)
{
    int v = fn_8052A35C(p, lbl_805FDC3C, lbl_805FDC40);
    v = v > 31 ? 31 : (v >? 0);
    p->f0 = v;
    p->f1 = v;
    p->f2 = v;
    p->f3 = v;
    p->f4 = v;
    p->f5 = v;
    p->f6 = v;
    p->f7 = v;
    p->f8 = v;
    p->f9 = v;
    p->f10 = v;
    p->f11 = v;
    p->f12 = v;
    p->f13 = v;
    p->f14 = v;
    p->f15 = v;
    p->f16 = v;
    p->f17 = v;
    p->f18 = v;
    p->f19 = v;
    p->f20 = v;
    p->f21 = v;
    p->f22 = v;
    p->f23 = v;
    p->f24 = v;
    p->f25 = v;
    p->f26 = v;
    p->f27 = v;
    p->f28 = v;
    p->f29 = v;
    p->f30 = v;
    p->f31 = v;
    p->f32 = v;
    p->f33 = v;
    p->f34 = v;
    p->f35 = v;
    p->f36 = v;
    p->f37 = v;
    p->f38 = v;
    p->f39 = v;
    p->f40 = v;
}

extern "C" DB_OVERLAY int fn_8052A35C(Unk8052A220_PalData* self, float a, float b)
{
    float t = (a - b) * lbl_805FDC44;
    return (int)(float)fn_80410634(t + lbl_805FDC48);
}

extern "C" DB_OVERLAY float fn_8052A3C0(Unk8052A220_PalData* self, float a, int b)
{
    return b * 0.1f + a;
}

extern "C" DB_OVERLAY void fn_8052A404(Unk8052A220_PalData* p, float v, unsigned idx)
{
    int c = fn_8052A35C(p, v, lbl_805FDC5C);
    c = c > 31 ? 31 : (c >? 0);
    switch (idx) {
    case 0:
        p->f0 = c;
        break;
    case 1:
        p->f1 = c;
        break;
    case 2:
        p->f2 = c;
        break;
    case 3:
        p->f3 = c;
        break;
    case 4:
        p->f4 = c;
        break;
    case 5:
        p->f5 = c;
        break;
    case 6:
        p->f6 = c;
        break;
    case 7:
        p->f7 = c;
        break;
    case 8:
        p->f8 = c;
        break;
    case 9:
        p->f9 = c;
        break;
    case 10:
        p->f10 = c;
        break;
    case 11:
        p->f11 = c;
        break;
    case 12:
        p->f12 = c;
        break;
    case 13:
        p->f13 = c;
        break;
    case 14:
        p->f14 = c;
        break;
    case 15:
        p->f15 = c;
        break;
    case 16:
        p->f16 = c;
        break;
    case 17:
        p->f17 = c;
        break;
    case 18:
        p->f18 = c;
        break;
    case 19:
        p->f19 = c;
        break;
    case 20:
        p->f20 = c;
        break;
    case 21:
        p->f21 = c;
        break;
    case 22:
        p->f22 = c;
        break;
    case 23:
        p->f23 = c;
        break;
    case 24:
        p->f24 = c;
        break;
    case 25:
        p->f25 = c;
        break;
    case 26:
        p->f26 = c;
        break;
    case 27:
        p->f27 = c;
        break;
    case 28:
        p->f28 = c;
        break;
    case 29:
        p->f29 = c;
        break;
    case 30:
        p->f30 = c;
        break;
    case 31:
        p->f31 = c;
        break;
    case 32:
        p->f32 = c;
        break;
    case 33:
        p->f33 = c;
        break;
    case 34:
        p->f34 = c;
        break;
    case 35:
        p->f35 = c;
        break;
    case 36:
        p->f36 = c;
        break;
    case 37:
        p->f37 = c;
        break;
    case 38:
        p->f38 = c;
        break;
    case 39:
        p->f39 = c;
        break;
    case 40:
        p->f40 = c;
        break;
    }
}

extern "C" DB_OVERLAY float fn_8052A894(Unk8052A220_PalData* p, unsigned idx)
{
    float r = lbl_805FDC60;
    float t;
    switch (idx) {
    case 0:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f0);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 1:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f1);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 2:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f2);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 3:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f3);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 4:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f4);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 5:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f5);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 6:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f6);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 7:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f7);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 8:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f8);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 9:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f9);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 10:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f10);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 11:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f11);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 12:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f12);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 13:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f13);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 14:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f14);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 15:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f15);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 16:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f16);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 17:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f17);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 18:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f18);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 19:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f19);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 20:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f20);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 21:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f21);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 22:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f22);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 23:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f23);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 24:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f24);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 25:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f25);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 26:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f26);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 27:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f27);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 28:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f28);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 29:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f29);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 30:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f30);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 31:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f31);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 32:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f32);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 33:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f33);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 34:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f34);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 35:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f35);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 36:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f36);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 37:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f37);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 38:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f38);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 39:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f39);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    case 40:
        t = fn_8052A3C0(p, lbl_805FDC64, p->f40);
        r = !(t > lbl_805FDC68) ? (t >? lbl_805FDC64) : lbl_805FDC68;
        break;
    }
    return r;
}

extern "C" DB_OVERLAY void fn_8052AD9C(Unk8052A220_Pal* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 0x1C);
}

extern "C" DB_OVERLAY void fn_8052ADDC(Unk8052A220_Pal* self)
{
    Unk8052A220_Pal* p = self;
    Unk8052A220_Pal* e = self + 24;
    do {
        fn_8052A220(p);
        p++;
    } while (p <= e);
}

extern "C" DB_OVERLAY void fn_8052AE1C(Unk8052A220_Pal* self, int a, Unk80070DDC_Stream* io)
{
    Unk8052A220_Pal* p = self;
    Unk8052A220_Pal* e = self + 24;
    do {
        p->v10(a, io);
        p++;
    } while (p <= e);
}

extern "C" DB_OVERLAY void fn_8052B1DC(Unk8052B1DC_Sub* p)
{
    fn_803FFC58(p, 0, 0xC);
}

extern "C" DB_OVERLAY void fn_8052B204(Unk8052B1DC_Sub* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, &self->m4, 8);
}

extern "C" DB_OVERLAY Unk8052A220_PalData* fn_8052B568(Unk8052A220_PalData* self, const Unk8052A220_PalData* src)
{
    fn_803FFA60(self, src, 0x1C);
    return self;
}

extern "C" DB_OVERLAY void fn_8052B59C(Unk8052B5C4_Ent* p)
{
    fn_803FFC58(p, 0, 0x1C);
}

extern "C" DB_OVERLAY void fn_8052B5C4(Unk8052B5C4_Ent* e, int v)
{
    e->m0 = v > 0xFFFF ? 0xFFFF : (v >? 0);
}

extern "C" DB_OVERLAY void fn_8052B5E8(Unk8052B5C4_Ent* e, int v)
{
    if (v == 0)
        v = 0x21C;
    v -= 0x21C;
    e->f2 = v > 0x383 ? 0x383 : (v >? 0);
}

extern "C" DB_OVERLAY void fn_8052B624(Unk8052B5C4_Ent* e, int v)
{
    e->f3 = v % 2;
}

extern "C" DB_OVERLAY void fn_8052B644(Unk8052B5C4_Ent* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    Unk8006A138_It<1> it(0);
    int i = 0;
    while (i <= 1) {
        fn_8052B204((Unk8052B1DC_Sub*)((char*)self + (i * 0xC + 4)), a, io);
        i = it.Next();
    }
}

extern "C" DB_OVERLAY Unk8052B978_Tbl* fn_8052B978(Unk8052B978_Tbl* self, int n)
{
    self->m0 = n;
    self->m4 = 0;
    self->m8 = 0;
    self->m8 = new (0) Unk8052B5C4_Ent[n];
    fn_8052BA70(self);
    return self;
}

extern "C" DB_OVERLAY void fn_8052BA1C(Unk8052B978_Tbl* self, int chrg)
{
    if (self->m8) {
        delete[] self->m8;
        self->m8 = 0;
    }
    if (chrg & 1)
        delete self;
}

extern "C" DB_OVERLAY void fn_8052BA70(Unk8052B978_Tbl* self)
{
    self->m4 = 0;
    fn_8040074C(self->m8, self->m0 * 0x1C);
}

extern "C" DB_OVERLAY void fn_8052BAA8(Unk8052B978_Tbl* self, int idx)
{
    fn_8052BA70(self);
    fn_8052C694(self, lbl_806228B8[idx], lbl_805FDF40[idx]);
}

extern "C" DB_OVERLAY void fn_8052BAFC(Unk8052B978_Tbl* self, int idx)
{
    fn_8052BA70(self);
    fn_8052C694(self, lbl_806228D0[idx], lbl_805FDF78[idx]);
}

extern "C" DB_OVERLAY void fn_8052BB50(Unk8052B978_Tbl* self, int idx)
{
    fn_8052BA70(self);
    fn_8052C694(self, lbl_806228E0[idx], lbl_805FDFA0[idx]);
}

extern "C" DB_OVERLAY void fn_8052BBA4(Unk8052B978_Tbl* self, int idx)
{
    fn_8052BA70(self);
    int* a = lbl_806228F0;
    int* b = lbl_805FDFC4;
    fn_8052C694(self, a[idx], b[idx]);
}

extern "C" DB_OVERLAY void fn_8052BBF8(Unk8052B978_Tbl* self, int idx)
{
    fn_8052BA70(self);
    int* a = lbl_806228F8;
    int* b = lbl_805FDFDC;
    fn_8052C694(self, a[idx], b[idx]);
}

extern "C" DB_OVERLAY void fn_8052BC4C(Unk8052B978_Tbl* self, int v)
{
    int a = self->m8->m0;
    if (a != v) {
        int d = v - a;
        unsigned i;
        for (i = 0; i < self->m4; i++) {
            int v = self->m8[i].m0 + d;
            fn_8052B5C4(&self->m8[i], v);
        }
    }
}

inline int EntUsed(Unk8052B5C4_Ent* e)
{
    int r = 1;
    if (e->f4 == 0)
        r = 0;
    return r;
}

extern "C" DB_OVERLAY unsigned fn_8052BCC8(Unk8052B978_Tbl* self)
{
    unsigned n = self->m4;
    unsigned lo = 0;
    unsigned hi = n;
    while (lo < n && EntUsed(&self->m8[lo]) == 1) {
        unsigned mid = (hi + lo) >> 1;
        if (EntUsed(&self->m8[mid]) == 1)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

extern "C" DB_OVERLAY int fn_8052BD40(Unk8052B978_Tbl* self)
{
    int n = self->m4;
    int r = -1;
    if (n != 0)
        r = n - 1;
    return r;
}

extern "C" DB_OVERLAY Db8052A220_S12 fn_8052BD58(Unk8052B978_Tbl* t)
{
    Db8052A220_S12 r;
    Db8052A220_S12* q = &r;
    r.w0 = -1;
    q->w1 = -1;
    q->w2 = 1;
    unsigned n = t->m4;
    unsigned idx = fn_8052BCC8(t);
    if (idx < n) {
        r.w2 = 0;
        Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)(idx * 0x1C + (int)t->m8);
        r.w0 = e->m0;
        r.w1 = e->f2 + 0x21C;
    } else {
        r.w2 = 1;
        if (n != 0) {
            Unk8052B5C4_Ent* e = (Unk8052B5C4_Ent*)((n - 1) * 0x1C + (int)t->m8);
            r.w0 = e->m0;
            r.w1 = e->f2 + 0x21C;
        } else {
            r.w0 = n;
            r.w1 = n;
        }
    }
    return r;
}

extern "C" DB_OVERLAY int fn_8052BE28(Unk8052B978_Tbl* self, int a, int b, int c, int d, int e)
{
    self->m8[self->m4].m4[0].m0 = a;
    self->m8[self->m4].m4[1].m0 = b;
    fn_8052B5C4(&self->m8[self->m4], c);
    fn_8052B5E8(&self->m8[self->m4], d);
    fn_8052B624(&self->m8[self->m4], e);
    return self->m4++;
}

extern "C" DB_OVERLAY void fn_8052BED8(Unk8052B978_Tbl* self, int i)
{
    Unk8052B5C4_Ent* e = &self->m8[i];
    Unk8052B1DC_Sub* s = e->m4;
    e->f4 = 8;
    if (s->m4 == e->m4[1].m4)
        s->m4++;
}

inline int KeyAt(Unk8052B978_Tbl* t, int i)
{
    return *(unsigned short*)((char*)t->m8 + i * 0x1C);
}

/* near-miss: lower-bound binary search over the 0x1C-byte entries (u16 key at +0). Retail keeps hi in
 * r3 (also the return register), enters the loop without folding lo = 0, and tests (hi - lo) >> 1
 * at the loop head; ours folds the first test and keeps hi in r11 (62 vs 65 insns). Tried for(;;)
 * with an inner test, while with goto, and a result variable. */
extern "C" DB_OVERLAY int fn_8052C390(Unk8052B978_Tbl* self, int key)
{
    int lo = 0;
    int hi = self->m4;
    if (hi != 0 && !(key > KeyAt(self, hi - 1)) && !(key < KeyAt(self, 0))) {
        int v;
        int mid;
        unsigned d;
        while ((d = (unsigned)(hi - lo) >> 1) > 0) {
            mid = lo + d;
            v = KeyAt(self, mid);
            if (v > key)
                hi = mid;
            else if (v < key)
                lo = mid;
            else
                goto found;
            if (hi == lo)
                goto found;
        }
        if (KeyAt(self, hi) == key)
            return hi;
        if (KeyAt(self, lo) == key)
            return lo;
        return -1;
    found:
        if (v != key)
            return -1;
        if ((unsigned)mid > (unsigned)lo) {
            int j;
            for (j = mid; j >= 0; j--) {
                if (KeyAt(self, j) != key)
                    return j + 1;
            }
            return 0;
        }
        return mid;
    }
    return -1;
}

extern "C" DB_OVERLAY void fn_8052C494(Unk8052B978_Tbl* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, &self->m4, 4);
    unsigned i;
    for (i = 0; i < (unsigned)self->m0; i++)
        fn_8052B644(&self->m8[i], a, io);
}

extern "C" int fn_804089B4(char* dst, const char* fmt, ...);
extern "C" int fn_80409DAC(const char* s);
extern "C" int fn_8040B6A0(const char* s);
extern const char* lbl_806228B0;
extern const char* lbl_806228B4;
extern "C" void fn_8052B6DC(Unk8052B5C4_Ent* e, char** pp, Unk80070DDC_Stream* io);
extern "C" void fn_8052C9B0(char** pp);
extern "C" void fn_8052CA10(char** pp);

extern "C" DB_OVERLAY void fn_8052C520(Unk8052B978_Tbl* self, char** pp, Unk80070DDC_Stream* io)
{
    char* cur = *pp;
    if (io->v10() == 1) {
        fn_804089B4(cur, lbl_806228B0, self->m4);
        cur += fn_8040B6A0(cur);
    } else {
        fn_8052C9B0(&cur);
        self->m4 = fn_80409DAC(cur);
        fn_8052CA10(&cur);
    }
    *pp = cur;
    unsigned i;
    for (i = 0; i < (unsigned)self->m0; i++)
        fn_8052B6DC(&self->m8[i], pp, io);
    if (io->v10() == 1) {
        cur = *pp;
        fn_804089B4(cur, lbl_806228B4);
        cur += fn_8040B6A0(cur);
    } else {
        cur = *pp;
        fn_8052CA10(&cur);
        fn_8052CA10(&cur);
        fn_8052CA10(&cur);
        fn_8052CA10(&cur);
    }
    *pp = cur;
}

extern "C" DB_OVERLAY void fn_8052C9B0(char** pp)
{
    fn_80378FB0(pp, 0x40, 0x20);
    while (**pp == 0x20)
        ++*pp;
}

extern "C" DB_OVERLAY void fn_8052CA10(char** pp)
{
    int n = 0x40;
    fn_803792AC(pp, &n);
    if (**pp == 10)
        ++*pp;
}
