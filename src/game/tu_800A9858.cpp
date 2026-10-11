/*
 * Game code, .text 0x800A9858-0x800AB0E8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/chooser.h"
#include "game/tu_800A8684.h"

int fn_8057CE00(int v);

/* Singleton (0x10 bytes) at lbl_80619C64: three ints, then the vptr at +0xC
 * (lbl_8065BE58). Evidence: ctor fn_800AA0B4, dtor fn_800AA0D4, fn_800AA2FC. */
extern const char lbl_8065BE58[];
class UnkFEA {
public:
    UnkFEA();
    ~UnkFEA();
    int m0;
    int m4;
    int m8;
    const void* mC;
};
/* The same object seen through its virtual destructor (fn_800AA144 deletes it
 * through the vtable, in-charge 3). */
class UnkFEAV {
public:
    int m0;
    int m4;
    int m8;
    virtual ~UnkFEAV();
};
extern UnkFEA* lbl_80619C64;
extern "C" UnkFEA* fn_800AA19C();
extern "C" void fn_800AA2FC(UnkFEA* s, int a, int b, int c);
int fn_800AA550(UnkFEA* s, int a, int b);
struct UnkFEArr {          /* fn_800AB098 / fn_800AB0C4: one-element array, count, pointer */
    UnkFEArr();
    int m0[1];
    int m4;
    int m8;
};
struct Unk8037C7FC_Data {  /* fn_8037C7FC() object: +4 selects the table at lbl_80619C68 / lbl_80619C84 */
    int m0;
    int m4;
};
extern int lbl_80619C68[];
extern int lbl_80619C84[];
extern int lbl_80619CA0[];
extern int lbl_80619CD0[];
extern int lbl_80619D00;
extern char lbl_806878CC[];
extern char lbl_80687954[];
/* Growable int array (vptr lbl_8065BED0): count at +4, data at +8 (fn_800AAAD8, fn_800AAB40). */
struct UnkFEVec {
    const void* m0;
    int m4;
    int* m8;
};
/* The 0x24-byte list object (fn_800AA67C): base Unk8037B3E8 (hash 0x8CA866F4), vector at +4. */
struct UnkFEL {
    const void* m0;
    UnkFEVec m4;
    int m10;
    int m14;
    int m18;
    int m1C;
    char m20;
};
/* Table object with sixteen vptr-like words (fn_800AAD6C, static dtor of lbl_806878CC). */
struct UnkFETbl {
    const void* m0;
    char pad4[4];
    const void* m8;
    char padC[4];
    const void* m10;
    char pad14[4];
    const void* m18;
    char pad1C[4];
    const void* m20;
    char pad24[4];
    const void* m28;
    char pad2C[4];
    const void* m30;
    char pad34[4];
    const void* m38;
    char pad3C[0x48 - 0x3C];
    const void* m48;
    char pad4C[4];
    const void* m50;
    char pad54[4];
    const void* m58;
    char pad5C[4];
    const void* m60;
    char pad64[4];
    const void* m68;
    char pad6C[0x7C - 0x6C];
    const void* m7C;
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" {
void fn_800A915C(UnkFEObj* self);
void fn_800A8E40(UnkFEObj* self, int* flag);
void fn_800A8C48(UnkFEObj* self, int* flag);
void fn_800A89DC(UnkFEObj* self, int* flag);
void fn_800A8B70(UnkFEObj* self, int* flag);
void fn_800A94B4(UnkFEObj* self, int* flag);
void fn_800A9328(UnkFEObj* self, int* flag);
int fn_800A96A4(UnkFEByte* self);
void fn_800A9818(void* self, Unk8037B3E8* o);
void fn_800A92D0(void* self, Unk8037B3E8* o);
void fn_800A8F40(void* self, Unk8037B3E8* o);
void fn_800A8DE8(void* self, Unk8037B3E8* o);
void fn_800A8B30(void* self, Unk8037B3E8* o);
void fn_800A8BF0(void* self, Unk8037B3E8* o);
void fn_800A9598(void* self, Unk8037B3E8* o);
void fn_800A945C(void* self, Unk8037B3E8* o);
}

