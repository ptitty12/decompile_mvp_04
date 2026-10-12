/*
 * Database overlay code, .database_codeoverlay 0x8059A728-0x8059FE24 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/db_80596D88.h"

struct Db8059F18C_Obj {
    char pad0[0x64];
    int m64;
    int m68;
    unsigned m6C;
};
extern "C" {
int fn_80403060(const short* s);
void fn_80403144(void* dst, const void* src);
void fn_8040316C(short* dst, const short* src, int n);
}

struct Db8059A728_Pair {
    short m0;
    char pad2[2];
    int m4;
    const void* m8;
};

struct Db8059A728_Bits {
    unsigned a : 8;
    unsigned b : 5;
    unsigned c : 3;
    unsigned d : 5;
    unsigned e : 11;
};

struct Db8059A728_Rec {
    unsigned short m0;
    unsigned short m2[15];
    Db8059A728_Bits m20;
    const void* m24;
};

extern const char lbl_806012B0[];
extern "C" void fn_8040321C(short* dst, const short* fmt, const short* a, const short* b);

struct Db8059AB2C_Obj {
    int m0;
    char m4[0x14];
};

struct Db8059AB84_Obj {
    int m0;
    int m4[5];
};

struct Db8059AC0C_Name {
    short m0[0x1C];
    unsigned m38;
};

extern "C" {
int fn_804030C8(const short* a, const short* b);
int fn_80403DE4(const short* dst, const short* fmt, ...);
void fn_800A6D60(void* p);
}

struct Unk80090880;
const short* fn_80090880(Unk80090880* p);
extern Unk80090880* lbl_8061977C;
extern const short lbl_806022AC[];
extern const char lbl_805FEC2C[];

/* Player stat record: name (9 wide chars), packed counters at +0x14..+0x23, scalars to +0x34. */
struct Db8059A728_Obj {
    unsigned short m0[9];
    char pad12[2];
    unsigned a0 : 3;
    unsigned a1 : 1;
    unsigned a2 : 10;
    unsigned a3 : 14;
    unsigned apad : 4;
    unsigned b0 : 14;
    unsigned b1 : 14;
    unsigned bpad : 4;
    unsigned c0 : 15;
    unsigned c1 : 12;
    unsigned cpad : 5;
    unsigned short m20;
    unsigned short m22;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    unsigned m38;
    char m3C[0x18];
    char m54[0x1C];
    char m70[0x10];
    Db8059A728_Rec m80[6];
    Db8059A728_Pair m170[4];
    char m1A0[1];
};

extern "C" {
int fn_8059B988(Db8059A728_Obj* self, int k);
void fn_8059BABC(Db8059A728_Obj* self, int k, unsigned v);
}

extern "C" {
}

struct Db8059B6AC_Obj {
    char pad0[0x38];
    unsigned m38;
    unsigned short s[11];
};

struct Db8059F05C_Obj {
    char pad0[0x60];
    unsigned p0 : 24;
    unsigned f0 : 1;
    unsigned f1 : 1;
    unsigned f2 : 1;
    unsigned f3 : 1;
    unsigned f4 : 1;
    unsigned f5 : 1;
    unsigned f6 : 1;
    unsigned f7 : 1;
    unsigned g0 : 1;
    unsigned g1 : 1;
    unsigned g2 : 1;
    unsigned g3 : 1;
    unsigned g4 : 1;
    unsigned g5 : 1;
    unsigned g6 : 1;
    unsigned gpad : 25;
};

struct Db8059D5C4_Obj {
    char pad0[0x20];
    unsigned short m20;
    char pad22[0x3E];
    unsigned m60;
    int m64;
    char pad68[4];
    unsigned m6C;
};

enum Db8059F05C_K { Db8059F05C_Neg = -1, Db8059F05C_Lo = 0, Db8059F05C_Hi = 14 };

extern "C" {
int fn_8059E708(Db8059D5C4_Obj* self, int k);
int fn_8059F18C(Db8059D5C4_Obj* self, int k);
int fn_8059F64C(Db8059D5C4_Obj* self, int k);
}

