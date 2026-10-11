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
void fn_800AAD6C(char* self, int a);
void fn_800AA6FC(char* self, int a);
void* fn_800AA67C(void* self);
void* fn_800AABA4(void* self);
void* fn_800AAA8C(char* self, int a);
void fn_800AAAD8(char* a, char* b);

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

int fn_800A9B0C(UnkFEObj* self)
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

int fn_800A9C90(UnkFEObj* self)
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

void fn_800AA42C()
{
    for (int i = 0; i < 12; i++) {
        lbl_80619CA0[i] = 0;
        lbl_80619CD0[i] = 0;
    }
    lbl_80619D00 = -1;
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

void* fn_800AA764()
{
    return fn_800AA67C(operator new(0x48, lbl_806EF9B4));
}

void* fn_800AA874(char* p, int i)
{
    return fn_800AAA8C(p + 4, i);
}

void fn_800AA898(char* a, char* b)
{
    fn_800AAAD8(b + 4, a + 4);
}

void* fn_800AADE0()
{
    return fn_800AABA4(operator new(0x84, lbl_806EF9B4));
}

void* fn_800AAF1C(UnkFEObj* self)
{
    return (void*)fn_8037C7FC()->fn_8037CE98(0x8CA866F4, self->m4, 0);
}

/* near-miss: the pointer copies come out as `mr r9,r3` / `mr r11,r9` instead of retail's `mr r11,r3` / `mr r9,r3` (2 slots) */
void fn_800AB098(UnkFEArr* a)
{
    a->m4 = 0;
    a->m8 = 0;
    for (int i = 0; i <= 0; i++) {
        a->m0[i] = 0;
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