extern const char lbl_8065BA40[];
extern const char lbl_8065BC28[];
extern const char lbl_8065CFD0[];
extern const char lbl_8065BE70[];
extern const char lbl_8065BED0[];
extern const char lbl_805B7084[];
extern "C" {
int fn_8037CDE0(Unk8037C7FC* o, const char* s, int v);
void fn_8037B424(void* p, int c);
void fn_80356798(void* p);
void* fn_803774A8(unsigned n, int heap);
void fn_80377408(void* p);
}

extern "C" {
void fn_8037B458(void* self, const char* name, int* field, int a, int b);
void fn_8037B584(void* self, const char* name, char* field, int a, int b);
void fn_8037B6B0(void* self, const char* name, int* field, const char* values);
void fn_8037B5FC(void* self, const char* name, int* field);
int fn_80409CF0(void (*f)());
}

extern const char* lbl_80619D04;
extern const char lbl_805B8C84[];
extern "C" void fn_80378E48(char** s, int* n, int delim, char** tok, int* used);
void* fn_800AA874(char* p, int i);
void* fn_800AAF1C(UnkFEObj* self);
int fn_800AAF5C(char* self, char* a);
void fn_800AB01C(char* p, int* a);
struct FEPair8 {
    UnkFEL* m0;
    int m4;
};
struct FEMsg16 {
    char name[16];
};
FEPair8 fn_800AA8C4(UnkFEL* o, FEMsg16* name, int* z);
extern "C" {
void fn_8035682C(FEMsg16* m);
void fn_8040B830(char* dst, const char* src, int n);
}

struct Unk8007F198_C;
int fn_8007FB2C(Unk8007F198_C* c, int i);
int fn_8007FDA8(Unk8007F198_C* c, int a, int b);
struct FE80619948 {
    char pad0[0x28];
    int m28;
    char pad2C[0x64 - 0x2C];
    char* m64;
};
struct FE80619E0 {
    int m0;
    struct FE80619E4* m4;
};
struct FE80619E4 {
    char pad0[0x10];
    struct FE80619E8* m10;
};
struct FE80619E8 {
    char pad0[0x120];
    int m120;
};
extern FE80619948* lbl_80619948;
extern Unk8007F198_C* lbl_8061930C;
extern FE80619E0* lbl_806192E0;
extern "C" {
int fn_8056AA08(int a, int b, int c);
int fn_800C2208(int* p);
int fn_800A2E6C(FE80619948* p);
}

extern const char lbl_805B8CCC[];
extern const char lbl_805B8CE8[];
extern const char lbl_805B8D00[];
extern const char lbl_805B8C90[];
extern const char lbl_805B8C9C[];
extern const char lbl_805B8CA8[];
extern const char lbl_805B8CB4[];
extern const char lbl_805B8CC0[];
extern int lbl_80687950;
extern int lbl_8068799C;
int fn_800A9E1C(UnkFEObj* self, char* s);
int fn_800A9B0C(UnkFEObj* self, int a);
int fn_800A9C90(UnkFEObj* self, int a);
void fn_800AA5A0();
void fn_800AA5CC();
void fn_800AAD6C(char* self, int a);
void fn_800AA6FC(char* self, int a);
void* fn_800AA67C(void* self);
void* fn_800AABA4(void* self);
void* fn_800AAA8C(char* self, int a);
void fn_800AAAD8(char* a, char* b);
void fn_800AAB40(UnkFEVec* self, int c);
void fn_800AA46C(UnkFEA* self, UnkFEL* a, UnkFEL* b);
int fn_800AA378(UnkFEA* self);
int fn_800AA3B4(UnkFEA* self);
int fn_800AA3F0(UnkFEA* self);

