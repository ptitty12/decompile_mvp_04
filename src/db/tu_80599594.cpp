/*
 * Database overlay code, .database_codeoverlay 0x80599594-0x8059A728 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct Obj {
    char* m0;
    int m4;
};

struct Unk80071604 {
    char m0[16];
    Obj* m10;
    int m14;
    int m18;
    unsigned m1C;
    void* m20;
    char* m24;
};

extern char lbl_80684230[];

struct Db80599B54_Slot {
    int v[3];
    unsigned char n;
    char pad[3];
    int m10;
};

struct Db80599B54_Ent {
    unsigned short m0;
    char pad2[2];
    Db80599B54_Slot s[2];
};

struct Unk80084910_VT {
    char pad0[8];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* p, int n);
};

struct Unk80084910_VObj {
    char pad0[4];
    Unk80084910_VT* m4;
};

typedef Unk80084910_VObj VObj;

struct Unk80070DDC_Stream0 {
    int m0;
};

struct Unk80070DDC_Stream : Unk80070DDC_Stream0 {
    virtual int v08(int a, void* data, int size);
    virtual int v10();
};

void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io);

extern "C" {
void fn_8040074C(void* p, unsigned n);
void* fn_803774A8(unsigned n, int heap);
void fn_80329FA0(void* out, int v, ...);
}
void* operator new[](unsigned int size, int heap); /* 0x803774A8 */
Unk80071604* fn_80071604(Unk80071604* self, const char* name, Obj* type, unsigned count);
unsigned fn_8007366C(const char* a, const char* b);
extern const char lbl_805FE19C[];

void fn_80071688(Unk80071604* self, int chrg);

extern "C" void fn_8040074C(void* p, unsigned n);

extern const float lbl_806012A8;

struct Unk80084910_T8 {
    char pad0[8];
};

template <class T>
struct Unk80084910_K {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    T* m24;
};

typedef Unk80084910_K<Unk80084910_T8> K8;

extern "C" void* fn_803FFA60(void* s, int a, int n);

struct Db80599A6C_Tab {
    int w[1];
};

struct U {
    char pad0[0x4000];
};

struct Db8059A360_Rec {
    int m0;
    int m4;
    unsigned short m8;
    char pad[2];
};

struct Db8059A028_Cont {
    Db80599B54_Ent e[30];
    unsigned m528;
    Db8059A360_Rec a[30];
    unsigned m694;
    Db8059A360_Rec b[30];
    unsigned m800;
    const void* m804;
};

struct Unk80361580;
void fn_80361580(Unk80361580* p);
extern char lbl_80684218[];

inline void Db8059A40C_Clr(Db8059A360_Rec* r)
{
    r->m0 = 0;
    r->m4 = 0;
    r->m8 = 0;
}
inline void Db8059A40C_Set(Db8059A360_Rec* r, int a, int b, short c)
{
    r->m0 = a;
    r->m4 = b;
    r->m8 = c;
}

struct Db805999E8_Out {
    unsigned short a;
    unsigned short b;
};
struct Db805999E8_Bits {
    unsigned a : 8;
    unsigned b : 6;
    unsigned c : 3;
    unsigned pad : 15;
};
struct Db805999E8_Src {
    char pad0[1];
    char m1[2];
    char pad3[4];
    unsigned char m7;
    unsigned m8;
};
extern "C" void fn_80329FA0(void* out, int v, ...);