struct Db8059B524_EntData {
    unsigned short m0;
    unsigned short m2[15];
    Db8059A728_Bits m20;
};
struct Db8059B524_Ent : Db8059B524_EntData {
    virtual void v08(int chrg);
};
struct Db8059B524_ItemData {
    short m0;
    char pad2[2];
    int m4;
};
struct Db8059B524_Item : Db8059B524_ItemData {
    virtual void v08(int chrg);
};
struct Db8059B524_Self {
    char pad0[0x3C];
    unsigned short m3C;
    unsigned short m3E;
    unsigned short m40;
    unsigned short m42;
    unsigned short m44;
    unsigned short m46;
    unsigned short m48;
    unsigned short m4A;
    unsigned short m4C;
    unsigned short m4E;
    unsigned short m50;
    char pad52[0x80 - 0x52];
    Db8059B524_Ent ents[6];
    Db8059B524_Item items[1];
};
extern "C" void fn_8059B524(Db8059B524_Self* s, int kind, int start, int cap, int n, int year, int a, int id);
/* forward declarations (definitions are in address order) */
extern "C" void fn_8059A728(Db8059A728_Pair* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_8059A79C(Db8059A728_Rec* self);
extern "C" void fn_8059A7E4(Db8059A728_Rec* self, int year, int a, int id);
extern "C" void fn_8059A8E4(Db8059A728_Rec* self, short* dst, int unused);
extern "C" int fn_8059A968(Db8059A728_Rec* self, int k);
extern "C" void fn_8059A9D4(Db8059A728_Rec* self, int k, unsigned v);
extern "C" void fn_8059AA7C(Db8059A728_Rec* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_8059AB2C(Db8059AB2C_Obj* self);
extern "C" void fn_8059AB5C(Db8059AB2C_Obj* self, int k, int v);
extern "C" int fn_8059AB6C(Db8059AB2C_Obj* self, int k);
extern "C" void fn_8059AB84(Db8059AB84_Obj* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_8059AC0C(Db8059AC0C_Name* self, const short* src, int n);
extern "C" void fn_8059AC80(const short* src, short* dst, unsigned n);
extern "C" void fn_8059AD30(Db8059A728_Obj* self);
extern "C" void fn_8059ADF8(Db8059A728_Obj* self, const short* b, int c);
extern "C" void fn_8059AE4C(Db8059A728_Obj* self, int both, int b, int c);
extern "C" void fn_8059AF50(Db8059B524_Self* self, int kind, int a, int b, int c);
extern "C" int fn_8059B158(void* self, int k);
extern "C" int fn_8059B1EC(void* self, int k);
extern "C" void fn_8059B280(Db8059A728_Obj* self, int k, int a, short* b, int c);
extern "C" int fn_8059B308(Db8059A728_Obj* self, int k, int a, int b);
extern "C" int fn_8059B3D4(Db8059A728_Obj* self, int k, int a);
extern "C" int fn_8059B47C(Db8059A728_Obj* self, int k, int a);
extern "C" int fn_8059B6AC(Db8059B6AC_Obj* self, int k);
extern "C" void fn_8059B780(Db8059B6AC_Obj* self, int k, unsigned v);
extern "C" int fn_8059B988(Db8059A728_Obj* self, int k);
extern "C" int fn_8059BAA4(Db8059A728_Obj* self, int k);
extern "C" void fn_8059BABC(Db8059A728_Obj* self, int k, unsigned v);
extern "C" void fn_8059BCD4(Db8059A728_Obj* self, int k, int v);
extern "C" void fn_8059BCF0(Db8059A728_Obj* self, int k, unsigned v);
extern "C" void fn_8059BD58(Db8059A728_Obj* self, unsigned d);
extern "C" void fn_8059BDD0(Db8059A728_Obj* self, unsigned d);
extern "C" int fn_8059D5C4(Db8059D5C4_Obj* self, int k);
extern "C" int fn_8059D5E8(Db8059D5C4_Obj* self, int k, int flag);
extern "C" int fn_8059E5D0(Db8059D5C4_Obj* self, int k, int flag);
extern "C" int fn_8059E684(Db8059D5C4_Obj* self, int k, int flag);
extern "C" int fn_8059F040(Db8059D5C4_Obj* self, int k);
extern "C" int fn_8059F05C(Db8059F05C_Obj* self, int k);
extern "C" int fn_8059F64C(Db8059D5C4_Obj* self, int k);
extern "C" int fn_8059F680(void* self, int k);
extern "C" int fn_8059FA44(void* self, int k);
extern "C" int fn_8059FADC(void* self, int k);
extern "C" int fn_8059FC90(Db8059D5C4_Obj* self, int k);
extern "C" int fn_8059FCB0(Db8059D5C4_Obj* self, int k);
extern "C" int fn_8059FCC4(Db8059D5C4_Obj* self);
extern "C" int fn_8059FD1C(Db8059D5C4_Obj* self);
extern "C" int fn_8059FD74(Db8059D5C4_Obj* self);
extern "C" int fn_8059FDCC(Db8059D5C4_Obj* self);

//@8059A728
extern "C" DB_OVERLAY void fn_8059A728(Db8059A728_Pair* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 2);
    io->v08(a, &self->m4, 4);
}

//@8059A79C
extern "C" DB_OVERLAY void fn_8059A79C(Db8059A728_Rec* self)
{
    self->m0 = 0;
    fn_8040074C(self->m2, 0x1E);
    fn_8040074C(&self->m20, 4);
}

extern "C" DB_OVERLAY void fn_8059A7E4(Db8059A728_Rec* self, int year, int a, int id)
{
    Unk8007A4DC_Screen* sc = (Unk8007A4DC_Screen*)lbl_8061930C;
    unsigned short buf[32];
    sc->fn_8007A7C8(0, id, (char*)buf);
    self->m0 = buf[0];
    sc->fn_8007A7C8(1, id, (char*)buf);
    unsigned n = fn_80403060((short*)buf);
    if (n > 14)
        n = 14;
    fn_8040316C((short*)self->m2, (short*)buf, n);
    fn_8059A9D4(self, 0, year - 0x7D4);
    fn_8059A9D4(self, 1, sc->fn_8007A6A0(5, id));
    fn_8059A9D4(self, 2, ((Unk8007B2B0_Screen*)sc)->fn_8007B8C4(0, a));
    fn_8059A9D4(self, 3, ((Unk8007B2B0_Screen*)sc)->fn_8007B8C4(1, a));
}

//@8059A8E4
extern "C" DB_OVERLAY void fn_8059A8E4(Db8059A728_Rec* self, short* dst, int unused)
{
    short pair[2];
    short* p = pair;
    pair[0] = self->m0;
    p[1] = 0;
    if (fn_80403060(p)) {
        short fmt[32];
        fn_80402EF8((char*)fmt, lbl_806012B0);
        fn_8040321C(dst, fmt, p, (short*)&self->m2);
    } else {
        fn_80403144(dst, &self->m2);
    }
}

//@8059A968
extern "C" DB_OVERLAY int fn_8059A968(Db8059A728_Rec* self, int k)
{
    int r = 0;
    switch (k) {
    case 0:
        r = *(unsigned char*)&self->m20;
        break;
    case 1:
        r = self->m20.b;
        break;
    case 2:
        r = self->m20.c;
        break;
    case 3:
        r = self->m20.d;
        break;
    }
    if (k == 0)
        r += 0x7D4;
    return r;
}

//@8059A9D4
extern "C" DB_OVERLAY void fn_8059A9D4(Db8059A728_Rec* self, int k, unsigned v)
{
    switch (k) {
    case 0: {
        unsigned t = v;
        if (t > 0xFF)
            t = 0xFF;
        *(unsigned char*)&self->m20 = t;
        break;
    }
    case 1: {
        unsigned t = v;
        if (t > 0x1F)
            t = 0x1F;
        self->m20.b = t;
        break;
    }
    case 2: {
        unsigned t = v;
        if (t > 7)
            t = 7;
        self->m20.c = t;
        break;
    }
    case 3: {
        unsigned t = v;
        if (t > 0x1F)
            t = 0x1F;
        self->m20.d = t;
        break;
    }
    }
}

//@8059AA7C
extern "C" DB_OVERLAY void fn_8059AA7C(Db8059A728_Rec* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 2);
    for (unsigned i = 0; i < 14; i++)
        io->v08(a, &self->m2[i], 2);
    io->v08(a, &self->m20, 4);
}

//@8059AB2C
extern "C" DB_OVERLAY void fn_8059AB2C(Db8059AB2C_Obj* self)
{
    self->m0 = 0;
    fn_8040074C(self->m4, 0x14);
}

//@8059AB5C
extern "C" DB_OVERLAY void fn_8059AB5C(Db8059AB2C_Obj* self, int k, int v)
{
    if (k == 10)
        self->m0 = v;
}

//@8059AB6C
extern "C" DB_OVERLAY int fn_8059AB6C(Db8059AB2C_Obj* self, int k)
{
    if (k == 10)
        return self->m0;
    return 0;
}

//@8059AB84
extern "C" DB_OVERLAY void fn_8059AB84(Db8059AB84_Obj* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    for (unsigned i = 0; i < 5; i++)
        io->v08(a, &self->m4[i], 4);
}

//@8059AC0C
extern "C" DB_OVERLAY void fn_8059AC0C(Db8059AC0C_Name* self, const short* src, int n)
{
    if (n == 0)
        n = fn_80403060(src);
    unsigned m = n;
    if (m > 8)
        m = 8;
    fn_8040316C(self->m0, src, m);
    self->m0[m] = 0;
    self->m38 |= 0x80000000;
}

//@8059AC80
extern "C" DB_OVERLAY void fn_8059AC80(const short* src, short* dst, unsigned n)
{
    typedef const short* (*Look)(Unk80090880*, int);
    if (fn_804030C8(src, lbl_806022AC) == 0)
        fn_80403DE4(src, ((Look)fn_80090880)(lbl_8061977C, 0x3BF0), 1);
    if (n > (unsigned)fn_80403060(src) || n == 0) {
        fn_80403144(dst, src);
    } else {
        fn_8040316C(dst, src, n);
        dst[n - 1] = 0;
    }
}

//@8059AD30
extern "C" DB_OVERLAY void fn_8059AD30(Db8059A728_Obj* self)
{
    self->m38 |= 0x80000000;
    fn_8040074C(self, 0x12);
    fn_8040074C((char*)self + 0x14, 0x28);
    self->m34 = fn_800736EC(lbl_805FEC2C);
    fn_8040074C(self->m3C, 0x18);
    fn_8040074C(self->m54, 0x1C);
    fn_8040074C(self->m70, 0x10);
    for (unsigned i = 0; i < 6; i++)
        fn_8059A79C(&self->m80[i]);
    Db8059A728_Pair* q = self->m170;
    for (unsigned j = 0; j < 4; j++) {
        q->m0 = 0;
        q->m4 = 0;
        q++;
    }
    fn_800A6D60(self->m1A0);
}

//@8059ADF8
extern "C" DB_OVERLAY void fn_8059ADF8(Db8059A728_Obj* self, const short* b, int c)
{
    fn_8059AD30(self);
    fn_8059AC0C((Db8059AC0C_Name*)self, b, 0);
    fn_8059BCD4(self, 0, c);
}

//@8059AE4C
extern "C" DB_OVERLAY void fn_8059AE4C(Db8059A728_Obj* self, int both, int b, int c)
{
    fn_8059BABC(self, 10, fn_8059B988(self, 10) + 1);
    if (both)
        fn_8059BABC(self, 11, fn_8059B988(self, 11) + 1);
    if (b) {
        fn_8059BABC(self, 12, fn_8059B988(self, 12) + 1);
        if (both)
            fn_8059BABC(self, 13, fn_8059B988(self, 13) + 1);
    }
    if (c) {
        fn_8059BABC(self, 6, fn_8059B988(self, 6) + 1);
        if (both)
            fn_8059BABC(self, 7, fn_8059B988(self, 7) + 1);
    }
}

extern "C" DB_OVERLAY void fn_8059AF50(Db8059B524_Self* self, int kind, int a, int b, int c)
{
    fn_8059B780((Db8059B6AC_Obj*)self, kind, fn_8059B6AC((Db8059B6AC_Obj*)self, kind) + 1);
    switch (kind) {
    case 0:
        fn_8059B524(self, 2, 0, 3, self->m3C, a, b, c);
        break;
    case 1:
        fn_8059B524(self, 1, 0, 3, self->m3E, a, b, c);
        break;
    case 2:
        fn_8059B524(self, 2, 3, 1, self->m40, a, b, c);
        break;
    case 3:
        fn_8059B524(self, 1, 3, 1, self->m42, a, b, c);
        break;
    case 4:
        fn_8059B524(self, 1, 4, 1, self->m44, a, b, c);
        break;
    case 5:
        fn_8059B524(self, 1, 5, 1, self->m46, a, b, c);
        break;
    case 6:
        fn_8059B524(self, 0, 0, 0, self->m48, a, b, c);
        break;
    case 7:
        fn_8059B524(self, 0, 0, 0, self->m4A, a, b, c);
        break;
    case 8:
        fn_8059B524(self, 0, 0, 0, self->m4C, a, b, c);
        break;
    case 9:
        fn_8059B524(self, 0, 0, 0, self->m4E, a, b, c);
        break;
    case 10:
        fn_8059B524(self, 0, 0, 0, self->m50, a, b, c);
        break;
    }
}

//@8059B158
extern "C" DB_OVERLAY int fn_8059B158(void* self, int k)
{
    switch (k) {
    case 0:
        return 3;
    case 1:
        return 3;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    case 6:
        return 0;
    case 7:
        return 0;
    case 8:
        return 0;
    case 9:
        return 0;
    case 10:
        return 0;
    default:
        return 0;
    }
}

//@8059B1EC
extern "C" DB_OVERLAY int fn_8059B1EC(void* self, int k)
{
    switch (k) {
    case 0:
        return 2;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    case 6:
        return 0;
    case 7:
        return 0;
    case 8:
        return 0;
    case 9:
        return 0;
    case 10:
        return 0;
    default:
        return 0;
    }
}

/* Every case assigns s (zero arms too) and there is no default arm. */
//@8059B280
extern "C" DB_OVERLAY void fn_8059B280(Db8059A728_Obj* self, int k, int a, short* b, int c)
{
    int s = 0;
    switch (k) {
    case 0:
        s = 0;
        break;
    case 1:
        s = 0;
        break;
    case 2:
        s = 3;
        break;
    case 3:
        s = 3;
        break;
    case 4:
        s = 4;
        break;
    case 5:
        s = 5;
        break;
    case 6:
        s = 0;
        break;
    case 7:
        s = 0;
        break;
    case 8:
        s = 0;
        break;
    case 9:
        s = 0;
        break;
    case 10:
        s = 0;
        break;
    }
    fn_8059A8E4(&self->m80[s + a], b, c);
}

//@8059B308
/* The zero arms share labels non-adjacently (0,6,8,10 and 1,7,9): labels with several uses are not followed by CSE,
   so each arm keeps its own s = 0 and the full compare tree stays. Same shape in fn_8059B3D4 and fn_8059B47C. */
extern "C" DB_OVERLAY int fn_8059B308(Db8059A728_Obj* self, int k, int a, int b)
{
    int s = 0;
    switch (k) {
    case 2:
        s = 3;
        break;
    case 3:
        s = 3;
        break;
    case 4:
        s = 4;
        break;
    case 5:
        s = 5;
        break;
    case 0:
    case 6:
    case 8:
    case 10:
        s = 0;
        break;
    case 1:
    case 7:
    case 9:
        s = 0;
        break;
    }
    return fn_8059A968(&self->m80[s + a], b);
}

//@8059B3D4
extern "C" DB_OVERLAY int fn_8059B3D4(Db8059A728_Obj* self, int k, int a)
{
    int s = 0;
    switch (k) {
    case 2:
        s = 3;
        break;
    case 3:
        s = 3;
        break;
    case 4:
        s = 4;
        break;
    case 5:
        s = 5;
        break;
    case 0:
    case 6:
    case 8:
    case 10:
        s = 0;
        break;
    case 1:
    case 7:
    case 9:
        s = 0;
        break;
    }
    return *(unsigned short*)((char*)self + ((s + a) * 12 + 0x170));
}

//@8059B47C
extern "C" DB_OVERLAY int fn_8059B47C(Db8059A728_Obj* self, int k, int a)
{
    int s = 0;
    switch (k) {
    case 2:
        s = 3;
        break;
    case 3:
        s = 3;
        break;
    case 4:
        s = 4;
        break;
    case 5:
        s = 5;
        break;
    case 0:
    case 6:
    case 8:
    case 10:
        s = 0;
        break;
    case 1:
    case 7:
    case 9:
        s = 0;
        break;
    }
    return *(int*)((char*)self + ((s + a) * 12 + 0x174));
}

extern "C" DB_OVERLAY void fn_8059B524(Db8059B524_Self* s, int kind, int start, int cap, int n, int year, int a, int id)
{
    int pos = start + n - 1;
    int i;
    switch (kind) {
    case 1:
        if (n != 0) {
            if (n > cap) {
                for (i = 0; i < cap - 1; i++)
                    s->ents[i] = s->ents[i + 1];
                pos = start + cap - 1;
            }
            fn_8059A7E4((Db8059A728_Rec*)&s->ents[pos], year, a, id);
        }
        break;
    case 2:
        if (n != 0) {
            if (n > cap) {
                for (i = 0; i < cap - 1; i++)
                    s->items[i] = s->items[i + 1];
                pos = start + cap - 1;
            }
            int it = pos * 12 + (int)s;
            it += 0x170;
            *(short*)it = year;
            *(int*)(it + 4) = a;
        }
        break;
    }
}

//@8059B6AC
extern "C" DB_OVERLAY int fn_8059B6AC(Db8059B6AC_Obj* self, int k)
{
    switch (k) {
    case 0:
        return self->s[0];
    case 1:
        return self->s[1];
    case 2:
        return self->s[2];
    case 3:
        return self->s[3];
    case 4:
        return self->s[4];
    case 5:
        return self->s[5];
    case 6:
        return self->s[6];
    case 7:
        return self->s[7];
    case 8:
        return self->s[8];
    case 9:
        return self->s[9];
    case 10:
        return self->s[10];
    default:
        return 0;
    }
}

//@8059B780
extern "C" DB_OVERLAY void fn_8059B780(Db8059B6AC_Obj* self, int k, unsigned v)
{
    switch (k) {
    case 0: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[0] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 1: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[1] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 2: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[2] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 3: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[3] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 4: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[4] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 5: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[5] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 6: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[6] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 7: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[7] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 8: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[8] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 9: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[9] = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 10: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->s[10] = t;
        self->m38 |= 0x80000000;
        break;
    }
    }
}

