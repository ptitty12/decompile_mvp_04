/*
 * Database overlay code, .database_codeoverlay 0x80554628-0x8055A3B0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"
#include "game/clampiter.h"

extern Unk8007A4DC_Screen* lbl_8061930C;
extern int lbl_80622C9C[];
extern int lbl_80622CAC[];
extern int lbl_80622CBC[];
extern int lbl_80622CCC[];
extern int lbl_80622CF4[];
extern int lbl_80622D1C[];
int fn_80084114(int a);
int fn_8007FB98(Unk8007F198_C* s, int a, int b, int c);
int fn_8007FDA8(Unk8007F198_C* s, int a, int b);
int fn_8007FD2C(Unk8007F198_C* s, int a, int b, int c);
void fn_80083E84(int t, int* a, int* b);
extern "C" int fn_8057CE00(int a);
extern "C" void fn_8007A380__18Unk8007A4DC_Screen(Unk8007A4DC_Screen* s, int a);
int fn_8007F674(Unk8007F198_A* self, int a, int x);
int fn_8007F7D0(Unk8007F198_B* self, unsigned i);
void fn_8007FE18(Unk8007F198_E* self);
extern "C" void fn_80560314(int obj, int j, int k);
extern "C" int fn_8033E888(int a, int b);

extern "C" void fn_805559D4(int a, void* idx, int b, int c);
extern "C" int fn_805481D8(void* p);
extern "C" void fn_80546D5C(void* p, int a);

/* Seven-slot index list: m0/m4/m8 header, slots from +0xC (fn_8055638C resets them to -1). */
struct Db8055638C_Idx {
    int m0;
    int m4;
    int m8;
    int mC[7];
};
struct Db8055547C_S {
    int m0;
    int m4;
    void* m8;
};

extern "C" DB_OVERLAY int fn_8055645C(Db8055638C_Idx* self, int* out);

extern float lbl_805FF59C;
extern float lbl_805FF5A0;
extern float lbl_805FF5A4;

struct Db80556E0C_S {
    char* m0;
    char* m4;
};

extern char lbl_80622D44[];

struct Db8055A360_S {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" void fn_80400CE4(int a);
extern "C" void fn_805371C4(Unk805352B0_List* self, unsigned f);
extern char lbl_8064A2A8[];
void fn_8007F524(Unk8007F198_A* g, int a);

int fn_8009047C(int a, int b);
/* forward declarations (definitions are in address order) */
extern "C" void fn_80555144();
extern "C" void fn_80555270();
extern "C" void fn_805552D4();
extern "C" void fn_805553C0();
extern "C" void fn_8055547C(Db8055547C_S* self);
extern "C" int fn_805558C0(int self, int a, int b);
extern "C" int fn_80555998(int a);
extern "C" int fn_80555D88(int k, int n);
extern "C" int fn_80555E6C(int a);
extern "C" int fn_80555EB0(int k, int i);
extern "C" int fn_80555F18(int k, int i);
extern "C" int fn_805562B8(int a);
extern "C" Db8055638C_Idx* fn_80556348(Db8055638C_Idx* self);
extern "C" void fn_8055638C(Db8055638C_Idx* self);
extern "C" int fn_805563C4(Db8055638C_Idx* self);
extern "C" int fn_80556410(Db8055638C_Idx* self);
extern "C" int fn_8055645C(Db8055638C_Idx* self, int* out);
extern "C" int fn_805564DC(Db8055638C_Idx* self);
extern "C" void fn_8055655C(Db8055638C_Idx* self, int* a, int* b);
extern "C" void fn_8055669C(Db8055638C_Idx* self, int v);
extern "C" char* fn_8055696C(char* base, int a, int mode, float f);
extern "C" void fn_80556E0C(Db80556E0C_S* self, int chrg);
extern "C" void fn_80556E78(Unk8007A4DC_Screen* sc, int x, int y, int z, int w);
extern "C" void fn_8055A32C(int* self);
extern "C" void fn_8055A338(void* self, int chrg);
extern "C" void fn_8055A360(Db8055A360_S* self);

/* near-miss: retail has two extra copies (li r9,0 / mr r30,r9 for the first counter, mr r3,r0 for the saturating counter) */
extern "C" DB_OVERLAY void fn_80555144()
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    unsigned n = sc->fn_8007B1EC();
    unsigned i = 0;
    for (; i < n; i++) {
        if ((unsigned char)i == 0)
            fn_80400CE4(0);
        int v = sc->fn_8007A8DC(0x19, i);
        int r = 0;
        if (v > 1)
            r = v - 1;
        sc->fn_8007A94C(0x19, i, r);
    }
    int g = fn_8007F7D0((Unk8007F198_B*)sc, 0);
    Unk8006A138_It<9> it(0);
    int k;
    do {
        int a = fn_8008FE14(0);
        int b = fn_8008FD78(it.v);
        int v = ((Unk8007B2B0_Screen*)sc)->fn_8007B380(a, g);
        if (v != 0) {
            int c = fn_8009047C(b, v);
            if (c > 0)
                fn_800905FC(b, v, c - 1);
        }
        k = it.Next();
    } while (k <= 9);
}