struct Db805997C4_Rec {
    unsigned a0 : 8;
    unsigned f0 : 16;
    unsigned f1 : 6;
    unsigned p0 : 2;
    unsigned f2 : 8;
    unsigned f3 : 7;
    unsigned f4 : 6;
    unsigned f5 : 1;
    unsigned f6 : 1;
    unsigned f7 : 1;
    unsigned f8 : 8;
    unsigned f9 : 3;
    unsigned f10 : 7;
    unsigned f11 : 7;
    unsigned f12 : 7;
    unsigned f13 : 7;
    unsigned p1 : 1;
    char pad0C[0x1C];
};
struct Db805997C4_Src {
    unsigned w0;
    unsigned w4;
};
struct Db805997C4_Date {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    Db805997C4_Date() {}
};
struct Db805997C4_Buf {
    unsigned short a;
    unsigned short b;
    ~Db805997C4_Buf() {}
};
extern int lbl_806022A4[];
extern "C" void fn_8040074C(void* p, unsigned n);
extern "C" void fn_800901C0__Fiiiiii(char* a, int b, unsigned c, char* d, int e, unsigned f);
extern "C" int fn_80090244__Fi(unsigned v);
extern "C" unsigned fn_8032A2CC(unsigned m, unsigned short y);
extern "C" int fn_80329E74(Db805997C4_Date d);
/* forward declarations (definitions are in address order) */
extern "C" void fn_80599594(Unk80071604* self, int a, VObj* obj);
extern "C" Unk80071604* fn_805995F0(Unk80071604* self, const char* name, Obj* type, unsigned count);
extern "C" void fn_8059966C(Unk80071604* self, int chrg);
extern "C" void fn_805996C8(Unk80071604* self, unsigned i);
extern "C" int fn_80599704();
extern "C" int fn_8059970C();
extern "C" int fn_80599714();
extern "C" int fn_8059971C(int a, int b, int c, int d);
extern "C" float fn_80599724();
extern "C" void fn_80599740();
extern "C" void fn_80599744();
extern "C" void fn_80599748(Unk80071604* self, int a, VObj* obj);
extern "C" Unk80084910_T8* fn_805997A4(K8* self, int i);
extern "C" Unk80084910_T8* fn_805997B4(K8* self, int i);
extern "C" Db805997C4_Rec* fn_805997C4(Db805997C4_Rec* dst, Db805997C4_Src* src);
extern "C" void* fn_805999B4(void* self, int a);
extern "C" Db805999E8_Bits* fn_805999E8(Db805999E8_Bits* self, Db805999E8_Src* src);
extern "C" int fn_80599A64();
extern "C" int fn_80599A6C(int i);
extern "C" void fn_80599A8C(void* self, int a, Unk80070DDC_Stream* io);
extern "C" U* fn_80599B24(U* self);
extern "C" void fn_80599B54(Db80599B54_Ent* self);
extern "C" void fn_80599B84(Db80599B54_Ent* self, int a, int b, int c);
extern "C" void fn_80599B94(Db80599B54_Ent* self, int i, int val);
extern "C" void fn_80599BC8(Db80599B54_Ent* self, int i, unsigned j);
extern "C" int fn_80599C40(Db80599B54_Ent* self, int i);
extern "C" int fn_80599C50(Db80599B54_Ent* self, int i, unsigned j);
extern "C" int fn_80599C80(Db80599B54_Ent* self, int i);
extern "C" void fn_80599CA0(Db80599B54_Ent* self, int a, Unk80070DDC_Stream* io);
extern "C" Db8059A028_Cont* fn_8059A028(Db8059A028_Cont* self);
extern "C" int fn_8059A0C8(Db8059A028_Cont* self, unsigned i, int k);
extern "C" int fn_8059A108(Db8059A028_Cont* self, unsigned i, int k, unsigned j);
extern "C" int fn_8059A14C(Db8059A028_Cont* self, unsigned i);
extern "C" void fn_8059A16C(Db8059A028_Cont* self, unsigned i, int* a, int* b, short* s);
extern "C" unsigned fn_8059A1DC(Db8059A028_Cont* self, Db80599B54_Ent* src);
extern "C" int fn_8059A360(Db8059A028_Cont* self, unsigned i);
extern "C" int fn_8059A384(Db8059A028_Cont* self, unsigned i);
extern "C" int fn_8059A3A8(Db8059A028_Cont* self, unsigned i);
extern "C" int fn_8059A3CC(Db8059A028_Cont* self, int v);
extern "C" unsigned fn_8059A40C(Db8059A028_Cont* self, int v0, int v1, short v2);
extern "C" int fn_8059A490(Db8059A028_Cont* self, unsigned i);
extern "C" int fn_8059A4B4(Db8059A028_Cont* self, unsigned i);
extern "C" int fn_8059A4D8(Db8059A028_Cont* self, unsigned i);
extern "C" unsigned fn_8059A4FC(Db8059A028_Cont* self, int v0, int v1, short v2);
extern "C" void fn_8059A580(Db8059A028_Cont* self);
extern "C" void fn_8059A61C(Db8059A028_Cont* self, int a, Unk80070DDC_Stream* io);

//@80599594
extern "C" DB_OVERLAY void fn_80599594(Unk80071604* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, (Unk80070DDC_Stream*)obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x28);
}

//@805995F0
extern "C" DB_OVERLAY Unk80071604* fn_805995F0(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_80684230;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 8, 0);
    fn_8040074C(self->m24, self->m1C * 8);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