//@8059B988
extern "C" DB_OVERLAY int fn_8059B988(Db8059A728_Obj* self, int k)
{
    unsigned r = 0;
    switch (k) {
    case 0:
        r = self->a0;
        break;
    case 1:
        r = self->a1;
        break;
    case 2:
        r = self->a2;
        break;
    case 3:
        r = self->a3;
        break;
    case 4:
        r = self->b0;
        break;
    case 5:
        r = self->b1;
        break;
    case 6:
        r = self->c0;
        break;
    case 7:
        r = self->c1;
        break;
    case 8:
        r = self->m20;
        break;
    case 9:
        r = self->m22;
        break;
    case 10:
        r = self->m24;
        break;
    case 11:
        r = self->m28;
        break;
    case 12:
        r = self->m2C;
        break;
    case 13:
        r = self->m30;
        break;
    }
    int lo = 8, hi = 9;
    if (k <= hi && k >= lo)
        r *= 25;
    return r;
}

//@8059BAA4
extern "C" DB_OVERLAY int fn_8059BAA4(Db8059A728_Obj* self, int k)
{
    int r = 0;
    if (k == 0)
        r = self->m34;
    return r;
}

//@8059BABC
extern "C" DB_OVERLAY void fn_8059BABC(Db8059A728_Obj* self, int k, unsigned v)
{
    int lo = 8, hi = 9;
    if (k <= hi && k >= lo)
        v = v / 25;
    switch (k) {
    case 0: {
        unsigned t = v;
        if (t > 7)
            t = 7;
        self->a0 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 1: {
        int t = 1;
        if (v == 0)
            t = 0;
        self->a1 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 2: {
        unsigned t = v;
        if (t > 0x3FF)
            t = 0x3FF;
        self->a2 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 3: {
        unsigned t = v;
        if (t > 0x3FFF)
            t = 0x3FFF;
        self->a3 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 4: {
        unsigned t = v;
        if (t > 0x3FFF)
            t = 0x3FFF;
        self->b0 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 5: {
        unsigned t = v;
        if (t > 0x3FFF)
            t = 0x3FFF;
        self->b1 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 6: {
        unsigned t = v;
        if (t > 0x7FFF)
            t = 0x7FFF;
        self->c0 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 7: {
        unsigned t = v;
        if (t > 0xFFF)
            t = 0xFFF;
        self->c1 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 8: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->m20 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 9: {
        unsigned t = v;
        if (t > 0xFFFF)
            t = 0xFFFF;
        self->m22 = t;
        self->m38 |= 0x80000000;
        break;
    }
    case 10:
        self->m24 = v;
        self->m38 |= 0x80000000;
        break;
    case 11:
        self->m28 = v;
        self->m38 |= 0x80000000;
        break;
    case 12:
        self->m2C = v;
        self->m38 |= 0x80000000;
        break;
    case 13:
        self->m30 = v;
        self->m38 |= 0x80000000;
        break;
    }
}

//@8059BCD4
extern "C" DB_OVERLAY void fn_8059BCD4(Db8059A728_Obj* self, int k, int v)
{
    if (k == 0) {
        self->m34 = v;
        self->m38 |= 0x80000000;
    }
}

//@8059BCF0
extern "C" DB_OVERLAY void fn_8059BCF0(Db8059A728_Obj* self, int k, unsigned v)
{
    unsigned c = fn_8059B988(self, k);
    if (k == 2) {
        if (v > c)
            fn_8059BABC(self, 2, v);
    } else {
        fn_8059BABC(self, k, c + v);
    }
}

/* near-miss: retail keeps both sums in r0 (add r0,r3,r30; mr r5,r0); ours folds them into r3/r5 */
//@8059BD58
extern "C" DB_OVERLAY void fn_8059BD58(Db8059A728_Obj* self, unsigned d)
{
    unsigned t = fn_8059B988(self, 8) + d;
    unsigned v = 1000000;
    if (v > t)
        v = t;
    fn_8059BABC(self, 8, v);
    unsigned u = fn_8059B988(self, 9) + d;
    fn_8059BABC(self, 9, u);
}

//@8059BDD0
extern "C" DB_OVERLAY void fn_8059BDD0(Db8059A728_Obj* self, unsigned d)
{
    fn_8059BABC(self, 8, fn_8059B988(self, 8) - d);
}

//@8059D5C4
extern "C" DB_OVERLAY int fn_8059D5C4(Db8059D5C4_Obj* self, int k)
{
    if (k == 0) {
        unsigned f = self->m60;
        if (!(f & 0x100))
            self->m60 = f | 0x100;
    }
    return 1;
}

//@8059D5E8
extern "C" DB_OVERLAY int fn_8059D5E8(Db8059D5C4_Obj* self, int k, int flag)
{
    int ret = 0;
    unsigned v = 0;
    if (flag == 0)
        v = fn_8059FA44(self, k);
    switch (k) {
    case 0: {
        unsigned f = self->m60;
        if (!(f & 0x80)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x80;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 1: {
        unsigned f = self->m60;
        if (!(f & 0x40)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x40;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 2: {
        unsigned f = self->m60;
        if (!(f & 0x20)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x20;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 3: {
        unsigned f = self->m60;
        if (!(f & 0x10)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x10;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 4: {
        unsigned f = self->m60;
        if (!(f & 0x8)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x8;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 5: {
        unsigned f = self->m60;
        if (!(f & 0x4)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x4;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 6: {
        unsigned f = self->m60;
        if (!(f & 0x2)) {
            if (!(v > self->m20 * 25)) {
                self->m60 = f | 0x2;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 7: {
        unsigned f = self->m60;
        if (f & 0x1)
            break;
        if (!(v > self->m20 * 25)) {
            self->m60 = f | 0x1;
            fn_8059BDD0((Db8059A728_Obj*)self, v);
            ret = 1;
        }
        break;
    }
    case 8: {
        int f = self->m64;
        if (!(f < 0)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x80000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 9: {
        unsigned f = self->m64;
        if (!(f & 0x40000000)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x40000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 10: {
        unsigned f = self->m64;
        if (!(f & 0x20000000)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x20000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 11: {
        unsigned f = self->m64;
        if (!(f & 0x10000000)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x10000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 12: {
        unsigned f = self->m64;
        if (!(f & 0x8000000)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x8000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 13: {
        unsigned f = self->m64;
        if (!(f & 0x4000000)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x4000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 14: {
        unsigned f = self->m64;
        if (!(f & 0x2000000)) {
            if (!(v > self->m20 * 25)) {
                self->m64 = f | 0x2000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    }
    return ret;
}

//@8059E5D0
extern "C" DB_OVERLAY int fn_8059E5D0(Db8059D5C4_Obj* self, int k, int flag)
{
    int ret = 0;
    unsigned v = 0;
    if (flag == 0)
        v = fn_8059FC90(self, k);
    switch (k) {
    case 0: {
        unsigned f = self->m6C;
        if (!(f & 0x2000000)) {
            if (!(v > self->m20 * 25)) {
                self->m6C = f | 0x2000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    case 1: {
        unsigned f = self->m6C;
        if (!(f & 0x1000000)) {
            if (!(v > self->m20 * 25)) {
                self->m6C = f | 0x1000000;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
                ret = 1;
            }
        }
        break;
    }
    }
    return ret;
}

//@8059E684
extern "C" DB_OVERLAY int fn_8059E684(Db8059D5C4_Obj* self, int k, int flag)
{
    int ret = 0;
    unsigned v = 0;
    if (flag == 0)
        v = fn_8059FCB0(self, k);
    if (k == 0) {
        unsigned f = self->m6C;
        if (!(f & 0x800000)) {
            if (!(v > self->m20 * 25)) {
                self->m6C = f | 0x800000;
                ret = 1;
                fn_8059BDD0((Db8059A728_Obj*)self, v);
            }
        }
    }
    return ret;
}

//@8059F040
extern "C" DB_OVERLAY int fn_8059F040(Db8059D5C4_Obj* self, int k)
{
    if (k == 0)
        return (self->m60 >> 8) & 1;
    return 0;
}

//@8059F05C
extern "C" DB_OVERLAY int fn_8059F05C(Db8059F05C_Obj* self, int k)
{
    switch (k) {
    case 0:
        return self->f0;
    case 1:
        return self->f1;
    case 2:
        return self->f2;
    case 3:
        return self->f3;
    case 4:
        return self->f4;
    case 5:
        return self->f5;
    case 6:
        return self->f6;
    case 7:
        return self->f7;
    case 8:
        return self->g0;
    case 9:
        return self->g1;
    case 10:
        return self->g2;
    case 11:
        return self->g3;
    case 12:
        return self->g4;
    case 13:
        return self->g5;
    case 14:
        return self->g6;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8059F18C(Db8059D5C4_Obj* obj, int k)
{
    Db8059F18C_Obj* self = (Db8059F18C_Obj*)obj;
    switch (k) {
    case 0:
        return *(unsigned char*)&self->m64 & 1;
    case 1:
        return ((unsigned)self->m64 >> 23) & 1;
    case 2:
        return ((unsigned)self->m64 >> 22) & 1;
    case 3:
        return ((unsigned)self->m64 >> 21) & 1;
    case 4:
        return ((unsigned)self->m64 >> 20) & 1;
    case 5:
        return ((unsigned)self->m64 >> 19) & 1;
    case 6:
        return ((unsigned)self->m64 >> 18) & 1;
    case 7:
        return ((unsigned)self->m64 >> 17) & 1;
    case 8:
        return *(unsigned short*)&self->m64 & 1;
    case 9:
        return ((unsigned)self->m64 >> 15) & 1;
    case 10:
        return ((unsigned)self->m64 >> 14) & 1;
    case 11:
        return ((unsigned)self->m64 >> 13) & 1;
    case 12:
        return ((unsigned)self->m64 >> 12) & 1;
    case 13:
        return ((unsigned)self->m64 >> 11) & 1;
    case 14:
        return ((unsigned)self->m64 >> 10) & 1;
    case 15:
        return ((unsigned)self->m64 >> 9) & 1;
    case 16:
        return ((unsigned)self->m64 >> 8) & 1;
    case 17:
        return ((unsigned)self->m64 >> 7) & 1;
    case 18:
        return ((unsigned)self->m64 >> 6) & 1;
    case 19:
        return ((unsigned)self->m64 >> 5) & 1;
    case 20:
        return ((unsigned)self->m64 >> 4) & 1;
    case 21:
        return ((unsigned)self->m64 >> 3) & 1;
    case 22:
        return ((unsigned)self->m64 >> 2) & 1;
    case 23:
        return ((unsigned)self->m64 >> 1) & 1;
    case 24:
        return self->m64 & 1;
    case 25:
        return (unsigned)self->m68 >> 31;
    case 26:
        return ((unsigned)self->m68 >> 30) & 1;
    case 27:
        return ((unsigned)self->m68 >> 29) & 1;
    case 28:
        return ((unsigned)self->m68 >> 28) & 1;
    case 29:
        return ((unsigned)self->m68 >> 27) & 1;
    case 30:
        return ((unsigned)self->m68 >> 26) & 1;
    case 31:
        return ((unsigned)self->m68 >> 25) & 1;
    case 32:
        return *(unsigned char*)&self->m68 & 1;
    case 33:
        return ((unsigned)self->m68 >> 23) & 1;
    case 34:
        return ((unsigned)self->m68 >> 22) & 1;
    case 35:
        return ((unsigned)self->m68 >> 21) & 1;
    case 36:
        return ((unsigned)self->m68 >> 20) & 1;
    case 37:
        return ((unsigned)self->m68 >> 19) & 1;
    case 38:
        return ((unsigned)self->m68 >> 18) & 1;
    case 39:
        return ((unsigned)self->m68 >> 17) & 1;
    case 40:
        return *(unsigned short*)&self->m68 & 1;
    case 41:
        return ((unsigned)self->m68 >> 15) & 1;
    case 42:
        return ((unsigned)self->m68 >> 14) & 1;
    case 43:
        return ((unsigned)self->m68 >> 13) & 1;
    case 44:
        return ((unsigned)self->m68 >> 12) & 1;
    case 45:
        return ((unsigned)self->m68 >> 11) & 1;
    case 46:
        return ((unsigned)self->m68 >> 10) & 1;
    case 47:
        return ((unsigned)self->m68 >> 9) & 1;
    case 48:
        return ((unsigned)self->m68 >> 8) & 1;
    case 49:
        return ((unsigned)self->m68 >> 7) & 1;
    case 50:
        return ((unsigned)self->m68 >> 6) & 1;
    case 51:
        return ((unsigned)self->m68 >> 5) & 1;
    case 52:
        return ((unsigned)self->m68 >> 4) & 1;
    case 53:
        return ((unsigned)self->m68 >> 3) & 1;
    case 54:
        return ((unsigned)self->m68 >> 2) & 1;
    case 55:
        return ((unsigned)self->m68 >> 1) & 1;
    case 56:
        return self->m68 & 1;
    case 57:
        return (unsigned)self->m6C >> 31;
    case 58:
        return ((unsigned)self->m6C >> 30) & 1;
    case 59:
        return ((unsigned)self->m6C >> 29) & 1;
    case 60:
        return ((unsigned)self->m6C >> 28) & 1;
    case 61:
        return ((unsigned)self->m6C >> 27) & 1;
    case 62:
        return ((unsigned)self->m6C >> 26) & 1;
    }
    return 0;
}

//@8059F64C
extern "C" DB_OVERLAY int fn_8059F64C(Db8059D5C4_Obj* self, int k)
{
    switch (k) {
    case 0:
        return (self->m6C >> 25) & 1;
    case 1:
        return *(unsigned char*)&self->m6C & 1;
    }
    return 0;
}

/* One return per case (119 cases): jump2 merges the equal returns, the compares stay. */
//@8059F680
extern "C" DB_OVERLAY int fn_8059F680(void* self, int k)
{
    switch (k) {
    case 0:
        return 25;
    case 1:
        return 25;
    case 2:
        return 25;
    case 3:
        return 25;
    case 4:
        return 25;
    case 5:
        return 25;
    case 6:
        return 50;
    case 7:
        return 50;
    case 8:
        return 50;
    case 9:
        return 50;
    case 10:
        return 50;
    case 11:
        return 50;
    case 12:
        return 75;
    case 13:
        return 75;
    case 14:
        return 75;
    case 15:
        return 75;
    case 16:
        return 75;
    case 17:
        return 75;
    case 18:
        return 100;
    case 19:
        return 100;
    case 20:
        return 100;
    case 21:
        return 100;
    case 22:
        return 100;
    case 23:
        return 100;
    case 24:
        return 125;
    case 25:
        return 125;
    case 26:
        return 125;
    case 27:
        return 125;
    case 28:
        return 125;
    case 29:
        return 125;
    case 30:
        return 150;
    case 31:
        return 150;
    case 32:
        return 150;
    case 33:
        return 150;
    case 34:
        return 150;
    case 35:
        return 150;
    case 36:
        return 175;
    case 37:
        return 175;
    case 38:
        return 175;
    case 39:
        return 175;
    case 40:
        return 175;
    case 41:
        return 200;
    case 42:
        return 200;
    case 43:
        return 200;
    case 44:
        return 200;
    case 45:
        return 200;
    case 46:
        return 250;
    case 47:
        return 250;
    case 48:
        return 250;
    case 49:
        return 250;
    case 50:
        return 250;
    case 51:
        return 300;
    case 52:
        return 300;
    case 53:
        return 300;
    case 54:
        return 300;
    case 55:
        return 300;
    case 56:
        return 350;
    case 57:
        return 350;
    case 58:
        return 350;
    case 59:
        return 350;
    case 60:
        return 350;
    case 61:
        return 400;
    case 62:
        return 400;
    case 63:
        return 400;
    case 64:
        return 400;
    case 65:
        return 400;
    case 66:
        return 450;
    case 67:
        return 450;
    case 68:
        return 450;
    case 69:
        return 450;
    case 70:
        return 450;
    case 71:
        return 500;
    case 72:
        return 500;
    case 73:
        return 500;
    case 74:
        return 500;
    case 75:
        return 500;
    case 76:
        return 550;
    case 77:
        return 550;
    case 78:
        return 550;
    case 79:
        return 550;
    case 80:
        return 600;
    case 81:
        return 600;
    case 82:
        return 600;
    case 83:
        return 600;
    case 84:
        return 600;
    case 85:
        return 650;
    case 86:
        return 650;
    case 87:
        return 650;
    case 88:
        return 650;
    case 89:
        return 700;
    case 90:
        return 700;
    case 91:
        return 700;
    case 92:
        return 700;
    case 93:
        return 750;
    case 94:
        return 750;
    case 95:
        return 750;
    case 96:
        return 800;
    case 97:
        return 800;
    case 98:
        return 800;
    case 99:
        return 800;
    case 100:
        return 850;
    case 101:
        return 850;
    case 102:
        return 850;
    case 103:
        return 850;
    case 104:
        return 900;
    case 105:
        return 900;
    case 106:
        return 900;
    case 107:
        return 900;
    case 108:
        return 950;
    case 109:
        return 950;
    case 110:
        return 950;
    case 111:
        return 950;
    case 112:
        return 1000;
    case 113:
        return 1000;
    case 114:
        return 1000;
    case 115:
        return 1000;
    case 116:
        return 1000;
    case 117:
        return 1000;
    case 118:
        return 1000;
    }
    return 0;
}

//@8059FA44
extern "C" DB_OVERLAY int fn_8059FA44(void* self, int k)
{
    switch (k) {
    case 0:
        return 2500;
    case 1:
        return 5000;
    case 2:
        return 3000;
    case 3:
        return 2500;
    case 4:
        return 4000;
    case 5:
        return 5000;
    case 6:
        return 3000;
    case 7:
        return 5000;
    case 8:
        return 5000;
    case 9:
        return 3000;
    case 10:
        return 2500;
    case 11:
        return 4000;
    case 12:
        return 4000;
    case 13:
        return 3000;
    case 14:
        return 2500;
    }
    return 0;
}

//@8059FADC
extern "C" DB_OVERLAY int fn_8059FADC(void* self, int k)
{
    switch (k) {
    case 0:
        return 2500;
    case 1:
        return 2500;
    case 2:
        return 2500;
    case 3:
        return 2500;
    case 4:
        return 2500;
    case 5:
        return 2500;
    case 6:
        return 2500;
    case 7:
        return 2500;
    case 8:
        return 2500;
    case 9:
        return 2500;
    case 10:
        return 2500;
    case 11:
        return 3000;
    case 12:
        return 3000;
    case 13:
        return 3000;
    case 14:
        return 3000;
    case 15:
        return 3000;
    case 16:
        return 3000;
    case 17:
        return 3000;
    case 18:
        return 3000;
    case 19:
        return 3000;
    case 20:
        return 3000;
    case 21:
        return 3000;
    case 22:
        return 3500;
    case 23:
        return 3500;
    case 24:
        return 3500;
    case 25:
        return 3500;
    case 26:
        return 3500;
    case 27:
        return 3500;
    case 28:
        return 3500;
    case 29:
        return 3500;
    case 30:
        return 3500;
    case 31:
        return 3500;
    case 32:
        return 3500;
    case 33:
        return 3500;
    case 34:
        return 3500;
    case 35:
        return 3500;
    case 36:
        return 3500;
    case 37:
        return 4000;
    case 38:
        return 4000;
    case 39:
        return 4000;
    case 40:
        return 4000;
    case 41:
        return 4000;
    case 42:
        return 4000;
    case 43:
        return 4000;
    case 44:
        return 4000;
    case 45:
        return 4000;
    case 46:
        return 4500;
    case 47:
        return 4500;
    case 48:
        return 4500;
    case 49:
        return 4500;
    case 50:
        return 4500;
    case 51:
        return 4500;
    case 52:
        return 4500;
    case 53:
        return 4500;
    case 54:
        return 4500;
    case 55:
        return 4500;
    case 56:
        return 4500;
    case 57:
        return 4500;
    case 58:
        return 5000;
    case 59:
        return 5000;
    case 60:
        return 5000;
    case 61:
        return 0;
    case 62:
        return 0;
    }
    return 0;
}

//@8059FC90
extern "C" DB_OVERLAY int fn_8059FC90(Db8059D5C4_Obj* self, int k)
{
    switch (k) {
    case 0:
        return 0;
    case 1:
        return 0;
    default:
        return 0;
    }
}

//@8059FCB0
extern "C" DB_OVERLAY int fn_8059FCB0(Db8059D5C4_Obj* self, int k)
{
    if (k == 0)
        return 10000;
    return 0;
}

//@8059FCC4
extern "C" DB_OVERLAY int fn_8059FCC4(Db8059D5C4_Obj* self)
{
    int n = 0;
    for (unsigned i = 0; i <= 0x76; i++) {
        if (fn_8059E708(self, i))
            n++;
    }
    return n;
}

//@8059FD1C
extern "C" DB_OVERLAY int fn_8059FD1C(Db8059D5C4_Obj* self)
{
    int n = 0;
    for (unsigned i = 0; i <= 0xE; i++) {
        if (fn_8059F05C((Db8059F05C_Obj*)self, i))
            n++;
    }
    return n;
}

//@8059FD74
extern "C" DB_OVERLAY int fn_8059FD74(Db8059D5C4_Obj* self)
{
    int n = 0;
    for (unsigned i = 0; i <= 0x3E; i++) {
        if (fn_8059F18C(self, i))
            n++;
    }
    return n;
}

//@8059FDCC
extern "C" DB_OVERLAY int fn_8059FDCC(Db8059D5C4_Obj* self)
{
    int n = 0;
    for (unsigned i = 0; i <= 1; i++) {
        if (fn_8059F64C(self, i))
            n++;
    }
    return n;
}