/* ---- generated externs ---- */
extern const char lbl_805B7340[];
extern const char lbl_805B7374[];
extern const char lbl_805B7640[];
extern const char lbl_805B8ABC[];
extern const char lbl_805B8AC8[];
extern const char lbl_805B8AD0[];
extern const char lbl_805B8AE0[];
extern const char lbl_805B8B4C[];
extern const char lbl_805B8B54[];
extern const char lbl_805B8C2C[];
extern const char* lbl_80619C30[];
extern const char* lbl_80619C48[];
extern int lbl_805C2E28[];
extern int lbl_805C2E3C[];
extern int lbl_80619C10;
extern int lbl_80619C2C;
extern int lbl_80619C44;

/* ---- functions ---- */

int fn_800A9858(UnkFEStr* self)
{
    return fn_8040B6A0(self->m4) != 0;
}

int fn_800A988C(UnkFEStr* self, char* s)
{
    return self->fn_vslot3() ? fn_8040B574(s, self->m4) == 0 : 1;
}

void fn_800A98F4(UnkFEStr* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        if (self->fn_vslot6(&p, n)) {
            fn_8040B61C(self->m4, p);
        } else {
            self->m4[0] = 0;
        }
    }
}

void fn_800A9974(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7374, lbl_805B8ABC, self, (int)lbl_805B8AC8);
}

int fn_800A99B4(UnkFEObj* self)
{
    if (self->m4 != 0x0) {
        return 1;
    }
    return 0;
}

int fn_800A99CC()
{
    return 0;
}

int fn_800A99D4(UnkFEObj* self, int a, int b)
{
    if (!self->fn_vslot3()) {
        return 1;
    }
    return fn_800AA550(fn_800AA19C(), self->m4, b);
}

void fn_800A9A38(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        int r = self->fn_vslot6(&p, n);
        if (r) {
            r = fn_80378568(p, 0);
        }
        self->m4 = r;
    }
}

void fn_800A9AB4(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7374, lbl_805B8AD0, self, (int)lbl_805B8AE0);
}

int fn_800A9AF4(UnkFEObj* self)
{
    if (self->m4 == -0x3e7) {
        return 0;
    }
    return 1;
}

int fn_800A9B0C(UnkFEObj* self, int a)
{
    return self->fn_vslot3() ? self->m4 == fn_8057CE00(fn_800B555C()->m608) : 1;
}

void fn_800A9B78(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        int i = 0;
        if (self->fn_vslot6(&p, n)) {
            for (; i <= 0x4; i++) {
                if (fn_8040B574(p, lbl_80619C30[i]) == 0) {
                    self->m4 = lbl_805C2E28[i];
                    break;
                }
            }
        } else {
            self->m4 = -0x3e7;
        }
    }
}

void fn_800A9C38(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B8B4C, self, lbl_80619C2C);
}

int fn_800A9C78(UnkFEObj* self)
{
    if (self->m4 == -0x3e7) {
        return 0;
    }
    return 1;
}

int fn_800A9C90(UnkFEObj* self, int a)
{
    if (!self->fn_vslot3()) {
        return 1;
    }
    int r = 1;
    if (self->m4 == fn_8057CE00(fn_800B555C()->m608)) {
        r = 0;
    }
    return r;
}

void fn_800A9D04(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        int i = 0;
        if (self->fn_vslot6(&p, n)) {
            for (; i <= 0x4; i++) {
                if (fn_8040B574(p, lbl_80619C30[i]) == 0) {
                    self->m4 = lbl_805C2E28[i];
                    break;
                }
            }
        } else {
            self->m4 = -0x3e7;
        }
    }
}

void fn_800A9DC4(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B8B54, self, lbl_80619C2C);
}

int fn_800A9E04(UnkFEObj* self)
{
    if (self->m4 == 0x0) {
        return 0;
    }
    return 1;
}