extern "C" DB_OVERLAY void fn_8059966C(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684230;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" DB_OVERLAY void fn_805996C8(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 8, 8);
}

extern "C" DB_OVERLAY int fn_80599704()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_8059970C()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_80599714()
{
    return 0;
}

//@8059971C
extern "C" DB_OVERLAY int fn_8059971C(int a, int b, int c, int d)
{
    return d;
}

extern "C" DB_OVERLAY float fn_80599724()
{
    float f;
    return f = lbl_806012A8;
}

extern "C" DB_OVERLAY void fn_80599740()
{
}

extern "C" DB_OVERLAY void fn_80599744()
{
}

extern "C" DB_OVERLAY void fn_80599748(Unk80071604* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, (Unk80070DDC_Stream*)obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 8);
}

extern "C" DB_OVERLAY Unk80084910_T8* fn_805997A4(K8* self, int i)
{
    return &self->m24[i];
}

extern "C" DB_OVERLAY Unk80084910_T8* fn_805997B4(K8* self, int i)
{
    return &self->m24[i];
}

/* near-miss (97.5%): same stack layout problem as fn_8053DB30 (tu_8053CC9C): retail has the by-value Date copy at sp+8, the
   fn_80329FA0 buffer at sp+0xC and the Date at sp+0x10; ours puts the buffer first and the copy second. */
extern "C" DB_OVERLAY Db805997C4_Rec* fn_805997C4(Db805997C4_Rec* dst, Db805997C4_Src* src)
{
    fn_8040074C(dst, 0x28);
    fn_800901C0__Fiiiiii((char*)dst + 0xC, lbl_806022A4[0], (src->w4 >> 19) & 0x3FF, (char*)dst + 0x18, lbl_806022A4[1], (src->w4 >> 8) & 0x3FF);
    Db805997C4_Buf buf;
    fn_80329FA0(&buf, 1);
    unsigned short yr = *(unsigned char*)src + buf.b;
    unsigned mon = ((src->w0 >> 10) & 0xF) % 12;
    unsigned dim = fn_8032A2CC(mon, yr);
    Db805997C4_Date d;
    d.m0 = mon + 1;
    d.m2 = yr;
    d.m1 = ((src->w0 >> 4) & 0x1F) % dim + 1;
    dst->f0 = fn_80329E74(d);
    dst->f5 = (src->w0 >> 14) & 1;
    dst->f8 = (src->w0 >> 18) & 0x3F;
    dst->f9 = (src->w0 >> 15) & 7;
    dst->f1 = (src->w0 & 7) + 0x15;
    dst->f2 = (src->w4 >> 29) * 5 + 0x50;
    dst->f3 = (src->w4 & 0x7F) % 100;
    dst->f4 = (src->w0 >> 8) & 0x3F;
    dst->f10 = fn_80090244__Fi((src->w0 >> 3) & 0x7F);
    dst->f11 = fn_80090244__Fi((src->w4 >> 23) & 0x7F);
    dst->f12 = fn_80090244__Fi((src->w4 >> 12) & 0x7F);
    dst->f13 = fn_80090244__Fi((src->w4 >> 3) & 0x7F);
    return dst;
}

extern "C" DB_OVERLAY void* fn_805999B4(void* self, int a)
{
    fn_803FFA60(self, a, 8);
    return self;
}

extern "C" DB_OVERLAY Db805999E8_Bits* fn_805999E8(Db805999E8_Bits* self, Db805999E8_Src* src)
{
    volatile Db805999E8_Out o1;
    volatile Db805999E8_Out o2;
    fn_80329FA0((void*)&o1, 1);
    unsigned short t = o1.b;
    fn_80329FA0((void*)&o2, *(unsigned short*)src->m1);
    self->a = o2.b - t;
    self->b = src->m7;
    self->c = src->m8 >> 29;
    return self;
}

extern "C" DB_OVERLAY int fn_80599A64()
{
    return 1;
}

//@80599A6C
extern "C" DB_OVERLAY int fn_80599A6C(int i)
{
    Db80599A6C_Tab t = { { 10 } };
    return t.w[i];
}

//@80599A8C
extern "C" DB_OVERLAY void fn_80599A8C(void* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, (char*)self + 4, 4);
    io->v08(a, (char*)self + 8, 2);
}

extern "C" DB_OVERLAY U* fn_80599B24(U* self)
{
    fn_80599B54((Db80599B54_Ent*)self);
    return self;
}

