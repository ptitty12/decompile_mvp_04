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

extern "C" void fn_80599B54(Db80599B54_Ent* self);

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

extern "C" void fn_8040074C(void* p, unsigned n);

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

extern const float lbl_806012A8;

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

extern "C" DB_OVERLAY Unk80084910_T8* fn_805997A4(K8* self, int i)
{
    return &self->m24[i];
}

extern "C" DB_OVERLAY Unk80084910_T8* fn_805997B4(K8* self, int i)
{
    return &self->m24[i];
}

extern "C" void* fn_803FFA60(void* s, int a, int n);

extern "C" DB_OVERLAY void* fn_805999B4(void* self, int a)
{
    fn_803FFA60(self, a, 8);
    return self;
}

extern "C" DB_OVERLAY int fn_80599A64()
{
    return 1;
}

struct Db80599A6C_Tab {
    int w[1];
};

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

struct U {
    char pad0[0x4000];
};


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

extern "C" void fn_8059A580(Db8059A028_Cont* self);
struct Unk80361580;
void fn_80361580(Unk80361580* p);
extern char lbl_80684218[];

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