/* near-miss (86/86 insns, 37 slots): retail joins every failing arm at one shared `li r3,0` block placed after the 0x20 return; early-return, goto and nested forms tried */
int fn_800A9E1C(UnkFEObj* self, char* s)
{
    if (self->fn_vslot3()) {
        if (self->m4 & 1) {
            FE80619948* o = lbl_80619948;
            int h = fn_800C2208(fn_800B555C()->m8);
            if (!fn_8056AA08(o->m28, h, 0)) {
                return 0;
            }
        }
        if (self->m4 & 2) {
            Unk8007F198_C* c = lbl_8061930C;
            if (!fn_8007FDA8(c, fn_8007FB2C(c, 0) - 1, 0)) {
                return 0;
            }
        }
        if (self->m4 & 4) {
            if (lbl_806192E0->m4->m10->m120 == 0) {
                return 0;
            }
        }
        if (self->m4 & 8) {
            return 0;
        }
        if (self->m4 & 0x20) {
            return fn_800A2E6C(lbl_80619948) ^ 1;
        } else if (self->m4 & 0x40) {
            FE80619948* o = lbl_80619948;
            int off = 0;
            for (int k = 0; k < 4; k++) {
                int a = *(int*)(o->m64 + 8 + off);
                int b = *(int*)(o->m64 + 0x4F4 + off);
                if (b * (a + 1) != 0) {
                    return 0;
                }
                off += 0x4F4;
            }
        }
    }
    return 1;
}

void fn_800A9F74(UnkFEObj* self, char* s, int n)
{
    unsigned used = 0;
    char buf[0x14];
    if (fn_8040B6A0(s) != 0) {
        do {
            fn_80378B68(s, n, buf, 0x14, lbl_80619C10, 1, &used);
            int rem = n - 1;
            n = rem - used;
            if (n > 0) {
                s += used + 1;
            } else {
                s += used;
            }
            for (int i = 0; i <= 0x6; i++) {
                if (fn_8040B574(buf, lbl_80619C48[i]) == 0) {
                    self->m4 |= lbl_805C2E3C[i];
                    break;
                }
            }
        } while (n > 0);
    } else {
        self->m4 = 0;
    }
}

void fn_800AA074(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7640, lbl_805B8C2C, self, lbl_80619C44);
}

UnkFEA::UnkFEA()
{
    mC = lbl_8065BE58;
    m0 = 0;
    m4 = 0;
}

UnkFEA::~UnkFEA()
{
    mC = lbl_8065BE58;
}

void fn_800AA108()
{
    lbl_80619C64 = new (0) UnkFEA;
}

void fn_800AA144()
{
    if (lbl_80619C64) {
        delete (UnkFEAV*)lbl_80619C64;
    }
    lbl_80619C64 = 0;
}

extern "C" UnkFEA* fn_800AA19C()
{
    return lbl_80619C64;
}

/* near-miss (60/60 insns, register assignment and arm order differ): retail keeps idx*4 in r0 per arm and the name arm after the nameless arm; ternary/nested forms tried */
UnkFEL* fn_800AA1A8(void* unused, int idx, const char* name)
{
    int* tbl;
    if (((Unk8037C7FC_Data*)fn_8037C7FC())->m4 != 0) {
        tbl = lbl_80619C68;
    } else {
        tbl = lbl_80619C84;
    }
    int v = tbl[idx];
    void* o = (void*)fn_8037C7FC()->fn_8037CE98(0x8CA866F4, v, 0);
    if (o == 0) {
        return 0;
    }
    if (name == 0) {
        void* r = fn_800AA874((char*)o, 0);
        if (r == 0) {
            return 0;
        }
        return (UnkFEL*)fn_800AAF1C((UnkFEObj*)r);
    }
    FEMsg16 m;
    FEMsg16* p = &m;
    int z = 0;
    fn_8035682C(p);
    fn_8040B830(p->name, name, 0xF);
    p->name[15] = 0;
    FEPair8 ret = fn_800AA8C4((UnkFEL*)o, p, &z);
    return ret.m0;
}

void fn_800AA298(int i, int v)
{
    if (i <= 6) {
        if (((Unk8037C7FC_Data*)fn_8037C7FC())->m4 != 0) {
            lbl_80619C68[i] = v;
        } else {
            lbl_80619C84[i] = v;
        }
    }
}