extern "C" DB_OVERLAY void fn_80555270()
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    unsigned i = 1;
    unsigned n = sc->fn_8007B1EC();
    for (; i < n; i++)
        sc->fn_8007A94C(0x1A, i, 0);
}

extern "C" DB_OVERLAY void fn_805552D4()
{
    Unk80535650_Tmp t;
    int buf[0x82];
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    Unk80535650_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    fn_805371C4((Unk805352B0_List*)q, 0x71FFFFFF);
    int n = q->m4;
    int i;
    for (i = 0; i < n; i++) {
        fn_80400CE4(0);
        fn_8007F524((Unk8007F198_A*)sc, t.At(i));
    }
    q->D();
}

extern "C" DB_OVERLAY void fn_805553C0()
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    unsigned i = 0;
    sc->fn_8007A2B4(3);
    fn_8007A380__18Unk8007A4DC_Screen(sc, 1);
    fn_8007FE18((Unk8007F198_E*)sc);
    unsigned n = ((Unk8007B2B0_Screen*)sc)->fn_8007BC9C();
    for (; i < n; i++) {
        int obj = ((Unk8007B2B0_Screen*)sc)->fn_8007290C(i);
        unsigned j;
        for (j = 0; j < 2; j++) {
            while (fn_8007F674((Unk8007F198_A*)sc, obj, j) != 0)
                fn_80560314(obj, j, 0);
        }
    }
}

extern "C" DB_OVERLAY void fn_8055547C(Db8055547C_S* self)
{
    if (fn_805481D8(self->m8) == 0)
        fn_80546D5C(self->m8, 0);
}

extern "C" DB_OVERLAY int fn_805558C0(int self, int a, int b)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    if ((unsigned)(sc->fn_8007A6A0(0x16, a) - 3) > 1)
        return 0;
    if (fn_8033E888(sc->fn_8007A6A0(1, a), b) > 0x1D)
        return 0;
    int t = sc->fn_8007A6A0(5, a);
    if (t == 0 || t == 10) {
        if (sc->fn_8007B054(0, a) > 14)
            return 0;
    } else {
        if (sc->fn_8007AEBC(0, a) > 0x1D)
            return 0;
    }
    return 1;
}

extern "C" DB_OVERLAY int fn_80555998(int a)
{
    switch (a) {
    case 0:
    case 3:
        return 0;
    case 1:
    case 2:
        return 1;
    }
    return 5;
}

/* near-miss: n range test and the loop body match; retail pre-tests the loop (duplicated lwz/lwz/cmpw)
 * where ours branches into the bottom test (51 vs 57 insns). */
extern "C" DB_OVERLAY int fn_80555D88(int k, int n)
{
    int sum = 0;
    if (n == 0) {
        int a = fn_80555EB0(k, 0);
        sum = a * fn_80555F18(k, 0);
    } else if (n < 0) {
        sum = 0;
    } else if (n > 3) {
        sum = 0;
    } else {
        Unk8006A138_It<10> it(0);
        int hi = 1;
        fn_80083E84(n, &it.v, &hi);
        int cur = it.v;
        if (cur <= hi) {
            do {
                int a = fn_80555E6C(k);
                a = a * fn_80555F18(k, it.v);
                sum += a;
                it.Next();
            } while (it.v <= hi);
        }
    }
    return sum;
}