//@80599B54
extern "C" DB_OVERLAY void fn_80599B54(Db80599B54_Ent* self)
{
    self->m0 = 0;
    fn_8040074C(self->s, 0x28);
}

//@80599B84
extern "C" DB_OVERLAY void fn_80599B84(Db80599B54_Ent* self, int a, int b, int c)
{
    *(int*)((char*)self + 0x14) = a;
    *(int*)((char*)self + 0x28) = b;
    self->m0 = c;
}

//@80599B94
extern "C" DB_OVERLAY void fn_80599B94(Db80599B54_Ent* self, int i, int val)
{
    int off = i * 0x14;
    unsigned char* c = (unsigned char*)self + off;
    unsigned n = c[0x10];
    if (n > 2)
        return;
    char* b = (char*)self + 4;
    *(int*)(b + (n * 4 + off)) = val;
    c[0x10] = c[0x10] + 1;
}

/* near-miss: retail keeps one shared stwx for both arms and recomputes self+off for the bounds test (30 insns, extra regs here) */
//@80599BC8
extern "C" DB_OVERLAY void fn_80599BC8(Db80599B54_Ent* self, int i, unsigned j)
{
    int off = i * 0x14;
    if (j >= *((unsigned char*)self + off + 0x10))
        return;
    do {
        int nx = j + 1;
        int val;
        if (nx == *((unsigned char*)self + off + 0x10)) {
            char* b = (char*)self + 4;
            int o = j * 4 + off;
            val = 0;
            *(int*)(b + o) = val;
        } else {
            char* b = (char*)self + 4;
            int o = nx * 4 + off;
            val = *(int*)(b + o);
            int o2 = j * 4 + off;
            *(int*)(b + o2) = val;
        }
        j = nx;
    } while (j < *((unsigned char*)self + off + 0x10));
    unsigned char* c = (unsigned char*)self + off;
    c[0x10] = c[0x10] - 1;
}

//@80599C40
extern "C" DB_OVERLAY int fn_80599C40(Db80599B54_Ent* self, int i)
{
    int off = i * 0x14;
    return *((unsigned char*)self + off + 0x10);
}

//@80599C50
extern "C" DB_OVERLAY int fn_80599C50(Db80599B54_Ent* self, int i, unsigned j)
{
    int off = i * 0x14;
    int r = 0;
    if (j < *((unsigned char*)self + off + 0x10)) {
        char* b = (char*)self + 4;
        int o = j * 4 + off;
        r = *(int*)(b + o);
    }
    return r;
}

//@80599C80
extern "C" DB_OVERLAY int fn_80599C80(Db80599B54_Ent* self, int i)
{
    int r = 0;
    if (i <= 1)
        r = self->s[i].m10;
    return r;
}

//@80599CA0
extern "C" DB_OVERLAY void fn_80599CA0(Db80599B54_Ent* self, int a, Unk80070DDC_Stream* io)
{
    for (unsigned i = 0; i < 2; i++)
        io->v08(a, &self->s[i], 0x14);
    io->v08(a, self, 2);
}

struct Db80599D30_T {
    int sid;
    int total;
    int b;
    int ab;
    int cnt;
    int ok;
};
extern "C" int fn_80075948__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" void fn_80078C04__18Unk8007A4DC_ScreeniPiN32(void* g, int a, int* o1, int* o2, int* o3, int* o4);
extern "C" float fn_80079EFC__18Unk8007B2B0_Screeni(void* g, int a);
extern "C" int fn_8007A270__18Unk8007A4DC_Screeni(void* g, int a);
extern "C" float fn_8007A768__18Unk8007A4DC_Screenii(void* g, int a, int b);
extern void* lbl_8061930C;