extern "C" void fn_800AA2FC(UnkFEA* s, int a, int b, int c)
{
    s->m0 = a;
    s->m4 = b;
    s->m8 = c;
}

int fn_800AA30C(UnkFEA* self, int k)
{
    int v;
    if (k == 0) {
        v = fn_800AA378(self);
    } else if (k == 2) {
        v = fn_800AA3F0(self);
    } else {
        v = fn_800AA3B4(self);
    }
    fn_800AA46C(self, (UnkFEL*)v, 0);
    return v;
}

int fn_800AA378(UnkFEA* self)
{
    return fn_8037CDE0(fn_8037C7FC(), lbl_805B7084, self->m0);
}

int fn_800AA3B4(UnkFEA* self)
{
    return fn_8037CDE0(fn_8037C7FC(), lbl_805B7084, self->m4);
}

int fn_800AA3F0(UnkFEA* self)
{
    return fn_8037CDE0(fn_8037C7FC(), lbl_805B7084, self->m8);
}

void fn_800AA42C()
{
    for (int i = 0; i < 12; i++) {
        lbl_80619CA0[i] = 0;
        lbl_80619CD0[i] = 0;
    }
    lbl_80619D00 = -1;
}

void fn_800AA46C(UnkFEA* self, UnkFEL* a, UnkFEL* b)
{
    int x = a->m18;
    int y = 0;
    if (b) {
        y = b->m18;
    }
    int found = 0;
    for (int i = lbl_80619D00; i >= 0; i--) {
        if (lbl_80619CA0[i] == x) {
            int nt = lbl_80619D00 - (lbl_80619D00 - i) - 1;
            for (int k = lbl_80619D00; k > nt; k--) {
                lbl_80619CA0[k] = 0;
                lbl_80619CD0[k] = 0;
            }
            lbl_80619D00 = nt;
            found = 1;
            break;
        }
    }
    if (found) {
        return;
    }
    if (b == 0) {
        return;
    }
    int t = lbl_80619D00 + 1;
    lbl_80619D00 = t;
    lbl_80619CA0[t] = y;
    lbl_80619CD0[t] = b->m1C;
}

int fn_800AA550(UnkFEA* s, int a, int b)
{
    for (int i = lbl_80619D00; i >= 0; i--) {
        if (lbl_80619CA0[i] == a) {
            if (lbl_80619CD0[i] == b) {
                return 1;
            }
            break;
        }
    }
    return 0;
}

void fn_800AA5A0()
{
    fn_800AAD6C(lbl_806878CC, 2);
}

void fn_800AA5CC()
{
    fn_800AA6FC(lbl_80687954, 2);
}

void fn_800AA5F8()
{
    if (lbl_80687950 == 0) {
        fn_800AABA4(lbl_806878CC);
        lbl_80687950 = 1;
        fn_80409CF0(fn_800AA5A0);
    }
    if (lbl_8068799C == 0) {
        fn_800AA67C(lbl_80687954);
        lbl_8068799C = 1;
        fn_80409CF0(fn_800AA5CC);
    }
}

void* fn_800AA67C(void* p)
{
    new (p) Unk8037B3E8(0x8CA866F4);
    UnkFEL* self = (UnkFEL*)p;
    UnkFEVec* v = &self->m4;
    self->m0 = lbl_8065BE70;
    fn_80356798(v);
    self->m4.m0 = lbl_8065BED0;
    v->m4 = 0;
    v->m8 = 0;
    self->m14 = -1;
    self->m10 = 0;
    self->m18 = 0;
    self->m1C = 0;
    self->m20 = 0;
    return self;
}

void fn_800AA6FC(char* p, int c)
{
    UnkFEL* self = (UnkFEL*)p;
    self->m0 = lbl_8065BE70;
    if (self->m10 != 0) {
        fn_800AA298(self->m14, 0);
    }
    fn_800AAB40(&self->m4, 2);
    fn_8037B424(self, c);
}