extern "C" DB_OVERLAY int fn_80555E6C(int a)
{
    switch (a) {
    case 0:
        return 4;
    case 1:
        return 2;
    case 2:
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80555EB0(int k, int i)
{
    switch (k) {
    case 0:
        return lbl_80622C9C[i];
    case 1:
        return lbl_80622CAC[i];
    case 2:
        return lbl_80622CBC[i];
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80555F18(int k, int i)
{
    switch (k) {
    case 0:
        return lbl_80622CCC[i];
    case 1:
        return lbl_80622CF4[i];
    case 2:
        return lbl_80622D1C[i];
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_805562B8(int a)
{
    if (fn_8057CE00(0) == 3) {
        Db8055638C_Idx buf;
        fn_80556348(&buf);
        fn_805559D4(2, &buf, 1, 0);
        int out = 0;
        int r = fn_8055645C(&buf, &out);
        if (r == ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, a))
            return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY Db8055638C_Idx* fn_80556348(Db8055638C_Idx* self)
{
    self->m4 = 1;
    self->m0 = 0;
    self->m8 = 0;
    fn_8055638C(self);
    return self;
}

extern "C" DB_OVERLAY void fn_8055638C(Db8055638C_Idx* self)
{
    self->m4 = 1;
    self->m0 = 0;
    self->m8 = 0;
    int i;
    for (i = 0; i < 7; i++)
        self->mC[i] = -1;
}

extern "C" DB_OVERLAY int fn_805563C4(Db8055638C_Idx* self)
{
    int c = self->mC[0];
    int h = fn_80084114(self->m0);
    return fn_8007FB98((Unk8007F198_C*)lbl_8061930C, c, 0, h);
}

extern "C" DB_OVERLAY int fn_80556410(Db8055638C_Idx* self)
{
    int c = self->mC[0];
    int h = fn_80084114(self->m0);
    return fn_8007FB98((Unk8007F198_C*)lbl_8061930C, c, 1, h);
}

extern "C" DB_OVERLAY int fn_8055645C(Db8055638C_Idx* self, int* out)
{
    int lo = 0;
    int hi = 0;
    fn_8055655C(self, &lo, &hi);
    if (lo > hi) {
        *out = fn_80556410(self);
        return fn_805563C4(self);
    }
    *out = fn_805563C4(self);
    return fn_80556410(self);
}

extern "C" DB_OVERLAY int fn_805564DC(Db8055638C_Idx* self)
{
    int k = fn_80555F18(self->m4, self->m0);
    int lo = 0;
    int hi = 0;
    fn_8055655C(self, &lo, &hi);
    int half = k / 2;
    int r = 0;
    if (lo > half || hi > half)
        r = 1;
    return r;
}

/* near-miss: control flow and calls match (80 vs 79 insns). Retail keeps the zero stored to *a and *b in
 * r31 (the register h later takes) and i in r22; ours uses r0 for the zero. */
extern "C" DB_OVERLAY void fn_8055655C(Db8055638C_Idx* self, int* a, int* b)
{
    Unk8007F198_C* sc = (Unk8007F198_C*)lbl_8061930C;
    int e = fn_80556410(self);
    *a = 0;
    *b = 0;
    int i = 0;
    if (i < self->m8) {
      do {
        int idx = self->mC[i];
        int h = fn_80084114(self->m0);
        if (fn_8007FDA8(sc, idx, h) == 0)
            break;
        int c1 = fn_8007FD2C(sc, idx, 1, h);
        int c0 = fn_8007FD2C(sc, idx, 0, h);
        int d1 = fn_8007FB98(sc, idx, 1, h);
        int d0 = fn_8007FB98(sc, idx, 0, h);
        if (c1 > c0) {
            if (d1 == e)
                (*b)++;
            else
                (*a)++;
        } else if (c0 > c1) {
            if (d0 == e)
                (*b)++;
            else
                (*a)++;
        }
        i++;
      } while (i < self->m8);
    }
}

extern "C" DB_OVERLAY void fn_8055669C(Db8055638C_Idx* self, int v)
{
    self->mC[self->m8] = v;
    self->m8 = self->m8 + 1;
}

extern "C" DB_OVERLAY char* fn_8055696C(char* base, int a, int mode, float f)
{
    int k;
    if (!(f <= lbl_805FF59C))
        k = 3;
    else if (!(f <= lbl_805FF5A0))
        k = 2;
    else
        k = f > lbl_805FF5A4;
    switch (mode) {
    case 0:
        return base + (a * 0x30 + 0x690) + k * 12;
    case 1:
        return base + (a * 0x30 + 0xBD0) + k * 12;
    default:
        return 0;
    }
}

extern "C" DB_OVERLAY void fn_80556E0C(Db80556E0C_S* self, int chrg)
{
    if (self->m0) {
        delete self->m0;
        self->m0 = 0;
    }
    if (self->m4) {
        delete self->m4;
        self->m4 = 0;
    }
    if (chrg & 1)
        delete self;
}

extern "C" DB_OVERLAY void fn_80556E78(Unk8007A4DC_Screen* sc, int x, int y, int z, int w)
{
    int v = sc->fn_8007AB9C(y, z);
    int k;
    if (x == 0x1C)
        k = 0;
    else
        k = sc->fn_8007AB9C(x, z);
    if ((k >= 1 && k <= 3) || k == 10 || (k >= 12 && k <= 13))
        v += w * -2;
    int m = sc->fn_8007AB9C(5, z);
    int hi = lbl_80622D44[k * 2 + 1];
    int lo = lbl_80622D44[k * 2];
    v = !(v > hi) ? (v >? lo) : hi;
    if (k != 0) {
        int top = m - 2;
        lo = lbl_80622D44[k * 2];
        v = !(v > top) ? (v >? lo) : top;
    }
    sc->fn_8007AC5C(y, z, v);
}

extern "C" DB_OVERLAY void fn_8055A32C(int* self)
{
    *self = 3;
}

extern "C" DB_OVERLAY void fn_8055A338(void* self, int chrg)
{
    if (chrg & 1)
        delete (char*)self;
}

extern "C" DB_OVERLAY void fn_8055A360(Db8055A360_S* self)
{
    self->m4 = 0;
    self->m8 = lbl_8061930C->fn_8007B1EC();
    self->mC = fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
}
