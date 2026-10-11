/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800401E4-0x80042DBC only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800401E4.h"

extern int lbl_80617050;
extern Unk80040640* lbl_806177D4;
extern Unk80040640_Tbl* lbl_806177D8;
extern int lbl_806177DC;
extern Unk805AEAB8_Ent lbl_805AEAB8[];
extern Unk805AF688_Ent lbl_805AF688[];
extern Unk805AF370_Ent lbl_805AF370[];
extern char lbl_806872A4[];
extern char lbl_806872AC[];
void fn_803A8B4C();
void fn_803B9FBC(int a);
void fn_803BA7C4(void* a, int* b);
void fn_800418C4(Unk80040640* self);
void fn_800410D8(Unk80040640* self, int a);
int fn_80040E9C(Unk80040640* self, int a);
void fn_80040C58(Unk80040640* self, int a);
void fn_80040DCC(Unk80040640* self, int a, int b);
int fn_800415C0(Unk80040640* self, int id, int a, int b, int c, int d);
int fn_80041350(Unk80040640* self, int id);
int fn_80041418(Unk80040640* self, int i);
void fn_80041478(Unk80040640* self, int id);
int fn_803A8548(int a, int b);
void fn_803A975C();
int fn_803A85B0(int a, int b, void* out);
void fn_803A979C();
void fn_803A9204(void* p);
void fn_8006772C();

int fn_802B96C4(const char* name, int a);
int fn_802B9764(const char* name);
int fn_802B9300(const char* name, int a, int b, int* out);
void fn_803EDA0C(int p);
void fn_803A8648(int a);
void fn_803A6644(int a);
int fn_803A82A8(int* out, int a);
int fn_803A8530(int a);
void* operator new[](unsigned int size, int heap); /* 0x803774A8 */
int fn_803A84BC(int a);
int fn_803A6B64(int a, const char* b, int c, void (*cb)(int, int));
Unk80040640* fn_8004072C();
void fn_800404A8(int u, int size);

Unk800401E4::Unk800401E4()
{
    int i;
    m0 = 0;
    m4 = -1;
    m8 = 0;
    m10 = 0;
    mC = -1;
    m34 = -1;
    for (i = 0; i < 8; i++)
        m14[i] = 0;
}

Unk800401E4::~Unk800401E4()
{
    if (m8 == 1)
        fn_800403EC();
}

int Unk800401E4::fn_8004028C(const char* name, int type, const char* name2, int flag)
{
    int spC = 0;
    int sp8 = 0;
    int ok;
    mC = type;
    ok = 1;
    if (fn_802B96C4(name, 0) == 0)
        ok = 0;
    if (ok == 1) {
        m34 = fn_802B9764(name);
        if (name2 != 0) {
            ok = 0;
            if (fn_802B96C4(name2, 0) != 0)
                ok = 1;
        }
        if (ok == 1) {
            spC = fn_802B9300(name, 0x400, 0xe, &sp8);
            if (sp8 <= 0 || spC == 0)
                ok = 0;
            if (ok == 1) {
                switch (type) {
                case 0:
                    ok = fn_800404E0(&spC, name);
                    break;
                case 1:
                    ok = fn_80040598(&spC, name, name2, flag);
                    break;
                default:
                    ok = 0;
                    break;
                }
            }
        }
    }
    m8 = ok;
    if (ok == 0) {
        if (spC != 0)
            fn_803EDA0C(spC);
        m0 = ok;
        m4 = -1;
    } else {
        m10 = (int)name;
    }
    return m8;
}

void Unk800401E4::fn_800403EC()
{
    int i;
    if (m8 == 1) {
        switch (mC) {
        case 0:
            fn_803A8648(m4);
            if (m0 != 0)
                delete[] (char*)m0;
            break;
        case 1:
            fn_803A6644(m4);
            if (m0 != 0)
                delete[] (char*)m0;
            break;
        }
    }
    m4 = -1;
    m0 = 0;
    m8 = 0;
    m10 = 0;
    mC = -1;
    for (i = 0; i < 8; i++)
        m14[i] = 0;
}

void fn_800404A8(int u, int size)
{
    lbl_80617050 = (int)(new (0x400) char[size]);
}

/* near-miss: 46/46 slots; retail stores m0 before the null test and puts the
 * delete[] error path in a different order. */