/* near-miss: 4 of 190 insns differ; retail sets the zero for result before the argument copies and copies it into i (mr r30,r26), ours emits two li after the copies */
extern "C" DB_OVERLAY int fn_80599D30(Db80599B54_Ent* ent, int skip)
{
    int result = 0;
    void* scr = lbl_8061930C;
    Db80599D30_T t[2];
    int a, b, c, d;
    unsigned i = 0;
    unsigned k;
    do {
        int ok = 0;
        k = 0;
        int sid = fn_80075948__18Unk8007B2B0_Screeni(scr, fn_80599C80(ent, i));
        fn_80078C04__18Unk8007A4DC_ScreeniPiN32(scr, sid, &a, &b, &c, &d);
        while (k < fn_80599C40(ent, i)) {
            if (fn_8007A270__18Unk8007A4DC_Screeni(scr, fn_80599C50(ent, i, (unsigned char)k)))
                ok++;
            k++;
        }
        t[i].sid = sid;
        t[i].total = a + b + c + d;
        t[i].b = b;
        t[i].ab = a + b;
        t[i].cnt = fn_80599C40(ent, i);
        t[i].ok = ok;
        if (t[i].cnt == 0)
            result = i + 2;
        i++;
    } while (i <= 1);
    if (result == 0 && t[1].cnt == 0 && t[0].cnt == 0)
        result = 1;
    for (i = 0; i <= 1; i++) {
        if (result == 0) {
            unsigned o = (i == 0);
            int x = t[i].total + (t[o].cnt - t[i].cnt);
            int y = t[o].ok - t[i].ok;
            if ((unsigned)x > 100)
                result = i + 4;
            else if ((unsigned)(t[i].ab + y) > 60)
                result = i + 10;
        }
    }
    Db80599D30_T* p = t;
    for (i = 0; i <= 1; i++) {
        unsigned o = (i == 0);
        if (result == 0 && skip == 0) {
            k = 0;
            float base = fn_80079EFC__18Unk8007B2B0_Screeni(scr, p->sid);
            float s = base;
            while (k < fn_80599C40(ent, i)) {
                float f = fn_8007A768__18Unk8007A4DC_Screenii(scr, 5, fn_80599C50(ent, i, (unsigned char)k));
                k++;
                s = s + f;
            }
            k = 0;
            while (k < fn_80599C40(ent, o)) {
                float f = fn_8007A768__18Unk8007A4DC_Screenii(scr, 5, fn_80599C50(ent, o, (unsigned char)k));
                k++;
                s = s - f;
            }
            if (!(s >= 0.0f) && !(s > base))
                result = i + 12;
        }
        p++;
    }
    return result;
}

//@8059A028
extern "C" DB_OVERLAY Db8059A028_Cont* fn_8059A028(Db8059A028_Cont* self)
{
    self->m804 = lbl_80684218;
    char* p = (char*)self;
    int n = 29;
    do {
        fn_80599B54((Db80599B54_Ent*)p);
        p += 0x2C;
    } while (n-- != 0);
    p = (char*)self + 0x52C;
    n = 29;
    do {
        fn_80361580((Unk80361580*)p);
        p += 0xC;
    } while (n-- != 0);
    p = (char*)self + 0x698;
    n = 29;
    do {
        fn_80361580((Unk80361580*)p);
        p += 0xC;
    } while (n-- != 0);
    fn_8059A580(self);
    return self;
}

//@8059A0C8
extern "C" DB_OVERLAY int fn_8059A0C8(Db8059A028_Cont* self, unsigned i, int k)
{
    int r = 0;
    if (i < self->m528)
        r = fn_80599C40(&self->e[i], k);
    return r;
}

//@8059A108
extern "C" DB_OVERLAY int fn_8059A108(Db8059A028_Cont* self, unsigned i, int k, unsigned j)
{
    int r = 0;
    if (i < self->m528)
        r = fn_80599C50(&self->e[i], k, j);
    return r;
}

//@8059A14C
extern "C" DB_OVERLAY int fn_8059A14C(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m528)
        r = self->e[i].m0;
    return r;
}

//@8059A16C
extern "C" DB_OVERLAY void fn_8059A16C(Db8059A028_Cont* self, unsigned i, int* a, int* b, short* s)
{
    if (i < self->m528) {
        Db80599B54_Ent* e = &self->e[i];
        *a = fn_80599C80(e, 0);
        *b = fn_80599C80(e, 1);
        *s = e->m0;
    }
}

extern "C" DB_OVERLAY unsigned fn_8059A1DC(Db8059A028_Cont* self, Db80599B54_Ent* src)
{
    unsigned n = self->m528;
    unsigned i;
    unsigned k;
    if (n <= 0x1D) {
        i = n;
        self->m528 = i + 1;
    } else {
        for (k = 0; k <= 28; k++)
            self->e[k] = self->e[k + 1];
        i = 29;
    }
    Db80599B54_Ent* e = &self->e[i];
    fn_80599B54(e);
    if (src != 0) {
        int a = fn_80599C80(src, 0);
        k = 0;
        int b = fn_80599C80(src, 1);
        fn_80599B84(e, a, b, src->m0);
        do {
            unsigned cnt = fn_80599C40(src, k);
            for (unsigned j = 0; j < cnt; j++) {
                int v = fn_80599C50(src, k, (unsigned char)j);
                fn_80599B94(&self->e[i], k, v);
            }
            k++;
        } while (k <= 1);
    }
    return i;
}