void* fn_800AA764()
{
    return fn_800AA67C(operator new(0x48, lbl_806EF9B4));
}

void fn_800AA794(UnkFEL* self)
{
    fn_8037B458(self, lbl_805B8C84, &self->m10, 0, 0);
    fn_8037B584(self, lbl_805B8C90, &self->m20, 0, 0);
    ((Unk8037B3E8*)self)->fn_8037B728(lbl_805B8C9C, lbl_805B8CA8, &self->m4, 0);
    fn_8037B6B0(self, lbl_805B8CB4, &self->m14, lbl_80619D04);
    fn_8037B5FC(self, lbl_805B8CC0, &self->m18);
}

void fn_800AA840(UnkFEL* self, int v)
{
    int c = self->m10;
    self->m1C = v;
    if (c != 0) {
        fn_800AA298(self->m14, v);
    }
}

void* fn_800AA874(char* p, int i)
{
    return fn_800AAA8C(p + 4, i);
}

void fn_800AA898(char* a, char* b)
{
    fn_800AAAD8(b + 4, a + 4);
}

/* near-miss (55/55 insns, callee-saved register numbering only): retail pr=r24 name=r25 n=r26 z=r27; all 720 orders of the six prologue statements tried. The caller fn_800AA1A8 emits `crclr cr1eq`, so retail declares this callee variadic at that call */
FEPair8 fn_800AA8C4(UnkFEL* o, FEMsg16* name, int* z)
{
    FEPair8 res;
    FEPair8* pr = &res;
    res.m0 = 0;
    pr->m4 = 0;
    UnkFEVec* v = &o->m4;
    int n = v->m4;
    for (int i = 0; i < n; i++) {
        void* e = fn_800AAA8C((char*)v, i);
        if (fn_800AAF5C((char*)e, (char*)name)) {
            fn_800AB01C((char*)e, z);
            res.m0 = (UnkFEL*)fn_800AAF1C((UnkFEObj*)e);
            pr->m4 = i;
            break;
        }
    }
    if (res.m0 != 0) {
        if (o->m18 != res.m0->m18) {
            fn_800AA46C((UnkFEA*)fn_800AA19C(), res.m0, o);
        }
    }
    return res;
}

void fn_800AA9A0(UnkFEVec* self, char* s, int n)
{
    int used = 0;
    char* tok;
    int tmp[100];
    if (self->m4 > 0) {
        fn_80377408(self->m8);
        self->m8 = 0;
        self->m4 = 0;
    }
    while (fn_80378E48(&s, &n, 0x2C, &tok, &used), used > 0) {
        tmp[self->m4] = fn_80378568(tok, used);
        self->m4 = self->m4 + 1;
    }
    self->m8 = (int*)fn_803774A8(self->m4 * 4, lbl_806EF9B4);
    for (int i = 0; i < self->m4; i++) {
        self->m8[i] = tmp[i];
    }
}

void* fn_800AAA8C(char* p, int i)
{
    UnkFEVec* self = (UnkFEVec*)p;
    return (void*)fn_8037C7FC()->fn_8037CE98(0x6A8513FF, self->m8[i], 0);
}

void fn_800AAAD8(char* pa, char* pb)
{
    UnkFEVec* a = (UnkFEVec*)pa;
    UnkFEVec* b = (UnkFEVec*)pb;
    if (b->m8 != 0) {
        if (a->m8 != 0) {
            fn_80377408(a->m8);
            a->m8 = 0;
            a->m4 = 0;
        }
        a->m8 = (int*)fn_803774A8(b->m4 * 4, 0);
    }
}

void fn_800AAB40(UnkFEVec* self, int c)
{
    self->m0 = lbl_8065BED0;
    if (self->m8 != 0) {
        fn_80377408(self->m8);
        self->m8 = 0;
        self->m4 = 0;
    }
    if (c & 1) {
        fn_80377408(self);
    }
}