int Unk800401E4::fn_800404E0(int* p, const char* name)
{
    int ok = 1;
    int r = fn_803A82A8(&m4, *p);
    if (r >= 0) {
        if (r == 7) {
            char* t = new (0x400) char[fn_803A8530(m4)];
            m0 = (int)t;
            if (t == 0) {
                ok = 0;
            } else if (fn_803A84BC(m4) < 0) {
                ok = 0;
                if (m0 != 0)
                    delete[] (char*)m0;
            } else {
                fn_803EDA0C(*p);
                *p = 0;
            }
        } else {
            m0 = *p;
        }
    } else {
        ok = 0;
    }
    return ok;
}

int Unk800401E4::fn_80040598(int* p, const char* name, const char* name2, int flag)
{
    int ok = 1;
    if (fn_8004072C()->m5D0 == 1) {
        m0 = *p;
        m4 = fn_803A6B64(*p, name2, flag, fn_800404A8);
        if (m4 >= 0) {
            if (lbl_80617050 != 0) {
                m0 = lbl_80617050;
                lbl_80617050 = 0;
                fn_803EDA0C(*p);
                *p = 0;
            }
        } else {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    return ok;
}

/* near-miss: 57/59 slots. Retail computes &lbl_806177D8 before the operator
 * new call (kept in r31) and stores it after the init loop; every spelling of
 * the table pointer tried here stores it at the end with a fresh lis. The
 * field-store order matches (found by permutation search). */
Unk80040640::Unk80040640()
{
    int i;
    Unk80040640_Tbl* t;
    m5D0 = 0;
    m5C4 = 0;
    m5C8 = 0;
    m5CC = 0;
    m5F4 = -1;
    m5F8 = -1;
    m5FC = -1;
    for (i = 0; i < 8; i++)
        m5D4[i] = -1;
    for (i = 0; i < 0x63; i++)
        m438[i] = 0x3f;
    t = new (0) Unk80040640_Tbl;
    for (i = 0; i < 0x40; i++)
        t->m4[i * 2] = 0;
    lbl_806177D8 = t;
    t->m200 = 0;
}

Unk80040640* fn_8004072C()
{
    if (lbl_806177D4 == 0)
        lbl_806177D4 = new (0) Unk80040640;
    return lbl_806177D4;
}

Unk80040640::~Unk80040640()
{
}

void fn_800407EC(Unk80040640* self)
{
    if (self->m5C4 == 1) {
        if (self->m5D0 == 0)
            fn_800418C4(self);
        fn_80040DCC(self, 4, -1);
        fn_80040DCC(self, 6, -1);
        fn_80040DCC(self, 7, -1);
        fn_80040DCC(self, 8, -1);
        fn_80040DCC(self, 9, -1);
        fn_80040DCC(self, 10, -1);
        fn_80040DCC(self, 11, -1);
    }
}

void fn_800408A0(Unk80040640* self)
{
    int c = 0;
    if (self->m5C4 == 1)
        c = self->m5F4 >= 0;
    if (c == 1) {
        int i = 0;
        do {
            fn_800410D8(self, i);
            i++;
        } while (i <= 7);
    }
    if (self->m5D0 == 1) {
        fn_803A8B4C();
        fn_803EDA0C(self->m5CC);
        fn_803B9FBC(self->m5C8);
        fn_803EDA0C(self->m5C8);
        self->m5D0 = 0;
    }
    if (lbl_806177D4 != 0) {
        delete lbl_806177D4;
        lbl_806177D4 = 0;
    }
}

void fn_80040BE8(Unk80040640* self, int a)
{
    int i;
    for (i = 0; i <= 0x11; i++) {
        if (lbl_805AEAB8[i].m30[a] == 1)
            fn_80040C58(self, i);
    }
}

/* near-miss: 27/28 slots. Retail computes idx*0x3C once into two registers
 * (mulli, mr, add) and re-adds it for the call. */
void fn_80040C58(Unk80040640* self, int idx)
{
    if (self->m0[idx].m8 == 1)
        self->m0[idx].fn_800403EC();
    if (idx == 13)
        self->m5F8 = -1;
    else if (idx == 12)
        self->m5FC = -1;
}

void fn_80040DCC(Unk80040640* self, int a, int b)
{
    if ((unsigned int)(a - 12) <= 1)
        lbl_806177DC = b;
    fn_80040E9C(self, a);
    if (a == 13) {
        if (self->m0[12].m8 == 1 && self->m5FC != lbl_806177DC) {
            fn_80040C58(self, 12);
            fn_80040E9C(self, 12);
        }
    } else if (a == 12) {
        if (self->m0[13].m8 == 1 && self->m5F8 != lbl_806177DC) {
            fn_80040C58(self, 13);
            fn_80040E9C(self, 13);
        }
    }
}

int fn_800412AC(Unk80040640* self, int id, int a, int b, int c, int d)
{
    int r = -1;
    int ok = 0;
    if (self->m5C4 == 1)
        ok = self->m5F4 >= 0;
    if (ok == 1 && id >= 0 && id <= 0xb4) {
        switch (lbl_805AEAB8[lbl_805AF688[id].mC].m54) {
        case 0:
            r = fn_80041350(self, id);
            break;
        case 1:
            r = fn_800415C0(self, id, a, b, c, d);
            break;
        }
    }
    return r;
}

int fn_80041350(Unk80040640* self, int id)
{
    int ret = -1;
    int a = lbl_805AF688[id].mC;
    int r30 = fn_80041418(self, a);
    int r31 = lbl_805AF688[id].m8;
    if (r30 >= 0 || (r30 = fn_80041418(self, lbl_805AEAB8[a].m50), r31 = lbl_805AF688[id].m10, r30 >= 0)) {
        fn_80041478(self, id);
        if (fn_803A8548(r30, r31) != 0) {
            fn_803A975C();
            ret = fn_803A85B0(r30, r31, &self->m600);
            fn_803A979C();
        }
    }
    return ret;
}

/* near-miss: 23/24 slots; same mulli/mr/add pattern as fn_80040C58 (idx*0x3C
 * kept in two registers). */
int fn_80041418(Unk80040640* self, int i)
{
    int r = -1;
    int ok = 0;
    if (self->m5C4 == 1)
        ok = self->m5F4 >= 0;
    if (ok == 1 && i >= 0 && i <= 0x11) {
        if (self->m0[i].m8 == 1)
            r = self->m0[i].m4;
    }
    return r;
}

/* near-miss: 33/33 slots, 2 differ: retail stores m5 (stb 0x605) before the
 * lwzx of the table entry, here after. 2,520 statement orders were tried. */
void fn_80041478(Unk80040640* self, int id)
{
    int t;
    fn_803A9204(&self->m600);
    t = lbl_805AF688[id].m14;
    self->m600.m5 = 0;
    if (t > -1)
        self->m600.m0 = (unsigned char)self->m438[t];
    self->m600.m2 = 0x3c;
    self->m600.m3 = 0x7f;
    self->m600.m8 = 0;
    self->m600.mA = 0;
}

int fn_800414FC(Unk80040640* self, int a, int idx)
{
    int v;
    if (a <= 100) {
        v = a;
        if (v < 0)
            v = 0;
    } else {
        v = 100;
    }
    if (idx <= 0x62) {
        self->m438[idx] = ((v << 7) - v) / 100;
        if (self->m5D0 == 1) {
            int (*fp)(int) = lbl_805AF370[idx].m0;
            v = ((v << 15) - v) / 100;
            if (fp != 0 && fp != (int (*)(int))fn_8006772C)
                v = fp(v);
        }
    }
    return v;
}

/* near-miss: 60/57 slots. Retail does not keep the "t < 0" compare in cr4
 * across the call (the second clamp re-tests); an inline Clamp() made it worse. */
void fn_80042C78(Unk80040640* self, int a)
{
    int v;
    int t;
    int sp8;
    int spC;
    if (a <= 100) {
        v = a;
        if (v < 0)
            v = 0;
    } else {
        v = 100;
    }
    t = ((v << 15) - v) / 100;
    sp8 = t;
    if (t < 0)
        sp8 = 0;
    else if (t > 0x7fff)
        sp8 = 0x7fff;
    fn_803BA7C4(lbl_806872AC, &sp8);
    if (self->m5D4[3] < 0 || self->m5D4[6] < 0) {
        spC = t;
        if (t < 0)
            spC = 0;
        else if (t > 0x7fff)
            spC = 0x7fff;
        fn_803BA7C4(lbl_806872A4, &spC);
    }
}

void fn_80042D5C(Unk80040640* self)
{
    fn_80040C58(self, 1);
    fn_80040C58(self, 0);
    fn_80040C58(self, 2);
    fn_80040C58(self, 12);
    fn_80040C58(self, 13);
}
