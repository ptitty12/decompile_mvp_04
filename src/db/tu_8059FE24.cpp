/*
 * Database overlay code, .database_codeoverlay 0x8059FE24-0x805A1A9C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/db_80596D88.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_80684800[];

extern "C" void fn_80377408(void* p);

struct A1A0 { char pad[0x1A0]; char m[1]; };

struct Db8059FE24_Bits {
    char pad[0x70];
    int m70[1];
};

//@8059FE24
extern "C" DB_OVERLAY void fn_8059FE24(Db8059FE24_Bits* self, unsigned i)
{
    self->m70[i >> 5] |= 1 << (i & 31);
}

//@8059FE48
extern "C" DB_OVERLAY int fn_8059FE48(Db8059FE24_Bits* self, unsigned i)
{
    int r = 0;
    if ((self->m70[i >> 5] >> (i & 31)) & 1)
        r = 1;
    return r;
}

extern "C" {
void fn_8059A728(void* self, int a, Unk80070DDC_Stream* io);
void fn_8059AA7C(void* self, int a, Unk80070DDC_Stream* io);
void fn_800A724C(char* o, int a, Unk80070DDC_Stream* io);
void fn_8059AD30(void* self);
void fn_8059AC0C(void* self, void* b, int c);
void fn_8059BCD4(void* self, int a, int c);
void fn_8059ADF8(void* self, void* b, int c);
}

struct Db8059FE70_Obj {
    short m0[8];
    short m10;
    char pad12[2];
    char m14[0x28];
    char m3C[0x18];
    char m54[0x1C];
    char m70[0x10];
    char m80[6][0x28];
    char m170[4][0xC];
    char pad1A0[1];
};

//@8059FE70
extern "C" DB_OVERLAY void fn_8059FE70(Db8059FE70_Obj* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self->m14, 0x28);
    io->v08(a, self->m54, 0x1C);
    io->v08(a, self->m3C, 0x18);
    io->v08(a, self->m70, 0x10);
    unsigned i;
    for (i = 0; i < 6; i++)
        fn_8059AA7C(self->m80[i], a, io);
    for (i = 0; i < 4; i++)
        fn_8059A728(self->m170[i], a, io);
    for (i = 0; i < 8; i++)
        io->v08(a, &self->m0[i], 2);
    if (io->v10() == 0 && io->m0 == 0)
        self->m10 = 0;
    fn_800A724C((char*)self + 0x1A0, a, io);
}

extern "C" DB_OVERLAY char* fn_8059FFF8(A1A0* p)
{
    return p->m;
}

struct Db805A0000_Obj {
    int m0;
    int m4;
    int m8[4];
    char pad18[0x6EC * 4];
    char pad1B;
};

struct Db805A0000_Ent {
    char m0[0x6EC];
};

struct Db805A0000_Holder {
    unsigned m0;
    int m4;
    int m8[4];
    Db805A0000_Ent m18[4];
    int m1BC8;
};

extern const char lbl_806012B8[];
extern const char lbl_805FEC2C[];
extern "C" int fn_805A00BC(Db805A0000_Holder* self, char* b, int c);

//@805A0000
extern "C" DB_OVERLAY void fn_805A0000(Db805A0000_Holder* self)
{
    char buf[0x14];
    self->m0 = 0;
    self->m1BC8 = -1;
    for (int i = 0; i < 4; i++)
        self->m8[i] = -1;
    for (unsigned u = 0; u < 4; u++)
        fn_8059AD30(&self->m18[u]);
    self->m4 = -1;
    fn_80402EF8(buf, lbl_806012B8);
    int r = fn_805A00BC(self, buf, fn_800736EC(lbl_805FEC2C));
    if (r < (int)self->m0)
        self->m4 = r;
}

//@805A00BC
extern "C" DB_OVERLAY int fn_805A00BC(Db805A0000_Holder* self, char* b, int c)
{
    int r = -1;
    int idx = self->m1BC8;
    if (idx == -1) {
        unsigned n = self->m0;
        if (n <= 3) {
            r = n;
            fn_8059AC0C(&self->m18[r], b, 0);
            fn_8059BCD4(&self->m18[self->m0], 0, c);
            self->m0 = self->m0 + 1;
        }
    } else {
        Db805A0000_Ent* p;
        if ((unsigned)idx < self->m0)
            p = &self->m18[idx];
        else
            p = 0;
        fn_8059ADF8(p, b, c);
        r = self->m1BC8;
    }
    self->m1BC8 = -1;
    return r;
}

//@805A0180
extern "C" DB_OVERLAY void fn_805A0180(Db805A0000_Holder* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, &self->m4, 4);
    io->v08(a, self->m8, 0x10);
    Db805A0000_Ent* p = self->m18;
    int n = 4;
    do {
        fn_8059FE70((Db8059FE70_Obj*)p, a, io);
        p++;
    } while (--n);
    if (io->v10() == 0 && io->m0 == 0)
        self->m1BC8 = -1;
}

extern "C" {
int fn_80403060(const short* s);
void fn_80403144(void* dst, const void* src);
void fn_8040316C(short* dst, const short* src, int n);
}

//@805A04C4
extern "C" DB_OVERLAY void fn_805A04C4(short* dst, const short* src, int n)
{
    if (n == 0)
        n = fn_80403060(src);
    unsigned m = n + 1;
    if (m > 9)
        m = 9;
    fn_8040316C(dst, src, m);
    int k = m - 1;
    dst[k] = 0;
}

//@805A0530
extern "C" DB_OVERLAY void fn_805A0530(const short* src, short* dst, unsigned n)
{
    if (n > (unsigned)fn_80403060(src) || n == 0) {
        fn_80403144(dst, src);
    } else {
        fn_8040316C(dst, src, n);
        dst[n - 1] = 0;
    }
}

struct Db805A05A4_Cell {
    char m0[0x14];
    unsigned char m14;
    unsigned char m15;
    char pad16[2];
    int m18;
    char pad1C[4];
};

//@805A05A4
extern "C" DB_OVERLAY void fn_805A05A4(Db805A05A4_Cell* self)
{
    fn_8040074C(self, 0x14);
    self->m14 = 0;
    self->m15 = 0;
    self->m18 = 0;
}

//@805A05E8
extern "C" DB_OVERLAY void fn_805A05E8(Db805A05A4_Cell* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, &self->m18, 4);
    io->v08(a, &self->m14, 1);
    io->v08(a, &self->m15, 1);
    io->v08(a, self, 0x12);
}

struct Db805A05A4_List {
    unsigned m0;
    Db805A05A4_Cell m4[16];
};

//@805A06A4
extern "C" DB_OVERLAY void fn_805A06A4(Db805A05A4_List* self)
{
    self->m0 = 0;
    for (unsigned i = 0; i < 16; i++)
        fn_805A05A4(&self->m4[i]);
}

//@805A06F0
extern "C" DB_OVERLAY int fn_805A06F0(Db805A05A4_List* self, short* a)
{
    int idx = -1;
    unsigned c = self->m0;
    if (c <= 15) {
        idx = c;
        fn_805A04C4((short*)((char*)self + (idx * 32 + 4)), a, 0);
        self->m0 = self->m0 + 1;
    }
    return idx;
}

//@805A0750
extern "C" DB_OVERLAY void fn_805A0750(Db805A05A4_List* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    for (unsigned i = 0; i < 16; i++)
        fn_805A05E8(&self->m4[i], a, io);
}

extern "C" DB_OVERLAY void fn_805A166C(U* self, int chrg)
{
    PUT(0x1c, lbl_80684800);
    if (chrg & 1)
        fn_80377408(self);
}

//@805A16A0
struct Vc20_5_D { char pad[0x20]; };
//@805A16A0
struct Vc20_5 : Vc20_5_D { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };

extern "C" DB_OVERLAY void fn_805A16A0(Vc20_5* p)
{
    p->v5();
}

extern "C" DB_OVERLAY void fn_805A16D4(Vc20_5* p)
{
    p->v5();
}

extern const char* lbl_80619308;

//@805A1708
extern "C" DB_OVERLAY char* fn_805A1708(int a, int b, int c, char* d)
{
    fn_8040B61C(d, lbl_80619308);
    return d;
}

//@805A1744
struct Vc20_8_D { char pad[0x20]; };
//@805A1744
struct Vc20_8 : Vc20_8_D { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };

extern "C" DB_OVERLAY void fn_805A1744(Vc20_8* p)
{
    p->v8();
}

extern "C" DB_OVERLAY void fn_805A1778()
{
}

extern "C" void fn_80400560(void* p, int n);

extern "C" DB_OVERLAY void fn_805A177C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A17A0(Vc20_5* p)
{
    p->v5();
}

extern "C" DB_OVERLAY void fn_805A17D4(Vc20_5* p)
{
    p->v5();
}

//@805A1808
extern "C" DB_OVERLAY char* fn_805A1808(int a, int b, int c, char* d)
{
    fn_8040B61C(d, lbl_80619308);
    return d;
}

extern "C" DB_OVERLAY void fn_805A1844(Vc20_8* p)
{
    p->v8();
}

extern "C" DB_OVERLAY void fn_805A1878()
{
}

extern "C" DB_OVERLAY void fn_805A187C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A18A0()
{
}

extern char lbl_80684688[];

//@805A18A4
extern "C" DB_OVERLAY void fn_805A18A4(U* self, int chrg)
{
    PUT(0x1DC, lbl_80684688);
    if (chrg & 1)
        fn_80377408(self);
}

struct T28 { int* m0; char pad4[0x24]; unsigned char* m28; };

extern "C" DB_OVERLAY int fn_805A18D8(T28* p, int i)
{
    int o = p->m28[i] * 4;
    return *(int*)((char*)p->m0 + o);
}

struct G2C { char pad[0x2C]; int m; };

extern "C" DB_OVERLAY int fn_805A18F0(G2C* p)
{
    return p->m;
}

struct T3C { int* m0; char pad4[0x38]; unsigned char* m3C; };

extern "C" DB_OVERLAY int fn_805A18F8(T3C* p, int i)
{
    int o = p->m3C[i] * 4;
    return *(int*)((char*)p->m0 + o);
}

struct G40 { char pad[0x40]; int m; };

extern "C" DB_OVERLAY int fn_805A1910(G40* p)
{
    return p->m;
}

struct T50 { int* m0; char pad4[0x4C]; unsigned char* m50; };

extern "C" DB_OVERLAY int fn_805A1918(T50* p, int i)
{
    int o = p->m50[i] * 4;
    return *(int*)((char*)p->m0 + o);
}

struct G54 { char pad[0x54]; int m; };

extern "C" DB_OVERLAY int fn_805A1930(G54* p)
{
    return p->m;
}

struct T64 { int* m0; char pad4[0x60]; unsigned char* m64; };

extern "C" DB_OVERLAY int fn_805A1938(T64* p, int i)
{
    int o = p->m64[i] * 4;
    return *(int*)((char*)p->m0 + o);
}

struct G68 { char pad[0x68]; int m; };

extern "C" DB_OVERLAY int fn_805A1950(G68* p)
{
    return p->m;
}

struct Db805A1958_Tab {
    char pad[0xF0];
    char mF0[1];
};

extern "C" DB_OVERLAY void fn_805A1958(Db805A1958_Tab* self, int i, int j, int v)
{
    self->mF0[j + i * 0x30] = v;
}

struct Db805A196C_Obj {
    char pad0[0x10];
    char* m10;
};

//@805A196C
extern "C" DB_OVERLAY void fn_805A196C(Db805A196C_Obj* self, int i, int v)
{
    fn_8053B548(self->m10 + i * 0x1E0, v);
}

extern "C" void fn_80400560(void* p, int n);

//@805A19A4
extern "C" DB_OVERLAY void fn_805A19A4(void* p)
{
    fn_80400560(p, 0x58);
}

struct Db805A19C8_Obj {
    char pad0[4];
    Db8053967C_DbObj* m4;
};

//@805A19C8
extern "C" DB_OVERLAY int fn_805A19C8(Db805A19C8_Obj* self, int id)
{
    int spC = -1;
    int sp8 = -1;
    fn_80377E90(self->m4, &sp8, &spC, id);
    return sp8;
}

struct Db805A1A08_Obj {
    char pad0[0x12B90];
    const void* m12B90;
};

extern char lbl_80684640[];

//@805A1A08
extern "C" DB_OVERLAY void fn_805A1A08(Db805A1A08_Obj* self, int chrg)
{
    self->m12B90 = lbl_80684640;
    if (chrg & 1)
        fn_80377408(self);
}

struct G4 { char pad[0x4]; int m; };

extern "C" DB_OVERLAY int fn_805A1A40(G4* p)
{
    return p->m;
}

struct DtorAt14 {
    char pad[0x14];
    const void* m;
};

extern "C" void fn_805943A0(void* self, int a);

extern char lbl_806845B0[];

//@805A1A48
extern "C" DB_OVERLAY void fn_805A1A48(DtorAt14* self, int a)
{
    self->m = lbl_806845B0;
    fn_805943A0(self, a);
}

extern "C" DB_OVERLAY void fn_805A1A78(void* p)
{
    fn_80400560(p, 0x28);
}

/* fn_805A0270: not attempted (constructs and destroys a stack Db8059FE70_Obj with virtual-dtor member arrays; original code stays linked) */
/* fn_805A07C4: not attempted (0xEA8 bytes, over the size limit; original code stays linked) */