void fn_800AAD6C(char* p, int c)
{
    UnkFETbl* self = (UnkFETbl*)p;
    self->m0 = lbl_8065BA40;
    self->m7C = lbl_8065BC28;
    self->m68 = lbl_8065BC28;
    self->m60 = lbl_8065CFD0;
    self->m58 = lbl_8065CFD0;
    self->m50 = lbl_8065CFD0;
    self->m48 = lbl_8065CFD0;
    self->m38 = lbl_8065CFD0;
    self->m30 = lbl_8065CFD0;
    self->m20 = lbl_8065BC28;
    self->m18 = lbl_8065BC28;
    self->m10 = lbl_8065BC28;
    self->m28 = lbl_8065CFD0;
    self->m8 = lbl_8065BC28;
    fn_8037B424(self, c);
}

void* fn_800AADE0()
{
    return fn_800AABA4(operator new(0x84, lbl_806EF9B4));
}

void fn_800AAE10(char* p)
{
    Unk8037B3E8* o = (Unk8037B3E8*)p;
    o->fn_8037B7E8(lbl_805B8CCC);
    fn_800A9818(p + 0x7C, o);
    fn_800A9974(p + 0x68, o);
    fn_800A9AB4(p + 8, o);
    fn_800A9C38(p + 0x10, o);
    fn_800A9DC4(p + 0x18, o);
    fn_800AA074(p + 0x20, o);
    o->fn_8037B830(lbl_805B8CCC);
    o->fn_8037B7E8(lbl_805B8CE8);
    fn_800A92D0(p + 0x28, o);
    fn_800A8F40(p + 0x30, o);
    fn_800A8DE8(p + 0x38, o);
    fn_800A8B30(p + 0x48, o);
    fn_800A8BF0(p + 0x50, o);
    fn_800A9598(p + 0x58, o);
    fn_800A945C(p + 0x60, o);
    o->fn_8037B830(lbl_805B8CE8);
    o->fn_8037B5FC(lbl_805B8D00, (int*)(p + 4));
}

void* fn_800AAF1C(UnkFEObj* self)
{
    return (void*)fn_8037C7FC()->fn_8037CE98(0x8CA866F4, self->m4, 0);
}

int fn_800AAF5C(char* self, char* a)
{
    if (!fn_800A96A4((UnkFEByte*)(self + 0x7C))) {
        return 0;
    }
    if (!fn_800A988C((UnkFEStr*)(self + 0x68), a)) {
        return 0;
    }
    if (!fn_800A99D4((UnkFEObj*)(self + 8), (int)a, *(int*)(self + 4))) {
        return 0;
    }
    if (!fn_800A9B0C((UnkFEObj*)(self + 0x10), (int)a)) {
        return 0;
    }
    if (!fn_800A9C90((UnkFEObj*)(self + 0x18), (int)a)) {
        return 0;
    }
    if (!fn_800A9E1C((UnkFEObj*)(self + 0x20), a)) {
        return 0;
    }
    return 1;
}

void fn_800AB01C(char* p, int* a)
{
    fn_800A915C((UnkFEObj*)(p + 0x28));
    fn_800A8E40((UnkFEObj*)(p + 0x30), a);
    fn_800A8C48((UnkFEObj*)(p + 0x38), a);
    fn_800A89DC((UnkFEObj*)(p + 0x48), a);
    fn_800A8B70((UnkFEObj*)(p + 0x50), a);
    fn_800A94B4((UnkFEObj*)(p + 0x58), a);
    fn_800A9328((UnkFEObj*)(p + 0x60), a);
}

UnkFEArr::UnkFEArr()
{
    m4 = 0;
    m8 = 0;
    for (int i = 0; i <= 0; i++) {
        m0[i] = 0;
    }
}

void fn_800AB0C4(UnkFEArr* a, int v)
{
    if (a->m4 > 0) {
        return;
    }
    a->m0[a->m4] = v;
    a->m4 = a->m4 + 1;
}