//@8059A360
extern "C" DB_OVERLAY int fn_8059A360(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m694)
        r = *(int*)((char*)self + i * 12 + 0x52C);
    return r;
}

//@8059A384
extern "C" DB_OVERLAY int fn_8059A384(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m694)
        r = *(int*)((char*)self + i * 12 + 0x530);
    return r;
}

//@8059A3A8
extern "C" DB_OVERLAY int fn_8059A3A8(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m694)
        r = *(unsigned short*)((char*)self + i * 12 + 0x534);
    return r;
}

//@8059A3CC
extern "C" DB_OVERLAY int fn_8059A3CC(Db8059A028_Cont* self, int v)
{
    unsigned n = self->m694;
    unsigned i = 0;
    if (i < n) {
        Db8059A360_Rec* p = self->a;
        do {
            if (p->m0 == v)
                return 1;
            i++;
            p++;
        } while (i < n);
    }
    return 0;
}

extern "C" DB_OVERLAY unsigned fn_8059A40C(Db8059A028_Cont* self, int v0, int v1, short v2)
{
    unsigned n = self->m694;
    unsigned i;
    if (n <= 0x1C) {
        i = n;
        self->m694 = i + 1;
    } else {
        for (int k = 0; k < 29; k++)
            self->a[k] = self->a[k + 1];
        i = 29;
    }
    Db8059A40C_Clr(&self->a[i]);
    Db8059A40C_Set(&self->a[i], v0, v1, v2);
    return i;
}

//@8059A490
extern "C" DB_OVERLAY int fn_8059A490(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m800)
        r = *(int*)((char*)self + i * 12 + 0x698);
    return r;
}

//@8059A4B4
extern "C" DB_OVERLAY int fn_8059A4B4(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m800)
        r = *(int*)((char*)self + i * 12 + 0x69C);
    return r;
}

//@8059A4D8
extern "C" DB_OVERLAY int fn_8059A4D8(Db8059A028_Cont* self, unsigned i)
{
    int r = 0;
    if (i < self->m800)
        r = *(unsigned short*)((char*)self + i * 12 + 0x6A0);
    return r;
}

extern "C" DB_OVERLAY unsigned fn_8059A4FC(Db8059A028_Cont* self, int v0, int v1, short v2)
{
    unsigned n = self->m800;
    unsigned i;
    if (n <= 0x1C) {
        i = n;
        self->m800 = i + 1;
    } else {
        for (int k = 0; k < 29; k++)
            self->b[k] = self->b[k + 1];
        i = 29;
    }
    Db8059A40C_Clr(&self->b[i]);
    Db8059A40C_Set(&self->b[i], v0, v1, v2);
    return i;
}

extern "C" DB_OVERLAY void fn_8059A580(Db8059A028_Cont* self)
{
    self->m800 = 0;
    self->m694 = 0;
    self->m528 = 0;
    Db80599B54_Ent* p = self->e;
    Db80599B54_Ent* end = &self->e[29];
    do {
        fn_80599B54(p);
        p++;
    } while (p <= end);
    for (int k = 0; k < 30; k++) {
        Db8059A360_Rec* r = &self->a[k];
        r->m0 = 0;
        r->m4 = 0;
        r->m8 = 0;
    }
    for (int k = 0; k < 30; k++) {
        Db8059A360_Rec* r = &self->b[k];
        r->m0 = 0;
        r->m4 = 0;
        r->m8 = 0;
    }
}

extern "C" DB_OVERLAY void fn_8059A61C(Db8059A028_Cont* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, &self->m528, 4);
    io->v08(a, &self->m694, 4);
    io->v08(a, &self->m800, 4);
    Db80599B54_Ent* p = self->e;
    Db80599B54_Ent* end = &self->e[29];
    do {
        fn_80599CA0(p, a, io);
        p++;
    } while (p <= end);
    unsigned k = 0;
    Db8059A360_Rec* r = self->a;
    do {
        k++;
        fn_80599A8C(r, a, io);
        r++;
    } while (k <= 29);
    r = self->b;
    unsigned k2 = 0;
    do {
        k2++;
        fn_80599A8C(r, a, io);
        r++;
    } while (k2 <= 29);
}
